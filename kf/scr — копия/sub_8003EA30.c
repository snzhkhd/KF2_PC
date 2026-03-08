#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(0X2, ctx->r17);
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79B4($s0)
    ctx->r16 = MEM_W(0X79B4, ctx->r16);
    // lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(0X38, ctx->r29);
    // lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(0X3C, ctx->r29);
    // jal         0x8003E608
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003E608(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // lh          $a0, 0x40($s0)
    ctx->r4 = MEM_H(0X40, ctx->r16);
    // lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(0X0, ctx->r17);
    // jal         0x80014C84
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    sub_80014C84(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    after_1:
    // addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x8003E8E8
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    sub_8003E8E8(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    after_2:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
