// dexDetail.js
// Detail page

import { app } from './app.js';
import { INDEX, fetchJSON, tArea, tBucket, tName } from './dataLoader.js';
import { colorToHex, fmtNum, fmtEv } from './uiUtils.js';
import { moveChip } from './moves.js';
import { spriteHTML } from './sprites.js';
import { renderEvolutionTree } from './evolution.js';
import { navMini } from './dexList.js';

export async function renderDexDetail(dex, speciesId) {
  let s = speciesId
    ? INDEX.find(x => x.dex === dex && x.speciesId === speciesId)
    : INDEX.find(x => x.dex === dex);

  if (!s) {
    app.innerHTML = `<footer>Entry not found.</footer>`;
    return;
  }

  const file = s.file || `${String(s.dex).padStart(3, '0')}_${s.speciesId}.json`;
  const data = await fetchJSON(`data/${file}`);

  // Accent color
  const accent = colorToHex(data.color || s.color || 'Gray');
  document.documentElement.style.setProperty('--accent', accent);

  const dex3 = String(data.dex).padStart(3, '0');

  // --- display name with overrides ---
  const displayName = tName(s, data.name);

  // Moves
  const eggs  = (data.eggMoves || []).map(m => moveChip(m)).join('');
  const teach = (data.teachableMoves || []).map(m => moveChip(m)).join('');

  // Types / abilities
  const types = (data.types || [])
    .filter(Boolean)
    .map(t => `<span class="pill type-${t} filled">${t}</span>`)
    .join('');

  // Filter out "None" and remove duplicates (case-insensitive, keeps first)
  const seen = new Set();
  const abilities = (data.abilities || [])
    .filter(a => a && a !== "None")
    .filter(a => {
      const key = String(a).toLowerCase().trim();
      if (seen.has(key)) return false;
      seen.add(key);
      return true;
    })
    .map(a => `<span class="badge">${a}</span>`)
    .join('');


  // Stats
  const stats = renderStats(data.baseStats || {});

  // Level-up moves
  const levelUps = (data.levelUpMoves || [])
    .map(m => `
      <tr>
        <td style="width:64px">${m.level}</td>
        <td>${moveChip(m.move)}</td>
      </tr>
    `)
    .join('');

  // Encounters
  const encRows = (data.encounters || [])
    .filter(e => {
      const label = tArea(e.areaKey, e.area);   // i18n’d label
      return e.area !== "Unused" && label !== "Unused";
    })
    .map(e => {
      const areaLabel   = tArea(e.areaKey,   e.area);
      const bucketLabel = tBucket(e.bucketKey, e.bucket);
      return `<tr><td>${areaLabel}</td><td>${bucketLabel}</td><td>${e.min}–${e.max}</td><td>${e.slot}</td><td>${e.rateBase ?? ''}</td></tr>`;
    })
    .join('');

  const enc = encRows || `<tr><td colspan="5" style="opacity:.8">—</td></tr>`;

  // Evolution tree
  const evoHTML = await renderEvolutionTree(data);

  // Prev/next
  const i = INDEX.findIndex(e => e.speciesId === s.speciesId);
  const prevEntry = i > 0 ? INDEX[i - 1] : null;
  const nextEntry = i < INDEX.length - 1 ? INDEX[i + 1] : null;
  const navHTML = `
    <div class="dex-nav">
      ${navMini(prevEntry, 'prev')}
      ${navMini(nextEntry, 'next')}
    </div>`;

  app.innerHTML = `
    ${navHTML}
    <div class="detail">
      <div class="hero" style="border-color:${accent}">
        <div style="display:flex;gap:1rem;align-items:flex-start;flex-wrap:wrap">
          <div class="thumb" style="width:220px">${spriteHTML(s.speciesId, displayName)}</div>
          <div>
            <h1>${displayName} <small>#${dex3}</small></h1>
            <div class="pills" style="margin:.25rem 0 .5rem 0">${types}</div>

            <div class="kv kv-hero">
              <div>Catch rate</div><div><span class="badge">${data.catchRate}</span></div>
              <div>Growth</div><div><span class="badge">${data.growthRate || '—'}</span></div>
              <div>Friendship</div><div><span class="badge">${data.friendship ?? '—'}</span></div>
              <div>Color</div><div><span class="badge">${data.color || '—'}</span></div>
            </div>

            <div class="section" style="margin:.6rem 0 0">
              <div class="h2" style="margin-bottom:.35rem">Abilities</div>
              <div class="chiplist">${abilities || '—'}</div>
            </div>
          </div>
        </div>
        <p style="margin-top:.6rem;white-space:pre-line">${data.description || ''}</p>
      </div>

      <div class="section">
        <div class="h2">Base stats</div>
        ${stats}
      </div>

      <div class="section">
        <div class="h2">Biometrics</div>
        <div class="kv">
          <div>Height</div><div>${fmtNum(data.heightM)} m</div>
          <div>Weight</div><div>${fmtNum(data.weightKg)} kg</div>
          <div>Egg groups</div><div>${(data.eggGroups || []).join(', ') || '—'}</div>
          <div>EV yield</div><div>${fmtEv(data.evYield || {})}</div>
        </div>
      </div>

      <div class="section">
        <div class="h2">Evolution Line</div>
        ${evoHTML}
      </div>

      <div class="section">
        <div class="h2">Level-up moves</div>
        <table class="table">
          <thead><tr><th>Lvl</th><th>Move</th></tr></thead>
          <tbody>${levelUps}</tbody>
        </table>
      </div>

      <div class="section">
        <div class="h2">Egg moves</div>
        <div class="chiplist">${eggs || '—'}</div>
      </div>

      <div class="section">
        <div class="h2">Teachable moves</div>
        <div class="chiplist">${teach || '—'}</div>
      </div>

      <div class="section">
        <div class="h2">Encounters</div>
        <table class="table">
          <thead>
            <tr><th>Area</th><th>Bucket</th><th>Level</th><th>Slot</th><th>Rate</th></tr>
          </thead>
          <tbody>${enc}</tbody>
        </table>
      </div>
    </div>
  `;
}

// --- local helpers ---
function renderStats(stats) {
  const keys = ['hp', 'atk', 'def', 'spa', 'spd', 'spe'];
  const rows = keys.map(k => {
    const v = Number(stats[k] || 0);
    const pct = Math.min(1, v / 180);
    return `
      <div class="statrow">
        <div style="text-transform:uppercase">${k}</div>
        <div class="bar"><div class="fill" style="width:${(pct * 100).toFixed(0)}%"></div></div>
        <div>${v}</div>
      </div>`;
  }).join('');

  const bst = Object.values(stats).reduce((a, b) => a + Number(b || 0), 0);
  return rows + `<div style="margin-top:.4rem"><strong>BST:</strong> ${bst}</div>`;
}
