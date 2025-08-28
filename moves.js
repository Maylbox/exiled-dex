// moves.js
// Move metadata lookup + UI chips

import { MOVE_TYPES } from './dataLoader.js';

/**
 * Lookup move metadata (type, category, etc.) by name.
 * Expects MOVE_TYPES to be a map: { "<Move Name>": { type, category, ... } }
 */
export function moveInfo(name) {
  if (!name) return null;
  // Try exact first, then case-insensitive fallback
  return (
    MOVE_TYPES?.[name] ??
    MOVE_TYPES?.[String(name).toLowerCase()] ??
    MOVE_TYPES?.[String(name).toUpperCase()] ??
    null
  );
}

/**
 * Returns an <img> icon HTML for Physical/Special categories.
 * Status (or unknown) returns an empty string.
 */
export function moveIcon(category) {
  const c = String(category || '').toLowerCase();
  if (c === 'physical' || c === 'special') {
    return `<img class="icon" src="assets/icons/move-${c}.png" alt="${category}">`;
  }
  return '';
}

/**
 * Renders a colored chip for a move with optional type class and category icon.
 * Links to `#move/<slug>`.
 */
export function moveChip(name) {
  const info = moveInfo(name);
  const typeCls = info?.type ? `type-${info.type}` : '';
  const icon = moveIcon(info?.category);
  const slug = String(name)
    .toLowerCase()
    .replace(/[^a-z0-9]+/g, '-')
    .replace(/(^-|-$)/g, '');
  return `<a class="badge move ${typeCls} filled" href="#move/${slug}">${icon}${name}</a>`;
}
