#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include <AL/al.h>
#include <string>
#include <thread>
#include <unordered_map>

#include "scr/funcs.h" // <---рекомпилированые функции. recomp.h включён в нём
#include "kf_cd.h"
#include "kf/recomp.h"
extern "C" 
{
#include "PsyX/PsyX_public.h"
#include "gpu/PsyX_GPU.h"
#include "pad/PsyX_pad.h"

#include "psx/libcd.h"
#include "psx/libspu.h"

#include "psx/libetc.h"
#include "PsyX/PsyX_render.h"

#include "audio/PsyX_SPUAL.h"



    // Возможно понадобятся и другие заголовки из include/psx
}

#include <SDL2/SDL.h>
#pragma pack(push, 1) // Гарантируем отсутствие паддинга (выравнивания)
struct PSXHeader {
    char id[8];             // "PS-X EXE"
    uint32_t text_off;      // Не используется (обычно 0)
    uint32_t data_off;      // Не используется (обычно 0)
    uint32_t pc0;           // Начальный PC (Program Counter)
    uint32_t gp0;           // Начальный GP (Global Pointer)
    uint32_t t_addr;        // Адрес загрузки в RAM (обычно 0x80010000 или выше)
    uint32_t t_size;        // Размер кода (в байтах)
    uint32_t d_addr;        // Обычно 0
    uint32_t d_size;        // Обычно 0
    uint32_t b_addr;        // Адрес начала BSS (секции, которую надо занулить)
    uint32_t b_size;        // Размер BSS
    uint32_t s_addr;        // Начальный SP (Stack Pointer) Base
    uint32_t s_size;        // Смещение стека (SP Offset)
    uint32_t SavedSP;       // (Обычно мусор или ASCII маркер Sony)
    uint32_t SavedFP;
    uint32_t SavedGP;
    uint32_t SavedRA;
    uint32_t SavedS0;
    char ascii_marker[2048 - 0x4C]; // Остаток заголовка (обычно текст "Sony Computer...")
};
#pragma pack(pop)


bool LoadGameEXE(const char* filename, recomp_context* ctx);
/////////


std::unordered_map<uint32_t, uint32_t> g_stream_file_sizes;;
bool g_pendingType10 = false;
uint8_t rdram[2 * 1024 * 1024] = { 0 };   // 2 MB Основной RAM
//gamepad
uint8_t g_pad1_buf[34]; 
uint8_t g_pad2_buf[34];

int main(int argc, char* argv[] )
{

    char appName[] = "King's Field II";
    recomp_context ctx = { 0 };
    g_ctx = &ctx;
    if (!LoadGameEXE("GAME.EXE", &ctx))
    {

        system("PAUSE");
        return 1;
    }

    init_function_table();

    // Стек (растет вниз от конца памяти)
    ctx.r29 = 0x801F0000; 

    // Глобальный указатель 0x800762C0
    ctx.r28 = 0x800762C0;
    // Начальное состояние GPU: Готов, бит 31 установлен
    *(uint32_t*)GET_PTR(0x1F801814) = 0x9C000000;


    PsyX_Initialise(appName, 640, 480, 0);
    

    PsyX_SetMemoryPointer(rdram);

    WRITE_W(0x1F801814, 0x1C000000);

    PsyX_UpdateInput();

    memset(g_pad1_buf, 0xFF, sizeof(g_pad1_buf));
    memset(g_pad2_buf, 0xFF, sizeof(g_pad2_buf));
    g_pad1_buf[0] = 0x00;
    g_pad1_buf[1] = 0x41; // тип контроллера

    PsyX_Pad_InitPad(1, g_pad1_buf);
    PsyX_Pad_InitPad(0, g_pad2_buf);

    ResetGraph(0);
   

    SpuInit();

    KFCD_Init("King's Field2.bin");

    //InitGeom();
    

   PsyX_BeginScene();

    //старт игры!
    start(rdram, &ctx);

   

    PsyX_Shutdown();
    return 0;
}





bool LoadGameEXE(const char* filename, recomp_context* ctx)
{

    memset(rdram, 0, 2 * 1024 * 1024);

    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("[ERROR] Failed to open %s\n", filename);
        return false;
    }

    PSXHeader header;

    fread(&header, 1, sizeof(header), f);

    if (strncmp(header.id, "PS-X EXE", 8) != 0) {
        printf("[ERROR] Not a valid PS-X EXE! Header: %.8s\n", header.id);
        fclose(f);
        return false;
    }

    printf("[LOADER] EXE Info:\n");
    printf("  PC: 0x%08X\n", header.pc0);
    printf("  GP: 0x%08X\n", header.gp0);
    printf("  Load Addr: 0x%08X\n", header.t_addr);
    printf("  Text Size: %d bytes\n", header.t_size);
    printf("  BSS Clear: 0x%08X (Size: %d)\n", header.b_addr, header.b_size);
    printf("  Stack: Base 0x%08X + Offset 0x%08X\n", header.s_addr, header.s_size);

    // Инициализация контекста CPU
    ctx->pc = header.pc0;
    ctx->r28 = header.gp0;

    // Инициализация стека из заголовка (если там не нули)
    if (header.s_addr != 0) {
        ctx->r30 = header.s_addr; // FP (Frame Pointer)
        ctx->r29 = header.s_addr + header.s_size; // SP (Stack Pointer)
        printf("  -> SP initialized to 0x%08X from Header\n", ctx->r29);
    }
    else {
        ctx->r29 = 0x801FFFF0; // Дефолтный стек
        printf("  -> SP initialized to Default (0x801FFFF0)\n");
    }

    // 3. Загрузка КОДА игры (Text Segment)
    uint32_t ram_offset = header.t_addr & 0x1FFFFF;

    // Пропускаем 2048 байт заголовка EXE
    fseek(f, 2048, SEEK_SET);
    fread(&rdram[ram_offset], 1, header.t_size, f);
    fclose(f);

    if (header.b_size > 0) {
        uint32_t bss_offset = header.b_addr & 0x1FFFFF;
        // Проверка на выход за границы RAM
        if (bss_offset + header.b_size <= 2 * 1024 * 1024) {
            memset(&rdram[bss_offset], 0, header.b_size);
            printf("[LOADER] BSS Cleared: 0x%08X - 0x%08X\n",
                header.b_addr, header.b_addr + header.b_size);
        }
        else {
            printf("[LOADER] WARNING: BSS region out of RAM bounds!\n");
        }
    }

    printf("[LOADER] Game loaded successfully.\n");
    return true;
}