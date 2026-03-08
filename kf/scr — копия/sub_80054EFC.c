#include "recomp.h"
#include "disable_warnings.h"

void sub_80054EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x1916($a0)
    ctx->r4 = MEM_HU(-0X1916, ctx->r4);
    // nop

    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80054F24
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80054F24;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $a3, $v0, $v1
    ctx->r7 = S32(ctx->r2) << (ctx->r3 & 31);
    // j           L_80054F34
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80054F34;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80054F24:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
L_80054F34:
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
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
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AC
    ctx->r1 = ADD32(ctx->r1, -0X75AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75B0
    ctx->r1 = ADD32(ctx->r1, -0X75B0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $a0, -0xFD8($a0)
    ctx->r4 = MEM_HU(-0XFD8, ctx->r4);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lhu         $a1, -0xFD0($a1)
    ctx->r5 = MEM_HU(-0XFD0, ctx->r5);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, -0x6EA0($v0)
    ctx->r2 = MEM_HU(-0X6EA0, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x6E98($v1)
    ctx->r3 = MEM_HU(-0X6E98, ctx->r3);
    // or          $a0, $a3, $a0
    ctx->r4 = ctx->r7 | ctx->r4;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $a0, -0xFD8($at)
    MEM_H(-0XFD8, ctx->r1) = ctx->r4;
    // or          $a1, $a2, $a1
    ctx->r5 = ctx->r6 | ctx->r5;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $a1, -0xFD0($at)
    MEM_H(-0XFD0, ctx->r1) = ctx->r5;
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, -0x6EA0($at)
    MEM_H(-0X6EA0, ctx->r1) = ctx->r2;
    // nor         $a1, $zero, $a1
    ctx->r5 = ~(0 | ctx->r5);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, -0x6E98($at)
    MEM_H(-0X6E98, ctx->r1) = ctx->r3;
    // jr          $ra
    // nop

    return;
    // nop

;}
