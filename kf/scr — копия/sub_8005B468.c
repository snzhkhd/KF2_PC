#include "recomp.h"
#include "disable_warnings.h"

void sub_8005B468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(0X70, ctx->r29);
    // lbu         $s1, 0x74($sp)
    ctx->r17 = MEM_BU(0X74, ctx->r29);
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // jal         0x8005BCF4
    // addu        $s5, $t0, $zero
    ctx->r21 = ADD32(ctx->r8, 0);
    sub_8005BCF4(rdram, ctx);
    goto after_0;
    // addu        $s5, $t0, $zero
    ctx->r21 = ADD32(ctx->r8, 0);
    after_0:
    // ori         $v0, $zero, 0x16
    ctx->r2 = 0 | 0X16;
    // addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // sltu        $v0, $v0, $s0
    ctx->r2 = ctx->r2 < ctx->r16 ? 1 : 0;
    // bne         $v0, $zero, L_8005B718
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16) << 2;
        goto L_8005B718;
    }
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x34E4
    ctx->r1 = ADD32(ctx->r1, 0X34E4);
    // addu        $at, $at, $v0
    gpr jr_addend_8005B4FC;
    jr_addend_8005B4FC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8005B4FC >> 2) {
        case 0: goto L_8005B504; break;
        case 1: goto L_8005B50C; break;
        case 2: goto L_8005B57C; break;
        case 3: goto L_8005B584; break;
        case 4: goto L_8005B5B0; break;
        case 5: goto L_8005B5B0; break;
        case 6: goto L_8005B5B0; break;
        case 7: goto L_8005B5B0; break;
        case 8: goto L_8005B5B0; break;
        case 9: goto L_8005B5B0; break;
        case 10: goto L_8005B5B0; break;
        case 11: goto L_8005B5B0; break;
        case 12: goto L_8005B5B0; break;
        case 13: goto L_8005B5B0; break;
        case 14: goto L_8005B5B0; break;
        case 15: goto L_8005B6DC; break;
        case 16: goto L_8005B6EC; break;
        case 17: goto L_8005B700; break;
        case 18: goto L_8005B710; break;
        case 19: goto L_8005B710; break;
        case 20: goto L_8005B718; break;
        case 21: goto L_8005B718; break;
        case 22: goto L_8005B718; break;
        default: switch_error(__func__, 0x8005B4FC, 0x800134E4);
    }
    // nop

L_8005B504:
    // j           L_8005B588
    // sb          $s1, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r17;
    goto L_8005B588;
    // sb          $s1, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r17;
