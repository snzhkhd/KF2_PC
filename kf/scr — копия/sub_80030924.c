#include "recomp.h"
#include "disable_warnings.h"

void sub_80030924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6) << 5;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // jal         0x8002FFD4
    // sh          $a2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r6;
    sub_8002FFD4(rdram, ctx);
    goto after_0;
    // sh          $a2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r6;
    after_0:
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, 0x250
    ctx->r5 = ADD32(ctx->r5, 0X250);
    // lw          $fp, 0x14($v0)
    ctx->r30 = MEM_W(0X14, ctx->r2);
    // lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(0X10, ctx->r2);
    // lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(0X0, ctx->r5);
    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $s1, $v1, $a0
    ctx->r17 = ADD32(ctx->r3, ctx->r4);
    // addu        $v1, $fp, $zero
    ctx->r3 = ADD32(ctx->r30, 0);
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // beq         $v1, $zero, L_80031000
    if (ctx->r3 == 0) {
        // addu        $s7, $v0, $a0
        ctx->r23 = ADD32(ctx->r2, ctx->r4);
        goto L_80031000;
    }
    // addu        $s7, $v0, $a0
    ctx->r23 = ADD32(ctx->r2, ctx->r4);
    // addiu       $s6, $a1, 0x9F8
    ctx->r22 = ADD32(ctx->r5, 0X9F8);
    // lui         $t0, 0x5555
    ctx->r8 = S32(0X5555 << 16);
    // ori         $t0, $t0, 0x5556
    ctx->r8 = ctx->r8 | 0X5556;
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_800309A8:
    // lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(0X0, ctx->r17);
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // srl         $v0, $t0, 24
    ctx->r2 = S32(U32(ctx->r8) >> 24);
    // andi        $v1, $v0, 0xFD
    ctx->r3 = ctx->r2 & 0XFD;
    // ori         $v0, $zero, 0x34
    ctx->r2 = 0 | 0X34;
    // beq         $v1, $v0, L_80030B78
    if (ctx->r3 == ctx->r2) {
        // sw          $t0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r8;
        goto L_80030B78;
    }
    // sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // slti        $v0, $v1, 0x35
    ctx->r2 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    // beq         $v0, $zero, L_800309E8
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x24
        ctx->r2 = 0 | 0X24;
        goto L_800309E8;
    }
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // beq         $v1, $v0, L_800309FC
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x2C
        ctx->r2 = 0 | 0X2C;
        goto L_800309FC;
    }
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // beq         $v1, $v0, L_80030E58
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80030E58;
    }
    // nop

    // j           L_80030FE0
    // nop

    goto L_80030FE0;
    // nop

L_800309E8:
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // beq         $v1, $v0, L_80030CF8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80030CF8;
    }
    // nop

    // j           L_80030FE0
    // nop

    goto L_80030FE0;
    // nop

