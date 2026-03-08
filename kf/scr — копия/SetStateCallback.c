#include "recomp.h"
#include "disable_warnings.h"

void SetStateCallback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x240
    ctx->r1 = ADD32(ctx->r1, 0X240);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sw          $a1, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r5;
    // jr          $ra
    // nop

    return;
    // nop

;}
