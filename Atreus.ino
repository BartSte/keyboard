#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-Qukeys.h>

#include "keys.h"
#include "layers.h"
#include "macros.h"
#include "qukeys.h"
#include "keymaps.h"
// clang-format on

KALEIDOSCOPE_INIT_PLUGINS(Qukeys, Focus, Macros); // Qukeys must be first

void setup() {
    setup_qukeys(); 
    Kaleidoscope.setup();
}

void loop() { Kaleidoscope.loop(); }
