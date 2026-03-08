#include "recomp.h"
#include "disable_warnings.h"

void ApplyDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(0XDC, ctx->r29);
    // lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(0XE0, ctx->r29);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    // lhu         $s4, 0xC0($sp)
    ctx->r20 = MEM_HU(0XC0, ctx->r29);
    // sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4) << 5;
    // sw          $s6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r22;
    // lhu         $s6, 0xC4($sp)
    ctx->r22 = MEM_HU(0XC4, ctx->r29);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $fp, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r30;
    // lhu         $fp, 0xC8($sp)
    ctx->r30 = MEM_HU(0XC8, ctx->r29);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xCC($sp)
    ctx->r9 = MEM_HU(0XCC, ctx->r29);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, -0x19F8
    ctx->r4 = ADD32(ctx->r4, -0X19F8);
    // sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xD0($sp)
    ctx->r9 = MEM_HU(0XD0, ctx->r29);
    // addu        $s2, $v0, $a0
    ctx->r18 = ADD32(ctx->r2, ctx->r4);
    // sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xD4($sp)
    ctx->r9 = MEM_HU(0XD4, ctx->r29);
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // sw          $ra, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r31;
    // sw          $s7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r23;
    // sw          $s5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r19;
    // sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // sh          $t1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r9;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // lhu         $t1, 0xD8($sp)
    ctx->r9 = MEM_HU(0XD8, ctx->r29);
    // ori         $a3, $zero, 0x3
    ctx->r7 = 0 | 0X3;
    // bne         $v0, $a3, L_8003C7C4
    if (ctx->r2 != ctx->r7) {
        // sh          $t1, 0x48($sp)
        MEM_H(0X48, ctx->r29) = ctx->r9;
        goto L_8003C7C4;
    }
    // sh          $t1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r9;
    // lh          $v1, 0x22($s2)
    ctx->r3 = MEM_H(0X22, ctx->r18);
    // nop

    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s2, $v0, $a0
    ctx->r18 = ADD32(ctx->r2, ctx->r4);
L_8003C7C4:
    // lbu         $v0, 0x2($s2)
    ctx->r2 = MEM_BU(0X2, ctx->r18);
    // nop

    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addiu       $v0, $a0, 0x60E0
    ctx->r2 = ADD32(ctx->r4, 0X60E0);
    // lbu         $a0, 0xE($s2)
    ctx->r4 = MEM_BU(0XE, ctx->r18);
    // nop

    // bne         $a0, $a3, L_8003C800
    if (ctx->r4 != ctx->r7) {
        // addu        $s7, $v1, $v0
        ctx->r23 = ADD32(ctx->r3, ctx->r2);
        goto L_8003C800;
    }
    // addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x18($s2)
    ctx->r2 = MEM_HU(0X18, ctx->r18);
    // nop

    // sltiu       $v0, $v0, 0x60C
    ctx->r2 = ctx->r2 < 0X60C ? 1 : 0;
    // beq         $v0, $zero, L_8003CD68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003CD68;
    }
    // nop

L_8003C800:
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // bne         $a0, $v0, L_8003C824
    if (ctx->r4 != ctx->r2) {
        // ori         $v0, $zero, 0x1A
        ctx->r2 = 0 | 0X1A;
        goto L_8003C824;
    }
    // ori         $v0, $zero, 0x1A
    ctx->r2 = 0 | 0X1A;
    // lh          $v0, 0x70($s2)
    ctx->r2 = MEM_H(0X70, ctx->r18);
    // nop

    // bne         $v0, $zero, L_8003CD68
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8003CD68;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_8003CD68
    // sh          $v0, 0x70($s2)
    MEM_H(0X70, ctx->r18) = ctx->r2;
    goto L_8003CD68;
    // sh          $v0, 0x70($s2)
    MEM_H(0X70, ctx->r18) = ctx->r2;
