RGB_MATRIX_EFFECT(CAPSLOCK)
RGB_MATRIX_EFFECT(DEFAULT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

int get_correct_brightness_value(int base_value) {
    int current_brightness = rgb_matrix_config.hsv.v;
    int percentage         = (100 * current_brightness / 255);
    int correct_brightness = (base_value * percentage) / 100;
    return correct_brightness;
}

static bool CAPSLOCK(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // rgb_matrix_config.hsv.v = 255;
    // HSV hsv = (HSV){0, 200, get_correct_brightness_value(255)};
    HSV      hsv  = (HSV){0, 200, rgb_matrix_config.hsv.v};
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

static bool DEFAULT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // rgb_matrix_config.hsv.v = 130;
    // HSV hsv = (HSV){0, 72, get_correct_brightness_value(130)};
    HSV hsv = (HSV){0, 72, rgb_matrix_config.hsv.v};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif
