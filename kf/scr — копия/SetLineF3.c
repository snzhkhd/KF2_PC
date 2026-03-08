#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetLineF3(uint8_t* rdram, recomp_context* ctx) {
    SetLineF3((LINE_F3*)GET_PTR(ctx->r4));
    ;
}
