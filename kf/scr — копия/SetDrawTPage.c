#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetDrawTPage(uint8_t* rdram, recomp_context* ctx)
{
    DR_TPAGE* p = (DR_TPAGE*)GET_PTR(ctx->r4);
    int dfe = (int)ctx->r5;
    int dtd = (int)ctx->r6;
    int tpage = (int)ctx->r7;

    if (p) {
        SetDrawTPage(p, dfe, dtd, tpage);
    }
}