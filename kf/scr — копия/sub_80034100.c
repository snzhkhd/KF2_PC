#include "recomp.h"
#include "disable_warnings.h"

void sub_80034100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $a1, $a3
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // addiu       $a0, $a0, 0x4DFD
    ctx->r4 = ADD32(ctx->r4, 0X4DFD);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // mult        $a2, $a3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lhu         $v0, 0x4DFE($v0)
    ctx->r2 = MEM_HU(0X4DFE, ctx->r2);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $v0, 0x4DFE($at)
    MEM_H(0X4DFE, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lhu         $v0, 0x4E00($v0)
    ctx->r2 = MEM_HU(0X4E00, ctx->r2);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4E02($v1)
    ctx->r3 = MEM_HU(0X4E02, ctx->r3);
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $v0, 0x4E00($at)
    MEM_H(0X4E00, ctx->r1) = ctx->r2;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $v1, 0x4E02($at)
    MEM_H(0X4E02, ctx->r1) = ctx->r3;
    // jr          $ra
    // nop

    return;
    // nop

;}
