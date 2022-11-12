/* istir - 11.11.2022
 * This file handles knob rotation. Notable cases:
 * Knob triggers on release instead of on press
 * Holding down knob and rotating it does an action (skips songs)
 * Holding down a key and rotating knob does an action (changes RGB value)
 */

#include QMK_KEYBOARD_H

const int VOLUME_MULTIPLICATION                    = 2;
const int MAX_NUMBER_OF_CLOCKWISE_ROTATIONS        = 1;
const int MAX_NUMBER_OF_COUNTERCLOCKWISE_ROTATIONS = 2;

bool is_knob_pressed                      = false;
bool should_send_play_pause_on_release    = true;
int  number_of_clockwise_rotations        = 0;
int  number_of_counterclockwise_rotations = 0;

bool is_fn1_pressed = false;
bool is_fn2_pressed = false;

/* ------------------------------- knob press ------------------------------- */
bool process_play_pause_rotary_encoder(keyrecord_t *record) {
    if (record->event.pressed) {
        if (!is_knob_pressed) {
            number_of_clockwise_rotations        = 0;
            number_of_counterclockwise_rotations = 0;
        }
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

/* -------------------------------- FN1 press ------------------------------- */

bool process_fn1_key(keyrecord_t *record) {
    if (record->event.pressed) {
        is_fn1_pressed = true;
    } else {
        is_fn1_pressed = false;
    }
    return true;
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

bool check_if_should_process_rotation(bool clockwise) {
    if (clockwise) {
        if (number_of_clockwise_rotations <= MAX_NUMBER_OF_CLOCKWISE_ROTATIONS) return true;
        return false;
    }
    if (number_of_counterclockwise_rotations <= MAX_NUMBER_OF_COUNTERCLOCKWISE_ROTATIONS) return true;
    return false;
}

void handle_knob_rotation(bool clockwise) {
    if (is_knob_pressed) {
        if (check_if_should_process_rotation(clockwise)) {
            tap_code(clockwise ? KC_MNXT : KC_MPRV);
        }
    } else {
        //* when fn1 is pressed
        if (is_fn1_pressed) {
            clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();

            return;
        }
        //* when fn2 is pressed
        if (is_fn2_pressed) {
            clockwise ? rgblight_increase_val() : rgblight_decrease_val();
            return;
        }
        //* when nothing is pressed
        for (int i = 0; i < VOLUME_MULTIPLICATION; i++) {
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
        }
    }
}

/* ----------------- determine what should happen with knob ----------------- */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        number_of_clockwise_rotations += 1;
    } else {
        number_of_counterclockwise_rotations += 1;
    }
    handle_knob_rotation(clockwise);
    should_send_play_pause_on_release = false;
    return false;
}
