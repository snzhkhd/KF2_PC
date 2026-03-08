#include "recomp.h"
#include "disable_warnings.h"

void sub_80036428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // ori         $a0, $zero, 0x3C
    ctx->r4 = 0 | 0X3C;
    // ori         $a1, $zero, 0x3C
    ctx->r5 = 0 | 0X3C;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8005DAD0
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    KF_SetBackColor(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    after_0:
    // jal         0x8005DB9C
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    KF_SetGeomScreen(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    after_1:
    // jal         0x8002FFA4
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    KF_TMDCurrentSet(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    after_2:
    // jal         0x80030008
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80030008(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // jal         0x8002FBC0
    // ori         $a0, $zero, 0x59D8
    ctx->r4 = 0 | 0X59D8;
    sub_8002FBC0(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x59D8
    ctx->r4 = 0 | 0X59D8;
    after_4:
    // jal         0x8002FFD4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_5;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // jal         0x80030474
    // nop

    sub_80030474(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80031034
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80031034(rdram, ctx);
    goto after_7;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
