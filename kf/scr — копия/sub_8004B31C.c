#include "recomp.h"
#include "disable_warnings.h"

void sub_8004B31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // jal         0x8004AD48
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    sub_8004AD48(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    after_0:
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $v0, $sp, $s0
    ctx->r2 = ADD32(ctx->r29, ctx->r16);
    // lw          $s0, 0x10($v0)
    ctx->r16 = MEM_W(0X10, ctx->r2);
    // nop

    // beq         $s0, $zero, L_8004B668
    if (ctx->r16 == 0) {
        // ori         $a2, $zero, 0xFF
        ctx->r6 = 0 | 0XFF;
        goto L_8004B668;
    }
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // addiu       $a1, $a1, -0x19F8
    ctx->r5 = ADD32(ctx->r5, -0X19F8);
L_8004B36C:
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $a0, $a2, L_8004B39C
    if (ctx->r4 == ctx->r6) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004B39C;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4) << 5;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // j           L_8004B36C
    // sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    goto L_8004B36C;
    // sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
L_8004B39C:
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x46E8
    ctx->r4 = ADD32(ctx->r4, 0X46E8);
L_8004B3A8:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v1, $a1, L_8004B3E8
    if (ctx->r3 == ctx->r5) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004B3E8;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(0X38, ctx->r2);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8004B3A8
    // sb          $v0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r2;
    goto L_8004B3A8;
    // sb          $v0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r2;
L_8004B3E8:
    // lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // addiu       $s5, $s5, -0x6810
    ctx->r21 = ADD32(ctx->r21, -0X6810);
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // addiu       $s1, $s5, 0x38
    ctx->r17 = ADD32(ctx->r21, 0X38);
L_8004B3F8:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // addiu       $v1, $v0, -0xF0
    ctx->r3 = ADD32(ctx->r2, -0XF0);
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8004B654
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004B654;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x2CF4
    ctx->r1 = ADD32(ctx->r1, 0X2CF4);
    // addu        $at, $at, $v0
    gpr jr_addend_8004B428;
    jr_addend_8004B428 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8004B428 >> 2) {
        case 0: goto L_8004B458; break;
        case 1: goto L_8004B52C; break;
        case 2: goto L_8004B594; break;
        case 3: goto L_8004B62C; break;
        case 4: goto L_8004B43C; break;
        case 5: goto L_8004B654; break;
        case 6: goto L_8004B654; break;
        case 7: goto L_8004B654; break;
        case 8: goto L_8004B654; break;
        case 9: goto L_8004B654; break;
        case 10: goto L_8004B654; break;
        case 11: goto L_8004B654; break;
        case 12: goto L_8004B654; break;
        case 13: goto L_8004B648; break;
        case 14: goto L_8004B654; break;
        case 15: goto L_8004B430; break;
        default: switch_error(__func__, 0x8004B428, 0x80012CF4);
    }
    // nop

L_8004B430:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_8004B654
    // sh          $v0, -0x32($s1)
    MEM_H(-0X32, ctx->r17) = ctx->r2;
    goto L_8004B654;
    // sh          $v0, -0x32($s1)
    MEM_H(-0X32, ctx->r17) = ctx->r2;
