#include "recomp.h"
#include "disable_warnings.h"

void PackVertex11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A0
    ctx->r2 = ADD32(ctx->r2, 0X61A0);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80064280
    if (ctx->r2 != 0) {
        // andi        $v1, $a1, 0xFFF
        ctx->r3 = ctx->r5 & 0XFFF;
        goto L_80064280;
    }
    // andi        $v1, $a1, 0xFFF
    ctx->r3 = ctx->r5 & 0XFFF;
    // andi        $v1, $a1, 0x7FF
    ctx->r3 = ctx->r5 & 0X7FF;
    // sll         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) << 11;
    // j           L_80064288
    // andi        $v0, $a0, 0x7FF
    ctx->r2 = ctx->r4 & 0X7FF;
    goto L_80064288;
    // andi        $v0, $a0, 0x7FF
    ctx->r2 = ctx->r4 & 0X7FF;
L_80064280:
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // andi        $v0, $a0, 0xFFF
    ctx->r2 = ctx->r4 & 0XFFF;
L_80064288:
    // lui         $a0, 0xE500
    ctx->r4 = S32(0XE500 << 16);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // jr          $ra
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    return;
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
;}
