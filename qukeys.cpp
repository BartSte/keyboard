#include "layers.h"
#include <Arduino.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-Qukeys.h>
#include <Kaleidoscope.h>

using namespace kaleidoscope;

// KeyAddr Atreus Keyboardio
// 0,0  0,1  0,2  0,3  0,4  ___  ___  0,7  0,8  0,9  0,10 0,11
// 1,0  1,1  1,2  1,3  1,4  ___  ___  1,7  1,8  1,9  1,10 1,11
// 2,0  2,1  2,2  2,3  2,4  2,5  2,6  2,7  2,8  2,9  2,10 2,11
// 3,0  3,1  3,2  3,3  3,4  3,5  3,6  3,7  3,8  3,9  3,10 3,11

// Qukey layout
// ___   ___   NUM     ___   ___               ___   ___   SYM   ___   ___
// GUI   ALT   SHIFT   CTRL  FKEY              ___   CTRL  SHIFT ALT   GUI
// ___   ___   ____    MACR  ___   ___   ___   ___   MACL  ___   ___   ___
// ___   ___   NAV     ___   ___   ___   ___   ___   ___   NAV   ___   ___


void setup_qukeys() {
  QUKEYS(
      // Row 0
      plugin::Qukey(0, KeyAddr(0, 2), ShiftToLayer(NUMPAD)),

      plugin::Qukey(0, KeyAddr(0, 9), ShiftToLayer(SYMBOLS)),

      // Row 1
      plugin::Qukey(0, KeyAddr(1, 0), Key_LeftGui),
      plugin::Qukey(0, KeyAddr(1, 1), Key_LeftAlt),
      plugin::Qukey(0, KeyAddr(1, 2), Key_LeftShift),
      plugin::Qukey(0, KeyAddr(1, 3), Key_LeftControl),
      plugin::Qukey(0, KeyAddr(1, 4), ShiftToLayer(F_KEYS)),

      plugin::Qukey(0, KeyAddr(1, 8), Key_RightControl),
      plugin::Qukey(0, KeyAddr(1, 9), Key_RightShift),
      plugin::Qukey(0, KeyAddr(1, 10), Key_RightAlt),
      plugin::Qukey(0, KeyAddr(1, 11), Key_RightGui),

      // Row 2
      plugin::Qukey(0, KeyAddr(2, 3), ShiftToLayer(MACROS_RIGHT)),

      plugin::Qukey(0, KeyAddr(2, 8), ShiftToLayer(MACROS_LEFT)),

      // Row 3
      plugin::Qukey(0, KeyAddr(3, 3), ShiftToLayer(NAVIGATION_RIGHT)),
      plugin::Qukey(0, KeyAddr(3, 8), ML(RightGui, NAVIGATION_LEFT)))
}
