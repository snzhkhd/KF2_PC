#include "recomp.h"
#include "disable_warnings.h"

void sub_800428D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, 0x1184($a1)
    ctx->r5 = MEM_W(0X1184, ctx->r5);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // lh          $v0, 0x34($a1)
    ctx->r2 = MEM_H(0X34, ctx->r5);
    // lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(0X14, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lh          $v0, 0x36($a1)
    ctx->r2 = MEM_H(0X36, ctx->r5);
    // lw          $v1, 0x18($a1)
    ctx->r3 = MEM_W(0X18, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // lh          $v0, 0x38($a1)
    ctx->r2 = MEM_H(0X38, ctx->r5);
    // lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(0X1C, ctx->r5);
    // ori         $a1, $zero, 0x1388
    ctx->r5 = 0 | 0X1388;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // jal         0x800427EC
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    sub_800427EC(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
