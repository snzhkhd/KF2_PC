#include "recomp.h"
#include "disable_warnings.h"

void sub_8004BC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, 0x79D8
    ctx->r2 = ADD32(ctx->r2, 0X79D8);
    // lwl         $v1, 0x3($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r7);
    // lwr         $v1, 0x0($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r7);
    // lb          $a0, 0x4($a3)
    ctx->r4 = MEM_B(0X4, ctx->r7);
    // swl         $v1, 0x3($v0)
    do_swl(rdram, 0X3, ctx->r2, ctx->r3);
    // swr         $v1, 0x0($v0)
    do_swr(rdram, 0X0, ctx->r2, ctx->r3);
    // sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D9($at)
    MEM_B(0X79D9, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DA($at)
    MEM_B(0X79DA, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DB($at)
    MEM_B(0X79DB, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DC($at)
    MEM_B(0X79DC, ctx->r1) = ctx->r2;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A64
    ctx->r5 = ADD32(ctx->r5, -0X4A64);
    // lw          $v0, 0x39D4($a3)
    ctx->r2 = MEM_W(0X39D4, ctx->r7);
    // lw          $v1, 0x39D8($a3)
    ctx->r3 = MEM_W(0X39D8, ctx->r7);
    // lw          $a0, 0x39DC($a3)
    ctx->r4 = MEM_W(0X39DC, ctx->r7);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // lw          $v0, 0x39E0($a3)
    ctx->r2 = MEM_W(0X39E0, ctx->r7);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A44
    ctx->r5 = ADD32(ctx->r5, -0X4A44);
    // lwl         $v0, 0x39E7($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X39E7, ctx->r7);
    // lwr         $v0, 0x39E4($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X39E4, ctx->r7);
    // lwl         $v1, 0x39EB($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X39EB, ctx->r7);
    // lwr         $v1, 0x39E8($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X39E8, ctx->r7);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
    // lw          $v0, 0x39EC($a3)
    ctx->r2 = MEM_W(0X39EC, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4B3C($at)
    MEM_W(-0X4B3C, ctx->r1) = ctx->r2;
    // lw          $v0, 0x39F0($a3)
    ctx->r2 = MEM_W(0X39F0, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4B38($at)
    MEM_W(-0X4B38, ctx->r1) = ctx->r2;
    // lw          $v0, 0x39F4($a3)
    ctx->r2 = MEM_W(0X39F4, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4B10($at)
    MEM_W(-0X4B10, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x39F8($a3)
    ctx->r2 = MEM_HU(0X39F8, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A14($at)
    MEM_H(-0X4A14, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x39FA($a3)
    ctx->r2 = MEM_HU(0X39FA, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2A($at)
    MEM_H(-0X4B2A, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x39FC($a3)
    ctx->r2 = MEM_HU(0X39FC, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B28($at)
    MEM_H(-0X4B28, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x39FE($a3)
    ctx->r2 = MEM_HU(0X39FE, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B26($at)
    MEM_H(-0X4B26, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A00($a3)
    ctx->r2 = MEM_HU(0X3A00, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A02($a3)
    ctx->r2 = MEM_HU(0X3A02, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B18($at)
    MEM_H(-0X4B18, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A04($a3)
    ctx->r2 = MEM_HU(0X3A04, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B16($at)
    MEM_H(-0X4B16, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A06($a3)
    ctx->r2 = MEM_HU(0X3A06, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B1C($at)
    MEM_H(-0X4B1C, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A08($a3)
    ctx->r2 = MEM_HU(0X3A08, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B1A($at)
    MEM_H(-0X4B1A, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A0A($a3)
    ctx->r2 = MEM_HU(0X3A0A, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A0C($a3)
    ctx->r2 = MEM_HU(0X3A0C, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE6($at)
    MEM_H(-0X4AE6, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A0E($a3)
    ctx->r2 = MEM_HU(0X3A0E, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE4($at)
    MEM_H(-0X4AE4, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A10($a3)
    ctx->r2 = MEM_HU(0X3A10, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE2($at)
    MEM_H(-0X4AE2, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A12($a3)
    ctx->r2 = MEM_HU(0X3A12, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE0($at)
    MEM_H(-0X4AE0, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A14($a3)
    ctx->r2 = MEM_HU(0X3A14, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADE($at)
    MEM_H(-0X4ADE, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A16($a3)
    ctx->r2 = MEM_HU(0X3A16, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADC($at)
    MEM_H(-0X4ADC, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A18($a3)
    ctx->r2 = MEM_HU(0X3A18, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADA($at)
    MEM_H(-0X4ADA, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A1A($a3)
    ctx->r2 = MEM_HU(0X3A1A, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD8($at)
    MEM_H(-0X4AD8, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A1C($a3)
    ctx->r2 = MEM_HU(0X3A1C, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD6($at)
    MEM_H(-0X4AD6, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A1E($a3)
    ctx->r2 = MEM_HU(0X3A1E, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD4($at)
    MEM_H(-0X4AD4, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A20($a3)
    ctx->r2 = MEM_HU(0X3A20, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD2($at)
    MEM_H(-0X4AD2, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A22($a3)
    ctx->r2 = MEM_HU(0X3A22, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD0($at)
    MEM_H(-0X4AD0, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A24($a3)
    ctx->r2 = MEM_HU(0X3A24, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ACE($at)
    MEM_H(-0X4ACE, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A2E($a3)
    ctx->r2 = MEM_BU(0X3A2E, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B34($at)
    MEM_B(-0X4B34, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A2F($a3)
    ctx->r2 = MEM_BU(0X3A2F, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B33($at)
    MEM_B(-0X4B33, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A30($a3)
    ctx->r2 = MEM_BU(0X3A30, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A7C($at)
    MEM_B(-0X4A7C, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A31($a3)
    ctx->r2 = MEM_BU(0X3A31, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A7B($at)
    MEM_B(-0X4A7B, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A32($a3)
    ctx->r2 = MEM_BU(0X3A32, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A7A($at)
    MEM_B(-0X4A7A, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A33($a3)
    ctx->r2 = MEM_BU(0X3A33, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A79($at)
    MEM_B(-0X4A79, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A34($a3)
    ctx->r2 = MEM_BU(0X3A34, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A78($at)
    MEM_B(-0X4A78, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A35($a3)
    ctx->r2 = MEM_BU(0X3A35, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A77($at)
    MEM_B(-0X4A77, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A36($a3)
    ctx->r2 = MEM_BU(0X3A36, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A76($at)
    MEM_B(-0X4A76, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A37($a3)
    ctx->r2 = MEM_BU(0X3A37, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA5($at)
    MEM_B(-0X4AA5, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A38($a3)
    ctx->r2 = MEM_BU(0X3A38, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA4($at)
    MEM_B(-0X4AA4, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A39($a3)
    ctx->r2 = MEM_BU(0X3A39, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA3($at)
    MEM_B(-0X4AA3, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A3A($a3)
    ctx->r2 = MEM_BU(0X3A3A, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA1($at)
    MEM_B(-0X4AA1, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A3B($a3)
    ctx->r2 = MEM_BU(0X3A3B, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A75($at)
    MEM_B(-0X4A75, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A3C($a3)
    ctx->r2 = MEM_BU(0X3A3C, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A74($at)
    MEM_B(-0X4A74, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A3D($a3)
    ctx->r2 = MEM_BU(0X3A3D, ctx->r7);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A73($at)
    MEM_B(-0X4A73, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A3E($a3)
    ctx->r2 = MEM_BU(0X3A3E, ctx->r7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A72($at)
    MEM_B(-0X4A72, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A3F($a3)
    ctx->r2 = MEM_BU(0X3A3F, ctx->r7);
    // addiu       $a1, $a3, 0x3992
    ctx->r5 = ADD32(ctx->r7, 0X3992);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A71($at)
    MEM_B(-0X4A71, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x3A40($a3)
    ctx->r2 = MEM_BU(0X3A40, ctx->r7);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1900
    ctx->r4 = ADD32(ctx->r4, -0X1900);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A70($at)
    MEM_B(-0X4A70, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x3A42($a3)
    ctx->r2 = MEM_HU(0X3A42, ctx->r7);
    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A66($at)
    MEM_H(-0X4A66, ctx->r1) = ctx->r2;
L_8004BFE0:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $a2, L_8004BFE0
    if (ctx->r3 != ctx->r6) {
        // addiu       $a0, $a0, 0x1A
        ctx->r4 = ADD32(ctx->r4, 0X1A);
        goto L_8004BFE0;
    }
    // addiu       $a0, $a0, 0x1A
    ctx->r4 = ADD32(ctx->r4, 0X1A);
    // lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // addiu       $t0, $t0, -0x2190
    ctx->r8 = ADD32(ctx->r8, -0X2190);
    // addiu       $a2, $a3, 0x391A
    ctx->r6 = ADD32(ctx->r7, 0X391A);
    // or          $v0, $a2, $t0
    ctx->r2 = ctx->r6 | ctx->r8;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_8004C068
    if (ctx->r2 == 0) {
        // addiu       $t1, $a3, 0x398A
        ctx->r9 = ADD32(ctx->r7, 0X398A);
        goto L_8004C068;
    }
    // addiu       $t1, $a3, 0x398A
    ctx->r9 = ADD32(ctx->r7, 0X398A);
L_8004C014:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
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
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t1, L_8004C014
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004C014;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // j           L_8004C094
    // nop

    goto L_8004C094;
    // nop

L_8004C068:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t1, L_8004C068
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004C068;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8004C094:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // swl         $v0, 0x3($t0)
    do_swl(rdram, 0X3, ctx->r8, ctx->r2);
    // swr         $v0, 0x0($t0)
    do_swr(rdram, 0X0, ctx->r8, ctx->r2);
    // swl         $v1, 0x7($t0)
    do_swl(rdram, 0X7, ctx->r8, ctx->r3);
    // swr         $v1, 0x4($t0)
    do_swr(rdram, 0X4, ctx->r8, ctx->r3);
    // lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // addiu       $t0, $t0, 0x519C
    ctx->r8 = ADD32(ctx->r8, 0X519C);
    // addiu       $a2, $a3, 0x5
    ctx->r6 = ADD32(ctx->r7, 0X5);
    // or          $v0, $a2, $t0
    ctx->r2 = ctx->r6 | ctx->r8;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_8004C124
    if (ctx->r2 == 0) {
        // addiu       $t1, $a3, 0x105
        ctx->r9 = ADD32(ctx->r7, 0X105);
        goto L_8004C124;
    }
    // addiu       $t1, $a3, 0x105
    ctx->r9 = ADD32(ctx->r7, 0X105);
L_8004C0D0:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
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
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t1, L_8004C0D0
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004C0D0;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // j           L_8004C150
    // nop

    goto L_8004C150;
    // nop

L_8004C124:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t1, L_8004C124
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004C124;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8004C150:
    // lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // addiu       $t0, $t0, 0x529C
    ctx->r8 = ADD32(ctx->r8, 0X529C);
    // addiu       $a2, $a3, 0x105
    ctx->r6 = ADD32(ctx->r7, 0X105);
    // or          $v0, $a2, $t0
    ctx->r2 = ctx->r6 | ctx->r8;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_8004C1C0
    if (ctx->r2 == 0) {
        // addiu       $t1, $a3, 0x3905
        ctx->r9 = ADD32(ctx->r7, 0X3905);
        goto L_8004C1C0;
    }
    // addiu       $t1, $a3, 0x3905
    ctx->r9 = ADD32(ctx->r7, 0X3905);
L_8004C16C:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
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
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t1, L_8004C16C
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004C16C;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // j           L_8004C1EC
    // nop

    goto L_8004C1EC;
    // nop

L_8004C1C0:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t1, L_8004C1C0
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8004C1C0;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8004C1EC:
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // addiu       $a1, $a1, -0x7564
    ctx->r5 = ADD32(ctx->r5, -0X7564);
    // lwl         $v0, 0x3909($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3909, ctx->r7);
    // lwr         $v0, 0x3906($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X3906, ctx->r7);
    // lwl         $v1, 0x390D($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X390D, ctx->r7);
    // lwr         $v1, 0x390A($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X390A, ctx->r7);
    // lwl         $a0, 0x3911($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X3911, ctx->r7);
    // lwr         $a0, 0x390E($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X390E, ctx->r7);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
    // swl         $a0, 0xB($a1)
    do_swl(rdram, 0XB, ctx->r5, ctx->r4);
    // swr         $a0, 0x8($a1)
    do_swr(rdram, 0X8, ctx->r5, ctx->r4);
    // lwl         $v0, 0x3915($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3915, ctx->r7);
    // lwr         $v0, 0x3912($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X3912, ctx->r7);
    // lwl         $v1, 0x3919($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3919, ctx->r7);
    // lwr         $v1, 0x3916($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X3916, ctx->r7);
    // swl         $v0, 0xF($a1)
    do_swl(rdram, 0XF, ctx->r5, ctx->r2);
    // swr         $v0, 0xC($a1)
    do_swr(rdram, 0XC, ctx->r5, ctx->r2);
    // swl         $v1, 0x13($a1)
    do_swl(rdram, 0X13, ctx->r5, ctx->r3);
    // swr         $v1, 0x10($a1)
    do_swr(rdram, 0X10, ctx->r5, ctx->r3);
    // jr          $ra
    // nop

    return;
    // nop

;}
