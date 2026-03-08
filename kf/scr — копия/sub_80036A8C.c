#include "recomp.h"
#include "disable_warnings.h"

void sub_80036A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(0X0, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $v0, L_80036AFC
    if (ctx->r6 == ctx->r2) {
        // addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_80036AFC;
    }
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80036AAC:
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // bne         $v0, $t0, L_80036AE0
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_80036AE0;
    }
    // nop

    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80036AF0
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_80036AF0;
    }
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // j           L_80036B00
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80036B00;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80036AE0:
    // beq         $v1, $a1, L_80036B00
    if (ctx->r3 == ctx->r5) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_80036B00;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
L_80036AF0:
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $a3, L_80036AAC
    if (ctx->r6 != ctx->r7) {
        // nop
    
        goto L_80036AAC;
    }
    // nop

L_80036AFC:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80036B00:
    // jr          $ra
    // nop

    return;
    // nop

;}
