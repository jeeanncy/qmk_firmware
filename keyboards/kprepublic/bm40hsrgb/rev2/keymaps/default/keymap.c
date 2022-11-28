#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _HOME 4
#define _FN 5

enum my_keycodes { RMT = SAFE_RANGE, RMS, RMIH, RMDH, RMIS, RMDS, RMIV, RMDV };

uint8_t rgbmode;
static void setGameRGB(int);
bool rgbStatus = true;

void matrix_scan_user(void) {
    if(rgb_matrix_config.mode != RGB_MATRIX_CUSTOM_home){
        rgbmode = rgb_matrix_config.mode;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RMT:
            if (record->event.pressed) {
                rgb_matrix_toggle();
            }
            return false;
        case RMS:
            if (record->event.pressed) {
                rgb_matrix_step();
            }
            return false;
        case RMIH:
            if (record->event.pressed) {
                rgb_matrix_increase_hue();
            }
            return false;
        case RMDH:
            if (record->event.pressed) {
                rgb_matrix_decrease_hue();
            }
            return false;
        case RMIS:
            if (record->event.pressed) {
                rgb_matrix_increase_sat();
            }
            return false;
        case RMDS:
            if (record->event.pressed) {
                rgb_matrix_decrease_sat();
            }
            return false;
        case RMIV:
            if (record->event.pressed) {
                rgb_matrix_increase_val();
            }
            return false;
        case RMDV:
            if (record->event.pressed) {
                rgb_matrix_decrease_val();
            }
            return true;
        default:
            return true;
    }
}

void setGameRGB(int layer) {
    if(!rgbmode) rgbmode = rgb_matrix_config.mode;
    switch (layer) {
        case 1:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_home);
        break;
      }
};

#define CAPSFN LT(_FN, KC_CAPS)
#define LOWER LT(_LOWER, KC_ENT)
#define SPCHOM LT(_HOME, KC_SPC)
#define RAISE LT(_RAISE, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_mit(
        /*  ,----------------------------------------------------------------------------------------------------------------.*/
               KC_TAB  ,   KC_Q  ,   KC_W  ,  KC_E   , KC_R  ,  KC_T  , KC_Y , KC_U  ,   KC_I  ,  KC_O   ,  KC_P   , KC_ESC  ,
        /*  |----------+---------+---------+---------+-------+--------+------+-------+---------+---------+---------+---------| */
               KC_LCTL ,   KC_A  ,   KC_S  ,  KC_D   , KC_F  ,  KC_G  , KC_H , KC_J  ,   KC_K  ,  KC_L   , KC_SCLN , KC_QUOT ,
        /*  |----------+---------+---------+--- -----+-------+--------+------+-------+---------+---------+---------+---------| */
               KC_LSFT ,   KC_Z  ,   KC_X  ,   KC_C  , KC_V  ,  KC_B  , KC_N , KC_M  , KC_COMM ,  KC_DOT , KC_SLSH , KC_RSFT ,
        /*  |----------+---------+---------+---------+-------+--------+------+-------+---------+---------+---------+---------| */
               CAPSFN  , KC_LCTL , KC_LGUI , KC_LALT , LOWER ,     SPCHOM    , RAISE , KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT ),
        /* `-----------------------------------------------------------------------------------------------------------------' */

    [1] = LAYOUT_planck_mit(
        /*  ,------------------------------------------------------------------------------------------------------------------------.*/
               KC_GRV ,  KC_1   ,   KC_2  ,   KC_3  ,   KC_4  ,   KC_5  ,   KC_6  ,   KC_7  ,   KC_8  ,   KC_9  ,   KC_0  , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MINS ,  KC_EQL , KC_LBRC , KC_RBRC , KC_BSLS ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , LOWER   ,      XXXXXXX      ,  RAISE  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ),
        /* `-------------------------------------------------------------------------------------------------------------------------' */

    [2] = LAYOUT_planck_mit(
        /*  ,------------------------------------------------------------------------------------------------------------------------.*/
               KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , LOWER   ,      XXXXXXX      ,  RAISE  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ),
        /* `-------------------------------------------------------------------------------------------------------------------------' */

    [3] = LAYOUT_planck_mit(
        /*  ,------------------------------------------------------------------------------------------------------------------------.*/
               XXXXXXX ,   RMT   ,   RMS   ,   RMIH  ,  RMDH   ,   RMIS  ,   RMDS  ,   RMIV  ,   RMDV  , XXXXXXX , XXXXXXX ,  RESET  ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , RGB_TOG , RGB_MOD , RGB_HUI , RGB_HUD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD , XXXXXXX , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX       , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ),
        /* `-------------------------------------------------------------------------------------------------------------------------' */

    [4] = LAYOUT_planck_mit(
        /*  ,-------------------------------------------------------------------------------------------------------------------------.*/
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_HOME ,  KC_UP  ,  KC_END  , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+----------+---------+---------| */
               XXXXXXX , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_RIGHT , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+----------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+----------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_ENT  ,      XXXXXXX      , KC_BSPC , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ),
        /* `--------------------------------------------------------------------------------------------------------------------------' */

    [5] = LAYOUT_planck_mit(
        /*  ,------------------------------------------------------------------------------------------------------------------------.*/
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 , XXXXXXX ,
        /*  |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------| */
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX       , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ),
        /* `-------------------------------------------------------------------------------------------------------------------------' */

};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _HOME:
            setGameRGB(1);
            break;

        default:
            rgbStatus = rgb_matrix_is_enabled();
            if(rgbStatus == true){
                rgb_matrix_mode_noeeprom(rgbmode);
            }
            break;
  }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
