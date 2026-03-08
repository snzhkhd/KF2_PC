#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetLineF4(uint8_t* rdram, recomp_context* ctx) {
    setLineF4((LINE_F4*)GET_PTR(ctx->r4));
    ;
}
