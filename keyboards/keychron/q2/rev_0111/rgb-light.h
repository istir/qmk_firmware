/* istir - 12.11.2022 - 26.11.2022
 * This file handles rgb switching.
 * It also handles correctly setting brightness 
 */

const int DEFAULT_PRESET_BRIGHTNESS   = 130;
const int CAPS_LOCK_PRESET_BRIGHTNESS = 255;

enum presets { DEFAULT_PRESET, CAPS_LOCK_PRESET, NUMBER_OF_PRESETS };

int previous_preset;
int current_preset = DEFAULT_PRESET;

int preset_brightnesses[NUMBER_OF_PRESETS];

void set_brightness(int value);
void switch_to_default_preset(void);
void switch_to_caps_lock_preset(bool active);
void switch_to_previous_preset(void);
void switch_to_preset(int preset);

void set_brightness(int value) {
    int brightness = value;
    if (value > 255) brightness = 255;
    if (value < 0) brightness = 0;
    rgb_matrix_config.hsv.v = brightness;
}

void caps_word_set_user(bool active) {
    switch_to_preset(CAPS_LOCK_PRESET);
}

void switch_to_default_preset() {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_DEFAULT);
}

void switch_to_caps_lock_preset(bool active) {
    if (active) {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_CAPSLOCK);
    } else {
        switch_to_preset(DEFAULT_PRESET);
    }
}

void switch_to_previous_preset(void) {
    int temp_brightness = preset_brightnesses[previous_preset];
    switch_to_preset(previous_preset);
    set_brightness(temp_brightness);
}

void switch_to_preset(int preset) {
    switch (preset) {
        case DEFAULT_PRESET:
            set_brightness(DEFAULT_PRESET_BRIGHTNESS);
            switch_to_default_preset();
            break;
        case CAPS_LOCK_PRESET:
            set_brightness(CAPS_LOCK_PRESET_BRIGHTNESS);
            switch_to_caps_lock_preset(is_caps_word_on());
            break;
        default:
            break;
    }
}