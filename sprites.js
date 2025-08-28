// sprites.js
// Sprite path resolution + fallback chain for images

import { FORMS_MAP, SPRITE_OVERRIDES } from './dataLoader.js';
import { makePlaceholder } from './uiUtils.js';

// ----- module-private constants -----
const SPRITE_ROOT = 'assets/pokemon/';
const REGION_TOKENS = {
  alolan:  ['alola',  'alolan'],
  hisuian: ['hisui',  'hisuian'],
  galarian:['galar',  'galarian'],
  paldean: ['paldea', 'paldean'],
};

// ----- helpers you export -----
export function splitSpeciesBaseAndForm(speciesId) {
  const sid = String(speciesId || '').toUpperCase().trim();
  const noPrefix = sid.replace(/^SPECIES_/, '');

  const GLOBAL_SUFFIXES = [
    'MEGA','MEGA_X','MEGA_Y','GIGANTAMAX',
    'ALOLA','ALOLAN','HISUI','HISUIAN','GALAR','GALARIAN','PALDEA','PALDEAN',
    'EXILED'
  ];

  let toks = noPrefix.split('_').filter(Boolean);
  if (!toks.length) {
    return { baseId: sid.startsWith('SPECIES_') ? sid : ('SPECIES_' + sid), formKey: null };
  }

  if (toks[0] === 'EXILED') toks = toks.slice(1);

  // trim global suffixes off the end
  let cut = toks.length;
  while (cut > 0 && GLOBAL_SUFFIXES.includes(toks[cut - 1])) cut--;

  // nidoran special-case
  if (toks[0] === 'NIDORAN' && (toks[1] === 'F' || toks[1] === 'M')) {
    const end = cut;
    const baseId = 'SPECIES_NIDORAN_' + toks[1];
    const tail   = toks.slice(2, end);
    const formKey = tail.length ? tail.join('_') : null;
    return { baseId, formKey };
  }

  // names that must keep underscore as base
  const KEEP_UNDERSCORE = new Set([
    'JANGMO_O','HAKAMO_O','KOMMO_O',
    'HO_OH','PORYGON_Z','MR_MIME','MIME_JR','TYPE_NULL',
  ]);

  const core = toks.slice(0, cut).join('_');
  if (KEEP_UNDERSCORE.has(core)) {
    return { baseId: 'SPECIES_' + core, formKey: null };
  }

  const baseToken = toks[0] || '';
  const tail = toks.slice(1, cut);
  const formKey = tail.length ? tail.join('_') : null;

  const baseId = 'SPECIES_' + baseToken;
  return { baseId, formKey };
}

export function speciesBaseFolder(speciesId, fallbackName) {
  const sid = String(speciesId || '').toUpperCase();
  const nm  = String(fallbackName || '');

  if (sid.startsWith('SPECIES_')) {
    const base = sid
      .replace(/^SPECIES_/, '')
      .replace(/^EXILED_/, '')
      .replace(/_EXILED\b.*/, '')
      .replace(/_(MEGA(?:_(?:X|Y))?|GIGANTAMAX|ALOLA|ALOLAN|HISUI|HISUIAN|GALAR|GALARIAN|PALDEA|PALDEAN).*$/, '');
    return base.toLowerCase().replace(/[^a-z0-9_-]+/g,'');
  }

  const baseFromName = nm.toLowerCase().trim()
    .replace(/^\s*exiled\s+/, '')
    .replace(/^\s*(alolan|hisuian|galarian|paldean)\s+/, '')
    .replace(/\s*-\s*(mega.*|alola.*|alolan.*|hisui.*|hisuian.*|galar.*|galarian.*|paldea.*|paldean.*)$/, '')
    .replace(/\s+/g,'_');
  return baseFromName.toLowerCase().replace(/[^a-z0-9_-]+/g,'');
}

/** Normalize any override value into an array of URLs (fallback chain). */
function normalizeOverrideValue(v) {
  if (!v) return [];
  if (typeof v === 'string') return [v];
  if (Array.isArray(v)) return v.filter(Boolean);
  if (typeof v === 'object') {
    // Common shapes:
    // { chain:[...paths] }
    if (Array.isArray(v.chain)) return v.chain.filter(Boolean);
    // { anim_front, front } → prefer anim then front
    const out = [];
    if (v.anim_front) out.push(v.anim_front);
    if (v.front) out.push(v.front);
    return out;
  }
  return [];
}

/**
 * Find an override chain for a species/form/variant, if any.
 * Supports:
 *   "SPECIES_PIKACHU": "custom/path.png"
 *   "SPECIES_PIKACHU": ["p1.png","p2.png"]
 *   "SPECIES_PIKACHU": { front:"...", anim_front:"..." }
 *   "SPECIES_ROTOM": { forms: { HEAT:{front:"..."}, WASH:{chain:[...]} } }
 *   "SPECIES_PIKACHU": { mega:{...}, alolan:{...}, ... } // per-variant
 */
function resolveOverrideChain(speciesId, formKey, variant) {
  const sid = String(speciesId || '').toUpperCase();
  const root = SPRITE_OVERRIDES?.[sid];
  if (!root) return [];

  // try per-form first if object
  if (formKey && typeof root === 'object' && root.forms) {
    const forForm = root.forms[formKey] || root.forms[formKey.replace(/_FORM$/, '')];
    if (forForm) {
      // allow nested variant override inside a form
      if (variant && typeof forForm === 'object' && forForm[variant]) {
        const v = normalizeOverrideValue(forForm[variant]);
        if (v.length) return v;
      }
      const v = normalizeOverrideValue(forForm);
      if (v.length) return v;
    }
  }

  // try variant level on the root object (e.g., { mega:{...}, alolan:{...} })
  if (variant && typeof root === 'object' && root[variant]) {
    const v = normalizeOverrideValue(root[variant]);
    if (v.length) return v;
  }

  // finally, apply the root override as-is
  return normalizeOverrideValue(root);
}

