#include "recomp.h"
#include "disable_warnings.h"

void TryCastMagic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A6B($v1)
    ctx->r3 = MEM_BU(-0X4A6B, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80029EFC
    if (ctx->r3 != ctx->r2) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_80029EFC;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // beq         $a1, $v1, L_80029EFC
    if (ctx->r5 == ctx->r3) {
        // sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5) << 1;
        goto L_80029EFC;
    }
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1900
    ctx->r3 = ADD32(ctx->r3, -0X1900);
    // addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B24($v0)
    ctx->r2 = MEM_HU(-0X4B24, ctx->r2);
    // lhu         $v1, 0x16($a2)
    ctx->r3 = MEM_HU(0X16, ctx->r6);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80029EFC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xC
        ctx->r2 = 0 | 0XC;
        goto L_80029EFC;
    }
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA1($v1)
    ctx->r3 = MEM_BU(-0X4AA1, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80029CC8
    if (ctx->r3 != ctx->r2) {
        // slti        $v0, $a1, 0xB
        ctx->r2 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
        goto L_80029CC8;
    }
    // slti        $v0, $a1, 0xB
    ctx->r2 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
    // beq         $v0, $zero, L_80029CC8
    if (ctx->r2 == 0) {
        // slti        $v0, $a1, 0x7
        ctx->r2 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
        goto L_80029CC8;
    }
    // slti        $v0, $a1, 0x7
    ctx->r2 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80029EFC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80029EFC;
    }
    // nop

L_80029CC8:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A7B($v1)
    ctx->r3 = MEM_BU(-0X4A7B, ctx->r3);
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // bne         $v1, $v0, L_80029CFC
    if (ctx->r3 != ctx->r2) {
        // slti        $v0, $a1, 0xB
        ctx->r2 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
        goto L_80029CFC;
    }
    // slti        $v0, $a1, 0xB
    ctx->r2 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
    // bne         $v0, $zero, L_80029CFC
    if (ctx->r2 != 0) {
        // slti        $v0, $a1, 0xD
        ctx->r2 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
        goto L_80029CFC;
    }
    // slti        $v0, $a1, 0xD
    ctx->r2 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
    // bne         $v0, $zero, L_80029EFC
    if (ctx->r2 != 0) {
        // slti        $v0, $a1, 0x14
        ctx->r2 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
        goto L_80029EFC;
    }
    // slti        $v0, $a1, 0x14
    ctx->r2 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // beq         $v0, $zero, L_80029CFC
    if (ctx->r2 == 0) {
        // slti        $v0, $a1, 0x12
        ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
        goto L_80029CFC;
    }
    // slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // beq         $v0, $zero, L_80029EFC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80029EFC;
    }
    // nop

L_80029CFC:
    // addiu       $v1, $a1, -0xE
    ctx->r3 = ADD32(ctx->r5, -0XE);
    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80029DA4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80029DA4;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1394
    ctx->r1 = ADD32(ctx->r1, 0X1394);
    // addu        $at, $at, $v0
    gpr jr_addend_80029D20;
    jr_addend_80029D20 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80029D20 >> 2) {
        case 0: goto L_80029D90; break;
        case 1: goto L_80029D28; break;
        case 2: goto L_80029D90; break;
        case 3: goto L_80029D44; break;
        case 4: goto L_80029D60; break;
        case 5: goto L_80029D90; break;
        default: switch_error(__func__, 0x80029D20, 0x80011394);
    }
    // nop

