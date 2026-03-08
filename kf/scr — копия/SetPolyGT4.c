#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetPolyGT4(uint8_t* rdram, recomp_context* ctx) {

    SetPolyGT4((POLY_GT4*)GET_PTR(ctx->r4));
    ;
}
