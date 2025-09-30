// trainersLoader.js
// Fetch + parse trainers.party into normalized JS objects.

import { fetchJSON } from './dataLoader.js'; // for parity; we’ll use our own fetchText here

export const TRAINERS_DATA_URL = 'data/trainers/trainers.party';

// in-memory caches
let TRAINERS_INDEX = [];                // lightweight cards [{id,name,class,pic,gender,double,partyCount,firstMon}]
const TRAINERS_BY_ID = new Map();       // id -> full trainer object

async function fetchText(url) {
  const res = await fetch(url, { cache: 'no-store' });
  if (!res.ok) throw new Error(`Failed to fetch ${url} (${res.status})`);
  return res.text();
}

// --- parsing helpers ---

// Parse "31 HP / 31 Atk / 31 Def / ..." into an object {hp:31, atk:31, ...}
function parseSlashStats(line) {
  // line after "IVs:" or "EVs:"
  const out = {};
  const map = { hp:'hp', atk:'atk', def:'def', spa:'spa', spd:'spd', spe:'spe', sp:'spe', spd2:'spd' };
  for (const part of line.split('/')) {
    const m = part.trim().match(/^(\d+)\s*(HP|Atk|Def|SpA|SpD|Spe|Spd)$/i);
    if (!m) continue;
    const val = Number(m[1]);
    const key = m[2].toLowerCase();
    const norm =
      key === 'spa' ? 'spa' :
      key === 'spd' ? 'spd' :
      key === 'spe' || key === 'spd2' || key === 'sp' ? 'spe' :
      key === 'atk' ? 'atk' :
      key === 'def' ? 'def' :
      'hp';
    out[norm] = val;
  }
  return out;
}

// Try to pull Species / Nick / Gender / Item from the first line of a Pokémon block.
// Accepts:
//   "Alfred (Abra) (M) @ Eviolite"
//   "Roberta (SPECIES_ABRA) (F) @ ITEM_CHOICE_SPECS"
//   "Golurk"  (bare species)
// Returns { speciesRaw, nickname, gender, itemRaw }
function parsePokemonHeader(line) {
  // normalize @ item
  const [left, itemRaw] = line.split('@').map(s => s.trim());
  const item = itemRaw || null;

  // nickname (Species) (M/F)
  const nickSpecies = left.match(/^(.+?)\s*\(([^)]+)\)(?:\s*\((M|F)\))?$/);
  if (nickSpecies) {
    return {
      nickname: nickSpecies[1].trim() || null,
      speciesRaw: nickSpecies[2].trim(),
      gender: nickSpecies[3] || null,
      itemRaw: item,
    };
  }

  // bare "SPECIES_ABRA" or "Abra"
  return {
    nickname: null,
    speciesRaw: left,
    gender: null,
    itemRaw: item,
  };
}

// Convert "Yes/No" like fields to boolean (default false)
function yesNo(s) {
  const v = String(s || '').trim().toLowerCase();
  if (!v) return false;
  return v === 'yes' || v === 'true' || v === '1';
}

