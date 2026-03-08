#include "recomp.h"
#include "disable_warnings.h"

void sub_8005BC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $a0, 0x8000
    ctx->r2 = ctx->r4 & 0X8000;
    // sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // andi        $v0, $a1, 0x8000
    ctx->r2 = ctx->r5 & 0X8000;
    // sh          $v0, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r2;
    // andi        $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 & 0X4000;
    // sh          $v0, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r2;
    // andi        $v0, $a1, 0x20
    ctx->r2 = ctx->r5 & 0X20;
    // sh          $v0, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r2;
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // sh          $v1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r3;
    // andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // sh          $a0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r4;
    // srl         $v0, $a1, 6
    ctx->r2 = S32(U32(ctx->r5) >> 6);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sh          $v0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r2;
    // andi        $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 & 0X1F;
    // jr          $ra
    // sh          $a1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r5;
    return;
    // sh          $a1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r5;
;}
