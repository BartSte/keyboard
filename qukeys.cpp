#include <Arduino.h>
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-Qukeys.h>
#include "layers.h"

using namespace kaleidoscope;

void setup_qukeys(){
  QUKEYS(
    plugin::Qukey(0, KeyAddr(1, 0), Key_LeftGui),
    plugin::Qukey(0, KeyAddr(1, 1), Key_LeftAlt),
    plugin::Qukey(0, KeyAddr(1, 2), Key_LeftShift),
    plugin::Qukey(0, KeyAddr(1, 3), Key_LeftControl),

    plugin::Qukey(-1, KeyAddr(1, 8), Key_RightControl),
    plugin::Qukey(-1, KeyAddr(1, 9), Key_RightShift),
    plugin::Qukey(-1, KeyAddr(1, 10), Key_RightAlt),
    plugin::Qukey(-1, KeyAddr(1, 11), Key_RightGui),

    plugin::Qukey(0, KeyAddr(3, 2), ShiftToLayer(F_KEYS)),
    plugin::Qukey(0, KeyAddr(3, 3), ShiftToLayer(NAVIGATION_RIGHT)),
    plugin::Qukey(0, KeyAddr(3, 4), ShiftToLayer(NUMPAD)),
    plugin::Qukey(0, KeyAddr(3, 7), ShiftToLayer(SYMBOLS)),
    plugin::Qukey(0, KeyAddr(3, 8), ShiftToLayer(NAVIGATION_LEFT)))
}
