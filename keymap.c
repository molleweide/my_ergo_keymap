#include QMK_KEYBOARD_H

#include <math.h>
#include "pointing_device.h"
#define PI 3.14159265

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  BASE_THUMB_L,
  BASE_THUMB_R,
  PDIR1,
  PDIR2,
  PDIR3,
  PDIR4,
  PDIR5,
  PDIR6,
  PDIR7,
  PDIR8,
  PDIR9,
  PDIR10,
  PDIR11,
  PDIR_LAST,
  PVEL1,
  PVEL2 = PVEL1 + 3,
  PVEL3 = PVEL2 + 6,
  PVEL_LAST = PVEL3 + 10,
};

enum layer_names {
  _BASE = 0,  // red
  _SYMB,      //    same, slightly changed just so that ri can percieve a change
  _MOVE,      // green
  _POINT,     // blue
  _FUN,       // turquoise
  _MIDI,      // purple
  _TEST,      // grey
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ergodox_pretty(//------|-----------------|---------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      TO(_TEST),        xxxxxxxx,         xxxxxxxx,         TO(_MIDI),     xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      KC_MINUS,         KC_Q,             LT(_SYMB,KC_W), KC_E,           KC_R,           KC_T,           KC__VOLUP,      /**/            KC_MS_WH_UP,    KC_Y,           KC_U,           KC_I,           LT(_SYMB,KC_O), KC_P,             KC_BSLASH,
      KC_ESC,   /***/   CTL_T(KC_A),      SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           CMD_T(KC_J),   ALT_T(KC_K),      SFT_T(KC_L),   CTL_T(KC_SCOLON),KC_UNDS,
      xxxxxxxx,         LT(_MOVE,KC_Z),   LT(_SYMB,KC_X), LT(_FUN,KC_C),  KC_V,           KC_B,           KC__VOLDOWN,    /**/            KC_MS_WH_DOWN,  KC_N,           KC_M,           LT(_FUN,KC_COMMA),LT(_SYMB,KC_DOT), KC_SLASH ,        KC_UNDS,
      xxxxxxxx,         CTL_T(KC_LEFT),   xxxxxxxx,       TO(_POINT),        KC_SPACE,      /*-------------*/              /**/            /*-------------*/                KC_ENTER,     TO(_POINT),        xxxxxxxx,         CTL_T(KC_RGHT),   xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*----------------------------------|----------------------------------------*/ KC__MUTE,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*----------------------------------|--------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,       /***************/
      /*----------------------------------|------------------------*/ KC_BSPACE,       BASE_THUMB_L,   xxxxxxxx,       /**/            xxxxxxxx,      BASE_THUMB_R,    KC_TAB),
  [_SYMB] = LAYOUT_ergodox_pretty(//------|--------|---------------X---------------|---------------$------------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          xxxxxxxx,       /**/            xxxxxxxx,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BASE),
      xxxxxxxx,       KC_EXLM,          KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        xxxxxxxx,       /**/            xxxxxxxx,       KC_QUOTE,       KC_7,           KC_8,           KC_9,           KC_EQUAL,       xxxxxxxx,
      xxxxxxxx,       KC_HASH,   KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/            /**/            KC_0,           KC_4,           KC_5,           KC_6,           KC_PLUS,   xxxxxxxx,
      KC_AMPR,        KC_PERC,          KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        xxxxxxxx,       /**/            xxxxxxxx,       KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       KC_LCTL,        /***************/               /**/            /***************/               KC_RCTL,        xxxxxxxx,       xxxxxxxx,         xxxxxxxx,        xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*----------------------------------|----------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,      xxxxxxxx,
      /*----------------------------------|--------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*----------------------------------|------------------------*/ KC_LCTL,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,      xxxxxxxx,        KC_RCTL),
  [_MOVE] = LAYOUT_ergodox_pretty(//------|--------|---------------X---------------|---------------$------------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       KC_MS_WH_DOWN,  KC_MS_WH_UP,    ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       /**/            /**/            /**/            KC_LEFT,        KC_DOWN,       KC_UP,       KC_RIGHT,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       /*-------------*/               /**/            /*-------------*/               ________,       ________,       ________,       ________,       ________,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,       ________,
      /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,       /***************/
      /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,       ________,         ________),
  [_POINT] = LAYOUT_ergodox_pretty(//-|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       PDIR9,          PDIR10,         PDIR11,         PDIR_LAST,      PDIR1,          xxxxxxxx,       /**/            xxxxxxxx,       KC_MS_BTN3,     KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN4,     KC_MS_BTN5,     xxxxxxxx,
      KC_ESC,         PDIR5,          PDIR6,          PDIR7,          PDIR8,          PDIR9,          /**/            /**/            /**/            xxxxxxxx,       PVEL1,          PVEL2,          PVEL3,          PVEL_LAST,      xxxxxxxx,
      xxxxxxxx,       PDIR1,          PDIR2,          PDIR3,          PDIR4,          PDIR5,          xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),      KC_MS_BTN1,                                     /**/                                            KC_MS_BTN2,     TO(_BASE),      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ TO(_BASE),      KC_MS_BTN3,     KC_MS_BTN4,     /**/            xxxxxxxx,       KC_MS_BTN5,     TO(_BASE)),
  [_FUN] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       KC_F9,          KC_F10,         KC_F11,         KC_F12,         xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F21,         KC_F22,         KC_F23,         KC_F24,         xxxxxxxx,
      xxxxxxxx,       KC_F5,          KC_F6,          KC_F7,          CMD_T(KC_F8),   xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       CMD_T(KC_F17),  KC_F18,         KC_F19,         KC_F20,         xxxxxxxx,
      xxxxxxxx,       CTL_T(KC_F1),   SFT_T(KC_F2),   KC_F3,          KC_F4,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F13,         KC_F14,         SFT_T(KC_F15),  CTL_T(KC_F16),  xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ KC_LALT,        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_RALT),
  [_MIDI] = LAYOUT_ergodox_pretty(//---|--------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,        xxxxxxxx,       xxxxxxxx,      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),      xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       MI_Gs_1,         MI_A_1,         MI_As_1,       MI_B_1,         MI_C_2,         xxxxxxxx,       /**/            xxxxxxxx,       MI_Cs_2,        MI_D_2,         MI_Ds_2,        MI_E_2,         MI_F_2,         xxxxxxxx,
      MI_TRNSD,       MI_As,           MI_B,           MI_C_1,        MI_Cs_1,        MI_D_1,         /*******/       /**/            /*******/       MI_Ds_1,        MI_E_1,         MI_F_1,         MI_Fs_1,        MI_G_1,         MI_TRNSU,
      xxxxxxxx,       MI_C,            MI_Cs,          MI_D,          MI_Ds,          MI_E,           xxxxxxxx,       /**/            xxxxxxxx,       MI_F,           MI_Fs,          MI_G,           MI_Gs,          MI_A,           xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,        xxxxxxxx,       MI_OCTD,       MI_C,           /*-------------*/               /**/            /*-------------*/               MI_C,           MI_OCTU,        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,       /***************/
      /*-----------------------------------------------------------*/ MI_TRNS_0,      BASE_THUMB_L,   xxxxxxxx,       /**/            xxxxxxxx,       BASE_THUMB_R,   MI_ALLOFF),
  [_TEST] = LAYOUT_ergodox_pretty(//------------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       RESET,          xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),
};

