#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

// clang-format off
#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-FirmwareVersion.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-Qukeys.h>

#include "keys.h"
#include "layers.h"
#include "macros.h"
#include "qukeys.h"
#include "keymaps.h"
// clang-format on

KALEIDOSCOPE_INIT_PLUGINS(Qukeys, EEPROMSettings, EEPROMKeymap, Focus,
                          FocusEEPROMCommand, FocusSettingsCommand, Macros,
                          FirmwareVersion); // Qukeys must be first

void setup() {
    setup_qukeys();
    Kaleidoscope.setup();
    EEPROMKeymap.setup(6);
    Layer.move(EEPROMSettings.default_layer());
}

void loop() { Kaleidoscope.loop(); }
