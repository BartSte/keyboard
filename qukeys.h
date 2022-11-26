#define MYQUKEYS {\
  QUKEYS(\
    plugin::Qukey(0, KeyAddr(1, 1), Key_LeftGui),\
    plugin::Qukey(0, KeyAddr(1, 2), Key_LeftAlt),\
    plugin::Qukey(0, KeyAddr(1, 3), Key_LeftShift),\
    plugin::Qukey(0, KeyAddr(1, 4), Key_LeftControl),\
\
    plugin::Qukey(0, KeyAddr(1, 7), Key_RightControl),\
    plugin::Qukey(0, KeyAddr(1, 8), Key_RightShift),\
    plugin::Qukey(0, KeyAddr(1, 9), Key_RightAlt),\
    plugin::Qukey(0, KeyAddr(1, 10), Key_RightGui),\
\
    plugin::Qukey(0, KeyAddr(3, 3), ShiftToLayer(F_KEYS)),\
    plugin::Qukey(0, KeyAddr(3, 4), ShiftToLayer(NAVIGATION_RIGHT)),\
    plugin::Qukey(0, KeyAddr(3, 5), ShiftToLayer(NUMPAD)),\
    plugin::Qukey(0, KeyAddr(3, 8), ShiftToLayer(SYMBOLS)),\
    plugin::Qukey(0, KeyAddr(3, 9), ShiftToLayer(NAVIGATION_LEFT)))\
}
