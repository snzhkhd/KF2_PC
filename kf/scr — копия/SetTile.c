#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetTile(uint8_t* rdram, recomp_context* ctx) {
    SetTile((TILE*)GET_PTR(ctx->r4));
    ;
}
