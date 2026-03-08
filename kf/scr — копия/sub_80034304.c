#include "recomp.h"
#include "disable_warnings.h"

void sub_80034304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // sw          $s4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r20;
    // lw          $s4, 0x118($sp)
    ctx->r20 = MEM_W(0X118, ctx->r29);
    // sw          $s7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r23;
    // lbu         $s7, 0x114($sp)
    ctx->r23 = MEM_BU(0X114, ctx->r29);
    // sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // lw          $s1, 0xF8($sp)
    ctx->r17 = MEM_W(0XF8, ctx->r29);
    // lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(0XFC, ctx->r29);
    // sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // lw          $s6, 0x100($sp)
    ctx->r22 = MEM_W(0X100, ctx->r29);
    // sw          $s5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r21;
    // lhu         $s5, 0x110($sp)
    ctx->r21 = MEM_HU(0X110, ctx->r29);
    // sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $fp, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r30;
    // addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x104($sp)
    ctx->r8 = MEM_HU(0X104, ctx->r29);
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // sh          $t0, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x108($sp)
    ctx->r8 = MEM_HU(0X108, ctx->r29);
    // lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // addiu       $s2, $s2, 0x4ECC
    ctx->r18 = ADD32(ctx->r18, 0X4ECC);
    // sh          $t0, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r8;
    // lbu         $t0, 0x10C($sp)
    ctx->r8 = MEM_BU(0X10C, ctx->r29);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
    // sh          $a1, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r5;
    // jal         0x8005E0F8
    // sb          $t0, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r8;
    KF_SetRotMatrix(rdram, ctx);
    goto after_0;
    // sb          $t0, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r8;
    after_0:
    // jal         0x8005E188
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    KF_SetTransMatrix(rdram, ctx);
    goto after_1;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // beq         $s6, $zero, L_8003445C
    if (ctx->r22 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8003445C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F2C($v1)
    ctx->r3 = MEM_HU(0X4F2C, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F30($v1)
    ctx->r3 = MEM_HU(0X4F30, ctx->r3);
    // addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F34($v1)
    ctx->r3 = MEM_HU(0X4F34, ctx->r3);
    // addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x8005F348
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    sub_8005F348(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80034434
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80034434;
    }
    // nop

    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_80034434:
    // lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(0X4, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // j           L_800344EC
    // addiu       $v0, $s2, 0x2D8
    ctx->r2 = ADD32(ctx->r18, 0X2D8);
    goto L_800344EC;
    // addiu       $v0, $s2, 0x2D8
    ctx->r2 = ADD32(ctx->r18, 0X2D8);
L_8003445C:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4F34($v1)
    ctx->r3 = MEM_W(0X4F34, ctx->r3);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x4F2C($a0)
    ctx->r4 = MEM_W(0X4F2C, ctx->r4);
    // sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4A14($a0)
    ctx->r4 = MEM_HU(-0X4A14, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // addiu       $at, $at, -0x4288
    ctx->r1 = ADD32(ctx->r1, -0X4288);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // nop

    // andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v1, $s2, 0x2D8
    ctx->r3 = ADD32(ctx->r18, 0X2D8);
L_800344EC:
    // addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // bne         $v1, $v0, L_80034508
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80034508;
    }
    // nop

    // j           L_8003451C
    // ori         $s7, $zero, 0xFF
    ctx->r23 = 0 | 0XFF;
    goto L_8003451C;
    // ori         $s7, $zero, 0xFF
    ctx->r23 = 0 | 0XFF;
L_80034508:
    // lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(0X1A, ctx->r29);
    // nop

    // bgtz        $v0, L_80034520
    if (SIGNED(ctx->r2) > 0) {
        // addu        $a0, $fp, $zero
        ctx->r4 = ADD32(ctx->r30, 0);
        goto L_80034520;
    }
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addiu       $s4, $s4, 0xF0
    ctx->r20 = ADD32(ctx->r20, 0XF0);
L_8003451C:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
L_80034520:
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // jal         0x80015460
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015460(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // beq         $s1, $zero, L_8003455C
    if (ctx->r17 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003455C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(0X0, ctx->r17);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(0X2, ctx->r17);
    // nop

    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s1)
    ctx->r2 = MEM_H(0X4, ctx->r17);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // jal         0x8005DFD4
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    KF_ScaleMatrix(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
L_8003455C:
    // lbu         $v1, 0xB8($sp)
    ctx->r3 = MEM_BU(0XB8, ctx->r29);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80034690
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_80034690;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0x51A4
    ctx->r3 = ADD32(ctx->r3, 0X51A4);
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x50($s3)
    ctx->r3 = MEM_H(0X50, ctx->r19);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_800345B8
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $s3, 0x50
        ctx->r5 = ADD32(ctx->r19, 0X50);
        goto L_800345B8;
    }
    // addiu       $a1, $s3, 0x50
    ctx->r5 = ADD32(ctx->r19, 0X50);
    // addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sll         $a3, $s5, 16
    ctx->r7 = S32(ctx->r21) << 16;
    // jal         0x80015D70
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    LerpRotationMatrix(rdram, ctx);
    goto after_5;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_5:
    // j           L_800345BC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_800345BC;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800345B8:
    // addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
L_800345BC:
    // jal         0x8005E158
    // nop

    KF_SetColorMatrix(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lh          $v1, 0x0($s3)
    ctx->r3 = MEM_H(0X0, ctx->r19);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_800345D8
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800345D8;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_800345D8:
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // jal         0x800611CC
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    sub_800611CC(rdram, ctx);
    goto after_7;
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_7:
    // lh          $a1, 0x66($s3)
    ctx->r5 = MEM_H(0X66, ctx->r19);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a1, $v0, L_80034608
    if (ctx->r5 == ctx->r2) {
        // sll         $a2, $s5, 16
        ctx->r6 = S32(ctx->r21) << 16;
        goto L_80034608;
    }
    // sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21) << 16;
    // lh          $a0, 0x66($s2)
    ctx->r4 = MEM_H(0X66, ctx->r18);
    // jal         0x80015D18
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    FixedPointLerp(rdram, ctx);
    goto after_8;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_8:
    // j           L_8003460C
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    goto L_8003460C;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80034608:
    // lh          $a0, 0x66($s2)
    ctx->r4 = MEM_H(0X66, ctx->r18);
L_8003460C:
    // jal         0x8002FBC0
    // nop

    sub_8002FBC0(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lbu         $a1, 0x62($s3)
    ctx->r5 = MEM_BU(0X62, ctx->r19);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a1, $v0, L_80034674
    if (ctx->r5 == ctx->r2) {
        // sll         $s0, $s5, 16
        ctx->r16 = S32(ctx->r21) << 16;
        goto L_80034674;
    }
    // sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // lbu         $a0, 0x62($s2)
    ctx->r4 = MEM_BU(0X62, ctx->r18);
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_10;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lbu         $a0, 0x63($s2)
    ctx->r4 = MEM_BU(0X63, ctx->r18);
    // lbu         $a1, 0x63($s3)
    ctx->r5 = MEM_BU(0X63, ctx->r19);
    // jal         0x80015D18
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    FixedPointLerp(rdram, ctx);
    goto after_11;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_11:
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lbu         $a0, 0x64($s2)
    ctx->r4 = MEM_BU(0X64, ctx->r18);
    // lbu         $a1, 0x64($s3)
    ctx->r5 = MEM_BU(0X64, ctx->r19);
    // jal         0x80015D18
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    FixedPointLerp(rdram, ctx);
    goto after_12;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_12:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x8005DAD0
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    KF_SetBackColor(rdram, ctx);
    goto after_13;
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_13:
    // j           L_800346C8
    // nop

    goto L_800346C8;
    // nop

L_80034674:
    // lbu         $a0, 0x62($s2)
    ctx->r4 = MEM_BU(0X62, ctx->r18);
    // lbu         $a1, 0x63($s2)
    ctx->r5 = MEM_BU(0X63, ctx->r18);
    // lbu         $a2, 0x64($s2)
    ctx->r6 = MEM_BU(0X64, ctx->r18);
    // jal         0x8005DAD0
    // nop

    KF_SetBackColor(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // j           L_800346C8
    // nop

    goto L_800346C8;
    // nop

L_80034690:
    // jal         0x8005E158
    // addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    KF_SetColorMatrix(rdram, ctx);
    goto after_15;
    // addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    after_15:
    // lh          $a0, 0x66($s2)
    ctx->r4 = MEM_H(0X66, ctx->r18);
    // jal         0x8002FBC0
    // nop

    sub_8002FBC0(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lbu         $a0, 0x62($s2)
    ctx->r4 = MEM_BU(0X62, ctx->r18);
    // lbu         $a1, 0x63($s2)
    ctx->r5 = MEM_BU(0X63, ctx->r18);
    // lbu         $a2, 0x64($s2)
    ctx->r6 = MEM_BU(0X64, ctx->r18);
    // jal         0x8005DAD0
    // nop

    KF_SetBackColor(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x800611CC
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    sub_800611CC(rdram, ctx);
    goto after_18;
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_18:
L_800346C8:
    // jal         0x8005E128
    // addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    KF_SetLightMatrix(rdram, ctx);
    goto after_19;
    // addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_19:
    // beq         $s6, $zero, L_800346E0
    if (ctx->r22 == 0) {
        // addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
        goto L_800346E0;
    }
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // jal         0x8005DDF8
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    sub_8005DDF8(rdram, ctx);
    goto after_20;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_20:
L_800346E0:
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // jal         0x8005E0F8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_SetRotMatrix(rdram, ctx);
    goto after_21;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_21:
    // jal         0x8005E188
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_SetTransMatrix(rdram, ctx);
    goto after_22;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_22:
    // lhu         $s3, 0x98($sp)
    ctx->r19 = MEM_HU(0X98, ctx->r29);
    // jal         0x80036594
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_23;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_23:
    // lhu         $s2, 0xA8($sp)
    ctx->r18 = MEM_HU(0XA8, ctx->r29);
    // nop

    // sltiu       $v0, $s2, 0x80
    ctx->r2 = ctx->r18 < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_80034758
    if (ctx->r2 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_80034758;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // jal         0x8002FFD4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_24;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_24:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(0XA0, ctx->r29);
    // lhu         $t0, 0xB0($sp)
    ctx->r8 = MEM_HU(0XB0, ctx->r29);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // jal         0x80036B08
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    SubmitDisplayListToGPU(rdram, ctx);
    goto after_25;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_25:
    // bne         $v0, $zero, L_8003477C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003477C;
    }
    // nop

    // jal         0x80030008
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80030008(rdram, ctx);
    goto after_26;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_26:
    // j           L_8003477C
    // nop

    goto L_8003477C;
    // nop

L_80034758:
    // lhu         $t0, 0xA8($sp)
    ctx->r8 = MEM_HU(0XA8, ctx->r29);
    // nop

    // andi        $s1, $t0, 0x7F
    ctx->r17 = ctx->r8 & 0X7F;
    // andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // jal         0x80030008
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80030008(rdram, ctx);
    goto after_27;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_27:
    // jal         0x8002FFD4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_28;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_28:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8003477C:
    // beq         $s6, $zero, L_80034798
    if (ctx->r22 == 0) {
        // nop
    
        goto L_80034798;
    }
    // nop

    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x80030474
    // nop

    sub_80030474(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // j           L_800347A8
    // andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
    goto L_800347A8;
    // andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
L_80034798:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x800307E8
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    sub_800307E8(rdram, ctx);
    goto after_30;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_30:
    // andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
L_800347A8:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_800347C8
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_800347C8;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80031034
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    sub_80031034(rdram, ctx);
    goto after_31;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_31:
    // j           L_800347F0
    // nop

    goto L_800347F0;
    // nop

L_800347C8:
    // bne         $v1, $v0, L_800347E4
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800347E4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x800322FC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_RenderTMD02(rdram, ctx);
    goto after_32;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_32:
    // j           L_800347F0
    // nop

    goto L_800347F0;
    // nop

L_800347E4:
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x80030924
    // andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    sub_80030924(rdram, ctx);
    goto after_33;
    // andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    after_33:
L_800347F0:
    // lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(0XE4, ctx->r29);
    // lw          $fp, 0xE0($sp)
    ctx->r30 = MEM_W(0XE0, ctx->r29);
    // lw          $s7, 0xDC($sp)
    ctx->r23 = MEM_W(0XDC, ctx->r29);
    // lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(0XD8, ctx->r29);
    // lw          $s5, 0xD4($sp)
    ctx->r21 = MEM_W(0XD4, ctx->r29);
    // lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(0XD0, ctx->r29);
    // lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(0XCC, ctx->r29);
    // lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(0XC8, ctx->r29);
    // lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(0XC4, ctx->r29);
    // lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(0XC0, ctx->r29);
    // addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // jr          $ra
    // nop

    return;
    // nop

;}
