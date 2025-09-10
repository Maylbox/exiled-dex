// keybinds.js — central keyboard shortcuts (scoped + global)

// ---------- helpers ----------
function inEditable(e) {
  const t = e.target, tag = (t?.tagName || '').toLowerCase();
  return t?.isContentEditable || tag === 'input' || tag === 'textarea' || tag === 'select';
}
function onDexDetail() {
  // #dex/<number>/<SPECIES_ID>
  return /^#dex\/\d+\/[^/]+$/.test(location.hash || '');
}

// ---------- 1) Global: left/right arrows navigate prev/next on the detail page ----------
export function setupDexDetailArrowNav() {
  if (window.__dexArrowsBound) return; // prevent double-binding in dev/HMR
  window.__dexArrowsBound = true;

  window.addEventListener('keydown', (e) => {
    if (!onDexDetail()) return;
    if (inEditable(e)) return;
    if (e.altKey || e.ctrlKey || e.metaKey || e.shiftKey) return;
    if (e.key !== 'ArrowLeft' && e.key !== 'ArrowRight') return;

    const sel = e.key === 'ArrowLeft' ? '.dex-nav-btn.prev' : '.dex-nav-btn.next';
    const btn = document.querySelector(sel);
    if (btn) { e.preventDefault(); btn.click(); }
  });
}

// ---------- 2) Scoped: keybinds for the Dex List search suggest menu ----------
export function setupSearchKeybinds({ input, menuEl, buildMenuItems, renderSuggest, applyMenuChoice, closeMenu }) {
  if (!input || !menuEl) return () => {};

  let idx = 0;

  const keyHandler = (e) => {
    const items = Array.from(menuEl.querySelectorAll('.item'));
    if (e.key === 'Tab') { closeMenu(); return; }
    if (!items.length) return;

    if (e.key === 'ArrowDown') {
      e.preventDefault();
      idx = (idx + 1) % items.length;
      renderSuggest(menuEl, buildMenuItems(input), idx);
    } else if (e.key === 'ArrowUp') {
      e.preventDefault();
      idx = (idx - 1 + items.length) % items.length;
      renderSuggest(menuEl, buildMenuItems(input), idx);
    } else if (e.key === 'Enter') {
      e.preventDefault();
      const it = items[idx];
      if (!it) return;
      applyMenuChoice(input, {
        mode:   it.dataset.mode,
        key:    it.dataset.key,
        prefix: it.dataset.prefix,
        label:  it.dataset.value
      });
      idx = 0;
      renderSuggest(menuEl, buildMenuItems(input), idx);
    } else if (e.key === 'Escape') {
      closeMenu();
    }
  };

  input.addEventListener('keydown', keyHandler);
  return () => input.removeEventListener('keydown', keyHandler);
}
// ---------- 3) Global: ESC navigates back (without touching inputs) ----------
export function setupEscapeBackNav() {
  if (window.__escBackBound) return; // avoid double-binding (HMR, etc.)
  window.__escBackBound = true;

  window.addEventListener('keydown', (e) => {
    // Let inputs/textarea/select/contenteditable keep Esc for themselves
    if (inEditable(e)) return;
    if (e.altKey || e.ctrlKey || e.metaKey || e.shiftKey) return;
    if (e.key !== 'Escape') return;

    // If we're not on home, try to go back. If there's no history entry, fall back to home.
    const before = location.hash;
    if (!before) return; // already on home

    e.preventDefault();
    history.back();

    // Fallback: if nothing changed after a tick, clear the hash to go home.
    requestAnimationFrame(() => {
      setTimeout(() => {
        if (location.hash === before) {
          location.hash = ''; // home
        }
      }, 0);
    });
  });
}
