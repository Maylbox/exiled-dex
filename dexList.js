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

function norm(s = '') {
  return String(s).toLowerCase().normalize('NFKD').replace(/\p{Diacritic}/gu, '');
}

let SUGGEST = null;
function buildSuggest() {
  if (SUGGEST) return SUGGEST;
  const uniq = (arr) => Array.from(new Set(arr)).filter(Boolean);

  const names = uniq(INDEX.map(s => tName(s, s.name) || s.name));
  const abilities = uniq(INDEX.flatMap(s => (s.abilities || [])));
  const moves = uniq(INDEX.flatMap(s => (s.moves || [])));        // comes from index.json we added earlier
  const types = uniq(INDEX.flatMap(s => (s.types || [])));

  // store both label and normalized value for fast filter
  const wrap = (arr) => arr.map(v => ({ label: v, n: norm(v) })).sort((a,b)=>a.label.localeCompare(b.label));

  SUGGEST = {
    pokemon: wrap(names),
    ability: wrap(abilities),
    move:    wrap(moves),
    type:    wrap(types),
  };
  return SUGGEST;
}

// helper: split into tokens, supports quotes
function splitQuery(q = '') {
  // first, grab words/quoted chunks
  const parts = [];
  const re = /"([^"]*)"|\S+/g;
  let m;
  while ((m = re.exec(q)) !== null) parts.push(m[1] ?? m[0]);

  // now merge runs after a prefix until the next prefix
  const out = [];
  for (let i = 0; i < parts.length; i++) {
    const w = parts[i];
    const p = w.match(/^(\w+):(.*)$/);
    if (!p) { out.push(w); continue; }

    let prefix = p[1].toLowerCase();
    let value  = p[2] ?? '';

    // accumulate words that are NOT a new prefix
    while (i + 1 < parts.length && !/^\w+:/.test(parts[i + 1])) {
      value += (value ? ' ' : '') + parts[++i];
    }
    out.push(`${prefix}:${value}`);
  }
  return out;
}

function tokenAtCaret(input) {
  const q = input.value;
  const pos = input.selectionStart ?? q.length;
  const re = /"([^"]*)"|\S+/g;
  let m;
  while ((m = re.exec(q)) !== null) {
    const start = m.index;
    const text = m[0];
    const end = start + text.length;
    if (pos >= start && pos <= end) {
      return { start, end, text };
    }
  }
  return { start: q.length, end: q.length, text: '' };
}

// Parse prefix + (possibly quoted) value of a token
function parsePrefixedToken(text) {
  const m = String(text).match(/^(\w+):(.*)$/);
  if (!m) return null;
  const prefix = m[1].toLowerCase();
  // remove outer quotes if present
  let rawVal = m[2] ?? '';
  let quoted = false;
  if (/^".*"$/.test(rawVal)) { quoted = true; rawVal = rawVal.slice(1, -1); }
  const value = rawVal;
  return { prefix, value, quoted };
}

const PREFIXES = [
  { key: 'pokemon', hint: 'name contains…', kbd: 'pokemon:' },
  { key: 'move',    hint: 'learns move…',   kbd: 'move:' },
  { key: 'ability', hint: 'has ability…',   kbd: 'ability:' },
  { key: 'type',    hint: 'is type…',       kbd: 'type:' },
];

function parseTokens(q){ return splitQuery(q); }
function buildQueryFromTokens(tokens){ return tokens.join(' '); }
function tokensToChips(tokens){
  return tokens.map((t,i)=>{
    const p = parsePrefixedToken(t);
    if (!p || !p.value) return null;
    return { idx:i, label:`${p.prefix}:${p.value}` };
  }).filter(Boolean);
}

function renderChips(chipsEl, input){
  const chips = tokensToChips(parseTokens(input.value));
  chipsEl.innerHTML = chips.map(c=>`
    <span class="chip" data-chip="${c.idx}">
      ${c.label} <span class="x" title="Remove">✕</span>
    </span>
  `).join('');

  // NEW: adjust body top padding to current header height
  adjustHeaderOffset();

  chipsEl.onclick = (e)=>{
    const chip = e.target.closest('.chip'); if(!chip) return;
    const i = Number(chip.dataset.chip);
    const toks = parseTokens(input.value).filter((_,j)=>j!==i);
    input.value = buildQueryFromTokens(toks);
    input.dispatchEvent(new Event('input', { bubbles: true }));
    input.focus();
  };
}

