#include "recomp.h"
#include "disable_warnings.h"

void sub_80028E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B14($v0)
    ctx->r2 = MEM_HU(-0X4B14, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 < 0X3C ? 1 : 0;
    // bne         $v0, $zero, L_80028EB8
    if (ctx->r2 != 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_80028EB8;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B12($v0)
    ctx->r2 = MEM_HU(-0X4B12, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 < 0X3C ? 1 : 0;
    // xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
L_80028EB8:
    // jr          $ra
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
