#include "recomp.h"
#include "disable_warnings.h"

void sub_8005BC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lh          $v0, 0xC($a3)
    ctx->r2 = MEM_H(0XC, ctx->r7);
    // addiu       $a0, $zero, -0x8000
    ctx->r4 = ADD32(0, -0X8000);
    // lh          $v1, 0xA($a3)
    ctx->r3 = MEM_H(0XA, ctx->r7);
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // and         $t1, $v0, $a0
    ctx->r9 = ctx->r2 & ctx->r4;
    // addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
    // sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // lh          $v0, 0x10($a3)
    ctx->r2 = MEM_H(0X10, ctx->r7);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // beq         $v0, $zero, L_8005BCA0
    if (ctx->r2 == 0) {
        // and         $a0, $v1, $a0
        ctx->r4 = ctx->r3 & ctx->r4;
        goto L_8005BCA0;
    }
    // and         $a0, $v1, $a0
    ctx->r4 = ctx->r3 & ctx->r4;
    // ori         $t0, $t1, 0x4000
    ctx->r8 = ctx->r9 | 0X4000;
L_8005BCA0:
    // lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(0X0, ctx->r7);
    // lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(0X2, ctx->r7);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // andi        $v1, $v1, 0x7F00
    ctx->r3 = ctx->r3 & 0X7F00;
    // or          $v1, $a0, $v1
    ctx->r3 = ctx->r4 | ctx->r3;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // lhu         $a0, 0x4($a3)
    ctx->r4 = MEM_HU(0X4, ctx->r7);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lhu         $a0, 0x8($a3)
    ctx->r4 = MEM_HU(0X8, ctx->r7);
    // andi        $v0, $v0, 0x1FC0
    ctx->r2 = ctx->r2 & 0X1FC0;
    // or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // andi        $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 & 0X1F;
    // or          $t0, $v0, $a0
    ctx->r8 = ctx->r2 | ctx->r4;
    // jr          $ra
    // sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    return;
    // sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
;}
