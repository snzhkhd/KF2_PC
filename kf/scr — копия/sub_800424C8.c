#include "recomp.h"
#include "disable_warnings.h"

void sub_800424C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, 0x1184($a0)
    ctx->r4 = MEM_W(0X1184, ctx->r4);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lbu         $v0, 0xB($a0)
    ctx->r2 = MEM_BU(0XB, ctx->r4);
    // nop

    // bne         $v0, $zero, L_80042580
    if (ctx->r2 != 0) {
        // addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
        goto L_80042580;
    }
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // andi        $v0, $a2, 0xFFF
    ctx->r2 = ctx->r6 & 0XFFF;
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(0X4, ctx->r8);
    // lbu         $a0, 0x0($a0)
    ctx->r4 = MEM_BU(0X0, ctx->r4);
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // andi        $a0, $a0, 0x7
    ctx->r4 = ctx->r4 & 0X7;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $a0, $v0, L_80042544
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x3
        ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
        goto L_80042544;
    }
    // slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80042528
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80042528;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a0, $v0, L_8004254C
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8004254C;
    }
    // nop

    // j           L_80042590
    // nop

    goto L_80042590;
    // nop

L_80042528:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $a0, $v0, L_80042554
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_80042554;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $a0, $v0, L_8004255C
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8004255C;
    }
    // nop

    // j           L_80042590
    // nop

    goto L_80042590;
    // nop

L_80042544:
    // j           L_80042560
    // ori         $v0, $zero, 0x31
    ctx->r2 = 0 | 0X31;
    goto L_80042560;
    // ori         $v0, $zero, 0x31
    ctx->r2 = 0 | 0X31;
L_8004254C:
    // j           L_80042560
    // ori         $v0, $zero, 0xA1
    ctx->r2 = 0 | 0XA1;
    goto L_80042560;
    // ori         $v0, $zero, 0xA1
    ctx->r2 = 0 | 0XA1;
L_80042554:
    // j           L_80042560
    // ori         $v0, $zero, 0xB1
    ctx->r2 = 0 | 0XB1;
    goto L_80042560;
    // ori         $v0, $zero, 0xB1
    ctx->r2 = 0 | 0XB1;
L_8004255C:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80042560:
    // sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(0X0, ctx->r8);
    // lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(0X8, ctx->r8);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80042590
    // nop

    goto L_80042590;
    // nop

L_80042580:
    // lbu         $v1, 0xB($a0)
    ctx->r3 = MEM_BU(0XB, ctx->r4);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v1, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r3;
L_80042590:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
