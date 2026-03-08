#include "recomp.h"
#include "disable_warnings.h"

void InteractWithObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x2($s2)
    ctx->r3 = MEM_BU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // addiu       $at, $at, 0x4720
    ctx->r1 = ADD32(ctx->r1, 0X4720);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $s1, 0x0($at)
    ctx->r17 = MEM_W(0X0, ctx->r1);
    // nop

    // beq         $s1, $zero, L_80049064
    if (ctx->r17 == 0) {
        // ori         $v0, $zero, 0x70
        ctx->r2 = 0 | 0X70;
        goto L_80049064;
    }
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // nop

    // bne         $v1, $v0, L_80049064
    if (ctx->r3 != ctx->r2) {
        // addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
        goto L_80049064;
    }
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80048CB4
    if (ctx->r2 != 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_80048CB4;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sb          $v0, 0x51DB($at)
    MEM_B(0X51DB, ctx->r1) = ctx->r2;
L_80048CB4:
    // jal         0x80048B10
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80048B10(rdram, ctx);
    goto after_0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // lbu         $a0, 0x51DB($a0)
    ctx->r4 = MEM_BU(0X51DB, ctx->r4);
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // nop

    // beq         $a0, $v1, L_80048D1C
    if (ctx->r4 == ctx->r3) {
        // addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
        goto L_80048D1C;
    }
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lbu         $v1, 0x13($s1)
    ctx->r3 = MEM_BU(0X13, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80048D1C
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80048D1C;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80048D08
    if (ctx->r3 == ctx->r2) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80048D08;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // ori         $v1, $zero, 0xF0
    ctx->r3 = 0 | 0XF0;
L_80048CF8:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $v1, L_80048CF8
    if (ctx->r2 != ctx->r3) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80048CF8;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80048D08:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $s0, 0xEC
    ctx->r2 = ADD32(ctx->r16, 0XEC);
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // sb          $zero, 0x13($s1)
    MEM_B(0X13, ctx->r17) = 0;
L_80048D1C:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // addiu       $v1, $v0, -0xF0
    ctx->r3 = ADD32(ctx->r2, -0XF0);
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80048E8C
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80048E8C;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x298C
    ctx->r1 = ADD32(ctx->r1, 0X298C);
    // addu        $at, $at, $v0
    gpr jr_addend_80048D48;
    jr_addend_80048D48 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80048D48 >> 2) {
        case 0: goto L_80048D50; break;
        case 1: goto L_80048E8C; break;
        case 2: goto L_80048DD0; break;
        case 3: goto L_80048F00; break;
        case 4: goto L_80048DE4; break;
        case 5: goto L_80048E18; break;
        case 6: goto L_80048E34; break;
        case 7: goto L_80048E5C; break;
        case 8: goto L_80048D58; break;
        case 9: goto L_80048D70; break;
        case 10: goto L_80048E8C; break;
        case 11: goto L_80048E8C; break;
        case 12: goto L_80048E8C; break;
        case 13: goto L_80048E8C; break;
        case 14: goto L_80048E8C; break;
        case 15: goto L_80048F1C; break;
        default: switch_error(__func__, 0x80048D48, 0x8001298C);
    }
    // nop

L_80048D50:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r2;
L_80048D58:
    // lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(0X1, ctx->r16);
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_80048D1C
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    goto L_80048D1C;
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
L_80048D70:
    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80048DBC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80048DBC;
    }
    // nop

    // lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(0X3, ctx->r16);
    // jal         0x80048AB4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80048AB4(rdram, ctx);
    goto after_1;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // j           L_80048D1C
    // addu        $s0, $s1, $v0
    ctx->r16 = ADD32(ctx->r17, ctx->r2);
    goto L_80048D1C;
    // addu        $s0, $s1, $v0
    ctx->r16 = ADD32(ctx->r17, ctx->r2);
