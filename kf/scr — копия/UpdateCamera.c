#include "recomp.h"
#include "disable_warnings.h"

void UpdateCamera(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("UpdateCamera\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // addiu       $s2, $s2, -0x1D48
    ctx->r18 = ADD32(ctx->r18, -0X1D48);
    // sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80033C58
    if (ctx->r3 == ctx->r2) {
        // addiu       $s3, $sp, 0x48
        ctx->r19 = ADD32(ctx->r29, 0X48);
        goto L_80033C58;
    }
    // addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // addiu       $s1, $s2, 0x6
    ctx->r17 = ADD32(ctx->r18, 0X6);
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
L_80033B20:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80033C44
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $s2, 0x18
        ctx->r4 = ADD32(ctx->r18, 0X18);
        goto L_80033C44;
    }
    // addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // lbu         $v1, -0x4($s1)
    ctx->r3 = MEM_BU(-0X4, ctx->r17);
    // lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(0XA, ctx->r17);
    // sll         $s0, $v1, 1
    ctx->r16 = S32(ctx->r3) << 1;
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // lh          $v0, 0xC($s1)
    ctx->r2 = MEM_H(0XC, ctx->r17);
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lh          $v0, 0xE($s1)
    ctx->r2 = MEM_H(0XE, ctx->r17);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x51A4
    ctx->r2 = ADD32(ctx->r2, 0X51A4);
    // jal         0x8005F698
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    KF_RotMatrix(rdram, ctx);
    goto after_0;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_0:
    // lh          $a0, 0x66($s0)
    ctx->r4 = MEM_H(0X66, ctx->r16);
    // jal         0x8002FBC0
    // nop

    sub_8002FBC0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lbu         $a0, 0x62($s0)
    ctx->r4 = MEM_BU(0X62, ctx->r16);
    // lbu         $a1, 0x63($s0)
    ctx->r5 = MEM_BU(0X63, ctx->r16);
    // lbu         $a2, 0x64($s0)
    ctx->r6 = MEM_BU(0X64, ctx->r16);
    // jal         0x8005DAD0
    // nop

    KF_SetBackColor(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x8005E158
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    KF_SetColorMatrix(rdram, ctx);
    goto after_3;
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // jal         0x800611CC
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_800611CC(rdram, ctx);
    goto after_4;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_4:
    // jal         0x8005E128
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    KF_SetLightMatrix(rdram, ctx);
    goto after_5;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_5:
    // lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(0X2, ctx->r17);
    // nop

    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s1)
    ctx->r2 = MEM_H(0X4, ctx->r17);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(0X6, ctx->r17);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // jal         0x8005DFD4
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    KF_ScaleMatrix(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_6:
    // jal         0x8005E0F8
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    KF_SetRotMatrix(rdram, ctx);
    goto after_7;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_7:
    // jal         0x8005E188
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    KF_SetTransMatrix(rdram, ctx);
    goto after_8;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_8:
    // lhu         $a0, -0x2($s1)
    ctx->r4 = MEM_HU(-0X2, ctx->r17);
    // jal         0x80036594
    // nop

    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x8002FFD4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_10;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lhu         $a1, -0x2($s1)
    ctx->r5 = MEM_HU(-0X2, ctx->r17);
    // lbu         $a2, -0x5($s1)
    ctx->r6 = MEM_BU(-0X5, ctx->r17);
    // lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(0X0, ctx->r17);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addiu       $a0, $s2, 0x20
    ctx->r4 = ADD32(ctx->r18, 0X20);
    // jal         0x80036B08
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    SubmitDisplayListToGPU(rdram, ctx);
    goto after_11;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_11:
    // beq         $v0, $zero, L_80033C2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80033C2C;
    }
    // nop

    // jal         0x80030008
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80030008(rdram, ctx);
    goto after_12;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
L_80033C2C:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x8003073C
    // nop

    sub_8003073C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80031034
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80031034(rdram, ctx);
    goto after_14;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_14:
L_80033C44:
    // addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80033B20
    if (ctx->r3 != ctx->r2) {
        // addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
        goto L_80033B20;
    }
    // addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
L_80033C58:
    // lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
