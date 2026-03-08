#include "recomp.h"
#include "disable_warnings.h"

void sub_80036754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(0X0, ctx->r5);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $v0, L_800367C8
    if (ctx->r6 == ctx->r2) {
        // addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_800367C8;
    }
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80036770:
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $t0, L_8003679C
    if (ctx->r2 != ctx->r8) {
        // addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_8003679C;
    }
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // j           L_800367BC
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    goto L_800367BC;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8003679C:
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800367BC:
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $a3, L_80036770
    if (ctx->r6 != ctx->r7) {
        // nop
    
        goto L_80036770;
    }
    // nop

L_800367C8:
    // jr          $ra
    // nop

    return;
    // nop

;}
