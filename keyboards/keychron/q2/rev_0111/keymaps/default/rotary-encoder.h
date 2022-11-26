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

bool should_send_play_pause_on_release    = true;
int  number_of_clockwise_rotations        = 0;
int  number_of_counterclockwise_rotations = 0;


/* ------------------------------- knob press ------------------------------- */
bool process_play_pause_rotary_encoder(keyrecord_t *record) {
    if (record->event.pressed) {
        if (!get_knob_pressed_state()) {
            number_of_clockwise_rotations        = 0;
            number_of_counterclockwise_rotations = 0;
        }
        should_send_play_pause_on_release = true;
        set_knob_pressed_state(true);
        return false;
    } else {
        set_knob_pressed_state(false);
        if (should_send_play_pause_on_release) {
            tap_code(DEFAULT_LAYER_KNOB_PRESS_ACTION);
        }
        return true;
    }
    return false;
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
    if (get_knob_pressed_state()) {
        if (check_if_should_process_rotation(clockwise)) {
            tap_code(clockwise ? KC_MNXT : KC_MPRV);
        }
    } else {
        //* when fn1 is pressed
        if (get_fn1_pressed_state()) {
            tap_code(clockwise?KC_F14:KC_F13);
            return;
        }
        //* when fn2 is pressed
        if (get_fn2_pressed_state()) {
            clockwise ? rgblight_increase_val() : rgblight_decrease_val();
            preset_brightnesses[current_preset] = rgb_matrix_config.hsv.v;
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
