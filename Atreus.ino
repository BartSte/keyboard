#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-FirmwareVersion.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-Qukeys.h>

#include "keymaps.h"

/* TODO: */
/* - Add Macros */

using namespace kaleidoscope;

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Macros,
  FirmwareVersion)

void setup() {
  QUKEYS(
    plugin::Qukey(0, KeyAddr(2, 1), Key_LeftGui),
    plugin::Qukey(0, KeyAddr(2, 2), Key_LeftAlt),
    plugin::Qukey(0, KeyAddr(2, 3), Key_LeftShift),
    plugin::Qukey(0, KeyAddr(2, 4), Key_LeftControl),
    plugin::Qukey(0, KeyAddr(4, 3), ShiftToLayer(F_KEYS)),
    plugin::Qukey(0, KeyAddr(4, 4), ShiftToLayer(NAVIGATION_RIGHT)),
    plugin::Qukey(0, KeyAddr(4, 5), ShiftToLayer(NUMPAD)),

    plugin::Qukey(0, KeyAddr(2, 7), Key_LeftControl),
    plugin::Qukey(0, KeyAddr(2, 8), Key_LeftShift),
    plugin::Qukey(0, KeyAddr(2, 9), Key_LeftAlt),
    plugin::Qukey(0, KeyAddr(2, 10), Key_LeftGui),
    plugin::Qukey(0, KeyAddr(4, 8), ShiftToLayer(SYMBOLS)),
    plugin::Qukey(0, KeyAddr(4, 9), ShiftToLayer(NAVIGATION_LEFT)))

  Kaleidoscope.setup();
  EEPROMKeymap.setup(9);
  Layer.move(EEPROMSettings.default_layer());
}

void loop() {
  Kaleidoscope.loop();
}
