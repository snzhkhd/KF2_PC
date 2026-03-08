#include "recomp.h"
#include "disable_warnings.h"

void sub_80014C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // andi        $a1, $a1, 0xFFF
    ctx->r5 = ctx->r5 & 0XFFF;
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // beq         $a1, $v1, L_80014D0C
    if (ctx->r5 == ctx->r3) {
        // slt         $v0, $v1, $a1
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_80014D0C;
    }
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_80014CE4
    if (ctx->r2 == 0) {
        // subu        $v0, $a1, $v1
        ctx->r2 = SUB32(ctx->r5, ctx->r3);
        goto L_80014CE4;
    }
    // subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80014CC0
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
        goto L_80014CC0;
    }
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // j           L_80014D04
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    goto L_80014D04;
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014CC0:
    // subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_80014D3C
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_80014D3C;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // j           L_80014D30
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    goto L_80014D30;
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_80014CE4:
    // subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80014D14
    if (ctx->r2 == 0) {
        // subu        $v0, $a0, $a2
        ctx->r2 = SUB32(ctx->r4, ctx->r6);
        goto L_80014D14;
    }
    // subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D04:
    // beq         $v0, $zero, L_80014D3C
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_80014D3C;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
L_80014D0C:
    // j           L_80014D40
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    goto L_80014D40;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80014D14:
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v1, 0x801
    ctx->r2 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80014D38
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $a1
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_80014D38;
    }
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D30:
    // beq         $v0, $zero, L_80014D40
    if (ctx->r2 == 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80014D40;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80014D38:
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
L_80014D3C:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_80014D40:
    // jr          $ra
    // nop

    return;
    // nop

;}
