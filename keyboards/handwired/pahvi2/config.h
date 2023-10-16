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
#define MATRIX_ROW_PINS {}
#define MATRIX_COL_PINS {}
#define MATRIX_ROW_PINS_RIGHT {}
#define MATRIX_COL_PINS_RIGHT {}

#define MASTER_LEFT

#define SOFT_SERIAL_PIN
#define USE_SERIAL

#define DEBOUNCE 10
#define NO_ACTION_ONESHOT

#define FORCE_NKRO

#define TAPPING_TERM 200
