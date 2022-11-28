RGB_MATRIX_EFFECT(home)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool home(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    rgb_matrix_set_color(8, 0x27, 0xc4, 0x6b);

    for (uint8_t i = 13; i < 17; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x27, 0xc4, 0x6b);
    }

    for (uint8_t i = 19; i < 22; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
         rgb_matrix_set_color(i, 0x27, 0xc4, 0x6b);
    }

    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS