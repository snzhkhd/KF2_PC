#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetPolyG3(uint8_t* rdram, recomp_context* ctx)
{
    setPolyG3((POLY_G3*)GET_PTR(ctx->r4));
    ;
}
