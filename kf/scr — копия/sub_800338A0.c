#include "recomp.h"
#include "disable_warnings.h"

void sub_800338A0(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("sub_800338A0\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8) << 1;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // beq         $v0, $zero, L_80033990
    if (ctx->r2 == 0) {
        // addu        $a2, $s1, $zero
        ctx->r6 = ADD32(ctx->r17, 0);
        goto L_80033990;
    }
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // slti        $v0, $v1, 0xF0
    ctx->r2 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_80033990
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80033990;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // andi        $s2, $a2, 0xFF
    ctx->r18 = ctx->r6 & 0XFF;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F2C($v1)
    ctx->r3 = MEM_HU(0X4F2C, ctx->r3);
    // sll         $v0, $a3, 11
    ctx->r2 = S32(ctx->r7) << 11;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lhu         $v0, 0x4F34($v0)
    ctx->r2 = MEM_HU(0X4F34, ctx->r2);
    // sll         $v1, $t0, 11
    ctx->r3 = S32(ctx->r8) << 11;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // addiu       $v1, $v1, 0x400
    ctx->r3 = ADD32(ctx->r3, 0X400);
    // sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F30($v1)
    ctx->r3 = MEM_HU(0X4F30, ctx->r3);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x800336D4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    sub_800336D4(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_0:
    // andi        $v0, $s1, 0x2
    ctx->r2 = ctx->r17 & 0X2;
    // lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(0X5, ctx->r16);
    // beq         $v0, $zero, L_80033A00
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0xF0
        ctx->r2 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
        goto L_80033A00;
    }
    // slti        $v0, $v1, 0xF0
    ctx->r2 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_80033A00
    if (ctx->r2 == 0) {
        // addiu       $a0, $s0, 0x5
        ctx->r4 = ADD32(ctx->r16, 0X5);
        goto L_80033A00;
    }
    // addiu       $a0, $s0, 0x5
    ctx->r4 = ADD32(ctx->r16, 0X5);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // j           L_800339E4
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    goto L_800339E4;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_80033990:
    // lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(0X5, ctx->r16);
    // andi        $v0, $a2, 0x2
    ctx->r2 = ctx->r6 & 0X2;
    // beq         $v0, $zero, L_80033A00
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0xF0
        ctx->r2 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
        goto L_80033A00;
    }
    // slti        $v0, $v1, 0xF0
    ctx->r2 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_80033A00
    if (ctx->r2 == 0) {
        // addiu       $a0, $s0, 0x5
        ctx->r4 = ADD32(ctx->r16, 0X5);
        goto L_80033A00;
    }
    // addiu       $a0, $s0, 0x5
    ctx->r4 = ADD32(ctx->r16, 0X5);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F2C($v1)
    ctx->r3 = MEM_HU(0X4F2C, ctx->r3);
    // sll         $v0, $a3, 11
    ctx->r2 = S32(ctx->r7) << 11;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lhu         $v0, 0x4F34($v0)
    ctx->r2 = MEM_HU(0X4F34, ctx->r2);
    // sll         $v1, $t0, 11
    ctx->r3 = S32(ctx->r8) << 11;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // addiu       $v1, $v1, 0x400
    ctx->r3 = ADD32(ctx->r3, 0X400);
    // sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
L_800339E4:
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lhu         $v1, 0x4F30($v1)
    ctx->r3 = MEM_HU(0X4F30, ctx->r3);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x800336D4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    sub_800336D4(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_1:
L_80033A00:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
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
