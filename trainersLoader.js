// trainersLoader.js
// Fetch + parse trainers.party into normalized JS objects.

export const TRAINERS_DATA_URL = 'data/trainers/trainers.party';

// in-memory caches
let TRAINERS_INDEX = [];                // lightweight cards [{id,name,class,double,partyCount,firstMon,location}]
const TRAINERS_BY_ID = new Map();       // id -> full trainer object

async function fetchText(url) {
  // cache-bust during dev
  const res = await fetch(`${url}?v=${Date.now()}`, { cache: 'no-store' });
  if (!res.ok) throw new Error(`Failed to fetch ${url} (${res.status})`);
  return res.text();
}

// Parse "31 HP / 31 Atk / 31 Def / ..." into {hp:31, atk:31, ...}
function parseSlashStats(line) {
  const out = {};
  for (const part of String(line || '').split('/')) {
    const m = part.trim().match(/^(\d+)\s*(HP|Atk|Def|SpA|SpD|Spe|Spd)$/i);
    if (!m) continue;
    const val = Number(m[1]);
    const key = m[2].toLowerCase();
    const norm =
      key === 'spa' ? 'spa' :
      key === 'spd' ? 'spd' :
      key === 'spe' || key === 'sp' ? 'spe' :
      key === 'atk' ? 'atk' :
      key === 'def' ? 'def' : 'hp';
    out[norm] = val;
  }
  return out;
}

// First line of a Pokémon block -> species/nick/gender/item
function parsePokemonHeader(line) {
  const [left, itemRaw] = line.split('@').map(s => s.trim());
  const item = itemRaw || null;

  const nickSpecies = left.match(/^(.+?)\s*\(([^)]+)\)(?:\s*\((M|F)\))?$/);
  if (nickSpecies) {
    return {
      nickname: nickSpecies[1].trim() || null,
      speciesRaw: nickSpecies[2].trim(),
      gender: nickSpecies[3] || null,
      itemRaw: item,
    };
  }
  return { nickname: null, speciesRaw: left, gender: null, itemRaw: item };
}

function yesNo(s) {
  const v = String(s || '').trim().toLowerCase();
  return v === 'yes' || v === 'true' || v === '1';
}

// --- main parse function ---
export async function loadTrainers() {
  if (TRAINERS_INDEX.length) return { index: TRAINERS_INDEX, byId: TRAINERS_BY_ID };

  const raw = await fetchText(TRAINERS_DATA_URL);

  // Strip /* ... */ comments, split blocks like === TRAINER_X ===
  const stripped = raw.replace(/\/\*[\s\S]*?\*\//g, '\n');
  const blocks = stripped.split(/\r?\n===\s*(TRAINER_[A-Z0-9_]+)\s*===\s*\r?\n/);

  for (let i = 1; i < blocks.length; i += 2) {
    const id = blocks[i].trim();
    const body = (blocks[i + 1] || '').trim();

    const lines = body.split(/\r?\n/);
    const trainer = { id, fields: {}, party: [] };

    // Header key: value until the first blank line
    let p = 0;
    for (; p < lines.length; p++) {
      const line = lines[p].trim();
      if (!line) { p++; break; }
      const kv = line.match(/^([\w\s]+):\s*(.*)$/);
      if (kv) {
        trainer.fields[kv[1].trim()] = kv[2].trim();
      } else {
        break;
      }
    }

    // Pokémon blocks
    while (p < lines.length) {
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

      while (p < lines.length && lines[p].trim()) {
        const line = lines[p++].trim();
        if (/^-\s+/.test(line)) { poke.moves.push(line.replace(/^-\s+/, '').trim()); continue; }
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
    }

    // Normalize common header fields
    const f = trainer.fields;
    const name     = (f.Name || '').trim() || id;
    const cls      = (f.Class || 'Pkmn Trainer').trim();
    const pic      = (f.Pic || '').trim();
    const gender   = (f.Gender || '').trim();       // kept in data, not displayed
    const music    = (f.Music || '').trim();        // kept in data, not displayed
    const double   = yesNo(f['Double Battle']);
    const location = (f.Location || f.Area || f.Map || '').trim();

    const items = String(f.Items || '')
      .split('/')
      .map(s => s.replace(/^ITEM_/, '').trim())
      .filter(Boolean);

    const ai = String(f.AI || '')
      .split('/')
      .map(s => s.trim())
      .filter(Boolean);

    const entry = { id, name, class: cls, pic, gender, music, double, location, items, ai, party: trainer.party };
    TRAINERS_BY_ID.set(id, entry);

    TRAINERS_INDEX.push({
      id, name, class: cls, double,
      partyCount: entry.party.length,
      firstMon: entry.party[0] || null,
      location
    });
  }

  TRAINERS_INDEX.sort((a, b) => a.name.localeCompare(b.name) || a.id.localeCompare(b.id));
  return { index: TRAINERS_INDEX, byId: TRAINERS_BY_ID };
}

export function getTrainerIndex() { return TRAINERS_INDEX; }
export function getTrainerById(id) { return TRAINERS_BY_ID.get(id) || null; }
