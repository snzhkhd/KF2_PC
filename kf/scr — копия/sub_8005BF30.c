#include "recomp.h"
#include "disable_warnings.h"

void sub_8005BF30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8005BF70
    if (ctx->r3 == ctx->r2) {
        // addu        $s0, $a3, $zero
        ctx->r16 = ADD32(ctx->r7, 0);
        goto L_8005BF70;
    }
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // j           L_8005C0E4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8005C0E4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005BF70:
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8005984C
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005984C(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1929($v1)
    ctx->r3 = MEM_BU(-0X1929, ctx->r3);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(0X1, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(0X2, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(0X3, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(0X4, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(0X5, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(0X7, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(0X6, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(0X8, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(0X9, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0xA($s0)
    ctx->r4 = MEM_BU(0XA, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(0XB, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(0XC, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(0XD, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // lhu         $a0, 0x10($s0)
    ctx->r4 = MEM_HU(0X10, ctx->r16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    // lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(0X16, ctx->r16);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
L_8005C0E4:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
