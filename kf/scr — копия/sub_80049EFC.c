#include "recomp.h"
#include "disable_warnings.h"

void sub_80049EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // bne         $a0, $zero, L_80049FA0
    if (ctx->r4 != 0) {
        // sw          $a0, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r4;
        goto L_80049FA0;
    }
    // sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // ori         $a0, $zero, 0x15E
    ctx->r4 = 0 | 0X15E;
    // lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // lhu         $a2, 0x12E($a2)
    ctx->r6 = MEM_HU(0X12E, ctx->r6);
    // lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(0X84, ctx->r29);
    // jal         0x80038E6C
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    FindFreeOrOldestProjectileSlot(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // jal         0x80038004
    // sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    sub_80038004(rdram, ctx);
    goto after_1;
    // sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    after_1:
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $s7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r23;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // nop

    // sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // sb          $v1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r3;
L_80049FA0:
    // lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(0X80, ctx->r29);
    // lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // addiu       $a2, $a2, 0x79F0
    ctx->r6 = ADD32(ctx->r6, 0X79F0);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // lhu         $t1, 0xE($a1)
    ctx->r9 = MEM_HU(0XE, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s4, $v0, $a2
    ctx->r20 = ADD32(ctx->r2, ctx->r6);
    // sh          $t1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r9;
    // lbu         $v1, 0x38($a1)
    ctx->r3 = MEM_BU(0X38, ctx->r5);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_8004A5B0
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x20
        ctx->r2 = 0 | 0X20;
        goto L_8004A5B0;
    }
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // lbu         $v1, 0x1($s4)
    ctx->r3 = MEM_BU(0X1, ctx->r20);
    // nop

    // bne         $v1, $v0, L_8004A020
    if (ctx->r3 != ctx->r2) {
        // lui         $a0, 0xFFFF
        ctx->r4 = S32(0XFFFF << 16);
        goto L_8004A020;
    }
    // lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // lhu         $a1, 0x3A($a1)
    ctx->r5 = MEM_HU(0X3A, ctx->r5);
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x15
    ctx->r4 = 0 | 0X15;
    MessageQueuePush(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x15
    ctx->r4 = 0 | 0X15;
    after_2:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B10
    ctx->r4 = ADD32(ctx->r4, -0X4B10);
    // sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x3A($v1)
    ctx->r2 = MEM_HU(0X3A, ctx->r3);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8004A5B0
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    goto L_8004A5B0;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8004A020:
    // ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // lui         $v1, 0x67
    ctx->r3 = S32(0X67 << 16);
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // bne         $v0, $v1, L_8004A08C
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $a2, 0x1E00
        ctx->r4 = ADD32(ctx->r6, 0X1E00);
        goto L_8004A08C;
    }
    // addiu       $a0, $a2, 0x1E00
    ctx->r4 = ADD32(ctx->r6, 0X1E00);
    // lhu         $v1, 0x40($a1)
    ctx->r3 = MEM_HU(0X40, ctx->r5);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x3B($v0)
    ctx->r3 = MEM_BU(0X3B, ctx->r2);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // bne         $v1, $v0, L_8004A08C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004A08C;
    }
    // nop

    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8004A5B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004A5B0;
    }
    // nop

L_8004A08C:
    // lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(0X80, ctx->r29);
    // nop

    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // bne         $v1, $v0, L_8004A0A8
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_8004A0A8;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
L_8004A0A8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4C($v0)
    ctx->r2 = MEM_HU(-0X4A4C, ctx->r2);
    // nop

    // andi        $s6, $v0, 0xFFF
    ctx->r22 = ctx->r2 & 0XFFF;
    // slti        $v0, $s6, 0x800
    ctx->r2 = SIGNED(ctx->r22) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_8004A0D8
    if (ctx->r2 == 0) {
        // addu        $s3, $s6, $zero
        ctx->r19 = ADD32(ctx->r22, 0);
        goto L_8004A0D8;
    }
    // addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // slti        $v0, $s6, 0x101
    ctx->r2 = SIGNED(ctx->r22) < 0X101 ? 1 : 0;
    // bne         $v0, $zero, L_8004A0E8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004A0E8;
    }
    // nop

    // j           L_8004A0E8
    // ori         $s3, $zero, 0x100
    ctx->r19 = 0 | 0X100;
    goto L_8004A0E8;
    // ori         $s3, $zero, 0x100
    ctx->r19 = 0 | 0X100;
