#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x7564
    ctx->r3 = ADD32(ctx->r3, -0X7564);
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    // ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // addiu       $a3, $v1, -0x3800
    ctx->r7 = ADD32(ctx->r3, -0X3800);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004AE20:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8004AE38
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8004AE38;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // j           L_8004AE40
    // sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    goto L_8004AE40;
    // sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_8004AE38:
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004AE40:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a2, L_8004AE20
    if (ctx->r5 != ctx->r6) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8004AE20;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // jr          $ra
    // nop

    return;
    // nop

;}
