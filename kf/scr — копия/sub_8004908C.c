#include "recomp.h"
#include "disable_warnings.h"

void sub_8004908C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // ori         $a0, $zero, 0x17C
    ctx->r4 = 0 | 0X17C;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80038E6C
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    FindFreeOrOldestProjectileSlot(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $a0, $v1, 8
    ctx->r4 = S32(ctx->r3) << 8;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) << 16;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addiu       $v1, $v1, -0x7C
    ctx->r3 = ADD32(ctx->r3, -0X7C);
    // sb          $v1, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r3;
    // sh          $s1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r17;
    // sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
