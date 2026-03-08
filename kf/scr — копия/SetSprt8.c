#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetSprt8(uint8_t* rdram, recomp_context* ctx) {
    SetSprt8((SPRT_8*)GET_PTR(ctx->r4));
    ;
}