//    MI_VEL_1,
//    MI_CHU, MI_Cs,    MI_Ds,     MI_Fs,    MI_Gs,    MI_As,    XXXXXXX,  MI_Cs_1,  MI_Ds_1,   XXXXXXX,   XXXXXXX, XXXXXXX,
//    MI_MOD,  MI_C,     MI_D,     MI_E,      MI_F,     MI_G,     MI_A,     MI_B,     MI_C_1,   MI_D_1,   MI_E_1,    MI_F_1,             _______,
//    MI_SUS,            MI_OCTD,  MI_OCTU,   MI_MODSD, MI_MODSU, XXXXXXX,  XXXXXXX,  XXXXXXX,  MI_TRNSD, MI_TRNSU,  MI_TRNS_0,          MI_SUS,
//    MI_ALLOFF

// VARIABLES ----------------------------------------
rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

// TODO
//
//  rename the last keycode `P_DIR_LAST`

int POINTER_DIR_COUNT =  PDIR_LAST - PDIR1 + 1;
int POINTER_VEL_COUNT =  PVEL_LAST - PVEL1 + 1;

int last_pressed_dir_key = 0;
int last_pressed_vel_key = 0;

int POINTER_CURR_DIR = 0;
int POINTER_V = 0;
int POINTER_X = 0;
int POINTER_Y = 0;

float rad = PI / 180;
float CLOCK_SHIFT = - PI / 3; // 0 == 12 o'clock ?

int POINTER_UPDATE_INTERVAL = 15; // milliseconds
uint16_t TIMESTAMP_PREV_POINTER = 0; // change to regular int??????

bool THUMB_IS_DOWN = false;