L_800309FC:
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(0X12, ctx->r17);
    // addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
    // addu        $s4, $v1, $s6
    ctx->r20 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(0X0, ctx->r20);
    // addu        $s3, $v0, $s6
    ctx->r19 = ADD32(ctx->r2, ctx->r22);
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x20
    ctx->r2 = ADD32(ctx->r16, 0X20);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80031000
    if (ctx->r2 != 0) {
        // addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
        goto L_80031000;
    }
    // addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // andi        $v0, $v0, 0xFF9F
    ctx->r2 = ctx->r2 & 0XFF9F;
    // or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // lh          $v0, 0x6($s2)
    ctx->r2 = MEM_H(0X6, ctx->r18);
    // lh          $v1, 0x6($s3)
    ctx->r3 = MEM_H(0X6, ctx->r19);
    // lh          $a0, 0x6($s4)
    ctx->r4 = MEM_H(0X6, ctx->r20);
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(0XC, ctx->r17);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // mfhi        $a2
    ctx->r6 = hi;
    // jal         0x8005F408
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    KF_NormalColorDpq(rdram, ctx);
    goto after_2;
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    after_2:
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x26
    ctx->r2 = 0 | 0X26;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(0X4, ctx->r18);
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_H(0X4, ctx->r19);
    // lh          $a0, 0x4($s4)
    ctx->r4 = MEM_H(0X4, ctx->r20);
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(0X20, ctx->r29);
    // nop

    // addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // sltiu       $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 < 0X2000 ? 1 : 0;
    // beq         $v0, $zero, L_80030FE0
    if (ctx->r2 == 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80030FE0;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lw          $v0, -0xAEC($s6)
    ctx->r2 = MEM_W(-0XAEC, ctx->r22);
    // j           L_80030FD8
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    goto L_80030FD8;
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
L_80030B78:
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // lhu         $v1, 0x16($s1)
    ctx->r3 = MEM_HU(0X16, ctx->r17);
    // addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
    // addu        $s4, $v1, $s6
    ctx->r20 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(0X0, ctx->r20);
    // addu        $s3, $v0, $s6
    ctx->r19 = ADD32(ctx->r2, ctx->r22);
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80031000
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80031000;
    }
    // nop

    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // andi        $v0, $v0, 0xFF9F
    ctx->r2 = ctx->r2 & 0XFF9F;
    // or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // addiu       $a3, $a3, 0x636C
    ctx->r7 = ADD32(ctx->r7, 0X636C);
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(0XC, ctx->r17);
    // lhu         $a1, 0x10($s1)
    ctx->r5 = MEM_HU(0X10, ctx->r17);
    // lhu         $a2, 0x14($s1)
    ctx->r6 = MEM_HU(0X14, ctx->r17);
    // lh          $v1, 0x6($s2)
    ctx->r3 = MEM_H(0X6, ctx->r18);
    // addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x10
    ctx->r2 = ADD32(ctx->r16, 0X10);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x1C
    ctx->r2 = ADD32(ctx->r16, 0X1C);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // addu        $a1, $s7, $a1
    ctx->r5 = ADD32(ctx->r23, ctx->r5);
    // addu        $a2, $s7, $a2
    ctx->r6 = ADD32(ctx->r23, ctx->r6);
    // jal         0x8005F42C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    KF_NormalColorDpq3(rdram, ctx);
    goto after_4;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_4:
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x36
    ctx->r2 = 0 | 0X36;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(0X4, ctx->r18);
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_H(0X4, ctx->r19);
    // lh          $a0, 0x4($s4)
    ctx->r4 = MEM_H(0X4, ctx->r20);
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(0X20, ctx->r29);
    // nop

    // addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // sltiu       $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 < 0X2000 ? 1 : 0;
    // beq         $v0, $zero, L_80030FE0
    if (ctx->r2 == 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80030FE0;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lw          $v0, -0xAEC($s6)
    ctx->r2 = MEM_W(-0XAEC, ctx->r22);
    // j           L_80030FD8
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    goto L_80030FD8;
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
L_80030CF8:
    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // lhu         $v1, 0x1A($s1)
    ctx->r3 = MEM_HU(0X1A, ctx->r17);
    // addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
    // addu        $s4, $v1, $s6
    ctx->r20 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(0X16, ctx->r17);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(0X0, ctx->r20);
    // addu        $s3, $v0, $s6
    ctx->r19 = ADD32(ctx->r2, ctx->r22);
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lhu         $a0, 0x1E($s1)
    ctx->r4 = MEM_HU(0X1E, ctx->r17);
    // addiu       $v0, $s0, 0x34
    ctx->r2 = ADD32(ctx->r16, 0X34);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80031000
    if (ctx->r2 != 0) {
        // addu        $s5, $a0, $s6
        ctx->r21 = ADD32(ctx->r4, ctx->r22);
        goto L_80031000;
    }
    // addu        $s5, $a0, $s6
    ctx->r21 = ADD32(ctx->r4, ctx->r22);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // andi        $v0, $v0, 0xFF9F
    ctx->r2 = ctx->r2 & 0XFF9F;
    // or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // addiu       $a3, $a3, 0x636C
    ctx->r7 = ADD32(ctx->r7, 0X636C);
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // lhu         $a0, 0x10($s1)
    ctx->r4 = MEM_HU(0X10, ctx->r17);
    // lhu         $a1, 0x14($s1)
    ctx->r5 = MEM_HU(0X14, ctx->r17);
    // lhu         $a2, 0x18($s1)
    ctx->r6 = MEM_HU(0X18, ctx->r17);
    // lh          $v1, 0x6($s2)
    ctx->r3 = MEM_H(0X6, ctx->r18);
    // addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x10
    ctx->r2 = ADD32(ctx->r16, 0X10);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x1C
    ctx->r2 = ADD32(ctx->r16, 0X1C);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // addu        $a1, $s7, $a1
    ctx->r5 = ADD32(ctx->r23, ctx->r5);
    // addu        $a2, $s7, $a2
    ctx->r6 = ADD32(ctx->r23, ctx->r6);
    // jal         0x8005F42C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    KF_NormalColorDpq3(rdram, ctx);
    goto after_6;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_6:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // lhu         $a0, 0x1C($s1)
    ctx->r4 = MEM_HU(0X1C, ctx->r17);
    // lh          $a2, 0x6($s2)
    ctx->r6 = MEM_H(0X6, ctx->r18);
    // jal         0x8005F408
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    KF_NormalColorDpq(rdram, ctx);
    goto after_7;
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    after_7:
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // j           L_80030F88
    // ori         $v0, $zero, 0x3E
    ctx->r2 = 0 | 0X3E;
    goto L_80030F88;
    // ori         $v0, $zero, 0x3E
    ctx->r2 = 0 | 0X3E;
L_80030E58:
    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // lhu         $v1, 0x16($s1)
    ctx->r3 = MEM_HU(0X16, ctx->r17);
    // addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
    // addu        $s4, $v1, $s6
    ctx->r20 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(0X0, ctx->r20);
    // addu        $s3, $v0, $s6
    ctx->r19 = ADD32(ctx->r2, ctx->r22);
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lhu         $a0, 0x18($s1)
    ctx->r4 = MEM_HU(0X18, ctx->r17);
    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80031000
    if (ctx->r2 != 0) {
        // addu        $s5, $a0, $s6
        ctx->r21 = ADD32(ctx->r4, ctx->r22);
        goto L_80031000;
    }
    // addu        $s5, $a0, $s6
    ctx->r21 = ADD32(ctx->r4, ctx->r22);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // andi        $v0, $v0, 0xFF9F
    ctx->r2 = ctx->r2 & 0XFF9F;
    // or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $a0, 0x10($s1)
    ctx->r4 = MEM_HU(0X10, ctx->r17);
    // lh          $a2, 0x6($s2)
    ctx->r6 = MEM_H(0X6, ctx->r18);
    // lh          $v0, 0x6($s3)
    ctx->r2 = MEM_H(0X6, ctx->r19);
    // lh          $v1, 0x6($s5)
    ctx->r3 = MEM_H(0X6, ctx->r21);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lh          $v0, 0x6($s4)
    ctx->r2 = MEM_H(0X6, ctx->r20);
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // jal         0x8005F408
    // sra         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) >> 2;
    KF_NormalColorDpq(rdram, ctx);
    goto after_9;
    // sra         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) >> 2;
    after_9:
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2E
    ctx->r2 = 0 | 0X2E;
L_80030F88:
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(0X4, ctx->r18);
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_H(0X4, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(0X4, ctx->r20);
    // lh          $a0, 0x4($s5)
    ctx->r4 = MEM_H(0X4, ctx->r21);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // blez        $v0, L_80030FE0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80030FE0;
    }
    // nop

    // lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(0X20, ctx->r29);
    // nop

    // addu        $a0, $v0, $t0
    ctx->r4 = ADD32(ctx->r2, ctx->r8);
    // sltiu       $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 < 0X2000 ? 1 : 0;
    // beq         $v0, $zero, L_80030FE0
    if (ctx->r2 == 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80030FE0;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lw          $v0, -0xAEC($s6)
    ctx->r2 = MEM_W(-0XAEC, ctx->r22);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
L_80030FD8:
    // jal         0x80067238
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_10;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_10:
L_80030FE0:
    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // nop

    // srl         $v0, $t0, 6
    ctx->r2 = S32(U32(ctx->r8) >> 6);
    // andi        $v0, $v0, 0x3FC
    ctx->r2 = ctx->r2 & 0X3FC;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // addu        $v0, $fp, $zero
    ctx->r2 = ADD32(ctx->r30, 0);
    // bne         $v0, $zero, L_800309A8
    if (ctx->r2 != 0) {
        // addiu       $fp, $fp, -0x1
        ctx->r30 = ADD32(ctx->r30, -0X1);
        goto L_800309A8;
    }
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
L_80031000:
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(0X60, ctx->r29);
    // lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
