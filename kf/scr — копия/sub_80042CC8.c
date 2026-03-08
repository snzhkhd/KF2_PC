#include "recomp.h"
#include "disable_warnings.h"

void sub_80042CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
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
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // sh          $v0, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r2;
    // sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // sh          $v0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0xA0
    ctx->r2 = 0 | 0XA0;
    // sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x78
    ctx->r2 = 0 | 0X78;
    // sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // sh          $zero, 0x26($a0)
    MEM_H(0X26, ctx->r4) = 0;
    // sh          $zero, 0x24($a0)
    MEM_H(0X24, ctx->r4) = 0;
    // jr          $ra
    // sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    return;
    // sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
;}