L_8003C824:
    // beq         $a0, $v0, L_8003CD68
    if (ctx->r4 == ctx->r2) {
        // andi        $t1, $a2, 0x30
        ctx->r9 = ctx->r6 & 0X30;
        goto L_8003CD68;
    }
    // andi        $t1, $a2, 0x30
    ctx->r9 = ctx->r6 & 0X30;
    // sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // bne         $t1, $v0, L_8003C850
    if (ctx->r9 != ctx->r2) {
        // andi        $s3, $a2, 0x3
        ctx->r19 = ctx->r6 & 0X3;
        goto L_8003C850;
    }
    // andi        $s3, $a2, 0x3
    ctx->r19 = ctx->r6 & 0X3;
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8003CD68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD68;
    }
    // nop

L_8003C850:
    // andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // lhu         $a2, 0x20($s7)
    ctx->r6 = MEM_HU(0X20, ctx->r23);
    // andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(0X68, ctx->r29);
    // jal         0x8003C69C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // lhu         $a2, 0x22($s7)
    ctx->r6 = MEM_HU(0X22, ctx->r23);
    // andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(0X70, ctx->r29);
    // jal         0x8003C69C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // lhu         $a2, 0x24($s7)
    ctx->r6 = MEM_HU(0X24, ctx->r23);
    // andi        $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 & 0XFFFF;
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(0X78, ctx->r29);
    // jal         0x8003C69C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // lhu         $a2, 0x26($s7)
    ctx->r6 = MEM_HU(0X26, ctx->r23);
    // andi        $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 & 0XFFFF;
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(0X80, ctx->r29);
    // jal         0x8003C69C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // andi        $fp, $fp, 0xFFFF
    ctx->r30 = ctx->r30 & 0XFFFF;
    // lhu         $a2, 0x28($s7)
    ctx->r6 = MEM_HU(0X28, ctx->r23);
    // jal         0x8003C69C
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_4;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    after_4:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $s4, 0x30($sp)
    ctx->r20 = MEM_HU(0X30, ctx->r29);
    // lhu         $a2, 0x2A($s7)
    ctx->r6 = MEM_HU(0X2A, ctx->r23);
    // jal         0x8003C69C
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_5;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_5:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $s1, 0x38($sp)
    ctx->r17 = MEM_HU(0X38, ctx->r29);
    // lhu         $a2, 0x2C($s7)
    ctx->r6 = MEM_HU(0X2C, ctx->r23);
    // jal         0x8003C69C
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_6;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_6:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $s0, 0x40($sp)
    ctx->r16 = MEM_HU(0X40, ctx->r29);
    // lhu         $a2, 0x2E($s7)
    ctx->r6 = MEM_HU(0X2E, ctx->r23);
    // jal         0x8003C69C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    CalculateDamagePart(rdram, ctx);
    goto after_7;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_7:
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
    // ori         $v0, $v0, 0x8DB7
    ctx->r2 = ctx->r2 | 0X8DB7;
    // slt         $v0, $v0, $s5
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // beq         $v0, $zero, L_8003C940
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8003C940;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lui         $s5, 0x6
    ctx->r21 = S32(0X6 << 16);
    // ori         $s5, $s5, 0x8DB7
    ctx->r21 = ctx->r21 | 0X8DB7;
