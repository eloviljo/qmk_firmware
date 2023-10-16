#pragma once

#include "quantum.h"

// readability
#define ___ KC_NO

#define LAYOUT_split( \
            K01, K02, K03, K04,                     K25, K24, K23, K22,           \
  K05, K06, K07, K08, K09, K10,                     K31, K30, K29, K28, K27, K26, \
  K11, K12, K13, K14, K15, K16,                     K37, K36, K35, K34, K33, K32, \
       K17,           K18, K19, K20, K21, K42, K41, K40, K39,           K38       \
  ) \
  { \
	{ ___, ___, K01, K02, K03, K04, ___, ___ }, \
	{ K05, K06, K07, K08, K09, K10, ___, ___ }, \
	{ K11, K12, K13, K14, K15, K16, ___, ___ }, \
	{ ___, K17, ___, ___, K18, K19, K20, K21 }, \
	{ ___, ___, K22, K23, K24, K25, ___, ___ }, \
	{ K26, K27, K28, K29, K30, K31, ___, ___ }, \
	{ K32, K33, K34, K35, K36, K37, ___, ___ }, \
	{ ___, K38, ___, ___, K39, K40, K41, K42 } \
  }

#define LAYOUT LAYOUT_split
