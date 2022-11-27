#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include "macros.h"

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    switch (macro_id) {
    case M_EQUALS:
      break;
    default:
      break;
    }
  }
  return MACRO_NONE;
}
