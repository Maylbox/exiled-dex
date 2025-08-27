// Static SPA: loads data/index.json and per-species JSONs

const el = (s)=>document.querySelector(s);
const app = el('#app');
const searchBox = el('#q');

const DATA_DIR = 'data/';
const SPRITE_DIR = 'sprites/'; // if missing we fall back to placeholder
let INDEX = [];
let DEX_MAX = 0;
let I18N = { area:{}, bucket:{} };
let MOVE_TYPES = {};
let FORMS_MAP = {};
let DEX_ORDER = [];
let DEX_TO_FIRST = new Map();

window.addEventListener('hashchange', route);
searchBox.addEventListener('input', () => { if(location.hash==='#dex') renderDexList(); });

init();

async function init(){
  const [index, blacklist, forms] = await Promise.all([
    fetchJSON(DATA_DIR + 'index.json'),
    fetchJSON(DATA_DIR + 'mods/blacklist.json').catch(() => []),
    fetchJSON(DATA_DIR + 'mods/forms.json').catch(() => ({}))
  ]);
  FORMS_MAP = forms || {};
  const blocked = new Set((blacklist || []).map(x => x.toUpperCase()));
  INDEX = index.filter(entry => !blocked.has(entry.speciesId.toUpperCase()));
  INDEX.sort((a,b) => {
    if (a.dex !== b.dex) return a.dex - b.dex;
    return a.name.localeCompare(b.name);
  });
  DEX_MAX = INDEX.reduce((m, e) => Math.max(m, Number(e.dex) || 0), 0);
  DEX_ORDER = [...new Set(INDEX.map(e => e.dex))].sort((a,b)=>a-b);
    DEX_TO_FIRST.clear();
    for (const e of INDEX) if (!DEX_TO_FIRST.has(e.dex)) DEX_TO_FIRST.set(e.dex, e);

  try {
    const i = await fetchJSON(DATA_DIR + 'i18n/areas.json');
    I18N.area   = i.area   || {};
    I18N.bucket = i.bucket || {};
  } catch(_) {}

  route(); // render after i18n is ready

  try {
    MOVE_TYPES = await fetchJSON(DATA_DIR + 'move_types.json');
  } catch(_) {}
}

function tArea(key, fallback){ return (I18N.area && I18N.area[key]) || fallback || key; }
function tBucket(key, fallback){ return (I18N.bucket && I18N.bucket[key]) || fallback || key; }

