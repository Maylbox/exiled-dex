// evolution.js
// Evolution tree: loading species, building layers, and rendering

import { INDEX, fetchJSON } from './dataLoader.js';
import { spriteHTML } from './sprites.js';
import { prettyParam, prettyMethod, chipHref, uniqBy } from './uiUtils.js';

// --- module-private cache ---
const SPECIES_CACHE = new Map(); // speciesId -> species JSON

// --- helpers (module-private) ---
function isMega(spec) {
  if (!spec) return false;
  return /(^|_)MEGA(_|$)/.test(spec.speciesId || '') || / - Mega$/i.test(spec.name || '');
}
function baseFormOf(spec) {
  const cand = INDEX.find(x => x.dex === spec.dex && !isMega(x));
  return cand ? cand : spec;
}
function megasFor(spec) {
  if (!spec || spec.dex == null) return [];
  return INDEX.filter(x => x.dex === spec.dex && isMega(x));
}

// Localized requirement label formatter
function reqLabel(method, param) {
  const p = prettyParam(param);
  const m = (method || '').toLowerCase();

  switch (m) {
    case 'level':              return `Lv. ${p}`;
    case 'level_atk_gt_def':   return `Lv. ${p} (Atk > Def)`;
    case 'level_def_gt_atk':   return `Lv. ${p} (Def > Atk)`;
    case 'level_night':        return `Lv. ${p} (Night)`;
    case 'level_day':          return `Lv. ${p} (Day)`;
    case 'level_beauty':       return `Beauty ${p}`;
    case 'item':               return p;
    case 'trade':              return 'Trade';
    case 'trade_item':         return `Trade + ${p}`;
    case 'friendship':         return 'High Friendship';
    case 'friendship_day':     return 'High Friendship (Day)';
    case 'friendship_night':   return 'High Friendship (Night)';
    case 'move':               return `Know Move: ${p}`;
    case 'map':                return `Location: ${p}`;
    case 'weather':            return `Weather: ${p}`;
    case 'critical_hits':      return `${p} Critical Hits`;
    case 'party':              return `Party has ${p}`;
    case 'type_in_party':      return `Party Type: ${p}`;
    case 'use_move':           return `Use Move: ${p}`;
    case 'mega':
    case 'mega_evolution':     return 'Mega Evolution';
    default:                   return [prettyMethod(method), p].filter(Boolean).join(': ');
  }
}

// --- public-ish helpers (module-private but exported functions use them) ---
async function loadSpecies(speciesId) {
  if (SPECIES_CACHE.has(speciesId)) return SPECIES_CACHE.get(speciesId);
  const idx = INDEX.find(x => x.speciesId === speciesId);
  if (!idx) return null;

  const file = idx.file || `${String(idx.dex).padStart(3, '0')}_${idx.speciesId}.json`;
  const data = await fetchJSON(`data/${file}`);
  SPECIES_CACHE.set(speciesId, data);
  return data;
}

async function ascendRoot(s) {
  // follow preEvolutionId up to the root
  let cur = s;
  while (cur.preEvolutionId) {
    const p = await loadSpecies(cur.preEvolutionId);
    if (!p) break;
    cur = p;
  }
  return cur;
}

async function buildEvolutionLayers(startSpecies) {
  // anchor on base if a Mega page was opened
  const start = isMega(startSpecies)
    ? (await loadSpecies(baseFormOf(startSpecies).speciesId))
    : startSpecies;

  let root = await ascendRoot(start);
  if (!root.evolution) root = await loadSpecies(root.speciesId);

  const layers = [[root]];
  const edges = [];

  const MAX_DEPTH = 4;
  for (let d = 0; d < MAX_DEPTH; d++) {
    const cur = layers[d];
    if (!cur || !cur.length) break;

    const next = [];

    for (const node of cur) {
      // real children from data
      for (const e of (node.evolution || [])) {
        const child = await loadSpecies(e.toSpeciesId);
        if (!child) continue;
        next.push(child);
        edges.push({ from: node.speciesId, to: child.speciesId, method: e.method, param: e.param });
      }

      // synthetic Mega branches (only if node is not already a Mega)
      const baseIdx = INDEX.find(x => x.speciesId === node.speciesId);
      if (baseIdx && !isMega(baseIdx)) {
        for (const m of megasFor(baseIdx)) {
          const megaFull = await loadSpecies(m.speciesId);
          next.push(megaFull);
          edges.push({ from: node.speciesId, to: m.speciesId, method: 'mega', param: null });
        }
      }
    }

    if (!next.length) break;
    layers.push(uniqBy(next, x => x.speciesId));
  }

  return { layers, edges, root };
}

function evoReqChips(edges, fromId, toId) {
  const reqs = edges
    .filter(e => e.from === fromId && e.to === toId)
    .map(e => ({ label: reqLabel(e.method, e.param), method: (e.method || '').toLowerCase() }));

  if (!reqs.length) return '';

  // any chip whose label/method contains one of these substrings is non-clickable
  const NON_CLICKABLE_SUBSTRINGS = [
    'level',
    'mega',
    'friendship',
    'move type',
  ];

  const chips = reqs.map(r => {
    const labelLc = r.label.toLowerCase();
    const methodLc = r.method.toLowerCase();
    const isLocked = NON_CLICKABLE_SUBSTRINGS.some(sub =>
      labelLc.includes(sub) || methodLc.includes(sub)
    );
    return isLocked
      ? `<span class="badge" aria-disabled="true">${r.label}</span>`
      : `<a class="badge" href="${chipHref(r.label)}">${r.label}</a>`;
  }).join('');

  return `<div class="chips">${chips}</div>`;
}

function evoCard(s, activeId) {
  const isActive = s.speciesId === activeId; // exact match only
  const cls = 'evo-node' + (isActive ? ' active' : '');
  return `
    <div class="${cls}" onclick="location.hash='#dex/${s.dex}/${s.speciesId}'" title="${s.name}">
      <div class="thumb">${spriteHTML(s.speciesId, s.name)}</div>
      <div class="name" style="text-align:center;margin-top:.35rem">${s.name}</div>
    </div>`;
}

export async function renderEvolutionTree(current) {
  const { layers, edges } = await buildEvolutionLayers(current);
  if (layers.length === 1 && !(layers[0][0].evolution || []).length) {
    return '<div>No known evolution.</div>';
  }

  let html = '<div class="evo-grid">';
  const activeId = current.speciesId;

  for (let c = 0; c < layers.length; c++) {
    html += `<div class="evo-col">`;
    for (const node of layers[c]) {
      html += evoCard(node, activeId);
      // show edge note from any parent in previous column (use the first that matches)
      if (c > 0) {
        const parent = layers[c - 1].find(p =>
          edges.some(e => e.from === p.speciesId && e.to === node.speciesId)
        );
        if (parent) html += evoReqChips(edges, parent.speciesId, node.speciesId);
      }
    }
    html += `</div>`;
    if (c < layers.length - 1) {
      html += `<div class="evo-col spacer"><div class="evo-edge">➜</div></div>`;
    }
  }

  html += '</div>';
  return html;
}

// Optional export if other modules want to introspect the structure
export { buildEvolutionLayers };
