// router.js
// URL → view routing + simple home/404 renderers

import { DEX_MAX } from './dataLoader.js';
import { renderDexList } from './dexList.js';
import { renderDexDetail } from './dexDetail.js';
import { app, searchBox } from './app.js';

// Public: called from app.js and on hashchange
export function route() {
  const hash = (location.hash || '').replace(/^#/, '');

  // Pokédex list (supports "#dex" and "#dex?q=...").
  if (hash === 'dex' || hash.startsWith('dex?')) {
    // Show search box and prefill from "?q=" if present.
    searchBox?.classList.remove('hidden');
    const m = hash.match(/^dex\?q=(.*)$/);
    if (m) searchBox.value = decodeURIComponent(m[1] || '');
    return renderDexList();
  }

  // Hide search box for all other pages.
  searchBox?.classList.add('hidden');

  // Detail route: "#dex/<number>" or "#dex/<number>/<SPECIES_ID>"
  const m = hash.match(/^dex\/(\d+)(?:\/([A-Z0-9_]+))?$/);
  if (m) {
    const dex = Number(m[1]);
    const speciesId = m[2] || null;
    return renderDexDetail(dex, speciesId);
  }

  // Empty hash → home; otherwise 404.
  if (!hash) return renderHome();
  return renderNotFound();
}

// ----- Private helpers -----

function renderHome() {
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

function renderNotFound() {
  app.innerHTML = `
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
