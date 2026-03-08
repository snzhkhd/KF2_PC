#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // addiu       $s2, $s2, -0x19F8
    ctx->r18 = ADD32(ctx->r18, -0X19F8);
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // addiu       $s7, $s7, 0x79A8
    ctx->r23 = ADD32(ctx->r23, 0X79A8);
    // sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $s0, $s2, 0x1E
    ctx->r16 = ADD32(ctx->r18, 0X1E);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
L_8003D644:
    // lbu         $v1, -0x15($s0)
    ctx->r3 = MEM_BU(-0X15, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8003D6FC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003D6FC;
    }
    // nop

    // lbu         $v0, 0x0($s7)
    ctx->r2 = MEM_BU(0X0, ctx->r23);
    // lw          $v1, 0xA($s0)
    ctx->r3 = MEM_W(0XA, ctx->r16);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8003D6FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003D6FC;
    }
    // nop

    // lw          $v0, 0xC($s7)
    ctx->r2 = MEM_W(0XC, ctx->r23);
    // nop

    // beq         $s2, $v0, L_8003D6FC
    if (ctx->r18 == ctx->r2) {
        // andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
        goto L_8003D6FC;
    }
    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_8003D6C8
    if (ctx->r2 == 0) {
        // addiu       $a0, $s2, 0x2C
        ctx->r4 = ADD32(ctx->r18, 0X2C);
        goto L_8003D6C8;
    }
    // addiu       $a0, $s2, 0x2C
    ctx->r4 = ADD32(ctx->r18, 0X2C);
    // lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(0X4, ctx->r16);
    // lw          $v0, 0x18($s7)
    ctx->r2 = MEM_W(0X18, ctx->r23);
    // nop

    // beq         $v1, $v0, L_8003D6FC
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8003D6FC;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // lw          $v0, 0xE($s0)
    ctx->r2 = MEM_W(0XE, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lw          $v0, 0x16($s0)
    ctx->r2 = MEM_W(0X16, ctx->r16);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(0X8, ctx->r16);
    // lw          $v1, 0x12($s0)
    ctx->r3 = MEM_W(0X12, ctx->r16);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8003D6D0
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    goto L_8003D6D0;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8003D6C8:
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
L_8003D6D0:
    // lhu         $v0, -0x2($s0)
    ctx->r2 = MEM_HU(-0X2, ctx->r16);
    // lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(0X68, ctx->r29);
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // jal         0x80015A88
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    GetDistanceIfInRange(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // bne         $v0, $fp, L_8003D714
    if (ctx->r2 != ctx->r30) {
        // addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
        goto L_8003D714;
    }
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8003D6FC:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // slti        $v0, $s1, 0xC8
    ctx->r2 = SIGNED(ctx->r17) < 0XC8 ? 1 : 0;
    // bne         $v0, $zero, L_8003D644
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x7C
        ctx->r18 = ADD32(ctx->r18, 0X7C);
        goto L_8003D644;
    }
    // addiu       $s2, $s2, 0x7C
    ctx->r18 = ADD32(ctx->r18, 0X7C);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003D714:
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(0X50, ctx->r29);
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