// --- main parse function ---
export async function loadTrainers() {
  if (TRAINERS_INDEX.length) return { index: TRAINERS_INDEX, byId: TRAINERS_BY_ID };

  // NOTE: place a copy at data/trainers.party in your repo for GH Pages
  const raw = await fetchText(TRAINERS_DATA_URL);

  // Strip C-style /* ... */ blocks, then split into blocks by === TRAINER_... ===
  const stripped = raw.replace(/\/\*[\s\S]*?\*\//g, '\n');
  const blocks = stripped.split(/\n===\s*(TRAINER_[A-Z0-9_]+)\s*===\s*\n/);

  // blocks looks like ["preamble","TRAINER_X","rest...","TRAINER_Y","rest...", ...]
  for (let i = 1; i < blocks.length; i += 2) {
    const id = blocks[i].trim();
    const body = (blocks[i + 1] || '').trim();

    // Split trainer header + party by first blank line that is followed by a non-empty line (start of Pokémon)
    const lines = body.split(/\r?\n/);
    const trainer = { id, fields:{}, party: [] };

    // Read header key: value until we hit a blank followed by non-blank (start of first mon)
    let p = 0;
    for (; p < lines.length; p++) {
      const line = lines[p].trim();
      if (!line) { p++; break; }              // stop at the first blank
      const kv = line.match(/^([\w\s]+):\s*(.*)$/);
      if (kv) {
        const key = kv[1].trim();
        const val = kv[2].trim();
        trainer.fields[key] = val;
      } else {
        // If we see a line without "Key:" we’ve already entered the Pokémon section
        break;
      }
    }

    // Parse Pokémon blocks (Showdown style)
    while (p < lines.length) {
      // skip empty spacing
      while (p < lines.length && !lines[p].trim()) p++;
      if (p >= lines.length) break;

      const header = lines[p++].trim();
      if (!header) break;

      const poke = {
        ...parsePokemonHeader(header),
        level: null, ability: null, nature: null, shiny: false,
        dynamaxLevel: null, gigantamax: null, teraType: null,
        ivs: null, evs: null, moves: [],
      };

      // read until next blank line
      while (p < lines.length && lines[p].trim()) {
        const line = lines[p++].trim();

        // moves: "- Tackle" or "- MOVE_TACKLE"
        if (/^-\s+/.test(line)) {
          poke.moves.push(line.replace(/^-\s+/, '').trim());
          continue;
        }

        const m = line.match(/^([\w ]+):\s*(.*)$/);
        if (!m) continue;
        const key = m[1].trim().toLowerCase();
        const val = m[2].trim();

        if (key === 'level') poke.level = Number(val);
        else if (key === 'ability') poke.ability = val;
        else if (key === 'ivs') poke.ivs = parseSlashStats(val);
        else if (key === 'evs') poke.evs = parseSlashStats(val);
        else if (key === 'nature') poke.nature = val;
        else if (key === 'shiny') poke.shiny = yesNo(val);
        else if (key === 'dynamax level') poke.dynamaxLevel = Number(val);
        else if (key === 'gigantamax') poke.gigantamax = yesNo(val);
        else if (key === 'tera type') poke.teraType = val;
        else if (key === 'ball') poke.ball = val;
        else if (key === 'happiness') poke.happiness = Number(val);
      }
      trainer.party.push(poke);
      // skip the blank line separator (if any) is already handled by the while loop start
    }

    // Normalize some common header fields
    const f = trainer.fields;
    const name   = (f.Name || '').trim() || id;
    const cls    = (f.Class || 'Pkmn Trainer').trim();
    const pic    = (f.Pic || '').trim();           // hook for future mugshot art
    const gender = (f.Gender || '').trim();
    const music  = (f.Music || '').trim();
    const double = yesNo(f['Double Battle']);
    const items  = (f.Items || '')
      .split('/')
      .map(s => s.replace(/^ITEM_/, '').trim())
      .filter(Boolean);

    const ai     = (f.AI || '')
      .split('/')
      .map(s => s.trim())
      .filter(Boolean);

    const entry = {
      id, name, class: cls, pic, gender, music, double, items, ai, party: trainer.party
    };

    TRAINERS_BY_ID.set(id, entry);

    TRAINERS_INDEX.push({
      id,
      name,
      class: cls,
      gender,
      double,
      partyCount: entry.party.length,
      firstMon: entry.party[0] || null,
    });
  }

  // stable sort: by name then id
  TRAINERS_INDEX.sort((a, b) => a.name.localeCompare(b.name) || a.id.localeCompare(b.id));

  return { index: TRAINERS_INDEX, byId: TRAINERS_BY_ID };
}

export function getTrainerIndex() { return TRAINERS_INDEX; }
export function getTrainerById(id) { return TRAINERS_BY_ID.get(id) || null; }
