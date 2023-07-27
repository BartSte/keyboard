// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include "macros.h"
#include "personal_macros.h"
// clang-format on

const macro_t *my_macros(uint8_t macro_id, KeyEvent &event) {
    if (keyToggledOn(event.state)) {
        switch (macro_id) {
        case M_EQUALS:
            return Macros.type(PSTR(" = "));
        case M_BART:
            return Macros.type(PSTR("Bart"));
        case M_STE:
            return Macros.type(PSTR("Steensma"));
        case M_NAME:
            return Macros.type(PSTR("Bart Steensma"));
        case M_MAIL:
            return Macros.type(PSTR(MAIL));
        case M_WORK:
            return Macros.type(PSTR(WORK));
        case M_PHONE:
            return Macros.type(PSTR(PHONE));
        case M_PWE:
            return Macros.type(PSTR(PWE));
        case M_PWL:
            return Macros.type(PSTR(PWL));
        case M_GMAIL:
            return Macros.type(PSTR(GMAIL));
        default:
            return MACRO_NONE;
        }
    }
    return MACRO_NONE;
}
