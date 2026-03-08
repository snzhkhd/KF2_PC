#include "recomp.h"
#include "disable_warnings.h"

void sub_800568CC(uint8_t* rdram, recomp_context* ctx) {
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
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // jal         0x8005208C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005208C(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x1940($at)
    MEM_H(-0X1940, ctx->r1) = 0;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $zero, -0x1F34($at)
    MEM_H(-0X1F34, ctx->r1) = 0;
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, -0x7080
    ctx->r5 = ADD32(ctx->r5, -0X7080);
    // jal         0x80059744
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    KF_SpuInitMalloc(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    after_1:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x7748
    ctx->r3 = ADD32(ctx->r3, -0X7748);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80056918:
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 < 0XC0 ? 1 : 0;
    // bne         $v0, $zero, L_80056918
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_80056918;
    }
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80056940:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80056940
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_80056940;
    }
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $zero, -0x1064($at)
    MEM_H(-0X1064, ctx->r1) = 0;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80056974:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80056974
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_80056974;
    }
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // sltiu       $v0, $a0, 0x18
    ctx->r2 = ctx->r4 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_800569B8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x18
        ctx->r2 = 0 | 0X18;
        goto L_800569B8;
    }
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x49D8($at)
    MEM_B(-0X49D8, ctx->r1) = ctx->r2;
    // j           L_800569C0
    // nop

    goto L_800569C0;
    // nop

L_800569B8:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x49D8($at)
    MEM_B(-0X49D8, ctx->r1) = ctx->r4;
L_800569C0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49D8($v0)
    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80056BB8
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80056BB8;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $s1, $zero, 0xFF
    ctx->r17 = 0 | 0XFF;
    // andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
L_800569DC:
    // sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3) << 3;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // ori         $v1, $zero, 0x18
    ctx->r3 = 0 | 0X18;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75B0
    ctx->r1 = ADD32(ctx->r1, -0X75B0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r17;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AC
    ctx->r1 = ADD32(ctx->r1, -0X75AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AA
    ctx->r1 = ADD32(ctx->r1, -0X75AA);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A2
    ctx->r1 = ADD32(ctx->r1, -0X75A2);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A0
    ctx->r1 = ADD32(ctx->r1, -0X75A0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r17;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A8
    ctx->r1 = ADD32(ctx->r1, -0X75A8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // ori         $v1, $zero, 0x40
    ctx->r3 = 0 | 0X40;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A6
    ctx->r1 = ADD32(ctx->r1, -0X75A6);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7594
    ctx->r1 = ADD32(ctx->r1, -0X7594);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7592
    ctx->r1 = ADD32(ctx->r1, -0X7592);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7590
    ctx->r1 = ADD32(ctx->r1, -0X7590);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758E
    ctx->r1 = ADD32(ctx->r1, -0X758E);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7588
    ctx->r1 = ADD32(ctx->r1, -0X7588);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7586
    ctx->r1 = ADD32(ctx->r1, -0X7586);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7584
    ctx->r1 = ADD32(ctx->r1, -0X7584);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7582
    ctx->r1 = ADD32(ctx->r1, -0X7582);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7580
    ctx->r1 = ADD32(ctx->r1, -0X7580);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758C
    ctx->r1 = ADD32(ctx->r1, -0X758C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // ori         $v0, $zero, 0x200
    ctx->r2 = 0 | 0X200;
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // ori         $v0, $zero, 0x80FF
    ctx->r2 = 0 | 0X80FF;
    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // ori         $v0, $zero, 0x4000
    ctx->r2 = 0 | 0X4000;
    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s0, -0x1916($at)
    MEM_H(-0X1916, ctx->r1) = ctx->r16;
    // jal         0x80054EFC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_80054EFC(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_2:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800569DC
    if (ctx->r2 != 0) {
        // andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
        goto L_800569DC;
    }
    // andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
L_80056BB8:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $zero, -0x6EA0($at)
    MEM_H(-0X6EA0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $zero, -0x6E98($at)
    MEM_H(-0X6E98, ctx->r1) = 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $zero, -0xFD8($at)
    MEM_H(-0XFD8, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $zero, -0x6E90($at)
    MEM_H(-0X6E90, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $zero, -0x6E88($at)
    MEM_H(-0X6E88, ctx->r1) = 0;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $zero, -0x21BC($at)
    MEM_W(-0X21BC, ctx->r1) = 0;
    // ori         $v0, $zero, 0x3FFF
    ctx->r2 = 0 | 0X3FFF;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $v0, -0x21B4($at)
    MEM_H(-0X21B4, ctx->r1) = ctx->r2;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $v0, -0x21B2($at)
    MEM_H(-0X21B2, ctx->r1) = ctx->r2;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $zero, -0x21B8($at)
    MEM_W(-0X21B8, ctx->r1) = 0;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sb          $zero, 0x5190($at)
    MEM_B(0X5190, ctx->r1) = 0;
    // lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // sh          $zero, 0xA88($at)
    MEM_H(0XA88, ctx->r1) = 0;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, -0x2568($at)
    MEM_H(-0X2568, ctx->r1) = ctx->r2;
    // jal         0x800570D0
    // nop

    sub_800570D0(rdram, ctx);
    goto after_3;
    // nop

    after_3:
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
