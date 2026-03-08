#include "recomp.h"
#include "disable_warnings.h"

void ApplyStatusEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(0X8C, ctx->r29);
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // lhu         $s6, 0x70($sp)
    ctx->r22 = MEM_HU(0X70, ctx->r29);
    // sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // lhu         $s7, 0x74($sp)
    ctx->r23 = MEM_HU(0X74, ctx->r29);
    // sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // lhu         $fp, 0x78($sp)
    ctx->r30 = MEM_HU(0X78, ctx->r29);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A9C($v0)
    ctx->r2 = MEM_BU(-0X4A9C, ctx->r2);
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x7C($sp)
    ctx->r8 = MEM_HU(0X7C, ctx->r29);
    // addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sh          $t0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x80($sp)
    ctx->r8 = MEM_HU(0X80, ctx->r29);
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // sh          $t0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x84($sp)
    ctx->r8 = MEM_HU(0X84, ctx->r29);
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // sh          $t0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x88($sp)
    ctx->r8 = MEM_HU(0X88, ctx->r29);
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // bne         $v0, $zero, L_800276CC
    if (ctx->r2 != 0) {
        // sh          $t0, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r8;
        goto L_800276CC;
    }
    // sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x36
    ctx->r3 = 0 | 0X36;
    // beq         $v0, $v1, L_800273EC
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800273EC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_80027404
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80027404;
    }
    // nop

L_800273EC:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // slti        $v0, $v0, 0x4000
    ctx->r2 = SIGNED(ctx->r2) < 0X4000 ? 1 : 0;
    // beq         $v0, $zero, L_80027404
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80027404;
    }
    // nop

    // andi        $s2, $s0, 0xFFF8
    ctx->r18 = ctx->r16 & 0XFFF8;
L_80027404:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x3A
    ctx->r3 = 0 | 0X3A;
    // beq         $v0, $v1, L_8002742C
    if (ctx->r2 == ctx->r3) {
        // ori         $a3, $zero, 0x12C
        ctx->r7 = 0 | 0X12C;
        goto L_8002742C;
    }
    // ori         $a3, $zero, 0x12C
    ctx->r7 = 0 | 0X12C;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_80027440
    if (ctx->r2 != ctx->r3) {
        // ori         $a2, $zero, 0x1F4
        ctx->r6 = 0 | 0X1F4;
        goto L_80027440;
    }
    // ori         $a2, $zero, 0x1F4
    ctx->r6 = 0 | 0X1F4;
L_8002742C:
    // ori         $a2, $zero, 0xFA
    ctx->r6 = 0 | 0XFA;
    // ori         $s1, $zero, 0x12C
    ctx->r17 = 0 | 0X12C;
    // ori         $a1, $zero, 0x64
    ctx->r5 = 0 | 0X64;
    // j           L_80027450
    // ori         $a0, $zero, 0x12C
    ctx->r4 = 0 | 0X12C;
    goto L_80027450;
    // ori         $a0, $zero, 0x12C
    ctx->r4 = 0 | 0X12C;
L_80027440:
    // ori         $a3, $zero, 0x258
    ctx->r7 = 0 | 0X258;
    // ori         $s1, $zero, 0x258
    ctx->r17 = 0 | 0X258;
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
L_80027450:
    // andi        $v0, $s2, 0xF
    ctx->r2 = ctx->r18 & 0XF;
    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_800275B0
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_800275B0;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1244
    ctx->r1 = ADD32(ctx->r1, 0X1244);
    // addu        $at, $at, $v0
    gpr jr_addend_80027478;
    jr_addend_80027478 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80027478 >> 2) {
        case 0: goto L_80027480; break;
        case 1: goto L_800274A4; break;
        case 2: goto L_800274B4; break;
        case 3: goto L_80027534; break;
        case 4: goto L_80027544; break;
        case 5: goto L_80027564; break;
        case 6: goto L_80027554; break;
        default: switch_error(__func__, 0x80027478, 0x80011244);
    }
    // nop

L_80027480:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a3, -0x4AE4($at)
    MEM_H(-0X4AE4, ctx->r1) = ctx->r7;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AE6($at)
    MEM_H(-0X4AE6, ctx->r1) = ctx->r2;
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_800274A4:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a2, -0x4AE0($at)
    MEM_H(-0X4AE0, ctx->r1) = ctx->r6;
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_800274B4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x35
    ctx->r3 = 0 | 0X35;
    // beq         $v0, $v1, L_800274DC
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800274DC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_800274F0
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800274F0;
    }
    // nop

