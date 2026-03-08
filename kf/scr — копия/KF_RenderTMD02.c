#include "recomp.h"
#include "disable_warnings.h"

void KF_RenderTMD02(uint8_t* rdram, recomp_context* ctx) 
{


//   printf("sub_800322FC\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // beq         $s0, $zero, L_80032360
    if (ctx->r16 == 0) {
        // sw          $a1, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r5;
        goto L_80032360;
    }
    // sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(0X14, ctx->r16);
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v0, 0xB54($at)
    MEM_W(0XB54, ctx->r1) = ctx->r2;
    // j           L_80032384
    // addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    goto L_80032384;
    // addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
L_80032360:
    // jal         0x8002FFD4
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sub_8002FFD4(rdram, ctx);
    goto after_0;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x250($v1)
    ctx->r3 = MEM_W(0X250, ctx->r3);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
L_80032384:
    // lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(0X4, ctx->r18);
    // lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // lw          $s7, 0xB54($s7)
    ctx->r23 = MEM_W(0XB54, ctx->r23);
    // jal         0x800305F4
    // nop

    sub_800305F4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // beq         $s0, $zero, L_800323B4
    if (ctx->r16 == 0) {
        // nop
    
        goto L_800323B4;
    }
    // nop

    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // j           L_800323C8
    // addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
    goto L_800323C8;
    // addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
L_800323B4:
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x250($v1)
    ctx->r3 = MEM_W(0X250, ctx->r3);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
L_800323C8:
    // lw          $s2, 0x14($s2)
    ctx->r18 = MEM_W(0X14, ctx->r18);
    // nop

    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(0X70, ctx->r29);
    // nop

    // addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    // beq         $v0, $zero, L_800329E8
    if (ctx->r2 == 0) {
        // sw          $t7, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_800329E8;
    }
    // sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // lui         $fp, 0x8019
    ctx->r30 = S32(0X8019 << 16);
    // addiu       $fp, $fp, 0xC48
    ctx->r30 = ADD32(ctx->r30, 0XC48);
    // addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
L_800323F8:
    // lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(0X0, ctx->r17);
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // srl         $t7, $t7, 24
    ctx->r15 = S32(U32(ctx->r15) >> 24);
    // andi        $v1, $t7, 0xFD
    ctx->r3 = ctx->r15 & 0XFD;
    // beq         $v1, $v0, L_8003270C
    if (ctx->r3 == ctx->r2) {
        // sw          $t7, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r15;
        goto L_8003270C;
    }
    // sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // bne         $v1, $v0, L_800329BC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800329BC;
    }
    // nop

    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // lhu         $v1, 0x14($s1)
    ctx->r3 = MEM_HU(0X14, ctx->r17);
    // addu        $s4, $v0, $fp
    ctx->r20 = ADD32(ctx->r2, ctx->r30);
    // addu        $s3, $v1, $fp
    ctx->r19 = ADD32(ctx->r3, ctx->r30);
    // lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(0X16, ctx->r17);
    // lhu         $v1, 0x18($s1)
    ctx->r3 = MEM_HU(0X18, ctx->r17);
    // lh          $t0, 0x2($s4)
    ctx->r8 = MEM_H(0X2, ctx->r20);
    // lh          $a2, 0x2($s3)
    ctx->r6 = MEM_H(0X2, ctx->r19);
    // lh          $a3, 0x0($s4)
    ctx->r7 = MEM_H(0X0, ctx->r20);
    // lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(0X0, ctx->r19);
    // addu        $s2, $v0, $fp
    ctx->r18 = ADD32(ctx->r2, ctx->r30);
    // addu        $s5, $v1, $fp
    ctx->r21 = ADD32(ctx->r3, ctx->r30);
    // subu        $t1, $t0, $a2
    ctx->r9 = SUB32(ctx->r8, ctx->r6);
    // subu        $t4, $a3, $a1
    ctx->r12 = SUB32(ctx->r7, ctx->r5);
    // lh          $v0, 0x2($s5)
    ctx->r2 = MEM_H(0X2, ctx->r21);
    // lh          $v1, 0x2($s2)
    ctx->r3 = MEM_H(0X2, ctx->r18);
    // lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(0X0, ctx->r18);
    // subu        $t2, $a2, $v0
    ctx->r10 = SUB32(ctx->r6, ctx->r2);
    // subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // subu        $t0, $v1, $t0
    ctx->r8 = SUB32(ctx->r3, ctx->r8);
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // subu        $a3, $a0, $a3
    ctx->r7 = SUB32(ctx->r4, ctx->r7);
    // lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(0X0, ctx->r21);
    // lhu         $v1, 0x4($s3)
    ctx->r3 = MEM_HU(0X4, ctx->r19);
    // subu        $t5, $a1, $v0
    ctx->r13 = SUB32(ctx->r5, ctx->r2);
    // subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // lhu         $a0, 0x4($s5)
    ctx->r4 = MEM_HU(0X4, ctx->r21);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_800326A0
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $t1, 0x1FF
        ctx->r2 = ADD32(ctx->r9, 0X1FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t1, 0x1FF
    ctx->r2 = ADD32(ctx->r9, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $t2, 0x1FF
        ctx->r2 = ADD32(ctx->r10, 0X1FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t2, 0x1FF
    ctx->r2 = ADD32(ctx->r10, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $t3, 0x1FF
        ctx->r2 = ADD32(ctx->r11, 0X1FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t3, 0x1FF
    ctx->r2 = ADD32(ctx->r11, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $t0, 0x1FF
        ctx->r2 = ADD32(ctx->r8, 0X1FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t0, 0x1FF
    ctx->r2 = ADD32(ctx->r8, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $a2, 0x1FF
        ctx->r2 = ADD32(ctx->r6, 0X1FF);
        goto L_800326A0;
    }
    // addiu       $v0, $a2, 0x1FF
    ctx->r2 = ADD32(ctx->r6, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $t4, 0x3FF
        ctx->r2 = ADD32(ctx->r12, 0X3FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t4, 0x3FF
    ctx->r2 = ADD32(ctx->r12, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $t5, 0x3FF
        ctx->r2 = ADD32(ctx->r13, 0X3FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t5, 0x3FF
    ctx->r2 = ADD32(ctx->r13, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $t6, 0x3FF
        ctx->r2 = ADD32(ctx->r14, 0X3FF);
        goto L_800326A0;
    }
    // addiu       $v0, $t6, 0x3FF
    ctx->r2 = ADD32(ctx->r14, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $a3, 0x3FF
        ctx->r2 = ADD32(ctx->r7, 0X3FF);
        goto L_800326A0;
    }
    // addiu       $v0, $a3, 0x3FF
    ctx->r2 = ADD32(ctx->r7, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $a1, 0x3FF
        ctx->r2 = ADD32(ctx->r5, 0X3FF);
        goto L_800326A0;
    }
    // addiu       $v0, $a1, 0x3FF
    ctx->r2 = ADD32(ctx->r5, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_800326A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800326A0;
    }
    // nop

    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // blez        $v0, L_800329BC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800329BC;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x34
    ctx->r2 = ADD32(ctx->r16, 0X34);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800329E8
    if (ctx->r2 != 0) {
        // addu        $a2, $s6, $zero
        ctx->r6 = ADD32(ctx->r22, 0);
        goto L_800329E8;
    }
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // lhu         $a0, 0x10($s1)
    ctx->r4 = MEM_HU(0X10, ctx->r17);
    // lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(0X68, ctx->r29);
    // jal         0x8005F474
    // addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    KF_NormalColorCol(rdram, ctx);
    goto after_3;
    // addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    after_3:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s4)
    ctx->r5 = MEM_H(0X6, ctx->r20);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    KF_DpqColor(rdram, ctx);
    goto after_4;
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_4:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(0X6, ctx->r19);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    KF_DpqColor(rdram, ctx);
    goto after_5;
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_5:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s2)
    ctx->r5 = MEM_H(0X6, ctx->r18);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    KF_DpqColor(rdram, ctx);
    goto after_6;
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_6:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s5)
    ctx->r5 = MEM_H(0X6, ctx->r21);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    KF_DpqColor(rdram, ctx);
    goto after_7;
    // addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_7:
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(0X78, ctx->r29);
    // nop

    // andi        $v0, $t7, 0x2
    ctx->r2 = ctx->r15 & 0X2;
    // ori         $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 | 0X3C;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_H(0X4, ctx->r20);
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_H(0X4, ctx->r19);
    // lh          $a0, 0x4($s5)
    ctx->r4 = MEM_H(0X4, ctx->r21);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x4($s2)
    ctx->r3 = MEM_H(0X4, ctx->r18);
    // lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(0X58, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_8003290C
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    goto L_8003290C;
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
L_800326A0:
    // lhu         $a0, 0x12($s1)
    ctx->r4 = MEM_HU(0X12, ctx->r17);
    // lhu         $a1, 0x14($s1)
    ctx->r5 = MEM_HU(0X14, ctx->r17);
    // lhu         $a2, 0x16($s1)
    ctx->r6 = MEM_HU(0X16, ctx->r17);
    // lhu         $a3, 0x18($s1)
    ctx->r7 = MEM_HU(0X18, ctx->r17);
    // addiu       $v0, $s1, 0x4
    ctx->r2 = ADD32(ctx->r17, 0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $s1, 0xC
    ctx->r2 = ADD32(ctx->r17, 0XC);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4ACC
    ctx->r2 = ADD32(ctx->r2, 0X4ACC);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // addu        $a1, $s7, $a1
    ctx->r5 = ADD32(ctx->r23, ctx->r5);
    // addu        $a2, $s7, $a2
    ctx->r6 = ADD32(ctx->r23, ctx->r6);
    // jal         0x8005E234
    // addu        $a3, $s7, $a3
    ctx->r7 = ADD32(ctx->r23, ctx->r7);
    sub_8005E234(rdram, ctx);
    goto after_8;
    // addu        $a3, $s7, $a3
    ctx->r7 = ADD32(ctx->r23, ctx->r7);
    after_8:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_800329BC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800329BC;
    }
    // nop

    // lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(0X60, ctx->r29);
    // lhu         $a1, 0x10($s1)
    ctx->r5 = MEM_HU(0X10, ctx->r17);
    // j           L_80032990
    // nop

    goto L_80032990;
    // nop

L_8003270C:
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(0X12, ctx->r17);
    // addu        $s4, $v0, $fp
    ctx->r20 = ADD32(ctx->r2, ctx->r30);
    // addu        $s2, $v1, $fp
    ctx->r18 = ADD32(ctx->r3, ctx->r30);
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(0X2, ctx->r20);
    // lh          $v1, 0x2($s2)
    ctx->r3 = MEM_H(0X2, ctx->r18);
    // addu        $s3, $v0, $fp
    ctx->r19 = ADD32(ctx->r2, ctx->r30);
    // lh          $v0, 0x2($s3)
    ctx->r2 = MEM_H(0X2, ctx->r19);
    // subu        $t3, $v1, $a0
    ctx->r11 = SUB32(ctx->r3, ctx->r4);
    // subu        $t1, $a0, $v0
    ctx->r9 = SUB32(ctx->r4, ctx->r2);
    // subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // lh          $a0, 0x0($s4)
    ctx->r4 = MEM_H(0X0, ctx->r20);
    // lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(0X0, ctx->r19);
    // lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(0X0, ctx->r18);
    // subu        $t4, $a0, $v0
    ctx->r12 = SUB32(ctx->r4, ctx->r2);
    // subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    // subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // lhu         $v1, 0x4($s3)
    ctx->r3 = MEM_HU(0X4, ctx->r19);
    // lhu         $a0, 0x4($s2)
    ctx->r4 = MEM_HU(0X4, ctx->r18);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003293C
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $t1, 0x1FF
        ctx->r2 = ADD32(ctx->r9, 0X1FF);
        goto L_8003293C;
    }
    // addiu       $v0, $t1, 0x1FF
    ctx->r2 = ADD32(ctx->r9, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_8003293C
    if (ctx->r2 == 0) {
        // addiu       $v0, $t2, 0x1FF
        ctx->r2 = ADD32(ctx->r10, 0X1FF);
        goto L_8003293C;
    }
    // addiu       $v0, $t2, 0x1FF
    ctx->r2 = ADD32(ctx->r10, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_8003293C
    if (ctx->r2 == 0) {
        // addiu       $v0, $t3, 0x1FF
        ctx->r2 = ADD32(ctx->r11, 0X1FF);
        goto L_8003293C;
    }
    // addiu       $v0, $t3, 0x1FF
    ctx->r2 = ADD32(ctx->r11, 0X1FF);
    // sltiu       $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 < 0X3FF ? 1 : 0;
    // beq         $v0, $zero, L_8003293C
    if (ctx->r2 == 0) {
        // addiu       $v0, $t4, 0x3FF
        ctx->r2 = ADD32(ctx->r12, 0X3FF);
        goto L_8003293C;
    }
    // addiu       $v0, $t4, 0x3FF
    ctx->r2 = ADD32(ctx->r12, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_8003293C
    if (ctx->r2 == 0) {
        // addiu       $v0, $t5, 0x3FF
        ctx->r2 = ADD32(ctx->r13, 0X3FF);
        goto L_8003293C;
    }
    // addiu       $v0, $t5, 0x3FF
    ctx->r2 = ADD32(ctx->r13, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_8003293C
    if (ctx->r2 == 0) {
        // addiu       $v0, $t6, 0x3FF
        ctx->r2 = ADD32(ctx->r14, 0X3FF);
        goto L_8003293C;
    }
    // addiu       $v0, $t6, 0x3FF
    ctx->r2 = ADD32(ctx->r14, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_80032940
    if (ctx->r2 == 0) {
        // addu        $a3, $s1, $zero
        ctx->r7 = ADD32(ctx->r17, 0);
        goto L_80032940;
    }
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // blez        $v0, L_800329BC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800329BC;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800329E8
    if (ctx->r2 != 0) {
        // addu        $a2, $s6, $zero
        ctx->r6 = ADD32(ctx->r22, 0);
        goto L_800329E8;
    }
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(0XC, ctx->r17);
    // lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(0X68, ctx->r29);
    // jal         0x8005F474
    // addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    KF_NormalColorCol(rdram, ctx);
    goto after_10;
    // addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    after_10:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s4)
    ctx->r5 = MEM_H(0X6, ctx->r20);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    KF_DpqColor(rdram, ctx);
    goto after_11;
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_11:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(0X6, ctx->r19);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    KF_DpqColor(rdram, ctx);
    goto after_12;
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_12:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $a1, 0x6($s2)
    ctx->r5 = MEM_H(0X6, ctx->r18);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    KF_DpqColor(rdram, ctx);
    goto after_13;
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_13:
    // lui         $a1, 0x5555
    ctx->r5 = S32(0X5555 << 16);
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(0X78, ctx->r29);
    // ori         $a1, $a1, 0x5556
    ctx->r5 = ctx->r5 | 0X5556;
    // andi        $v0, $t7, 0x2
    ctx->r2 = ctx->r15 & 0X2;
    // ori         $v0, $v0, 0x34
    ctx->r2 = ctx->r2 | 0X34;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(0X4, ctx->r20);
    // lh          $v0, 0x4($s3)
    ctx->r2 = MEM_H(0X4, ctx->r19);
    // lh          $a0, 0x4($s2)
    ctx->r4 = MEM_H(0X4, ctx->r18);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(0X58, ctx->r29);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8003290C:
    // addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80032920
    if (ctx->r2 == 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80032920;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
L_80032920:
    // andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // lw          $v0, -0xAEC($fp)
    ctx->r2 = MEM_W(-0XAEC, ctx->r30);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x80067238
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_14;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_14:
    // j           L_800329BC
    // nop

    goto L_800329BC;
    // nop

L_8003293C:
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_80032940:
    // lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(0XE, ctx->r17);
    // lhu         $a1, 0x10($s1)
    ctx->r5 = MEM_HU(0X10, ctx->r17);
    // lhu         $a2, 0x12($s1)
    ctx->r6 = MEM_HU(0X12, ctx->r17);
    // addiu       $v0, $s1, 0x4
    ctx->r2 = ADD32(ctx->r17, 0X4);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4ACC
    ctx->r2 = ADD32(ctx->r2, 0X4ACC);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // addu        $a1, $s7, $a1
    ctx->r5 = ADD32(ctx->r23, ctx->r5);
    // jal         0x8005E1AC
    // addu        $a2, $s7, $a2
    ctx->r6 = ADD32(ctx->r23, ctx->r6);
    sub_8005E1AC(rdram, ctx);
    goto after_15;
    // addu        $a2, $s7, $a2
    ctx->r6 = ADD32(ctx->r23, ctx->r6);
    after_15:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_800329BC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800329BC;
    }
    // nop

    // lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(0X60, ctx->r29);
    // lhu         $a1, 0xC($s1)
    ctx->r5 = MEM_HU(0XC, ctx->r17);
L_80032990:
    // lhu         $a2, 0x2($s1)
    ctx->r6 = MEM_HU(0X2, ctx->r17);
    // lhu         $a3, 0x6($s1)
    ctx->r7 = MEM_HU(0X6, ctx->r17);
    // srl         $v0, $t7, 24
    ctx->r2 = S32(U32(ctx->r15) >> 24);
    // lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(0X58, ctx->r29);
    // nop

    // sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(0X68, ctx->r29);
    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x800320BC
    // addu        $a1, $t7, $a1
    ctx->r5 = ADD32(ctx->r15, ctx->r5);
    sub_800320BC(rdram, ctx);
    goto after_16;
    // addu        $a1, $t7, $a1
    ctx->r5 = ADD32(ctx->r15, ctx->r5);
    after_16:
L_800329BC:
    // lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(0X60, ctx->r29);
    // nop

    // srl         $v0, $t7, 6
    ctx->r2 = S32(U32(ctx->r15) >> 6);
    // andi        $v0, $v0, 0x3FC
    ctx->r2 = ctx->r2 & 0X3FC;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(0X70, ctx->r29);
    // nop

    // addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    // bne         $v0, $zero, L_800323F8
    if (ctx->r2 != 0) {
        // sw          $t7, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_800323F8;
    }
    // sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_800329E8:
    // lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(0XA4, ctx->r29);
    // lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(0XA0, ctx->r29);
    // lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(0X9C, ctx->r29);
    // lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(0X98, ctx->r29);
    // lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(0X94, ctx->r29);
    // lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(0X90, ctx->r29);
    // lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(0X8C, ctx->r29);
    // lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(0X88, ctx->r29);
    // lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(0X84, ctx->r29);
    // lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(0X80, ctx->r29);
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // jr          $ra
    // nop

    return;
    // nop

;}
