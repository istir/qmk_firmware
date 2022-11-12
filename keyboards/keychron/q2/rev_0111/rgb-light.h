/* istir - 12.11.2022
 * This file handles rgb.
 * It's supposed to handle switching between presets later on
 */

uint8_t previous_preset = RGB_MATRIX_CUSTOM_DEFAULT; //* used for momentary switching, like with caps lock
uint8_t current_preset  = RGB_MATRIX_CUSTOM_DEFAULT;

void caps_word_set_user(bool active) {
    if (active) {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_CAPSLOCK);
    } else {
        rgb_matrix_mode(previous_preset);
    }
}
