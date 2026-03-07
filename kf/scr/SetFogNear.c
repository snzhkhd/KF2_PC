#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"


void KF_SetFogNear(uint8_t* rdram, recomp_context* ctx) {
    // a0 = дистанция начала тумана, a1 = projection value (h)
    ctx_to_gte(ctx);
    SetFogNear((long)ctx->r4, (long)ctx->r5);
    gte_to_ctx(ctx);
}