#include "recomp.h"
#include "disable_warnings.h"

void KF_RenderUpdateCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // beq         $a3, $zero, L_800300A8
    if (ctx->r7 == 0) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_800300A8;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4F2C
    ctx->r2 = ADD32(ctx->r2, 0X4F2C);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(0X4, ctx->r7);
    // lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(0X8, ctx->r7);
    // lw          $a2, 0xC($a3)
    ctx->r6 = MEM_W(0XC, ctx->r7);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4F34($v1)
    ctx->r3 = MEM_W(0X4F34, ctx->r3);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v0, 0x4F44($at)
    MEM_W(0X4F44, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v1, 0x4F48($at)
    MEM_W(0X4F48, ctx->r1) = ctx->r3;
L_800300A8:
    // beq         $t0, $zero, L_800300D8
    if (ctx->r8 == 0) {
        // nop
    
        goto L_800300D8;
    }
    // nop

    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, 0x4F3C
    ctx->r5 = ADD32(ctx->r5, 0X4F3C);
    // lwl         $v0, 0x3($t0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r8);
    // lwr         $v0, 0x0($t0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r8);
    // lwl         $v1, 0x7($t0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r8);
    // lwr         $v1, 0x4($t0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r8);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
L_800300D8:
    // lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // addiu       $s0, $s0, 0x4F3C
    ctx->r16 = ADD32(ctx->r16, 0X4F3C);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F40($v1)
    ctx->r3 = MEM_HU(0X4F40, ctx->r3);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lhu         $v0, 0x4F3E($v0)
    ctx->r2 = MEM_HU(0X4F3E, ctx->r2);
    // addiu       $a1, $s0, -0x70
    ctx->r5 = ADD32(ctx->r16, -0X70);
    // sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x800154CC
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    sub_800154CC(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_0:
    // lh          $a0, 0x10($sp)
    ctx->r4 = MEM_H(0X10, ctx->r29);
    // jal         0x80015304
    // addiu       $a1, $s0, -0x50
    ctx->r5 = ADD32(ctx->r16, -0X50);
    sub_80015304(rdram, ctx);
    goto after_1;
    // addiu       $a1, $s0, -0x50
    ctx->r5 = ADD32(ctx->r16, -0X50);
    after_1:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
