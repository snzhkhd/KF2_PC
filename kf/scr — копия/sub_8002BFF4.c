#include "recomp.h"
#include "disable_warnings.h"

void sub_8002BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = ctx->r2;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x49EC
    ctx->r8 = ADD32(ctx->r8, -0X49EC);
    // lwl         $v0, 0x3($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r4);
    // lwr         $v0, 0x0($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r4);
    // lwl         $v1, 0x7($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r4);
    // lwr         $v1, 0x4($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r4);
    // swl         $v0, 0x3($t0)
    do_swl(rdram, 0X3, ctx->r8, ctx->r2);
    // swr         $v0, 0x0($t0)
    do_swr(rdram, 0X0, ctx->r8, ctx->r2);
    // swl         $v1, 0x7($t0)
    do_swl(rdram, 0X7, ctx->r8, ctx->r3);
    // swr         $v1, 0x4($t0)
    do_swr(rdram, 0X4, ctx->r8, ctx->r3);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x49E4
    ctx->r7 = ADD32(ctx->r7, -0X49E4);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lwl         $v1, 0x7($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r5);
    // lwr         $v1, 0x4($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r5);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // ori         $v0, $zero, 0xDAC
    ctx->r2 = 0 | 0XDAC;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A00($at)
    MEM_H(-0X4A00, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a2, -0x49FE($at)
    MEM_H(-0X49FE, ctx->r1) = ctx->r6;
    // jr          $ra
    // nop

    return;
    // nop

;}
