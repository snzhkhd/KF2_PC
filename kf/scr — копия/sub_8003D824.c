#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // bgez        $v0, L_8003D83C
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
        goto L_8003D83C;
    }
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // j           L_8003D840
    // sh          $v0, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r2;
    goto L_8003D840;
    // sh          $v0, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r2;
L_8003D83C:
    // sh          $v1, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r3;
L_8003D840:
    // lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(0X18, ctx->r4);
    // nop

    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // jr          $ra
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    return;
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
;}
