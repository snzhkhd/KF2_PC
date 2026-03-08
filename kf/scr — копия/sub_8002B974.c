#include "recomp.h"
#include "disable_warnings.h"

void sub_8002B974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x4
    ctx->r16 = 0 | 0X4;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4A3C
    ctx->r17 = ADD32(ctx->r17, -0X4A3C);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(0X0, ctx->r17);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x49E4($a2)
    ctx->r6 = MEM_H(-0X49E4, ctx->r6);
    // jal         0x80014ED4
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    sub_80014ED4(rdram, ctx);
    goto after_0;
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A3A($a1)
    ctx->r5 = MEM_H(-0X4A3A, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x49E2($a2)
    ctx->r6 = MEM_H(-0X49E2, ctx->r6);
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49E4($at)
    MEM_H(-0X49E4, ctx->r1) = ctx->r2;
    // jal         0x80014ED4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80014ED4(rdram, ctx);
    goto after_1;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A38($a1)
    ctx->r5 = MEM_H(-0X4A38, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x49E0($a2)
    ctx->r6 = MEM_H(-0X49E0, ctx->r6);
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49E2($at)
    MEM_H(-0X49E2, ctx->r1) = ctx->r2;
    // jal         0x80014ED4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80014ED4(rdram, ctx);
    goto after_2;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x49E4($a0)
    ctx->r4 = MEM_HU(-0X49E4, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49E0($at)
    MEM_H(-0X49E0, ctx->r1) = ctx->r2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A3A($v1)
    ctx->r3 = MEM_HU(-0X4A3A, ctx->r3);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x49E2($a1)
    ctx->r5 = MEM_HU(-0X49E2, ctx->r5);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4A38($a0)
    ctx->r4 = MEM_HU(-0X4A38, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4A3A($at)
    MEM_H(-0X4A3A, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4A38($at)
    MEM_H(-0X4A38, ctx->r1) = ctx->r4;
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
