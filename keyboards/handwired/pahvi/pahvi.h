#pragma once

#include "quantum.h"

// readability
#define ___ KC_NO

#define LAYOUT_split( \
  K01, K02, K03, K04, K05, K06,				       K36, K35, K34, K33, K32, K31, \
  K11, K12, K13, K14, K15, K16,				       K46, K45, K44, K43, K42, K41, \
       K22, K23, K24, K25, K26, K27, K28, K29,	K59, K58, K57, K56, K55, K54, K53, K52	     \
  ) \
  { \
	  { K01, K02, K03, K04, K05, K06, ___, ___, ___ }, \
	  { K11, K12, K13, K14, K15, K16, ___, ___, ___ }, \
	  { ___, K22, K23, K24, K25, K26, K27, K28, K29 }, \
	  { K31, K32, K33, K34, K35, K36, ___, ___, ___ }, \
	  { K41, K42, K43, K44, K45, K46, ___, ___, ___ }, \
	  { ___, K52, K53, K54, K55, K56, K57, K58, K59 } \
  }

#define LAYOUT LAYOUT_split
