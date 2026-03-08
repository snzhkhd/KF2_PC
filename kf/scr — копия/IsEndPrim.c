#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_IsEndPrim(uint8_t* rdram, recomp_context* ctx) {

    uint32_t ps1_addr = ctx->r4;
    void* p = GET_PTR(ps1_addr);
    int result = isendprim(p);
    ctx->r2 = (uint32_t)result;
    ;
}
