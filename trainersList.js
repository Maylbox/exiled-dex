// trainersList.js
import { el } from './uiUtils.js';
import { spriteHTML } from './sprites.js';
import { loadTrainers, getTrainerIndex } from './trainersLoader.js';

const app = el('#app');

export async function renderTrainersList() {
  await loadTrainers();
  const list = getTrainerIndex();

  const cards = list.map(t => {
    // Thumbnail: show first Pokémon sprite if available, else a placeholder mugshot block
    const thumb = t.firstMon
      ? spriteHTML(t.firstMon.speciesRaw, t.firstMon.speciesRaw)
      : `<div style="width:100%;height:100%;display:grid;place-items:center;color:#888">No party</div>`;

    return `
      <div class="card" onclick="location.hash='#trainers/${t.id}'" title="${t.name}">
        <div class="thumb">${thumb}</div>
        <div class="dex">${t.class}${t.double ? ' · Doubles' : ''}</div>
        <div class="name">${t.name}</div>
        <div class="pills">
          <span class="badge">${t.gender || '—'}</span>
          <span class="badge">Party: ${t.partyCount}</span>
        </div>
      </div>
    `;
  }).join('');

  app.innerHTML = `<div class="grid">${cards}</div><footer>${list.length} trainers</footer>`;
}
