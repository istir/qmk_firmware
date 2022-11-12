/* istir - 11.11.2022
 * This file handles knob rotation. Notable cases:
 * Knob triggers on release instead of on press
 * Holding down knob and rotating it does an action (skips songs)
 * Holding down a key and rotating knob does an action (changes RGB value)
 */

#include QMK_KEYBOARD_H

const int VOLUME_MULTIPLICATION = 2;

bool is_knob_pressed                   = false;
bool should_send_play_pause_on_release = true;
bool is_fn2_pressed                    = false;
bool should_process_knob_press         = true;

/* ------------------------------- knob press ------------------------------- */
bool process_play_pause_rotary_encoder(keyrecord_t *record) {
    if (record->event.pressed) {
        should_send_play_pause_on_release = true;
        is_knob_pressed                   = true;
        should_process_knob_press         = true;
        return false;
    } else {
        is_knob_pressed           = false;
        should_process_knob_press = false;
        if (should_send_play_pause_on_release) {
            tap_code(DEFAULT_LAYER_KNOB_PRESS_ACTION);
        }
        return true;
    }
    return false;
}

/* -------------------------------- FN2 press ------------------------------- */
bool process_fn2_key(keyrecord_t *record) {
    if (record->event.pressed) {
        is_fn2_pressed = true
    } else {
        is_fn2_pressed = false;
    }
    return true;
}

/* ------------------------------ knob rotation ----------------------------- */
void handle_knob_rotation(bool clockwise) {
    if (is_knob_pressed) {
        if (!should_process_knob_press) return;
        tap_code(clockwise ? KC_MNXT : KC_MPRV);
        should_process_knob_press = false;
    } else {
        if (is_fn2_pressed) {
            clockwise ? rgblight_increase_val() : rgblight_decrease_val();
        } else {
            for (int i = 0; i < VOLUME_MULTIPLICATION; i++) {
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
            }
        }
    }
}

/* ----------------- determine what should happen with knob ----------------- */
bool encoder_update_user(uint8_t index, bool clockwise) {
    handle_knob_rotation(clockwise);
    should_send_play_pause_on_release = false;
    return false;
}
