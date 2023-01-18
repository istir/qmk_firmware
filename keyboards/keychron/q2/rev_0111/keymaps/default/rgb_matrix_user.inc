RGB_MATRIX_EFFECT(CAPSLOCK)
RGB_MATRIX_EFFECT(DEFAULT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

int get_correct_brightness_value(int base_value) {
    int current_brightness = rgb_matrix_config.hsv.v;
    int percentage         = (100 * current_brightness / 255);
    int correct_brightness = (base_value * percentage) / 100;
    return correct_brightness;
}

/*
 * ,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.,--------.
 * |   Esc  ||   1 !  ||   2 @  ||   3 #  ||   4 $  ||   5 %  ||   6 ^  ||   7 &  ||   8 *  ||   9 (  ||   0 )  ||   - _  ||   = +  ||BKspace || Knob   |
 * |    0   ||    1   ||    2   ||    3   ||    4   ||    5   ||    6   ||    7   ||    8   ||    9   ||   10   ||   11   ||   12   ||   13   ||  14    |
 * '--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------'
 * |   Tab  ||   Q    ||   W    ||   E    ||   R    ||   T    ||   Y    ||   U    ||   I    ||   O    ||   P    ||  [     ||  ]     ||  \     ||  DEL   |
 * |   15   ||   16   ||   17   ||   18   ||   19   ||   20   ||   21   ||   22   ||   23   ||   24   ||   25   ||  26    ||  27    ||  28    ||  29    |
 * '--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------'
 * |  CAPS  ||   A    ||   S    ||   D    ||   F    ||   G    ||   H    ||   J    ||   K    ||   L    ||  ; :   ||   ' "  ||      ENTER       ||  HOME  |
 * |   30   ||   31   ||   32   ||   33   ||   34   ||   35   ||   36   ||   37   ||   38   ||   39   ||   40   ||   41   ||       42         ||  43    |
 * '--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''------------------''--------'
 * |      SHIFT       ||   Z    ||   X    ||   C    ||   V    ||   B    ||   N    ||   M    ||  , <   ||  . >   ||  / ?   ||   SHIFT  |  ,--------.
 * |        44        ||   45   ||   46   ||   47   ||   48   ||   49   ||   50   ||   51   ||   52   ||   53   ||   54   ||    55    |  |   UP   |
 * '------------------''--------''--------''--------''--------''--------''--------''--------''--------''--------''--------''----------'  |   56   |
 * |  CTRL  ||  WIN   ||  ALT   ||                                SPACEBAR                       ||  ALT  ||  FN1  ||  FN2  |  ,--------.'--------',--------.
 * |   57   ||  58    ||   59   ||                                  60                           ||  61   ||  62   ||  63   |  |  LEFT  ||  DOWN  ||  RIGHT |
 * '--------''--------''--------''---------------------------------------------------------------''-------''-------''-------'  |   64   ||   65   ||   66   |
 *                                                                                                                             '--------''--------''--------'
 */

static bool CAPSLOCK(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV hsv = (HSV){0, 200, rgb_matrix_config.hsv.v};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    //* Set modifiers to color
    int modifier_keycodes[] = {0, 15, 30, 44, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 55, 56, 42, 43, 28, 29, 13};

    for (uint8_t i = led_min; i < led_max; i++) {
        for (size_t j = 0; j < sizeof(modifier_keycodes) / sizeof(modifier_keycodes[0]); j++) {
            if (modifier_keycodes[j] == i) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }

    return led_max < DRIVER_LED_TOTAL;
}

static bool DEFAULT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = (HSV){0, 72, rgb_matrix_config.hsv.v};
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif
