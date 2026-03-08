#include "recomp.h"
#include "disable_warnings.h"

void sub_80025D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $v1, $zero, 0x3BFF
    ctx->r3 = 0 | 0X3BFF;
L_80025D48:
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80025D48
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
        goto L_80025D48;
    }
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jr          $ra
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