L_800274DC:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // slti        $v0, $v0, 0x4000
    ctx->r2 = SIGNED(ctx->r2) < 0X4000 ? 1 : 0;
    // bne         $v0, $zero, L_800275B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800275B0;
    }
    // nop

L_800274F0:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // lhu         $s0, -0x4AF4($s0)
    ctx->r16 = MEM_HU(-0X4AF4, ctx->r16);
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sra         $v1, $v1, 15
    ctx->r3 = S32(ctx->r3) >> 15;
    // slt         $s0, $s0, $v1
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $s0, $zero, L_800275B0
    if (ctx->r16 == 0) {
        // nop
    
        goto L_800275B0;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s1, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = ctx->r17;
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_80027534:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a1, -0x4ADC($at)
    MEM_H(-0X4ADC, ctx->r1) = ctx->r5;
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_80027544:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4ADE($at)
    MEM_H(-0X4ADE, ctx->r1) = ctx->r4;
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_80027554:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = 0;
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_80027564:
    // lui         $v1, 0xAAAA
    ctx->r3 = S32(0XAAAA << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B26($v0)
    ctx->r2 = MEM_HU(-0X4B26, ctx->r2);
    // ori         $v1, $v1, 0xAAAB
    ctx->r3 = ctx->r3 | 0XAAAB;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B24($a0)
    ctx->r4 = MEM_HU(-0X4B24, ctx->r4);
    // mfhi        $v0
    ctx->r2 = hi;
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_800275A8
    if (ctx->r2 == 0) {
        // subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
        goto L_800275A8;
    }
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r2;
    // j           L_800275B0
    // nop

    goto L_800275B0;
    // nop

L_800275A8:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = 0;
L_800275B0:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4B14
    ctx->r16 = ADD32(ctx->r16, -0X4B14);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AFA($a1)
    ctx->r5 = MEM_HU(-0X4AFA, ctx->r5);
    // jal         0x80026E38
    // andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    sub_80026E38(rdram, ctx);
    goto after_4;
    // andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    after_4:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AF8($a1)
    ctx->r5 = MEM_HU(-0X4AF8, ctx->r5);
    // jal         0x80026E38
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    sub_80026E38(rdram, ctx);
    goto after_5;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    after_5:
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AF6($a1)
    ctx->r5 = MEM_HU(-0X4AF6, ctx->r5);
    // jal         0x80026E38
    // andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    sub_80026E38(rdram, ctx);
    goto after_6;
    // andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    after_6:
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AF2($a1)
    ctx->r5 = MEM_HU(-0X4AF2, ctx->r5);
    // jal         0x80026E38
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    sub_80026E38(rdram, ctx);
    goto after_7;
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_7:
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AF0($a1)
    ctx->r5 = MEM_HU(-0X4AF0, ctx->r5);
    // jal         0x80026E38
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    sub_80026E38(rdram, ctx);
    goto after_8;
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    after_8:
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AEE($a1)
    ctx->r5 = MEM_HU(-0X4AEE, ctx->r5);
    // jal         0x80026E38
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    sub_80026E38(rdram, ctx);
    goto after_9;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_9:
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lhu         $t0, 0x10($sp)
    ctx->r8 = MEM_HU(0X10, ctx->r29);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AEC($a1)
    ctx->r5 = MEM_HU(-0X4AEC, ctx->r5);
    // jal         0x80026E38
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    sub_80026E38(rdram, ctx);
    goto after_10;
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_10:
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lhu         $t0, 0x18($sp)
    ctx->r8 = MEM_HU(0X18, ctx->r29);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4AEA($a1)
    ctx->r5 = MEM_HU(-0X4AEA, ctx->r5);
    // jal         0x80026E38
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    sub_80026E38(rdram, ctx);
    goto after_11;
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_11:
    // lhu         $t0, 0x20($sp)
    ctx->r8 = MEM_HU(0X20, ctx->r29);
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // mult        $t0, $s1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // mult        $t0, $s1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $a1
    ctx->r5 = hi;
    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
    // jal         0x80026F34
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    sub_80026F34(rdram, ctx);
    goto after_12;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    after_12:
L_800276CC:
    // lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(0X5C, ctx->r29);
    // lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(0X58, ctx->r29);
    // lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // jr          $ra
    // nop

    return;
    // nop

;}