L_8004A0D8:
    // slti        $v0, $s6, 0xF00
    ctx->r2 = SIGNED(ctx->r22) < 0XF00 ? 1 : 0;
    // beq         $v0, $zero, L_8004A0E8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004A0E8;
    }
    // nop

    // ori         $s3, $zero, 0xF00
    ctx->r19 = 0 | 0XF00;
L_8004A0E8:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_3:
    // lh          $v1, 0xE($s4)
    ctx->r3 = MEM_H(0XE, ctx->r20);
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // bgez        $v0, L_8004A108
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004A108;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_8004A108:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addiu       $fp, $v0, -0xC8
    ctx->r30 = ADD32(ctx->r2, -0XC8);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s7, $v0, L_8004A160
    if (ctx->r23 == ctx->r2) {
        // ori         $a2, $zero, 0x5DC
        ctx->r6 = 0 | 0X5DC;
        goto L_8004A160;
    }
    // ori         $a2, $zero, 0x5DC
    ctx->r6 = 0 | 0X5DC;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A4A($v0)
    ctx->r2 = MEM_H(-0X4A4A, ctx->r2);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(0XC, ctx->r20);
    // ori         $a1, $zero, 0x1F4
    ctx->r5 = 0 | 0X1F4;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xE($s4)
    ctx->r2 = MEM_H(0XE, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // jal         0x80048874
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80048874(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // j           L_8004A27C
    // nop

    goto L_8004A27C;
    // nop

L_8004A160:
    // jal         0x80018190
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_5;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_5:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x1F4
    ctx->r5 = 0 | 0X1F4;
    // ori         $a2, $zero, 0x5DC
    ctx->r6 = 0 | 0X5DC;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // addu        $s5, $s2, $zero
    ctx->r21 = ADD32(ctx->r18, 0);
    // lwl         $v1, 0x27($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X27, ctx->r2);
    // lwr         $v1, 0x24($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X24, ctx->r2);
    // lwl         $t0, 0x2B($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X2B, ctx->r2);
    // lwr         $t0, 0x28($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X28, ctx->r2);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $t0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r8);
    // swr         $t0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r8);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x4A4A
    ctx->r8 = ADD32(ctx->r8, -0X4A4A);
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(0X0, ctx->r8);
    // lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(0X14, ctx->r2);
    // lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(0X18, ctx->r2);
    // lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(0X1C, ctx->r2);
    // lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(0X20, ctx->r2);
    // sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(0XC, ctx->r20);
    // addiu       $s2, $t0, -0x2
    ctx->r18 = ADD32(ctx->r8, -0X2);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v1, 0xE($s4)
    ctx->r3 = MEM_H(0XE, ctx->r20);
    // addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x80048874
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    sub_80048874(rdram, ctx);
    goto after_6;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_6:
    // sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
L_8004A200:
    // addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(0X80, ctx->r29);
    // jal         0x8004892C
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    sub_8004892C(rdram, ctx);
    goto after_7;
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_7:
    // sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // lhu         $t1, 0x50($sp)
    ctx->r9 = MEM_HU(0X50, ctx->r29);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9) << 16;
    // jal         0x80014D48
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80014D48(rdram, ctx);
    goto after_8;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_8:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // addiu       $s0, $s0, 0x200
    ctx->r16 = ADD32(ctx->r16, 0X200);
    // jal         0x80015D30
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    sub_80015D30(rdram, ctx);
    goto after_9;
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    after_9:
    // jal         0x80014988
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    ProcessCDAudioLoad(rdram, ctx);
    goto after_10;
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    after_10:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_12;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_12:
    // slti        $v0, $s0, 0x1001
    ctx->r2 = SIGNED(ctx->r16) < 0X1001 ? 1 : 0;
    // bne         $v0, $zero, L_8004A200
    if (ctx->r2 != 0) {
        // addiu       $a1, $sp, 0x40
        ctx->r5 = ADD32(ctx->r29, 0X40);
        goto L_8004A200;
    }
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
L_8004A27C:
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // ori         $s0, $zero, 0x100
    ctx->r16 = 0 | 0X100;
    // sh          $fp, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r30;
L_8004A288:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_13;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_13:
    // bne         $s5, $zero, L_8004A2A8
    if (ctx->r21 != 0) {
        // addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
        goto L_8004A2A8;
    }
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // beq         $s2, $zero, L_8004A2A8
    if (ctx->r18 == 0) {
        // nop
    
        goto L_8004A2A8;
    }
    // nop

    // beq         $s1, $s0, L_8004A2F8
    if (ctx->r17 == ctx->r16) {
        // nop
    
        goto L_8004A2F8;
    }
    // nop

L_8004A2A8:
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // addu        $s5, $s2, $zero
    ctx->r21 = ADD32(ctx->r18, 0);
    // lhu         $v1, 0x26($v0)
    ctx->r3 = MEM_HU(0X26, ctx->r2);
    // nop

    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // sh          $v1, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r3;
    // slti        $v0, $s1, 0x100
    ctx->r2 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // beq         $v0, $zero, L_8004A2D0
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8004A2D0;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
L_8004A2D0:
    // jal         0x80014988
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    ProcessCDAudioLoad(rdram, ctx);
    goto after_14;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    after_14:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A4C
    ctx->r5 = ADD32(ctx->r5, -0X4A4C);
    // jal         0x800360A0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_16;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
    // j           L_8004A288
    // nop

    goto L_8004A288;
    // nop

L_8004A2F8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $s2, $v0
    ctx->r2 = ctx->r18 & ctx->r2;
    // bne         $v0, $zero, L_8004A318
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A318;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s7, $v0, L_8004A44C
    if (ctx->r23 == ctx->r2) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8004A44C;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8004A318:
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // nop

    // lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(0X6, ctx->r2);
    // jal         0x80049D6C
    // nop

    InventoryAddItem(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // bne         $v0, $zero, L_8004A444
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A444;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // nop

    // lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(0X6, ctx->r2);
    // ori         $v0, $zero, 0x75
    ctx->r2 = 0 | 0X75;
    // beq         $v1, $v0, L_8004A35C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x76
        ctx->r2 = 0 | 0X76;
        goto L_8004A35C;
    }
    // ori         $v0, $zero, 0x76
    ctx->r2 = 0 | 0X76;
    // beq         $v1, $v0, L_8004A3B4
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, -0x1F4
        ctx->r4 = ADD32(0, -0X1F4);
        goto L_8004A3B4;
    }
    // addiu       $a0, $zero, -0x1F4
    ctx->r4 = ADD32(0, -0X1F4);
    // j           L_8004A3E8
    // nop

    goto L_8004A3E8;
    // nop

