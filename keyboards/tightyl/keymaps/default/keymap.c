// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
	_QWERTY,
	_GALFI,
	_GAME,
	_FUNC,
	_NUM,
	_STUFF
};

enum custom_keycodes {
	ENTER_GAMING = SAFE_RANGE,
	EXIT_GAMING
};

#define REP_SFT	LSFT_T(QK_REP)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case EXIT_GAMING:
			if (record->event.pressed) {
				combo_enable();
				layer_clear();
			} else {
			}
			break;
		case ENTER_GAMING:
			if (record->event.pressed) {
				combo_disable();
				layer_on(_GAME);
			} else {
			}
			break;
		case REP_SFT:
			if (record->tap.count) {
				process_repeat_key(QK_REP,record);
				return false;
			}
			return true;
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* qwerty
*
*,-----------------------------------------.  ,-----------------------------------------.
*| ESC  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |   /  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*| GUI  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   Ä  |   '  |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*|  F1  |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   -  |  F2  |
*`------+----------------------------------'  `----------------------------------+------'
*
*       ,----------------------------------.  ,----------------------------------.
*       | ctrl | alt  |CrlTab| Sft/@| _NUM |  | Enter| Space|BckAlt| ctrl |shift |
*       `----------------------------------'  `----------------------------------'
*/
[_QWERTY] = LAYOUT( \
KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                               KC_Y,	KC_U,	KC_I,	KC_O,   KC_P,   LSFT(KC_7),\
KC_LGUI,KC_A,   KC_S,	KC_D,	KC_F,	KC_G,                                               KC_H,	KC_J,	KC_K,	KC_L,   KC_QUOT,KC_NUHS,\
KC_F1,  KC_Z,   KC_X,	KC_C,	KC_V,	KC_B,                                               KC_N,	KC_M,	KC_COMM,KC_DOT, KC_SLSH,KC_F2,\
                KC_LCTL,KC_LALT,CTL_T(KC_TAB),REP_SFT,LT(_NUM,KC_SPC),LT(_STUFF,KC_ENT),LT(_FUNC,ALT_T(KC_SPC),KC_LCTL,KC_LFST\
),
/* slightly modified gallium
*
*,-----------------------------------------.  ,-----------------------------------------.
*| ESC  |   B  |   L  |   D  |   C  |   V  |  |   Z  |   Y  |   O  |   U  |   ,  |   /  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*| GUI  |   N  |   R  |   T  |   S  |   G  |  |   P  |   H  |   A  |   E  |   I  |   -  |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*|  F1  |   Q  |   X  |   M  |   W  |   J  |  |   F  |   K  |   Ä  |   '  |   .  |  F2  |
*`------+----------------------------------'  `----------------------------------+------'
*
*       ,----------------------------------.  ,----------------------------------.
*       | ctrl | alt  |CrlTab| Sft/@| _NUM |  | Enter| Space|BckAlt| ctrl |shift |
*       `----------------------------------'  `----------------------------------'
*/
[_GALFI] = LAYOUT( \
KC_ESC, KC_B,   KC_L,   KC_D,   KC_C,   KC_V,                                               KC_Z,	KC_Y,	KC_O,	KC_U,   KC_COMM,LSFT(KC_7),\
KC_LGUI,KC_N,   KC_R,	KC_T,	KC_S,	KC_G,                                               KC_P,	KC_H,	KC_A,	KC_E,   KC_I,   KC_SLSH,\
KC_F1,  KC_Q,   KC_X,	KC_M,	KC_W,	KC_J,                                               KC_F,	KC_K,	KC_QUOT,KC_NUHS,KC_DOT, KC_F2,\
                KC_LCTL,KC_LALT,CTL_T(KC_TAB),REP_SFT,LT(_NUM,KC_SPC),LT(_STUFF,KC_ENT),LT(_FUNC,ALT_T(KC_SPC),KC_LCTL,KC_LFST\
),
/* gaming
*
*,-----------------------------------------.  ,-----------------------------------------.
*|   1  |      |      |      |      |      |  |      |      |      |      |      |  F1  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*| ESC  |      |      |      |      |      |  |      |      |      |      |      |  F2  |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*|      |      |      |      |      |      |  |      |      |   -  |      |      |      |
*`------+----------------------------------'  `----------------------------------+------'
*
*       ,----------------------------------.  ,----------------------------------.
*       | ctrl | alt  |  tab | Shift|  alt |  | Enter| Space|BckSpc| ctrl |shift |
*       `----------------------------------'  `----------------------------------'
*/
[_GAME] = LAYOUT( \
KC_1,   _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,KC_F1,\
KC_ESC, _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,KC_F2,\
_______,_______,_______,_______,_______,_______,                _______,_______,KC_SLSH,_______,_______,_______,\
                _______,_______,KC_TAB, KC_LSFT,KC_LALT,_______,_______,LT(_NUM,KC_BSPC),_______,_______\
),
/* fkeys
*
*,-----------------------------------------.  ,-----------------------------------------.
*|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*| F19  | MUTE | VOLD | VOLU | PLAY |  F20 |  | LEFT | DOWN |  UP  | RIGHT|   Ö  |  DEL |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*|  F1  |  REW | PREV | NEXT | FAST |  F21 |  | F22  | BACK | FORW |  F23 |  INS |  F2  |
*`------+----------------------------------'  `----------------------------------+------'
*
*       ,----------------------------------.  ,----------------------------------.
*       | ctrl | alt  |CrlTab| Sft/@| _NUM |  | Enter| Space|BckAlt| ctrl |shift |
*       `----------------------------------'  `----------------------------------'
*/
[_FUNC] = LAYOUT( \
KC_F1,	KC_F2,  KC_F3,	KC_F4,	KC_F5,	KC_F6,                                      KC_F7,	KC_F8,	KC_F9,	KC_F10, KC_F11,	KC_F12,\
KC_F19,	KC_KB_MUTE,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,KC_MPLY,KC_F20,                KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,KC_SCLN,KC_DEL,\
_______,KC_MRWD,KC_MPRV,KC_MNXT,KC_MFFD,KC_F21,                                     KC_F22,	KC_WBAK,KC_WFWD,KC_F23, KC_INS,_______,\
                _______,_______,_______,_______,_______,_______,_______,_______,_______,_______\
),
/* numbers + stuff
*
*,-----------------------------------------.  ,-----------------------------------------.
*|   |  |   ^  |   {  |   [  |   (  | Home |  |  End |   )  |   ]  |   }  |   \  |   ?  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*|   ~  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   "  |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*|  F1  |   !  |   @  |   #  |   $  |   %  |  |   &  |   =  |   <  |   >  |   +  |  F2  |
*`------+----------------------------------'  `----------------------------------+------'
*
*       ,----------------------------------.  ,----------------------------------.
*       | ctrl | alt  |CrlTab| Sft/@| _NUM |  | Enter| Space|BckAlt| ctrl |shift |
*       `----------------------------------'  `----------------------------------'
*/
[_NUM] = LAYOUT( \
RALT(KC_NUBS),LSFT(KC_RBRC),RALT(KC_7),RALT(KC_8),LSFT(KC_8),KC_HOME,                    KC_END,	LSFT(KC_9),RALT(KC_9),RALT(KC_0),RALT(KC_MINS),LSFT(KC_MINS),\
RALT(KC_RBRC),KC_1,KC_2,KC_3,	KC_4,	KC_5,                                            KC_6,	KC_7,	KC_8,	KC_9,   KC_0,LSFT(KC_2),\
_______,LSFT(KC_1),LSFT(KC_3),RALT(KC_4),LSFT(KC_5),                                     LSFT(KC_6),LSFT(KC_0),KC_NUBS,LSFT(KC_NUBS),KC_MINS,_______,\
                _______,_______,_______,_______,_______,_______,_______,_______,_______,_______\
),
/* stuff
*
*,-----------------------------------------.  ,-----------------------------------------.
*|  `   |      |      |      |      |      |  |      |      |      |      |      |      |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*|      |      | PGDN | PTAB | GAME |GALFI |  |QWERTY| EXIT | NTAB | PGUP |   å  | PSCR |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*|  F1  |      |      |      |      |      |  |      |      |      |      |RESET |  F2  |
*`------+----------------------------------'  `----------------------------------+------'
*
*       ,----------------------------------.  ,----------------------------------.
*       | ctrl | alt  |CrlTab| Sft/@| _NUM |  | Enter| Space|BckAlt| ctrl |shift |
*       `----------------------------------'  `----------------------------------'
*/
[_STUFF] = LAYOUT( \
LSFT(KC_EQL),_______,_______,_______,_______,_______,                               _______,_______,_______,_______,_______,_______,\
_______,_______,KC_PGDN,LCTL(LSFT(KC_TAB)),ENTER_GAMING,PDF(_GALFI),                DF(_QWERTY),EXIT_GAMING,LCTL(KC_TAB),KC_PGUP,KC_LEFT_BRACKET,KC_PSCR,\
_______,_______,_______,_______,_______,_______,                                    _______,_______,_______,_______,QK_BOOT,_______,\
                _______,_______,_______,_______,_______,_______,_______,_______,_______,_______\
),
};
enum combo_events {
	FJ_ESC, // qwerty
	SH_ESC // gallium fi
};

const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM sh_combo[] = {KC_S, KC_H, COMBO_END};

combo_t key_combos[] = {
	[FJ_ESC] = COMBO(fj_combo, KC_ESC),
	[SH_ESC] = COMBO(sh_combo, KC_ESC)
};

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
	switch (keycode) {
		case KC_A ... KC_Z:
			if ((*remembered_mods & ~MOD_MASK_SHIFT)== 0) {
				*remembered_mods &= ~MOD_MASK_SHIFT;
			}
			break;
		case REP_SFT:
			return false;
	}
	return true;
}
