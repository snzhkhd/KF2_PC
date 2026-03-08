#include "recomp.h"
#include "disable_warnings.h"

void sub_8003654C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x254
    ctx->r1 = ADD32(ctx->r1, 0X254);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a1, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r5;
    // jal         0x80036594
    // nop

    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x250($a0)
    ctx->r4 = MEM_W(0X250, ctx->r4);
    // jal         0x80030130
    // nop

    KF_TMDIndicesToOffsets(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
