#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-FirmwareVersion.h>
#include <Kaleidoscope-FocusSerial.h>

#define MO(n) ShiftToLayer(n)

#define Br_Decr Consumer_DisplayBrightnessDecrement
#define Br_Incr Consumer_DisplayBrightnessIncrement
#define Vol_Decr Consumer_VolumeDecrement
#define Vol_Incr Consumer_VolumeIncrement

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

#define Key_SwitchDisplay LGUI(LSHIFT(Key_RightArrow))
enum {
    COLEMAK_DH,
    SYMBOLS_LEFT,
};

// clang-format off
KEYMAPS(
    [COLEMAK_DH] = KEYMAP_STACKED(

    Key_Q             ,Key_W             ,Key_F           ,Key_P           ,Key_B,
    Key_A             ,Key_R             ,Key_S           ,Key_T           ,Key_G,
    Key_Z             ,Key_X             ,Key_C           ,Key_D           ,Key_V           ,Key_PrintScreen,
    Br_Incr           ,Br_Decr           ,Key_Escape      ,Key_Tab         ,Key_Space       ,Key_CapsLock

                      ,Key_J             ,Key_L           ,Key_U           ,Key_Y           ,Key_Semicolon
                      ,Key_M             ,Key_N           ,Key_E           ,Key_I           ,Key_O,
    Key_Menu          ,Key_K             ,Key_H           ,Key_Comma       ,Key_Period      ,Key_Slash,
    Key_SwitchDisplay ,Key_Backspace     ,Key_Enter       ,Key_Delete      ,Vol_Decr        ,Vol_Incr),

    [SYMBOLS_LEFT] = KEYMAP_STACKED(

    Key_Exclamation      ,Key_At             ,Key_Hash        ,Key_Dollar   ,Key_Percent,
    Key_LeftCurlyBrace   ,Key_LeftBracket    ,Key_LeftParen   ,Key_Quote    ,Key_Backtick,
    Key_RightCurlyBrace  ,Key_RightBracket   ,Key_RightParen  ,Key_DubQuote ,Key_Tilde        ,Key_PrintScreen,
    Br_Incr              ,Br_Decr            ,Key_Escape      ,Key_Equals   ,Key_Underscore   ,Key_Caret

            ,Key_A   ,Key_A   ,Key_A   ,Key_A   ,Key_A
            ,Key_A   ,Key_A   ,Key_A   ,Key_A   ,Key_A,
    Key_A   ,Key_A   ,Key_A   ,Key_A   ,Key_A   ,Key_A,
    Key_A   ,Key_A   ,Key_A   ,Key_A   ,Key_A   ,Key_A)
)
