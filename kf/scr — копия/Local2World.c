#include "recomp.h"
#include "disable_warnings.h"

void Local2World(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lw          $t0, -0x4ABC($t0)
    ctx->r8 = MEM_W(-0X4ABC, ctx->r8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4C($v0)
    ctx->r2 = MEM_HU(-0X4A4C, ctx->r2);
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // lhu         $v1, 0x3C($t0)
    ctx->r3 = MEM_HU(0X3C, ctx->r8);
    // addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4A($v0)
    ctx->r2 = MEM_HU(-0X4A4A, ctx->r2);
    // lhu         $v1, 0x3E($t0)
    ctx->r3 = MEM_HU(0X3E, ctx->r8);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x4AA2($a1)
    ctx->r5 = MEM_BU(-0X4AA2, ctx->r5);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A48($v0)
    ctx->r2 = MEM_HU(-0X4A48, ctx->r2);
    // lhu         $v1, 0x40($t0)
    ctx->r3 = MEM_HU(0X40, ctx->r8);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4AAC($a2)
    ctx->r6 = MEM_H(-0X4AAC, ctx->r6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // jal         0x80036DD8
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80036DD8(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4ABC($a2)
    ctx->r6 = MEM_W(-0X4ABC, ctx->r6);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x34($a2)
    ctx->r3 = MEM_HU(0X34, ctx->r6);
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lhu         $v1, 0x36($a2)
    ctx->r3 = MEM_HU(0X36, ctx->r6);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(0X1C, ctx->r29);
    // lhu         $v1, 0x38($a2)
    ctx->r3 = MEM_HU(0X38, ctx->r6);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80015614
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    sub_80015614(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A5C($a0)
    ctx->r4 = MEM_W(-0X4A5C, ctx->r4);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $v1, -0x640
    ctx->r3 = ADD32(ctx->r3, -0X640);
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A08($v0)
    ctx->r2 = MEM_H(-0X4A08, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A04($a1)
    ctx->r5 = MEM_H(-0X4A04, ctx->r5);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
