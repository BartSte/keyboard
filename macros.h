#pragma once

// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
// clang-format on

enum { M_EQUALS, M_1, M_2, M_3, M_4, M_5, M_6, M_7, M_8 };

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event);