L_8004A35C:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sra         $v1, $v1, 15
    ctx->r3 = S32(ctx->r3) >> 15;
    // addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x211B
    ctx->r4 = ADD32(ctx->r4, -0X211B);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8004A3AC
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x63
        ctx->r2 = 0 | 0X63;
        goto L_8004A3AC;
    }
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // j           L_8004A3E4
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_8004A3E4;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004A3AC:
    // j           L_8004A3E4
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_8004A3E4;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004A3B4:
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // addiu       $v1, $v1, -0x211A
    ctx->r3 = ADD32(ctx->r3, -0X211A);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x5F
    ctx->r2 = ctx->r2 < 0X5F ? 1 : 0;
    // beq         $v0, $zero, L_8004A3DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004A3DC;
    }
    // nop

    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // j           L_8004A3E0
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    goto L_8004A3E0;
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8004A3DC:
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
L_8004A3E0:
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8004A3E4:
    // addiu       $a0, $zero, -0x1F4
    ctx->r4 = ADD32(0, -0X1F4);
L_8004A3E8:
    // ori         $a1, $zero, 0x1F4
    ctx->r5 = 0 | 0X1F4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A4A($v1)
    ctx->r3 = MEM_H(-0X4A4A, ctx->r3);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x80048874
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_80048874(rdram, ctx);
    goto after_19;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_19:
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // lwl         $v1, 0x27($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X27, ctx->r2);
    // lwr         $v1, 0x24($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X24, ctx->r2);
    // lwl         $a0, 0x2B($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X2B, ctx->r2);
    // lwr         $a0, 0x28($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X28, ctx->r2);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // j           L_8004A4A4
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    goto L_8004A4A4;
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
L_8004A444:
    // bne         $s7, $v0, L_8004A57C
    if (ctx->r23 != ctx->r2) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8004A57C;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8004A44C:
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(0X2A, ctx->r29);
    // lh          $a0, 0x26($v0)
    ctx->r4 = MEM_H(0X26, ctx->r2);
    // jal         0x80015798
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    Math_IsAngleInRange(rdram, ctx);
    goto after_20;
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    after_20:
    // bne         $v0, $zero, L_8004A494
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8004A494;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // nop

    // lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(0X26, ctx->r3);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A4C
    ctx->r5 = ADD32(ctx->r5, -0X4A4C);
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // jal         0x800360A0
    // sh          $v0, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r2;
    KF_GpuUpdate(rdram, ctx);
    goto after_21;
    // sh          $v0, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r2;
    after_21:
    // j           L_8004A44C
    // nop

    goto L_8004A44C;
    // nop

