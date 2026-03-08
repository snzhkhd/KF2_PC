#include "recomp.h"
#include "disable_warnings.h"

void sub_8002BED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x49EC($at)
    MEM_B(-0X49EC, ctx->r1) = ctx->r4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x49EB($at)
    MEM_B(-0X49EB, ctx->r1) = 0;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A44
    ctx->r5 = ADD32(ctx->r5, -0X4A44);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x49EA
    ctx->r4 = ADD32(ctx->r4, -0X49EA);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lwl         $v1, 0x7($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r5);
    // lwr         $v1, 0x4($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r5);
    // swl         $v0, 0x3($a0)
    do_swl(rdram, 0X3, ctx->r4, ctx->r2);
    // swr         $v0, 0x0($a0)
    do_swr(rdram, 0X0, ctx->r4, ctx->r2);
    // swl         $v1, 0x7($a0)
    do_swl(rdram, 0X7, ctx->r4, ctx->r3);
    // swr         $v1, 0x4($a0)
    do_swr(rdram, 0X4, ctx->r4, ctx->r3);
    // jr          $ra
    // nop

    return;
    // nop

;}
