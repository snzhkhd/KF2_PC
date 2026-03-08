#include "recomp.h"
#include "disable_warnings.h"

void sub_800370FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // ori         $a0, $zero, 0xC
    ctx->r4 = 0 | 0XC;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_80037110:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80037124
    if (ctx->r2 == 0) {
        // addu        $a0, $a0, $a1
        ctx->r4 = ADD32(ctx->r4, ctx->r5);
        goto L_80037124;
    }
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_80037124:
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // bne         $v0, $zero, L_80037110
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
        goto L_80037110;
    }
    // addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // jr          $ra
    // nop

    return;
    // nop

;}
