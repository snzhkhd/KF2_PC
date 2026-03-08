#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "psx/libetc.h"

void KF_ClearOTagR(uint8_t* rdram, recomp_context* ctx) 
{
    uint32_t ot_addr = ctx->r4;
    int n = (int)ctx->r5;
    uint32_t* ot = (uint32_t*)GET_PTR(ot_addr);
    if (ot && n > 0) {
        // Правильно — как в оригинале:
        // ClearOTag заполняет список, потом ot[0] = dword_8007625C & 0xFFFFFF
        for (int i = n - 1; i >= 1; i--)
            ot[i] = (ot_addr + (i - 1) * 4) & 0x00FFFFFF;

        // Читаем dword_8007625C как делает оригинал
        uint32_t terminator = MEM_W(0, 0x8007625C) & 0x00FFFFFF;
        ot[0] = terminator;
    }

    ctx->r2 = 0;

;}
