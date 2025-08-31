// moves.js

import { MOVE_TYPES } from './dataLoader.js';

// --- normalize helper (ignore spaces, hyphens, dots, underscores, apostrophes)
function normMoveKey(s) {
  return String(s || '')
    .toLowerCase()
    .replace(/[\s\-\._']/g, '');
}

// Build a lookup once, carrying the original key label
let MOVE_LOOKUP = null;
function buildMoveLookup() {
  if (MOVE_LOOKUP) return MOVE_LOOKUP;
  const map = new Map();

  if (MOVE_TYPES && typeof MOVE_TYPES === 'object') {
    for (const [key, meta] of Object.entries(MOVE_TYPES)) {
      const norm = normMoveKey(key);
      // Store meta and remember the canonical label from the key
      const entry = {
        ...meta,
        // best-effort display fields:
        name: meta?.name || key,
        display: meta?.display || meta?.name || key,
        __label: key, // raw dictionary key (last-resort fallback)
      };
      map.set(norm, entry);

      // Also index any aliases if provided
      if (meta && Array.isArray(meta.aliases)) {
        for (const alias of meta.aliases) {
          map.set(normMoveKey(alias), entry);
        }
      }
    }
  }

  MOVE_LOOKUP = map;
  return MOVE_LOOKUP;
}

/** Lookup move metadata by flexible name (spacing/punct/case-insensitive). */
export function moveInfo(name) {
  if (!name) return null;
  const map = buildMoveLookup();
  return map.get(normMoveKey(name)) || null;
}

/** Physical/Special icon */
export function moveIcon(category) {
  const c = String(category || '').toLowerCase();
  if (c === 'physical' || c === 'special') {
    return `<img class="icon" src="assets/icons/move-${c}.png" alt="${category}">`;
  }
  return '';
}

/** Chip renderer */
export function moveChip(name) {
  const info = moveInfo(name);
  const typeCls = info?.type ? `type-${info.type}` : '';
  const icon = moveIcon(info?.category);

  // Use canonical label from data; fall back to the dictionary key if needed.
  const displayName = info?.display || info?.name || info?.__label || name;

  const slug = String(displayName)
    .toLowerCase()
    .replace(/[^a-z0-9]+/g, '-')
    .replace(/(^-|-$)/g, '');

  return `<a class="badge move ${typeCls} filled" href="#move/${slug}">${icon}${displayName}</a>`;
}
