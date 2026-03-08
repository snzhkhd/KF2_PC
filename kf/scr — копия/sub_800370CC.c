#include "recomp.h"
#include "disable_warnings.h"

void sub_800370CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // ori         $a0, $zero, 0xC
    ctx->r4 = 0 | 0XC;
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_800370DC:
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // bne         $v0, $zero, L_800370DC
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
        goto L_800370DC;
    }
    // addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // jr          $ra
    // nop

    return;
    // nop

;}
