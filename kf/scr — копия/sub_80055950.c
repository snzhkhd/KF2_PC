#include "recomp.h"
#include "disable_warnings.h"

void sub_80055950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(0X44, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AC
    ctx->r1 = ADD32(ctx->r1, -0X75AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // sh          $zero, 0x194($v1)
    MEM_H(0X194, ctx->r3) = 0;
    // jr          $ra
    // sh          $zero, 0x196($v1)
    MEM_H(0X196, ctx->r3) = 0;
    return;
    // sh          $zero, 0x196($v1)
    MEM_H(0X196, ctx->r3) = 0;
;}
