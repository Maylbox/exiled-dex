// dataLoader.js
// Centralized data + state loader. No DOM, no routing — just fetch and expose state.

export const DATA_DIR = 'data/';

// --- mutable state (populated by init) ---
export let INDEX = [];
export let DEX_MAX = 0;
export let DEX_ORDER = [];
export let SPRITE_OVERRIDES = {};
export let DEX_TO_FIRST = new Map();

/**
 * I18N buckets:
 * - area:   area key -> label
 * - bucket: encounter bucket key -> label
 * - names:  speciesId -> display name (overrides)
 */
export let I18N = { area: {}, bucket: {}, names: {} };

export let MOVE_TYPES = {};  // { "Tackle": { type:"Normal", category:"Physical" }, ... }
export let FORMS_MAP  = {};  // { SPECIES_PIKACHU: { ROCK_STAR: "rock_star", ... }, ... }

// --- helpers exposed ---
export async function fetchJSON(url) {
  const res = await fetch(url, { cache: 'no-store' });
  if (!res.ok) throw new Error(`Failed to fetch ${url} (${res.status})`);
  return res.json();
}

export function tArea(key, fallback) {
  return (I18N.area && I18N.area[key]) || fallback || key;
}
export function tBucket(key, fallback) {
  return (I18N.bucket && I18N.bucket[key]) || fallback || key;
}

/** Resolve a display name for a species. Accepts a speciesId string or an INDEX/species entry. */
export function tName(speciesIdOrEntry, fallback) {
  const sid = typeof speciesIdOrEntry === 'string'
    ? speciesIdOrEntry
    : (speciesIdOrEntry?.speciesId || '');
  return I18N.names?.[sid] || fallback || (typeof speciesIdOrEntry === 'object' ? speciesIdOrEntry?.name : sid);
}

/**
 * Load all static data files and build derived indexes.
 * - data/index.json
 * - data/mods/blacklist.json (optional)
 * - data/mods/forms.json (optional)
 * - data/i18n/areas.json (optional)
 * - data/mods/names.json (optional)  <-- display-name overrides
 * - data/move_types.json (optional)
 */
export async function init() {
  // Load core lists (index + optional mods)
  const [index, blacklist, forms, spriteOverrides] = await Promise.all([
    fetchJSON(`${DATA_DIR}index.json`),
    fetchJSON(`${DATA_DIR}mods/blacklist.json`).catch(() => []),
    fetchJSON(`${DATA_DIR}mods/forms.json`).catch(() => ({})),
    fetchJSON(`${DATA_DIR}mods/sprites.json`).catch(() => ({})),
  ]);

  FORMS_MAP = forms || {};
  SPRITE_OVERRIDES = spriteOverrides || {};

  // Filter blacklisted species (case-insensitive on speciesId)
  const blocked = new Set((blacklist || []).map((x) => String(x).toUpperCase()));
  INDEX = (index || []).filter((entry) => !blocked.has(String(entry.speciesId).toUpperCase()));

  // Stable sort: by dex then by localized/display name (fallback to raw name here)
  INDEX.sort((a, b) => {
    if (a.dex !== b.dex) return (a.dex || 0) - (b.dex || 0);
    return String(a.name).localeCompare(String(b.name));
  });

  // Derived aggregates
  DEX_MAX = INDEX.reduce((m, e) => Math.max(m, Number(e.dex) || 0), 0);
  DEX_ORDER = [...new Set(INDEX.map((e) => e.dex))].sort((a, b) => a - b);
  DEX_TO_FIRST = new Map();
  for (const e of INDEX) {
    if (!DEX_TO_FIRST.has(e.dex)) DEX_TO_FIRST.set(e.dex, e);
  }

  // Optional i18n (areas/buckets)
  try {
    const i = await fetchJSON(`${DATA_DIR}i18n/areas.json`);
    I18N.area   = (i && i.area)   || {};
    I18N.bucket = (i && i.bucket) || {};
  } catch {
    I18N.area   = I18N.area   || {};
    I18N.bucket = I18N.bucket || {};
  }

  // Optional display-name overrides (mods/names.json)
  // File can be either { "names": { SPECIES_X: "Label", ... } } or flat { SPECIES_X: "Label", ... }
  try {
    const n = await fetchJSON(`${DATA_DIR}mods/names.json`);
    I18N.names = (n && (n.names || n)) || {};
  } catch {
    I18N.names = {};
  }

  // Optionally attach a convenience field so existing code can read `entry.displayName`
  // (safe: adds property, does not change sort order)
  if (INDEX && I18N.names && Object.keys(I18N.names).length) {
    INDEX = INDEX.map(e => ({ ...e, displayName: I18N.names[e.speciesId] || e.name }));
  }

  // Optional move → type/category map
  try {
    MOVE_TYPES = await fetchJSON(`${DATA_DIR}move_types.json`);
  } catch {
    MOVE_TYPES = {};
  }
}
