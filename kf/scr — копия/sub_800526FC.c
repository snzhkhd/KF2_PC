#include "recomp.h"
#include "disable_warnings.h"

void sub_800526FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // lw          $s3, 0x0($s2)
    ctx->r19 = MEM_W(0X0, ctx->r18);
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // sltiu       $s5, $s3, 0x1
    ctx->r21 = ctx->r19 < 0X1 ? 1 : 0;
    // bne         $s5, $zero, L_80052758
    if (ctx->r21 != 0) {
        // sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
        goto L_80052758;
    }
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // andi        $v0, $s3, 0x1
    ctx->r2 = ctx->r19 & 0X1;
    // beq         $v0, $zero, L_80052878
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052878;
    }
    // nop

L_80052758:
    // lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(0X4, ctx->r18);
    // nop

    // andi        $v0, $s0, 0x100
    ctx->r2 = ctx->r16 & 0X100;
    // beq         $v0, $zero, L_80052774
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x101
        ctx->r2 = ADD32(0, -0X101);
        goto L_80052774;
    }
    // addiu       $v0, $zero, -0x101
    ctx->r2 = ADD32(0, -0X101);
    // and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    // ori         $fp, $zero, 0x1
    ctx->r30 = 0 | 0X1;
L_80052774:
    // sltiu       $v0, $s0, 0xA
    ctx->r2 = ctx->r16 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_800527A8
    if (ctx->r2 == 0) {
        // sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16) << 2;
        goto L_800527A8;
    }
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x310
    ctx->r1 = ADD32(ctx->r1, -0X310);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a0, 0x0($at)
    ctx->r4 = MEM_W(0X0, ctx->r1);
    // lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // addiu       $s1, $s1, -0x310
    ctx->r17 = ADD32(ctx->r17, -0X310);
    // jal         0x8005314C
    // nop

    sub_8005314C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_800527B0
    if (ctx->r2 == 0) {
        // ori         $s4, $zero, 0x1
        ctx->r20 = 0 | 0X1;
        goto L_800527B0;
    }
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
L_800527A8:
    // j           L_80052BD8
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80052BD8;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800527B0:
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // ori         $a1, $zero, 0x43
    ctx->r5 = 0 | 0X43;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s0, -0x760($at)
    MEM_W(-0X760, ctx->r1) = ctx->r16;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x760($v1)
    ctx->r3 = MEM_W(-0X760, ctx->r3);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x2C0
    ctx->r3 = ADD32(ctx->r3, -0X2C0);
    // lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(0X0, ctx->r4);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, -0x750($at)
    MEM_W(-0X750, ctx->r1) = ctx->r4;
L_800527F8:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // bne         $a1, $a3, L_800527F8
    if (ctx->r5 != ctx->r7) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_800527F8;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x760($v1)
    ctx->r3 = MEM_W(-0X760, ctx->r3);
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // beq         $v1, $v0, L_80052834
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x8
        ctx->r2 = 0 | 0X8;
        goto L_80052834;
    }
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // beq         $v1, $v0, L_80052850
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x7F
        ctx->r2 = 0 | 0X7F;
        goto L_80052850;
    }
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // j           L_80052868
    // nop

    goto L_80052868;
    // nop

L_80052834:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x754($at)
    MEM_W(-0X754, ctx->r1) = ctx->r2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x758($at)
    MEM_W(-0X758, ctx->r1) = ctx->r2;
    // j           L_80052878
    // nop

    goto L_80052878;
    // nop

L_80052850:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x754($at)
    MEM_W(-0X754, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x758($at)
    MEM_W(-0X758, ctx->r1) = ctx->r2;
    // j           L_80052878
    // nop

    goto L_80052878;
    // nop

L_80052868:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x754($at)
    MEM_W(-0X754, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x758($at)
    MEM_W(-0X758, ctx->r1) = 0;
L_80052878:
    // bne         $s5, $zero, L_80052888
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x8
        ctx->r2 = ctx->r19 & 0X8;
        goto L_80052888;
    }
    // andi        $v0, $s3, 0x8
    ctx->r2 = ctx->r19 & 0X8;
    // beq         $v0, $zero, L_800529A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800529A0;
    }
    // nop

