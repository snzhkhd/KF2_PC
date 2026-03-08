#include "recomp.h"
#include "disable_warnings.h"

void sub_8003706C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x254
    ctx->r1 = ADD32(ctx->r1, 0X254);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $a0, 0x0($at)
    ctx->r4 = MEM_W(0X0, ctx->r1);
    // nop

    // beq         $a0, $zero, L_800370C4
    if (ctx->r4 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800370C4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // nop

    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // slti        $v0, $a1, 0x80
    ctx->r2 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_800370B0
    if (ctx->r2 == 0) {
        // andi        $v1, $a1, 0x7F
        ctx->r3 = ctx->r5 & 0X7F;
        goto L_800370B0;
    }
    // andi        $v1, $a1, 0x7F
    ctx->r3 = ctx->r5 & 0X7F;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // j           L_800370C4
    // nop

    goto L_800370C4;
    // nop

L_800370B0:
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(0X10, ctx->r2);
L_800370C4:
    // jr          $ra
    // nop

    return;
    // nop

;}
