#include "recomp.h"
#include "disable_warnings.h"

void sub_80034F14(uint8_t* rdram, recomp_context* ctx) 
{
    printf("sub_80034F14\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x300
    ctx->r29 = ADD32(ctx->r29, -0X300);
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x20
    ctx->r6 = 0 | 0X20;
    // sw          $ra, 0x2FC($sp)
    MEM_W(0X2FC, ctx->r29) = ctx->r31;
    // sw          $fp, 0x2F8($sp)
    MEM_W(0X2F8, ctx->r29) = ctx->r30;
    // sw          $s7, 0x2F4($sp)
    MEM_W(0X2F4, ctx->r29) = ctx->r23;
    // sw          $s6, 0x2F0($sp)
    MEM_W(0X2F0, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2EC($sp)
    MEM_W(0X2EC, ctx->r29) = ctx->r21;
    // sw          $s4, 0x2E8($sp)
    MEM_W(0X2E8, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2E4($sp)
    MEM_W(0X2E4, ctx->r29) = ctx->r19;
    // sw          $s2, 0x2E0($sp)
    MEM_W(0X2E0, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2DC($sp)
    MEM_W(0X2DC, ctx->r29) = ctx->r17;
    // jal         0x800176E4
    // sw          $s0, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->r16;
    memset_0(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $a0, $sp, 0x198
    ctx->r4 = ADD32(ctx->r29, 0X198);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
    memset_0(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
    after_1:
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // addiu       $s2, $s2, -0x19F8
    ctx->r18 = ADD32(ctx->r18, -0X19F8);
    // ori         $s6, $zero, 0xC7
    ctx->r22 = 0 | 0XC7;
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // addiu       $s0, $s2, 0x3
    ctx->r16 = ADD32(ctx->r18, 0X3);
    // addiu       $s3, $s2, 0x2C
    ctx->r19 = ADD32(ctx->r18, 0X2C);
L_80034F78:
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // bne         $v0, $s4, L_8003516C
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_8003516C;
    }
    // nop

    // lw          $v0, 0x25($s0)
    ctx->r2 = MEM_W(0X25, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_80034FA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80034FA8;
    }
    // nop

    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // j           L_80034FAC
    // ori         $s1, $v0, 0x20
    ctx->r17 = ctx->r2 | 0X20;
    goto L_80034FAC;
    // ori         $s1, $v0, 0x20
    ctx->r17 = ctx->r2 | 0X20;
L_80034FA8:
    // lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(0X0, ctx->r16);
L_80034FAC:
    // lw          $v0, 0x25($s0)
    ctx->r2 = MEM_W(0X25, ctx->r16);
    // lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80035150
    if (ctx->r2 != 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80035150;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80034AD4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_80034AD4(rdram, ctx);
    goto after_2;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_2:
    // and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // beq         $v0, $zero, L_8003516C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003516C;
    }
    // nop

L_80034FD4:
    // lbu         $a0, -0x2($s0)
    ctx->r4 = MEM_BU(-0X2, ctx->r16);
    // jal         0x80034A2C
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    sub_80034A2C(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_3:
    // beq         $v0, $zero, L_800350FC
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800350FC;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8003EBC0
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    sub_8003EBC0(rdram, ctx);
    goto after_4;
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_4:
    // lw          $v1, 0x25($s0)
    ctx->r3 = MEM_W(0X25, ctx->r16);
    // nop

    // andi        $v1, $v1, 0x20
    ctx->r3 = ctx->r3 & 0X20;
    // beq         $v1, $zero, L_80035064
    if (ctx->r3 == 0) {
        // addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
        goto L_80035064;
    }
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // sh          $zero, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = 0;
    // sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // lbu         $a1, -0x2($s0)
    ctx->r5 = MEM_BU(-0X2, ctx->r16);
    // addiu       $v0, $s2, 0x48
    ctx->r2 = ADD32(ctx->r18, 0X48);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $s2, 0x5C
    ctx->r2 = ADD32(ctx->r18, 0X5C);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // addiu       $v0, $v0, 0x79F4
    ctx->r2 = ADD32(ctx->r2, 0X79F4);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x15($s0)
    ctx->r2 = MEM_HU(0X15, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x13($s0)
    ctx->r2 = MEM_H(0X13, ctx->r16);
    // j           L_800350D8
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    goto L_800350D8;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
L_80035064:
    // lhu         $v0, 0x3D($s0)
    ctx->r2 = MEM_HU(0X3D, ctx->r16);
    // nop

    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x3F($s0)
    ctx->r2 = MEM_HU(0X3F, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x41($s0)
    ctx->r2 = MEM_HU(0X41, ctx->r16);
    // nop

    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // lbu         $a1, -0x2($s0)
    ctx->r5 = MEM_BU(-0X2, ctx->r16);
    // addiu       $v0, $s2, 0x48
    ctx->r2 = ADD32(ctx->r18, 0X48);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $s2, 0x5C
    ctx->r2 = ADD32(ctx->r18, 0X5C);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4ECC
    ctx->r2 = ADD32(ctx->r2, 0X4ECC);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x15($s0)
    ctx->r2 = MEM_HU(0X15, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x13($s0)
    ctx->r2 = MEM_H(0X13, ctx->r16);
L_800350D8:
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // lb          $v0, 0x12($s0)
    ctx->r2 = MEM_B(0X12, ctx->r16);
    // addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // jal         0x80034304
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    sub_80034304(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_5:
L_800350FC:
    // lbu         $v1, -0x1($s0)
    ctx->r3 = MEM_BU(-0X1, ctx->r16);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x46E8
    ctx->r3 = ADD32(ctx->r3, 0X46E8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x7($v0)
    ctx->r3 = MEM_BU(0X7, ctx->r2);
    // addiu       $a0, $sp, 0x198
    ctx->r4 = ADD32(ctx->r29, 0X198);
    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // sb          $s4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r20;
    // lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(0X8, ctx->r2);
    // nop

    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sb          $s4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r20;
    // lbu         $v1, -0x2($s0)
    ctx->r3 = MEM_BU(-0X2, ctx->r16);
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8003516C
    // sb          $s4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r20;
    goto L_8003516C;
    // sb          $s4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r20;
L_80035150:
    // jal         0x80034B44
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    sub_80034B44(rdram, ctx);
    goto after_6;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    after_6:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80034FD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80034FD4;
    }
    // nop

L_8003516C:
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // addiu       $s3, $s3, 0x7C
    ctx->r19 = ADD32(ctx->r19, 0X7C);
    // addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80034F78
    if (ctx->r2 != ctx->r3) {
        // addiu       $s2, $s2, 0x7C
        ctx->r18 = ADD32(ctx->r18, 0X7C);
        goto L_80034F78;
    }
    // addiu       $s2, $s2, 0x7C
    ctx->r18 = ADD32(ctx->r18, 0X7C);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    // ori         $a3, $zero, 0x80
    ctx->r7 = 0 | 0X80;
    // addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // jal         0x80034DFC
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80034DFC(rdram, ctx);
    goto after_7;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_7:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    // ori         $a3, $zero, 0x40
    ctx->r7 = 0 | 0X40;
    // addiu       $s0, $sp, 0x198
    ctx->r16 = ADD32(ctx->r29, 0X198);
    // jal         0x80034D08
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80034D08(rdram, ctx);
    goto after_8;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_8:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // lw          $s5, -0x5A50($s5)
    ctx->r21 = MEM_W(-0X5A50, ctx->r21);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x50
    ctx->r6 = 0 | 0X50;
    memset_0(rdram, ctx);
    goto after_9;
    // ori         $a2, $zero, 0x50
    ctx->r6 = 0 | 0X50;
    after_9:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
    memset_0(rdram, ctx);
    goto after_10;
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
    after_10:
    // lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // addiu       $s3, $s3, -0x6810
    ctx->r19 = ADD32(ctx->r19, -0X6810);
    // ori         $s6, $zero, 0x18B
    ctx->r22 = 0 | 0X18B;
    // ori         $s7, $zero, 0x1
    ctx->r23 = 0 | 0X1;
    // lui         $fp, 0x801A
    ctx->r30 = S32(0X801A << 16);
    // addiu       $fp, $fp, -0x4A64
    ctx->r30 = ADD32(ctx->r30, -0X4A64);
    // addiu       $s0, $s3, 0x14
    ctx->r16 = ADD32(ctx->r19, 0X14);
    // addiu       $s4, $s3, 0x34
    ctx->r20 = ADD32(ctx->r19, 0X34);
L_80035210:
    // lhu         $v1, -0xE($s0)
    ctx->r3 = MEM_HU(-0XE, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80035670
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lbu         $a0, -0x11($s0)
    ctx->r4 = MEM_BU(-0X11, ctx->r16);
    // lbu         $v1, -0x10($s0)
    ctx->r3 = MEM_BU(-0X10, ctx->r16);
    // andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // sb          $v0, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // beq         $v1, $v0, L_800352F8
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_800352F8;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // bne         $v1, $v0, L_800354F0
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $a0, 0x2
        ctx->r2 = ctx->r4 & 0X2;
        goto L_800354F0;
    }
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // lbu         $a1, 0x24($s0)
    ctx->r5 = MEM_BU(0X24, ctx->r16);
    // lbu         $a2, 0x25($s0)
    ctx->r6 = MEM_BU(0X25, ctx->r16);
    // jal         0x80034C04
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80034C04(rdram, ctx);
    goto after_11;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // beq         $v0, $zero, L_80035670
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lbu         $v1, -0x7548($v1)
    ctx->r3 = MEM_BU(-0X7548, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80035670
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lhu         $a0, -0xE($s0)
    ctx->r4 = MEM_HU(-0XE, ctx->r16);
    // nop

    // addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // jal         0x80034A2C
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sub_80034A2C(rdram, ctx);
    goto after_12;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_12:
    // beq         $v0, $zero, L_800352E4
    if (ctx->r2 == 0) {
        // addiu       $a1, $s3, 0x24
        ctx->r5 = ADD32(ctx->r19, 0X24);
        goto L_800352E4;
    }
    // addiu       $a1, $s3, 0x24
    ctx->r5 = ADD32(ctx->r19, 0X24);
    // lhu         $a0, -0xE($s0)
    ctx->r4 = MEM_HU(-0XE, ctx->r16);
    // lbu         $a3, -0x13($s0)
    ctx->r7 = MEM_BU(-0X13, ctx->r16);
    // lhu         $v0, -0xA($s0)
    ctx->r2 = MEM_HU(-0XA, ctx->r16);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(0X28, ctx->r16);
    // addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x27($s0)
    ctx->r2 = MEM_BU(0X27, ctx->r16);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x26($s0)
    ctx->r3 = MEM_BU(0X26, ctx->r16);
    // ori         $v0, $zero, 0x1FFF
    ctx->r2 = 0 | 0X1FFF;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80034824
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80034824(rdram, ctx);
    goto after_13;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_13:
    // lbu         $v0, -0x11($s0)
    ctx->r2 = MEM_BU(-0X11, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r2;
L_800352E4:
    // lhu         $v1, -0xE($s0)
    ctx->r3 = MEM_HU(-0XE, ctx->r16);
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80035670
    // sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
    goto L_80035670;
    // sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
L_800352F8:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(0X8, ctx->r16);
    // lbu         $a2, 0x24($s0)
    ctx->r6 = MEM_BU(0X24, ctx->r16);
    // lbu         $a3, 0x25($s0)
    ctx->r7 = MEM_BU(0X25, ctx->r16);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // jal         0x8003955C
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    sub_8003955C(rdram, ctx);
    goto after_14;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    after_14:
    // beq         $v0, $zero, L_800354D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800354D0;
    }
    // nop

    // lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(0X26, ctx->r16);
    // nop

    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x5574
    ctx->r1 = ADD32(ctx->r1, -0X5574);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // nop

    // addiu       $v0, $v1, -0x42
    ctx->r2 = ADD32(ctx->r3, -0X42);
    // sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8003536C
    if (ctx->r2 == 0) {
        // sll         $v1, $v1, 16
        ctx->r3 = S32(ctx->r3) << 16;
        goto L_8003536C;
    }
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addiu       $v0, $sp, 0x156
    ctx->r2 = ADD32(ctx->r29, 0X156);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
L_8003536C:
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // nop

    // subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // bgez        $v0, L_80035670
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lhu         $v1, 0x2A($s0)
    ctx->r3 = MEM_HU(0X2A, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lbu         $v1, 0x24($s0)
    ctx->r3 = MEM_BU(0X24, ctx->r16);
    // addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // sll         $a1, $v1, 10
    ctx->r5 = S32(ctx->r3) << 10;
    // lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(0X0, ctx->r30);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // bgez        $a0, L_800353C0
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_800353C0;
    }
    // nop

    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800353C0:
    // lbu         $v0, 0x25($s0)
    ctx->r2 = MEM_BU(0X25, ctx->r16);
    // subu        $a0, $a1, $a0
    ctx->r4 = SUB32(ctx->r5, ctx->r4);
    // sll         $a1, $v0, 10
    ctx->r5 = S32(ctx->r2) << 10;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(0X8, ctx->r30);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_800353E8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800353E8;
    }
    // nop

    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800353E8:
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_800353FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800353FC;
    }
    // nop

    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_800353FC:
    // lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(0X28, ctx->r16);
    // nop

    // sll         $a1, $v0, 11
    ctx->r5 = S32(ctx->r2) << 11;
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80035420
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035420;
    }
    // nop

    // lbu         $a1, 0x27($s0)
    ctx->r5 = MEM_BU(0X27, ctx->r16);
    // j           L_80035464
    // nop

    goto L_80035464;
    // nop

L_80035420:
    // beq         $a1, $zero, L_80035670
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lbu         $v0, 0x27($s0)
    ctx->r2 = MEM_BU(0X27, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_80035448
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80035448;
    }
    // nop

    // break       7
    do_break(2147701828);
L_80035448:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_80035460
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80035460;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80035460
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80035460;
    }
    // nop

    // break       6
    do_break(2147701852);
L_80035460:
    // mflo        $a1
    ctx->r5 = lo;
L_80035464:
    // lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(0X29, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800354B4
    if (ctx->r2 == 0) {
        // slti        $v0, $a1, 0x14
        ctx->r2 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
        goto L_800354B4;
    }
    // slti        $v0, $a1, 0x14
    ctx->r2 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_80035498
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80035498;
    }
    // nop

    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80035498:
    // lbu         $v0, 0x27($s0)
    ctx->r2 = MEM_BU(0X27, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v1, $v0, 13
    ctx->r3 = S32(ctx->r2) >> 13;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // slti        $v0, $a1, 0x14
    ctx->r2 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
L_800354B4:
    // bne         $v0, $zero, L_80035670
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lbu         $a0, 0x26($s0)
    ctx->r4 = MEM_BU(0X26, ctx->r16);
    // jal         0x80014570
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    PlaySoundEffect(rdram, ctx);
    goto after_15;
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    after_15:
    // j           L_80035678
    // addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
    goto L_80035678;
    // addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
L_800354D0:
    // lhu         $v1, 0x2A($s0)
    ctx->r3 = MEM_HU(0X2A, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // j           L_80035670
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    goto L_80035670;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_800354F0:
    // bne         $v0, $zero, L_80035630
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035630;
    }
    // nop

    // jal         0x80034AD4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80034AD4(rdram, ctx);
    goto after_16;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_16:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // and         $v1, $s2, $v1
    ctx->r3 = ctx->r18 & ctx->r3;
    // beq         $v1, $zero, L_80035670
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lhu         $v0, -0xE($s0)
    ctx->r2 = MEM_HU(-0XE, ctx->r16);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, 0x79F0
    ctx->r2 = ADD32(ctx->r2, 0X79F0);
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
L_80035534:
    // lhu         $v1, -0xE($s0)
    ctx->r3 = MEM_HU(-0XE, ctx->r16);
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // addiu       $v0, $sp, 0x198
    ctx->r2 = ADD32(ctx->r29, 0X198);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $s7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r23;
    // lhu         $a0, -0xE($s0)
    ctx->r4 = MEM_HU(-0XE, ctx->r16);
    // addiu       $s1, $s3, 0x2C
    ctx->r17 = ADD32(ctx->r19, 0X2C);
    // addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // jal         0x80034A2C
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sub_80034A2C(rdram, ctx);
    goto after_17;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_17:
    // beq         $v0, $zero, L_80035670
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lbu         $v0, -0x11($s0)
    ctx->r2 = MEM_BU(-0X11, ctx->r16);
    // lbu         $v1, -0x12($s0)
    ctx->r3 = MEM_BU(-0X12, ctx->r16);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800355BC
    if (ctx->r2 == 0) {
        // addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
        goto L_800355BC;
    }
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // andi        $v0, $s2, 0x80
    ctx->r2 = ctx->r18 & 0X80;
    // beq         $v0, $zero, L_800355BC
    if (ctx->r2 == 0) {
        // ori         $v1, $zero, 0xFF
        ctx->r3 = 0 | 0XFF;
        goto L_800355BC;
    }
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // ori         $v1, $zero, 0xFE
    ctx->r3 = 0 | 0XFE;
L_800355BC:
    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // lhu         $a1, -0xE($s0)
    ctx->r5 = MEM_HU(-0XE, ctx->r16);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4ECC
    ctx->r2 = ADD32(ctx->r2, 0X4ECC);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, -0x13($s0)
    ctx->r2 = MEM_BU(-0X13, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, -0xA($s0)
    ctx->r2 = MEM_HU(-0XA, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, -0xF($s0)
    ctx->r2 = MEM_BU(-0XF, ctx->r16);
    // addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, -0x4($s0)
    ctx->r2 = MEM_H(-0X4, ctx->r16);
    // addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lh          $v0, -0x6($s0)
    ctx->r2 = MEM_H(-0X6, ctx->r16);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // jal         0x80034304
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    sub_80034304(rdram, ctx);
    goto after_18;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_18:
    // lbu         $v0, -0x11($s0)
    ctx->r2 = MEM_BU(-0X11, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // j           L_80035670
    // sb          $v0, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r2;
    goto L_80035670;
    // sb          $v0, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r2;
L_80035630:
    // lhu         $v1, -0xE($s0)
    ctx->r3 = MEM_HU(-0XE, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lbu         $a1, 0xC($s1)
    ctx->r5 = MEM_BU(0XC, ctx->r17);
    // jal         0x80034B44
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80034B44(rdram, ctx);
    goto after_19;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_19:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // and         $v1, $s2, $v1
    ctx->r3 = ctx->r18 & ctx->r3;
    // bne         $v1, $zero, L_80035534
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80035534;
    }
    // nop

L_80035670:
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
L_80035678:
    // addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80035210
    if (ctx->r2 != ctx->r3) {
        // addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
        goto L_80035210;
    }
    // addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x80
    ctx->r5 = 0 | 0X80;
    // ori         $a2, $zero, 0x100
    ctx->r6 = 0 | 0X100;
    // ori         $a3, $zero, 0x140
    ctx->r7 = 0 | 0X140;
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // jal         0x80034DFC
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80034DFC(rdram, ctx);
    goto after_20;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_20:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // ori         $a1, $zero, 0x60
    ctx->r5 = 0 | 0X60;
    // ori         $a2, $zero, 0x42
    ctx->r6 = 0 | 0X42;
    // ori         $a3, $zero, 0x40
    ctx->r7 = 0 | 0X40;
    // addiu       $v0, $sp, 0x198
    ctx->r2 = ADD32(ctx->r29, 0X198);
    // jal         0x80034D08
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80034D08(rdram, ctx);
    goto after_21;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_21:
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // addiu       $s4, $s4, -0x1280
    ctx->r20 = ADD32(ctx->r20, -0X1280);
    // ori         $s6, $zero, 0x7F
    ctx->r22 = 0 | 0X7F;
    // addiu       $s7, $zero, -0x3C
    ctx->r23 = ADD32(0, -0X3C);
    // addiu       $s0, $s4, 0x9
    ctx->r16 = ADD32(ctx->r20, 0X9);
    // addiu       $s3, $s4, 0x3C
    ctx->r19 = ADD32(ctx->r20, 0X3C);
    // addiu       $s2, $s4, 0x2C
    ctx->r18 = ADD32(ctx->r20, 0X2C);
    // addiu       $s5, $s4, 0x24
    ctx->r21 = ADD32(ctx->r20, 0X24);
    // addiu       $s1, $s4, 0x14
    ctx->r17 = ADD32(ctx->r20, 0X14);
L_800356F0:
    // lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(0X0, ctx->r20);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80035928
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80035928;
    }
    // nop

    // lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(-0X1, ctx->r16);
    // nop

    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $zero, L_80035928
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80035928;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_80035738
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80035738;
    }
    // nop

    // jal         0x80034AD4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80034AD4(rdram, ctx);
    goto after_22;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_22:
    // lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(0X1, ctx->r16);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80035928
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035928;
    }
    // nop

L_80035738:
    // lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(-0X1, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xC
    ctx->r3 = ctx->r2 & 0XC;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $v1, $v0, L_8003580C
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_8003580C;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80035768
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035768;
    }
    // nop

    // beq         $v1, $zero, L_80035784
    if (ctx->r3 == 0) {
        // addu        $a2, $s1, $zero
        ctx->r6 = ADD32(ctx->r17, 0);
        goto L_80035784;
    }
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // j           L_8003592C
    // addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    goto L_8003592C;
    // addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
L_80035768:
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // beq         $v1, $v0, L_8003586C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xC
        ctx->r2 = 0 | 0XC;
        goto L_8003586C;
    }
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // beq         $v1, $v0, L_800358CC
    if (ctx->r3 == ctx->r2) {
        // addu        $a2, $s1, $zero
        ctx->r6 = ADD32(ctx->r17, 0);
        goto L_800358CC;
    }
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // j           L_8003592C
    // addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    goto L_8003592C;
    // addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
L_80035784:
    // lhu         $v0, 0x1B($s0)
    ctx->r2 = MEM_HU(0X1B, ctx->r16);
    // nop

    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1D($s0)
    ctx->r2 = MEM_HU(0X1D, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1F($s0)
    ctx->r2 = MEM_HU(0X1F, ctx->r16);
    // nop

    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(0X1, ctx->r16);
    // lbu         $a1, -0x6($s0)
    ctx->r5 = MEM_BU(-0X6, ctx->r16);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4ECC
    ctx->r2 = ADD32(ctx->r2, 0X4ECC);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x9($s0)
    ctx->r2 = MEM_HU(0X9, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // nop

    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x7($s0)
    ctx->r2 = MEM_H(0X7, ctx->r16);
    // addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // j           L_80035920
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    goto L_80035920;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8003580C:
    // lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(0X1, ctx->r16);
    // lbu         $a1, -0x6($s0)
    ctx->r5 = MEM_BU(-0X6, ctx->r16);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // addiu       $v0, $v0, 0x79F4
    ctx->r2 = ADD32(ctx->r2, 0X79F4);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x9($s0)
    ctx->r2 = MEM_HU(0X9, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x7($s0)
    ctx->r2 = MEM_H(0X7, ctx->r16);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // j           L_80035920
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    goto L_80035920;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8003586C:
    // lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(0X1, ctx->r16);
    // lbu         $a1, -0x6($s0)
    ctx->r5 = MEM_BU(-0X6, ctx->r16);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4EEC
    ctx->r2 = ADD32(ctx->r2, 0X4EEC);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x9($s0)
    ctx->r2 = MEM_HU(0X9, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x7($s0)
    ctx->r2 = MEM_H(0X7, ctx->r16);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // j           L_80035920
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    goto L_80035920;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_800358CC:
    // lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(0X1, ctx->r16);
    // lbu         $a1, -0x6($s0)
    ctx->r5 = MEM_BU(-0X6, ctx->r16);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x9($s0)
    ctx->r2 = MEM_HU(0X9, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x7($s0)
    ctx->r2 = MEM_H(0X7, ctx->r16);
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
L_80035920:
    // jal         0x80034304
    // nop

    sub_80034304(rdram, ctx);
    goto after_23;
    // nop

    after_23:
L_80035928:
    // addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
L_8003592C:
    // addiu       $s3, $s3, 0x48
    ctx->r19 = ADD32(ctx->r19, 0X48);
    // addiu       $s2, $s2, 0x48
    ctx->r18 = ADD32(ctx->r18, 0X48);
    // addiu       $s5, $s5, 0x48
    ctx->r21 = ADD32(ctx->r21, 0X48);
    // addiu       $s1, $s1, 0x48
    ctx->r17 = ADD32(ctx->r17, 0X48);
    // addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_800356F0
    if (ctx->r2 != ctx->r3) {
        // addiu       $s4, $s4, 0x48
        ctx->r20 = ADD32(ctx->r20, 0X48);
        goto L_800356F0;
    }
    // addiu       $s4, $s4, 0x48
    ctx->r20 = ADD32(ctx->r20, 0X48);
    // lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // addiu       $s2, $s2, 0x7228
    ctx->r18 = ADD32(ctx->r18, 0X7228);
    // ori         $s6, $zero, 0x7F
    ctx->r22 = 0 | 0X7F;
    // addiu       $s0, $s2, 0x5
    ctx->r16 = ADD32(ctx->r18, 0X5);
    // sh          $zero, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = 0;
    // sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
L_80035974:
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80035A70
    if (ctx->r3 == ctx->r2) {
        // addiu       $s1, $s2, 0x8
        ctx->r17 = ADD32(ctx->r18, 0X8);
        goto L_80035A70;
    }
    // addiu       $s1, $s2, 0x8
    ctx->r17 = ADD32(ctx->r18, 0X8);
    // jal         0x80034AD4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80034AD4(rdram, ctx);
    goto after_24;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_24:
    // lbu         $a0, -0x3($s0)
    ctx->r4 = MEM_BU(-0X3, ctx->r16);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_800359F4
    if (ctx->r2 == 0) {
        // addu        $a2, $s1, $zero
        ctx->r6 = ADD32(ctx->r17, 0);
        goto L_800359F4;
    }
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4EEC
    ctx->r2 = ADD32(ctx->r2, 0X4EEC);
    // lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(0X0, ctx->r18);
    // addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // jal         0x80034304
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    sub_80034304(rdram, ctx);
    goto after_25;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_25:
L_800359F4:
    // lbu         $v1, -0x1($s0)
    ctx->r3 = MEM_BU(-0X1, ctx->r16);
    // nop

    // beq         $v1, $zero, L_80035A70
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80035A70;
    }
    // nop

    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x7224($v0)
    ctx->r2 = MEM_W(0X7224, ctx->r2);
    // nop

    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80035A20
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80035A20;
    }
    // nop

    // break       7
    do_break(2147703324);
L_80035A20:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80035A38
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80035A38;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80035A38
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80035A38;
    }
    // nop

    // break       6
    do_break(2147703348);
L_80035A38:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_80035A70
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80035A70;
    }
    // nop

    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // lbu         $v1, -0x2($s0)
    ctx->r3 = MEM_BU(-0X2, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80035A70
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035A70;
    }
    // nop

    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80035A70:
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80035974
    if (ctx->r2 != ctx->r3) {
        // addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
        goto L_80035974;
    }
    // addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0x7224
    ctx->r3 = ADD32(ctx->r3, 0X7224);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $ra, 0x2FC($sp)
    ctx->r31 = MEM_W(0X2FC, ctx->r29);
    // lw          $fp, 0x2F8($sp)
    ctx->r30 = MEM_W(0X2F8, ctx->r29);
    // lw          $s7, 0x2F4($sp)
    ctx->r23 = MEM_W(0X2F4, ctx->r29);
    // lw          $s6, 0x2F0($sp)
    ctx->r22 = MEM_W(0X2F0, ctx->r29);
    // lw          $s5, 0x2EC($sp)
    ctx->r21 = MEM_W(0X2EC, ctx->r29);
    // lw          $s4, 0x2E8($sp)
    ctx->r20 = MEM_W(0X2E8, ctx->r29);
    // lw          $s3, 0x2E4($sp)
    ctx->r19 = MEM_W(0X2E4, ctx->r29);
    // lw          $s2, 0x2E0($sp)
    ctx->r18 = MEM_W(0X2E0, ctx->r29);
    // lw          $s1, 0x2DC($sp)
    ctx->r17 = MEM_W(0X2DC, ctx->r29);
    // lw          $s0, 0x2D8($sp)
    ctx->r16 = MEM_W(0X2D8, ctx->r29);
    // addiu       $sp, $sp, 0x300
    ctx->r29 = ADD32(ctx->r29, 0X300);
    // jr          $ra
    // nop

    return;
    // nop

;}
