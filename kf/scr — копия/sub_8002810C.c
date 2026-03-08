#include "recomp.h"
#include "disable_warnings.h"

void sub_8002810C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B31($at)
    MEM_B(-0X4B31, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B20($at)
    MEM_H(-0X4B20, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a1, -0x4AA1($at)
    MEM_B(-0X4AA1, ctx->r1) = ctx->r5;
    // beq         $v1, $v0, L_80028190
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $zero, 0x5
        ctx->r4 = 0 | 0X5;
        goto L_80028190;
    }
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x4754
    ctx->r3 = ADD32(ctx->r3, -0X4754);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4AB8($a2)
    ctx->r6 = MEM_W(-0X4AB8, ctx->r6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4ABC($at)
    MEM_W(-0X4ABC, ctx->r1) = ctx->r2;
    // jal         0x800188CC
    // addiu       $a1, $a1, 0x31
    ctx->r5 = ADD32(ctx->r5, 0X31);
    LoadTFile(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, 0x31
    ctx->r5 = ADD32(ctx->r5, 0X31);
    after_0:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4AB8($a1)
    ctx->r5 = MEM_W(-0X4AB8, ctx->r5);
    // jal         0x8003654C
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    sub_8003654C(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    after_1:
L_80028190:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AAC($at)
    MEM_H(-0X4AAC, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4AB4($at)
    MEM_W(-0X4AB4, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4AA6($at)
    MEM_B(-0X4AA6, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A9C($at)
    MEM_B(-0X4A9C, ctx->r1) = 0;
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
