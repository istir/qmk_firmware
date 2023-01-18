/* istir - 26.11.2022
 * This file removes automatic deactivation of caps word on some, if not all, keys
 */

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;
#ifdef CAPS_WORD_NO_AUTO_DEACTIVATION
        default:
            return true; // Continue Caps Word.
#else
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
#endif
    }
}