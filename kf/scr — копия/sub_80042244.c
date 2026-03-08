#include "recomp.h"
#include "disable_warnings.h"

void sub_80042244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // addiu       $a1, $a1, 0x46E8
    ctx->r5 = ADD32(ctx->r5, 0X46E8);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $t1, $zero, 0xFF
    ctx->r9 = 0 | 0XFF;
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // addiu       $a3, $a1, 0x12C0
    ctx->r7 = ADD32(ctx->r5, 0X12C0);
L_8004225C:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // beq         $v0, $t1, L_800422B0
    if (ctx->r2 == ctx->r9) {
        // nop
    
        goto L_800422B0;
    }
    // nop

    // addiu       $v1, $a1, 0x38
    ctx->r3 = ADD32(ctx->r5, 0X38);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80042274:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // bne         $v0, $t0, L_8004228C
    if (ctx->r2 != ctx->r8) {
        // addu        $v0, $v0, $a3
        ctx->r2 = ADD32(ctx->r2, ctx->r7);
        goto L_8004228C;
    }
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // j           L_80042290
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    goto L_80042290;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8004228C:
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80042290:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80042274
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80042274;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x28
    ctx->r2 = SIGNED(ctx->r6) < 0X28 ? 1 : 0;
    // bne         $v0, $zero, L_8004225C
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x78
        ctx->r5 = ADD32(ctx->r5, 0X78);
        goto L_8004225C;
    }
    // addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
L_800422B0:
    // jr          $ra
    // nop

    return;
    // nop

;}
