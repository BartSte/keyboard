#pragma once

#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-FirmwareVersion.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope.h>

#define MO(n) ShiftToLayer(n)

#define Key_Tilde LSHIFT(Key_Backtick)
#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_RightParen LSHIFT(Key_9)
#define Key_LeftParen LSHIFT(Key_0)
#define Key_Underscore LSHIFT(Key_Minus)
#define Key_Plus LSHIFT(Key_Equals)

#define Key_LeftCurlyBrace LSHIFT(Key_LeftBracket)
#define Key_RightCurlyBrace LSHIFT(Key_RightBracket)
#define Key_DubQuote LSHIFT(Key_Quote)

#define Key_BrDecr Consumer_DisplayBrightnessDecrement
#define Key_BrIncr Consumer_DisplayBrightnessIncrement
#define Key_VolDecr Consumer_VolumeDecrement
#define Key_VolIncr Consumer_VolumeIncrement

#define Key_SwitchDisplay LGUI(LSHIFT(Key_RightArrow))
#define ___ Key_Transparent

#define Key_RCtrl Key_RightControl
#define Key_RShift Key_RightShift
#define Key_RAlt Key_RightAlt
#define Key_RGui Key_RightGui
#define Key_LCtrl Key_LeftControl
#define Key_LShift Key_LeftShift
#define Key_LAlt Key_LeftAlt
#define Key_LGui Key_LeftGui

enum {
    COLEMAK_DH,
    SYMBOLS,
    NUMPAD,
    NAVIGATION_RIGHT,
    NAVIGATION_LEFT,
    F_KEYS
};

// clang-format off
KEYMAPS(

[COLEMAK_DH] = KEYMAP_STACKED(

    Key_Q             ,Key_W             ,Key_F           ,Key_P           ,Key_B,
    Key_A             ,Key_R             ,Key_S           ,Key_T           ,Key_G,
    Key_Z             ,Key_X             ,Key_C           ,Key_D           ,Key_V           ,Key_PrintScreen,
    Key_BrIncr        ,Key_BrDecr        ,Key_Escape      ,Key_Tab         ,Key_Space       ,Key_CapsLock,

                       Key_J             ,Key_L           ,Key_U           ,Key_Y           ,Key_Semicolon,
                       Key_M             ,Key_N           ,Key_E           ,Key_I           ,Key_O,
    Key_Menu          ,Key_K             ,Key_H           ,Key_Comma       ,Key_Period      ,Key_Slash,
    Key_SwitchDisplay ,Key_Backspace     ,Key_Enter       ,Key_Delete      ,Key_VolDecr     ,Key_VolIncr
    ),

[SYMBOLS] = KEYMAP_STACKED(

    Key_Exclamation      ,Key_At             ,Key_Hash        ,Key_Dollar   ,Key_Percent,
    Key_LeftCurlyBrace   ,Key_LeftBracket    ,Key_LeftParen   ,Key_Quote    ,Key_Backtick,
    Key_RightCurlyBrace  ,Key_RightBracket   ,Key_RightParen  ,Key_DubQuote ,Key_Tilde        ,Key_PrintScreen,
    ___                  ,___                ,___             ,Key_Equals   ,Key_Underscore   ,Key_Caret,

           ___   ,___       ,___        ,___        ,___,
           ___   ,Key_RCtrl ,Key_RShift ,Key_RAlt   ,Key_RGui,
    ___   ,___   ,___       ,___        ,___        ,___,
    ___   ,___   ,___       ,___        ,___        ,___
    ),

[NUMPAD] = KEYMAP_STACKED(

    ___         ,___        ,___        ,___        ,___,
    Key_LGui    ,Key_LAlt   ,Key_LShift ,Key_LCtrl  ,___,
    ___         ,___        ,___        ,___        ,___    ,___,
    ___         ,___        ,___        ,___        ,___    ,___,

                 ___        ,Key_7      ,Key_8      ,Key_9  ,___,
                 ___        ,Key_4      ,Key_5      ,Key_6  ,___,
    ___         ,___        ,Key_1      ,Key_2      ,Key_3  ,___,
    ___         ,___        ,___        ,___        ,___    ,___
    ),

[NAVIGATION_RIGHT] = KEYMAP_STACKED(

    ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,

           ___   ,___   ,___   ,___   ,___,
           ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___
    ),

[NAVIGATION_LEFT] = KEYMAP_STACKED(

    ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,

           ___   ,___   ,___   ,___   ,___,
           ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___
    ),

[F_KEYS] = KEYMAP_STACKED(

    ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,

           ___   ,___   ,___   ,___   ,___,
           ___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___,
    ___   ,___   ,___   ,___   ,___   ,___
    )
)
