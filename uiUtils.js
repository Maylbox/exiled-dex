// uiUtils.js
// Small pure helpers — no imports, all named exports

/** Optional shorthand for querySelector */
export const el = (s) => document.querySelector(s);

/** "hello_world" -> "Hello World" (preserves non-letters) */
export function titleize(s = '') {
  return String(s)
    .toLowerCase()
    .replace(/(^|[\s-])\w/g, (m) => m.toUpperCase());
}

/** Converts enum tokens into a nice label by removing a prefix and underscores. */
export function niceEnumToken(tok = '', prefix = '') {
  return titleize(String(tok).replace(prefix, '').replace(/_/g, ' '));
}

/** Pretty-print common enum-like params (ITEM_*, SPECIES_*, MOVE_*, ABILITY_*). */
export function prettyParam(param) {
  if (!param) return '';
  const p = String(param);
  if (/^ITEM_/.test(p))    return niceEnumToken(p, 'ITEM_');
  if (/^SPECIES_/.test(p)) return niceEnumToken(p, 'SPECIES_');
  if (/^MOVE_/.test(p))    return niceEnumToken(p, 'MOVE_');
  if (/^ABILITY_/.test(p)) return niceEnumToken(p, 'ABILITY_');
  return p;
}

/** Turns an evolution method token into a nice label. */
export function prettyMethod(method) {
  if (!method) return '';
  return titleize(String(method).replace(/^evo_?/i, '').replace(/_/g, ' '));
}

/** Array de-duplication by a key function. */
export function uniqBy(arr = [], key = (x) => x) {
  const seen = new Set();
  const out = [];
  for (const item of arr) {
    const k = key(item);
    if (!seen.has(k)) {
      seen.add(k);
      out.push(item);
    }
  }
  return out;
}

/** Format a possibly-null number, using an em dash when nullish. */
export function fmtNum(n) {
  return (n == null) ? '—' : String(n);
}

/** Format EV yield objects like { hp:2, atk:1 } -> "2 HP, 1 Atk" */
export function fmtEv(ev = {}) {
  const map = { hp: 'HP', atk: 'Atk', def: 'Def', spa: 'SpA', spd: 'SpD', spe: 'Spe' };
  const parts = Object.entries(ev)
    .filter(([, v]) => Number(v) > 0)
    .map(([k, v]) => `${v} ${map[k] || k.toUpperCase()}`);
  return parts.join(', ') || '—';
}

/** Map Pokédex color names to a UI accent hex value. */
export function colorToHex(name = '') {
  const T = {
    Black:  '#111111',
    Blue:   '#3b82f6',
    Brown:  '#8b5e3c',
    Gray:   '#6b7280',
    Green:  '#22c55e',
    Pink:   '#ec4899',
    Purple: '#8b5cf6',
    Red:    '#ef4444',
    White:  '#ADD8E6',
    Yellow: '#eab308',
  };
  return T[name] || '#8ab4ff';
}

/** Future routing stub for clickable chips: link to a dex search for now. */
export function chipHref(label = '') {
  return `#dex?q=${encodeURIComponent(String(label))}`;
}

/** SVG data-URL placeholder with the given text label. */
export function makePlaceholder(label = '') {
  const text = String(label).replace(/&/g, '&amp;').replace(/</g, '&lt;');
  const svg =
    `<svg xmlns='http://www.w3.org/2000/svg' width='512' height='512'>
       <rect width='100%' height='100%' fill='#0e0f11'/>
       <text x='50%' y='50%' dominant-baseline='middle' text-anchor='middle'
             font-family='Segoe UI, Roboto, Arial' font-size='48' fill='#6b7280'>${text}</text>
     </svg>`;
  return 'data:image/svg+xml;charset=utf-8,' + encodeURIComponent(svg);
}
