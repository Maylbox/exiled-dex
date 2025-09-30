// trainerDetail.js
import { app } from './app.js';
import { loadTrainers, getTrainerById } from './trainersLoader.js';
import { spriteHTML } from './sprites.js';
import { moveChip } from './moves.js';
import { fmtNum } from './uiUtils.js';

function kv(label, val) {
  return `<div>${label}</div><div><span class="badge">${val || '—'}</span></div>`;
}

function statChips(obj, cls) {
  if (!obj) return '';
  const map = { hp:'HP', atk:'Atk', def:'Def', spa:'SpA', spd:'SpD', spe:'Spe' };
  return Object.entries(map)
    .filter(([k]) => obj[k] != null)
    .map(([k, label]) => `<span class="badge ev ${k} filled">${fmtNum(obj[k])} ${label}</span>`)
    .join(' ');
}

function renderPokemonCard(p, idx) {
  const ivs = statChips(p.ivs, 'ivs');
  const evs = statChips(p.evs, 'evs');
  const moves = (p.moves || []).map(m => moveChip(m)).join('');

  const rightMeta = [
    p.level ? `<span class="badge">Lv. ${p.level}</span>` : '',
    p.nature ? `<span class="badge">${p.nature}</span>` : '',
    p.ability ? `<span class="badge">${p.ability}</span>` : '',
    p.gender ? `<span class="badge">${p.gender}</span>` : '',
    p.itemRaw ? `<span class="badge">${p.itemRaw.replace(/^ITEM_/, '')}</span>` : '',
    p.shiny ? `<span class="badge">Shiny</span>` : '',
    p.teraType ? `<span class="badge">Tera: ${p.teraType.replace(/^TYPE_/, '')}</span>` : '',
    (p.gigantamax ? `<span class="badge">Gigantamax</span>` : ''),
  ].filter(Boolean).join(' ');

  return `
    <div class="hero" style="margin:.8rem 0">
      <div style="display:flex; gap:1rem; align-items:flex-start; flex-wrap:wrap">
        <div class="thumb" style="width:160px">${spriteHTML(p.speciesRaw, p.speciesRaw)}</div>
        <div style="flex:1">
          <h2 style="margin:.2rem 0">${p.nickname ? `${p.nickname} ` : ''}<small>${p.speciesRaw}</small></h2>
          <div class="chiplist">${rightMeta}</div>

          <div class="section" style="margin:.6rem 0 0">
            <div class="h2">Moves</div>
            <div class="chiplist">${moves || '—'}</div>
          </div>

          ${(ivs || evs) ? `
            <div class="section">
              <div class="h2">IVs / EVs</div>
              <div class="chiplist">${ivs} ${evs}</div>
            </div>` : ''}
        </div>
      </div>
    </div>
  `;
}

export async function renderTrainerDetail(id) {
  await loadTrainers();
  const t = getTrainerById(id);
  if (!t) {
    app.innerHTML = `<footer>Trainer not found.</footer>`;
    return;
  }

  const meta = `
    <div class="kv kv-hero">
      ${kv('Class', t.class)}
      ${kv('Gender', t.gender)}
      ${kv('Music', t.music)}
      ${kv('Double Battle', t.double ? 'Yes' : 'No')}
      ${t.items?.length ? kv('Items', t.items.join(', ')) : ''}
      ${t.ai?.length ? kv('AI', t.ai.join(' / ')) : ''}
    </div>
  `;

  const party = (t.party || []).map(renderPokemonCard).join('');

  app.innerHTML = `
    <div class="detail">
      <div class="hero">
        <h1 style="margin:.2rem 0">${t.name} <small>${t.id}</small></h1>
        ${meta}
      </div>

      <div class="section">
        <div class="h2">Party</div>
        ${party || '<div>—</div>'}
      </div>
    </div>
  `;
}
