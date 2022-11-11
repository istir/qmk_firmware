/* istir - 11.11.2022
 * This file handles knob rotation. Notable cases:
 * Knob
 */

#include QMK_KEYBOARD_H

const int VOLUME_MULTIPLICATION = 2;

bool is_knob_pressed                   = false;
bool should_send_play_pause_on_release = true;
bool is_fn2_pressed                    = false;

/* ------------------------------- knob press ------------------------------- */
bool process_play_pause_rotary_encoder(keyrecord_t *record) {
    if (record->event.pressed) {
        should_send_play_pause_on_release = true;
        is_knob_pressed                   = true;
        return false;
    } else {
        is_knob_pressed = false;
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
        is_fn2_pressed = true;
    } else {
        is_fn2_pressed = false;
    }
    return true;
}

/* ------------------------------ knob rotation ----------------------------- */
void handle_clockwise_knob_rotation(void) {
    if (is_knob_pressed) {
        tap_code(KC_MNXT);
    } else if (is_fn2_pressed) {
        rgblight_increase_val();
    } else {
        for (int i = 0; i < VOLUME_MULTIPLICATION; i++) {
            tap_code(KC_VOLU);
        }
    }
}

void handle_counterclockwise_knob_rotation(void) {
    if (is_knob_pressed) {
        tap_code(KC_MPRV);
    } else if (is_fn2_pressed) {
        rgblight_decrease_val();
    } else {
        for (int i = 0; i < VOLUME_MULTIPLICATION; i++) {
            tap_code(KC_VOLD);
        }
    }
}

/* ----------------- determine what should happen with knob ----------------- */
bool encoder_update_user(uint8_t index, bool clockwise) {
    clockwise ? handle_clockwise_knob_rotation() : handle_counterclockwise_knob_rotation();
    is_knob_pressed                   = false;
    should_send_play_pause_on_release = false;
    return false;
}
