#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sll         $v1, $a1, 6
    ctx->r3 = S32(ctx->r5) << 6;
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // addiu       $s7, $s7, -0x4A64
    ctx->r23 = ADD32(ctx->r23, -0X4A64);
    // sll         $t0, $a2, 5
    ctx->r8 = S32(ctx->r6) << 5;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // sll         $s2, $a3, 4
    ctx->r18 = S32(ctx->r7) << 4;
    // sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(0X0, ctx->r23);
    // lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // lw          $s1, 0x79B4($s1)
    ctx->r17 = MEM_W(0X79B4, ctx->r17);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A60($a2)
    ctx->r6 = MEM_W(-0X4A60, ctx->r6);
    // lhu         $s3, 0x78($sp)
    ctx->r19 = MEM_HU(0X78, ctx->r29);
    // lhu         $s4, 0x7C($sp)
    ctx->r20 = MEM_HU(0X7C, ctx->r29);
    // lhu         $s5, 0x80($sp)
    ctx->r21 = MEM_HU(0X80, ctx->r29);
    // lhu         $s6, 0x84($sp)
    ctx->r22 = MEM_HU(0X84, ctx->r29);
    // lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(0X2C, ctx->r17);
    // sll         $s0, $a0, 6
    ctx->r16 = S32(ctx->r4) << 6;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(0X30, ctx->r17);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4A5C($a3)
    ctx->r7 = MEM_W(-0X4A5C, ctx->r7);
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(0X34, ctx->r17);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80015A88
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    GetDistanceIfInRange(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8003D1CC
    if (ctx->r3 == ctx->r2) {
        // slt         $v0, $v1, $s0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
        goto L_8003D1CC;
    }
    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8003D1D0
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8003D1D0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(0X0, ctx->r23);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(0X38, ctx->r29);
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
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) << 16;
    // lh          $a0, 0x42($s1)
    ctx->r4 = MEM_H(0X42, ctx->r17);
    // jal         0x80015798
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_2;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_2:
    // beq         $v0, $zero, L_8003D1CC
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8003D1CC;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // jal         0x80027344
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    ApplyStatusEffect(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // j           L_8003D1D0
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8003D1D0;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8003D1CC:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003D1D0:
    // lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(0X60, ctx->r29);
    // lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