// ----- main export -----
export function spriteHTML(speciesId, name) {
  const sid = String(speciesId || '').toUpperCase();
  const nm  = String(name || '');

  // detect variants
  const isMegaX = /MEGA[_-]?X/.test(sid) || /\bmega\s*x\b/i.test(nm);
  const isMegaY = /MEGA[_-]?Y/.test(sid) || /\bmega\s*y\b/i.test(nm);
  const isMega  = (!isMegaX && !isMegaY) && (/_MEGA\b/.test(sid) || /\b-\s*mega\b/i.test(nm));
  let region = null;
  for (const [folder, toks] of Object.entries(REGION_TOKENS)) {
    if (toks.some(tok => sid.includes(tok.toUpperCase()) || nm.toLowerCase().includes(tok))) {
      region = folder;
      break;
    }
  }
  const isExiled = /^SPECIES_EXILED_/.test(sid) || /_EXILED\b/.test(sid) || /^\s*exiled\b/i.test(nm);
  const variant = isExiled ? 'exiled' : isMegaX ? 'mega_x' : isMegaY ? 'mega_y' : isMega ? 'mega' : region;

  // resolve base + form
  const { baseId, formKey } = splitSpeciesBaseAndForm(speciesId);
  const baseFolder = speciesBaseFolder(baseId, name);
  const baseDir    = `${SPRITE_ROOT}${baseFolder}`;
  const exiledDir  = `${SPRITE_ROOT}exiled_${baseFolder}`;

  // form subfolder via FORMS_MAP
  let formSubfolder = '';
  const mapForSpecies = FORMS_MAP[baseId];
  if (formKey && mapForSpecies) {
    formSubfolder = mapForSpecies[formKey]
                 ?? mapForSpecies[formKey.replace(/_FORM$/, '')]
                 ?? '';
  }
  const formDir = formSubfolder ? `${baseDir}/${formSubfolder}` : baseDir;

  // default chain
  const defaultChain = (variant === 'exiled'
    ? [
        `${exiledDir}/anim_front.png`,
        `${exiledDir}/front.png`,
        `${formDir}/anim_front.png`,
        `${formDir}/front.png`,
        `${baseDir}/anim_front.png`,
        `${baseDir}/front.png`,
      ]
    : variant
    ? [
        `${formDir}/${variant}/anim_front.png`,
        `${formDir}/${variant}/front.png`,
        `${formDir}/anim_front.png`,
        `${formDir}/front.png`,
        `${baseDir}/${variant}/anim_front.png`,
        `${baseDir}/${variant}/front.png`,
        `${baseDir}/anim_front.png`,
        `${baseDir}/front.png`,
      ]
    : [
        `${formDir}/anim_front.png`,
        `${formDir}/front.png`,
        `${baseDir}/mega_x/front.png`,
        `${baseDir}/mega_y/front.png`,
        `${baseDir}/mega/front.png`,
        `${baseDir}/alolan/front.png`,
        `${baseDir}/galarian/front.png`,
        `${baseDir}/hisuian/front.png`,
        `${baseDir}/paldean/front.png`,
        `${SPRITE_ROOT}exiled_${baseFolder}/anim_front.png`,
        `${SPRITE_ROOT}exiled_${baseFolder}/front.png`,
      ]);

  // override chain (prepended)
  const overrideChain = resolveOverrideChain(sid, formKey, variant) || [];

  // de-dupe while preserving order: overrides first, then defaults
  const seen = new Set();
  const chain = [...overrideChain, ...defaultChain].filter(p => {
    if (!p || seen.has(p)) return false;
    seen.add(p);
    return true;
  });

  const safeAlt = nm.replace(/"/g,'&quot;');
  const placeholder = makePlaceholder(nm);

  return `
    <img class="sprite ${variant && variant!=='exiled' ? '' : 'anim'}"
         src="${chain[0]}"
         data-fallback="${chain.slice(1).join('|')}"
         alt="${safeAlt}" loading="lazy"
         onerror="(function(img){
           const rest=(img.dataset.fallback||'').split('|').filter(Boolean);
           if(rest.length){ img.src=rest.shift(); img.dataset.fallback=rest.join('|'); }
           else{ img.src='${placeholder}'; }
         })(this)">
  `;
}

// ----- global error handler (advances data-fallback) -----
(function installSpriteErrorHandler(){
  if (window.__SPRITE_ERROR_HANDLER_INSTALLED__) return;
  window.__SPRITE_ERROR_HANDLER_INSTALLED__ = true;

  const DEBUG_SPRITES = false;

  document.addEventListener('error', function onImgError(ev){
    const img = ev.target;
    if (!(img instanceof HTMLImageElement)) return;

    const chain = img.dataset?.fallback || '';
    if (!chain) return;

    const rest = chain.split('|').filter(Boolean);
    const next = rest.shift();

    if (DEBUG_SPRITES) {
      console.warn('[sprite fallback]', { failed: img.src, next, remaining: rest });
    }

    if (next) {
      img.dataset.fallback = rest.join('|');
      img.src = next;
    } else {
      try {
        const label = img.getAttribute('alt') || '';
        img.src = makePlaceholder(label);
      } catch (_) {}
    }
  }, true);
})();
