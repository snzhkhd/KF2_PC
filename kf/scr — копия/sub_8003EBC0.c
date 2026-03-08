#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8003EC0C
    if (ctx->r3 == ctx->r2) {
        // addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
        goto L_8003EC0C;
    }
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // beq         $v1, $zero, L_8003EC04
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003EC04;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_8003EC6C
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $s0, 0x40
        ctx->r4 = ADD32(ctx->r16, 0X40);
        goto L_8003EC6C;
    }
    // addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // j           L_8003ECD0
    // nop

    goto L_8003ECD0;
    // nop

L_8003EC04:
    // j           L_8003ECD0
    // addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
    goto L_8003ECD0;
    // addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
L_8003EC0C:
    // lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x46E8
    ctx->r3 = ADD32(ctx->r3, 0X46E8);
    // addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0xC($a2)
    ctx->r2 = MEM_H(0XC, ctx->r6);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // lh          $v0, 0xE($a2)
    ctx->r2 = MEM_H(0XE, ctx->r6);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lh          $v1, 0x10($a2)
    ctx->r3 = MEM_H(0X10, ctx->r6);
    // lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(0X34, ctx->r16);
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // j           L_8003ECD0
    // sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    goto L_8003ECD0;
    // sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
L_8003EC6C:
    // lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // addiu       $a2, $a2, 0x46F4
    ctx->r6 = ADD32(ctx->r6, 0X46F4);
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2) << 4;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) << 3;
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // jal         0x80015614
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015614(rdram, ctx);
    goto after_0;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(0X34, ctx->r16);
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
L_8003ECD0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
