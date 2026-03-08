#include "recomp.h"
#include "disable_warnings.h"

void RenderItemList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // lw          $s7, 0x24($s2)
    ctx->r23 = MEM_W(0X24, ctx->r18);
    // lw          $s6, 0x28($s2)
    ctx->r22 = MEM_W(0X28, ctx->r18);
    // lw          $s1, 0x30($s2)
    ctx->r17 = MEM_W(0X30, ctx->r18);
    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(0X0, ctx->r18);
    // lw          $s3, 0x2C($s2)
    ctx->r19 = MEM_W(0X2C, ctx->r18);
    // beq         $v0, $zero, L_80022920
    if (ctx->r2 == 0) {
        // addu        $s5, $a1, $zero
        ctx->r21 = ADD32(ctx->r5, 0);
        goto L_80022920;
    }
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7AE4
    ctx->r16 = ADD32(ctx->r16, 0X7AE4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80023944
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    ui_DrawFrame(rdram, ctx);
    goto after_0;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // addiu       $a0, $s0, -0x30
    ctx->r4 = ADD32(ctx->r16, -0X30);
    // jal         0x80023E20
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    ui_DrawText(rdram, ctx);
    goto after_1;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
L_80022920:
    // lbu         $v1, 0x20($s2)
    ctx->r3 = MEM_BU(0X20, ctx->r18);
    // lbu         $v0, 0x23($s2)
    ctx->r2 = MEM_BU(0X23, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s6, $s6, $v0
    ctx->r22 = ADD32(ctx->r22, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // addu        $s3, $s3, $v1
    ctx->r19 = ADD32(ctx->r19, ctx->r3);
    // lbu         $v1, 0x1F($s2)
    ctx->r3 = MEM_BU(0X1F, ctx->r18);
    // mflo        $v0
    ctx->r2 = lo;
    // blez        $v1, L_80022C8C
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $s7, $s7, $v0
        ctx->r23 = ADD32(ctx->r23, ctx->r2);
        goto L_80022C8C;
    }
    // addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // addiu       $s0, $sp, 0x1C
    ctx->r16 = ADD32(ctx->r29, 0X1C);
    // addiu       $v0, $s5, -0x8
    ctx->r2 = ADD32(ctx->r21, -0X8);
    // sltiu       $fp, $v0, 0x2
    ctx->r30 = ctx->r2 < 0X2 ? 1 : 0;
L_8002296C:
    // lbu         $v0, 0x1E($s2)
    ctx->r2 = MEM_BU(0X1E, ctx->r18);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80022C8C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80022C8C;
    }
    // nop

    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // sll         $v0, $s4, 3
    ctx->r2 = S32(ctx->r20) << 3;
    // subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // lbu         $v1, 0x1D($s2)
    ctx->r3 = MEM_BU(0X1D, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // lbu         $v0, 0x23($s2)
    ctx->r2 = MEM_BU(0X23, ctx->r18);
    // nop

    // blez        $v0, L_800229E0
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_800229E0;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800229BC:
    // lbu         $v0, 0x0($s7)
    ctx->r2 = MEM_BU(0X0, ctx->r23);
    // addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x23($s2)
    ctx->r2 = MEM_BU(0X23, ctx->r18);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800229BC
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800229BC;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800229E0:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AB4
    ctx->r4 = ADD32(ctx->r4, 0X7AB4);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_2;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // bne         $s5, $v0, L_80022A40
    if (ctx->r21 != ctx->r2) {
        // addiu       $v0, $s5, -0xA
        ctx->r2 = ADD32(ctx->r21, -0XA);
        goto L_80022A40;
    }
    // addiu       $v0, $s5, -0xA
    ctx->r2 = ADD32(ctx->r21, -0XA);
    // addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
L_80022A10:
    // lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(0X0, ctx->r22);
    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // slti        $v0, $v1, 0x18
    ctx->r2 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80022A10
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80022A10;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AB4
    ctx->r4 = ADD32(ctx->r4, 0X7AB4);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_3;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_3:
    // addiu       $v0, $s5, -0xA
    ctx->r2 = ADD32(ctx->r21, -0XA);
L_80022A40:
    // sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80022AA4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xC
        ctx->r2 = 0 | 0XC;
        goto L_80022AA4;
    }
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // beq         $s5, $v0, L_80022AA8
    if (ctx->r21 == ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80022AA8;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x8C
    ctx->r2 = ADD32(ctx->r2, 0X8C);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // bne         $s5, $v0, L_80022A80
    if (ctx->r21 != ctx->r2) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80022A80;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // j           L_80022A8C
    // ori         $a3, $zero, 0x6
    ctx->r7 = 0 | 0X6;
    goto L_80022A8C;
    // ori         $a3, $zero, 0x6
    ctx->r7 = 0 | 0X6;
L_80022A80:
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // ori         $a3, $zero, 0x2
    ctx->r7 = 0 | 0X2;
L_80022A8C:
    // jal         0x80024B24
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    FormatHUDNumber(rdram, ctx);
    goto after_4;
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    after_4:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_5;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_5:
L_80022AA4:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_80022AA8:
    // beq         $s5, $v0, L_80022AB8
    if (ctx->r21 == ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_80022AB8;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // bne         $s5, $v0, L_80022AF8
    if (ctx->r21 != ctx->r2) {
        // nop
    
        goto L_80022AF8;
    }
    // nop

L_80022AB8:
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_80022AF8
    if (ctx->r4 == ctx->r2) {
        // addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_80022AF8;
    }
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // ori         $a3, $zero, 0x3
    ctx->r7 = 0 | 0X3;
    // addiu       $v0, $v0, 0xBD
    ctx->r2 = ADD32(ctx->r2, 0XBD);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    FormatHUDNumber(rdram, ctx);
    goto after_6;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_6:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_7;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_7:
L_80022AF8:
    // beq         $fp, $zero, L_80022B80
    if (ctx->r30 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80022B80;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // nop

    // beq         $a0, $v0, L_80022B40
    if (ctx->r4 == ctx->r2) {
        // addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_80022B40;
    }
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // ori         $a3, $zero, 0x4
    ctx->r7 = 0 | 0X4;
    // addiu       $v0, $v0, 0x62
    ctx->r2 = ADD32(ctx->r2, 0X62);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    FormatHUDNumber(rdram, ctx);
    goto after_8;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_8:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_9;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_9:
L_80022B40:
    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_80022B80
    if (ctx->r4 == ctx->r2) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80022B80;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    // addiu       $v0, $v0, 0x5B
    ctx->r2 = ADD32(ctx->r2, 0X5B);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    FormatHUDNumber(rdram, ctx);
    goto after_10;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_10:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_11;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_11:
L_80022B80:
    // addiu       $v0, $s5, -0x2
    ctx->r2 = ADD32(ctx->r21, -0X2);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80022BF0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80022BF0;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $s5, $v0, L_80022BEC
    if (ctx->r21 == ctx->r2) {
        // nop
    
        goto L_80022BEC;
    }
    // nop

    // bne         $fp, $zero, L_80022BF0
    if (ctx->r30 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80022BF0;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $s5, $v0, L_80022BF8
    if (ctx->r21 == ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80022BF8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // nop

    // beq         $a0, $v0, L_80022BEC
    if (ctx->r4 == ctx->r2) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80022BEC;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, 0XD0);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    FormatHUDNumber(rdram, ctx);
    goto after_12;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_12:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_13;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_13:
L_80022BEC:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
L_80022BF0:
    // bne         $s5, $v0, L_80022C78
    if (ctx->r21 != ctx->r2) {
        // nop
    
        goto L_80022C78;
    }
    // nop

L_80022BF8:
    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_80022C38
    if (ctx->r4 == ctx->r2) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80022C38;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // addiu       $v0, $v0, 0xCB
    ctx->r2 = ADD32(ctx->r2, 0XCB);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    FormatHUDNumber(rdram, ctx);
    goto after_14;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_14:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_15;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_15:
L_80022C38:
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_80022C78
    if (ctx->r4 == ctx->r2) {
        // addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_80022C78;
    }
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // ori         $a3, $zero, 0x3
    ctx->r7 = 0 | 0X3;
    // addiu       $v0, $v0, 0xBD
    ctx->r2 = ADD32(ctx->r2, 0XBD);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    FormatHUDNumber(rdram, ctx);
    goto after_16;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_16:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_17;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_17:
L_80022C78:
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002296C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002296C;
    }
    // nop

L_80022C8C:
    // jal         0x8002492C
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_18;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    after_18:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lhu         $v0, 0x7AFC($v0)
    ctx->r2 = MEM_HU(0X7AFC, ctx->r2);
    // nop

    // sh          $v0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lhu         $v0, 0x7AFE($v0)
    ctx->r2 = MEM_HU(0X7AFE, ctx->r2);
    // nop

    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // nop

    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1D($s2)
    ctx->r2 = MEM_BU(0X1D, ctx->r18);
    // nop

    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lhu         $v1, 0x7B04($v1)
    ctx->r3 = MEM_HU(0X7B04, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1D($s2)
    ctx->r2 = MEM_BU(0X1D, ctx->r18);
    // nop

    // sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // nop

    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1D($s2)
    ctx->r2 = MEM_BU(0X1D, ctx->r18);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lhu         $v1, 0x7B06($v1)
    ctx->r3 = MEM_HU(0X7B06, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lhu         $v1, 0x7B04($v1)
    ctx->r3 = MEM_HU(0X7B04, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1D($s2)
    ctx->r2 = MEM_BU(0X1D, ctx->r18);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lhu         $v1, 0x7B06($v1)
    ctx->r3 = MEM_HU(0X7B06, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B00($v0)
    ctx->r2 = MEM_BU(0X7B00, ctx->r2);
    // nop

    // sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B02($v0)
    ctx->r2 = MEM_BU(0X7B02, ctx->r2);
    // nop

    // sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B00($v0)
    ctx->r2 = MEM_BU(0X7B00, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B04($v1)
    ctx->r3 = MEM_BU(0X7B04, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B02($v0)
    ctx->r2 = MEM_BU(0X7B02, ctx->r2);
    // nop

    // sb          $v0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B00($v0)
    ctx->r2 = MEM_BU(0X7B00, ctx->r2);
    // nop

    // sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B02($v0)
    ctx->r2 = MEM_BU(0X7B02, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B06($v1)
    ctx->r3 = MEM_BU(0X7B06, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B00($v0)
    ctx->r2 = MEM_BU(0X7B00, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B04($v1)
    ctx->r3 = MEM_BU(0X7B04, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B02($v0)
    ctx->r2 = MEM_BU(0X7B02, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B06($v1)
    ctx->r3 = MEM_BU(0X7B06, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r2;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // jal         0x800672EC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    GPU_Cmd_SetBlendFlag(rdram, ctx);
    goto after_19;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_19:
    // jal         0x80024974
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_20;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    after_20:
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // nop

    // blez        $v0, L_8002300C
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8002300C;
    }
    // nop

    // ori         $s6, $zero, 0xFF
    ctx->r22 = 0 | 0XFF;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80022E54:
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // addiu       $v0, $v0, 0x7B08
    ctx->r2 = ADD32(ctx->r2, 0X7B08);
    // addiu       $s1, $v0, 0xA
    ctx->r17 = ADD32(ctx->r2, 0XA);
    // lbu         $v1, 0x22($s2)
    ctx->r3 = MEM_BU(0X22, ctx->r18);
    // nop

    // bne         $s4, $v1, L_80022E78
    if (ctx->r20 != ctx->r3) {
        // addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
        goto L_80022E78;
    }
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $s1, $s0, 0x22
    ctx->r17 = ADD32(ctx->r16, 0X22);
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_80022E78:
    // jal         0x8002492C
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_21;
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    after_21:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $s6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r22;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $s6, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r22;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $s6, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r22;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sh          $v0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r2;
    // lhu         $v0, -0x8($s1)
    ctx->r2 = MEM_HU(-0X8, ctx->r17);
    // nop

    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // nop

    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1D($s2)
    ctx->r2 = MEM_BU(0X1D, ctx->r18);
    // nop

    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1D($s2)
    ctx->r2 = MEM_BU(0X1D, ctx->r18);
    // nop

    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // nop

    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x1D($s2)
    ctx->r3 = MEM_BU(0X1D, ctx->r18);
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r3;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x1D($s2)
    ctx->r3 = MEM_BU(0X1D, ctx->r18);
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r3;
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // nop

    // sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, -0x4($s1)
    ctx->r2 = MEM_BU(-0X4, ctx->r17);
    // nop

    // sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // lbu         $v1, -0x2($s1)
    ctx->r3 = MEM_BU(-0X2, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, -0x4($s1)
    ctx->r2 = MEM_BU(-0X4, ctx->r17);
    // nop

    // sb          $v0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // nop

    // sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // lbu         $v0, -0x4($s1)
    ctx->r2 = MEM_BU(-0X4, ctx->r17);
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // lbu         $v1, -0x2($s1)
    ctx->r3 = MEM_BU(-0X2, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
    // lbu         $v0, -0x4($s1)
    ctx->r2 = MEM_BU(-0X4, ctx->r17);
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r2;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // jal         0x800672EC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    GPU_Cmd_SetBlendFlag(rdram, ctx);
    goto after_22;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_22:
    // jal         0x80024974
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_23;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    after_23:
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80022E54
    if (ctx->r2 != 0) {
        // addiu       $s3, $s3, 0xE
        ctx->r19 = ADD32(ctx->r19, 0XE);
        goto L_80022E54;
    }
    // addiu       $s3, $s3, 0xE
    ctx->r19 = ADD32(ctx->r19, 0XE);
L_8002300C:
    // jal         0x8002492C
    // nop

    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // lw          $a1, 0xF0($gp)
    ctx->r5 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lhu         $v0, 0x7B14($v0)
    ctx->r2 = MEM_HU(0X7B14, ctx->r2);
    // nop

    // sh          $v0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lhu         $v0, 0x7B16($v0)
    ctx->r2 = MEM_HU(0X7B16, ctx->r2);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // nop

    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x1F($s2)
    ctx->r3 = MEM_BU(0X1F, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x1D($s2)
    ctx->r3 = MEM_BU(0X1D, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lhu         $v1, 0x7B1C($v1)
    ctx->r3 = MEM_HU(0X7B1C, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x1F($s2)
    ctx->r3 = MEM_BU(0X1F, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x1D($s2)
    ctx->r3 = MEM_BU(0X1D, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // sh          $v1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r3;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // nop

    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // lbu         $a0, 0x1D($s2)
    ctx->r4 = MEM_BU(0X1D, ctx->r18);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lhu         $v0, 0x7B1E($v0)
    ctx->r2 = MEM_HU(0X7B1E, ctx->r2);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $a0, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r4;
    // lbu         $v0, 0x1C($s2)
    ctx->r2 = MEM_BU(0X1C, ctx->r18);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lhu         $v1, 0x7B1C($v1)
    ctx->r3 = MEM_HU(0X7B1C, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // lbu         $a0, 0x1D($s2)
    ctx->r4 = MEM_BU(0X1D, ctx->r18);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lhu         $v0, 0x7B1E($v0)
    ctx->r2 = MEM_HU(0X7B1E, ctx->r2);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $a0, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r4;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B18($v0)
    ctx->r2 = MEM_BU(0X7B18, ctx->r2);
    // nop

    // sb          $v0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B1A($v0)
    ctx->r2 = MEM_BU(0X7B1A, ctx->r2);
    // nop

    // sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B18($v0)
    ctx->r2 = MEM_BU(0X7B18, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B1C($v1)
    ctx->r3 = MEM_BU(0X7B1C, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B1A($v0)
    ctx->r2 = MEM_BU(0X7B1A, ctx->r2);
    // nop

    // sb          $v0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B18($v0)
    ctx->r2 = MEM_BU(0X7B18, ctx->r2);
    // nop

    // sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B1A($v0)
    ctx->r2 = MEM_BU(0X7B1A, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B1E($v1)
    ctx->r3 = MEM_BU(0X7B1E, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B18($v0)
    ctx->r2 = MEM_BU(0X7B18, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B1C($v1)
    ctx->r3 = MEM_BU(0X7B1C, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // lbu         $v0, 0x7B1A($v0)
    ctx->r2 = MEM_BU(0X7B1A, ctx->r2);
    // lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // lbu         $v1, 0x7B1E($v1)
    ctx->r3 = MEM_BU(0X7B1E, ctx->r3);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r2;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // jal         0x800672EC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    GPU_Cmd_SetBlendFlag(rdram, ctx);
    goto after_25;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_25:
    // jal         0x80024974
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_26;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    after_26:
    // addiu       $v0, $s5, -0xA
    ctx->r2 = ADD32(ctx->r21, -0XA);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80023240
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_80023240;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addiu       $v0, $s5, -0xD
    ctx->r2 = ADD32(ctx->r21, -0XD);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80023240
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF
        ctx->r2 = 0 | 0XF;
        goto L_80023240;
    }
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // bne         $s5, $v0, L_8002324C
    if (ctx->r21 != ctx->r2) {
        // addiu       $v0, $s5, -0x8
        ctx->r2 = ADD32(ctx->r21, -0X8);
        goto L_8002324C;
    }
    // addiu       $v0, $s5, -0x8
    ctx->r2 = ADD32(ctx->r21, -0X8);
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
L_80023240:
    // jal         0x800234CC
    // nop

    sub_800234CC(rdram, ctx);
    goto after_27;
    // nop

    after_27:
    // addiu       $v0, $s5, -0x8
    ctx->r2 = ADD32(ctx->r21, -0X8);
L_8002324C:
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80023260
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80023260;
    }
    // nop

    // jal         0x800244D8
    // nop

    nullsub_2(rdram, ctx);
    goto after_28;
    // nop

    after_28:
L_80023260:
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(0X70, ctx->r29);
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
