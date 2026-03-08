#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetLineG4(uint8_t* rdram, recomp_context* ctx) {
    setLineG4((LINE_G4*)GET_PTR(ctx->r4));
    ;
}
