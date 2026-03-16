#include "UI.h"
#include "scr/funcs.h"

#include <chrono>
#include <unordered_map>

static std::unordered_map<std::string, unsigned char> charMap =
{
    // --- РЯД 0 (0x00 - 0x0F) ---
    {"A", 0x00}, {"А", 0x00},{"a", 0x00}, {"а", 0x00},  // Латинская A и Русская А выглядят одинаково
    {"B", 0x01}, {"В", 0x01}, {"b", 0x01}, {"в", 0x01}, // B и В
    {"C", 0x02}, {"С", 0x02}, {"c", 0x02}, {"с", 0x02}, // C и С
    {"Д", 0x03}, {"д", 0x03}, {"D", 0x03}, {"d", 0x03},
    {"E", 0x04}, {"Е", 0x04},{"e", 0x04}, {"е", 0x04},
    {"Ц", 0x05}, {"ц", 0x05}, {"F", 0x05}, {"f", 0x05},
    {"Э", 0x06},{"э", 0x06},{"G", 0x06},{"g", 0x06},
    {"H", 0x07}, {"Н", 0x07},{"h", 0x07}, {"н", 0x07},
    {"I", 0x08},{"i", 0x08},
    {"Г", 0x09},{"г", 0x09},{"J", 0x09},{"j", 0x09},
    {"K", 0x0A}, {"К", 0x0A},{"k", 0x0A}, {"к", 0x0A},
    {"L", 0x0B},{"l", 0x0B},{"Л", 0x0B},{"л", 0x0B},
    {"M", 0x0C}, {"М", 0x0C},{"m", 0x0C}, {"м", 0x0C},
    {"N", 0x0D}, {"И", 0x0D},{"n", 0x0D}, {"и", 0x0D},
    {"Ш", 0x0E}, {"ш", 0x0E},{"O", 0x0E}, {"o", 0x0E},
    {"P", 0x0F}, {"Р", 0x0F}, {"p", 0x0F}, {"р", 0x0F},

    // --- РЯД 1 (0x10 - 0x1F) ---
    {"Ф", 0x10},{"ф", 0x10},{"Q", 0x10},{"q", 0x10},
    {"Я", 0x11},{"я", 0x11},{"R", 0x11},{"r", 0x11},
    {"Ь", 0x12},{"ь", 0x12},{"S", 0x12},{"s", 0x12},
    {"T", 0x13}, {"Т", 0x13},{"t", 0x13}, {"т", 0x13},
    {"U", 0x14},{"u", 0x14},
    {"Ю", 0x15},{"ю", 0x15},{"V", 0x15},{"v", 0x15},
    {"Ж", 0x16},{"ж", 0x16},{"W", 0x16},{"w", 0x16},
    {"Х", 0x17},{"х", 0x17},{"X", 0x17},{"x", 0x17},
    {"У", 0x18},{"у", 0x18},{"Y", 0x18 }, { "y", 0x18 },
    {"П", 0x19},{"п", 0x19},{"Z", 0x19},{"z", 0x19},

    // --- РЯД 2 (Цифры) (0x20 - 0x29) ---
    {"0", 0x20}, {"1", 0x21}, {"2", 0x22}, {"3", 0x23}, {"4", 0x24}, {"5", 0x25}, {"6", 0x26}, {"7", 0x27}, {"8", 0x28}, {"9", 0x29},

    // --- РЯД 3 (Символы) ---30-40
    {".", 0x30}, {",", 0x31}, {"-", 0x33}, {"=", 0x34}, {"/", 0x35}, {"*", 0x37}, {"#", 0x38}, {"!", 0x39}, {"-", 0x40}, {"?", 0x41},

    //40-50
    //skip
    //50-60

    {"Б", 0x53},{"б", 0x53},
    {"З", 0x54},{"з", 0x54},
    {"О", 0x55},{"о", 0x55},
    {"Д", 0x56},{"д", 0x56},
    {"Ч", 0x57},{"ч", 0x57},
    {"Ы", 0x58},{"ы", 0x58},

    //space
    {" ", 254}
};



static uint8_t StringToKF(const std::string& text, uint8_t* out, int maxLen = 23) 
{
    int pos = 0;
    for (size_t i = 0; i < text.size() && pos < maxLen; ) {
        // UTF-8: русские символы = 2 байта
        std::string ch;
        if ((text[i] & 0x80) == 0) {
            ch = std::string(1, text[i]);
            i++;
        }
        else {
            ch = text.substr(i, 2);
            i += 2;
        }

        auto it = charMap.find(ch);
        if (it != charMap.end()) {
            out[pos++] = it->second;
        }
        else if (ch == " ") {
            out[pos++] = 0xFE; 
        }
    }
    out[pos] = 0xFF; // терминатор
    return pos;
}

void ShowCustomMessage(uint8_t* rdram, const std::string& text, float duration, int x, int y)
{
    memset(g_customMsg.chars, 0xFF, 24);
    StringToKF(text, g_customMsg.chars);
    g_customMsg.posX = x;
    g_customMsg.posY = y;
    g_customMsg.duration = duration;
    g_customMsg.timer = duration;
    g_customMsg.alpha = 0;
    g_customMsg.state = 1;
    g_customMsg.active = true;
}


void UpdateCustomMessageState()
{
    if (!g_customMsg.active) return;

    switch (g_customMsg.state) {
    case 1: // fade in
        g_customMsg.alpha += 20;
        if (g_customMsg.alpha >= 100) {
            g_customMsg.alpha = 100;
            g_customMsg.state = 2;
        }
        break;
    case 2: // on
        g_customMsg.timer -= 1.0f / 24.0f; // 24fps
        if (g_customMsg.timer <= 0) {
            g_customMsg.state = 3;
        }
        break;
    case 3: // fade out
        g_customMsg.alpha -= 20;
        if (g_customMsg.alpha <= 0) {
            g_customMsg.alpha = 0;
            g_customMsg.state = 0;
            g_customMsg.active = false;
            return;
        }
        break;
    }
}






void FillRectWithChar(uint8_t* rdram, int rectIdx, uint8_t kfChar, int screenX, int screenY)
{
    uint32_t addr = ADDR_MSG_RECT_ARRAY + rectIdx * MSG_RECT_SIZE;

    uint8_t u = (kfChar & 0x0F) * 8;     // столбец в атласе
    uint8_t v = ((kfChar >> 4) & 0x07) * 15; // строка в атласе

    MEM_B(0x00, addr) = 1;          // Enabled
    MEM_B(0x01, addr) = u;          // TX
    MEM_B(0x02, addr) = v;          // TY
    MEM_B(0x03, addr) = 8;          // TW (ширина символа)
    MEM_B(0x04, addr) = 15;         // TH (высота символа)
    MEM_B(0x05, addr) = 0;          // Unknown
    MEM_H(0x06, addr) = (int16_t)screenX;  // X
    MEM_H(0x08, addr) = (int16_t)screenY;  // Y
    MEM_H(0x0A, addr) = 8;          // W
    MEM_H(0x0C, addr) = 15;         // H
    MEM_H(0x0E, addr) = 0x7F64;       // CLUT
    MEM_H(0x10, addr) = 0x001D;      // TPage
}