function route(){
  const hash = location.hash.replace(/^#/,'');
  // dex list (supports #dex and #dex?q=...)
  if (hash === 'dex' || hash.startsWith('dex?')) {
    // prefill search from query if present
    const m = hash.match(/^dex\?q=(.*)$/);
    searchBox.classList.remove('hidden');
    if (m) searchBox.value = decodeURIComponent(m[1] || '');
    return renderDexList();
  }
  // toggle search otherwise
  searchBox.classList.add('hidden');

  if (!hash) return renderHome();
  const m = hash.match(/^dex\/(\d+)(?:\/([A-Z0-9_]+))?$/);
  if (m) return renderDexDetail(Number(m[1]), m[2] || null);
  renderNotFound();
}

function renderHome(){
  app.innerHTML = `
    <div class="grid">
      <div class="card" onclick="location.hash='#dex'">
        <div class="name">Pokédex</div>
        <div class="dex">${DEX_MAX} entries</div>
      </div>

      <div class="card" onclick="location.hash='#moves'">
        <div class="name">Moves</div>
        <div class="dex">Work In Progress</div>
      </div>

      <div class="card" onclick="location.hash='#items'">
        <div class="name">Items</div>
        <div class="dex">Work In Progress</div>
      </div>

      <div class="card" onclick="location.hash='#trainers'">
        <div class="name">Trainers</div>
        <div class="dex">Work In Progress</div>
      </div>
    </div>
    <footer>
      Work In Progress.<br>
      <span style="color:#55CDFC">Trans</span>
      <span style="color:#F7A8B8">Rights</span>
      <span style="color:#ffffff">are</span>
      <span style="color:#F7A8B8">Human</span>
      <span style="color:#55CDFC">Rights!</span>
    </footer>
  `;
}


function reqLabel(method, param){
  const p = prettyParam(param);
  const m = (method||'').toLowerCase();

  switch(m){
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
    case 'mega_evolution': return 'Mega Evolution';
    default:                   return [prettyMethod(method), p].filter(Boolean).join(': ');
  }
}

// stub for future routing – makes chips “clickable” later
function chipHref(label){
  // items will become #item/<slug> later; for now, keep it inert or link to search
  return `#dex?q=${encodeURIComponent(label)}`;
}
function moveInfo(name){ return MOVE_TYPES?.[name] || null; }

function moveIcon(category){
  const c = (category || '').toLowerCase();
  if (c === 'physical' || c === 'special')
    return `<img class="icon" src="assets/icons/move-${c}.png" alt="${category}">`;
  return '';
}
function splitSpeciesBaseAndForm(speciesId) {
  const sid = String(speciesId || '').toUpperCase().trim();
  const noPrefix = sid.replace(/^SPECIES_/, '');

  const GLOBAL_SUFFIXES = [
    'MEGA','MEGA_X','MEGA_Y','GIGANTAMAX',
    'ALOLA','ALOLAN','HISUI','HISUIAN','GALAR','GALARIAN','PALDEA','PALDEAN',
    'EXILED'
  ];

  let toks = noPrefix.split('_').filter(Boolean);
  if (!toks.length) {
    return { baseId: sid.startsWith('SPECIES_') ? sid : ('SPECIES_' + sid), formKey: null };
  }

  if (toks[0] === 'EXILED') toks = toks.slice(1);

  // trim known global suffixes off the end
  let cut = toks.length;
  while (cut > 0 && GLOBAL_SUFFIXES.includes(toks[cut - 1])) cut--;

  // Nidoran special-case
  if (toks[0] === 'NIDORAN' && (toks[1] === 'F' || toks[1] === 'M')) {
    const end = cut;
    const baseId = 'SPECIES_NIDORAN_' + toks[1];
    const tail   = toks.slice(2, end);
    const formKey = tail.length ? tail.join('_') : null;
    return { baseId, formKey };
  }

  // ✅ Base names that *must* keep the underscore (no form split)
  const KEEP_UNDERSCORE = new Set([
    'JANGMO_O','HAKAMO_O','KOMMO_O',
    'HO_OH','PORYGON_Z','MR_MIME','MIME_JR','TYPE_NULL',
    // add more here if you bump into them
  ]);

  const core = toks.slice(0, cut).join('_');     // everything before any global suffix
  if (KEEP_UNDERSCORE.has(core)) {
    return { baseId: 'SPECIES_' + core, formKey: null };
  }

  // Default behavior: base = first token, form = the rest (before global suffix)
  const baseToken = toks[0] || '';
  const tail = toks.slice(1, cut);
  const formKey = tail.length ? tail.join('_') : null;

  const baseId = 'SPECIES_' + baseToken;
  return { baseId, formKey };
}


// Turn "SPECIES_XYZ" into "xyz" for folder naming (keeps your existing cleanup rules)
function speciesBaseFolder(speciesId, fallbackName){
  const sid = String(speciesId || '').toUpperCase();
  const nm  = String(fallbackName || '');

  if (sid.startsWith('SPECIES_')) {
    const base = sid
      .replace(/^SPECIES_/, '')
      .replace(/^EXILED_/, '')            // drop leading EXILED_
      .replace(/_EXILED\b.*/, '')         // drop trailing _EXILED and anything after
      // strip known suffix chains, including *-AN variants
      .replace(/_(MEGA(?:_(?:X|Y))?|GIGANTAMAX|ALOLA|ALOLAN|HISUI|HISUIAN|GALAR|GALARIAN|PALDEA|PALDEAN).*$/, '');
    return base.toLowerCase().replace(/[^a-z0-9_-]+/g,'');
  }

  // Fallback to name-based normalization
  const baseFromName = nm.toLowerCase().trim()
    .replace(/^\s*exiled\s+/, '')                                // "Exiled Machop" → "machop"
    .replace(/^\s*(alolan|hisuian|galarian|paldean)\s+/, '')     // strip leading regional adjectives
    .replace(/\s*-\s*(mega.*|alola.*|alolan.*|hisui.*|hisuian.*|galar.*|galarian.*|paldea.*|paldean.*)$/, '')
    .replace(/\s+/g,'_');
  return baseFromName.toLowerCase().replace(/[^a-z0-9_-]+/g,'');
}

// colored chip for a move (egg or TM)
function moveChip(name){
  const info   = moveInfo(name);
  const typeCls = info ? `type-${info.type}` : '';
  const icon    = moveIcon(info?.category); // always show when phys/special
  const slug    = name.toLowerCase().replace(/[^a-z0-9]+/g,'-').replace(/(^-|-$)/g,'');
  return `<a class="badge move ${typeCls} filled" href="#move/${slug}">${icon}${name}</a>`;
}

// EV chips
function renderEvChips(ev){
  const map = {hp:'HP', atk:'Atk', def:'Def', spa:'SpA', spd:'SpD', spe:'Spe'};
  const cls = {hp:'hp', atk:'atk', def:'def', spa:'spa', spd:'spd', spe:'spe'};
  const chips = Object.entries(ev||{})
    .filter(([,v])=>Number(v)>0)
    .map(([k,v])=>`<span class="badge ev ${cls[k]||k} filled">${v} ${map[k]||k.toUpperCase()}</span>`)
    .join('');
  return chips || '—';
}


// --- evolution helpers ---
const SPECIES_CACHE = new Map(); // speciesId -> JSON
async function loadSpecies(speciesId){
  if (SPECIES_CACHE.has(speciesId)) return SPECIES_CACHE.get(speciesId);
  const idx = INDEX.find(x => x.speciesId === speciesId);
  if (!idx) return null;
  const data = await fetchJSON(DATA_DIR + (idx.file || `${String(idx.dex).padStart(3,'0')}_${idx.speciesId}.json`));
  SPECIES_CACHE.set(speciesId, data);
  return data;
}
async function ascendRoot(s){ // follow preEvolutionId to the root
  let cur = s;
  while (cur.preEvolutionId){
    const p = await loadSpecies(cur.preEvolutionId);
    if (!p) break;
    cur = p;
  }
  return cur;
}
function uniqBy(arr, key){ const m=new Set(), out=[]; for(const x of arr){const k=key(x); if(!m.has(k)){m.add(k); out.push(x);} } return out; }

function titleize(s){ return s.toLowerCase().replace(/(^|[\s-])\w/g,m=>m.toUpperCase()); }
function niceEnumToken(tok,prefix){ return titleize(tok.replace(prefix,'').replace(/_/g,' ')); }
function prettyParam(param){
  if (!param) return '';
  if (/^ITEM_/.test(param))   return niceEnumToken(param,'ITEM_');
  if (/^SPECIES_/.test(param))return niceEnumToken(param,'SPECIES_');
  if (/^MOVE_/.test(param))   return niceEnumToken(param,'MOVE_');
  if (/^ABILITY_/.test(param))return niceEnumToken(param,'ABILITY_');
  return param;
}
function prettyMethod(method){
  if (!method) return '';
  return titleize(method.replace(/^evo_?/i,'').replace(/_/g,' '));
}
function isMega(spec){
  if (!spec) return false;
  return /(^|_)MEGA(_|$)/.test(spec.speciesId || '') || / - Mega$/i.test(spec.name || '');
}
function baseFormOf(spec){
  const cand = INDEX.find(x => x.dex === spec.dex && !isMega(x));
  return cand ? cand : spec;
}
function megasFor(spec){
  if (!spec || spec.dex == null) return [];
  return INDEX.filter(x => x.dex === spec.dex && isMega(x));
}


async function buildEvolutionLayers(startSpecies){
  // anchor on base if user opened a Mega page
  const start = isMega(startSpecies)
    ? (await loadSpecies(baseFormOf(startSpecies).speciesId))
    : startSpecies;
  let root = await ascendRoot(start);
  if (!root.evolution) root = await loadSpecies(root.speciesId);

  const layers = [[root]];
  const edges  = [];

  const MAX_DEPTH = 4;
  for (let d=0; d<MAX_DEPTH; d++){
    const cur = layers[d]; if (!cur || !cur.length) break;
    const next = [];

    for (const node of cur){
      // real children from data
      for (const e of (node.evolution||[])){
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
    layers.push(uniqBy(next, x=>x.speciesId));
  }

  return {layers, edges, root};
}


function evoReqChips(edges, fromId, toId){
  const reqs = edges
    .filter(e => e.from === fromId && e.to === toId)
    .map(e => ({ label: reqLabel(e.method, e.param), method: (e.method||'').toLowerCase() }));

  if (!reqs.length) return '';

  // any chip whose label/method contains one of these substrings is non-clickable
  const NON_CLICKABLE_SUBSTRINGS = [
    'level',
    'mega',
    'friendship',
    'move type'
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



function evoCard(s, activeId){
  const dex3 = String(s.dex).padStart(3,'0');

  const isActive = s.speciesId === activeId;   // exact match only
  const cls = "evo-node" + (isActive ? " active" : "");
  return `
    <div class="${cls}" onclick="location.hash='#dex/${s.dex}/${s.speciesId}'" title="${s.name}">
      <div class="thumb">${spriteHTML(s.speciesId, s.name)}</div>
      <div class="name" style="text-align:center;margin-top:.35rem">${s.name}</div>
    </div>`;
}




async function renderEvolutionTree(current){
  const {layers, edges} = await buildEvolutionLayers(current);
  if (layers.length===1 && !(layers[0][0].evolution||[]).length) {
    return '<div>No known evolution.</div>';
  }

  // columns
  let html = '<div class="evo-grid">';
  const activeId = current.speciesId;
  for (let c=0; c<layers.length; c++){
    html += `<div class="evo-col">`;
    for (const node of layers[c]){
      html += evoCard(node, activeId);
      // show edge note from any parent in previous column (use the first that matches)
      if (c > 0){
        const parent = layers[c-1].find(p =>
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


function renderDexList(){
  const q = (searchBox.value||'').trim().toLowerCase();
  let list = INDEX;
  if(q){
    list = INDEX.filter(s =>
      String(s.dex).includes(q) ||
      s.name.toLowerCase().includes(q) ||
      (s.types||[]).join(' ').toLowerCase().includes(q) ||
      (s.abilities||[]).join(' ').toLowerCase().includes(q)
    );
  }

  const cards = list.map(s=>{
    const dex3 = String(s.dex).padStart(3,'0');
    const img = spriteUrlOrPlaceholder(dex3, s.name);
    const types = (s.types||[]).filter(Boolean)
    .map(t=>`<span class="pill type-${t} filled">${t}</span>`)
    .join('');
    return `
      <div class="card" onclick="location.hash='#dex/${s.dex}/${s.speciesId}'" title="${s.name}">
        <div class="thumb">${spriteHTML(s.speciesId, s.name)}</div>
        <div class="dex">#${dex3}</div>
        <div class="name">${s.name}</div>
        <div class="pills">${types}</div>
      </div>`;
  }).join('');

  app.innerHTML = `<div class="grid">${cards}</div><footer>${list.length} shown</footer>`;
}
function navMini(entry, dir){  // dir: 'prev' | 'next'
  if (!entry) return '';
  const dex3 = String(entry.dex).padStart(3,'0');
  const arrow = dir === 'prev' ? '◀' : '▶';
  return `
    <button class="dex-nav-btn ${dir}" onclick="location.hash='#dex/${entry.dex}/${entry.speciesId}'" title="${entry.name}">
      <span class="arrow">${arrow}</span>
      <div class="mini">
        <div class="thumb">${spriteHTML(entry.speciesId, entry.name)}</div>
        <div class="label">#${dex3}<br><strong>${entry.name}</strong></div>
      </div>
    </button>`;
}


async function renderDexDetail(dex, speciesId){
  let s;
  if (speciesId) {
    s = INDEX.find(x => x.dex === dex && x.speciesId === speciesId);
  } else {
    // fallback: first species with that dex (old behavior)
    s = INDEX.find(x => x.dex === dex);
  }
  if (!s) return renderNotFound();

  const file = s.file || (String(s.dex).padStart(3,'0') + '_' + s.speciesId + '.json');
  const data = await fetchJSON(DATA_DIR + file);

  // accent only
  const accent = colorToHex(data.color || s.color || 'Gray');
  document.documentElement.style.setProperty('--accent', accent);

  const dex3 = String(data.dex).padStart(3,'0');
  const img = spriteUrlOrPlaceholder(dex3, data.name);

  // util: slugify once
  const slug = s => s.toLowerCase().replace(/[^a-z0-9]+/g,'-').replace(/(^-|-$)/g,'');

  // TODO: when you have move->type data, also add `type-${moveType}` to color by move type.
  const eggs  = (data.eggMoves || []).map(m => moveChip(m)).join('');
  const teach = (data.teachableMoves || []).map(m => moveChip(m)).join('');



  const types = (data.types||[]).filter(Boolean).map(t =>
    `<span class="pill type-${t} filled">${t}</span>`
  ).join('');
  const abilities = (data.abilities||[]).filter(Boolean).map(a=>`<span class="badge">${a}</span>`).join('');
  const stats = renderStats(data.baseStats||{});

  const levelUps = (data.levelUpMoves||[]).map(m=>`<tr><td>${m.level}</td><td>${m.move}</td></tr>`).join('');
  const enc = (data.encounters||[]).map(e=>{
    const areaLabel   = tArea(e.areaKey,   e.area);    // prefer translation, else prettified fallback from JSON
    const bucketLabel = tBucket(e.bucketKey, e.bucket);
    return `<tr><td>${areaLabel}</td><td>${bucketLabel}</td><td>${e.min}–${e.max}</td><td>${e.slot}</td><td>${e.rateBase??''}</td></tr>`;
  }).join('');
  const evoHTML = await renderEvolutionTree(data);

  const i = INDEX.findIndex(e => e.speciesId === s.speciesId);
  const prevEntry = i > 0 ? INDEX[i-1] : null;
  const nextEntry = i < INDEX.length-1 ? INDEX[i+1] : null;


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
          <div class="thumb" style="width:220px">${spriteHTML(s.speciesId, data.name)}</div>
          <div>
            <h1>${data.name} <small>#${dex3}</small></h1>
            <div class="pills" style="margin:.25rem 0 .5rem 0">${types}</div>

            <div class="kv kv-hero">
              <div>Catch rate</div><div><span class="badge">${data.catchRate}</span></div>
              <div>Growth</div><div><span class="badge">${data.growthRate||'—'}</span></div>
              <div>Friendship</div><div><span class="badge">${data.friendship??'—'}</span></div>
              <div>Color</div><div><span class="badge">${data.color||'—'}</span></div>
            </div>

            <div class="section" style="margin:.6rem 0 0">
              <div class="h2" style="margin-bottom:.35rem">Abilities</div>
              <div class="chiplist">${abilities || '—'}</div>
            </div>

          </div>
        </div>
        <p style="margin-top:.6rem;white-space:pre-line">${data.description||''}</p>
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
          <div>Egg groups</div><div>${(data.eggGroups||[]).join(', ')||'—'}</div>
          <div>EV yield</div><div>${fmtEv(data.evYield||{})}</div>
        </div>
      </div>

      <div class="section">
        <div class="h2">Evolution Line</div>
        ${evoHTML}
      </div>

      <div class="section">
        <div class="h2">Level-up moves</div>
        <table class="table"><thead><tr><th>Lvl</th><th>Move</th></tr></thead>
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
        <table class="table"><thead>
          <tr><th>Area</th><th>Bucket</th><th>Level</th><th>Slot</th><th>Rate</th></tr>
        </thead><tbody>${enc}</tbody></table>
      </div>
    </div>
  `;
}

function renderNotFound(){ app.innerHTML = `<footer>Work In Progress.<br>
                                                     <span style="color:#55CDFC">Trans</span>
                                                     <span style="color:#F7A8B8">Rights</span>
                                                     <span style="color:#ffffff">are</span>
                                                     <span style="color:#F7A8B8">Human</span>
                                                     <span style="color:#55CDFC">Rights!</span></footer>`; }

// helpers
async function fetchJSON(url){ const r=await fetch(url,{cache:'no-store'}); if(!r.ok) throw new Error(`Failed ${url}`); return r.json(); }

function spriteUrlOrPlaceholder(dex3, name){
  return SPRITE_DIR + dex3 + '.png#maybe';
}

(function(){
  const DEBUG_SPRITES = false; // set true to log fallback steps

  // Use capture so we catch resource errors, and don't rely on inline handlers
  document.addEventListener('error', function onImgError(ev){
    const img = ev.target;
    if (!(img instanceof HTMLImageElement)) return;

    // Only handle images that advertise a fallback chain
    const fallback = img.dataset.fallback || '';
    if (!fallback) return;

    const rest = fallback.split('|').filter(Boolean);
    const next = rest.shift();

    if (DEBUG_SPRITES) {
      console.warn('[sprite fallback]', { failed: img.src, next, remaining: rest });
    }

    if (next) {
      img.dataset.fallback = rest.join('|');
      img.src = next;
    } else {
      // Last resort: placeholder (if available)
      try {
        const label = img.getAttribute('alt') || '';
        if (typeof makePlaceholder === 'function') {
          img.src = makePlaceholder(label);
        }
      } catch (_) {}
    }
  }, true);
})();

function dirFromId(speciesId, name) {
  return (speciesId || name || '')
    .toString()
    .toLowerCase()
    .replace(/[^a-z0-9_-]+/g, ''); // allow dash/underscore
}
const SPRITE_ROOT = 'assets/pokemon/';
const REGION_MAP = { alola:'alolan', galar:'galarian', hisui:'hisuian', paldea:'paldean' };
const REGION_TOKENS = {
  alolan:  ['alola',  'alolan'],
  hisuian: ['hisui',  'hisuian'],
  galarian:['galar',  'galarian'],
  paldean: ['paldea', 'paldean'],
};

function spriteHTML(speciesId, name){
  const sid = String(speciesId || '').toUpperCase();
  const nm  = String(name || '');

  // variant detect (unchanged)
  const isMegaX = /MEGA[_-]?X/.test(sid) || /\bmega\s*x\b/i.test(nm);
  const isMegaY = /MEGA[_-]?Y/.test(sid) || /\bmega\s*y\b/i.test(nm);
  const isMega  = (!isMegaX && !isMegaY) && (/_MEGA\b/.test(sid) || /\b-\s*mega\b/i.test(nm));
  let region = null;
  // detect by either ID or display name (supports *-an endings)
  for (const [folder, toks] of Object.entries(REGION_TOKENS)) {
    if (toks.some(tok => sid.includes(tok.toUpperCase()) || nm.toLowerCase().includes(tok))) {
      region = folder; // e.g., 'alolan' — matches your folder name
      break;
    }
  }
  const isExiled = /^SPECIES_EXILED_/.test(sid) || /_EXILED\b/.test(sid) || /^\s*exiled\b/i.test(nm);

  const variant = isExiled ? 'exiled' : isMegaX ? 'mega_x' : isMegaY ? 'mega_y' : isMega ? 'mega' : region;

  // === species-specific form resolution (NEW) ===
  const { baseId, formKey } = splitSpeciesBaseAndForm(speciesId);
  const baseFolder = speciesBaseFolder(baseId, name);           // e.g., "maushold"
  const baseDir    = `${SPRITE_ROOT}${baseFolder}`;
  const exiledDir  = `${SPRITE_ROOT}exiled_${baseFolder}`;

  // map formKey -> subfolder via FORMS_MAP ("" means base folder)
  let formSubfolder = '';
  const mapForSpecies = FORMS_MAP[baseId];
  if (formKey && mapForSpecies) {
    formSubfolder = mapForSpecies[formKey]
                 ?? mapForSpecies[formKey.replace(/_FORM$/, '')]
                 ?? '';
  }
  const formDir = formSubfolder ? `${baseDir}/${formSubfolder}` : baseDir;

  // === build chain (prefers formDir first, then baseDir) ===
  const chain = variant === 'exiled'
      ? [
          `${exiledDir}/anim_front.png`,
          `${exiledDir}/front.png`,
          `${formDir}/anim_front.png`,
          `${formDir}/front.png`,
          `${baseDir}/anim_front.png`,
          `${baseDir}/front.png`
        ]
      : variant
      ? [
          // try variant inside formDir first
          `${formDir}/${variant}/anim_front.png`,
          `${formDir}/${variant}/front.png`,
          // then non-variant in formDir
          `${formDir}/anim_front.png`,
          `${formDir}/front.png`,
          // then try the same variant in baseDir (in case formDir didn’t exist)
          `${baseDir}/${variant}/anim_front.png`,
          `${baseDir}/${variant}/front.png`,
          // and finally baseDir plain
          `${baseDir}/anim_front.png`,
          `${baseDir}/front.png`
        ]
      : [
          `${formDir}/anim_front.png`,
          `${formDir}/front.png`,
          `${baseDir}/mega_x/front.png`,
          `${baseDir}/mega_y/front.png`,
          `${baseDir}/mega/front.png`,
          `${baseDir}/alolan/front.png`,
          `${baseDir}/galarian/front.png`,
          `${baseDir}/hisuian/front.png`,
          `${baseDir}/paldean/front.png`,
          `${SPRITE_ROOT}exiled_${baseFolder}/anim_front.png`,
          `${SPRITE_ROOT}exiled_${baseFolder}/front.png`
        ];

  const safeAlt = nm.replace(/"/g,'&quot;');
  const placeholder = makePlaceholder(nm);

  return `
    <img class="sprite ${variant && variant!=='exiled' ? '' : 'anim'}"
         src="${chain[0]}"
         data-fallback="${chain.slice(1).join('|')}"
         alt="${safeAlt}" loading="lazy"
         onerror="(function(img){
           const rest=(img.dataset.fallback||'').split('|').filter(Boolean);
           if(rest.length){ img.src=rest.shift(); img.dataset.fallback=rest.join('|'); }
           else{ img.src='${placeholder}'; }
         })(this)">
  `;
}


// global fallback used by onerror above
window.__spriteFallback = function(img){
  const alt = img.getAttribute('alt') || '';
  // if we haven't tried anim yet, try it and crop via CSS with .anim
  if (!img.dataset.triedAnim && img.dataset.anim){
    img.dataset.triedAnim = '1';
    img.classList.add('anim');
    img.src = img.dataset.anim;
    return;
  }
  // last resort: placeholder
  img.src = makePlaceholder(alt);
};

function makePlaceholder(label){
  const text = label.replace(/&/g,'&amp;').replace(/</g,'&lt;');
  const svg =
    `<svg xmlns='http://www.w3.org/2000/svg' width='512' height='512'>
       <rect width='100%' height='100%' fill='#0e0f11'/>
       <text x='50%' y='50%' dominant-baseline='middle' text-anchor='middle'
             font-family='Segoe UI, Roboto, Arial' font-size='48' fill='#6b7280'>${text}</text>
     </svg>`;
  return 'data:image/svg+xml;charset=utf-8,' + encodeURIComponent(svg);
}

function renderStats(stats){
  const rows = ['hp','atk','def','spa','spd','spe'].map(k=>{
    const v = Number(stats[k]||0);
    const pct = Math.min(1, v/180);
    return `
      <div class="statrow">
        <div style="text-transform:uppercase">${k}</div>
        <div class="bar"><div class="fill" style="width:${(pct*100).toFixed(0)}%"></div></div>
        <div>${v}</div>
      </div>`;
  }).join('');
  const bst = Object.values(stats).reduce((a,b)=>a+Number(b||0),0);
  return rows + `<div style="margin-top:.4rem"><strong>BST:</strong> ${bst}</div>`;
}

function fmtNum(n){ return (n==null)?'—':String(n); }
function fmtEv(ev){ const map={hp:'HP',atk:'Atk',def:'Def',spa:'SpA',spd:'SpD',spe:'Spe'}; return Object.entries(ev).map(([k,v])=>`${v} ${map[k]||k.toUpperCase()}`).join(', ') || '—'; }

function colorToHex(name){
  const T={Black:'#111111',Blue:'#3b82f6',Brown:'#8b5e3c',Gray:'#6b7280',Green:'#22c55e',Pink:'#ec4899',Purple:'#8b5cf6',Red:'#ef4444',White:'#1f1f1f',Yellow:'#eab308'};
  return T[name] || '#8ab4ff';
}