L_8004A494:
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(0X2A, ctx->r29);
    // nop

    // sh          $v0, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r2;
L_8004A4A4:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x4A4C
    ctx->r2 = ADD32(ctx->r2, -0X4A4C);
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // lwl         $v0, 0x27($v1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X27, ctx->r3);
    // lwr         $v0, 0x24($v1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X24, ctx->r3);
    // lwl         $a0, 0x2B($v1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X2B, ctx->r3);
    // lwr         $a0, 0x28($v1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X28, ctx->r3);
    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(0X80, ctx->r29);
    // lh          $s3, 0x0($s1)
    ctx->r19 = MEM_H(0X0, ctx->r17);
    // lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(0X14, ctx->r2);
    // lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(0X18, ctx->r2);
    // lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(0X1C, ctx->r2);
    // lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(0X20, ctx->r2);
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
L_8004A504:
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(0X80, ctx->r29);
    // jal         0x8004892C
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    sub_8004892C(rdram, ctx);
    goto after_22;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_22:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // jal         0x80015D30
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80015D30(rdram, ctx);
    goto after_23;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_23:
    // sll         $a0, $fp, 16
    ctx->r4 = S32(ctx->r30) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lhu         $t1, 0x50($sp)
    ctx->r9 = MEM_HU(0X50, ctx->r29);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $a1, $t1, 16
    ctx->r5 = S32(ctx->r9) << 16;
    // jal         0x80014D48
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_80014D48(rdram, ctx);
    goto after_24;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_24:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // addiu       $s0, $s0, 0x200
    ctx->r16 = ADD32(ctx->r16, 0X200);
    // jal         0x800360A0
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    KF_GpuUpdate(rdram, ctx);
    goto after_25;
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    after_25:
    // slti        $v0, $s0, 0x1001
    ctx->r2 = SIGNED(ctx->r16) < 0X1001 ? 1 : 0;
    // bne         $v0, $zero, L_8004A504
    if (ctx->r2 != 0) {
        // addiu       $a1, $sp, 0x30
        ctx->r5 = ADD32(ctx->r29, 0X30);
        goto L_8004A504;
    }
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // beq         $s2, $zero, L_8004A58C
    if (ctx->r18 == 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_8004A58C;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
L_8004A57C:
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_8004A5A8
    // sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    goto L_8004A5A8;
    // sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_8004A58C:
    // lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(0X80, ctx->r29);
    // nop

    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // nop

    // bne         $v1, $v0, L_8004A5A8
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x12
        ctx->r2 = 0 | 0X12;
        goto L_8004A5A8;
    }
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
L_8004A5A8:
    // jal         0x80027C38
    // nop

    Player_ResetMovement(rdram, ctx);
    goto after_26;
    // nop

    after_26:
L_8004A5B0:
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
