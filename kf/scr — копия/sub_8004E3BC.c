#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x8A8
    ctx->r3 = ADD32(ctx->r3, -0X8A8);
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB74($at)
    MEM_W(-0XB74, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB78($at)
    MEM_W(-0XB78, ctx->r1) = 0;
L_8004E3F4:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $a0, L_8004E3F4
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8004E3F4;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // jal         0x80061B54
    // nop

    KF_ResetCallback(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // addiu       $a1, $a1, -0xF3C
    ctx->r5 = ADD32(ctx->r5, -0XF3C);
    // jal         0x80061B84
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    InterruptCallback(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
