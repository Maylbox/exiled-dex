// app.js
// App shell: boots data, wires routing, exposes the #app element.

import { init, DEX_MAX } from './dataLoader.js';
import { el } from './uiUtils.js';
import { renderDexDetail } from './dexDetail.js';
import { renderDexList } from './dexList.js';

export const app = el('#app');
const searchBox = el('#q');

// --- routing ---
function route() {
  const raw = location.hash.replace(/^#/, '');
  // Dex list (supports #dex and #dex?q=...)
  if (raw === 'dex' || raw.startsWith('dex?')) {
    searchBox.classList.remove('hidden');
    const m = raw.match(/^dex\?q=(.*)$/);
    if (m) searchBox.value = decodeURIComponent(m[1] || '');
    renderDexList();
    return;
  }

  // Hide search outside of the dex list
  searchBox.classList.add('hidden');

  if (!raw) {
    renderHome();
    return;
  }

  // Detail: #dex/<number>[/<SPECIES_ID>]
  const dm = raw.match(/^dex\/(\d+)(?:\/([A-Z0-9_]+))?$/);
  if (dm) {
    const dex = Number(dm[1]);
    const speciesId = dm[2] || null;
    renderDexDetail(dex, speciesId);
    return;
  }

  renderNotFound();
}

// --- UI sections ---
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
  app.innerHTML = `<footer>Work In Progress.<br>
    <span style="color:#55CDFC">Trans</span>
    <span style="color:#F7A8B8">Rights</span>
    <span style="color:#ffffff">are</span>
    <span style="color:#F7A8B8">Human</span>
    <span style="color:#55CDFC">Rights!</span></footer>`;
}

// --- boot ---
window.addEventListener('hashchange', route);
searchBox.addEventListener('input', () => {
  if (location.hash === '#dex' || location.hash.startsWith('#dex?')) {
    renderDexList();
  }
});

(async () => {
  await init();   // loads index, i18n, forms, move types
  route();        // initial render
})();
