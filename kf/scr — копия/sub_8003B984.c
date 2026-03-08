#include "recomp.h"
#include "disable_warnings.h"

void sub_8003B984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8003B784
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
    Entity_UpdatePhysics(rdram, ctx);
    goto after_0;
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
