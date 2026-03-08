#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetPolyGT3(uint8_t* rdram, recomp_context* ctx) {
    setPolyGT3((POLY_GT3*)GET_PTR(ctx->r4));
    ;
}
