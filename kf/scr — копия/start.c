#include "recomp.h"
#include "disable_warnings.h"

void start(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
L_80013A5C:
    // lui         $gp, 0x8007
    ctx->r28 = S32(0X8007 << 16);
    // addiu       $gp, $gp, 0x62C0
    ctx->r28 = ADD32(ctx->r28, 0X62C0);
    // j           L_80013A5C
    // nop

    sub_80013A5C(rdram, ctx);
    return;
    // nop

;}