L_8004B43C:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8004B654
    // sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    goto L_8004B654;
    // sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_8004B458:
    // jal         0x80038004
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    sub_80038004(rdram, ctx);
    goto after_1;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_1:
    // ori         $v0, $zero, 0x60
    ctx->r2 = 0 | 0X60;
    // sb          $v0, -0x34($s1)
    MEM_B(-0X34, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sh          $v0, -0x32($s1)
    MEM_H(-0X32, ctx->r17) = ctx->r2;
    // lbu         $s4, 0x0($s0)
    ctx->r20 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $s3, 0x0($s0)
    ctx->r19 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $s2, 0x0($s0)
    ctx->r18 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sh          $v0, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r2;
    // sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6) << 8;
    // or          $s4, $s4, $a2
    ctx->r20 = ctx->r20 | ctx->r6;
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // or          $s3, $s3, $a1
    ctx->r19 = ctx->r19 | ctx->r5;
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $s2, $s2, $v1
    ctx->r18 = ctx->r18 | ctx->r3;
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // sh          $a0, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = ctx->r4;
L_8004B4D4:
    // sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20) << 2;
    // sw          $v0, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r2;
    // sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19) << 2;
    // sw          $v0, -0x1C($s1)
    MEM_W(-0X1C, ctx->r17) = ctx->r2;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // lw          $a0, -0x24($s1)
    ctx->r4 = MEM_W(-0X24, ctx->r17);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $v0, -0x20($s1)
    MEM_W(-0X20, ctx->r17) = ctx->r2;
    // lw          $a1, -0x20($s1)
    ctx->r5 = MEM_W(-0X20, ctx->r17);
    // lw          $a2, -0x1C($s1)
    ctx->r6 = MEM_W(-0X1C, ctx->r17);
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // jal         0x8002D4A4
    // sh          $v0, -0x30($s1)
    MEM_H(-0X30, ctx->r17) = ctx->r2;
    ResolveCurrentMetaTile(rdram, ctx);
    goto after_2;
    // sh          $v0, -0x30($s1)
    MEM_H(-0X30, ctx->r17) = ctx->r2;
    after_2:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x2A82($v0)
    ctx->r2 = MEM_HU(-0X2A82, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8004B520
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x2
        ctx->r3 = 0 | 0X2;
        goto L_8004B520;
    }
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
L_8004B520:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_8004B650
    // sb          $v1, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r3;
    goto L_8004B650;
    // sb          $v1, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r3;
L_8004B52C:
    // jal         0x80038004
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    sub_80038004(rdram, ctx);
    goto after_3;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_3:
    // ori         $v0, $zero, 0x61
    ctx->r2 = 0 | 0X61;
    // sb          $v0, -0x34($s1)
    MEM_B(-0X34, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sh          $v0, -0x32($s1)
    MEM_H(-0X32, ctx->r17) = ctx->r2;
    // lbu         $s4, 0x0($s0)
    ctx->r20 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $s3, 0x0($s0)
    ctx->r19 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $s2, 0x0($s0)
    ctx->r18 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // or          $s4, $s4, $a0
    ctx->r20 = ctx->r20 | ctx->r4;
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $s3, $s3, $v1
    ctx->r19 = ctx->r19 | ctx->r3;
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // j           L_8004B4D4
    // or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    goto L_8004B4D4;
    // or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_8004B594:
    // jal         0x80038004
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    sub_80038004(rdram, ctx);
    goto after_4;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_4:
    // ori         $v0, $zero, 0x62
    ctx->r2 = 0 | 0X62;
    // sb          $v0, -0x34($s1)
    MEM_B(-0X34, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sh          $v0, -0x32($s1)
    MEM_H(-0X32, ctx->r17) = ctx->r2;
    // lbu         $s4, 0x0($s0)
    ctx->r20 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $s3, 0x0($s0)
    ctx->r19 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $s2, 0x0($s0)
    ctx->r18 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // or          $s4, $s4, $a0
    ctx->r20 = ctx->r20 | ctx->r4;
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $s3, $s3, $v1
    ctx->r19 = ctx->r19 | ctx->r3;
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // jal         0x80062BF0
    // or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_5;
    // or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    after_5:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // sra         $v0, $v0, 13
    ctx->r2 = S32(ctx->r2) >> 13;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r3;
    // lhu         $v1, -0x32($s1)
    ctx->r3 = MEM_HU(-0X32, ctx->r17);
    // ori         $v0, $zero, 0x67
    ctx->r2 = 0 | 0X67;
    // bne         $v1, $v0, L_8004B4D4
    if (ctx->r3 != ctx->r2) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004B4D4;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // j           L_8004B4D4
    // sh          $v0, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r2;
    goto L_8004B4D4;
    // sh          $v0, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r2;
L_8004B62C:
    // jal         0x80038004
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    sub_80038004(rdram, ctx);
    goto after_6;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_6:
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // sb          $v0, -0x34($s1)
    MEM_B(-0X34, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sh          $v0, -0x32($s1)
    MEM_H(-0X32, ctx->r17) = ctx->r2;
L_8004B648:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004B650:
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_8004B654:
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // slti        $v0, $s6, 0x18C
    ctx->r2 = SIGNED(ctx->r22) < 0X18C ? 1 : 0;
    // bne         $v0, $zero, L_8004B3F8
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x44
        ctx->r21 = ADD32(ctx->r21, 0X44);
        goto L_8004B3F8;
    }
    // addiu       $s5, $s5, 0x44
    ctx->r21 = ADD32(ctx->r21, 0X44);
L_8004B668:
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
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
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
