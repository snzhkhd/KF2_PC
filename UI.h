#pragma once

#include <string>
// Адреса
#define ADDR_MSG_RECT_ARRAY   0x8006E238
#define ADDR_MSG_COLOUR       0x80194DF8
#define ADDR_MSG_STATE        0x80194df6  //  KFMessageState
#define ADDR_MSG_TIMER        0x80194df7  //  KFMessageTimer
#define ADDR_MSG_QUEUE        0x80194DDC
#define ADDR_MSG_CURRENT      0x80194DF4
#define ADDR_FONT_CONFIG      0x80067AB4

#define MSG_RECT_SIZE  0x12  // 18 байт на запись

struct CustomMessage {
    bool active = false;
    uint8_t chars[24];  // max 24 символов, 0xFF = терминатор
    int posX = 80;
    int posY = 20;
    float timer = 0.0f;
    float duration = 3.0f;
    int alpha = 0;
    int state = 0; // 0=off, 1=fadein, 2=on, 3=fadeout
};

inline CustomMessage g_customMsg;


void ShowCustomMessage(uint8_t* rdram, const std::string& text, float duration = 3.0f, int x = 100, int y = 200);
void UpdateCustomMessageState();



void FillRectWithChar(uint8_t* rdram, int rectIdx, uint8_t kfChar, int screenX, int screenY);