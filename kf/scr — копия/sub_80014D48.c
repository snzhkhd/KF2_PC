#include "recomp.h"
#include "disable_warnings.h"

void sub_80014D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // blez        $a2, L_80014D74
    if (SIGNED(ctx->r6) <= 0) {
        // slt         $v0, $a0, $a1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_80014D74;
    }
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_80014D60
    if (ctx->r2 == 0) {
        // slt         $v0, $a1, $a0
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80014D60;
    }
    // slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // j           L_80014D98
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    goto L_80014D98;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
L_80014D60:
    // beq         $v0, $zero, L_80014DA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80014DA8;
    }
    // nop

    // subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // j           L_80014D9C
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    goto L_80014D9C;
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D74:
    // slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80014D8C
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $a1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_80014D8C;
    }
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // j           L_80014D9C
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    goto L_80014D9C;
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D8C:
    // beq         $v0, $zero, L_80014DA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80014DA8;
    }
    // nop

    // subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
L_80014D98:
    // slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80014D9C:
    // beq         $v0, $zero, L_80014DA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80014DA8;
    }
    // nop

    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80014DA8:
    // jr          $ra
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
