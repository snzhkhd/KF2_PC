#include "recomp.h"
#include "disable_warnings.h"

void sub_8004C500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, 0x6404($at)
    MEM_W(0X6404, ctx->r1) = ctx->r4;
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // srl         $v0, $a1, 2
    ctx->r2 = S32(U32(ctx->r5) >> 2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, 0x6414($at)
    MEM_W(0X6414, ctx->r1) = ctx->r4;
    // addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a1, 0x640C($at)
    MEM_W(0X640C, ctx->r1) = ctx->r5;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x641C($at)
    MEM_W(0X641C, ctx->r1) = 0;
    // jr          $ra
    // nop

    return;
    // nop

;}