// Build the menu HTML depending on mode
function renderSuggest(menuEl, items, activeIndex=0) {
  menuEl.innerHTML = items.map((it,i)=> {
    if (it.mode === 'prefix') {
      return `<div class="item ${i===activeIndex?'active':''}" data-mode="prefix" data-key="${it.key}">
        <kbd>${it.kbd}</kbd> <span>${it.hint}</span>
      </div>`;
    } else {
      return `<div class="item ${i===activeIndex?'active':''}" data-mode="value" data-prefix="${it.prefix}" data-value="${it.label}">
        <kbd>${it.prefix}:</kbd> <span>${it.label}</span>
      </div>`;
    }
  }).join('');
  menuEl.classList.remove('hidden');
}

function hideSuggest(menuEl){ menuEl.classList.add('hidden'); }

// Build the right list: prefixes or values for the current prefix
function buildMenuItems(input) {
  buildSuggest(); // ensure catalogs ready
  const { text } = tokenAtCaret(input);
  const p = parsePrefixedToken(text);

  // If not inside a prefixed token, show the 4 prefixes
  if (!p || !SUGGEST[p.prefix]) {
    return PREFIXES.map(p => ({ mode:'prefix', ...p }));
  }

  // Inside a known prefix: show value suggestions filtered by currently typed value
  const cat = SUGGEST[p.prefix];
  const needle = norm(p.value);
  const filtered = needle
    ? cat.filter(x => x.n.startsWith(needle))
    : cat;

  // Limit to top N for performance
  const MAX = 12;
  return filtered.slice(0, MAX).map(x => ({ mode:'value', prefix:p.prefix, label:x.label }));
}

// Insert prefix or value at the current token, with quotes
function applyMenuChoice(input, item) {
  const q = input.value;
  const { start, end, text } = tokenAtCaret(input);

  if (item.mode === 'prefix') {
    // Insert "pokemon:" (no trailing space) and place caret right after the colon
    const ins = `${item.key}:`;
    const before = q.slice(0, start).replace(/\s+$/,''); // trim end -> avoid double spaces before
    const after  = q.slice(end).replace(/^\s+/,'');      // trim start

    // keep a single space *before* following content, but not after the colon
    const between = after ? ' ' : '';
    const newQ = (before ? before + ' ' : '') + ins + between + after;

    input.value = newQ;
    input.focus();
    const caret = ((before ? before + ' ' : '') + ins).length;
    input.setSelectionRange(caret, caret);
    input.dispatchEvent(new Event('input', { bubbles: true }));
    return;
  }


  if (item.mode === 'value') {
    // Replace current token with "pokemon:Abra " (note trailing space after the value)
    const p = parsePrefixedToken(text) || { prefix: item.prefix, value: '' };
    const replacement = `${p.prefix}:${item.label}`;     // no quotes, canonical
    const before = q.slice(0, start).replace(/\s+$/,'');
    const after  = q.slice(end).replace(/^\s+/,'');      // remove any leading spaces after token

    const newQ = (before ? before + ' ' : '') + replacement + ' ' + after;

    input.value = newQ;
    input.focus();
    const caret = ((before ? before + ' ' : '') + replacement + ' ').length;
    input.setSelectionRange(caret, caret);
    input.dispatchEvent(new Event('input', { bubbles: true }));
    return;
  }

}

function adjustHeaderOffset() {
  const h = document.querySelector('header');
  if (!h) return;
  document.body.style.paddingTop = h.offsetHeight + 'px';
}

