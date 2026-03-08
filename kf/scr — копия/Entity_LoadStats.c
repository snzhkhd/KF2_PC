#include "recomp.h"
#include "disable_warnings.h"

void Entity_LoadStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x46E8
    ctx->r3 = ADD32(ctx->r3, 0X46E8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // lhu         $v1, 0x1A($v0)
    ctx->r3 = MEM_HU(0X1A, ctx->r2);
    // nop

    // sh          $v1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r3;
    // lhu         $v1, 0x12($v0)
    ctx->r3 = MEM_HU(0X12, ctx->r2);
    // nop

    // sh          $v1, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r3;
    // lhu         $v1, 0x14($v0)
    ctx->r3 = MEM_HU(0X14, ctx->r2);
    // nop

    // sh          $v1, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r3;
    // lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(0X34, ctx->r2);
    // nop

    // sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
    // lhu         $v0, 0x32($v0)
    ctx->r2 = MEM_HU(0X32, ctx->r2);
    // nop

    // sh          $v0, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r2;
    // sh          $v0, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r2;
    // jr          $ra
    // sh          $v0, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r2;
    return;
    // sh          $v0, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r2;
;}
