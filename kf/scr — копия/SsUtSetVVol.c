#include "recomp.h"
#include "disable_warnings.h"

void SsUtSetVVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
L_800595F0:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A0
    ctx->r1 = ADD32(ctx->r1, -0X75A0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r17;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // sll         $a0, $a0, 19
    ctx->r4 = S32(ctx->r4) << 19;
    // sra         $a0, $a0, 15
    ctx->r4 = S32(ctx->r4) >> 15;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // ori         $v0, $zero, 0x200
    ctx->r2 = 0 | 0X200;
    // sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x80FF
    ctx->r2 = 0 | 0X80FF;
    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x4000
    ctx->r2 = 0 | 0X4000;
    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s0, -0x1916($at)
    MEM_H(-0X1916, ctx->r1) = ctx->r16;
    // jal         0x80054EFC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_80054EFC(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_0:
    // addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800595F0
    if (ctx->r2 != 0) {
        // sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16) << 16;
        goto L_800595F0;
    }
    // sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16) << 16;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
