#include "recomp.h"
#include "disable_warnings.h"

void FinalizePlayerInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A08($at)
    MEM_H(-0X4A08, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A06($at)
    MEM_H(-0X4A06, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A04($at)
    MEM_H(-0X4A04, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A28($at)
    MEM_H(-0X4A28, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A2A($at)
    MEM_H(-0X4A2A, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A2C($at)
    MEM_H(-0X4A2C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A34($at)
    MEM_H(-0X4A34, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A38($at)
    MEM_H(-0X4A38, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A3A($at)
    MEM_H(-0X4A3A, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A3C($at)
    MEM_H(-0X4A3C, ctx->r1) = 0;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A44
    ctx->r5 = ADD32(ctx->r5, -0X4A44);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4A4C
    ctx->r4 = ADD32(ctx->r4, -0X4A4C);
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
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2C($at)
    MEM_H(-0X4B2C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6B($at)
    MEM_B(-0X4A6B, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x2710
    ctx->r2 = 0 | 0X2710;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4B2F($at)
    MEM_B(-0X4B2F, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A1C($at)
    MEM_W(-0X4A1C, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A18($at)
    MEM_W(-0X4A18, ctx->r1) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
