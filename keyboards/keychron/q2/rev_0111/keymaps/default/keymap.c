/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H



typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

//! tap dance enums
enum {
    TD_PLAY_NEXT_HOLD,
    TD_PLAY_NEXT
};

enum layers { MAC_BASE, WIN_BASE, _FN1, _FN2, _FN3 };

enum custom_keycodes { KC_MISSION_CONTROL = SAFE_RANGE, KC_LAUNCHPAD };

#define KC_WAVE S(KC_GRV)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_PNXT TD(TD_PLAY_NEXT)
#define KC_PHNT TD(TD_PLAY_NEXT_HOLD)
#define KC_FN1 MO(_FN1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[MAC_BASE] = LAYOUT_ansi_67(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_DEL, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LOPT, KC_LCMD, KC_SPC, KC_RCMD, KC_FN1, MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

                                                              [WIN_BASE] = LAYOUT_ansi_67(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PHNT, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_DEL, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

                                                              [_FN1] = LAYOUT_ansi_67(KC_GRV, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

                                                              [_FN2] = LAYOUT_ansi_67(KC_GRV, KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

                                                              [_FN3] = LAYOUT_ansi_67(KC_WAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

// #if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [_FN1] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}, [_FN2] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}, [_FN3] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};

// #endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false; // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}

bool is_interrupted_or_pressed(qk_tap_dance_state_t *state) {
    if (state->interrupted || state->pressed) return true;
    return false;
}

td_state_t get_current_dance_code(qk_tap_dance_state_t *state) {

     if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;



//     switch (state->count) {
//         case 1:
//             return is_interrupted_or_pressed(state) ? TD_SINGLE_TAP : TD_SINGLE_HOLD;
//         case 2:
//             return is_interrupted_or_pressed(state) ? TD_DOUBLE_TAP : TD_DOUBLE_HOLD;
//         case 3:
//             return is_interrupted_or_pressed(state) ? TD_TRIPLE_TAP : TD_TRIPLE_HOLD;
//         default:
//             return TD_UNKNOWN;
//     }
}



void triple_tap(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_MPLY);
            break;
        case 2:
            tap_code(KC_MNXT);
            break;
        case 3:
            tap_code(KC_MPRV);
            break;
        default:
            reset_tap_dance(state);
    }
}

static td_tap_t triple_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void triple_tap_hold_finished(qk_tap_dance_state_t  *state, void *user_data) {
     triple_tap_state.state = get_current_dance_code(state);
    switch (triple_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_MPLY); break;
        case TD_SINGLE_HOLD:
            set_oneshot_layer(_FN1,ONESHOT_START);
            // clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        // case TD_SINGLE_HOLD: register_code((uint8_t)KC_FN1); break;
        case TD_DOUBLE_TAP: register_code(KC_MNXT); break;
        case TD_TRIPLE_TAP: register_code(KC_MPRV); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break; //! change this X to something else
        default:
                    clear_oneshot_layer_state(ONESHOT_PRESSED);

         reset_tap_dance(state);
         break;
    }
}

void triple_tap_hold_reset(qk_tap_dance_state_t  *state, void *user_data) {
     triple_tap_state.state = get_current_dance_code(state);
    switch (triple_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_MPLY); break;
        // case TD_SINGLE_HOLD: unregister_code((uint8_t)KC_FN1); break;
        case TD_SINGLE_HOLD:
            // layer_off(_FN1);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_TAP: unregister_code(KC_MNXT); break;
        case TD_TRIPLE_TAP: unregister_code(KC_MPRV); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default:
                    clear_oneshot_layer_state(ONESHOT_PRESSED);

            reset_tap_dance(state);
            reset_oneshot_layer();
                layer_off(_FN1);

            break;
    }
             reset_oneshot_layer();
                layer_off(_FN1);
    triple_tap_state.state = TD_NONE;

}


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PLAY_NEXT] = ACTION_TAP_DANCE_FN(triple_tap),
    [TD_PLAY_NEXT_HOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_tap_hold_finished, triple_tap_hold_reset),
    // [TD_PLAY_NEXT_HOLD] = ACTION_TAP_DANCE_LAYER_MOVE(KC_MPLY,_FN1),
};

//! może na przytrzymaniu keya ustawiać flagę, i na puszczeniu go resetować? i wtedy jest tylko 1 piosenka przód tył
