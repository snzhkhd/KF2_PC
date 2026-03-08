#include "recomp.h"
#include "disable_warnings.h"

void sub_80034824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(0X8C, ctx->r29);
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // lw          $s1, 0x90($sp)
    ctx->r17 = MEM_W(0X90, ctx->r29);
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // lhu         $s7, 0x88($sp)
    ctx->r23 = MEM_HU(0X88, ctx->r29);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // lhu         $s2, 0x94($sp)
    ctx->r18 = MEM_HU(0X94, ctx->r29);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80015460
    // sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    sub_80015460(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // addiu       $s0, $s0, 0x4ECC
    ctx->r16 = ADD32(ctx->r16, 0X4ECC);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8005DDF8
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    sub_8005DDF8(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // jal         0x8005E0F8
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    KF_SetRotMatrix(rdram, ctx);
    goto after_2;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // jal         0x8005E188
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    KF_SetTransMatrix(rdram, ctx);
    goto after_3;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_3:
    // addiu       $s0, $s0, 0x2D8
    ctx->r16 = ADD32(ctx->r16, 0X2D8);
    // andi        $v1, $s1, 0x7F
    ctx->r3 = ctx->r17 & 0X7F;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8005E158
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    KF_SetColorMatrix(rdram, ctx);
    goto after_4;
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_4:
    // lbu         $a0, 0x62($s0)
    ctx->r4 = MEM_BU(0X62, ctx->r16);
    // lbu         $a1, 0x63($s0)
    ctx->r5 = MEM_BU(0X63, ctx->r16);
    // lbu         $a2, 0x64($s0)
    ctx->r6 = MEM_BU(0X64, ctx->r16);
    // jal         0x8005DAD0
    // andi        $s1, $s1, 0x80
    ctx->r17 = ctx->r17 & 0X80;
    KF_SetBackColor(rdram, ctx);
    goto after_5;
    // andi        $s1, $s1, 0x80
    ctx->r17 = ctx->r17 & 0X80;
    after_5:
    // beq         $s1, $zero, L_8003497C
    if (ctx->r17 == 0) {
        // nop
    
        goto L_8003497C;
    }
    // nop

    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80034980
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    goto L_80034980;
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
L_8003497C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80034980:
    // jal         0x8005E128
    // andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    KF_SetLightMatrix(rdram, ctx);
    goto after_6;
    // andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    after_6:
    // jal         0x80036594
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_7;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // jal         0x8002FFD4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_8;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // jal         0x80036B08
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    SubmitDisplayListToGPU(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
    // bne         $v0, $zero, L_800349DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800349DC;
    }
    // nop

    // jal         0x80030008
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80030008(rdram, ctx);
    goto after_10;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // jal         0x8002FFD4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_11;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // j           L_800349E0
    // nop

    goto L_800349E0;
    // nop

L_800349DC:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
L_800349E0:
    // jal         0x80030894
    // nop

    sub_80030894(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) << 16;
    // jal         0x8003171C
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    sub_8003171C(rdram, ctx);
    goto after_13;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_13:
    // lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