L_80052888:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x760($v1)
    ctx->r3 = MEM_W(-0X760, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_80052998
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
        goto L_80052998;
    }
    // slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_80052998
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80052998;
    }
    // nop

    // bne         $s4, $zero, L_80052900
    if (ctx->r20 != 0) {
        // ori         $s6, $zero, 0x1
        ctx->r22 = 0 | 0X1;
        goto L_80052900;
    }
    // ori         $s6, $zero, 0x1
    ctx->r22 = 0 | 0X1;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // ori         $a0, $zero, 0x43
    ctx->r4 = 0 | 0X43;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x760($v0)
    ctx->r2 = MEM_W(-0X760, ctx->r2);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x2C0
    ctx->r2 = ADD32(ctx->r2, -0X2C0);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800528DC:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $a0, $a2, L_800528DC
    if (ctx->r4 != ctx->r6) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800528DC;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // lui         $v0, 0xC01
    ctx->r2 = S32(0XC01 << 16);
    // ori         $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 | 0X1C00;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80052900:
    // lui         $a2, 0x8102
    ctx->r6 = S32(0X8102 << 16);
    // lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(0XC, ctx->r18);
    // ori         $a2, $a2, 0x409
    ctx->r6 = ctx->r6 | 0X409;
    // sll         $v1, $a0, 13
    ctx->r3 = S32(ctx->r4) << 13;
    // mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // sll         $a1, $a0, 12
    ctx->r5 = S32(ctx->r4) << 12;
    // mult        $a1, $a2
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, -0x758($at)
    MEM_W(-0X758, ctx->r1) = ctx->r4;
    // lhu         $a0, 0x14($sp)
    ctx->r4 = MEM_HU(0X14, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($sp)
    ctx->r2 = MEM_HU(0X16, ctx->r29);
    // lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(0X36, ctx->r29);
    // mfhi        $v1
    ctx->r3 = hi;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sra         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) >> 6;
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2E($sp)
    ctx->r2 = MEM_HU(0X2E, ctx->r29);
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // sh          $a0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r4;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4C($sp)
    ctx->r2 = MEM_HU(0X4C, ctx->r29);
    // lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(0X4E, ctx->r29);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // j           L_800529A0
    // sh          $v1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r3;
    goto L_800529A0;
    // sh          $v1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r3;
L_80052998:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x758($at)
    MEM_W(-0X758, ctx->r1) = 0;
L_800529A0:
    // bne         $s5, $zero, L_800529B0
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x10
        ctx->r2 = ctx->r19 & 0X10;
        goto L_800529B0;
    }
    // andi        $v0, $s3, 0x10
    ctx->r2 = ctx->r19 & 0X10;
    // beq         $v0, $zero, L_80052A80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052A80;
    }
    // nop

L_800529B0:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x760($v1)
    ctx->r3 = MEM_W(-0X760, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_80052A78
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
        goto L_80052A78;
    }
    // slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_80052A78
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80052A78;
    }
    // nop

    // bne         $s4, $zero, L_80052A38
    if (ctx->r20 != 0) {
        // ori         $s7, $zero, 0x1
        ctx->r23 = 0 | 0X1;
        goto L_80052A38;
    }
    // ori         $s7, $zero, 0x1
    ctx->r23 = 0 | 0X1;
    // bne         $s6, $zero, L_80052A28
    if (ctx->r22 != 0) {
        // addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
        goto L_80052A28;
    }
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // ori         $a0, $zero, 0x43
    ctx->r4 = 0 | 0X43;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x760($v0)
    ctx->r2 = MEM_W(-0X760, ctx->r2);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x2C0
    ctx->r2 = ADD32(ctx->r2, -0X2C0);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80052A08:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $a0, $a2, L_80052A08
    if (ctx->r4 != ctx->r6) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80052A08;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // j           L_80052A34
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    goto L_80052A34;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
L_80052A28:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
L_80052A34:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80052A38:
    // lui         $a0, 0x8102
    ctx->r4 = S32(0X8102 << 16);
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // ori         $a0, $a0, 0x409
    ctx->r4 = ctx->r4 | 0X409;
    // sll         $v1, $v0, 7
    ctx->r3 = S32(ctx->r2) << 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x754($at)
    MEM_W(-0X754, ctx->r1) = ctx->r2;
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_80052A80
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    goto L_80052A80;
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
L_80052A78:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x754($at)
    MEM_W(-0X754, ctx->r1) = 0;
