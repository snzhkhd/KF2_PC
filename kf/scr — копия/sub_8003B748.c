#include "recomp.h"
#include "disable_warnings.h"

void sub_8003B748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x4210
    ctx->r3 = ADD32(ctx->r3, 0X4210);
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8003B75C:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a2, L_8003B77C
    if (ctx->r2 == ctx->r6) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8003B77C;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $a1, L_8003B75C
    if (ctx->r4 != ctx->r5) {
        // addiu       $v1, $v1, 0x7C
        ctx->r3 = ADD32(ctx->r3, 0X7C);
        goto L_8003B75C;
    }
    // addiu       $v1, $v1, 0x7C
    ctx->r3 = ADD32(ctx->r3, 0X7C);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003B77C:
    // jr          $ra
    // nop

    return;
    // nop

;}