// TODO
// how can I shift the valus so that U/D/L/R becomes as smooth as possible

void update_pointer_xy(int dummy){
  float direction_in_radians = POINTER_CURR_DIR * 360/POINTER_DIR_COUNT * rad; // replace 30 by 360/POINTER_DIR_COUNT
  POINTER_X = round(POINTER_V * cos(direction_in_radians + CLOCK_SHIFT));
  POINTER_Y = round(POINTER_V * sin(direction_in_radians + CLOCK_SHIFT));
}

// TODO
//   add and not = prev keycode!!!

void handle_pointer_keycodes(uint16_t keycode, keyrecord_t *record){
  int pk = keycode - PDIR1 + 1; // important !!!
  if ( 1 <= pk && pk <= POINTER_DIR_COUNT ) { // poin
    if (record->event.pressed) {
      POINTER_CURR_DIR = pk; last_pressed_dir_key = keycode;
      update_pointer_xy(1);
    } else {
      if (last_pressed_dir_key == keycode) {
        last_pressed_dir_key = 0;
      }
    }
  }
  if ( POINTER_DIR_COUNT < pk && pk <= POINTER_DIR_COUNT + POINTER_VEL_COUNT ) {
    if (record->event.pressed) {
      POINTER_V = pk - POINTER_DIR_COUNT; last_pressed_vel_key = keycode;
      update_pointer_xy(1);
    } else {
      if (last_pressed_vel_key == keycode) {
        last_pressed_vel_key = 0;
      }
    }
  }
}


//  todo
//
//    press            down true
//    release          down = false
//    press && down    change layer

void kc_down_at_same_time(uint16_t keycode, keyrecord_t *record/*, bool *is_down, send_layer*/) {
  if (record->event.pressed) {
    /* if (THUMB_IS_DOWN) { */
    /*   // move layer */
    /*   layer_move(_MIDI); */
    /* } else { */
    /*   THUMB_IS_DOWN = true; */
    /* } */

    if (IS_LAYER_ON(_BASE)) {
      layer_move(_MIDI);
      return;
    }
    if (IS_LAYER_ON(_MIDI)) {
      layer_move(_BASE);
      return;
    }
  } else {
    /* THUMB_IS_DOWN = false; */
    /* if (keycode == BASE_THUMB_L) { */
    /*   // emmit keycode left */
    /* } */
    /* if (keycode == BASE_THUMB_R) { */
    /*   // emmit keycode right */
    /* } */
  }




  /* if (*is_down) { */
  /*   // second press */
  /*   if (record->pressed) { */
  /*     // do stuff .... */
  /*     // */
  /*     // */
  /*     // */
  /*     // */
  /*     // */
  /*     // */
  /*   } else { */
  /*     *is_down = false; */
  /*   } */
  /* } else { */
  /*   // first press */
  /*   *is_down = true; // poinger */
  /* } */
}

void pointing_device_task(void) {
  report_mouse_t report = pointing_device_get_report();

  if (timer_elapsed(TIMESTAMP_PREV_POINTER) > POINTER_UPDATE_INTERVAL
      && last_pressed_dir_key > 0
      && last_pressed_vel_key > 0
     ) {
    TIMESTAMP_PREV_POINTER = timer_read();
    report.x = POINTER_X;
    report.y =  POINTER_Y;
  }
  pointing_device_set_report(report);
  pointing_device_send();
}

/*
 * todo
 *
 *  add case if mode = _base && both thumb keys held down at the same time.
 *  tmuxThumb_L, tmuxThumb_R
 *
 * case thumbs
 *
 */
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

    case BASE_THUMB_L ... BASE_THUMB_R:
      kc_down_at_same_time(keycode, record/*, THUMB_IS_DOWN, _POINT*/);

    case PDIR1 ... PVEL_LAST:
      // first P direction ... last p velocity
      handle_pointer_keycodes(keycode, record);
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
      // red
      case _BASE:
        rgblight_sethsv_noeeprom(0,252,255);
        break;
      case _SYMB:
        rgblight_sethsv_noeeprom(10,90,40);


        // green
      case _MOVE:
        rgblight_sethsv_noeeprom(100,30,40);
        break;

        // blue
      case _POINT:
        rgblight_sethsv_noeeprom(10,90,40);
        break;

        // turquoise
      case _FUN:
        rgblight_sethsv_noeeprom(70,0,50);
        break;

        // purple
      case _MIDI:
        rgblight_sethsv_noeeprom(56,0,150);
        break;

        // grey
      case _TEST:
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
}

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}
