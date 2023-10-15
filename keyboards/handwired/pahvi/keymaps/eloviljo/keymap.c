#include "pahvi.h"

#define _QWERTY 0
#define _GAME 1
#define _SCUFFED 2
#define _CUBE 3
#define _FUNC 4
#define _NUM 5
#define _STUFF 6
#define _AKLFIN 7
// #define _AKLENG 8


enum custom_keycodes {
	ENTER_GAMING = SAFE_RANGE,
	AKL_FIN,
	// AKL_ENG,
	ENTER_SCUFFED,
	EXIT_GAMING,
	/*
	R,
	R_I,
	U,
	U_I,
	F,
	F_I,
	L,
	L_I,
	D,
	D_I,
	B,
	B_I,
	M,
	M_I,
	r,
	r_I,
	u,
	u_I,
	l,
	l_I,
	d,
	d_I,
	x,
	x_I,
	y,
	y_I,
	z,
	z_I,
	DBL_BCKSPC,
	TRPL_BCKSPC,
	R2,
	R2_I,
	U2,
	U2_I,
	F2,
	F2_I,
	L2,
	L2_I,
	D2,
	D2_I,
	B2,
	B2_I,
	M2,
	M2_I,
	r2,
	r2_I,
	u2,
	u2_I,
	l2,
	l2_I,
	d2,
	d2_I,
	x2,
	y2,
	z2
	*/
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
		case ENTER_SCUFFED:
			if (record->event.pressed) {
				combo_disable();
				layer_on(_SCUFFED);
			} else {
			}
			break;
		case AKL_FIN:
			if (record->event.pressed) {
				combo_enable();
				layer_on(_AKLFIN);
		/*case AKL_ENG:
			if (record->event.pressed) {
				combo_enable();
				layer_on(_AKLENG);*/
			/*
		case ENTER_CUBING:
			if (record->event.pressed) {
				combo_disable();
				layer_on(_CUBE);
			} else {
			}
			break;
		case R:
			if (record->event.pressed) {
				SEND_STRING("R ");
			} else {
			}
			break;
		case R_I:
			if (record->event.pressed) {
				SEND_STRING("R\\ ");
			} else {
			}
			break;
		case U:
			if (record->event.pressed) {
				SEND_STRING("U ");
			} else {
			}
			break;
		case U_I:
			if (record->event.pressed) {
				SEND_STRING("U\\ ");
			} else {
			}
			break;
		case F:
			if (record->event.pressed) {
				SEND_STRING("F ");
			} else {
			}
			break;
		case F_I:
			if (record->event.pressed) {
				SEND_STRING("F\\ ");
			} else {
			}
			break;
		case L:
			if (record->event.pressed) {
				SEND_STRING("L ");
			} else {
			}
			break;
		case L_I:
			if (record->event.pressed) {
				SEND_STRING("L\\ ");
			} else {
			}
			break;
		case D:
			if (record->event.pressed) {
				SEND_STRING("D ");
			} else {
			}
			break;
		case D_I:
			if (record->event.pressed) {
				SEND_STRING("D\\ ");
			} else {
			}
			break;
		case B:
			if (record->event.pressed) {
				SEND_STRING("B ");
			} else {
			}
			break;
		case B_I:
			if (record->event.pressed) {
				SEND_STRING("B\\ ");
			} else {
			}
			break;
		case M:
			if (record->event.pressed) {
				SEND_STRING("M ");
			} else {
			}
			break;
		case M_I:
			if (record->event.pressed) {
				SEND_STRING("M\\ ");
			} else {
			}
			break;
		case r:
			if (record->event.pressed) {
				SEND_STRING("r ");
			} else {
			}
			break;
		case r_I:
			if (record->event.pressed) {
				SEND_STRING("r\\ ");
			} else {
			}
			break;
		case u:
			if (record->event.pressed) {
				SEND_STRING("u ");
			} else {
			}
			break;
		case u_I:
			if (record->event.pressed) {
				SEND_STRING("u\\ ");
			} else {
			}
			break;
		case l:
			if (record->event.pressed) {
				SEND_STRING("l ");
			} else {
			}
			break;
		case l_I:
			if (record->event.pressed) {
				SEND_STRING("l\\ ");
			} else {
			}
			break;
		case d:
			if (record->event.pressed) {
				SEND_STRING("d ");
			} else {
			}
			break;
		case d_I:
			if (record->event.pressed) {
				SEND_STRING("d\\ ");
			} else {
			}
			break;
		case x:
			if (record->event.pressed) {
				SEND_STRING("x ");
			} else {
			}
			break;
		case x_I:
			if (record->event.pressed) {
				SEND_STRING("x\\ ");
			} else {
			}
			break;
		case y:
			if (record->event.pressed) {
				SEND_STRING("y ");
			} else {
			}
			break;
		case y_I:
			if (record->event.pressed) {
				SEND_STRING("y\\ ");
			} else {
			}
			break;
		case z:
			if (record->event.pressed) {
				SEND_STRING("z ");
			} else {
			}
			break;
		case z_I:
			if (record->event.pressed) {
				SEND_STRING("z\\ ");
			} else {
			}
			break;
			*/
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |	|   Y  |   U  |   I  |   O  |   P  |   /  |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * | GUI  |   A  |   S  |   D  |   F  |   G  |	|   H  |   J  |   K  |   L  |   Ä  |   '  |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |   Z  |   X  |   C  |   V  |   B  |	|   N  |   M  |   ,  |   .  |   -  |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			|Sh/tab| ctrl | _NUM |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
[_QWERTY] = LAYOUT_split( \
KC_ESC,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,												KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	LSFT(KC_7),\
KC_LGUI,KC_A,	KC_S,	KC_D,	KC_F,	KC_G,												KC_H,	KC_J,	KC_K,	KC_L,	KC_QUOT,KC_NUHS,\
	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_LCTL,LSFT_T(KC_TAB),LT(_NUM,KC_SPC),LT(_STUFF,KC_ENT),LT(_FUNC,KC_SPC),LALT_T(KC_BSPC),KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_SLSH		\
),
/* Gaming
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * |   1  |   Q  |   W  |   E  |   R  |   T  |	|   Y  |   U  |   I  |   O  | Back |  F1  |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |	|   H  |   J  |   K  |   L  | ESC  |  F2  |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |   Z  |   X  |   C  |   V  |   B  |	|   N  |   M  |   ,  |   .  |   -  |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			| ctrl | Shift| alt  |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
[_GAME] = LAYOUT_split( \
KC_1,	_______,_______,_______,_______,_______,							_______,_______,_______,_______,_______,KC_F1,	\
KC_TAB,	_______,_______,_______,_______,_______,							_______,_______,_______,_______,KC_ESC,	KC_F2,	\
	_______,_______,_______,_______,_______,KC_LCTL,KC_LSFT,KC_LALT,_______,_______,LT(_NUM,KC_BSPC),_______,_______,_______,_______,_______	\
),
/* Scuffed gaming
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * |   1  |   Q  |   W  |   W  |   R  |   T  |	|   Y  |   U  |   I  |   O  | Back |  F1  |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * | TAB  |   A  |   A  |   S  |   D  |   G  |	|   H  |   J  |   K  |   L  | ESC  |  F2  |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |   Z  |   X  |   C  |   V  |   B  |	|   N  |   M  |   ,  |   .  |   -  |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			| ctrl | Shift| alt  |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
/*
[_SCUFFED] = LAYOUT_split( \
KC_1,	_______,_______,KC_W,_______,_______,							_______,_______,_______,_______,_______,KC_F1,	\
KC_TAB,	_______,KC_A,KC_S,KC_D,_______,							_______,_______,_______,_______,KC_ESC,	KC_F2,	\
	_______,_______,_______,_______,_______,KC_LCTL,KC_LSFT,KC_LALT,_______,_______,LT(_NUM,KC_BSPC),_______,_______,_______,_______,_______	\
),
*/
/* Fkeys
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |	| F7   |  F8  |  F9  | F10  | F11  | F12  |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * |  F19 | MUTE | VOLD | VOLU | PLAY |  F20 |	| LEFT | DOWN |  UP  | RIGHT|   Ö  |  DEL |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |  REW | PREV | NEXT | FAST |  F21 |	|  F22 | BACK | FORW |  F23 |  INS |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			| ctrl |Sh/tab| _NUM |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
[_FUNC] = LAYOUT_split( \
KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,							KC_F7,	KC_F8,	KC_F9,	KC_F10, KC_F11, KC_F12,	\
KC_F19,	KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,KC_F20,							KC_LEFT,KC_DOWN,KC_UP,	KC_RIGHT,KC_SCLN,KC_DEL,\
	KC_MRWD,KC_MPRV,KC_MNXT,KC_MFFD,KC_F21,	_______,_______,_______,_______,_______,_______,KC_F22,	KC_WBAK,KC_WFWD,KC_F23,KC_INS		\
),
/* Numbers + stuff
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * |   |  |   ^  |   {  |   [  |   (  | Home |	|  End |   )  |   ]  |   }  |   \  |   ?  |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * |   ~  |   1  |   2  |   3  |   4  |   5  |	|   6  |   7  |   8  |   9  |   0  |   "  |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |   !  |   @  |   #  |   $  |   %  |	|   &  |   =  |   <  |   >  |   +  |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			| ctrl |Sh/tab| _NUM |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
[_NUM] = LAYOUT_split( \
RALT(KC_NUBS),LSFT(KC_RBRC),RALT(KC_7),RALT(KC_8),LSFT(KC_8),KC_HOME,						KC_END,LSFT(KC_9),RALT(KC_9),RALT(KC_0),RALT(KC_MINS),LSFT(KC_MINS),\
RALT(KC_RBRC),KC_1,	KC_2,	KC_3,	KC_4,	KC_5,							KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	LSFT(KC_2),\
	LSFT(KC_1),RALT(KC_2),LSFT(KC_3),RALT(KC_4),LSFT(KC_5),_______,_______,_______,_______,_______,_______,LSFT(KC_6),LSFT(KC_0),KC_NUBS,LSFT(KC_NUBS),KC_MINS		\
),
/* Stuff
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * |      |      |      |      |      |      |	|      |      |      |      |      |      |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * |      |      | PGDN | PTAB | GAME |      |	|      | EXIT | NTAB | PGUP |   å  | PSRC |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |      |      |      | CUBE |      |	|      |      |      |      |RESET |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			| ctrl |Sh/tab| _NUM |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
[_STUFF] = LAYOUT_split( \
LSFT(KC_EQL),_______,_______,_______,_______,_______,						_______,_______,_______,_______,_______,_______,\
_______,_______,KC_PGDN,LCTL(LSFT(KC_TAB)),ENTER_GAMING,_______,						_______,EXIT_GAMING,LCTL(KC_TAB),KC_PGUP,KC_LEFT_BRACKET,KC_PSCR,\
	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, RESET		\
),
/* Cubing
 *
 * ,-----------------------------------------.	,-----------------------------------------.
 * |  ESC |  z'  |  B   |  L'  |  l'  |  x   |	|  x   |  r   |  R   |  B'  |  z   |  F1  |	
 * |------+------+------+------+------+------|	|------+------+------+------+------+------|
 * | TAB  |  y'  |  D   |  L   |  U'  |  F'  |	|  F   |  U   |  R'  |  D'  |  y   |  F2  |
 * `------+------+------+------+------+------|	|------+------+------+------+------+------'
 *        |  d   |  u'  |  M'  |  l   |  x'  |	|  x'  |  r'  |  M   |  u   |  d'  |
 *        `----------------------------------'	`----------------------------------'
 *
 * 			,--------------------.	,--------------------.
 * 			| ctrl | Shift| alt  |	| Enter| Space|BckSpc|
 * 			`--------------------'	`--------------------'
 */
/*
[_CUBE] = LAYOUT_split( \
KC_ESC,	z_I,B,L_I,l_I,x,							x,r,R,B_I,z,KC_F1,	\
KC_TAB,	y_I,D,L,U_I,F_I,							F,U,R_I,D_I,y,	KC_F2,	\
	d,u_I,M_I,l,x_I,KC_LCTL,KC_LSFT,KC_LALT,_______,_______,LT(_NUM,KC_BSPC),x_I,r_I,M,u,d_I	\
)
*/
};
enum combo_events {
	FJ_ESC,
};


const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[FJ_ESC] = COMBO_ACTION(fj_combo),
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
