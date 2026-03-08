#include "recomp.h"
#include "disable_warnings.h"

void sub_80038120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bne         $a1, $zero, L_800381A4
    if (ctx->r5 != 0) {
        // addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
        goto L_800381A4;
    }
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AD2($v0)
    ctx->r2 = MEM_H(-0X4AD2, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800381A4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800381A4;
    }
    // nop

    // lw          $v0, 0x1C($a3)
    ctx->r2 = MEM_W(0X1C, ctx->r7);
    // lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(0X14, ctx->r7);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(0X0, ctx->r7);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80038190
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80038190;
    }
    // nop

    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_80038190:
    // sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // sh          $zero, 0x30($a3)
    MEM_H(0X30, ctx->r7) = 0;
    // sh          $zero, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = 0;
    // j           L_8003820C
    // sh          $zero, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = 0;
    goto L_8003820C;
    // sh          $zero, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = 0;
L_800381A4:
    // lw          $v0, 0x1C($a3)
    ctx->r2 = MEM_W(0X1C, ctx->r7);
    // lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(0X14, ctx->r7);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(0X0, ctx->r7);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_800381F8
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_800381F8;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_800381F8:
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x30($a3)
    MEM_H(0X30, ctx->r7) = ctx->r2;
    // sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
    // sh          $v0, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = ctx->r2;
L_8003820C:
    // jr          $ra
    // nop

    return;
    // nop

;}
