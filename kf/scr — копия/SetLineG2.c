#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetLineG2(uint8_t* rdram, recomp_context* ctx) {
    setLineG2((LINE_G2*)GET_PTR(ctx->r4));
    ;
}
