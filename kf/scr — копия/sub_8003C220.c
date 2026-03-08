#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, 0x79B4($v1)
    ctx->r3 = MEM_W(0X79B4, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // jal         0x8003C138
    // sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    Entity_UpdateAIByDistance(rdram, ctx);
    goto after_0;
    // sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
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
