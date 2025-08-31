// dexList.js
// Pokédex grid page

import { INDEX, tName } from './dataLoader.js';
import { spriteHTML } from './sprites.js';
import { el } from './uiUtils.js';

const app = el('#app');

function getQuery() {
  const sb = document.querySelector('#q');
  const typed = (sb && sb.value) ? sb.value.trim().toLowerCase() : '';

  if (typed) return typed;

  const m = (location.hash || '').replace(/^#/, '').match(/^dex\?q=(.*)$/);
  return m ? decodeURIComponent(m[1] || '').trim().toLowerCase() : '';
}

export function renderDexList() {
  const q = getQuery();

  let list = INDEX;
  if (q) {
    list = INDEX.filter(s => {
      const display = (tName(s, s.name) || s.name || '').toLowerCase();
      const types   = (s.types || []).join(' ').toLowerCase();
      const abils   = (s.abilities || []).join(' ').toLowerCase();

      // collect every move name across sources
      const moves = (s.moves || []).join(' ').toLowerCase();

      return (
        String(s.dex).includes(q) ||
        display.includes(q) ||
        types.includes(q) ||
        abils.includes(q) ||
        moves.includes(q)            // ← NEW: search by move
      );
    });
  }

  const cards = list.map(s => {
    const dex3 = String(s.dex).padStart(3, '0');
    const displayName = tName(s, s.name);
    const types = (s.types || [])
      .filter(Boolean)
      .map(t => `<span class="pill type-${t} filled">${t}</span>`)
      .join('');

    return `
      <div class="card" onclick="location.hash='#dex/${s.dex}/${s.speciesId}'" title="${displayName}">
        <div class="thumb">${spriteHTML(s.speciesId, displayName)}</div>
        <div class="dex">#${dex3}</div>
        <div class="name">${displayName}</div>
        <div class="pills">${types}</div>
      </div>`;
  }).join('');

  app.innerHTML = `<div class="grid">${cards}</div><footer>${list.length} shown</footer>`;
}

// Small prev/next button used by the detail page
export function navMini(entry, dir) {
  if (!entry) return '';
  const dex3 = String(entry.dex).padStart(3, '0');
  const displayName = tName(entry, entry.name);
  const arrow = dir === 'prev' ? '◀' : '▶';
  return `
    <button class="dex-nav-btn ${dir}" onclick="location.hash='#dex/${entry.dex}/${entry.speciesId}'" title="${displayName}">
      <span class="arrow">${arrow}</span>
      <div class="mini">
        <div class="thumb">${spriteHTML(entry.speciesId, displayName)}</div>
        <div class="label">#${dex3}<br><strong>${displayName}</strong></div>
      </div>
    </button>`;
}
