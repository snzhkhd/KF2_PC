#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetLineF2(uint8_t* rdram, recomp_context* ctx) {
    setLineF2((LINE_F2*)GET_PTR(ctx->r4));
    ;
}
