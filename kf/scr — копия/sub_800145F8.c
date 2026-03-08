#include "recomp.h"
#include "disable_warnings.h"

void sub_800145F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80014594
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80014594(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x559C
    ctx->r16 = ADD32(ctx->r16, -0X559C);
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80014628:
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(0X0, ctx->r16);
    // nop

    // bne         $v0, $v1, L_80014640
    if (ctx->r2 != ctx->r3) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_80014640;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // j           L_800146F0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800146F0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80014640:
    // bne         $a1, $v1, L_80014628
    if (ctx->r5 != ctx->r3) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80014628;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x559C
    ctx->r16 = ADD32(ctx->r16, -0X559C);
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_80014658:
    // lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(0X2, ctx->r16);
    // nop

    // bne         $v0, $s3, L_8001467C
    if (ctx->r2 != ctx->r19) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_8001467C;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // jal         0x80014448
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80014448(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // sh          $s1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r17;
    // j           L_800146F0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800146F0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8001467C:
    // bne         $a1, $s1, L_80014658
    if (ctx->r5 != ctx->r17) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80014658;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x559C
    ctx->r16 = ADD32(ctx->r16, -0X559C);
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    // addiu       $t0, $s0, 0x28
    ctx->r8 = ADD32(ctx->r16, 0X28);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800146A0:
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // nop

    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // lhu         $v1, 0x8($v1)
    ctx->r3 = MEM_HU(0X8, ctx->r3);
    // nop

    // slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_800146D4
    if (ctx->r2 == 0) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_800146D4;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
L_800146D4:
    // bne         $a1, $a3, L_800146A0
    if (ctx->r5 != ctx->r7) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_800146A0;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // jal         0x80014448
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80014448(rdram, ctx);
    goto after_2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_2:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_800146F0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
