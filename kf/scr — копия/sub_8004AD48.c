#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AD48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x7564
    ctx->r3 = ADD32(ctx->r3, -0X7564);
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    // ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // addiu       $a3, $v1, -0x3800
    ctx->r7 = ADD32(ctx->r3, -0X3800);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004AD60:
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $t0, L_8004AD7C
    if (ctx->r2 != ctx->r8) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8004AD7C;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // j           L_8004AD84
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    goto L_8004AD84;
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8004AD7C:
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8004AD84:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a2, L_8004AD60
    if (ctx->r5 != ctx->r6) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8004AD60;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // jr          $ra
    // nop

    return;
    // nop

;}
