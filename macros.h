#pragma once

// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
// clang-format on

enum {
    M_BART,
    M_EQUALS,
    M_GMAIL,
    M_MAIL,
    M_NAME,
    M_PHONE,
    M_PWE,
    M_PWL,
    M_STE,
    M_WORK
};

const macro_t *my_macros(uint8_t macro_id, KeyEvent &event);
