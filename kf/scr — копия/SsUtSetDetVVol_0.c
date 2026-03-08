#include "recomp.h"
#include "disable_warnings.h"

void SsUtSetDetVVol_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8005937C
    if (ctx->r2 != 0) {
        // addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
        goto L_8005937C;
    }
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // j           L_800593D0
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800593D0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005937C:
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7746
    ctx->r1 = ADD32(ctx->r1, -0X7746);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a2, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r6;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $a0, 0x0($at)
    ctx->r4 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7748
    ctx->r1 = ADD32(ctx->r1, -0X7748);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r5;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $a0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r4;
L_800593D0:
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
