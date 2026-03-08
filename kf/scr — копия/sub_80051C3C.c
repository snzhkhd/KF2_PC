#include "recomp.h"
#include "disable_warnings.h"

void sub_80051C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bne         $a2, $zero, L_80051C60
    if (ctx->r6 != 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_80051C60;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // j           L_80051C7C
    // nop

    goto L_80051C7C;
    // nop

L_80051C60:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7CC($a0)
    ctx->r4 = MEM_W(-0X7CC, ctx->r4);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7A8($v1)
    ctx->r3 = MEM_W(-0X7A8, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // srlv        $v1, $a1, $v1
    ctx->r3 = S32(U32(ctx->r5) >> (ctx->r3 & 31));
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_80051C7C:
    // jr          $ra
    // nop

    return;
    // nop

;}
