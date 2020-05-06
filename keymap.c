#include QMK_KEYBOARD_H

#include "pointing_device.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

//////////////////////////////////////
// my custom keynames
////////////////////////////////////////

#define KC_SPC      KC_SPACE
#define KC_BSPC     KC_BSPACE
#define KC_ENT      KC_ENTER
#define KC_SLSH     KC_SLASH
#define KC_BSLSH    KC_BSLASH
#define KC_SCOL     KC_SCOLON

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

#define KC_MA0     KC_MS_ACCEL0
#define KC_MA1     KC_MS_ACCEL1
#define KC_MA2     KC_MS_ACCEL2

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

// tap dance functions rename
#define TD_LMV      ACTION_TAP_DANCE_LAYER_MOVE


enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MOVE_U,
  MOVE_D,
  MOVE_L,
  MOVE_R,
  MOVE_OFF,
  MGRID,
  PFREEZE,
  SET_MS_STATE,
};

enum layer_names {
    _BAS = 0,

    _LSY,
    _RNU,

    _LMS,
    _RMS,

    _LCO,
    _RCO,

    _RTE,
    _DVO, // rm?
    _COL,
    _WRK, // rm ?

    _MS_TEST, // this is where I do my mouse testing
}

enum tapdance_keycodes {
    TD_MMODE,       // switch mouse mode
    TD_ESC_LCMP,    // esc or move to L mouse complement
    TD_QUOTE_RCMP,  // esc or move to R mouse complement
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 00 | Base
    [_BAS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        TO(_RTE),       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB,         /**/            xxxxxxxx,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,        /**/            KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLSH,
        TD(TD_ESC_LCMP),CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           GUI_T(KC_J),    ALT_T(KC_K),    SFT_T(KC_L),    CTL_T(KC_SCOL), TD(TD_QUOTE_RCMP),
        KC_LSPO,        LT(_RMS,KC_Z),  LT(_RNU,KC_X),  KC_C,           KC_V,           KC_B,           KC_TRNS,        /**/            KC_TRNS,        KC_N,           KC_M,           KC_COMMA,       LT(_LSY,KC_DOT),LT(_LMS,KC_SLSH),KC_RSPC,
        KC_GRAVE,       CTL_T(KC_LEFT), KC_DOWN,        KC_UP,          KC_RGHT,        /*-------------*/               /**/            /*-------------*/               KC_LEFT,        KC_DOWN,        KC_UP,          CTL_T(KC_RGHT), xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        LSFT_T(KC_SPC), KC_BSPC,        KC_TRNS,        /**/            KC_TRNS,        KC_TAB,         RSFT_T(KC_ENT)),



    // 01 | L Symbols
    [_LSY] = LAYOUT_ergodox_pretty(//------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
        ________,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       TO(_BAS),
        ________,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/                            ________,       ________,       ________,       ________,       ________,       ________,
        KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       ________,       ________,       ________,       ________,                                       /**/                                            ________,       ________,       ________,       ________,       ________,
        /*--------------|***************|***************|***************|***************|---------------$-----------------------------------------------$---------------|***************|***************|***************|***************/
                                                                                        ________,       ________,                       ________,      ________,
                                                                                                        ________,                       ________,
                                                                        ________,       ________,       ________,                       ________,      ________,        ________),

    // 02 | R Numbers
    [_RNU] = LAYOUT_ergodox_pretty(//----------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /***********************/       KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BAS),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /***********************/       KC_TRNS,        KC_TRNS,        KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK, KC_F12,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,   /***********************/                                            KC_0,           KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_KP_SLASH,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  /***********************/             KC_TRNS,        KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
    // 03 | Mouse L
    [_LMS] = LAYOUT_ergodox_pretty(//----------|---------------|---------------X---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AU_M,  KC_TRNS,        /***********************/             KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
            KC_TRNS,        KC_MWHL,        KC_MWHD,        KC_MWHU,        KC_MWHR,        KC_TRNS,        KC_AU_U,/***********************/               KC_TRNS,        KC_RGUI,        KC_RALT,        KC_RSHIFT,      KC_RCTRL,       KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_ML,          KC_MD,          KC_MU,          KC_MR,          KC_TRNS,                 /***********************/                              KC_TRNS,        KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_TRNS,        KC_AU_D,      /***********************/         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,     KC_TRNS,        KC_MS_BTN2,     KC_MS_BTN1
    ),

    // 04 | Mouse R         |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [_RMS] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_AU_M,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_AU_U,        KC_MS_WH_UP,    KC_TRNS,        KC_MS_UP,       KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRNS,                                                                        KC_TRNS,        KC_ML,          KC_MD,          KC_MU,          KC_MR,          KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_AU_D,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_MS_BTN1,     KC_MS_BTN2,     KC_TRNS,        KC_MS_BTN5,     KC_MS_BTN4,     KC_MS_BTN3
    ),


