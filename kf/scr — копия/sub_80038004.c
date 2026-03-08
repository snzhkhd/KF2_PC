#include "recomp.h"
#include "disable_warnings.h"

void sub_80038004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // sh          $zero, 0x24($a0)
    MEM_H(0X24, ctx->r4) = 0;
    // sh          $zero, 0x26($a0)
    MEM_H(0X26, ctx->r4) = 0;
    // sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // sh          $v0, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r2;
    // sh          $v0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r2;
    // sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    // sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
    // jr          $ra
    // sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    return;
    // sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
;}
