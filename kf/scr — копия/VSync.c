#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "psx/libetc.h"



void KF_VSync(uint8_t* rdram, recomp_context* ctx) {
    // Не делаем swap здесь — только запоминаем что он нужен
    //printf("[DEBUG] Game called KF_VSync!\n");
    int mode = (int32_t)ctx->r4;
    ctx->r2 = VSync(mode == 0 ? 1 : mode);

    g_vsync_pending = true;
//    PsyX_UpdateInput();
    ctx->r2 = 0;
    WRITE_W(0x1F801814, 0x1C000000);
}
