#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_GetClut(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint32_t)GetClut((int)ctx->r4, (int)ctx->r5);
    ;
}