    [_LCO] = LAYOUT_ergodox_pretty(//---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|-----------
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                            xxxxxxxx,       xxxxxxxx,   /**/            xxxxxxxx,       xxxxxxxx,
                                                                            /***************/               xxxxxxxx,   /**/            xxxxxxxx,       /***************/
                                                                            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,   /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),


    [_RCO] = LAYOUT_ergodox_pretty(//---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|-----------
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                            xxxxxxxx,       xxxxxxxx,   /**/            xxxxxxxx,       xxxxxxxx,
                                                                            /***************/               xxxxxxxx,   /**/            xxxxxxxx,       /***************/
                                                                            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,   /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),



    // Layouts              |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [_RTE] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_MS_TEST),   KC_TRNS,                                                                        KC_TRNS,        TO(_DVO),       TO(_COL),       TO(_WRK),       KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // dvorak               |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [_DVO] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
            KC_TRNS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRNS,                                        KC_TRNS,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TRNS,
            KC_TRNS,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_TRNS,
            KC_TRNS,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,           KC_TRNS,                                        KC_TRNS,        KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // colemakDH            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [_COL] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
            KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_TRNS,
            KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_K,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
            KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRNS,                                        KC_TRNS,        KC_M,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLSH,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // workman              |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [_WRK] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
            KC_TRNS,        KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_F,           KC_U,           KC_P,           KC_SLSH,       KC_TRNS,
            KC_TRNS,        KC_A,           KC_S,           KC_H,           KC_T,           KC_G,                                                                           KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           KC_TRNS,
            KC_TRNS,        KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,           KC_TRNS,                                        KC_TRNS,        KC_K,           KC_L,           KC_COMMA,       KC_DOT,         KC_SLSH,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // Mouse testing
    [_MS_TEST] = LAYOUT_ergodox_pretty(//---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        TD(TD_MMODE),   MGRID,          MGRID,          MGRID,          MGRID,          MGRID,          /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                            xxxxxxxx,       xxxxxxxx,   /**/            xxxxxxxx,       xxxxxxxx,
                                                                            /***************/               xxxxxxxx,   /**/            xxxxxxxx,       /***************/
                                                                            MOVE_OFF,       xxxxxxxx,       xxxxxxxx,   /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),
};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;
bool moveToggle = false;
bool moveState = false;
uint8_t moveDirection = 0;
uint8_t cursorTimeout = 10;
uint16_t lastCursor = 0;
uint8_t stateMove = 0;
uint8_t mouseMode = 1;

uint8_t seqStep = 0;
uint8_t contMagnitude = 10;
uint8_t discMagnitude = 10;

void reset_pointer(void) {
#ifdef CONSOLE_ENABLE
    uprintf("reset pointer\n");
#endif
}

void dance_mousemode_finished (qk_tap_dance_state_t *state, void *user_data) {
    mouseMode = state->count;
    reset_pointer();
}

void dance_esc_lcmp (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_ESC);
    } else {
        // set layer left compl
        layer_move(_L_MCOMP)
    }
}
void dance_quote_rcmp (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_QUOTE);
    } else {
        // set layer right comp
        layer_move(_R_MCOMP)
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MMODE] = ACTION_TAP_DANCE_FN (dance_mousemode_finished),
    [TD_ESC_LCMP]   = ACTION_TAP_DANCE_FN (dance_esc_lcmp),
    [TD_QUOTE_RCMP] = ACTION_TAP_DANCE_FN (dance_quote_rcmp),
};

