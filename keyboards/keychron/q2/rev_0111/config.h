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

#pragma once

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 34
#define DRIVER_2_LED_TOTAL 33
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

/* Encoder used pins */
#define ENCODERS_PAD_A { A10 }
#define ENCODERS_PAD_B { B5 }

/* Specifies the number of pulses the encoder registers between each detent */
#define ENCODER_RESOLUTION 4

// rotary-encoder.h
#define USE_MANUAL_KNOB_CONTROL

//rgb-light.h
#define USE_CUSTOM_RGB_PRESETS
#define RGB_MATRIX_KEYPRESSES 

//caps word
#define CAPS_WORD_IDLE_TIMEOUT 0 //disable timeout
#define CAPS_WORD_NO_AUTO_DEACTIVATION //disable automatic deactivation on some keys 

// caps as ctrl
#define SWAP_CAPS_TO_CTRL