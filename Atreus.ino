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
#include "qukeys.h"

/* TODO: */
/* - Add Macros */

using namespace kaleidoscope;

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,  // Qukeys must be first
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Macros,
  FirmwareVersion)

void setup() {
  MYQUKEYS;
  Kaleidoscope.setup();
  EEPROMKeymap.setup(6);
  Layer.move(EEPROMSettings.default_layer());
}

void loop() {
  Kaleidoscope.loop();
}
