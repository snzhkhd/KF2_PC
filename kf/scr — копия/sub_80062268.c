#include "recomp.h"
#include "disable_warnings.h"

void sub_80062268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x60E4
    ctx->r4 = ADD32(ctx->r4, 0X60E4);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x800624E4
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    sub_800624E4(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    after_0:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x60E0($v0)
    ctx->r2 = MEM_W(0X60E0, ctx->r2);
    // lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // addiu       $a1, $a1, 0x22B8
    ctx->r5 = ADD32(ctx->r5, 0X22B8);
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // jal         0x80061B84
    // nop

    InterruptCallback(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // addiu       $v0, $v0, 0x243C
    ctx->r2 = ADD32(ctx->r2, 0X243C);
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
