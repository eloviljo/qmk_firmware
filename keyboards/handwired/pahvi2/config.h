#pragma once

#include "config_common.h"

// USE Device descriptor parameter
#define VENDOR_ID	0xABCD
#define PRODUCT_ID	0x0001
#define DEVICE_VER	0x0001
#define MANUFACTURER	"EloTech"
#define PRODUCT		"Pahvi 2.0"

// key matrix size
// rows are doubled up
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

// COL2ROW or ROW2COL
#define DIODE_DIRECTION COL2ROW

// wiring of each half
#define MATRIX_ROW_PINS { B3, B5, B4, C6 }
#define MATRIX_COL_PINS { B2, B6, F6, F5, F7, B1, E6, D7 }
#define MATRIX_ROW_PINS_RIGHT { E6, B6, B2, F7 }
#define MATRIX_COL_PINS_RIGHT { B4, B5, D4, D0, C6, D7, B3, B1 }

#define MASTER_LEFT

#define SOFT_SERIAL_PIN D2
#define USE_SERIAL

#define DEBOUNCE 10
#define NO_ACTION_ONESHOT

#define FORCE_NKRO

#define TAPPING_TERM 200
#define COMBO_COUNT 2
