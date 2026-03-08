#include "recomp.h"
#include "disable_warnings.h"

void PrepareRenderPrimitives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, -0x1B1C
    ctx->r9 = ADD32(ctx->r9, -0X1B1C);
    // lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // addiu       $t0, $t0, 0x51A4
    ctx->r8 = ADD32(ctx->r8, 0X51A4);
    // ori         $t2, $zero, 0x4F
    ctx->r10 = 0 | 0X4F;
    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // addiu       $a3, $t0, 0x66
    ctx->r7 = ADD32(ctx->r8, 0X66);
    // addiu       $a2, $t1, 0x2A
    ctx->r6 = ADD32(ctx->r9, 0X2A);
L_8002E75C:
    // lwl         $v0, -0x13($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, -0X13, ctx->r6);
    // lwr         $v0, -0x16($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, -0X16, ctx->r6);
    // lwl         $v1, -0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, -0XF, ctx->r6);
    // lwr         $v1, -0x12($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, -0X12, ctx->r6);
    // lwl         $a0, -0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, -0XB, ctx->r6);
    // lwr         $a0, -0xE($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, -0XE, ctx->r6);
    // lwl         $a1, -0x7($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, -0X7, ctx->r6);
    // lwr         $a1, -0xA($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, -0XA, ctx->r6);
    // swl         $v0, -0x13($a3)
    do_swl(rdram, -0X13, ctx->r7, ctx->r2);
    // swr         $v0, -0x16($a3)
    do_swr(rdram, -0X16, ctx->r7, ctx->r2);
    // swl         $v1, -0xF($a3)
    do_swl(rdram, -0XF, ctx->r7, ctx->r3);
    // swr         $v1, -0x12($a3)
    do_swr(rdram, -0X12, ctx->r7, ctx->r3);
    // swl         $a0, -0xB($a3)
    do_swl(rdram, -0XB, ctx->r7, ctx->r4);
    // swr         $a0, -0xE($a3)
    do_swr(rdram, -0XE, ctx->r7, ctx->r4);
    // swl         $a1, -0x7($a3)
    do_swl(rdram, -0X7, ctx->r7, ctx->r5);
    // swr         $a1, -0xA($a3)
    do_swr(rdram, -0XA, ctx->r7, ctx->r5);
    // lh          $v0, -0x6($a2)
    ctx->r2 = MEM_H(-0X6, ctx->r6);
    // nop

    // sh          $v0, -0x6($a3)
    MEM_H(-0X6, ctx->r7) = ctx->r2;
    // lwl         $v0, 0x3($t1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r9);
    // lwr         $v0, 0x0($t1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r9);
    // lwl         $v1, 0x7($t1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r9);
    // lwr         $v1, 0x4($t1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r9);
    // lwl         $a0, 0xB($t1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r9);
    // lwr         $a0, 0x8($t1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r9);
    // lwl         $a1, 0xF($t1)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r9);
    // lwr         $a1, 0xC($t1)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r9);
    // swl         $v0, 0x3($t0)
    do_swl(rdram, 0X3, ctx->r8, ctx->r2);
    // swr         $v0, 0x0($t0)
    do_swr(rdram, 0X0, ctx->r8, ctx->r2);
    // swl         $v1, 0x7($t0)
    do_swl(rdram, 0X7, ctx->r8, ctx->r3);
    // swr         $v1, 0x4($t0)
    do_swr(rdram, 0X4, ctx->r8, ctx->r3);
    // swl         $a0, 0xB($t0)
    do_swl(rdram, 0XB, ctx->r8, ctx->r4);
    // swr         $a0, 0x8($t0)
    do_swr(rdram, 0X8, ctx->r8, ctx->r4);
    // swl         $a1, 0xF($t0)
    do_swl(rdram, 0XF, ctx->r8, ctx->r5);
    // swr         $a1, 0xC($t0)
    do_swr(rdram, 0XC, ctx->r8, ctx->r5);
    // lwl         $v0, 0x13($t1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r9);
    // lwr         $v0, 0x10($t1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r9);
    // nop

    // swl         $v0, 0x13($t0)
    do_swl(rdram, 0X13, ctx->r8, ctx->r2);
    // swr         $v0, 0x10($t0)
    do_swr(rdram, 0X10, ctx->r8, ctx->r2);
    // lwl         $v0, -0x1($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, -0X1, ctx->r6);
    // lwr         $v0, -0x4($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, -0X4, ctx->r6);
    // nop

    // swl         $v0, -0x1($a3)
    do_swl(rdram, -0X1, ctx->r7, ctx->r2);
    // swr         $v0, -0x4($a3)
    do_swr(rdram, -0X4, ctx->r7, ctx->r2);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x2C
    ctx->r6 = ADD32(ctx->r6, 0X2C);
    // addiu       $t1, $t1, 0x2C
    ctx->r9 = ADD32(ctx->r9, 0X2C);
    // addiu       $t0, $t0, 0x68
    ctx->r8 = ADD32(ctx->r8, 0X68);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // bne         $t2, $t3, L_8002E75C
    if (ctx->r10 != ctx->r11) {
        // addiu       $a3, $a3, 0x68
        ctx->r7 = ADD32(ctx->r7, 0X68);
        goto L_8002E75C;
    }
    // addiu       $a3, $a3, 0x68
    ctx->r7 = ADD32(ctx->r7, 0X68);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $zero, 0x51A0($at)
    MEM_W(0X51A0, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x4DFD($at)
    MEM_B(0X4DFD, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $zero, 0x4E02($at)
    MEM_H(0X4E02, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $zero, 0x4E00($at)
    MEM_H(0X4E00, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $zero, 0x4DFE($at)
    MEM_H(0X4DFE, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x4DF9($at)
    MEM_B(0X4DF9, ctx->r1) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
