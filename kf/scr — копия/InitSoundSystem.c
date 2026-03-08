#include "recomp.h"
#include "disable_warnings.h"

void InitSoundSystem(uint8_t* rdram, recomp_context* ctx) 
{
    printf("InitSoundSystem\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80052358
    // nop

    sub_80052358(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80054388
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    SetMasterVolume(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x20D0
    ctx->r4 = ADD32(ctx->r4, -0X20D0);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // jal         0x80059920
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    sub_80059920(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_2:
    // jal         0x80054214
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    sub_80054214(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    after_3:
    // jal         0x800541F4
    // nop

    sub_800541F4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80052510
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    sub_80052510(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    after_5:
    // jal         0x800524D0
    // nop

    sub_800524D0(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // ori         $a0, $zero, 0x28
    ctx->r4 = 0 | 0X28;
    // jal         0x800525C0
    // ori         $a1, $zero, 0x28
    ctx->r5 = 0 | 0X28;
    sub_800525C0(rdram, ctx);
    goto after_7;
    // ori         $a1, $zero, 0x28
    ctx->r5 = 0 | 0X28;
    after_7:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x59D8
    ctx->r3 = ADD32(ctx->r3, -0X59D8);
    // addiu       $a1, $v1, 0x2C
    ctx->r5 = ADD32(ctx->r3, 0X2C);
    // ori         $a0, $zero, 0x81
    ctx->r4 = 0 | 0X81;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x49D0
    ctx->r2 = ADD32(ctx->r2, -0X49D0);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x59D0($at)
    MEM_W(-0X59D0, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x59CC($at)
    MEM_W(-0X59CC, ctx->r1) = 0;
L_80013F2C:
    // sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $a2, L_80013F2C
    if (ctx->r4 != ctx->r6) {
        // addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
        goto L_80013F2C;
    }
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x559C
    ctx->r2 = ADD32(ctx->r2, -0X559C);
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80013F50:
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $v1, L_80013F50
    if (ctx->r4 != ctx->r3) {
        // addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_80013F50;
    }
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B74
    ctx->r3 = ADD32(ctx->r3, -0X4B74);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // addiu       $a1, $a1, -0x7570
    ctx->r5 = ADD32(ctx->r5, -0X7570);
L_80013F74:
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_80013F74
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1000
        ctx->r5 = ADD32(ctx->r5, 0X1000);
        goto L_80013F74;
    }
    // addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x7E28
    ctx->r2 = ADD32(ctx->r2, 0X7E28);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4B48($at)
    MEM_W(-0X4B48, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, 0x7A90
    ctx->r2 = ADD32(ctx->r2, 0X7A90);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4B40($at)
    MEM_W(-0X4B40, ctx->r1) = ctx->r2;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
