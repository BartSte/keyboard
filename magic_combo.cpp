#include "magic_combo.h"

void tap_mute(uint8_t combo_index) { Macros.tap(Key_Mute); }

USE_MAGIC_COMBOS([MUTE] = {.action = tap_mute,
                                    .keys = {R3C10, R3C11}});
