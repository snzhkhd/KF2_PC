#include "recomp.h"
#include "disable_warnings.h"

void sub_80055790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7746
    ctx->r1 = ADD32(ctx->r1, -0X7746);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a2, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r6;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7748
    ctx->r1 = ADD32(ctx->r1, -0X7748);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r5;
    // sltiu       $v0, $a0, 0x10
    ctx->r2 = ctx->r4 < 0X10 ? 1 : 0;
    // ori         $v1, $v1, 0x3
    ctx->r3 = ctx->r3 | 0X3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // beq         $v0, $zero, L_800557FC
    if (ctx->r2 == 0) {
        // addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
        goto L_800557FC;
    }
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $t0, $v0, $a0
    ctx->r8 = S32(ctx->r2) << (ctx->r4 & 31);
    // j           L_8005580C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_8005580C;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800557FC:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $v1, $a0, -0x10
    ctx->r3 = ADD32(ctx->r4, -0X10);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
L_8005580C:
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x49D8($a0)
    ctx->r4 = MEM_BU(-0X49D8, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // ori         $v1, $zero, 0xA
    ctx->r3 = 0 | 0XA;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AC
    ctx->r1 = ADD32(ctx->r1, -0X75AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // beq         $a0, $zero, L_800558A4
    if (ctx->r4 == 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_800558A4;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
L_8005584C:
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
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // nop

    // andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8005584C
    if (ctx->r2 != 0) {
        // andi        $v1, $a1, 0xFFFF
        ctx->r3 = ctx->r5 & 0XFFFF;
        goto L_8005584C;
    }
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
L_800558A4:
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
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
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x6EA0($v1)
    ctx->r3 = MEM_HU(-0X6EA0, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x6E98($a0)
    ctx->r4 = MEM_HU(-0X6E98, ctx->r4);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lhu         $a1, -0xFD8($a1)
    ctx->r5 = MEM_HU(-0XFD8, ctx->r5);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0xFD0($v0)
    ctx->r2 = MEM_HU(-0XFD0, ctx->r2);
    // or          $v1, $t0, $v1
    ctx->r3 = ctx->r8 | ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, -0x6EA0($at)
    MEM_H(-0X6EA0, ctx->r1) = ctx->r3;
    // or          $a0, $a2, $a0
    ctx->r4 = ctx->r6 | ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $a0, -0x6E98($at)
    MEM_H(-0X6E98, ctx->r1) = ctx->r4;
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $a1, $a1, $v1
    ctx->r5 = ctx->r5 & ctx->r3;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $a1, -0xFD8($at)
    MEM_H(-0XFD8, ctx->r1) = ctx->r5;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(0X44, ctx->r3);
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0xFD0($at)
    MEM_H(-0XFD0, ctx->r1) = ctx->r2;
    // sh          $t0, 0x194($v1)
    MEM_H(0X194, ctx->r3) = ctx->r8;
    // sh          $a2, 0x196($v1)
    MEM_H(0X196, ctx->r3) = ctx->r6;
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
