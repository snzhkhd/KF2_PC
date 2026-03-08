#include "recomp.h"
#include "disable_warnings.h"

void sub_8002FBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $a0, 0x4F5C($at)
    MEM_W(0X4F5C, ctx->r1) = ctx->r4;
    // andi        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 & 0X7FFF;
    // srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80061008
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    KF_SetFogNear(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
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