L_8003C940:
    // lhu         $s6, 0x48($sp)
    ctx->r22 = MEM_HU(0X48, ctx->r29);
    // nop

    // mult        $s5, $s6
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x68DB
    ctx->r2 = S32(0X68DB << 16);
    // ori         $v0, $v0, 0x8BAD
    ctx->r2 = ctx->r2 | 0X8BAD;
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(0X68, ctx->r29);
    // lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(0X78, ctx->r29);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(0X70, ctx->r29);
    // sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(0X80, ctx->r29);
    // sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, 0x79E0($v1)
    ctx->r3 = MEM_W(0X79E0, ctx->r3);
    // sra         $s5, $v0, 4
    ctx->r21 = S32(ctx->r2) >> 4;
    // lw          $v0, 0x48($v1)
    ctx->r2 = MEM_W(0X48, ctx->r3);
    // nop

    // jalr        $v0
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_8:
    // beq         $s5, $zero, L_8003CD68
    if (ctx->r21 == 0) {
        // nop
    
        goto L_8003CD68;
    }
    // nop

    // lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(0X1A, ctx->r18);
    // nop

    // beq         $v0, $zero, L_8003CA14
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003CA14;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(0X60, ctx->r29);
    // nop

    // bne         $t1, $v0, L_8003CA18
    if (ctx->r9 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8003CA18;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $s3, $v0, L_8003C9F8
    if (ctx->r19 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8003C9F8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80026B7C
    // nop

    Player_MagicPowerUp(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_8003CA18
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8003CA18;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8003C9F8:
    // bne         $s3, $v0, L_8003CA20
    if (ctx->r19 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003CA20;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sltiu       $v0, $s6, 0x9C4
    ctx->r2 = ctx->r22 < 0X9C4 ? 1 : 0;
    // bne         $v0, $zero, L_8003CA18
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8003CA18;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80026AE4
    // nop

    Player_StrengthPowerUP(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_8003CA14:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8003CA18:
    // beq         $s3, $v0, L_8003CAA0
    if (ctx->r19 == ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003CAA0;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8003CA20:
    // bne         $s3, $v0, L_8003CAC0
    if (ctx->r19 != ctx->r2) {
        // lui         $v1, 0x4
        ctx->r3 = S32(0X4 << 16);
        goto L_8003CAC0;
    }
    // lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8003CB94
    if (ctx->r2 != 0) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_8003CB94;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // jal         0x8003C184
    // ori         $a1, $zero, 0x16
    ctx->r5 = 0 | 0X16;
    EntityClass_GetActionSequence(rdram, ctx);
    goto after_11;
    // ori         $a1, $zero, 0x16
    ctx->r5 = 0 | 0X16;
    after_11:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003CAC0
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8003CAC0;
    }
    // nop

    // lw          $v1, 0x2C($s2)
    ctx->r3 = MEM_W(0X2C, ctx->r18);
    // lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(0X50, ctx->r29);
    // lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(0X34, ctx->r18);
    // lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(0X0, ctx->r9);
    // lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(0X8, ctx->r9);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_12;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_12:
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lh          $a0, 0x42($s2)
    ctx->r4 = MEM_H(0X42, ctx->r18);
    // jal         0x80015798
    // ori         $a2, $zero, 0x200
    ctx->r6 = 0 | 0X200;
    Math_IsAngleInRange(rdram, ctx);
    goto after_13;
    // ori         $a2, $zero, 0x200
    ctx->r6 = 0 | 0X200;
    after_13:
    // beq         $v0, $zero, L_8003CAC0
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8003CAC0;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8003BB60
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Entity_ApplySequence(rdram, ctx);
    goto after_14;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_14:
    // j           L_8003CB94
    // nop

    goto L_8003CB94;
    // nop

L_8003CAA0:
    // lbu         $v1, 0xE($s2)
    ctx->r3 = MEM_BU(0XE, ctx->r18);
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // bne         $v1, $v0, L_8003CAC0
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003CAC0;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lh          $v1, 0x70($s2)
    ctx->r3 = MEM_H(0X70, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8003CB94
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003CB94;
    }
    // nop

L_8003CAC0:
    // lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(0X1A, ctx->r18);
    // nop

    // subu        $s6, $v0, $s5
    ctx->r22 = SUB32(ctx->r2, ctx->r21);
    // bgtz        $s6, L_8003CB0C
    if (SIGNED(ctx->r22) > 0) {
        // addiu       $s4, $s7, 0x38
        ctx->r20 = ADD32(ctx->r23, 0X38);
        goto L_8003CB0C;
    }
    // addiu       $s4, $s7, 0x38
    ctx->r20 = ADD32(ctx->r23, 0X38);
    // beq         $v0, $zero, L_8003CAF8
    if (ctx->r2 == 0) {
        // addu        $s6, $zero, $zero
        ctx->r22 = ADD32(0, 0);
        goto L_8003CAF8;
    }
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(0X60, ctx->r29);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // bne         $t1, $v0, L_8003CAFC
    if (ctx->r9 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8003CAFC;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lh          $a0, 0x1E($s7)
    ctx->r4 = MEM_H(0X1E, ctx->r23);
    // jal         0x80026C14
    // nop

    Player_LevelUp(rdram, ctx);
    goto after_15;
    // nop

    after_15:
L_8003CAF8:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8003CAFC:
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    Entity_ChangeState(rdram, ctx);
    goto after_16;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    after_16:
    // j           L_8003CB94
    // sh          $s6, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r22;
    goto L_8003CB94;
    // sh          $s6, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r22;
L_8003CB0C:
    // ori         $s3, $zero, 0xF
    ctx->r19 = 0 | 0XF;
    // ori         $fp, $zero, 0x2
    ctx->r30 = 0 | 0X2;
L_8003CB14:
    // lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(0X0, ctx->r20);
    // nop

    // beq         $s0, $zero, L_8003CB90
    if (ctx->r16 == 0) {
        // addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
        goto L_8003CB90;
    }
    // addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $fp, L_8003CB80
    if (ctx->r2 != ctx->r30) {
        // nop
    
        goto L_8003CB80;
    }
    // nop

    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // slt         $v0, $s5, $v0
    ctx->r2 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003CB80
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8003CB80;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $s1, 0x2($s0)
    ctx->r17 = MEM_BU(0X2, ctx->r16);
    // nop

    // beq         $s1, $v0, L_8003CB70
    if (ctx->r17 == ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8003CB70;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // beq         $v0, $zero, L_8003CB80
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8003CB80;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8003CB70:
    // jal         0x8003BB60
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Entity_ApplySequence(rdram, ctx);
    goto after_18;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_18:
    // j           L_8003CB94
    // sh          $s6, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r22;
    goto L_8003CB94;
    // sh          $s6, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r22;
L_8003CB80:
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s3, $v0, L_8003CB14
    if (ctx->r19 != ctx->r2) {
        // nop
    
        goto L_8003CB14;
    }
    // nop

L_8003CB90:
    // sh          $s6, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r22;
L_8003CB94:
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8003CBEC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003CBEC;
    }
    // nop

    // lh          $v1, 0x22($s2)
    ctx->r3 = MEM_H(0X22, ctx->r18);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, -0x19F8
    ctx->r4 = ADD32(ctx->r4, -0X19F8);
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lbu         $s0, 0x60E2($a0)
    ctx->r16 = MEM_BU(0X60E2, ctx->r4);
    // j           L_8003CBF0
    // nop

    goto L_8003CBF0;
    // nop

L_8003CBEC:
    // lbu         $s0, 0x2($s7)
    ctx->r16 = MEM_BU(0X2, ctx->r23);
L_8003CBF0:
    // lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(0X50, ctx->r29);
    // nop

    // beq         $t1, $zero, L_8003CD60
    if (ctx->r9 == 0) {
        // slti        $v0, $s0, 0xF0
        ctx->r2 = SIGNED(ctx->r16) < 0XF0 ? 1 : 0;
        goto L_8003CD60;
    }
    // slti        $v0, $s0, 0xF0
    ctx->r2 = SIGNED(ctx->r16) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_8003CD60
    if (ctx->r2 == 0) {
        // addiu       $a3, $sp, 0x28
        ctx->r7 = ADD32(ctx->r29, 0X28);
        goto L_8003CD60;
    }
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(0X2C, ctx->r18);
    // lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(0X0, ctx->r9);
    // lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(0X30, ctx->r18);
    // lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(0X34, ctx->r18);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x1E($s2)
    ctx->r2 = MEM_HU(0X1E, ctx->r18);
    // lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(0X8, ctx->r9);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(0X4, ctx->r9);
    // subu        $a2, $v1, $a2
    ctx->r6 = SUB32(ctx->r3, ctx->r6);
    // jal         0x800159DC
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    Math_VectorToAngles(rdram, ctx);
    goto after_19;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    after_19:
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // addiu       $s1, $s2, 0x50
    ctx->r17 = ADD32(ctx->r18, 0X50);
    // jal         0x80015538
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_20;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_20:
    // jal         0x8005DBCC
    // sll         $a0, $s5, 11
    ctx->r4 = S32(ctx->r21) << 11;
    KF_SquareRoot0(rdram, ctx);
    goto after_21;
    // sll         $a0, $s5, 11
    ctx->r4 = S32(ctx->r21) << 11;
    after_21:
    // jal         0x8005DBCC
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    KF_SquareRoot0(rdram, ctx);
    goto after_22;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_22:
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // div         $zero, $v0, $s0
	if (ctx->r16 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
	}
	else
	{
		lo = 0;
		hi = 0;
	}
    
    // bne         $s0, $zero, L_8003CC70
    if (ctx->r16 != 0) {
        // nop
    
        goto L_8003CC70;
    }
    // nop

    // break       7
    do_break(2147732588);
L_8003CC70:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_8003CC88
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003CC88;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003CC88
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003CC88;
    }
    // nop

    // break       6
    do_break(2147732612);
L_8003CC88:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // bne         $s0, $zero, L_8003CCA4
    if (ctx->r16 != 0) {
        // nop
    
        goto L_8003CCA4;
    }
    // nop

    // break       7
    do_break(2147732640);
L_8003CCA4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_8003CCBC
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003CCBC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003CCBC
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003CCBC;
    }
    // nop

    // break       6
    do_break(2147732664);
L_8003CCBC:
    // mflo        $s5
    ctx->r21 = lo;
    // nop

    // slti        $v0, $s5, 0x201
    ctx->r2 = SIGNED(ctx->r21) < 0X201 ? 1 : 0;
    // bne         $v0, $zero, L_8003CCD8
    if (ctx->r2 != 0) {
        // sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) << 16;
        goto L_8003CCD8;
    }
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // ori         $s5, $zero, 0x200
    ctx->r21 = 0 | 0X200;
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
L_8003CCD8:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80015694
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_80015694(rdram, ctx);
    goto after_23;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_23:
    // lhu         $v0, 0x50($s2)
    ctx->r2 = MEM_HU(0X50, ctx->r18);
    // lhu         $v1, 0x54($s2)
    ctx->r3 = MEM_HU(0X54, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 19
    ctx->r2 = S32(ctx->r2) >> 19;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x52($s2)
    ctx->r2 = MEM_HU(0X52, ctx->r18);
    // sra         $v1, $v1, 19
    ctx->r3 = S32(ctx->r3) >> 19;
    // sh          $v1, 0x54($s2)
    MEM_H(0X54, ctx->r18) = ctx->r3;
    // lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(0X28, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 22
    ctx->r2 = S32(ctx->r2) >> 22;
    // andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // beq         $v1, $zero, L_8003CD60
    if (ctx->r3 == 0) {
        // sh          $v0, 0x52($s2)
        MEM_H(0X52, ctx->r18) = ctx->r2;
        goto L_8003CD60;
    }
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x50($s2)
    ctx->r2 = MEM_HU(0X50, ctx->r18);
    // lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(0X58, ctx->r29);
    // nop

    // sh          $v0, 0x50($t1)
    MEM_H(0X50, ctx->r9) = ctx->r2;
    // lhu         $v0, 0x52($s2)
    ctx->r2 = MEM_HU(0X52, ctx->r18);
    // lbu         $v1, 0xE($t1)
    ctx->r3 = MEM_BU(0XE, ctx->r9);
    // sh          $v0, 0x52($t1)
    MEM_H(0X52, ctx->r9) = ctx->r2;
    // lhu         $v0, 0x54($s2)
    ctx->r2 = MEM_HU(0X54, ctx->r18);
    // nop

    // sh          $v0, 0x54($t1)
    MEM_H(0X54, ctx->r9) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_8003CD64
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003CD64;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(0X58, ctx->r29);
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    Entity_ChangeState(rdram, ctx);
    goto after_24;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    after_24:
L_8003CD60:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
L_8003CD64:
    // sb          $v0, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r2;
L_8003CD68:
    // lw          $ra, 0xAC($sp)
    ctx->r31 = MEM_W(0XAC, ctx->r29);
    // lw          $fp, 0xA8($sp)
    ctx->r30 = MEM_W(0XA8, ctx->r29);
    // lw          $s7, 0xA4($sp)
    ctx->r23 = MEM_W(0XA4, ctx->r29);
    // lw          $s6, 0xA0($sp)
    ctx->r22 = MEM_W(0XA0, ctx->r29);
    // lw          $s5, 0x9C($sp)
    ctx->r21 = MEM_W(0X9C, ctx->r29);
    // lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(0X98, ctx->r29);
    // lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(0X94, ctx->r29);
    // lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(0X90, ctx->r29);
    // lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(0X8C, ctx->r29);
    // lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(0X88, ctx->r29);
    // addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // jr          $ra
    // nop

    return;
    // nop

;}
