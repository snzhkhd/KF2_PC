#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_GetTPage(uint8_t* rdram, recomp_context* ctx) {

    int tp = (int)ctx->r4; // Texture Page color mode (0:4-bit, 1:8-bit, 2:15-bit)
    int abr = (int)ctx->r5; // Semi-transparency mode (0, 1, 2, 3)
    int x = (int)ctx->r6; // X-coordinate in VRAM (0-1023)
    int y = (int)ctx->r7; // Y-coordinate in VRAM (0-511)

    // 2. Вызываем Psy-X. 
    // Это чистая математика (упаковка бит), она вернет u_short.
    u_short result = GetTPage(tp, abr, x, y);

    // 3. Записываем результат в r2 (v0).
    ctx->r2 = (uint32_t)result;
    ;
}
