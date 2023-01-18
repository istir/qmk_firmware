typedef struct {
    bool caps_lock;
    bool fn1;
    bool fn2;
    bool knob;
} custom_pressed_t;

custom_pressed_t custom_pressed_keys = {false, false, false, false};

/* -------------------------------- caps lock ------------------------------- */
void set_capslock_pressed_state(bool pressed) {
#ifdef CAPS_WORD_ENABLE
    custom_pressed_keys.caps_lock is_caps_word_on();
#else
    custom_pressed_keys.caps_lock = pressed;
    switch_to_preset(CAPS_LOCK_PRESET);
#endif
}
bool get_capslock_pressed_state(void) {
    return custom_pressed_keys.caps_lock;
}

/* ----------------------------------- fn1 ---------------------------------- */
void set_fn1_pressed_state(bool pressed) {
    custom_pressed_keys.fn1 = pressed;
}
bool get_fn1_pressed_state(void) {
    return custom_pressed_keys.fn1;
}

/* ----------------------------------- fn2 ---------------------------------- */
void set_fn2_pressed_state(bool pressed) {
    custom_pressed_keys.fn2 = pressed;
}
bool get_fn2_pressed_state(void) {
    return custom_pressed_keys.fn2;
}

/* ---------------------------------- knob ---------------------------------- */
void set_knob_pressed_state(bool pressed) {
    custom_pressed_keys.knob = pressed;
}
bool get_knob_pressed_state(void) {
    return custom_pressed_keys.knob;
}