#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetShadeTex(uint8_t* rdram, recomp_context* ctx)
{

    void* p = GET_PTR(ctx->r4);

    int tge = (int)ctx->r5;
    if (p) {
        SetShadeTex(p, tge);
    }
    ;
}
