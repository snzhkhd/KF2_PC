#include "recomp.h"
#include "disable_warnings.h"

void sub_8002BF24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = ctx->r2;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x49EC
    ctx->r6 = ADD32(ctx->r6, -0X49EC);
    // lwl         $v0, 0x3($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r4);
    // lwr         $v0, 0x0($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r4);
    // lwl         $v1, 0x7($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r4);
    // lwr         $v1, 0x4($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r4);
    // swl         $v0, 0x3($a2)
    do_swl(rdram, 0X3, ctx->r6, ctx->r2);
    // swr         $v0, 0x0($a2)
    do_swr(rdram, 0X0, ctx->r6, ctx->r2);
    // swl         $v1, 0x7($a2)
    do_swl(rdram, 0X7, ctx->r6, ctx->r3);
    // swr         $v1, 0x4($a2)
    do_swr(rdram, 0X4, ctx->r6, ctx->r3);
    // jr          $ra
    // nop

    return;
    // nop

;}
