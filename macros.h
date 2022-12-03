#pragma once

// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
// clang-format on

enum { M_EQUALS, M_BART, M_STE, M_MAIL, M_NAME, M_WORK, M_PHONE };

const macro_t *my_macros(uint8_t macro_id, KeyEvent &event);

