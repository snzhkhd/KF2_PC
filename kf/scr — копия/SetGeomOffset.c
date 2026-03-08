#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetGeomOffset(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[SetGeomOffset] x=%d y=%d\n", (int32_t)ctx->r4, (int32_t)ctx->r5);
    ctx_to_gte(ctx);
    SetGeomOffset((int)ctx->r4, (int)ctx->r5);
    gte_to_ctx(ctx);
    ctx->r2 = 0;

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// sll         $a0, $a0, 16
    //ctx->r4 = S32(ctx->r4) << 16;
    //// sll         $a1, $a1, 16
    //ctx->r5 = S32(ctx->r5) << 16;
    //// ctc2        $a0, $24
    //gte_ctc2(ctx, 4, 24);
    //// ctc2        $a1, $25
    //gte_ctc2(ctx, 5, 25);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
