#include "recomp.h"
#include "disable_warnings.h"

void MeleeAttack_800281CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4AAC
    ctx->r5 = ADD32(ctx->r5, -0X4AAC);
    // lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(0X0, ctx->r5);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_800282E8
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800282E8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA1($v1)
    ctx->r3 = MEM_BU(-0X4AA1, ctx->r3);
    // nop

    // beq         $v1, $v0, L_800282E8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800282E8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADC($v0)
    ctx->r2 = MEM_H(-0X4ADC, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800282E8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800282E8;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4AA2($at)
    MEM_B(-0X4AA2, ctx->r1) = ctx->r4;
    // bne         $a0, $zero, L_80028244
    if (ctx->r4 != 0) {
        // sh          $zero, 0x0($a1)
        MEM_H(0X0, ctx->r5) = 0;
        goto L_80028244;
    }
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4ABC($v0)
    ctx->r2 = MEM_W(-0X4ABC, ctx->r2);
    // nop

    // lhu         $v1, 0x1E($v0)
    ctx->r3 = MEM_HU(0X1E, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AAA($at)
    MEM_H(-0X4AAA, ctx->r1) = ctx->r3;
    // lhu         $v0, 0x2C($v0)
    ctx->r2 = MEM_HU(0X2C, ctx->r2);
    // j           L_80028264
    // nop

    goto L_80028264;
    // nop

L_80028244:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4ABC($v0)
    ctx->r2 = MEM_W(-0X4ABC, ctx->r2);
    // nop

    // lhu         $v1, 0x26($v0)
    ctx->r3 = MEM_HU(0X26, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AAA($at)
    MEM_H(-0X4AAA, ctx->r1) = ctx->r3;
    // lhu         $v0, 0x2E($v0)
    ctx->r2 = MEM_HU(0X2E, ctx->r2);
L_80028264:
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AA8($at)
    MEM_H(-0X4AA8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B22($v0)
    ctx->r2 = MEM_HU(-0X4B22, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B22($v1)
    ctx->r3 = MEM_HU(-0X4B22, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B20($at)
    MEM_H(-0X4B20, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // bne         $v1, $v0, L_800282D0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800282D0;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B1E($v0)
    ctx->r2 = MEM_HU(-0X4B1E, ctx->r2);
    // nop

    // bne         $v0, $v1, L_800282D0
    if (ctx->r2 != ctx->r3) {
        // ori         $v1, $zero, 0x1
        ctx->r3 = 0 | 0X1;
        goto L_800282D0;
    }
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4ABC($v0)
    ctx->r2 = MEM_W(-0X4ABC, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x4A9D($at)
    MEM_B(-0X4A9D, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(0X5, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A9E($at)
    MEM_B(-0X4A9E, ctx->r1) = ctx->r2;
    // j           L_800282D8
    // nop

    goto L_800282D8;
    // nop

L_800282D0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A9D($at)
    MEM_B(-0X4A9D, ctx->r1) = 0;
L_800282D8:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4AA0($at)
    MEM_B(-0X4AA0, ctx->r1) = 0;
L_800282E8:
    // jr          $ra
    // nop

    return;
    // nop

;}
