#include "recomp.h"
#include "disable_warnings.h"

void sub_8002EAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0x4F60
    ctx->r3 = ADD32(ctx->r3, 0X4F60);
    // ori         $v0, $zero, 0x8F
    ctx->r2 = 0 | 0X8F;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8002EB0C:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $a0, L_8002EB0C
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8002EB0C;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // jr          $ra
    // nop

    return;
    // nop

;}
