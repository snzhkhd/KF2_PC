#include "recomp.h"
#include "disable_warnings.h"

void sub_8004435C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // lw          $s1, 0x1184($s1)
    ctx->r17 = MEM_W(0X1184, ctx->r17);
    // sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(0X7C, ctx->r29);
    // sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(0X84, ctx->r29);
    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80044468
    if (ctx->r2 == 0) {
        // addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
        goto L_80044468;
    }
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // ori         $a3, $zero, 0x5DC0
    ctx->r7 = 0 | 0X5DC0;
    // lh          $a1, 0x26($s1)
    ctx->r5 = MEM_H(0X26, ctx->r17);
    // lh          $a2, 0x24($s1)
    ctx->r6 = MEM_H(0X24, ctx->r17);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x8003D200
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8003D200(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_800444B4
    if (ctx->r4 == 0) {
        // nop
    
        goto L_800444B4;
    }
    // nop

    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(0X1E, ctx->r4);
    // lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(0X30, ctx->r4);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(0X34, ctx->r4);
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80044408:
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(0X14, ctx->r17);
    // lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(0X24, ctx->r29);
    // lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(0X18, ctx->r17);
    // lw          $a2, 0x1C($s1)
    ctx->r6 = MEM_W(0X1C, ctx->r17);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x800159DC
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    Math_VectorToAngles(rdram, ctx);
    goto after_1;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_1:
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // lh          $a0, 0x24($s1)
    ctx->r4 = MEM_H(0X24, ctx->r17);
    // lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(0X30, ctx->r29);
    // jal         0x80014C84
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80014C84(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // lh          $a0, 0x26($s1)
    ctx->r4 = MEM_H(0X26, ctx->r17);
    // sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    // lh          $a1, 0x32($sp)
    ctx->r5 = MEM_H(0X32, ctx->r29);
    // jal         0x80014C84
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80014C84(rdram, ctx);
    goto after_3;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // j           L_800444B4
    // sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    goto L_800444B4;
    // sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
L_80044468:
    // addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // ori         $a2, $zero, 0x5DC0
    ctx->r6 = 0 | 0X5DC0;
    // lh          $a1, 0x26($s1)
    ctx->r5 = MEM_H(0X26, ctx->r17);
    // jal         0x80027D54
    // ori         $a3, $zero, 0x1000
    ctx->r7 = 0 | 0X1000;
    sub_80027D54(rdram, ctx);
    goto after_4;
    // ori         $a3, $zero, 0x1000
    ctx->r7 = 0 | 0X1000;
    after_4:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_800444B4
    if (ctx->r2 == ctx->r3) {
        // sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
        goto L_800444B4;
    }
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // j           L_80044408
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    goto L_80044408;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800444B4:
    // addiu       $a0, $s1, 0x24
    ctx->r4 = ADD32(ctx->r17, 0X24);
    // jal         0x80015538
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_5;
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_5:
    // lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(0X40, ctx->r29);
    // nop

    // bltz        $v0, L_800444E0
    if (SIGNED(ctx->r2) < 0) {
        // addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
        goto L_800444E0;
    }
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // slt         $v0, $s5, $v0
    ctx->r2 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800444E4
    if (ctx->r2 != 0) {
        // addiu       $v0, $sp, 0x38
        ctx->r2 = ADD32(ctx->r29, 0X38);
        goto L_800444E4;
    }
    // addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(0X80, ctx->r29);
L_800444E0:
    // addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
L_800444E4:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(0X78, ctx->r29);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // jal         0x80044184
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80044184(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(0X60, ctx->r29);
    // lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(0X5C, ctx->r29);
    // lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(0X58, ctx->r29);
    // lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(0X54, ctx->r29);
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
