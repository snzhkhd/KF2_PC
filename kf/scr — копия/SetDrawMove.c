#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetDrawMode(uint8_t* rdram, recomp_context* ctx)
{
    // a0, a1, a2, a3 - стандартно
    DR_MODE* p = (DR_MODE*)GET_PTR(ctx->r4);
    int dfe = (int)ctx->r5;   // Draw on Display Area (разрешить рисовать там, где экран)
    int dtd = (int)ctx->r6;   // Dither (сглаживание переходов цвета)
    int tpage = (int)ctx->r7;   // Номер текстурной страницы

    // Пятый аргумент (RECT16 *tw - Texture Window) берем со стека
    // На MIPS аргументы со стека начинаются с отступа 16 байт от текущего SP
    uint32_t tw_addr = MEM_W(16, ctx->r29);
    RECT16* tw = (RECT16*)GET_PTR(tw_addr);

    if (p) {
        SetDrawMode(p, dfe, dtd, tpage, tw);
    }
}