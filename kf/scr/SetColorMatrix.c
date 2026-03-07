#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetColorMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint32_t vram_addr = ctx->r4;

    if (vram_addr == 0) return;


    MATRIX* m = (MATRIX*)GET_PTR(vram_addr);
    ctx_to_gte(ctx);
    SetColorMatrix(m);
    gte_to_ctx(ctx);
    ;
}