L_80029D28:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADA($v0)
    ctx->r2 = MEM_H(-0X4ADA, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80029EFC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80029EFC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80029D94
    // nop

    goto L_80029D94;
    // nop

L_80029D44:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AD8($v0)
    ctx->r2 = MEM_H(-0X4AD8, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80029EFC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80029EFC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80029D94
    // nop

    goto L_80029D94;
    // nop

L_80029D60:
    // ori         $v0, $zero, 0x384
    ctx->r2 = 0 | 0X384;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD4($at)
    MEM_H(-0X4AD4, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B24($v0)
    ctx->r2 = MEM_HU(-0X4B24, ctx->r2);
    // lhu         $v1, 0x16($a2)
    ctx->r3 = MEM_HU(0X16, ctx->r6);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r2;
    // j           L_80029EFC
    // nop

    goto L_80029EFC;
    // nop

L_80029D90:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80029D94:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A69($at)
    MEM_B(-0X4A69, ctx->r1) = ctx->r2;
L_80029DA4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B1E
    ctx->r3 = ADD32(ctx->r3, -0X4B1E);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1388
    ctx->r2 = ctx->r2 < 0X1388 ? 1 : 0;
    // bne         $v0, $zero, L_80029EFC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0xC8
        ctx->r2 = ADD32(0, -0XC8);
        goto L_80029EFC;
    }
    // addiu       $v0, $zero, -0xC8
    ctx->r2 = ADD32(0, -0XC8);
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // lhu         $a0, 0x16($a2)
    ctx->r4 = MEM_HU(0X16, ctx->r6);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xC8
    ctx->r2 = 0 | 0XC8;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A22($at)
    MEM_H(-0X4A22, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x190
    ctx->r2 = 0 | 0X190;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B24($v0)
    ctx->r2 = MEM_HU(-0X4B24, ctx->r2);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a1, -0x4A6B($at)
    MEM_B(-0X4A6B, ctx->r1) = ctx->r5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x4A68($at)
    MEM_B(-0X4A68, ctx->r1) = ctx->r3;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r2;
    // sltiu       $v0, $a1, 0x13
    ctx->r2 = ctx->r5 < 0X13 ? 1 : 0;
    // beq         $v0, $zero, L_80029EF4
    if (ctx->r2 == 0) {
        // sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5) << 2;
        goto L_80029EF4;
    }
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x13AC
    ctx->r1 = ADD32(ctx->r1, 0X13AC);
    // addu        $at, $at, $v0
    gpr jr_addend_80029E30;
    jr_addend_80029E30 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80029E30 >> 2) {
        case 0: goto L_80029E94; break;
        case 1: goto L_80029E58; break;
        case 2: goto L_80029E94; break;
        case 3: goto L_80029EDC; break;
        case 4: goto L_80029E58; break;
        case 5: goto L_80029E58; break;
        case 6: goto L_80029E58; break;
        case 7: goto L_80029E58; break;
        case 8: goto L_80029E58; break;
        case 9: goto L_80029E80; break;
        case 10: goto L_80029E38; break;
        case 11: goto L_80029E58; break;
        case 12: goto L_80029E6C; break;
        case 13: goto L_80029EC8; break;
        case 14: goto L_80029EF4; break;
        case 15: goto L_80029EF4; break;
        case 16: goto L_80029EF4; break;
        case 17: goto L_80029EF4; break;
        case 18: goto L_80029E58; break;
        default: switch_error(__func__, 0x80029E30, 0x800113AC);
    }
    // nop

L_80029E38:
    // addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A22($at)
    MEM_H(-0X4A22, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x7D0
    ctx->r2 = 0 | 0X7D0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = ctx->r2;
L_80029E58:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // j           L_80029EEC
    // nop

    goto L_80029EEC;
    // nop

L_80029E6C:
    // addiu       $v0, $zero, -0xC8
    ctx->r2 = ADD32(0, -0XC8);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = ctx->r2;
    // j           L_80029EE0
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    goto L_80029EE0;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_80029E80:
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // j           L_80029EEC
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80029EEC;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80029E94:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A69($at)
    MEM_B(-0X4A69, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A22($at)
    MEM_H(-0X4A22, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = 0;
    // j           L_80029EF4
    // nop

    goto L_80029EF4;
    // nop

L_80029EC8:
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // j           L_80029EEC
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80029EEC;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80029EDC:
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
L_80029EE0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_80029EEC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A69($at)
    MEM_B(-0X4A69, ctx->r1) = ctx->r2;
L_80029EF4:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $a2, -0x4AC0($at)
    MEM_W(-0X4AC0, ctx->r1) = ctx->r6;
L_80029EFC:
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
