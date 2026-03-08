#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetGeomScreen(uint8_t* rdram, recomp_context* ctx) {

    ctx_to_gte(ctx);
    SetGeomScreen((int)ctx->r4);
    gte_to_ctx(ctx);
    ctx->r2 = 0;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// ctc2        $a0, $26
    //gte_ctc2(ctx, 4, 26);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
