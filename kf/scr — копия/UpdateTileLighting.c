#include "recomp.h"
#include "disable_warnings.h"

void UpdateTileLighting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4AAC
    ctx->r17 = ADD32(ctx->r17, -0X4AAC);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_800342EC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800342EC;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4A14($a0)
    ctx->r4 = MEM_HU(-0X4A14, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // addiu       $at, $at, -0x4288
    ctx->r1 = ADD32(ctx->r1, -0X4288);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x51A4
    ctx->r2 = ADD32(ctx->r2, 0X51A4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // jal         0x8005E158
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    KF_SetColorMatrix(rdram, ctx);
    goto after_0;
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_0:
    // jal         0x8005E128
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_SetLightMatrix(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // lh          $a0, 0x66($s0)
    ctx->r4 = MEM_H(0X66, ctx->r16);
    // jal         0x8002FBC0
    // nop

    sub_8002FBC0(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lbu         $a0, 0x62($s0)
    ctx->r4 = MEM_BU(0X62, ctx->r16);
    // lbu         $a1, 0x63($s0)
    ctx->r5 = MEM_BU(0X63, ctx->r16);
    // lbu         $a2, 0x64($s0)
    ctx->r6 = MEM_BU(0X64, ctx->r16);
    // jal         0x8005DAD0
    // nop

    KF_SetBackColor(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4ABC($a0)
    ctx->r4 = MEM_W(-0X4ABC, ctx->r4);
    // nop

    // lh          $v0, 0x34($a0)
    ctx->r2 = MEM_H(0X34, ctx->r4);
    // nop

    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x36($a0)
    ctx->r2 = MEM_H(0X36, ctx->r4);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lh          $v0, 0x38($a0)
    ctx->r2 = MEM_H(0X38, ctx->r4);
    // addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // jal         0x8005F698
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    KF_RotMatrix(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // jal         0x8005E0F8
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    KF_SetRotMatrix(rdram, ctx);
    goto after_5;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_5:
    // jal         0x8005E188
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    KF_SetTransMatrix(rdram, ctx);
    goto after_6;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_6:
    // jal         0x80036594
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    after_7:
    // jal         0x8002FFD4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_8;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // addiu       $a0, $s1, -0x8
    ctx->r4 = ADD32(ctx->r17, -0X8);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lbu         $a2, -0x4AA2($a2)
    ctx->r6 = MEM_BU(-0X4AA2, ctx->r6);
    // lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(0X0, ctx->r17);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // jal         0x80036B08
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    SubmitDisplayListToGPU(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
    // beq         $v0, $zero, L_800342EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800342EC;
    }
    // nop

    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x80030474
    // nop

    sub_80030474(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80031034
    // ori         $a1, $zero, 0x64
    ctx->r5 = 0 | 0X64;
    sub_80031034(rdram, ctx);
    goto after_11;
    // ori         $a1, $zero, 0x64
    ctx->r5 = 0 | 0X64;
    after_11:
L_800342EC:
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
