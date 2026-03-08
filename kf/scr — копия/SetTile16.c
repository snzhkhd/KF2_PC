#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetTile16(uint8_t* rdram, recomp_context* ctx) {
    setTile16((TILE_16*)GET_PTR(ctx->r4));
    ;
}
