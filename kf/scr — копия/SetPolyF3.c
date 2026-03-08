#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetPolyF3(uint8_t* rdram, recomp_context* ctx) {
    setPolyF3((POLY_F3*)GET_PTR(ctx->r4));
    ;
}
