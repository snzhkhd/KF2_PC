#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetSprt16(uint8_t* rdram, recomp_context* ctx) {
    SetSprt16((SPRT_16*)GET_PTR(ctx->r4));
    ;
}
