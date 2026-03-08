#include "recomp.h"
#include "disable_warnings.h"

void Math_IsTargetInVerticalRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80015A6C
    if (ctx->r2 == 0) {
        // subu        $v0, $a0, $a1
        ctx->r2 = SUB32(ctx->r4, ctx->r5);
        goto L_80015A6C;
    }
    // subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // j           L_80015A74
    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    goto L_80015A74;
    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_80015A6C:
    // subu        $v0, $a2, $a3
    ctx->r2 = SUB32(ctx->r6, ctx->r7);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_80015A74:
    // bne         $v0, $zero, L_80015A80
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80015A80;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80015A80:
    // jr          $ra
    // nop

    return;
    // nop

;}
