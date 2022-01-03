#pragma once

#include "config_common.h"

/* USE Device descriptor parameter */
#define VENDOR_ID	0x1234
#define PRODUCT_ID	0X5678
#define DEVICE_VER	0x0001
#define MANUFACTURER	ME
#define PRODUCT		Pahvi

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 6
#define MATRIX_COLS 9

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// wiring of each ahlf
#define MATRIX_ROW_PINS { B6, B5, B4}
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, E6, D7, C6 }
#define MATRIX_ROW_PINS_RIGHT { B5, B6, B2}
#define MATRIX_COL_PINS_RIGHT { D0, D4, C6, D7, E6, B4, F6, F5, F4 }

#define MASTER_RIGHT

#define SOFT_SERIAL_PIN D2
#define USE_SERIAL
/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define NO_ACTION_ONESHOT

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define COMBO_COUNT 2

#define QMK_ESC_OUTPUT B6
#define QMK_EST_INPUT F5
#define QMK_LED B0
#define QMK_SPEAKER B1
