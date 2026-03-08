#include "recomp.h"
#include "disable_warnings.h"

void sub_800629F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80062A24
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80062A24;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x6144($a0)
    ctx->r4 = MEM_W(0X6144, ctx->r4);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // j           L_80062A28
    // nop

    goto L_80062A28;
    // nop

L_80062A24:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80062A28:
    // jr          $ra
    // nop

    return;
    // nop

;}
