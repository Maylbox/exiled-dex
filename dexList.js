// dexList.js
// Pokédex grid page

import { INDEX } from './dataLoader.js';
import { spriteHTML } from './sprites.js';
import { el } from './uiUtils.js';
const app = el('#app');

function getQuery() {
  // Prefer the live input value if the search box exists
  const sb = document.querySelector('#q');
  const typed = (sb && sb.value) ? sb.value.trim().toLowerCase() : '';

  if (typed) return typed;

  // Else read from the hash (#dex?q=...)
  const m = (location.hash || '').replace(/^#/, '').match(/^dex\?q=(.*)$/);
  return m ? decodeURIComponent(m[1] || '').trim().toLowerCase() : '';
}

export function renderDexList() {
  const q = getQuery();

  let list = INDEX;
  if (q) {
    list = INDEX.filter(s =>
      String(s.dex).includes(q) ||
      s.name.toLowerCase().includes(q) ||
      (s.types || []).join(' ').toLowerCase().includes(q) ||
      (s.abilities || []).join(' ').toLowerCase().includes(q)
    );
  }

  const cards = list.map(s => {
    const dex3 = String(s.dex).padStart(3, '0');
    const types = (s.types || [])
      .filter(Boolean)
      .map(t => `<span class="pill type-${t} filled">${t}</span>`)
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

// Small prev/next button used by the detail page
export function navMini(entry, dir) {
  if (!entry) return '';
  const dex3 = String(entry.dex).padStart(3, '0');
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
