#include "recomp.h"
#include "disable_warnings.h"

void sub_8001A3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4AE2
    ctx->r3 = ADD32(ctx->r3, -0X4AE2);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // bne         $v0, $zero, L_8001A3F0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_8001A3F0;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE0($at)
    MEM_H(-0X4AE0, ctx->r1) = 0;
L_8001A3F0:
    // jr          $ra
    // nop

    return;
    // nop

;}
