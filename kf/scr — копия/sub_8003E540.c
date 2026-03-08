#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // lw          $s2, 0x79B4($s2)
    ctx->r18 = MEM_W(0X79B4, ctx->r18);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // jal         0x80014FAC
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_80014FAC(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    // sra         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16) >> 16;
    // jal         0x8001565C
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_8001565C(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) << 16;
    // sra         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17) >> 16;
    // jal         0x8001565C
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    sub_8001565C(rdram, ctx);
    goto after_2;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(0X10, ctx->r29);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // lh          $a0, 0x50($s2)
    ctx->r4 = MEM_H(0X50, ctx->r18);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lh          $a0, 0x54($s2)
    ctx->r4 = MEM_H(0X54, ctx->r18);
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(0X14, ctx->r29);
    // lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(0X1C, ctx->r29);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jal         0x8003D8E4
    // sh          $v0, 0x54($s2)
    MEM_H(0X54, ctx->r18) = ctx->r2;
    sub_8003D8E4(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x54($s2)
    MEM_H(0X54, ctx->r18) = ctx->r2;
    after_5:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
