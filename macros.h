#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>

enum {
    M_EQUALS
};

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event);
