#include "recomp.h"
#include "disable_warnings.h"

void sub_80033ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // addiu       $a3, $a3, 0x4DF9
    ctx->r7 = ADD32(ctx->r7, 0X4DF9);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(0X0, ctx->r7);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80033F84
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x80
        ctx->r2 = 0 | 0X80;
        goto L_80033F84;
    }
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xD0
    ctx->r2 = 0 | 0XD0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(0X0, ctx->r7);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lbu         $a0, 0x4DFA($a0)
    ctx->r4 = MEM_BU(0X4DFA, ctx->r4);
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lbu         $a1, 0x4DFB($a1)
    ctx->r5 = MEM_BU(0X4DFB, ctx->r5);
    // lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // lbu         $a2, 0x4DFC($a2)
    ctx->r6 = MEM_BU(0X4DFC, ctx->r6);
    // ori         $v1, $zero, 0x7BDC
    ctx->r3 = 0 | 0X7BDC;
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(0X0, ctx->r7);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // ori         $v0, $v0, 0x17
    ctx->r2 = ctx->r2 | 0X17;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // beq         $v1, $zero, L_80033F68
    if (ctx->r3 == 0) {
        // sw          $a2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r6;
        goto L_80033F68;
    }
    // sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // j           L_80033F70
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    goto L_80033F70;
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_80033F68:
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80033F70:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    // jal         0x80033C78
    // ori         $a3, $zero, 0xF0
    ctx->r7 = 0 | 0XF0;
    RenderFadeOverlay(rdram, ctx);
    goto after_0;
    // ori         $a3, $zero, 0xF0
    ctx->r7 = 0 | 0XF0;
    after_0:
L_80033F84:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
