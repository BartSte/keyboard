// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-Qukeys.h>
// clang-format on

#include "macros.h"
#include "qukeys.h"
#include "keymaps.h"

KALEIDOSCOPE_INIT_PLUGINS(Qukeys, Macros); // Qukeys must be first

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
    return my_macros(macro_id, event);
}

void setup() {
    setup_qukeys(); 
    Kaleidoscope.setup();
}

void loop() { Kaleidoscope.loop(); }
