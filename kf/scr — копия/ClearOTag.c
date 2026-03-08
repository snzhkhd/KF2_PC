#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

// sub_80064560 KF_ClearOTag
void KF_ClearOTag(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t ot_addr = ctx->r4;
    int n = (int)ctx->r5;
    uint32_t* ot = (uint32_t*)GET_PTR(ot_addr);
    if (ot && n > 0) {
        ot[0] = 0x00FFFFFF;
        for (int i = 1; i < n; i++)
            ot[i] = (ot_addr + (i - 1) * 4) & 0x00FFFFFF;
    }
    /*u_long* ot = (u_long*)GET_PTR(ctx->r4);
    int n = (int)ctx->r5;
    ClearOTag(ot, n);*/
    ctx->r2 = 0;
}