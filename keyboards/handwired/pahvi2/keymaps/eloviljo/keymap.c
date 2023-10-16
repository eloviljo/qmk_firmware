#include "pahvi.h"

#define _QWERTY 0
#define _GAME 1
#define _FUNC 2
#define _NUM 3
#define _STUFF 4

enum custom_keycodes {
	ENTER_GAMING = SAFE_RANGE,
	EXIT_GAMING
};

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
*       |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   -  |
*       `----------------------------------'  `----------------------------------'
*
*              ,---------------------------.  ,---------------------------.
*              |      | ctrl |Sh/tab| _NUM |  | Enter| Space|BckSpc| alt  |
*              `---------------------------'  `---------------------------'
*/
[_QWERTY] = LAYOUT_split( \
		KC_W,	KC_E,	KC_R,	KC_T,									KC_Y,	KC_U,	KC_I,	KC_O,			\
KC_ESC,	KC_Q,	KC_S,	KC_D,	KC_F,	KC_G,									KC_H,	KC_J,	KC_K,	KC_L,	KC_P,	LSFT(KC_7),\
KC_LGUI,KC_A,	KC_X,	KC_C,	KC_V,	KC_B,									KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_QUOT,KC_NUHS,\
	KC_Z,				KC_LCTL,LSFT_T(KC_TAB),LT(_NUM,KC_SPC),LT(_STUFF,KC_ENT),LT(_FUNC,KC_SPC),KC_BSPC,KC_LALT,		KC_SLSH		\
),
/* gaming
*
*,-----------------------------------------.  ,-----------------------------------------.
*|   1  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |  F1  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*| TAB  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  | ESC  |  F2  |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*       |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   -  |
*       `----------------------------------'  `----------------------------------'
*
*              ,---------------------------.  ,---------------------------.
*              |      | ctrl | SHift| alt  |  | Enter| Space|BckSpc| alt  |
*              `---------------------------'  `---------------------------'
*/
[_GAME] = LAYOUT_split( \
		_______,_______,_______,_______,					_______,_______,_______,_______,		\
KC_1,	_______,_______,_______,_______,_______,					_______,_______,_______,_______,_______,KC_F1,	\
KC_TAB,	_______,_______,_______,_______,_______,					_______,_______,_______,_______,KC_ESC,KC_F2,	\
	_______,			KC_LCTL,KC_LSFT,KC_LALT,_______,_______,LT(_NUM,KC_BSPC),_______,		_______		\
),
/* fkeys
*
*,-----------------------------------------.  ,-----------------------------------------.
*|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*| F19  | MUTE | VOLD | VOLU | PLAY |  F20 |  | LEFT | DOWN |  UP  | RIGHT|   Ö  |  DEL |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*       |  REW | PREV | NEXT | FAST |  F21 |  | F22  | BACK | FORW |  F23 |  INS |
*       `----------------------------------'  `----------------------------------'
*
*              ,---------------------------.  ,---------------------------.
*              |      | ctrl |Sh/tab| _NUM |  | Enter| Space|BckSpc| alt  |
*              `---------------------------'  `---------------------------'
*/
[_FUNC] = LAYOUT_split( \
		KC_F3,	KC_F4,	KC_F5,	KC_F6,					KC_F7,	KC_F8,	KC_F9,	KC_F10,			\
KC_F1,	KC_F2,	KC_VOLD,KC_VOLU,KC_MPLY,KC_F20,					KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,KC_F11,	KC_F12, \
KC_F19,	KC_MUTE,KC_MPRV,KC_MNXT,KC_MFFD,KC_F21,					KC_F22,	KC_WBAK,KC_WFWD,KC_F23,	KC_SCLN,KC_DEL,	\
	KC_MRWD,		_______,_______,_______,_______,_______,_______,_______,_______,		KC_INS		\
),
/* numbers + stuff
*
*,-----------------------------------------.  ,-----------------------------------------.
*|   |  |   ^  |   {  |   [  |   (  | Home |  |  End |   )  |   ]  |   }  |   \  |   ?  |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*|   ~  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   "  |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*       |   !  |   @  |   #  |   $  |   %  |  |   &  |   =  |   <  |   >  |   +  |
*       `----------------------------------'  `----------------------------------'
*
*              ,---------------------------.  ,---------------------------.
*              |      | ctrl |Sh/tab| _NUM |  | Enter| Space|BckSpc| alt  |
*              `---------------------------'  `---------------------------'
*/
[_NUM] = LAYOUT_split( \
		RALT(KC_7),RALT(KC_8),LSFT(KC_8),KCHOME,			KC_END,	LSFT(KC_9),RALT(KC_9),RALT(KC_0),	\
RALT(KC_NUBS),LSFT(KC_RBRC),KC_2,KC_3,	KC_4,	KC_5,				KC_6,	KC_7,	KC_8,	KC_9,RALT(KC_MINS),LSFT(KC_MINS),\
RALT(KC_RBRC),KC_1,RALT(KC_2),LSFT(KC3),RALT(KC_4),LSFT(KC_5),			LSFT(KC_6),LSFT(KC_0),KC_NUBS,LSFT(KC_NUBS),KC_0,LSFT(KC_2),\
	LSFT(KC_1),		_______,_______,_______,_______,_______,_______,_______,_______,		KC_MINS		\
),
/* stuff
*
*,-----------------------------------------.  ,-----------------------------------------.
*|  `   |      |      |      |      |      |  |      |      |      |      |      |      |
*|------+------+------+------+------+------|  |------+------+------+------+------+------|
*|      |      | PGDN | PTAB | GAME |      |  |      | EXIT | NTAB | PGUP |   å  | PSCR |
*`------+------+------+------+------+------|  |------+------+------+------+------+------'
*       |      |      |      |      |      |  |      |      |      |      |RESET |
*       `----------------------------------'  `----------------------------------'
*
*              ,---------------------------.  ,---------------------------.
*              |      | ctrl |Sh/tab| _NUM |  | Enter| Space|BckSpc| alt  |
*              `---------------------------'  `---------------------------'
*/
[_STUFF] = LAYOUT_split( \
		_______,_______,_______,_______,				_______,_______,_______,_______,		\
LSFT(KC_EQL),_______,KC_PGDN,LCTL(LSFT(KC_TAB)),ENTER_GAMING,_______,		_______,EXIT_GAMING,LCTL(KC_TAB),KC_PGUP,_______,_______,\
_______,_______,_______,_______,_______,_______,				_______,_______,_______,_______,KC_LEFT_BRACKET,KC_PSCR,\
	_______,		_______,_______,_______,_______,_______,_______,_______,_______,		RESET		\
),

};
enum combo_events {
	FJ_ESC
};

const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[FJ_ESC] = COMBO_ACTION(fj_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
	switch(combo_index) {
		case FJ_ESC:
			if (pressed) {
				tap_code16(KC_ESC);
			}
			break;
	}
};