L_8005B50C:
    // sb          $s1, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r17;
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x8005BF30
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    sub_8005BF30(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_1:
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // bne         $a0, $zero, L_8005B54C
    if (ctx->r4 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005B54C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x800524F0
    // nop

    sub_800524F0(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B54C:
    // beq         $a0, $v0, L_8005B718
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8005B718;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $a0, $v0, L_8005B718
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8005B718;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $a0, $v0, L_8005B718
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8005B718;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // bne         $a0, $v0, L_8005B718
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8005B718;
    }
    // nop

    // jal         0x800524D0
    // nop

    sub_800524D0(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B57C:
    // j           L_8005B588
    // sb          $s1, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r17;
    goto L_8005B588;
    // sb          $s1, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r17;
L_8005B584:
    // sb          $s1, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r17;
L_8005B588:
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x8005BF30
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    sub_8005BF30(rdram, ctx);
    goto after_4;
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_4:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B5B0:
    // lhu         $a0, 0x4C($sp)
    ctx->r4 = MEM_HU(0X4C, ctx->r29);
    // lhu         $a1, 0x4E($sp)
    ctx->r5 = MEM_HU(0X4E, ctx->r29);
    // jal         0x8005BC0C
    // addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    sub_8005BC0C(rdram, ctx);
    goto after_5;
    // addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_5:
    // addiu       $v0, $s4, -0x4
    ctx->r2 = ADD32(ctx->r20, -0X4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8005B6A4
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
        goto L_8005B6A4;
    }
    // addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x3544
    ctx->r1 = ADD32(ctx->r1, 0X3544);
    // addu        $at, $at, $v0
    gpr jr_addend_8005B5F4;
    jr_addend_8005B5F4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8005B5F4 >> 2) {
        case 0: goto L_8005B5FC; break;
        case 1: goto L_8005B608; break;
        case 2: goto L_8005B618; break;
        case 3: goto L_8005B620; break;
        case 4: goto L_8005B628; break;
        case 5: goto L_8005B634; break;
        case 6: goto L_8005B644; break;
        case 7: goto L_8005B650; break;
        case 8: goto L_8005B660; break;
        case 9: goto L_8005B694; break;
        case 10: goto L_8005B69C; break;
        default: switch_error(__func__, 0x8005B5F4, 0x80013544);
    }
    // nop

L_8005B5FC:
    // sh          $zero, 0x66($sp)
    MEM_H(0X66, ctx->r29) = 0;
    // j           L_8005B6A0
    // sh          $s1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r17;
L_8005B608:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r2;
    // j           L_8005B6A0
    // sh          $s1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r17;
L_8005B618:
    // j           L_8005B6A0
    // sh          $s1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r17;
L_8005B620:
    // j           L_8005B6A0
    // sh          $s1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r17;
L_8005B628:
    // sh          $zero, 0x68($sp)
    MEM_H(0X68, ctx->r29) = 0;
    // j           L_8005B6A0
    // sh          $s1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r17;
L_8005B634:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // j           L_8005B6A0
    // sh          $s1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r17;
L_8005B644:
    // sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // j           L_8005B6A0
    // sh          $s1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r17;
L_8005B650:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    // j           L_8005B6A0
    // sh          $s1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sh          $s1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r17;
L_8005B660:
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // beq         $v0, $zero, L_8005B67C
    if (ctx->r2 == 0) {
        // sltiu       $v0, $v0, 0x40
        ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
        goto L_8005B67C;
    }
    // sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8005B680
    if (ctx->r2 == 0) {
        // addiu       $v0, $s1, -0x40
        ctx->r2 = ADD32(ctx->r17, -0X40);
        goto L_8005B680;
    }
    // addiu       $v0, $s1, -0x40
    ctx->r2 = ADD32(ctx->r17, -0X40);
    // j           L_8005B6A0
    // sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    goto L_8005B6A0;
    // sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
L_8005B67C:
    // addiu       $v0, $s1, -0x40
    ctx->r2 = ADD32(ctx->r17, -0X40);
L_8005B680:
    // sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8005B6A0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005B6A0;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_8005B6A0
    // sh          $v0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r2;
    goto L_8005B6A0;
    // sh          $v0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r2;
L_8005B694:
    // j           L_8005B6A0
    // sb          $s1, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r17;
    goto L_8005B6A0;
    // sb          $s1, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r17;
L_8005B69C:
    // sb          $s1, 0x46($sp)
    MEM_B(0X46, ctx->r29) = ctx->r17;
L_8005B6A0:
    // addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
L_8005B6A4:
    // addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // addiu       $a2, $sp, 0x4E
    ctx->r6 = ADD32(ctx->r29, 0X4E);
    // jal         0x8005BC68
    // addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    sub_8005BC68(rdram, ctx);
    goto after_6;
    // addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    after_6:
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x8005BF30
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_8005BF30(rdram, ctx);
    goto after_7;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_7:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B6DC:
    // jal         0x80052510
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80052510(rdram, ctx);
    goto after_8;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B6EC:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800525C0
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_800525C0(rdram, ctx);
    goto after_9;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_9:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B700:
    // jal         0x8005267C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8005267C(rdram, ctx);
    goto after_10;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // j           L_8005B718
    // nop

    goto L_8005B718;
    // nop

L_8005B710:
    // jal         0x800526BC
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_800526BC(rdram, ctx);
    goto after_11;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
L_8005B718:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
