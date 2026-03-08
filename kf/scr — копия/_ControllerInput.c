#include "recomp.h"
#include "disable_warnings.h"

void _ControllerInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A64
    ctx->r16 = ADD32(ctx->r16, -0X4A64);
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79A8($at)
    MEM_B(0X79A8, ctx->r1) = ctx->r2;
    // jal         0x8002E25C
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // addiu       $a0, $s0, -0x7E
    ctx->r4 = ADD32(ctx->r16, -0X7E);
    // addiu       $a1, $s0, -0x7C
    ctx->r5 = ADD32(ctx->r16, -0X7C);
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // jal         0x8002C124
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    sub_8002C124(rdram, ctx);
    goto after_1;
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    after_1:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // beq         $v0, $s1, L_8002C3C4
    if (ctx->r2 == ctx->r17) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_8002C3C4;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    // ori         $a2, $zero, 0xA
    ctx->r6 = 0 | 0XA;
    // jal         0x8002EA88
    // ori         $a3, $zero, 0xEF9
    ctx->r7 = 0 | 0XEF9;
    TriggerLightFlash(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0xEF9
    ctx->r7 = 0 | 0XEF9;
    after_2:
L_8002C3C4:
    // addiu       $a0, $s0, -0x72
    ctx->r4 = ADD32(ctx->r16, -0X72);
    // addiu       $a1, $s0, -0x70
    ctx->r5 = ADD32(ctx->r16, -0X70);
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // jal         0x8002C124
    // ori         $a3, $zero, 0xE10
    ctx->r7 = 0 | 0XE10;
    sub_8002C124(rdram, ctx);
    goto after_3;
    // ori         $a3, $zero, 0xE10
    ctx->r7 = 0 | 0XE10;
    after_3:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $s1, L_8002C3FC
    if (ctx->r2 == ctx->r17) {
        // ori         $a0, $zero, 0xDC
        ctx->r4 = 0 | 0XDC;
        goto L_8002C3FC;
    }
    // ori         $a0, $zero, 0xDC
    ctx->r4 = 0 | 0XDC;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a1, $zero, 0xDC
    ctx->r5 = 0 | 0XDC;
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
    // jal         0x8002EA88
    // ori         $a3, $zero, 0x4650
    ctx->r7 = 0 | 0X4650;
    TriggerLightFlash(rdram, ctx);
    goto after_4;
    // ori         $a3, $zero, 0x4650
    ctx->r7 = 0 | 0X4650;
    after_4:
L_8002C3FC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A00($v0)
    ctx->r2 = MEM_H(-0X4A00, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002C470
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002C470;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49FE($v0)
    ctx->r2 = MEM_HU(-0X49FE, ctx->r2);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A00($at)
    MEM_H(-0X4A00, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8002C43C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8002C43C;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A00($at)
    MEM_H(-0X4A00, ctx->r1) = 0;
L_8002C43C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A00($v0)
    ctx->r2 = MEM_H(-0X4A00, ctx->r2);
    // nop

    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8002C45C
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x3C
        ctx->r4 = 0 | 0X3C;
        goto L_8002C45C;
    }
    // ori         $a0, $zero, 0x3C
    ctx->r4 = 0 | 0X3C;
    // ori         $a3, $zero, 0x1000
    ctx->r7 = 0 | 0X1000;
L_8002C45C:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // jal         0x80034100
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    sub_80034100(rdram, ctx);
    goto after_5;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_5:
L_8002C470:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_6:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x49FA
    ctx->r16 = ADD32(ctx->r16, -0X49FA);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62DC($v1)
    ctx->r3 = MEM_W(0X62DC, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002C4A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C4A8;
    }
    // nop

    // jal         0x800186B8
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    nullsub_1(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    after_7:
L_8002C4A8:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62E0($v1)
    ctx->r3 = MEM_W(0X62E0, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002C4D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C4D4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lhu         $v0, 0x62D0($v0)
    ctx->r2 = MEM_HU(0X62D0, ctx->r2);
    // nop

    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8002C4D4:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62F4($v1)
    ctx->r3 = MEM_W(0X62F4, ctx->r3);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x62F8($a0)
    ctx->r4 = MEM_W(0X62F8, ctx->r4);
    // ori         $v0, $zero, 0xC8
    ctx->r2 = 0 | 0XC8;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49F4($at)
    MEM_W(-0X49F4, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49F0($at)
    MEM_W(-0X49F0, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002C518
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x23
        ctx->r2 = 0 | 0X23;
        goto L_8002C518;
    }
    // ori         $v0, $zero, 0x23
    ctx->r2 = 0 | 0X23;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49F0($at)
    MEM_W(-0X49F0, ctx->r1) = ctx->r2;
L_8002C518:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADE($v0)
    ctx->r2 = MEM_H(-0X4ADE, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002C5CC
    if (ctx->r2 == 0) {
        // slti        $v0, $v0, 0x40
        ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
        goto L_8002C5CC;
    }
    // slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8002C568
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C568;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2E($v0)
    ctx->r2 = MEM_HU(-0X4B2E, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002C59C
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8002C59C;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = 0;
    // j           L_8002C59C
    // nop

    goto L_8002C59C;
    // nop

L_8002C568:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2E($v0)
    ctx->r2 = MEM_HU(-0X4B2E, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x64
    ctx->r2 = ADD32(ctx->r2, -0X64);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0xCE4
    ctx->r2 = SIGNED(ctx->r2) < -0XCE4 ? 1 : 0;
    // beq         $v0, $zero, L_8002C59C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0xCE4
        ctx->r2 = ADD32(0, -0XCE4);
        goto L_8002C59C;
    }
    // addiu       $v0, $zero, -0xCE4
    ctx->r2 = ADD32(0, -0XCE4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = ctx->r2;
L_8002C59C:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x49F0
    ctx->r4 = ADD32(ctx->r4, -0X49F0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4ADE($v1)
    ctx->r3 = MEM_HU(-0X4ADE, ctx->r3);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4ADE($at)
    MEM_H(-0X4ADE, ctx->r1) = ctx->r3;
    // j           L_8002C64C
    // nop

    goto L_8002C64C;
    // nop

L_8002C5CC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4B2F($v0)
    ctx->r2 = MEM_BU(-0X4B2F, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002C620
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002C620;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2E($v0)
    ctx->r2 = MEM_HU(-0X4B2E, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x320
    ctx->r2 = ADD32(ctx->r2, 0X320);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xAF1
    ctx->r2 = SIGNED(ctx->r2) < 0XAF1 ? 1 : 0;
    // bne         $v0, $zero, L_8002C64C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002C64C;
    }
    // nop

    // ori         $v0, $zero, 0xAF0
    ctx->r2 = 0 | 0XAF0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = ctx->r2;
    // j           L_8002C64C
    // nop

    goto L_8002C64C;
    // nop

L_8002C620:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2E($v0)
    ctx->r2 = MEM_HU(-0X4B2E, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x320
    ctx->r2 = ADD32(ctx->r2, -0X320);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8002C64C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8002C64C;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B2E($at)
    MEM_H(-0X4B2E, ctx->r1) = 0;
L_8002C64C:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x49F4
    ctx->r5 = ADD32(ctx->r5, -0X49F4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4B2E($v0)
    ctx->r2 = MEM_H(-0X4B2E, ctx->r2);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4ADC($a0)
    ctx->r4 = MEM_H(-0X4ADC, ctx->r4);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // beq         $a0, $zero, L_8002C6BC
    if (ctx->r4 == 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8002C6BC;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADC($at)
    MEM_H(-0X4ADC, ctx->r1) = ctx->r2;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x49F0($at)
    MEM_W(-0X49F0, ctx->r1) = 0;
    // bne         $v0, $zero, L_8002C6BC
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x3C
        ctx->r4 = 0 | 0X3C;
        goto L_8002C6BC;
    }
    // ori         $a0, $zero, 0x3C
    ctx->r4 = 0 | 0X3C;
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80034100
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    sub_80034100(rdram, ctx);
    goto after_8;
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    after_8:
L_8002C6BC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A9C($v0)
    ctx->r2 = MEM_BU(-0X4A9C, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002C6F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C6F8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x49F0($v1)
    ctx->r3 = MEM_W(-0X49F0, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49F4($at)
    MEM_W(-0X49F4, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x49F0($at)
    MEM_W(-0X49F0, ctx->r1) = ctx->r3;
L_8002C6F8:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A6F($v1)
    ctx->r3 = MEM_BU(-0X4A6F, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x13
    ctx->r2 = ctx->r3 < 0X13 ? 1 : 0;
    // beq         $v0, $zero, L_8002CE70
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8002CE70;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x13FC
    ctx->r1 = ADD32(ctx->r1, 0X13FC);
    // addu        $at, $at, $v0
    gpr jr_addend_8002C724;
    jr_addend_8002C724 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8002C724 >> 2) {
        case 0: goto L_8002C72C; break;
        case 1: goto L_8002C74C; break;
        case 2: goto L_8002C834; break;
        case 3: goto L_8002CA2C; break;
        case 4: goto L_8002CA4C; break;
        case 5: goto L_8002C990; break;
        case 6: goto L_8002CE70; break;
        case 7: goto L_8002CE70; break;
        case 8: goto L_8002CE70; break;
        case 9: goto L_8002CE70; break;
        case 10: goto L_8002CE70; break;
        case 11: goto L_8002CE70; break;
        case 12: goto L_8002CE70; break;
        case 13: goto L_8002CE70; break;
        case 14: goto L_8002CE70; break;
        case 15: goto L_8002CE70; break;
        case 16: goto L_8002CAE8; break;
        case 17: goto L_8002CB9C; break;
        case 18: goto L_8002CB5C; break;
        default: switch_error(__func__, 0x8002C724, 0x800113FC);
    }
    // nop

L_8002C72C:
    // jal         0x8002B3B8
    // nop

    ProcessPlayerInput(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x8002AC04
    // nop

    sub_8002AC04(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x8002AF20
    // nop

    sub_8002AF20(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // j           L_8002CB4C
    // nop

    goto L_8002CB4C;
    // nop

L_8002C74C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49EC($v0)
    ctx->r2 = MEM_BU(-0X49EC, ctx->r2);
    // nop

    // sll         $s0, $v0, 4
    ctx->r16 = S32(ctx->r2) << 4;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // jal         0x8002B3B8
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    ProcessPlayerInput(rdram, ctx);
    goto after_12;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_12:
    // jal         0x8002AC04
    // nop

    sub_8002AC04(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A64($v1)
    ctx->r3 = MEM_HU(-0X4A64, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A54($at)
    MEM_H(-0X4A54, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A60($v1)
    ctx->r3 = MEM_HU(-0X4A60, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A52($at)
    MEM_H(-0X4A52, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A5C($v1)
    ctx->r3 = MEM_HU(-0X4A5C, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A50($at)
    MEM_H(-0X4A50, ctx->r1) = ctx->r2;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A64
    ctx->r5 = ADD32(ctx->r5, -0X4A64);
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A34
    ctx->r5 = ADD32(ctx->r5, -0X4A34);
    // lwl         $v0, 0x27($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X27, ctx->r16);
    // lwr         $v0, 0x24($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X24, ctx->r16);
    // lwl         $v1, 0x2B($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X2B, ctx->r16);
    // lwr         $v1, 0x28($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X28, ctx->r16);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
L_8002C824:
    // jal         0x8002BAD0
    // nop

    PlayerDoInteract(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // j           L_8002CE70
    // nop

    goto L_8002CE70;
    // nop

L_8002C834:
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s2, $s2, -0x49EC
    ctx->r18 = ADD32(ctx->r18, -0X49EC);
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // sll         $s0, $v0, 4
    ctx->r16 = S32(ctx->r2) << 4;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // jal         0x8002B3B8
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    ProcessPlayerInput(rdram, ctx);
    goto after_15;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_15:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // lbu         $s1, -0x49EB($s1)
    ctx->r17 = MEM_BU(-0X49EB, ctx->r17);
    // lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(0X14, ctx->r16);
    // sll         $s1, $s1, 7
    ctx->r17 = S32(ctx->r17) << 7;
    // jal         0x80015D18
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    FixedPointLerp(rdram, ctx);
    goto after_16;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_16:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r2;
    // lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(0X18, ctx->r16);
    // jal         0x80015D18
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    FixedPointLerp(rdram, ctx);
    goto after_17;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_17:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A5C($a0)
    ctx->r4 = MEM_W(-0X4A5C, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r2;
    // lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(0X1C, ctx->r16);
    // jal         0x80015D18
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    FixedPointLerp(rdram, ctx);
    goto after_18;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_18:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r2;
    // lh          $a1, 0x24($s0)
    ctx->r5 = MEM_H(0X24, ctx->r16);
    // jal         0x80015D30
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015D30(rdram, ctx);
    goto after_19;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_19:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A34($at)
    MEM_H(-0X4A34, ctx->r1) = ctx->r2;
    // lh          $a1, 0x26($s0)
    ctx->r5 = MEM_H(0X26, ctx->r16);
    // jal         0x80015D30
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015D30(rdram, ctx);
    goto after_20;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_20:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = ctx->r2;
    // lh          $a1, 0x28($s0)
    ctx->r5 = MEM_H(0X28, ctx->r16);
    // jal         0x80015D30
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015D30(rdram, ctx);
    goto after_21;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_21:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x49EA($a0)
    ctx->r4 = MEM_H(-0X49EA, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = ctx->r2;
    // jal         0x80015D30
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015D30(rdram, ctx);
    goto after_22;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_22:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x49E8($a0)
    ctx->r4 = MEM_H(-0X49E8, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = ctx->r2;
    // jal         0x80015D30
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015D30(rdram, ctx);
    goto after_23;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_23:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x49E6($a0)
    ctx->r4 = MEM_H(-0X49E6, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A42($at)
    MEM_H(-0X4A42, ctx->r1) = ctx->r2;
    // jal         0x80015D30
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80015D30(rdram, ctx);
    goto after_24;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_24:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49EB($v1)
    ctx->r3 = MEM_BU(-0X49EB, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A40($at)
    MEM_H(-0X4A40, ctx->r1) = ctx->r2;
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sltiu       $v1, $v1, 0x20
    ctx->r3 = ctx->r3 < 0X20 ? 1 : 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x49EB($at)
    MEM_B(-0X49EB, ctx->r1) = ctx->r2;
    // bne         $v1, $zero, L_8002CE70
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002CE70;
    }
    // nop

    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // jal         0x8002BCDC
    // nop

    sub_8002BCDC(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // j           L_8002CE70
    // nop

    goto L_8002CE70;
    // nop

L_8002C990:
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x49EC
    ctx->r17 = ADD32(ctx->r17, -0X49EC);
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(0X0, ctx->r17);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x49E8($a1)
    ctx->r5 = MEM_W(-0X49E8, ctx->r5);
    // sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16) << 8;
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_26;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_26:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x49E4($a1)
    ctx->r5 = MEM_W(-0X49E4, ctx->r5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r2;
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_27;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_27:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A5C($a0)
    ctx->r4 = MEM_W(-0X4A5C, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x49E0($a1)
    ctx->r5 = MEM_W(-0X49E0, ctx->r5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r2;
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_28;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_28:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r2;
    // sltiu       $v1, $v1, 0x10
    ctx->r3 = ctx->r3 < 0X10 ? 1 : 0;
    // bne         $v1, $zero, L_8002CE70
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002CE70;
    }
    // nop

    // jal         0x8002BC74
    // nop

    sub_8002BC74(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // j           L_8002CE70
    // nop

    goto L_8002CE70;
    // nop

L_8002CA2C:
    // jal         0x8002A964
    // nop

    sub_8002A964(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // beq         $v0, $zero, L_8002C824
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C824;
    }
    // nop

    // jal         0x8002BC74
    // nop

    sub_8002BC74(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // j           L_8002C824
    // nop

    goto L_8002C824;
    // nop

L_8002CA4C:
    // jal         0x8002B3B8
    // nop

    ProcessPlayerInput(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // jal         0x8002AC04
    // nop

    sub_8002AC04(rdram, ctx);
    goto after_33;
    // nop

    after_33:
    // jal         0x8002AF20
    // nop

    sub_8002AF20(rdram, ctx);
    goto after_34;
    // nop

    after_34:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A08
    ctx->r16 = ADD32(ctx->r16, -0X4A08);
    // jal         0x8002A3DC
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    sub_8002A3DC(rdram, ctx);
    goto after_35;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    after_35:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x49EC($a0)
    ctx->r4 = MEM_H(-0X49EC, ctx->r4);
    // jal         0x800602D0
    // nop

    FixedCos(rdram, ctx);
    goto after_36;
    // nop

    after_36:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x49EC($a0)
    ctx->r4 = MEM_H(-0X49EC, ctx->r4);
    // addiu       $v1, $v1, -0x100
    ctx->r3 = ADD32(ctx->r3, -0X100);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x800601F4
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    FixedSin(rdram, ctx);
    goto after_37;
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    after_37:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x49EC($v1)
    ctx->r3 = MEM_HU(-0X49EC, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = ctx->r2;
    // addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x49EC($at)
    MEM_H(-0X49EC, ctx->r1) = ctx->r3;
    // bne         $v1, $zero, L_8002C824
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002C824;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = 0;
    // jal         0x8002BC74
    // nop

    sub_8002BC74(rdram, ctx);
    goto after_38;
    // nop

    after_38:
    // j           L_8002C824
    // nop

    goto L_8002C824;
    // nop

L_8002CAE8:
    // jal         0x8002B3B8
    // nop

    ProcessPlayerInput(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // jal         0x8002AC04
    // nop

    sub_8002AC04(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // jal         0x8002AF20
    // nop

    sub_8002AF20(rdram, ctx);
    goto after_41;
    // nop

    after_41:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49EA($at)
    MEM_H(-0X49EA, ctx->r1) = ctx->r2;
    // jal         0x8002A964
    // nop

    sub_8002A964(rdram, ctx);
    goto after_42;
    // nop

    after_42:
    // jal         0x8002B974
    // nop

    sub_8002B974(rdram, ctx);
    goto after_43;
    // nop

    after_43:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A3C($v0)
    ctx->r2 = MEM_W(-0X4A3C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002CB4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CB4C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A38($v0)
    ctx->r2 = MEM_H(-0X4A38, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002CB4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CB4C;
    }
    // nop

    // jal         0x8002BC74
    // nop

    sub_8002BC74(rdram, ctx);
    goto after_44;
    // nop

    after_44:
L_8002CB4C:
    // jal         0x8002A3DC
    // nop

    sub_8002A3DC(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // j           L_8002C824
    // nop

    goto L_8002C824;
    // nop

L_8002CB5C:
    // jal         0x8002B974
    // nop

    sub_8002B974(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A3C($v0)
    ctx->r2 = MEM_W(-0X4A3C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002C824
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002C824;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A38($v0)
    ctx->r2 = MEM_H(-0X4A38, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002C824
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002C824;
    }
    // nop

    // jal         0x8002BC74
    // nop

    sub_8002BC74(rdram, ctx);
    goto after_47;
    // nop

    after_47:
    // j           L_8002C824
    // nop

    goto L_8002C824;
    // nop

L_8002CB9C:
    // addiu       $a0, $zero, -0x400
    ctx->r4 = ADD32(0, -0X400);
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A3C($a1)
    ctx->r5 = MEM_H(-0X4A3C, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x49E4($a2)
    ctx->r6 = MEM_H(-0X49E4, ctx->r6);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B28($at)
    MEM_H(-0X4B28, ctx->r1) = 0;
    // jal         0x80014ED4
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80014ED4(rdram, ctx);
    goto after_48;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_48:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49E4($at)
    MEM_H(-0X49E4, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A3C($v0)
    ctx->r2 = MEM_HU(-0X4A3C, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A08($a0)
    ctx->r4 = MEM_H(-0X4A08, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A3C($at)
    MEM_H(-0X4A3C, ctx->r1) = ctx->r2;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // slti        $a0, $a0, 0x5DC
    ctx->r4 = SIGNED(ctx->r4) < 0X5DC ? 1 : 0;
    // bne         $a0, $zero, L_8002CC14
    if (ctx->r4 != 0) {
        // addiu       $v0, $v0, 0x1F4
        ctx->r2 = ADD32(ctx->r2, 0X1F4);
        goto L_8002CC14;
    }
    // addiu       $v0, $v0, 0x1F4
    ctx->r2 = ADD32(ctx->r2, 0X1F4);
    // ori         $v0, $zero, 0x5DC
    ctx->r2 = 0 | 0X5DC;
L_8002CC14:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A08($at)
    MEM_H(-0X4A08, ctx->r1) = ctx->r2;
    // jal         0x8002A964
    // nop

    sub_8002A964(rdram, ctx);
    goto after_49;
    // nop

    after_49:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x4A36
    ctx->r2 = ADD32(ctx->r2, -0X4A36);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // nop

    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // bne         $v1, $v0, L_8002CD08
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002CD08;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A1C($v0)
    ctx->r2 = MEM_W(-0X4A1C, ctx->r2);
    // nop

    // slti        $v0, $v0, -0x3E8
    ctx->r2 = SIGNED(ctx->r2) < -0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_8002CD08
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CD08;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A18($v0)
    ctx->r2 = MEM_W(-0X4A18, ctx->r2);
    // nop

    // bltz        $v0, L_8002CD08
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8002CD08;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A67($v0)
    ctx->r2 = MEM_BU(-0X4A67, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002CD08
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x36
        ctx->r3 = 0 | 0X36;
        goto L_8002CD08;
    }
    // ori         $v1, $zero, 0x36
    ctx->r3 = 0 | 0X36;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // nop

    // beq         $v0, $v1, L_8002CCB8
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8002CCB8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_8002CD08
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8002CD08;
    }
    // nop

L_8002CCB8:
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // addiu       $v1, $v1, -0x213D
    ctx->r3 = ADD32(ctx->r3, -0X213D);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_8002CD08
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_8002CD08;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // ori         $a3, $zero, 0x200
    ctx->r7 = 0 | 0X200;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // jal         0x80039898
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    FadeScreenIn(rdram, ctx);
    goto after_50;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_50:
    // jal         0x80027994
    // nop

    ResetPlayerBuffers(rdram, ctx);
    goto after_51;
    // nop

    after_51:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80039898
    // addiu       $a3, $zero, -0x200
    ctx->r7 = ADD32(0, -0X200);
    FadeScreenIn(rdram, ctx);
    goto after_52;
    // addiu       $a3, $zero, -0x200
    ctx->r7 = ADD32(0, -0X200);
    after_52:
L_8002CD08:
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4A36($a2)
    ctx->r6 = MEM_H(-0X4A36, ctx->r6);
    // nop

    // slti        $v0, $a2, 0x20
    ctx->r2 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_8002CE70
    if (ctx->r2 != 0) {
        // slti        $v0, $a2, 0x41
        ctx->r2 = SIGNED(ctx->r6) < 0X41 ? 1 : 0;
        goto L_8002CE70;
    }
    // slti        $v0, $a2, 0x41
    ctx->r2 = SIGNED(ctx->r6) < 0X41 ? 1 : 0;
    // beq         $v0, $zero, L_8002CD54
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8002CD54;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // jal         0x80015D18
    // sll         $a2, $a2, 7
    ctx->r6 = S32(ctx->r6) << 7;
    FixedPointLerp(rdram, ctx);
    goto after_53;
    // sll         $a2, $a2, 7
    ctx->r6 = S32(ctx->r6) << 7;
    after_53:
    // ori         $a0, $zero, 0x82
    ctx->r4 = 0 | 0X82;
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80033F94
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    SetFadeColor(rdram, ctx);
    goto after_54;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_54:
    // j           L_8002CE70
    // nop

    goto L_8002CE70;
    // nop

L_8002CD54:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1280
    ctx->r3 = ADD32(ctx->r3, -0X1280);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
L_8002CD64:
    // sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $zero, L_8002CD64
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x48
        ctx->r3 = ADD32(ctx->r3, 0X48);
        goto L_8002CD64;
    }
    // addiu       $v1, $v1, 0x48
    ctx->r3 = ADD32(ctx->r3, 0X48);
    // lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // addiu       $s0, $s0, -0x2144
    ctx->r16 = ADD32(ctx->r16, -0X2144);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8002CE40
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002CE40;
    }
    // nop

    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x519D($v0)
    ctx->r2 = MEM_BU(0X519D, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8002CE40
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002CE40;
    }
    // nop

    // jal         0x8003B9A8
    // nop

    sub_8003B9A8(rdram, ctx);
    goto after_55;
    // nop

    after_55:
    // lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // ori         $a1, $a1, 0xE000
    ctx->r5 = ctx->r5 | 0XE000;
    // lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79D8($a0)
    ctx->r4 = MEM_BU(0X79D8, ctx->r4);
    // ori         $v0, $zero, 0xC00
    ctx->r2 = 0 | 0XC00;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A42($at)
    MEM_H(-0X4A42, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, -0x2480
    ctx->r2 = ADD32(0, -0X2480);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A40($at)
    MEM_H(-0X4A40, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $a1, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // ori         $v1, $zero, 0x5
    ctx->r3 = 0 | 0X5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4A14($at)
    MEM_H(-0X4A14, ctx->r1) = ctx->r3;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // jal         0x8004AEC4
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    sub_8004AEC4(rdram, ctx);
    goto after_56;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    after_56:
    // jal         0x80027994
    // nop

    ResetPlayerBuffers(rdram, ctx);
    goto after_57;
    // nop

    after_57:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // j           L_8002CE68
    // ori         $v0, $zero, 0x43
    ctx->r2 = 0 | 0X43;
    goto L_8002CE68;
    // ori         $v0, $zero, 0x43
    ctx->r2 = 0 | 0X43;
L_8002CE40:
    // jal         0x80027A4C
    // nop

    InitPlayerStats(rdram, ctx);
    goto after_58;
    // nop

    after_58:
    // jal         0x8004AC5C
    // nop

    InitPlayerInventory(rdram, ctx);
    goto after_59;
    // nop

    after_59:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_8002CE68:
    // jal         0x800260BC
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_800260BC(rdram, ctx);
    goto after_60;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_60:
L_8002CE70:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AE8($v1)
    ctx->r3 = MEM_HU(-0X4AE8, ctx->r3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49FA($v0)
    ctx->r2 = MEM_HU(-0X49FA, ctx->r2);
    // sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3) << 16;
    // sra         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5) >> 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49F8($at)
    MEM_H(-0X49F8, ctx->r1) = ctx->r2;
    // beq         $a0, $zero, L_8002CF04
    if (ctx->r4 == 0) {
        // lui         $v0, 0x8888
        ctx->r2 = S32(0X8888 << 16);
        goto L_8002CF04;
    }
    // lui         $v0, 0x8888
    ctx->r2 = S32(0X8888 << 16);
    // ori         $v0, $v0, 0x8889
    ctx->r2 = ctx->r2 | 0X8889;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $a1, 31
    ctx->r2 = S32(ctx->r5) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sra         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) >> 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_8002CEEC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x960
        ctx->r2 = 0 | 0X960;
        goto L_8002CEEC;
    }
    // ori         $v0, $zero, 0x960
    ctx->r2 = 0 | 0X960;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A00($at)
    MEM_H(-0X4A00, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49FE($at)
    MEM_H(-0X49FE, ctx->r1) = ctx->r2;
    // jal         0x80026EE0
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    sub_80026EE0(rdram, ctx);
    goto after_61;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_61:
L_8002CEEC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AE8($v0)
    ctx->r2 = MEM_HU(-0X4AE8, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = ctx->r2;
L_8002CF04:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4ADA
    ctx->r4 = ADD32(ctx->r4, -0X4ADA);
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8002CF38
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002CF38;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_8002CF38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CF38;
    }
    // nop

    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_62;
    // nop

    after_62:
L_8002CF38:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4AD8
    ctx->r4 = ADD32(ctx->r4, -0X4AD8);
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8002CF6C
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002CF6C;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_8002CF6C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CF6C;
    }
    // nop

    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_63;
    // nop

    after_63:
L_8002CF6C:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4AD0
    ctx->r5 = ADD32(ctx->r5, -0X4AD0);
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(0X0, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8002CFB0
    if (ctx->r2 == 0) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8002CFB0;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B26($v1)
    ctx->r3 = MEM_HU(-0X4B26, ctx->r3);
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r3;
    // bne         $v0, $zero, L_8002CFB0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CFB0;
    }
    // nop

    // jal         0x80035CC4
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    MessageQueuePush(rdram, ctx);
    goto after_64;
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    after_64:
L_8002CFB0:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4ACE
    ctx->r4 = ADD32(ctx->r4, -0X4ACE);
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8002CFEC
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002CFEC;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_8002CFEC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002CFEC;
    }
    // nop

    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_65;
    // nop

    after_65:
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    MessageQueuePush(rdram, ctx);
    goto after_66;
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    after_66:
L_8002CFEC:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4AD2
    ctx->r16 = ADD32(ctx->r16, -0X4AD2);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(0X0, ctx->r16);
    // nop

    // beq         $v1, $zero, L_8002D0BC
    if (ctx->r3 == 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8002D0BC;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // bne         $v1, $s1, L_8002D054
    if (ctx->r3 != ctx->r17) {
        // andi        $v0, $v0, 0x7
        ctx->r2 = ctx->r2 & 0X7;
        goto L_8002D054;
    }
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x634C
    ctx->r4 = ADD32(ctx->r4, 0X634C);
    // ori         $a1, $zero, 0x240
    ctx->r5 = 0 | 0X240;
    // jal         0x800633C0
    // ori         $a2, $zero, 0x103
    ctx->r6 = 0 | 0X103;
    MoveImageWithCallback(rdram, ctx);
    goto after_67;
    // ori         $a2, $zero, 0x103
    ctx->r6 = 0 | 0X103;
    after_67:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x635C
    ctx->r4 = ADD32(ctx->r4, 0X635C);
    // ori         $a1, $zero, 0x240
    ctx->r5 = 0 | 0X240;
    // jal         0x800633C0
    // ori         $a2, $zero, 0x106
    ctx->r6 = 0 | 0X106;
    MoveImageWithCallback(rdram, ctx);
    goto after_68;
    // ori         $a2, $zero, 0x106
    ctx->r6 = 0 | 0X106;
    after_68:
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    MessageQueuePush(rdram, ctx);
    goto after_69;
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    after_69:
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // jal         0x80038214
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80038214(rdram, ctx);
    goto after_70;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_70:
    // j           L_8002D0BC
    // nop

    goto L_8002D0BC;
    // nop

L_8002D054:
    // bne         $v0, $zero, L_8002D06C
    if (ctx->r2 != 0) {
        // ori         $a1, $zero, 0x240
        ctx->r5 = 0 | 0X240;
        goto L_8002D06C;
    }
    // ori         $a1, $zero, 0x240
    ctx->r5 = 0 | 0X240;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6354
    ctx->r4 = ADD32(ctx->r4, 0X6354);
    // jal         0x800633C0
    // ori         $a2, $zero, 0x103
    ctx->r6 = 0 | 0X103;
    MoveImageWithCallback(rdram, ctx);
    goto after_71;
    // ori         $a2, $zero, 0x103
    ctx->r6 = 0 | 0X103;
    after_71:
L_8002D06C:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // ori         $v1, $zero, 0x4
    ctx->r3 = 0 | 0X4;
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $v1, L_8002D090
    if (ctx->r2 != ctx->r3) {
        // ori         $a1, $zero, 0x240
        ctx->r5 = 0 | 0X240;
        goto L_8002D090;
    }
    // ori         $a1, $zero, 0x240
    ctx->r5 = 0 | 0X240;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6364
    ctx->r4 = ADD32(ctx->r4, 0X6364);
    // jal         0x800633C0
    // ori         $a2, $zero, 0x106
    ctx->r6 = 0 | 0X106;
    MoveImageWithCallback(rdram, ctx);
    goto after_72;
    // ori         $a2, $zero, 0x106
    ctx->r6 = 0 | 0X106;
    after_72:
L_8002D090:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $s1, L_8002D0AC
    if (ctx->r2 != ctx->r17) {
        // nop
    
        goto L_8002D0AC;
    }
    // nop

    // jal         0x80038214
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_80038214(rdram, ctx);
    goto after_73;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_73:
L_8002D0AC:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8002D0BC:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4AE6
    ctx->r16 = ADD32(ctx->r16, -0X4AE6);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // jal         0x8002C124
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    sub_8002C124(rdram, ctx);
    goto after_74;
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    after_74:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_8002D11C
    if (ctx->r17 == ctx->r2) {
        // ori         $a2, $zero, 0x320
        ctx->r6 = 0 | 0X320;
        goto L_8002D11C;
    }
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8002D108
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x46
        ctx->r4 = 0 | 0X46;
        goto L_8002D108;
    }
    // ori         $a0, $zero, 0x46
    ctx->r4 = 0 | 0X46;
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_75;
    // nop

    after_75:
    // ori         $a0, $zero, 0x46
    ctx->r4 = 0 | 0X46;
L_8002D108:
    // ori         $a1, $zero, 0x46
    ctx->r5 = 0 | 0X46;
    // ori         $a2, $zero, 0x1E
    ctx->r6 = 0 | 0X1E;
    // jal         0x80034100
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_80034100(rdram, ctx);
    goto after_76;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_76:
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
L_8002D11C:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A44($v0)
    ctx->r2 = MEM_HU(-0X4A44, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A3C($v1)
    ctx->r3 = MEM_HU(-0X4A3C, ctx->r3);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lhu         $t0, -0x4A2C($t0)
    ctx->r8 = MEM_HU(-0X4A2C, ctx->r8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A34($v1)
    ctx->r3 = MEM_HU(-0X4A34, ctx->r3);
    // lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // lhu         $t1, -0x4A38($t1)
    ctx->r9 = MEM_HU(-0X4A38, ctx->r9);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A4C($at)
    MEM_H(-0X4A4C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A42($v0)
    ctx->r2 = MEM_HU(-0X4A42, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A3A($v1)
    ctx->r3 = MEM_HU(-0X4A3A, ctx->r3);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lhu         $t0, -0x4A32($t0)
    ctx->r8 = MEM_HU(-0X4A32, ctx->r8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lhu         $t0, -0x4A2A($t0)
    ctx->r8 = MEM_HU(-0X4A2A, ctx->r8);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A40($v1)
    ctx->r3 = MEM_HU(-0X4A40, ctx->r3);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A4A($at)
    MEM_H(-0X4A4A, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A30($v0)
    ctx->r2 = MEM_HU(-0X4A30, ctx->r2);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lhu         $t0, -0x4A28($t0)
    ctx->r8 = MEM_HU(-0X4A28, ctx->r8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4A48($at)
    MEM_H(-0X4A48, ctx->r1) = ctx->r3;
    // jal         0x8002E25C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_77;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_77:
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A60($a1)
    ctx->r5 = MEM_W(-0X4A60, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A5C($a2)
    ctx->r6 = MEM_W(-0X4A5C, ctx->r6);
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79A8($at)
    MEM_B(0X79A8, ctx->r1) = 0;
    // jal         0x8003D480
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    Entity_CheckWorldCollision(rdram, ctx);
    goto after_78;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_78:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8002D240
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_8002D240;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // addiu       $at, $at, -0x19D0
    ctx->r1 = ADD32(ctx->r1, -0X19D0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8002D240
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D240;
    }
    // nop

    // jal         0x8002C0F8
    // nop

    sub_8002C0F8(rdram, ctx);
    goto after_79;
    // nop

    after_79:
L_8002D240:
    // jal         0x80029088
    // nop

    ProcessMeleeAttack(rdram, ctx);
    goto after_80;
    // nop

    after_80:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA1($v1)
    ctx->r3 = MEM_BU(-0X4AA1, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8002D2FC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002D2FC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4ABC($v0)
    ctx->r2 = MEM_W(-0X4ABC, ctx->r2);
    // nop

    // lhu         $v1, 0x16($v0)
    ctx->r3 = MEM_HU(0X16, ctx->r2);
    // nop

    // beq         $v1, $zero, L_8002D2B4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002D2B4;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4AC8($v0)
    ctx->r2 = MEM_W(-0X4AC8, ctx->r2);
    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_8002D294
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002D294;
    }
    // nop

    // break       7
    do_break(2147668624);
L_8002D294:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_8002D2AC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002D2AC;
    }
    // nop

    // jal         0x8002C1E0
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_8002C1E0(rdram, ctx);
    goto after_81;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_81:
L_8002D2AC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4ABC($v0)
    ctx->r2 = MEM_W(-0X4ABC, ctx->r2);
L_8002D2B4:
    // nop

    // lhu         $v1, 0x18($v0)
    ctx->r3 = MEM_HU(0X18, ctx->r2);
    // nop

    // beq         $v1, $zero, L_8002D2FC
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002D2FC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4AC8($v0)
    ctx->r2 = MEM_W(-0X4AC8, ctx->r2);
    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_8002D2E4
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002D2E4;
    }
    // nop

    // break       7
    do_break(2147668704);
L_8002D2E4:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_8002D2FC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002D2FC;
    }
    // nop

    // jal         0x8002C24C
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_8002C24C(rdram, ctx);
    goto after_82;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_82:
L_8002D2FC:
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4A7C
    ctx->r17 = ADD32(ctx->r17, -0X4A7C);
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // ori         $s0, $zero, 0xFF
    ctx->r16 = 0 | 0XFF;
    // beq         $v0, $s0, L_8002D324
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D324;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A98($a0)
    ctx->r4 = MEM_W(-0X4A98, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_83;
    // nop

    after_83:
L_8002D324:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A7B($v0)
    ctx->r2 = MEM_BU(-0X4A7B, ctx->r2);
    // nop

    // beq         $v0, $s0, L_8002D348
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D348;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A94($a0)
    ctx->r4 = MEM_W(-0X4A94, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_84;
    // nop

    after_84:
L_8002D348:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A7A($v0)
    ctx->r2 = MEM_BU(-0X4A7A, ctx->r2);
    // nop

    // beq         $v0, $s0, L_8002D36C
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D36C;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A90($a0)
    ctx->r4 = MEM_W(-0X4A90, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_85;
    // nop

    after_85:
L_8002D36C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A79($v0)
    ctx->r2 = MEM_BU(-0X4A79, ctx->r2);
    // nop

    // beq         $v0, $s0, L_8002D390
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D390;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A8C($a0)
    ctx->r4 = MEM_W(-0X4A8C, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_86;
    // nop

    after_86:
L_8002D390:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A78($v0)
    ctx->r2 = MEM_BU(-0X4A78, ctx->r2);
    // nop

    // beq         $v0, $s0, L_8002D3B4
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D3B4;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A88($a0)
    ctx->r4 = MEM_W(-0X4A88, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_87;
    // nop

    after_87:
L_8002D3B4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // nop

    // beq         $v0, $s0, L_8002D3D8
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D3D8;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A84($a0)
    ctx->r4 = MEM_W(-0X4A84, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_88;
    // nop

    after_88:
L_8002D3D8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // beq         $v0, $s0, L_8002D3FC
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8002D3FC;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A80($a0)
    ctx->r4 = MEM_W(-0X4A80, ctx->r4);
    // jal         0x8002C29C
    // nop

    sub_8002C29C(rdram, ctx);
    goto after_89;
    // nop

    after_89:
L_8002D3FC:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0x19
    ctx->r2 = 0 | 0X19;
    // bne         $v1, $v0, L_8002D444
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002D444;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_90;
    // nop

    after_90:
    // slti        $v0, $v0, 0x24
    ctx->r2 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // beq         $v0, $zero, L_8002D444
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x12C
        ctx->r2 = ADD32(0, -0X12C);
        goto L_8002D444;
    }
    // addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A22($at)
    MEM_H(-0X4A22, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x190
    ctx->r2 = 0 | 0X190;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = ctx->r2;
    // jal         0x80028498
    // ori         $a0, $zero, 0xB
    ctx->r4 = 0 | 0XB;
    SpawnMagicProjectile(rdram, ctx);
    goto after_91;
    // ori         $a0, $zero, 0xB
    ctx->r4 = 0 | 0XB;
    after_91:
L_8002D444:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A7B($v1)
    ctx->r3 = MEM_BU(-0X4A7B, ctx->r3);
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // bne         $v1, $v0, L_8002D470
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x800
        ctx->r2 = 0 | 0X800;
        goto L_8002D470;
    }
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    // ori         $a1, $zero, 0x14
    ctx->r5 = 0 | 0X14;
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    // jal         0x8002EA88
    // ori         $a3, $zero, 0x1388
    ctx->r7 = 0 | 0X1388;
    TriggerLightFlash(rdram, ctx);
    goto after_92;
    // ori         $a3, $zero, 0x1388
    ctx->r7 = 0 | 0X1388;
    after_92:
L_8002D470:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4AC8($v0)
    ctx->r2 = MEM_W(-0X4AC8, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4AC8($at)
    MEM_W(-0X4AC8, ctx->r1) = ctx->r2;
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