function setupSearchUI(){
  const input  = document.querySelector('#q');
  const menuEl = document.querySelector('#q-menu');
  if (!input || !menuEl) return;

  let idx = 0;
  let suppressBlurClose = false;

  const openMenu    = ()=> { const items = buildMenuItems(input); idx = 0; renderSuggest(menuEl, items, idx); };
  const refreshMenu = ()=> { if (menuEl.classList.contains('hidden')) return; const items = buildMenuItems(input); idx = Math.min(idx, items.length-1); renderSuggest(menuEl, items, idx); };
  const closeMenu   = ()=> { hideSuggest(menuEl); };

  input.addEventListener('focus', openMenu);

  // Close when input loses focus *and* the new focus isn't inside the menu
  input.addEventListener('focusout', (e)=>{
    // If the next focused element is inside the menu (e.g., during click),
    // let the menu handler decide; otherwise close.
    const to = e.relatedTarget;
    if (!to || !to.closest || !to.closest('#q-menu')) {
      closeMenu();
    }
  });

  // Also close on click/tap anywhere outside input+menu (robust on mobile)
  // Use capture so it runs before other handlers that might stopPropagation.
  const outsideCloser = (e)=>{
    const t = e.target;
    if (!t.closest('#q') && !t.closest('#q-menu')) closeMenu();
  };
  document.addEventListener('pointerdown', outsideCloser, true);

  // Clean up listener if you ever re-init setupSearchUI (optional)
  window.addEventListener('beforeunload', ()=> {
    document.removeEventListener('pointerdown', outsideCloser, true);
  });

  input.addEventListener('input', ()=>{
    refreshMenu();
    renderDexList();
  });

  input.addEventListener('keydown', (e)=>{
    const items = Array.from(menuEl.querySelectorAll('.item'));
    if (e.key === 'Tab'){ closeMenu(); return; }   // tab away = close
    if (!items.length) return;
    if (e.key === 'ArrowDown'){ e.preventDefault(); idx = (idx+1)%items.length; renderSuggest(menuEl, buildMenuItems(input), idx); }
    else if (e.key === 'ArrowUp'){ e.preventDefault(); idx = (idx-1+items.length)%items.length; renderSuggest(menuEl, buildMenuItems(input), idx); }
    else if (e.key === 'Enter'){
      e.preventDefault();
      const it = items[idx];
      applyMenuChoice(input, {
        mode: it.dataset.mode,
        key: it.dataset.key,
        prefix: it.dataset.prefix,
        label: it.dataset.value
      });
      idx = 0;
      renderSuggest(menuEl, buildMenuItems(input), idx);
    }
    else if (e.key === 'Escape'){ closeMenu(); }
    else { setTimeout(refreshMenu, 0); }
  });

  // Keep menu open when clicking a suggestion
  menuEl.addEventListener('mousedown', (e)=>{
    e.preventDefault();                 // keep focus in input (no blur)
    const it = e.target.closest('.item'); if(!it) return;
    applyMenuChoice(input, {
      mode: it.dataset.mode,
      key: it.dataset.key,
      prefix: it.dataset.prefix,
      label: it.dataset.value
    });
    idx = 0;
    renderSuggest(menuEl, buildMenuItems(input), idx);
    input.focus();
  });
}

if (document.readyState !== 'loading') { setupSearchUI(); adjustHeaderOffset(); }
else document.addEventListener('DOMContentLoaded', () => { setupSearchUI(); adjustHeaderOffset(); });

export function renderDexList() {
  const qRaw = getQuery();
  const tokens = splitQuery(qRaw);
  let list = INDEX;

  if (tokens.length) {
    list = INDEX.filter(s => {
      // precompute haystacks per entry
      const display   = norm(tName(s, s.name) || s.name || '');
      const typesArr  = (s.types || []).map(norm);
      const abilsArr  = (s.abilities || []).map(norm);
      const movesArr  = (s.moves || []).map(norm);

      const typesStr  = typesArr.join(' ');
      const abilsStr  = abilsArr.join(' ');
      const movesStr  = movesArr.join(' ');
      const dexStr    = norm(String(s.dex));

      // build a predicate per token
      return tokens.every(tokRaw => {
        const tok = norm(tokRaw);
        // prefixed?
        const m = tok.match(/^(\w+):(.*)$/);
        if (m) {
          const [, prefix, val] = m;
          if (!val) return true; // empty value -> ignore
          switch (prefix) {
            case 'pokemon':
            case 'poke':
            case 'name':
              return display.startsWith(val);

            case 'move':
            case 'moves':
              return movesArr.some(m => m.startsWith(val));

            case 'ability':
            case 'abilities':
              return abilsArr.some(a => a.startsWith(val));

            case 'type':
            case 'types':
              return typesArr.some(t => t.startsWith(val));

            default:
              // keep broad fallback as "contains" so unprefixed queries behave like before
              return (
                dexStr.includes(tok) ||
                display.includes(tok) ||
                typesStr.includes(tok) ||
                abilsStr.includes(tok) ||
                movesStr.includes(tok)
              );
          }
        }
        // no prefix: broad match (legacy behavior)
        return (
          dexStr.includes(tok) ||
          display.includes(tok) ||
          typesStr.includes(tok) ||
          abilsStr.includes(tok) ||
          movesStr.includes(tok)
        );
      });
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
