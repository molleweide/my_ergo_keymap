#include QMK_KEYBOARD_H

//#ifdef CONSOLE_ENABLE
//  uprintf("xxx: %u, yyy: %u\n\n", xxx, yyy);
//#endif

#include <math.h>
#include "pointing_device.h"

#define PI 3.14159265
//#define KC_MAC_UNDO LGUI(KC_Z)
//#define KC_MAC_CUT LGUI(KC_X)
//#define KC_MAC_COPY LGUI(KC_C)
//#define KC_MAC_PASTE LGUI(KC_V)
//#define KC_PC_UNDO LCTL(KC_Z)
//#define KC_PC_CUT LCTL(KC_X)
//#define KC_PC_COPY LCTL(KC_C)
//#define KC_PC_PASTE LCTL(KC_V)
//#define ES_LESS_MAC KC_GRAVE
//#define ES_GRTR_MAC LSFT(KC_GRAVE)
//#define ES_BSLS_MAC ALGR(KC_6)
//#define NO_PIPE_ALT KC_GRAVE
//#define NO_BSLS_ALT KC_EQUAL

//////////////////////////////////////
// my custom keynames
////////////////////////////////////////

#define KC_SPC      KC_SPACE
#define KC_BSPC     KC_BSPACE
#define KC_ENT      KC_ENTER
#define KC_SLSH     KC_SLASH
#define KC_BSLSH    KC_BSLASH
#define KC_SCOL     KC_SCOLON
#define KC_COM      KC_COMMA

#define WEBUSB      WEBUSB_PAIR

// audio
#define KC_AU_M     KC_AUDIO_MUTE
#define KC_AU_U     KC_AUDIO_VOL_UP
#define KC_AU_D     KC_AUDIO_VOL_DOWN

// mouse keys
#define KC_MU      KC_MS_UP
#define KC_MD      KC_MS_DOWN
#define KC_ML      KC_MS_LEFT
#define KC_MR      KC_MS_RIGHT

#define KC_MWHU    KC_MS_WH_UP
#define KC_MWHD    KC_MS_WH_DOWN
#define KC_MWHL    KC_MS_WH_LEFT
#define KC_MWHR    KC_MS_WH_RIGHT

#define KC_MACC0    KC_MS_ACCEL0
#define KC_MACC1    KC_MS_ACCEL1
#define KC_MACC2    KC_MS_ACCEL2

#define KC_MB1     KC_MS_BTN1
#define KC_MB2     KC_MS_BTN2
#define KC_MB3     KC_MS_BTN3
#define KC_MB4     KC_MS_BTN4
#define KC_MB5     KC_MS_BTN5

// media keys
#define KC_YPP      KC_MEDIA_PLAY_PAUSE
#define KC_YST      KC_MEDIA_STOP
#define KC_YNT      KC_MEDIA_NEXT_TRACK
#define KC_YPT      KC_MEDIA_PREV_TRACK
#define KC_YFF      KC_MEDIA_FAST_FORWARD
#define KC_YRW      KC_MEDIA_REWIND
#define KC_YEJ      KC_MEDIA_EJECT
#define KC_YSE      KC_MEDIA_SELECT

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MGRID,
};

enum layer_names {
    _BAS = 0,

    _SYM,
    _NUM,

    _LMS,
    _RMS,

    _FUN,

    _TEST, // this is where I do my mouse testing
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /**
     * BASE ----------------------------------------
     */

    [_BAS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        TO(_TEST),      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB,         /**/            xxxxxxxx,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_AU_U,        /**/            KC_MS_WH_UP,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLSH,
        KC_ESC,         CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           CMD_T(KC_J),    ALT_T(KC_K),    SFT_T(KC_L),    CTL_T(KC_SCOL), KC_QUOTE,
        TO(_LMS),       LT(_RMS,KC_Z),  LT(_NUM,KC_X),  LT(_FUN,KC_C),  KC_V,           KC_B,           KC_AU_D,        /**/            KC_MS_WH_DOWN,  KC_N,           KC_M,           LT(_FUN,KC_COM),LT(_SYM,KC_DOT),LT(_LMS,KC_SLSH),TO(_RMS),
        KC_GRAVE,       CTL_T(KC_LEFT), KC_DOWN,        KC_UP,          KC_RGHT,        /*-------------*/               /**/            /*-------------*/               KC_LEFT,        KC_DOWN,        KC_UP,          CTL_T(KC_RGHT), xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        LSFT_T(KC_SPC), KC_BSPC,        KC_TRNS,        /**/            KC_TRNS,        KC_TAB,         RSFT_T(KC_ENT)),

    /**
     * SYMBOLS / NUMBERS ---------------------------
     */

