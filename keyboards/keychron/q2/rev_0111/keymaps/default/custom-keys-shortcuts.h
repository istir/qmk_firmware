/* istir - 26.11.2022
 * This file is used for custom shortcuts and combos
 */

#ifdef COMBO_ENABLE

enum combos {
    REGION_SCREENSHOT,
    // SAVE_AMD_VIDEO,
    RECORD_VIDEO,
    FULL_SCREENSHOT,
    CUSTOM_COMBO_LENGTH
};
const uint16_t COMBO_LEN = CUSTOM_COMBO_LENGTH; // number of combos

const uint16_t PROGMEM region_screenshot_combo[] = {KC_DEL, KC_HOME, COMBO_END};
// const uint16_t PROGMEM save_amd_video_combo[]    = {KC_BSLS, KC_BACKSPACE, COMBO_END};
const uint16_t PROGMEM record_video_combo[]    = {KC_BSLS, KC_HOME, COMBO_END};
const uint16_t PROGMEM full_screenshot_combo[] = {KC_BSLS, KC_DEL, COMBO_END};

combo_t key_combos[CUSTOM_COMBO_LENGTH] = {

    [REGION_SCREENSHOT] = COMBO(region_screenshot_combo, KC_PRINT_SCREEN),
    [RECORD_VIDEO]      = COMBO(record_video_combo, LWIN(LCTL(KC_BSLS))),
    [FULL_SCREENSHOT]   = COMBO(full_screenshot_combo, KC_F9)};

#endif

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t REGION_OVERRIDE_SCREENSHOT = ko_make_with_layers_negmods_and_options(MOD_MASK_SG, KC_S, KC_PRINT_SCREEN, (1 << 1), MOD_MASK_CA, ko_option_no_reregister_trigger);
const key_override_t SEARCH_OVERRIDE            = ko_make_with_layers_negmods_and_options(MOD_MASK_GUI, KC_A, LWIN(LCTL(KC_A)), (1 << 1), MOD_MASK_CSA, ko_option_no_reregister_trigger);
const key_override_t SEARCH_OVERRIDE_MAC_LIKE   = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_SPACE, LWIN(LCTL(KC_A)), (1 << 1), MOD_MASK_CSG, ko_option_no_reregister_trigger);
const key_override_t EVERYTHING_SEARCH_OVERRIDE = ko_make_with_layers_negmods_and_options(MOD_MASK_GUI, KC_S, LWIN(LALT(KC_S)), (1 << 1), MOD_MASK_CSA, ko_option_no_reregister_trigger);
const key_override_t CLOSE_WINDOW_OVERRIDE      = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_Q, LALT(KC_F4), (1 << 1), MOD_MASK_SG, ko_option_no_reregister_trigger);
const key_override_t OPEN_TERMINAL_OVERRIDE     = ko_make_with_layers_negmods_and_options(MOD_MASK_GUI, KC_RETURN, LCTL(LALT(KC_LBRACKET)), (1 << 1), MOD_MASK_CSA, ko_option_no_reregister_trigger);
const key_override_t CAPSLOCK_TOGGLE            = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_RCTL, KC_CAPS, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
//* Mac-like combos

// const key_override_t COPY_OVERRIDE         = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_C, LCTL(KC_C), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t CUT_OVERRIDE          = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_X, LCTL(KC_X), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t PASTE_OVERRIDE        = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_V, LCTL(KC_V), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t SELECT_ALL_OVERRIDE   = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_A, LCTL(KC_A), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t SEARCH_BASIC_OVERRIDE = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_F, LCTL(KC_F), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t HISTORY_OVERRIDE      = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_H, LCTL(KC_H), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t URL_CURSOR_OVERRIDE   = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_L, LCTL(KC_L), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t RELOAD_OVERRIDE       = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_R, LCTL(KC_R), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t SAVE_OVERRIDE         = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_S, LCTL(KC_S), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t FORWARD_OVERRIDE      = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_Y, LCTL(KC_Y), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t BACK_OVERRIDE         = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_Z, LCTL(KC_Z), ~0, MOD_MASK_CSG, ko_option_activation_negative_mod_up);
// const key_override_t COPY_OVERRIDE         = ko_make_basic(MOD_MASK_ALT, KC_C, LCTL(KC_C));
// const key_override_t CUT_OVERRIDE          = ko_make_basic(MOD_MASK_ALT, KC_X, LCTL(KC_X));
// const key_override_t PASTE_OVERRIDE        = ko_make_basic(MOD_MASK_ALT, KC_V, LCTL(KC_V));
// const key_override_t SELECT_ALL_OVERRIDE   = ko_make_basic(MOD_MASK_ALT, KC_A, LCTL(KC_A));
// const key_override_t SEARCH_BASIC_OVERRIDE = ko_make_basic(MOD_MASK_ALT, KC_F, LCTL(KC_F));
// const key_override_t HISTORY_OVERRIDE      = ko_make_basic(MOD_MASK_ALT, KC_H, LCTL(KC_H));
// const key_override_t URL_CURSOR_OVERRIDE   = ko_make_basic(MOD_MASK_ALT, KC_L, LCTL(KC_L));
// const key_override_t RELOAD_OVERRIDE       = ko_make_basic(MOD_MASK_ALT, KC_R, LCTL(KC_R));
// const key_override_t SAVE_OVERRIDE         = ko_make_basic(MOD_MASK_ALT, KC_S, LCTL(KC_S));
// const key_override_t FORWARD_OVERRIDE      = ko_make_basic(MOD_MASK_ALT, KC_Y, LCTL(KC_Y));
// const key_override_t BACK_OVERRIDE         = ko_make_basic(MOD_MASK_ALT, KC_Z, LCTL(KC_Z));
// const key_override_t HARD_RELOAD_OVERRIDE  = ko_make_basic(MOD_MASK_SA, KC_R, LCTL(KC_R));
// const key_override_t REOPEN_TAB_OVERRIDE   = ko_make_basic(MOD_MASK_SA, KC_T, LCTL(KC_T));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &REGION_OVERRIDE_SCREENSHOT, &CLOSE_WINDOW_OVERRIDE, &OPEN_TERMINAL_OVERRIDE, &SEARCH_OVERRIDE, &SEARCH_OVERRIDE_MAC_LIKE, &EVERYTHING_SEARCH_OVERRIDE,
    // mac
    // &COPY_OVERRIDE,
    // &CUT_OVERRIDE,
    // &PASTE_OVERRIDE,
    // &SELECT_ALL_OVERRIDE,
    // &SEARCH_BASIC_OVERRIDE,
    // &HISTORY_OVERRIDE,
    // &URL_CURSOR_OVERRIDE,
    // &RELOAD_OVERRIDE,
    // &SAVE_OVERRIDE,
    // &FORWARD_OVERRIDE,
    // &BACK_OVERRIDE,
    // &HARD_RELOAD_OVERRIDE,
    // &REOPEN_TAB_OVERRIDE,

    NULL // Null terminate the array of overrides!
};
#endif
