#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $v1, 0x18($a0)
    ctx->r3 = MEM_HU(0X18, ctx->r4);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // sltu        $v0, $a1, $v1
    ctx->r2 = ctx->r5 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8003D8DC
    if (ctx->r2 == 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8003D8DC;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lh          $v0, 0x66($a0)
    ctx->r2 = MEM_H(0X66, ctx->r4);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // xori        $a2, $v0, 0x1
    ctx->r6 = ctx->r2 ^ 0X1;
L_8003D8DC:
    // jr          $ra
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
