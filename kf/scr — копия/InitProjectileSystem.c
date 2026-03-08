#include "recomp.h"
#include "disable_warnings.h"

void InitProjectileSystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $a0, $zero, 0x18B
    ctx->r4 = 0 | 0X18B;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x67DC
    ctx->r3 = ADD32(ctx->r3, -0X67DC);
L_80037FBC:
    // sh          $a1, -0x2E($v1)
    MEM_H(-0X2E, ctx->r3) = ctx->r5;
    // sb          $a1, -0x30($v1)
    MEM_B(-0X30, ctx->r3) = ctx->r5;
    // sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_80037FBC
    if (ctx->r2 != 0) {
        // addu        $a0, $a0, $a2
        ctx->r4 = ADD32(ctx->r4, ctx->r6);
        goto L_80037FBC;
    }
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sh          $zero, 0x132($at)
    MEM_H(0X132, ctx->r1) = 0;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sh          $zero, 0x130($at)
    MEM_H(0X130, ctx->r1) = 0;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sh          $zero, 0x12E($at)
    MEM_H(0X12E, ctx->r1) = 0;
    // jr          $ra
    // nop

    return;
    // nop

;}
