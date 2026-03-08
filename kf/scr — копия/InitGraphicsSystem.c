#include "recomp.h"
#include "disable_warnings.h"

void InitGraphicsSystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80062C30
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    KF_ResetGraph(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // jal         0x80063034
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_SetDispMask(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_1:
    // jal         0x8005F578
    // ori         $s0, $zero, 0xF0
    ctx->r16 = 0 | 0XF0;
    KF_InitGeom(rdram, ctx);
    goto after_2;
    // ori         $s0, $zero, 0xF0
    ctx->r16 = 0 | 0XF0;
    after_2:
    // ori         $a0, $zero, 0xA0
    ctx->r4 = 0 | 0XA0;
    // jal         0x8005DB84
    // ori         $a1, $zero, 0x78
    ctx->r5 = 0 | 0X78;
    KF_SetGeomOffset(rdram, ctx);
    goto after_3;
    // ori         $a1, $zero, 0x78
    ctx->r5 = 0 | 0X78;
    after_3:
    // jal         0x8005DB9C
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    KF_SetGeomScreen(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    after_4:
    // lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // addiu       $s1, $s1, 0x4B1C
    ctx->r17 = ADD32(ctx->r17, 0X4B1C);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x140
    ctx->r5 = 0 | 0X140;
    // ori         $a2, $zero, 0xF0
    ctx->r6 = 0 | 0XF0;
    // ori         $a3, $zero, 0x64
    ctx->r7 = 0 | 0X64;
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8005EF38
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    KF_InitClip(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_5:
    // addiu       $a0, $s1, -0x49BC
    ctx->r4 = ADD32(ctx->r17, -0X49BC);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x140
    ctx->r7 = 0 | 0X140;
    // jal         0x800678F8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_SetDefDrawEnv(rdram, ctx);
    goto after_6;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_6:
    // addiu       $s2, $s1, -0x4904
    ctx->r18 = ADD32(ctx->r17, -0X4904);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0xF0
    ctx->r6 = 0 | 0XF0;
    // ori         $a3, $zero, 0x140
    ctx->r7 = 0 | 0X140;
    // jal         0x800679B8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_SetDefDispEnv(rdram, ctx);
    goto after_7;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // addiu       $a0, $s1, -0x4960
    ctx->r4 = ADD32(ctx->r17, -0X4960);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0xF0
    ctx->r6 = 0 | 0XF0;
    // ori         $a3, $zero, 0x140
    ctx->r7 = 0 | 0X140;
    // jal         0x800678F8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_SetDefDrawEnv(rdram, ctx);
    goto after_8;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_8:
    // addiu       $a0, $s1, -0x48F0
    ctx->r4 = ADD32(ctx->r17, -0X48F0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x140
    ctx->r7 = 0 | 0X140;
    // jal         0x800679B8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_SetDefDispEnv(rdram, ctx);
    goto after_9;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_9:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x1D2($at)
    MEM_B(0X1D2, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x176($at)
    MEM_B(0X176, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x178($at)
    MEM_B(0X178, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x1D4($at)
    MEM_B(0X1D4, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $zero, 0x220($at)
    MEM_H(0X220, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $v0, 0x222($at)
    MEM_H(0X222, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $zero, 0x234($at)
    MEM_H(0X234, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sh          $v0, 0x236($at)
    MEM_H(0X236, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x179($at)
    MEM_B(0X179, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x17A($at)
    MEM_B(0X17A, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x17B($at)
    MEM_B(0X17B, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x1D5($at)
    MEM_B(0X1D5, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x1D6($at)
    MEM_B(0X1D6, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x1D7($at)
    MEM_B(0X1D7, ctx->r1) = 0;
    // jal         0x800637A4
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    KF_PutDispEnv(rdram, ctx);
    goto after_10;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_10:
    // jal         0x8005DB9C
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    KF_SetGeomScreen(rdram, ctx);
    goto after_11;
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    after_11:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8005DAD0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_SetBackColor(rdram, ctx);
    goto after_12;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_12:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8005DAF0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_SetFarColor(rdram, ctx);
    goto after_13;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_13:
    // jal         0x8002FBC0
    // ori         $a0, $zero, 0x59D8
    ctx->r4 = 0 | 0X59D8;
    sub_8002FBC0(rdram, ctx);
    goto after_14;
    // ori         $a0, $zero, 0x59D8
    ctx->r4 = 0 | 0X59D8;
    after_14:
    // jal         0x8002FD90
    // nop

    sub_8002FD90(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
