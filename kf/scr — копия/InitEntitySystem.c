#include "recomp.h"
#include "disable_warnings.h"

void InitEntitySystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79CC($at)
    MEM_W(0X79CC, ctx->r1) = 0;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, -0x19F8
    ctx->r4 = ADD32(ctx->r4, -0X19F8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // addiu       $v1, $a0, 0x5C
    ctx->r3 = ADD32(ctx->r4, 0X5C);
L_8003BB2C:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // sb          $zero, -0x53($v1)
    MEM_B(-0X53, ctx->r3) = 0;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v1, $v1, 0x7C
    ctx->r3 = ADD32(ctx->r3, 0X7C);
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // sltiu       $v0, $v0, 0xC8
    ctx->r2 = ctx->r2 < 0XC8 ? 1 : 0;
    // bne         $v0, $zero, L_8003BB2C
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x7C
        ctx->r4 = ADD32(ctx->r4, 0X7C);
        goto L_8003BB2C;
    }
    // addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79A8($at)
    MEM_B(0X79A8, ctx->r1) = 0;
    // jr          $ra
    // nop

    return;
    // nop

;}
