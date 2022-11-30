// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include "macros.h"
// clang-format on

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
    if (keyToggledOn(event.state)) {
        switch (macro_id) {
        case M_EQUALS:
            return Macros.type(PSTR(" = "));
        case M_1:
            return MACRO(D(LeftGui), T(1));
        case M_2:
            return MACRO(D(LeftGui), T(2));
        case M_3:
            return MACRO(D(LeftGui), T(3));
        case M_4:
            return MACRO(D(LeftGui), T(4));
        case M_5:
            return MACRO(D(LeftGui), T(5));
        case M_6:
            return MACRO(D(LeftGui), T(6));
        case M_7:
            return MACRO(D(LeftGui), T(7));
        case M_8:
            return MACRO(D(LeftGui), T(8));
        default:
            return MACRO_NONE;
        }
    }
    return MACRO_NONE;
}
