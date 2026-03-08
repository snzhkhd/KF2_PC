#include "recomp.h"
#include "disable_warnings.h"

void sub_8003DF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(0X58, ctx->r29);
    // lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(0X5C, ctx->r29);
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79B4($s0)
    ctx->r16 = MEM_W(0X79B4, ctx->r16);
    // addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x68
    ctx->r2 = ADD32(ctx->r16, 0X68);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x6A
    ctx->r2 = ADD32(ctx->r16, 0X6A);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(0X2C, ctx->r16);
    // lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(0X30, ctx->r16);
    // lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(0X34, ctx->r16);
    // jal         0x8001605C
    // nop

    sub_8001605C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // bne         $v0, $zero, L_8003E020
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8003E020;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // lh          $v0, 0x30($sp)
    ctx->r2 = MEM_H(0X30, ctx->r29);
    // lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(0X30, ctx->r16);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // sh          $v1, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r3;
    // sh          $s1, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r17;
    // sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
L_8003E020:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
