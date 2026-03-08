#include "recomp.h"
#include "disable_warnings.h"

void sub_8003955C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(0X10, ctx->r29);
    // sra         $t0, $v0, 11
    ctx->r8 = S32(ctx->r2) >> 11;
    // slt         $v0, $t0, $a0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_800395E0
    if (ctx->r2 != 0) {
        // sra         $v1, $v1, 11
        ctx->r3 = S32(ctx->r3) >> 11;
        goto L_800395E0;
    }
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800395E0
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $a1
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_800395E0;
    }
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_800395E4
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800395E4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800395E0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x8000
        ctx->r2 = 0 | 0X8000;
        goto L_800395E0;
    }
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // beq         $t1, $v0, L_800395D8
    if (ctx->r9 == ctx->r2) {
        // addiu       $v0, $t1, 0x800
        ctx->r2 = ADD32(ctx->r9, 0X800);
        goto L_800395D8;
    }
    // addiu       $v0, $t1, 0x800
    ctx->r2 = ADD32(ctx->r9, 0X800);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800395E4
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800395E4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v0, $t1, -0xC80
    ctx->r2 = ADD32(ctx->r9, -0XC80);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800395E4
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800395E4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800395D8:
    // j           L_800395E4
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_800395E4;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800395E0:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800395E4:
    // jr          $ra
    // nop

    return;
    // nop

;}
