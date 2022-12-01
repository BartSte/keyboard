#pragma once

#include <Kaleidoscope.h>

#include "layers.h"
#include "keys.h"
#include "macros.h"

// clang-format off
KEYMAPS(

[COLEMAK_DH] = KEYMAP_STACKED( 
    Key_Q                ,Key_W             ,Key_F           ,Key_P           ,Key_B,          
    Key_A                ,Key_R             ,Key_S           ,Key_T           ,Key_G,          
    Key_Z                ,Key_X             ,Key_C           ,Key_D           ,Key_V           ,Key_PrintScreen,
    Key_BrIncr           ,Key_BrDecr        ,Key_Escape      ,Key_Tab         ,Key_Space       ,Key_CapsLock,
    
                          Key_J             ,Key_L           ,Key_U           ,Key_Y           ,Key_Semicolon,  
                          Key_M             ,Key_N           ,Key_E           ,Key_I           ,Key_O,          
    Key_Menu             ,Key_K             ,Key_H           ,Key_Comma       ,Key_Period      ,Key_Slash,
    Key_SwitchDisplay    ,Key_Backspace     ,Key_Enter       ,Key_Delete      ,Key_VolDecr     ,Key_VolIncr
),                                                                                         


[SYMBOLS] = KEYMAP_STACKED( 
    Key_Exclamation      ,Key_At            ,Key_Hash        ,Key_Dollar      ,Key_Percent,    
    Key_LeftCurlyBrace   ,Key_LeftBracket   ,Key_LeftParen   ,Key_Quote       ,Key_Backtick,   
    Key_RightCurlyBrace  ,Key_RightBracket  ,Key_RightParen  ,Key_DubQuote    ,Key_Tilde       ,Key_PrintScreen,
    ___                  ,___               ,___             ,M(M_EQUALS)     ,Key_Underscore  ,___,
    
                          ___               ,___             ,___             ,___             ,___,            
                          ___               ,Key_RCtrl       ,Key_RShift      ,Key_RAlt        ,Key_RGui,       
    ___                  ,___               ,___             ,___             ,___             ,___,
    ___                  ,___               ,___             ,___             ,___             ,___
),                                                                                         


[NUMPAD] = KEYMAP_STACKED( 
    ___                  ,___               ,___             ,___             ,___,            
    Key_LGui             ,Key_LAlt          ,Key_LShift      ,Key_LCtrl       ,___,            
    ___                  ,___               ,___             ,___             ,___             ,___,
    ___                  ,___               ,___             ,___             ,___             ,___,
    
                          Key_Star          ,Key_7           ,Key_8           ,Key_9           ,Key_Plus,       
                          Key_Backslash     ,Key_4           ,Key_5           ,Key_6           ,Key_Minus,      
    ___                  ,Key_Pipe          ,Key_1           ,Key_2           ,Key_3           ,Key_And,
    ___                  ,Key_Equals        ,Key_0           ,___             ,___             ,___
),                                                                                         


[NAVIGATION_LEFT] = KEYMAP_STACKED( 
    ___                  ,___               ,Key_A           ,___             ,___,            
    ___                  ,___               ,Key_A           ,Key_A           ,___,            
    ___                  ,Key_A             ,___             ,___             ,___             ,___,
    ___                  ,___               ,___             ,___             ,___             ,___,
    
                          ___               ,___             ,___             ,___             ,___,            
                          ___               ,Key_RCtrl       ,Key_RShift      ,Key_RAlt        ,Key_RGui,       
    ___                  ,___               ,___             ,___             ,___             ,___,
    ___                  ,___               ,___             ,___             ,___             ,___
),                                                                                         


[NAVIGATION_RIGHT] = KEYMAP_STACKED( 
    ___                  ,___               ,___             ,___             ,___,            
    Key_LGui             ,Key_LAlt          ,Key_LShift      ,Key_LCtrl       ,___,            
    ___                  ,___               ,___             ,___             ,___             ,___,
    ___                  ,___               ,___             ,___             ,___             ,___,
    
                          Key_Home          ,Key_PageDown    ,Key_PageUp      ,Key_End         ,Key_Play,       
                          Key_LeftArrow     ,Key_DownArrow   ,Key_UpArrow     ,Key_RightArrow  ,Key_Next,       
    ___                  ,___               ,Key_A           ,Key_A           ,Key_A           ,Key_Prev,
    ___                  ,___               ,___             ,RALT(Key_F4)    ,___             ,___
),                                                                                         


[F_KEYS] = KEYMAP_STACKED( 
    ___                  ,___               ,___             ,___             ,___,            
    Key_LGui             ,Key_LAlt          ,Key_LShift      ,Key_LCtrl       ,___,            
    ___                  ,___               ,___             ,___             ,___             ,___,
    ___                  ,___               ,___             ,___             ,___             ,___,
    
                          Key_Pause         ,Key_F7          ,Key_F8          ,Key_F9          ,Key_F10,        
                          Key_ScrollLock    ,Key_F4          ,Key_F5          ,Key_F6          ,Key_F11,        
    ___                  ,Key_Insert        ,Key_F1          ,Key_F2          ,Key_F3          ,Key_F12,
    ___                  ,___               ,___             ,___             ,___             ,___
)                                                                                          
);                                                                                         
// clang-format on
