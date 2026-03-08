#include "recomp.h"
#include "disable_warnings.h"

void sub_8004C264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a0, $zero, L_8004C2DC
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8004C2DC;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x640C($v1)
    ctx->r3 = MEM_W(0X640C, ctx->r3);
    // nop

    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_8004C28C
    if (ctx->r2 != 0) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_8004C28C;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // j           L_8004C290
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    goto L_8004C290;
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8004C28C:
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8004C290:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6414($v0)
    ctx->r2 = MEM_W(0X6414, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6404($v1)
    ctx->r3 = MEM_W(0X6404, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v1, $v0, -0x8
    ctx->r3 = ADD32(ctx->r2, -0X8);
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004C2C8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004C2C8;
    }
    // nop

    // j           L_8004C2FC
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    goto L_8004C2FC;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8004C2C8:
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8004C2FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C2FC;
    }
    // nop

L_8004C2D4:
    // j           L_8004C350
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004C350;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004C2DC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6404($v0)
    ctx->r2 = MEM_W(0X6404, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6414($v1)
    ctx->r3 = MEM_W(0X6414, ctx->r3);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8004C2D4
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8004C2D4;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8004C2FC:
    // bgez        $a0, L_8004C308
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8004C308;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
L_8004C308:
    // addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x6404($a2)
    ctx->r6 = MEM_W(0X6404, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // ori         $v0, $a0, 0x1
    ctx->r2 = ctx->r4 | 0X1;
    // bgez        $a1, L_8004C338
    if (SIGNED(ctx->r5) >= 0) {
        // sw          $v0, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r2;
        goto L_8004C338;
    }
    // sw          $v0, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r2;
    // addiu       $a1, $a0, 0x7
    ctx->r5 = ADD32(ctx->r4, 0X7);
L_8004C338:
    // sra         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) >> 2;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x6404($at)
    MEM_W(0X6404, ctx->r1) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004C350:
    // jr          $ra
    // nop

    return;
    // nop

;}
