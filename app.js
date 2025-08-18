// Static SPA: loads data/index.json and per-species JSONs

const el = (s)=>document.querySelector(s);
const app = el('#app');
const searchBox = el('#q');

const DATA_DIR = 'data/';
const SPRITE_DIR = 'sprites/'; // if missing we fall back to placeholder
let INDEX = [];

window.addEventListener('hashchange', route);
searchBox.addEventListener('input', () => { if(location.hash==='#dex') renderDexList(); });

init();

async function init(){
  INDEX = await fetchJSON(DATA_DIR + 'index.json');
  route();
}

function route(){
  const hash = location.hash.replace(/^#/,'');
  // toggle search visibility
  if (hash === 'dex') searchBox.classList.remove('hidden');
  else searchBox.classList.add('hidden');

  if (!hash) return renderHome();
  if (hash === 'dex') return renderDexList();
  const m = hash.match(/^dex\/(\d+)(?:\/([A-Z0-9_]+))?$/);
  if (m) return renderDexDetail(Number(m[1]), m[2] || null);
  renderNotFound();
}

function renderHome(){
  app.innerHTML = `
    <div class="grid">
      <div class="card" onclick="location.hash='#dex'">
        <div class="name">Pokédex</div>
        <div class="dex">${INDEX.length} species</div>
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
    const types = (s.types||[]).filter(Boolean).map(t=>`<span class="pill">${t}</span>`).join('');
    return `
      <div class="card" onclick="location.hash='#dex/${s.dex}/${s.speciesId}'" title="${s.name}">
        <div class="thumb"><img src="${img}" alt="${s.name}" loading="lazy"></div>
        <div class="dex">#${dex3}</div>
        <div class="name">${s.name}</div>
        <div class="pills">${types}</div>
      </div>`;
  }).join('');

  app.innerHTML = `<div class="grid">${cards}</div><footer>${list.length} shown</footer>`;
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

  const types = (data.types||[]).filter(Boolean).map(t=>`<span class="pill">${t}</span>`).join('');
  const abilities = (data.abilities||[]).filter(Boolean).map(a=>`<span class="badge">${a}</span>`).join('');
  const stats = renderStats(data.baseStats||{});

  const evoPrev = data.preEvolutionId ? `<div><strong>Pre-evo:</strong> ${data.preEvolutionId}</div>` : '';
  const evoNext = (data.evolution||[]).map(e=>`<div>➜ ${e.toSpeciesId} <small>(${e.method}${e.param?': '+e.param:''})</small></div>`).join('') || '';

  const levelUps = (data.levelUpMoves||[]).map(m=>`<tr><td>${m.level}</td><td>${m.move}</td></tr>`).join('');
  const eggs = (data.eggMoves||[]).map(m=>`<span class="badge">${m}</span>`).join('');
  const teach = (data.teachableMoves||[]).map(m=>`<span class="badge">${m}</span>`).join('');
  const enc = (data.encounters||[]).map(e=>`<tr><td>${e.area}</td><td>${e.bucket}</td><td>${e.min}–${e.max}</td><td>${e.slot}</td><td>${e.rateBase??''}</td></tr>`).join('');

  app.innerHTML = `
    <div class="detail">
      <div class="hero" style="border-color:${accent}">
        <div style="display:flex;gap:1rem;align-items:flex-start;flex-wrap:wrap">
          <div class="thumb" style="width:220px"><img src="${img}" alt="${data.name}"></div>
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
        <div class="h2">Evolution</div>
        ${evoPrev}
        ${evoNext || '<div>No further known evolution.</div>'}
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

function renderNotFound(){ app.innerHTML = `<p>Not found.</p>`; }

// helpers
async function fetchJSON(url){ const r=await fetch(url,{cache:'no-store'}); if(!r.ok) throw new Error(`Failed ${url}`); return r.json(); }

function spriteUrlOrPlaceholder(dex3,name){ return SPRITE_DIR + dex3 + '.png#maybe'; }

window.addEventListener('error',(e)=>{
  const n=e.target;
  if(n.tagName==='IMG' && String(n.src).includes('/sprites/')){
    const label=n.getAttribute('alt')||'';
    n.src = makePlaceholder(label);
  }
},true);

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
