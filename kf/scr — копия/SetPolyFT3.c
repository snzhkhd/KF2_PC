#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetPolyFT3(uint8_t* rdram, recomp_context* ctx) {
    setPolyFT3((POLY_FT3*)GET_PTR(ctx->r4));
    ;
}
