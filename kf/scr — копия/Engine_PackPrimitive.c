#include "recomp.h"
#include "disable_warnings.h"

void Engine_PackPrimitive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80062B80
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
    memset_recomp(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
    after_0:
    // lui         $v1, 0xFDFF
    ctx->r3 = S32(0XFDFF << 16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // lui         $a0, 0x2D01
    ctx->r4 = S32(0X2D01 << 16);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // ori         $a0, $a0, 0x709
    ctx->r4 = ctx->r4 | 0X709;
    // and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // beq         $v1, $a0, L_80066D1C
    if (ctx->r3 == ctx->r4) {
        // sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80066D1C;
    }
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80065F80
    if (ctx->r2 != 0) {
        // lui         $v0, 0x3501
        ctx->r2 = S32(0X3501 << 16);
        goto L_80065F80;
    }
    // lui         $v0, 0x3501
    ctx->r2 = S32(0X3501 << 16);
    // lui         $v0, 0x2501
    ctx->r2 = S32(0X2501 << 16);
    // ori         $v0, $v0, 0x607
    ctx->r2 = ctx->r2 | 0X607;
    // beq         $v1, $v0, L_800664EC
    if (ctx->r3 == ctx->r2) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_800664EC;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80065F40
    if (ctx->r2 != 0) {
        // lui         $v0, 0x2901
        ctx->r2 = S32(0X2901 << 16);
        goto L_80065F40;
    }
    // lui         $v0, 0x2901
    ctx->r2 = S32(0X2901 << 16);
    // lui         $v0, 0x2101
    ctx->r2 = S32(0X2101 << 16);
    // ori         $v0, $v0, 0x304
    ctx->r2 = ctx->r2 | 0X304;
    // beq         $v1, $v0, L_8006637C
    if (ctx->r3 == ctx->r2) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_8006637C;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80065F2C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x2400
        ctx->r2 = S32(0X2400 << 16);
        goto L_80065F2C;
    }
    // lui         $v0, 0x2400
    ctx->r2 = S32(0X2400 << 16);
    // lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // ori         $v0, $v0, 0x304
    ctx->r2 = ctx->r2 | 0X304;
    // beq         $v1, $v0, L_80066024
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_80066024;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80065F2C:
    // ori         $v0, $v0, 0x507
    ctx->r2 = ctx->r2 | 0X507;
    // beq         $v1, $v0, L_800661DC
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_800661DC;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80065F40:
    // ori         $v0, $v0, 0x305
    ctx->r2 = ctx->r2 | 0X305;
    // beq         $v1, $v0, L_80066B4C
    if (ctx->r3 == ctx->r2) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_80066B4C;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80065F6C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x2C00
        ctx->r2 = S32(0X2C00 << 16);
        goto L_80065F6C;
    }
    // lui         $v0, 0x2C00
    ctx->r2 = S32(0X2C00 << 16);
    // lui         $v0, 0x2800
    ctx->r2 = S32(0X2800 << 16);
    // ori         $v0, $v0, 0x405
    ctx->r2 = ctx->r2 | 0X405;
    // beq         $v1, $v0, L_8006671C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_8006671C;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80065F6C:
    // ori         $v0, $v0, 0x709
    ctx->r2 = ctx->r2 | 0X709;
    // beq         $v1, $v0, L_8006694C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_8006694C;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80065F80:
    // ori         $v0, $v0, 0x809
    ctx->r2 = ctx->r2 | 0X809;
    // beq         $v1, $v0, L_80066604
    if (ctx->r3 == ctx->r2) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_80066604;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80065FD8
    if (ctx->r2 != 0) {
        // lui         $v0, 0x3901
        ctx->r2 = S32(0X3901 << 16);
        goto L_80065FD8;
    }
    // lui         $v0, 0x3901
    ctx->r2 = S32(0X3901 << 16);
    // lui         $v0, 0x3101
    ctx->r2 = S32(0X3101 << 16);
    // ori         $v0, $v0, 0x506
    ctx->r2 = ctx->r2 | 0X506;
    // beq         $v1, $v0, L_80066434
    if (ctx->r3 == ctx->r2) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_80066434;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80065FC4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x3400
        ctx->r2 = S32(0X3400 << 16);
        goto L_80065FC4;
    }
    // lui         $v0, 0x3400
    ctx->r2 = S32(0X3400 << 16);
    // lui         $v0, 0x3000
    ctx->r2 = S32(0X3000 << 16);
    // ori         $v0, $v0, 0x406
    ctx->r2 = ctx->r2 | 0X406;
    // beq         $v1, $v0, L_80066100
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_80066100;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80065FC4:
    // ori         $v0, $v0, 0x609
    ctx->r2 = ctx->r2 | 0X609;
    // beq         $v1, $v0, L_800662AC
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_800662AC;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80065FD8:
    // ori         $v0, $v0, 0x608
    ctx->r2 = ctx->r2 | 0X608;
    // beq         $v1, $v0, L_80066C34
    if (ctx->r3 == ctx->r2) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_80066C34;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80066004
    if (ctx->r2 != 0) {
        // lui         $v0, 0x3C00
        ctx->r2 = S32(0X3C00 << 16);
        goto L_80066004;
    }
    // lui         $v0, 0x3C00
    ctx->r2 = S32(0X3C00 << 16);
    // lui         $v0, 0x3800
    ctx->r2 = S32(0X3800 << 16);
    // ori         $v0, $v0, 0x508
    ctx->r2 = ctx->r2 | 0X508;
    // beq         $v1, $v0, L_80066834
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_80066834;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80066004:
    // ori         $v0, $v0, 0x80C
    ctx->r2 = ctx->r2 | 0X80C;
    // beq         $v1, $v0, L_80066A4C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x3D01
        ctx->r2 = S32(0X3D01 << 16);
        goto L_80066A4C;
    }
    // lui         $v0, 0x3D01
    ctx->r2 = S32(0X3D01 << 16);
    // ori         $v0, $v0, 0xA0C
    ctx->r2 = ctx->r2 | 0XA0C;
    // beq         $v1, $v0, L_80066E7C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
        goto L_80066E7C;
    }
    // lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // j           L_80066FDC
    // nop

    goto L_80066FDC;
    // nop