    [_SYM] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        ________,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       TO(_BAS),
        ________,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/                            ________,       ________,       ________,       ________,       ________,       ________,
        KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       ________,       ________,       ________,       ________,       /***************/               /**/            /***************/               ________,       ________,       ________,       ________,       ________,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        ________,       ________,       /**/            ________,      ________,
                                                                                                        ________,       /**/            ________,
                                                                        ________,       ________,       ________,       /**/            ________,      ________,        ________),

    [_NUM] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            xxxxxxxx,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BAS),
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            xxxxxxxx,       xxxxxxxx,       KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_F12,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            /**/            /**/            KC_0,           KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_KP_SLASH,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            xxxxxxxx,       KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_UNDS,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,                                       /**/                                            KC_LPRN,        KC_COM,         KC_DOT,       KC_RPRN,        oooooooo,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        oooooooo,       oooooooo,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                                                        oooooooo,       /**/            xxxxxxxx,
                                                                        oooooooo,       oooooooo,       oooooooo,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),

    /**
     * MOUSE_LEFT_AND_RIGHT ------------------------------------------- MOUSE_LEFT_AND_RIGHT ------------------------------------------ MOUSE_LEFT_AND_RIGHT ---------------------------------------------------------- MOUSE_LEFT_AND_RIGHT -----------
     */

    [_LMS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       KC_RGUI,        KC_RALT,        KC_RSHIFT,      KC_RCTRL,       xxxxxxxx,       oooooooo,
        KC_ESC,         MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       /**/            /**/            /**/            KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,       xxxxxxxx,       oooooooo,
        TO(_BAS),       MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       KC_ML,          KC_MD,          KC_MU,          KC_MR,                                          /**/                                            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       oooooooo,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        oooooooo,       oooooooo,       /**/            oooooooo,       oooooooo,
                                                                                                        oooooooo,       /**/            oooooooo,
                                                                        KC_MS_BTN1,     KC_MS_BTN2,     xxxxxxxx,       /**/            KC_MS_BTN5,     KC_MS_BTN4,     KC_MS_BTN3),

    [_RMS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            KC_AU_M,        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       xxxxxxxx,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_AU_U,        KC_MS_WH_UP,    KC_TRNS,        KC_MS_UP,       KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_MACC0,       KC_MACC1,       KC_MACC2,       KC_TRNS,                        /**/                            KC_TRNS,        KC_ML,          KC_MD,          KC_MU,          KC_MR,          KC_ESC,
        TO(_BAS),       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_AU_D,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        /**/                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,        /**/            KC_TRNS,
                                                                        KC_MS_BTN1,     KC_MS_BTN2,     KC_TRNS,        /**/            KC_MS_BTN5,     KC_MS_BTN4,     KC_MS_BTN3),


    /**
     * FUNCTION_LAYER ------------------------------------------------ FUNCTION_LAYER ----------------------------------------------- FUCNTION_LAYER --------------------------------------------------------------- FUNCTION_LAYER ----------------
     */

    [_FUN] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(0),
        xxxxxxxx,       KC_F9,          KC_F10,         KC_F11,         KC_F12,         xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F21,         KC_F22,         KC_F23,         KC_F24,         xxxxxxxx,
        xxxxxxxx,       KC_F5,          KC_F6,          KC_F7,          CMD_T(KC_F8),   xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       CMD_T(KC_F17),  KC_F18,         KC_F19,         KC_F20,         xxxxxxxx,
        xxxxxxxx,       CTL_T(KC_F1),   SFT_T(KC_F2),   KC_F3,          KC_F4,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F13,         KC_F14,         SFT_T(KC_F15),  CTL_T(KC_F16),  xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(0),
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        KC_LALT,        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_RALT),


    /**
     * MOUSE TESTING
     */

    [_TEST] = LAYOUT_ergodox_pretty(//------------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        KC_ESC,         MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        KC_MS_BTN1,     KC_MS_BTN2,     xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),
};

// VARIABLES ----------------------------------------
rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

uint8_t stateMouseSequence = 0; // 0 = set magnitude; 1 = set direction; 2 = enter layer
int mag = 0;
double rad = PI / 180;

void setp(int m, double d){
  if (stateMouseSequence == 0 || stateMouseSequence == 2) {
    mag = m; stateMouseSequence = 1;
  } else {
    report_mouse_t report = pointing_device_get_report();
    report.x = round(mag * cos(d * rad));
    report.y = round(mag * sin(d * rad));
    pointing_device_set_report(report);
    pointing_device_send();
    stateMouseSequence = 0;
  }
}

void custom_pointer(keyrecord_t *record) { /////////////////////////////////////////////////
  if (record->event.pressed) { // key pressed
    if (record->event.key.col == 0) {
      switch (record->event.key.row) {
        case 1: setp(70, 202.5); break;    case 2: setp(100, 112.5); break;    case 3: setp(112, 292.5); break;    case 4:setp(125,22.5);break;
      }
    }
    if (record->event.key.col == 1) {
      switch (record->event.key.row) {
        case 1: setp(45, 247.5); break;    case 2: setp(50, 157.5); break;    case 3: setp(55, 337.5); break;    case 4:setp(60, 67.5);break;
      }
    }
    if (record->event.key.col == 2) {
      switch (record->event.key.row) {
        case 1: setp(25, 180); break;     case 2: setp(30, 90); break;    case 3: setp(35, 270); break;      case 4:setp(40, 0);break;
      }
    }
    if (record->event.key.col == 3) {
      switch (record->event.key.row) {
        case 1: setp(3,  225); break;      case 2: setp(6, 135); break;     case 3: setp(10, 315); break;   case 4:setp(20, 45);break;
      }
    }

  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case MGRID:
      custom_pointer(record);
      break;
    case KC_ESC:
      stateMouseSequence = 0; // reset mouse pointer
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    if(!disable_layer_color) {
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(1);
      switch (layer) {
        case _BAS:
          rgblight_sethsv_noeeprom(0,252,255);
          break;
        case _SYM:
        case _NUM:
          ergodox_right_led_1_on(); // top
          rgblight_sethsv_noeeprom(7,255,147);
          break;
        case _LMS:
        case _RMS:
          stateMouseSequence = 2;
          rgblight_sethsv_noeeprom(10,90,40);
          break;
        case _FUN:
          rgblight_sethsv_noeeprom(70,0,50);
          break;
        case _TEST:
          stateMouseSequence = 2;
          rgblight_sethsv_noeeprom(100,150,100);
          break;
        default:
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
          break;
      }
    }
    return state;
};
