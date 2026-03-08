#include "recomp.h"
#include "disable_warnings.h"

void sub_80052244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80061B54
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    KF_ResetCallback(rdram, ctx);
    goto after_0;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // bne         $s0, $zero, L_80052270
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80052270;
    }
    // nop

    // jal         0x800523B8
    // nop

    sub_800523B8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8005227C
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    goto L_8005227C;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
L_80052270:
    // jal         0x80052398
    // nop

    sub_80052398(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
L_8005227C:
    // ori         $a2, $a2, 0x1C00
    ctx->r6 = ctx->r6 | 0X1C00;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // addiu       $a3, $a3, -0x10
    ctx->r7 = ADD32(ctx->r7, -0X10);
L_8005228C:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80052294:
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80052294
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_80052294;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8005228C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005228C;
    }
    // nop

    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x1D80
    ctx->r6 = ctx->r6 | 0X1D80;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
L_800522D4:
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_800522D4
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_800522D4;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // jal         0x800568CC
    // ori         $a0, $zero, 0x18
    ctx->r4 = 0 | 0X18;
    sub_800568CC(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x18
    ctx->r4 = 0 | 0X18;
    after_3:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x21C8
    ctx->r3 = ADD32(ctx->r3, -0X21C8);
L_80052304:
    // ori         $a0, $zero, 0xF
    ctx->r4 = 0 | 0XF;
    // addiu       $v0, $v1, 0x3C
    ctx->r2 = ADD32(ctx->r3, 0X3C);
L_8005230C:
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bgez        $a0, L_8005230C
    if (SIGNED(ctx->r4) >= 0) {
        // addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
        goto L_8005230C;
    }
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_80052304
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
        goto L_80052304;
    }
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x1938($at)
    MEM_W(-0X1938, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = 0;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
