#include "recomp.h"
#include "disable_warnings.h"

void sub_8005984C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_800598A0
    if (ctx->r2 == 0) {
        // addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
        goto L_800598A0;
    }
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80059918
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80059918;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, -0x2568($v0)
    ctx->r2 = MEM_H(-0X2568, ctx->r2);
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3) >> 16;
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800598A8
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4) << 2;
        goto L_800598A8;
    }
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
L_800598A0:
    // j           L_80059918
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80059918;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800598A8:
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x1F74
    ctx->r1 = ADD32(ctx->r1, -0X1F74);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2110
    ctx->r1 = ADD32(ctx->r1, -0X2110);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a0, 0x0($at)
    ctx->r4 = MEM_W(0X0, ctx->r1);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x1F2C
    ctx->r1 = ADD32(ctx->r1, -0X1F2C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a2, -0x192F($at)
    MEM_B(-0X192F, ctx->r1) = ctx->r6;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a3, -0x192A($at)
    MEM_B(-0X192A, ctx->r1) = ctx->r7;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v1, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = ctx->r3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $a0, -0x2560($at)
    MEM_W(-0X2560, ctx->r1) = ctx->r4;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, -0x1A08($at)
    MEM_W(-0X1A08, ctx->r1) = ctx->r2;
    // sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(0X8, ctx->r2);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1929($at)
    MEM_B(-0X1929, ctx->r1) = ctx->r3;
L_80059918:
    // jr          $ra
    // nop

    return;
    // nop

;}
