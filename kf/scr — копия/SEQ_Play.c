#include "recomp.h"
#include "disable_warnings.h"

void SEQ_Play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6) << 16;
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // jal         0x8005C32C
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    sub_8005C32C(rdram, ctx);
    goto after_0;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // nop

    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
