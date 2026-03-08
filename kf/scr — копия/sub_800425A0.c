#include "recomp.h"
#include "disable_warnings.h"

void sub_800425A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // lw          $s3, 0xC8($sp)
    ctx->r19 = MEM_W(0XC8, ctx->r29);
    // and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // lbu         $v1, 0xA0($sp)
    ctx->r3 = MEM_BU(0XA0, ctx->r29);
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // lhu         $s4, 0xA4($sp)
    ctx->r20 = MEM_HU(0XA4, ctx->r29);
    // sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // lhu         $s5, 0xA8($sp)
    ctx->r21 = MEM_HU(0XA8, ctx->r29);
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // lhu         $s6, 0xAC($sp)
    ctx->r22 = MEM_HU(0XAC, ctx->r29);
    // sh          $a3, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r7;
    // lhu         $a3, 0xB0($sp)
    ctx->r7 = MEM_HU(0XB0, ctx->r29);
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // lhu         $s7, 0xB4($sp)
    ctx->r23 = MEM_HU(0XB4, ctx->r29);
    // lui         $v0, 0xFFF0
    ctx->r2 = S32(0XFFF0 << 16);
    // sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // lhu         $fp, 0xB8($sp)
    ctx->r30 = MEM_HU(0XB8, ctx->r29);
    // lhu         $t0, 0xBC($sp)
    ctx->r8 = MEM_HU(0XBC, ctx->r29);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
    // lhu         $t0, 0xC0($sp)
    ctx->r8 = MEM_HU(0XC0, ctx->r29);
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // sh          $t0, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r8;
    // lhu         $t0, 0xC4($sp)
    ctx->r8 = MEM_HU(0XC4, ctx->r29);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // bne         $a0, $v0, L_8004267C
    if (ctx->r4 != ctx->r2) {
        // sh          $t0, 0x58($sp)
        MEM_H(0X58, ctx->r29) = ctx->r8;
        goto L_8004267C;
    }
    // sh          $t0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r8;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // lhu         $t0, 0x48($sp)
    ctx->r8 = MEM_HU(0X48, ctx->r29);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x50($sp)
    ctx->r8 = MEM_HU(0X50, ctx->r29);
    // nop

    // sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x58($sp)
    ctx->r8 = MEM_HU(0X58, ctx->r29);
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // jal         0x80027344
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    ApplyStatusEffect(rdram, ctx);
    goto after_0;
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // j           L_80042794
    // nop

    goto L_80042794;
    // nop

L_8004267C:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // bne         $a0, $v0, L_80042794
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80042794;
    }
    // nop

    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A68($v1)
    ctx->r3 = MEM_W(-0X2A68, ctx->r3);
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
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // addiu       $a0, $a0, 0x60E0
    ctx->r4 = ADD32(ctx->r4, 0X60E0);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // beq         $s3, $zero, L_80042700
    if (ctx->r19 == 0) {
        // addu        $s2, $v0, $a0
        ctx->r18 = ADD32(ctx->r2, ctx->r4);
        goto L_80042700;
    }
    // addu        $s2, $v0, $a0
    ctx->r18 = ADD32(ctx->r2, ctx->r4);
    // lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(0X2C, ctx->r17);
    // lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(0X0, ctx->r19);
    // lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(0X34, ctx->r17);
    // lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(0X8, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_1;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_1:
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lh          $a0, 0x42($s1)
    ctx->r4 = MEM_H(0X42, ctx->r17);
    // lh          $a2, 0x18($s2)
    ctx->r6 = MEM_H(0X18, ctx->r18);
    // jal         0x80015798
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_2;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    after_2:
    // beq         $v0, $zero, L_80042794
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80042794;
    }
    // nop

L_80042700:
    // lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(0X60, ctx->r29);
    // lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // and         $v0, $t0, $v0
    ctx->r2 = ctx->r8 & ctx->r2;
    // beq         $v0, $zero, L_8004271C
    if (ctx->r2 == 0) {
        // andi        $s0, $s0, 0x30
        ctx->r16 = ctx->r16 & 0X30;
        goto L_8004271C;
    }
    // andi        $s0, $s0, 0x30
    ctx->r16 = ctx->r16 & 0X30;
    // j           L_80042720
    // ori         $s0, $s0, 0x1
    ctx->r16 = ctx->r16 | 0X1;
    goto L_80042720;
    // ori         $s0, $s0, 0x1
    ctx->r16 = ctx->r16 | 0X1;
L_8004271C:
    // ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
L_80042720:
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // lhu         $a1, 0x40($sp)
    ctx->r5 = MEM_HU(0X40, ctx->r29);
    // lhu         $t0, 0x48($sp)
    ctx->r8 = MEM_HU(0X48, ctx->r29);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $a0, -0x2A68($a0)
    ctx->r4 = MEM_HU(-0X2A68, ctx->r4);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x50($sp)
    ctx->r8 = MEM_HU(0X50, ctx->r29);
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x58($sp)
    ctx->r8 = MEM_HU(0X58, ctx->r29);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // jal         0x8003C718
    // sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    ApplyDamage(rdram, ctx);
    goto after_3;
    // sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_3:
    // lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(0X60, ctx->r29);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // and         $v0, $t0, $v0
    ctx->r2 = ctx->r8 & ctx->r2;
    // beq         $v0, $zero, L_80042794
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80042794;
    }
    // nop

    // lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(0X28, ctx->r17);
    // nop

    // ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
L_80042794:
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