L_80048DBC:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // j           L_80048D1C
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    goto L_80048D1C;
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
L_80048DD0:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // j           L_80048D1C
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    goto L_80048D1C;
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
L_80048DE4:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(0X10, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_2:
    // j           L_80048F00
    // nop

    goto L_80048F00;
    // nop

L_80048E18:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // lbu         $s3, 0x0($s0)
    ctx->r19 = MEM_BU(0X0, ctx->r16);
    // j           L_80048F00
    // nop

    goto L_80048F00;
    // nop

L_80048E34:
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sb          $v0, 0x51DB($at)
    MEM_B(0X51DB, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $zero, 0x13($s1)
    MEM_B(0X13, ctx->r17) = 0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_80048D1C
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    goto L_80048D1C;
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
L_80048E5C:
    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(0X2, ctx->r16);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // j           L_80048F00
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    goto L_80048F00;
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
L_80048E8C:
    // bne         $s4, $zero, L_80048EE8
    if (ctx->r20 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80048EE8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(0X1, ctx->r17);
    // nop

    // beq         $v1, $v0, L_80048EE8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80048EE8;
    }
    // nop

    // lhu         $a2, 0x18($s2)
    ctx->r6 = MEM_HU(0X18, ctx->r18);
    // lbu         $s5, 0xC($s2)
    ctx->r21 = MEM_BU(0XC, ctx->r18);
    // beq         $a2, $zero, L_80048ECC
    if (ctx->r6 == 0) {
        // ori         $s4, $zero, 0x1
        ctx->r20 = 0 | 0X1;
        goto L_80048ECC;
    }
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lbu         $a1, 0xC($s2)
    ctx->r5 = MEM_BU(0XC, ctx->r18);
    // lhu         $v0, 0x66($s2)
    ctx->r2 = MEM_HU(0X66, ctx->r18);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x800489FC
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800489FC(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_80048ECC:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0xFFF
    ctx->r7 = 0 | 0XFFF;
    // lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(0X1, ctx->r17);
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // jal         0x800489FC
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800489FC(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
L_80048EE8:
    // lhu         $a1, 0xC($s1)
    ctx->r5 = MEM_HU(0XC, ctx->r17);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x800378A0
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    LoadPopupsTexturOrTalk(rdram, ctx);
    goto after_5;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_5:
L_80048F00:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // beq         $s3, $zero, L_80048F1C
    if (ctx->r19 == 0) {
        // sb          $v0, 0x10($s1)
        MEM_B(0X10, ctx->r17) = ctx->r2;
        goto L_80048F1C;
    }
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // j           L_80048D1C
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    goto L_80048D1C;
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80048F1C:
    // lbu         $v0, 0x12($s1)
    ctx->r2 = MEM_BU(0X12, ctx->r17);
    // lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // lbu         $s3, -0x213D($s3)
    ctx->r19 = MEM_BU(-0X213D, ctx->r19);
    // andi        $v1, $v0, 0xF0
    ctx->r3 = ctx->r2 & 0XF0;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_80048F88
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x11
        ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
        goto L_80048F88;
    }
    // slti        $v0, $v1, 0x11
    ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_80048F50
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048F50;
    }
    // nop

    // beq         $v1, $zero, L_80048F6C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80048F6C;
    }
    // nop

    // j           L_80048FF0
    // nop

    goto L_80048FF0;
    // nop

L_80048F50:
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_80048FA0
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x30
        ctx->r2 = 0 | 0X30;
        goto L_80048FA0;
    }
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // beq         $v1, $v0, L_80048FB8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80048FB8;
    }
    // nop

    // j           L_80048FF0
    // nop

    goto L_80048FF0;
    // nop

L_80048F6C:
    // jal         0x8002BA60
    // nop

    HideInGameUI(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lbu         $a0, 0x12($s1)
    ctx->r4 = MEM_BU(0X12, ctx->r17);
    // jal         0x8001EF38
    // andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    sub_8001EF38(rdram, ctx);
    goto after_7;
    // andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    after_7:
    // j           L_80048FF0
    // nop

    goto L_80048FF0;
    // nop

L_80048F88:
    // jal         0x8002BA60
    // nop

    HideInGameUI(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x8001FD28
    // nop

    Locksmith_Menu(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_80048FF0
    // nop

    goto L_80048FF0;
    // nop

L_80048FA0:
    // jal         0x8002BA60
    // nop

    HideInGameUI(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x8001F9B8
    // nop

    sub_8001F9B8(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // j           L_80048FF0
    // nop

    goto L_80048FF0;
    // nop

L_80048FB8:
    // jal         0x8002BA60
    // nop

    HideInGameUI(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x8001F77C
    // nop

    sub_8001F77C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80048FF0
    if (ctx->r16 == ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80048FF0;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_14;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_14:
    // addiu       $a1, $s0, 0x168
    ctx->r5 = ADD32(ctx->r16, 0X168);
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // jal         0x800378A0
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    LoadPopupsTexturOrTalk(rdram, ctx);
    goto after_15;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_15:
L_80048FF0:
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lbu         $v0, -0x213D($v0)
    ctx->r2 = MEM_BU(-0X213D, ctx->r2);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // beq         $v0, $zero, L_80049010
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80049010;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sb          $v0, 0x51B8($at)
    MEM_B(0X51B8, ctx->r1) = ctx->r2;
L_80049010:
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sb          $v0, 0x51DB($at)
    MEM_B(0X51DB, ctx->r1) = ctx->r2;
    // beq         $s4, $zero, L_80049050
    if (ctx->r20 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80049050;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(0X11, ctx->r17);
    // nop

    // beq         $a1, $v0, L_80049050
    if (ctx->r5 == ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80049050;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // ori         $a3, $zero, 0xFFF
    ctx->r7 = 0 | 0XFFF;
    // jal         0x800489FC
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800489FC(rdram, ctx);
    goto after_16;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_16:
    // sb          $s5, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r21;
L_80049050:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v0, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r2;
    // jal         0x80027C38
    // nop

    Player_ResetMovement(rdram, ctx);
    goto after_17;
    // nop

    after_17:
L_80049064:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