L_80066024:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066048
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066048;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3900
    ctx->r4 = ADD32(ctx->r4, 0X3900);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80066048:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80066FF8
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
L_80066100:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066124
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066124;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3908
    ctx->r4 = ADD32(ctx->r4, 0X3908);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80066124:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(0X10, ctx->r16);
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // j           L_80066FF8
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
L_800661DC:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066200
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066200;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3910
    ctx->r4 = ADD32(ctx->r4, 0X3910);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_80066200:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(0X10, ctx->r16);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // j           L_80066FF8
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
L_800662AC:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_800662D0
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800662D0;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3918
    ctx->r4 = ADD32(ctx->r4, 0X3918);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_800662D0:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(0X1A, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x18($s0)
    ctx->r3 = MEM_HU(0X18, ctx->r16);
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // j           L_80066FF8
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r3;
L_8006637C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_800663A0
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800663A0;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3920
    ctx->r4 = ADD32(ctx->r4, 0X3920);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_800663A0:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(0XC, ctx->r16);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80066FF8
    // sh          $v1, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r3;
L_80066434:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066458
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066458;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3924
    ctx->r4 = ADD32(ctx->r4, 0X3924);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_80066458:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xE($s0)
    ctx->r2 = MEM_BU(0XE, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(0X14, ctx->r16);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // j           L_80066FF8
    // sh          $v1, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r3;
L_800664EC:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066510
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066510;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3928
    ctx->r4 = ADD32(ctx->r4, 0X3928);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_80066510:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x18($s0)
    ctx->r3 = MEM_HU(0X18, ctx->r16);
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // j           L_80066FF8
    // sh          $v1, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r3;
L_80066604:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066628
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066628;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3930
    ctx->r4 = ADD32(ctx->r4, 0X3930);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_16;
    // nop

    after_16:
L_80066628:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(0X16, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(0X18, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x19($s0)
    ctx->r2 = MEM_BU(0X19, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(0X1A, ctx->r16);
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // j           L_80066FF8
    // sb          $v1, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sb          $v1, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r3;
L_8006671C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066740
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066740;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3938
    ctx->r4 = ADD32(ctx->r4, 0X3938);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_18;
    // nop

    after_18:
L_80066740:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // j           L_80066FF8
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
L_80066834:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066858
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066858;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3940
    ctx->r4 = ADD32(ctx->r4, 0X3940);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_20;
    // nop

    after_20:
L_80066858:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // nop

    // sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(0X14, ctx->r16);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // j           L_80066FF8
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
L_8006694C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066970
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066970;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3948
    ctx->r4 = ADD32(ctx->r4, 0X3948);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_22;
    // nop

    after_22:
L_80066970:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x1F($s1)
    MEM_B(0X1F, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(0X1A, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // nop

    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(0X14, ctx->r16);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // j           L_80066FF8
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
L_80066A4C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066A70
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066A70;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3950
    ctx->r4 = ADD32(ctx->r4, 0X3950);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_24;
    // nop

    after_24:
L_80066A70:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x1F($s1)
    MEM_B(0X1F, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(0X1A, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(0X22, ctx->r16);
    // nop

    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // nop

    // sh          $v0, 0x74($s1)
    MEM_H(0X74, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(0X20, ctx->r16);
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // j           L_80066FF8
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x76($s1)
    MEM_H(0X76, ctx->r17) = ctx->r3;
L_80066B4C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066B70
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066B70;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3958
    ctx->r4 = ADD32(ctx->r4, 0X3958);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_26;
    // nop

    after_26:
L_80066B70:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v1, 0xE($s0)
    ctx->r3 = MEM_HU(0XE, ctx->r16);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80066FF8
    // sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
L_80066C34:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_27;
    // nop

    after_27:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066C58
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066C58;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x395C
    ctx->r4 = ADD32(ctx->r4, 0X395C);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_28;
    // nop

    after_28:
L_80066C58:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xE($s0)
    ctx->r2 = MEM_BU(0XE, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x1A($s0)
    ctx->r3 = MEM_HU(0X1A, ctx->r16);
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // j           L_80066FF8
    // sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
L_80066D1C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066D40
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066D40;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3960
    ctx->r4 = ADD32(ctx->r4, 0X3960);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_30;
    // nop

    after_30:
L_80066D40:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x1F($s1)
    MEM_B(0X1F, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(0X16, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(0X16, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(0X16, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(0X16, ctx->r16);
    // nop

    // sb          $v0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(0X1A, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x1E($s0)
    ctx->r3 = MEM_HU(0X1E, ctx->r16);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // j           L_80066FF8
    // sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
L_80066E7C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_80066EA0
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80066EA0;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3968
    ctx->r4 = ADD32(ctx->r4, 0X3968);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_32;
    // nop

    after_32:
L_80066EA0:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // nop

    // sb          $v0, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(0X9, ctx->r16);
    // nop

    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(0XC, ctx->r16);
    // nop

    // sb          $v0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // sb          $v0, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // sb          $v0, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // sb          $v0, 0x1F($s1)
    MEM_B(0X1F, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(0X24, ctx->r16);
    // nop

    // sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x26($s0)
    ctx->r2 = MEM_HU(0X26, ctx->r16);
    // nop

    // sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(0X28, ctx->r16);
    // nop

    // sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(0X2A, ctx->r16);
    // nop

    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x16($s0)
    ctx->r2 = MEM_BU(0X16, ctx->r16);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(0X18, ctx->r16);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x19($s0)
    ctx->r2 = MEM_BU(0X19, ctx->r16);
    // nop

    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(0X1A, ctx->r16);
    // nop

    // sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x1C($s0)
    ctx->r2 = MEM_BU(0X1C, ctx->r16);
    // nop

    // sb          $v0, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x1D($s0)
    ctx->r2 = MEM_BU(0X1D, ctx->r16);
    // nop

    // sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x1E($s0)
    ctx->r2 = MEM_BU(0X1E, ctx->r16);
    // nop

    // sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(0X20, ctx->r16);
    // nop

    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // nop

    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lbu         $v1, 0x22($s0)
    ctx->r3 = MEM_BU(0X22, ctx->r16);
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // j           L_80066FF8
    // sb          $v1, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r3;
    goto L_80066FF8;
    // sb          $v1, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r3;
L_80066FDC:
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3970
    ctx->r4 = ADD32(ctx->r4, 0X3970);
    // jal         0x80062BA0
    // and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    psx_printf(rdram, ctx);
    goto after_33;
    // and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    after_33:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80066FF8:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