void mouse_mode_basic(keyrecord_t *record) {
    // change speed by altering the report OR the cursorTimeout.
    moveToggle = true;
    // note that the rows and cols are inverted for some reason?!
    if (record->event.key.col == 2 && record->event.pressed) {
        if (record->event.key.row == 1){
                //seqStep == 0 ?  moveDirection = 0 : contMagnitude = 10;
        }
        if (record->event.key.row == 2){
                //seqStep == 0 ?  moveDirection = 1 : contMagnitude = 20;
        }
        if (record->event.key.row == 3){
                //seqStep == 0 ?  moveDirection = 2 : contMagnitude = 30;
        }
        if (record->event.key.row == 4){
                //seqStep == 0 ?  moveDirection = 3 : contMagnitude = 40;
        }
    }
}

void mouse_mode_basic_discrete(keyrecord_t *record) {
    // change magnitude by changing report below
    report_mouse_t report = pointing_device_get_report();

// ifdef CONSOLE_ENABLE
//    uprintf("x: %u, y: %u\n", report.x, report.y);
// endif
    if (record->event.key.col == 2 && record->event.pressed) {
        if (record->event.key.row == 1){
                report.x = -5;
        }
        if (record->event.key.row == 2){
                report.y = 5;
        }
        if (record->event.key.row == 3){
                report.y = -5;
        }
        if (record->event.key.row == 4){
                report.x = 5;
        }
    }
    pointing_device_set_report(report);
    pointing_device_send();
}


void handle_mvim_grid_event(keyrecord_t *record) {
    switch (mouseMode) {
        case 1:
            mouse_mode_basic(record);
            // set continuous mode
            break;
        case 2:
            mouse_mode_basic_discrete(record);
            // set discrete mode
            break;
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
        case MOVE_OFF:
            if (record->event.pressed) {
                moveToggle = false;
            }
            break;
        case MOVE_U:
            if(record->event.pressed) {
                moveDirection = 0;
                moveToggle = true;
            }
            break;
        case MOVE_D:
            if(record->event.pressed) {
                moveDirection = 2;
                moveToggle = true;
            }
            break;
        case MOVE_L:
            if(record->event.pressed) {
                moveDirection = 3;
                moveToggle = true;
            }
            break;
        case MOVE_R:
            if(record->event.pressed) {
                moveDirection = 1;
                moveToggle = true;
            }
            break;
        case MGRID:
            handle_mvim_grid_event(record);
            break;
    }
    return true;
}

void pointing_device_task(void) {
    report_mouse_t report = pointing_device_get_report();
    if (timer_elapsed(lastCursor) > cursorTimeout && moveToggle) {
        lastCursor = timer_read();
        switch (moveDirection) {
            case 0:
                report.x = -contMagnitude; // replace the integer with contMagnitude
                break;
            case 1:
                report.y = contMagnitude;
                break;
            case 2:
                report.y = -contMagnitude;
                break;
            case 3:
                report.x = contMagnitude;
                break;
        }
    }
    pointing_device_set_report(report);
    pointing_device_send();
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    switch (layer) {
        case 0:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(0,252,255);
            }
            break;
        case 1:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(7,255,147);
            }
            break;
        case 2:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(7,255,147);
            }
            break;
        case 3:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(92,179,121);
            }
            break;
        case 4:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(92,179,121);
            }
            break;
        case 5:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(45,255,255);
            }
            break;
        case 6:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(142,255,143);
            }
            break;
        case 7:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(217,255,133);
            }
            break;
        case 8:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(255,255,201);
            }
            break;
        case 9:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(210,255,255);
            }
            break;
        case 10:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(1,0,114);
            }
            break;
        case 11:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(43,255,154);
            }
            break;
        default:
            if(!disable_layer_color) {
                rgblight_config.raw = eeconfig_read_rgblight();
                if(rgblight_config.enable == true) {
                    rgblight_enable();
                    rgblight_mode(rgblight_config.mode);
                    rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
                }
                else {
                    rgblight_disable();
                }
            }
            break;
    }
    return state;

};

//  find what it is that is not working; console true/ debug enable/ or matrix=true?
void keyboard_post_init_user(void) {
    // Customise these values to desired behave
    // debug_enable=true; // keyboard becomes very slow when using this or next setting; why??
    // debug_matrix=true; // this makes keyb very slow!!!
    // debug_keyboard=true;
    // debug_mouse=true;

    layer_state_set_user(layer_state);
}