L_80052A80:
    // beq         $s4, $zero, L_80052AC4
    if (ctx->r20 == 0) {
        // nop
    
        goto L_80052AC4;
    }
    // nop

    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7CC($a0)
    ctx->r4 = MEM_W(-0X7CC, ctx->r4);
    // nop

    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80052B34
    if (ctx->r2 == 0) {
        // sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80052B34;
    }
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x1AA($a0)
    ctx->r3 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v1, $v1, 0xFF7F
    ctx->r3 = ctx->r3 & 0XFF7F;
    // sh          $v1, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r3;
    // j           L_80052B34
    // nop

    goto L_80052B34;
    // nop

L_80052AC4:
    // bne         $s5, $zero, L_80052AD4
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x2
        ctx->r2 = ctx->r19 & 0X2;
        goto L_80052AD4;
    }
    // andi        $v0, $s3, 0x2
    ctx->r2 = ctx->r19 & 0X2;
    // beq         $v0, $zero, L_80052AF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052AF8;
    }
    // nop

L_80052AD4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // nop

    // sh          $v1, 0x184($v0)
    MEM_H(0X184, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, -0x75C($at)
    MEM_H(-0X75C, ctx->r1) = ctx->r2;
L_80052AF8:
    // bne         $s5, $zero, L_80052B08
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x4
        ctx->r2 = ctx->r19 & 0X4;
        goto L_80052B08;
    }
    // andi        $v0, $s3, 0x4
    ctx->r2 = ctx->r19 & 0X4;
    // beq         $v0, $zero, L_80052B58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052B58;
    }
    // nop

L_80052B08:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(0XA, ctx->r18);
    // nop

    // sh          $v1, 0x186($v0)
    MEM_H(0X186, ctx->r2) = ctx->r3;
    // lhu         $v0, 0xA($s2)
    ctx->r2 = MEM_HU(0XA, ctx->r18);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, -0x75A($at)
    MEM_H(-0X75A, ctx->r1) = ctx->r2;
    // j           L_80052B58
    // nop

    goto L_80052B58;
    // nop

L_80052B34:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // sh          $zero, 0x184($v0)
    MEM_H(0X184, ctx->r2) = 0;
    // sh          $zero, 0x186($v0)
    MEM_H(0X186, ctx->r2) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $zero, -0x75C($at)
    MEM_H(-0X75C, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $zero, -0x75A($at)
    MEM_H(-0X75A, ctx->r1) = 0;
L_80052B58:
    // bne         $s4, $zero, L_80052B70
    if (ctx->r20 != 0) {
        // nop
    
        goto L_80052B70;
    }
    // nop

    // bne         $s6, $zero, L_80052B70
    if (ctx->r22 != 0) {
        // nop
    
        goto L_80052B70;
    }
    // nop

    // beq         $s7, $zero, L_80052B78
    if (ctx->r23 == 0) {
        // nop
    
        goto L_80052B78;
    }
    // nop

L_80052B70:
    // jal         0x80052C0C
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    _spu_setReverbAttr(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
L_80052B78:
    // beq         $fp, $zero, L_80052B90
    if (ctx->r30 == 0) {
        // nop
    
        goto L_80052B90;
    }
    // nop

    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x760($a0)
    ctx->r4 = MEM_W(-0X760, ctx->r4);
    // jal         0x800531C4
    // nop

    KF_SpuClearReverbWorkArea(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80052B90:
    // beq         $s4, $zero, L_80052BD4
    if (ctx->r20 == 0) {
        // ori         $a0, $zero, 0xD1
        ctx->r4 = 0 | 0XD1;
        goto L_80052BD4;
    }
    // ori         $a0, $zero, 0xD1
    ctx->r4 = 0 | 0XD1;
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x750($a1)
    ctx->r5 = MEM_W(-0X750, ctx->r5);
    // jal         0x80051C3C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80051C3C(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(0X58, ctx->r29);
    // nop

    // beq         $t0, $zero, L_80052BD8
    if (ctx->r8 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80052BD8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v1, 0x1AA($v0)
    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
    // nop

    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sh          $v1, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = ctx->r3;
L_80052BD4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80052BD8:
    // lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(0X8C, ctx->r29);
    // lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(0X88, ctx->r29);
    // lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(0X84, ctx->r29);
    // lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(0X80, ctx->r29);
    // lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(0X7C, ctx->r29);
    // lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // jr          $ra
    // nop

    return;
    // nop

;}
