#include "recomp.h"
#include "disable_warnings.h"

void SetupEntityAnimation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x43
    ctx->r2 = 0 | 0X43;
    // sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // sh          $a2, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r6;
    // sh          $a2, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r6;
    // jr          $ra
    // sh          $a2, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r6;
    return;
    // sh          $a2, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r6;
;}
