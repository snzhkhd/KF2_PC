#include "recomp.h"
#include "disable_warnings.h"

void sub_800526BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // addiu       $v1, $v1, -0x21BC
    ctx->r3 = ADD32(ctx->r3, -0X21BC);
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $a0, -0x21B0($at)
    MEM_W(-0X21B0, ctx->r1) = ctx->r4;
    // jal         0x800526FC
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    sub_800526FC(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
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
