#include "recomp.h"
#include "disable_warnings.h"

void UpdateParticleEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // sw          $s2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // lw          $s2, 0x1184($s2)
    ctx->r18 = MEM_W(0X1184, ctx->r18);
    // sw          $s0, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // lw          $s0, 0x1180($s0)
    ctx->r16 = MEM_W(0X1180, ctx->r16);
    // sw          $ra, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r31;
    // sw          $s5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r21;
    // sw          $s4, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r20;
    // sw          $s3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r17;
    // lbu         $s4, 0x1($s2)
    ctx->r20 = MEM_BU(0X1, ctx->r18);
    // lbu         $s1, 0x7($s2)
    ctx->r17 = MEM_BU(0X7, ctx->r18);
    // sltiu       $v0, $s4, 0x7B
    ctx->r2 = ctx->r20 < 0X7B ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // sll         $v0, $s4, 2
        ctx->r2 = S32(ctx->r20) << 2;
        goto L_800485E4;
    }
    // sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x2788
    ctx->r1 = ADD32(ctx->r1, 0X2788);
    // addu        $at, $at, $v0
    gpr jr_addend_80045070;
    jr_addend_80045070 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80045070 >> 2) {
        case 0: goto L_80045FE4; break;
        case 1: goto L_80045D3C; break;
        case 2: goto L_800465BC; break;
        case 3: goto L_8004825C; break;
        case 4: goto L_800454C8; break;
        case 5: goto L_800468D8; break;
        case 6: goto L_800478D0; break;
        case 7: goto L_8004520C; break;
        case 8: goto L_800471EC; break;
        case 9: goto L_80046DC4; break;
        case 10: goto L_800475F8; break;
        case 11: goto L_8004649C; break;
        case 12: goto L_80046668; break;
        case 13: goto L_80045268; break;
        case 14: goto L_80048050; break;
        case 15: goto L_80047F90; break;
        case 16: goto L_80047FE8; break;
        case 17: goto L_80047FBC; break;
        case 18: goto L_800485E4; break;
        case 19: goto L_80048110; break;
        case 20: goto L_80046658; break;
        case 21: goto L_800485E4; break;
        case 22: goto L_80048224; break;
        case 23: goto L_800452E8; break;
        case 24: goto L_8004839C; break;
        case 25: goto L_8004554C; break;
        case 26: goto L_80045E28; break;
        case 27: goto L_80045E28; break;
        case 28: goto L_80045D34; break;
        case 29: goto L_80045078; break;
        case 30: goto L_80045080; break;
        case 31: goto L_80045078; break;
        case 32: goto L_80045268; break;
        case 33: goto L_80046F80; break;
        case 34: goto L_80045544; break;
        case 35: goto L_80045544; break;
        case 36: goto L_800485E4; break;
        case 37: goto L_800485E4; break;
        case 38: goto L_80045AF8; break;
        case 39: goto L_80045AD4; break;
        case 40: goto L_80045A9C; break;
        case 41: goto L_800485E4; break;
        case 42: goto L_800455B0; break;
        case 43: goto L_800485E4; break;
        case 44: goto L_800485E4; break;
        case 45: goto L_800458C4; break;
        case 46: goto L_8004577C; break;
        case 47: goto L_80045080; break;
        case 48: goto L_80045078; break;
        case 49: goto L_8004520C; break;
        case 50: goto L_80045C2C; break;
        case 51: goto L_8004653C; break;
        case 52: goto L_80046554; break;
        case 53: goto L_80046F78; break;
        case 54: goto L_8004649C; break;
        case 55: goto L_800485E4; break;
        case 56: goto L_800485E4; break;
        case 57: goto L_800485E4; break;
        case 58: goto L_800485E4; break;
        case 59: goto L_800485E4; break;
        case 60: goto L_800485E4; break;
        case 61: goto L_800485E4; break;
        case 62: goto L_800485E4; break;
        case 63: goto L_800485E4; break;
        case 64: goto L_800485E4; break;
        case 65: goto L_800485E4; break;
        case 66: goto L_800485E4; break;
        case 67: goto L_800485E4; break;
        case 68: goto L_800485E4; break;
        case 69: goto L_800485E4; break;
        case 70: goto L_800485E4; break;
        case 71: goto L_800485E4; break;
        case 72: goto L_800485E4; break;
        case 73: goto L_800485E4; break;
        case 74: goto L_800485E4; break;
        case 75: goto L_800485E4; break;
        case 76: goto L_800485E4; break;
        case 77: goto L_800485E4; break;
        case 78: goto L_800485E4; break;
        case 79: goto L_800485E4; break;
        case 80: goto L_800485E4; break;
        case 81: goto L_800485E4; break;
        case 82: goto L_800485E4; break;
        case 83: goto L_800485E4; break;
        case 84: goto L_800485E4; break;
        case 85: goto L_800485E4; break;
        case 86: goto L_800485E4; break;
        case 87: goto L_800485E4; break;
        case 88: goto L_800485E4; break;
        case 89: goto L_800485E4; break;
        case 90: goto L_800485E4; break;
        case 91: goto L_800485E4; break;
        case 92: goto L_800485E4; break;
        case 93: goto L_800485E4; break;
        case 94: goto L_800485E4; break;
        case 95: goto L_800485E4; break;
        case 96: goto L_800485E4; break;
        case 97: goto L_800485E4; break;
        case 98: goto L_800485E4; break;
        case 99: goto L_800485E4; break;
        case 100: goto L_800467BC; break;
        case 101: goto L_80047EE8; break;
        case 102: goto L_80047F44; break;
        case 103: goto L_800460C0; break;
        case 104: goto L_80046368; break;
        case 105: goto L_80046B74; break;
        case 106: goto L_800470CC; break;
        case 107: goto L_80047E10; break;
        case 108: goto L_800485E4; break;
        case 109: goto L_800484B0; break;
        case 110: goto L_800485E4; break;
        case 111: goto L_80045ED0; break;
        case 112: goto L_800485E4; break;
        case 113: goto L_800456C8; break;
        case 114: goto L_80048280; break;
        case 115: goto L_800455E4; break;
        case 116: goto L_800458E8; break;
        case 117: goto L_800459D0; break;
        case 118: goto L_80046578; break;
        case 119: goto L_80046580; break;
        case 120: goto L_800484F4; break;
        case 121: goto L_800460C0; break;
        case 122: goto L_80046368; break;
        default: switch_error(__func__, 0x80045070, 0x80012788);
    }
    // nop

L_80045078:
    // j           L_80045084
    // ori         $s0, $zero, 0xA
    ctx->r16 = 0 | 0XA;
    goto L_80045084;
    // ori         $s0, $zero, 0xA
    ctx->r16 = 0 | 0XA;
L_80045080:
    // ori         $s0, $zero, 0x5
    ctx->r16 = 0 | 0X5;
L_80045084:
    // bne         $s1, $zero, L_800485E4
    if (ctx->r17 != 0) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // lh          $v0, 0x42($s2)
    ctx->r2 = MEM_H(0X42, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800450B8
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x5
        ctx->r4 = 0 | 0X5;
        goto L_800450B8;
    }
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // addiu       $a1, $s2, 0x14
    ctx->r5 = ADD32(ctx->r18, 0X14);
    // ori         $a2, $zero, 0x6E
    ctx->r6 = 0 | 0X6E;
    // ori         $a3, $zero, 0x6D60
    ctx->r7 = 0 | 0X6D60;
    // ori         $v0, $zero, 0x7148
    ctx->r2 = 0 | 0X7148;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80014414
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    PlayPositionalSound3D_Wrap(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
L_800450B8:
    // lhu         $a1, 0x42($s2)
    ctx->r5 = MEM_HU(0X42, ctx->r18);
    // lh          $v0, 0x36($s2)
    ctx->r2 = MEM_H(0X36, ctx->r18);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // mult        $s0, $v1
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $s1, 0x18($s2)
    ctx->r17 = MEM_W(0X18, ctx->r18);
    // lh          $v1, 0x40($s2)
    ctx->r3 = MEM_H(0X40, ctx->r18);
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // sh          $a1, 0x42($s2)
    MEM_H(0X42, ctx->r18) = ctx->r5;
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(0X34, ctx->r18);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // ori         $a1, $zero, 0x14
    ctx->r5 = 0 | 0X14;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(0X38, ctx->r18);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800424C8
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    sub_800424C8(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $zero, L_80045190
    if (ctx->r16 != 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80045190;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(0X3C, ctx->r29);
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // ori         $a1, $zero, 0x14
    ctx->r5 = 0 | 0X14;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(0X40, ctx->r29);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // jal         0x800424C8
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    sub_800424C8(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_2:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045190:
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(0X3C, ctx->r29);
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(0X40, ctx->r29);
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    // jal         0x80044814
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    sub_80044814(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    after_3:
    // beq         $s0, $zero, L_800451D0
    if (ctx->r16 == 0) {
        // lui         $a0, 0x2
        ctx->r4 = S32(0X2 << 16);
        goto L_800451D0;
    }
    // lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // jal         0x800428D0
    // or          $a0, $s0, $a0
    ctx->r4 = ctx->r16 | ctx->r4;
    sub_800428D0(rdram, ctx);
    goto after_4;
    // or          $a0, $s0, $a0
    ctx->r4 = ctx->r16 | ctx->r4;
    after_4:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800451D0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x2A82($v0)
    ctx->r2 = MEM_HU(-0X2A82, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800451E8
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x2
        ctx->r3 = 0 | 0X2;
        goto L_800451E8;
    }
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
L_800451E8:
    // lh          $a0, 0x34($s2)
    ctx->r4 = MEM_H(0X34, ctx->r18);
    // lh          $a2, 0x38($s2)
    ctx->r6 = MEM_H(0X38, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // addiu       $a3, $s2, 0x24
    ctx->r7 = ADD32(ctx->r18, 0X24);
    // sb          $v1, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r3;
    // jal         0x800159DC
    // subu        $a1, $a1, $s1
    ctx->r5 = SUB32(ctx->r5, ctx->r17);
    Math_VectorToAngles(rdram, ctx);
    goto after_5;
    // subu        $a1, $a1, $s1
    ctx->r5 = SUB32(ctx->r5, ctx->r17);
    after_5:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_8004520C:
    // bne         $s1, $zero, L_80045258
    if (ctx->r17 != 0) {
        // slti        $v0, $s1, 0x3
        ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
        goto L_80045258;
    }
    // slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // ori         $a0, $zero, 0xB4
    ctx->r4 = 0 | 0XB4;
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // jal         0x80044C74
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    sub_80044C74(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800485E4
    if (ctx->r16 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800485E4;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // ori         $a2, $zero, 0x190
    ctx->r6 = 0 | 0X190;
    // ori         $a3, $zero, 0x2000
    ctx->r7 = 0 | 0X2000;
    // ori         $v0, $zero, 0x2000
    ctx->r2 = 0 | 0X2000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // jal         0x80044B20
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80044B20(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_7:
    // j           L_8004528C
    // nop

    goto L_8004528C;
    // nop

L_80045258:
    // bne         $v0, $zero, L_800452C0
    if (ctx->r2 != 0) {
        // addiu       $v0, $s1, -0x80
        ctx->r2 = ADD32(ctx->r17, -0X80);
        goto L_800452C0;
    }
    // addiu       $v0, $s1, -0x80
    ctx->r2 = ADD32(ctx->r17, -0X80);
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80045268:
    // bne         $s1, $zero, L_800452B4
    if (ctx->r17 != 0) {
        // slti        $v0, $s1, 0x3
        ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
        goto L_800452B4;
    }
    // slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // ori         $a0, $zero, 0xB4
    ctx->r4 = 0 | 0XB4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    sub_80044C74(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    after_8:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800452A8
    if (ctx->r16 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800452A8;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_8004528C:
    // jal         0x80044DF8
    // nop

    sub_80044DF8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_10;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_800452BC
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    goto L_800452BC;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_800452A8:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // j           L_80045E18
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80045E18;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_800452B4:
    // beq         $v0, $zero, L_80048468
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80048468;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800452BC:
    // addiu       $v0, $s1, -0x80
    ctx->r2 = ADD32(ctx->r17, -0X80);
L_800452C0:
    // sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // lbu         $v1, 0x7($s2)
    ctx->r3 = MEM_BU(0X7, ctx->r18);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // j           L_800485E4
    // sb          $v1, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r3;
    goto L_800485E4;
    // sb          $v1, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r3;
L_800452E8:
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // bne         $s1, $v0, L_80045494
    if (ctx->r17 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80045494;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lh          $v1, 0x40($s2)
    ctx->r3 = MEM_H(0X40, ctx->r18);
    // nop

    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x9($s0)
    ctx->r3 = MEM_BU(0X9, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80048468
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80048468;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v1, 0xE($s0)
    ctx->r3 = MEM_BU(0XE, ctx->r16);
    // ori         $v0, $zero, 0x19
    ctx->r2 = 0 | 0X19;
    // bne         $v1, $v0, L_80048468
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80048468;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lh          $a1, 0x42($s2)
    ctx->r5 = MEM_H(0X42, ctx->r18);
    // jal         0x8003EAC0
    // addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    sub_8003EAC0(rdram, ctx);
    goto after_11;
    // addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_11:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003EBC0
    // addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    sub_8003EBC0(rdram, ctx);
    goto after_12;
    // addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_12:
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(0X18, ctx->r18);
    // lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(0X1C, ctx->r18);
    // lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(0X20, ctx->r18);
    // sw          $v1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r3;
    // sw          $a0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r4;
    // sw          $a1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r5;
    // sw          $a2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r6;
    // lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(0X68, ctx->r29);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r3;
    // lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(0X6C, ctx->r29);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // addiu       $s1, $s2, 0x14
    ctx->r17 = ADD32(ctx->r18, 0X14);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(0X70, ctx->r29);
    // lhu         $v1, 0x2C($s2)
    ctx->r3 = MEM_HU(0X2C, ctx->r18);
    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $v1, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slti        $v1, $v1, 0x1801
    ctx->r3 = SIGNED(ctx->r3) < 0X1801 ? 1 : 0;
    // bne         $v1, $zero, L_800453CC
    if (ctx->r3 != 0) {
        // sw          $a0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r4;
        goto L_800453CC;
    }
    // sw          $a0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r4;
    // ori         $v0, $zero, 0x1800
    ctx->r2 = 0 | 0X1800;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
L_800453CC:
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x14($s2)
    ctx->r2 = MEM_HU(0X14, ctx->r18);
    // lhu         $v1, 0x88($sp)
    ctx->r3 = MEM_HU(0X88, ctx->r29);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x18($s2)
    ctx->r2 = MEM_HU(0X18, ctx->r18);
    // lhu         $v1, 0x8C($sp)
    ctx->r3 = MEM_HU(0X8C, ctx->r29);
    // addiu       $a2, $zero, -0x2BC
    ctx->r6 = ADD32(0, -0X2BC);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // lhu         $v1, 0x90($sp)
    ctx->r3 = MEM_HU(0X90, ctx->r29);
    // lh          $a3, 0x2C($s2)
    ctx->r7 = MEM_H(0X2C, ctx->r18);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x8004489C
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8004489C(rdram, ctx);
    goto after_13;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_13:
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // lhu         $v1, 0x44($s2)
    ctx->r3 = MEM_HU(0X44, ctx->r18);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800485E4
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800485E4;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A64
    ctx->r5 = ADD32(ctx->r5, -0X4A64);
    // ori         $a2, $zero, 0x28A
    ctx->r6 = 0 | 0X28A;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // addiu       $v0, $s2, 0x34
    ctx->r2 = ADD32(ctx->r18, 0X34);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_14;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_14:
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
    // j           L_800485E4
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80045494:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // ori         $a2, $zero, 0x100
    ctx->r6 = 0 | 0X100;
    // lh          $a3, 0x2C($s2)
    ctx->r7 = MEM_H(0X2C, ctx->r18);
    // addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x8004489C
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8004489C(rdram, ctx);
    goto after_15;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_15:
    // j           L_8004520C
    // nop

    goto L_8004520C;
    // nop

L_800454C8:
    // ori         $a0, $zero, 0xB4
    ctx->r4 = 0 | 0XB4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_16;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_16:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80045518
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0xF
        ctx->r2 = ctx->r16 & 0XF;
        goto L_80045518;
    }
    // andi        $v0, $s0, 0xF
    ctx->r2 = ctx->r16 & 0XF;
    // beq         $v0, $zero, L_800454F0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800454F0;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_800454F0:
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // bne         $v0, $zero, L_80045520
    if (ctx->r2 != 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80045520;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_17;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // j           L_80045520
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    goto L_80045520;
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045518:
    // sb          $zero, 0x40($s2)
    MEM_B(0X40, ctx->r18) = 0;
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045520:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    // addiu       $v0, $v0, 0x2EE
    ctx->r2 = ADD32(ctx->r2, 0X2EE);
    // jal         0x80044814
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    sub_80044814(rdram, ctx);
    goto after_18;
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    after_18:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045544:
    // j           L_80045550
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80045550;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8004554C:
    // addiu       $a2, $zero, -0x1E
    ctx->r6 = ADD32(0, -0X1E);
L_80045550:
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
    // jal         0x80044C74
    // ori         $a1, $zero, 0x64
    ctx->r5 = 0 | 0X64;
    sub_80044C74(rdram, ctx);
    goto after_19;
    // ori         $a1, $zero, 0x64
    ctx->r5 = 0 | 0X64;
    after_19:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8004559C
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0xF
        ctx->r2 = ctx->r16 & 0XF;
        goto L_8004559C;
    }
    // andi        $v0, $s0, 0xF
    ctx->r2 = ctx->r16 & 0XF;
    // beq         $v0, $zero, L_80045574
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80045574;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80045574:
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800455A4
    if (ctx->r2 != 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800455A4;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_20;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_20:
    // j           L_800455A4
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    goto L_800455A4;
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_8004559C:
    // sb          $zero, 0x40($s2)
    MEM_B(0X40, ctx->r18) = 0;
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_800455A4:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // j           L_80045E18
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80045E18;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_800455B0:
    // lb          $v0, 0x40($s2)
    ctx->r2 = MEM_B(0X40, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800455D8
    if (ctx->r2 != 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_800455D8;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0x3800
    ctx->r4 = 0 | 0X3800;
    // ori         $a1, $zero, 0x1F8
    ctx->r5 = 0 | 0X1F8;
    // j           L_80046568
    // ori         $a2, $zero, 0x46
    ctx->r6 = 0 | 0X46;
    goto L_80046568;
    // ori         $a2, $zero, 0x46
    ctx->r6 = 0 | 0X46;
L_800455D8:
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_800485E4
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
L_800455E4:
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
    // ori         $a1, $zero, 0x28
    ctx->r5 = 0 | 0X28;
    // ori         $a2, $zero, 0x24
    ctx->r6 = 0 | 0X24;
    // ori         $a3, $zero, 0xB4
    ctx->r7 = 0 | 0XB4;
    // ori         $v0, $zero, 0x168
    ctx->r2 = 0 | 0X168;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x104
    ctx->r2 = 0 | 0X104;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // jal         0x8004435C
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8004435C(rdram, ctx);
    goto after_21;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_21:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80045638
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80045638;
    }
    // nop

    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800456BC
    if (ctx->r2 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800456BC;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045638:
    // jal         0x80044DF8
    // addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    sub_80044DF8(rdram, ctx);
    goto after_22;
    // addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    after_22:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_23;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_23:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_24;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_24:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_25;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_25:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    PlayEntitySound(rdram, ctx);
    goto after_26;
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    after_26:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800456BC:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // j           L_80045E18
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80045E18;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_800456C8:
    // ori         $a0, $zero, 0xB4
    ctx->r4 = 0 | 0XB4;
    // ori         $a1, $zero, 0x168
    ctx->r5 = 0 | 0X168;
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_27;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_27:
    // bne         $v0, $zero, L_800456F4
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_800456F4;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80045770
    if (ctx->r2 == 0) {
        // ori         $a1, $zero, 0x2000
        ctx->r5 = 0 | 0X2000;
        goto L_80045770;
    }
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
L_800456F4:
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_28;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_28:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_29;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_29:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_30;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_30:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    PlayEntitySound(rdram, ctx);
    goto after_31;
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    after_31:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80045770:
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // j           L_80045E18
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80045E18;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_8004577C:
    // lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(0X34, ctx->r18);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(0X38, ctx->r18);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // lb          $a0, 0x41($s2)
    ctx->r4 = MEM_B(0X41, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1280
    ctx->r3 = ADD32(ctx->r3, -0X1280);
    // lb          $a0, 0x40($s2)
    ctx->r4 = MEM_B(0X40, ctx->r18);
    // nop

    // beq         $a0, $zero, L_800457DC
    if (ctx->r4 == 0) {
        // addu        $s0, $v0, $v1
        ctx->r16 = ADD32(ctx->r2, ctx->r3);
        goto L_800457DC;
    }
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a0, $v0, L_80045888
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80045888;
    }
    // nop

    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800457DC:
    // lh          $v1, 0x2E($s2)
    ctx->r3 = MEM_H(0X2E, ctx->r18);
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    sub_8002E4F4(rdram, ctx);
    goto after_32;
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    after_32:
    // jal         0x800428D0
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    sub_800428D0(rdram, ctx);
    goto after_33;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_33:
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(0X18, ctx->r16);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E120
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    MAP_CollisionWithTile(rdram, ctx);
    goto after_34;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_34:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2A7C
    ctx->r3 = ADD32(ctx->r3, -0X2A7C);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A78($v0)
    ctx->r2 = MEM_W(-0X2A78, ctx->r2);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0x7FFF
    ctx->r2 = 0 | 0X7FFF;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80045860
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x7FFF
        ctx->r2 = 0 | 0X7FFF;
        goto L_80045860;
    }
    // ori         $v0, $zero, 0x7FFF
    ctx->r2 = 0 | 0X7FFF;
    // j           L_80045864
    // sh          $v1, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r3;
    goto L_80045864;
    // sh          $v1, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r3;
L_80045860:
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
L_80045864:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_800485E4
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lhu         $v1, 0x2E($s2)
    ctx->r3 = MEM_HU(0X2E, ctx->r18);
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // sh          $zero, 0x42($s2)
    MEM_H(0X42, ctx->r18) = 0;
    // j           L_800485E4
    // sh          $v1, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r3;
    goto L_800485E4;
    // sh          $v1, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r3;
L_80045888:
    // lh          $a0, 0x32($s2)
    ctx->r4 = MEM_H(0X32, ctx->r18);
    // lh          $a2, 0x42($s2)
    ctx->r6 = MEM_H(0X42, ctx->r18);
    // jal         0x80015D18
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    FixedPointLerp(rdram, ctx);
    goto after_35;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_35:
    // lhu         $v1, 0x42($s2)
    ctx->r3 = MEM_HU(0X42, ctx->r18);
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // sh          $v1, 0x42($s2)
    MEM_H(0X42, ctx->r18) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slti        $v1, $v1, 0x1000
    ctx->r3 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // bne         $v1, $zero, L_800485E4
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80048468
    // nop

    goto L_80048468;
    // nop

L_800458C4:
    // ori         $a0, $zero, 0x4000
    ctx->r4 = 0 | 0X4000;
    // ori         $a2, $zero, 0x46
    ctx->r6 = 0 | 0X46;
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    // lh          $a1, 0x40($s2)
    ctx->r5 = MEM_H(0X40, ctx->r18);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // jal         0x800446E0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800446E0(rdram, ctx);
    goto after_36;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_36:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800458E8:
    // ori         $s0, $zero, 0xA
    ctx->r16 = 0 | 0XA;
    // lhu         $v0, 0x34($s2)
    ctx->r2 = MEM_HU(0X34, ctx->r18);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(0X34, ctx->r18);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(0X18, ctx->r18);
    // lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(0X1C, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lh          $v0, 0x36($s2)
    ctx->r2 = MEM_H(0X36, ctx->r18);
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_H(0X38, ctx->r18);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(0X58, ctx->r29);
    // lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(0X5C, ctx->r29);
    // lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(0X60, ctx->r29);
    // jal         0x8002E318
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    CollisionWithTilemap(rdram, ctx);
    goto after_37;
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    after_37:
    // bne         $v0, $zero, L_800459A4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800459A4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E318
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    CollisionWithTilemap(rdram, ctx);
    goto after_38;
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    after_38:
    // beq         $v0, $zero, L_800459A8
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800459A8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800459A4:
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_800459A8:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2D
    ctx->r6 = 0 | 0X2D;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x1A4
    ctx->r2 = 0 | 0X1A4;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80042D2C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_39;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_39:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800459D0:
    // lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(0X34, ctx->r18);
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lh          $v1, 0x36($s2)
    ctx->r3 = MEM_H(0X36, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(0X38, ctx->r18);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1388
    ctx->r2 = ADD32(ctx->r2, 0X1388);
    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // nop

    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2710
    ctx->r2 = 0 | 0X2710;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(0X38, ctx->r29);
    // lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(0X3C, ctx->r29);
    // lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(0X40, ctx->r29);
    // jal         0x8003D480
    // ori         $a3, $zero, 0x64
    ctx->r7 = 0 | 0X64;
    Entity_CheckWorldCollision(rdram, ctx);
    goto after_40;
    // ori         $a3, $zero, 0x64
    ctx->r7 = 0 | 0X64;
    after_40:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80045A80
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_80045A80;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2D
    ctx->r6 = 0 | 0X2D;
    // sll         $a3, $v1, 5
    ctx->r7 = S32(ctx->r3) << 5;
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7) << 2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, -0x19CC
    ctx->r2 = ADD32(ctx->r2, -0X19CC);
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x4EC
    ctx->r2 = 0 | 0X4EC;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80042D2C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_41;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_41:
L_80045A80:
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x7FFF
    ctx->r6 = 0 | 0X7FFF;
    // jal         0x80044814
    // ori         $a3, $zero, 0x2710
    ctx->r7 = 0 | 0X2710;
    sub_80044814(rdram, ctx);
    goto after_42;
    // ori         $a3, $zero, 0x2710
    ctx->r7 = 0 | 0X2710;
    after_42:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045A9C:
    // ori         $a0, $zero, 0x64
    ctx->r4 = 0 | 0X64;
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_43;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_43:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80045AC8
    if (ctx->r16 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80045AC8;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_44;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_44:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80045AC8:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // j           L_80045E18
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80045E18;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_80045AD4:
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x2D
    ctx->r2 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // bne         $v0, $zero, L_80045B18
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x258
        ctx->r4 = 0 | 0X258;
        goto L_80045B18;
    }
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
L_80045AF8:
    // ori         $a0, $zero, 0x64
    ctx->r4 = 0 | 0X64;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_45;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_45:
    // bne         $v0, $zero, L_80045B54
    if (ctx->r2 != 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80045B54;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // j           L_80045C20
    // nop

    goto L_80045C20;
    // nop

L_80045B18:
    // ori         $a1, $zero, 0x28
    ctx->r5 = 0 | 0X28;
    // ori         $a2, $zero, 0x24
    ctx->r6 = 0 | 0X24;
    // ori         $a3, $zero, 0x32
    ctx->r7 = 0 | 0X32;
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x104
    ctx->r2 = 0 | 0X104;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // jal         0x8004435C
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8004435C(rdram, ctx);
    goto after_46;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_46:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80045C20
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80045C20;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045B54:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A6C($a0)
    ctx->r4 = MEM_W(-0X2A6C, ctx->r4);
    // nop

    // andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // beq         $v0, $zero, L_80045B94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80045B94;
    }
    // nop

    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // bne         $v0, $zero, L_80045B8C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80045B8C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x800428D0
    // ori         $s0, $zero, 0xB
    ctx->r16 = 0 | 0XB;
    sub_800428D0(rdram, ctx);
    goto after_47;
    // ori         $s0, $zero, 0xB
    ctx->r16 = 0 | 0XB;
    after_47:
    // j           L_80045BA0
    // addiu       $s4, $zero, -0x5A
    ctx->r20 = ADD32(0, -0X5A);
    goto L_80045BA0;
    // addiu       $s4, $zero, -0x5A
    ctx->r20 = ADD32(0, -0X5A);
L_80045B8C:
    // j           L_80045B98
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    goto L_80045B98;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
L_80045B94:
    // sb          $zero, 0x40($s2)
    MEM_B(0X40, ctx->r18) = 0;
L_80045B98:
    // ori         $s0, $zero, 0xB
    ctx->r16 = 0 | 0XB;
    // addiu       $s4, $zero, -0x5A
    ctx->r20 = ADD32(0, -0X5A);
L_80045BA0:
    // ori         $s3, $zero, 0x200
    ctx->r19 = 0 | 0X200;
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80045BAC:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // jal         0x8004489C
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    sub_8004489C(rdram, ctx);
    goto after_48;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    after_48:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80045BAC
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80045BAC;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A6C($v0)
    ctx->r2 = MEM_W(-0X2A6C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // beq         $v0, $zero, L_80045C1C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80045C1C;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80045C1C:
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045C20:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // j           L_80045E18
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80045E18;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_80045C2C:
    // lb          $v1, 0x40($s2)
    ctx->r3 = MEM_B(0X40, ctx->r18);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80045CB8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80045CB8;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80045C54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80045C54;
    }
    // nop

    // beq         $v1, $zero, L_80045C68
    if (ctx->r3 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80045C68;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045C54:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_80045D00
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045D00;
    }
    // nop

    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045C68:
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // addiu       $a1, $s2, 0x14
    ctx->r5 = ADD32(ctx->r18, 0X14);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // jal         0x80028D54
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    Local2World(rdram, ctx);
    goto after_49;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    after_49:
    // lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(0X2C, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // bne         $v0, $zero, L_800485E4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $s2, 0x34
    ctx->r6 = ADD32(ctx->r18, 0X34);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x98
    ctx->r7 = ADD32(ctx->r29, 0X98);
    CalculateTrajectory(rdram, ctx);
    goto after_50;
    // addiu       $a3, $sp, 0x98
    ctx->r7 = ADD32(ctx->r29, 0X98);
    after_50:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045CB8:
    // ori         $a0, $zero, 0x200
    ctx->r4 = 0 | 0X200;
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_51;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_51:
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800485E4;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    // ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80042938
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80042938(rdram, ctx);
    goto after_52;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_52:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045D00:
    // lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(0X2C, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x200
    ctx->r2 = SIGNED(ctx->r2) < 0X200 ? 1 : 0;
    // bne         $v0, $zero, L_80045D18
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80045D18;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80045D18:
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // j           L_800485E4
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
L_80045D34:
    // j           L_80045D40
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
    goto L_80045D40;
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
L_80045D3C:
    // ori         $a0, $zero, 0x1F4
    ctx->r4 = 0 | 0X1F4;
L_80045D40:
    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $v0, L_80045D7C
    if (ctx->r3 != ctx->r2) {
        // ori         $s1, $zero, 0x1
        ctx->r17 = 0 | 0X1;
        goto L_80045D7C;
    }
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // lhu         $v0, 0x10($s2)
    ctx->r2 = MEM_HU(0X10, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_800485E4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80048468
    // nop

    goto L_80048468;
    // nop

L_80045D7C:
    // bne         $v1, $s1, L_80045D94
    if (ctx->r3 != ctx->r17) {
        // sll         $a1, $a0, 1
        ctx->r5 = S32(ctx->r4) << 1;
        goto L_80045D94;
    }
    // sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4) << 1;
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
L_80045D94:
    // lhu         $v0, 0x24($s2)
    ctx->r2 = MEM_HU(0X24, ctx->r18);
    // ori         $a2, $zero, 0xFA
    ctx->r6 = 0 | 0XFA;
    // addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
    // jal         0x80044C74
    // sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    sub_80044C74(rdram, ctx);
    goto after_53;
    // sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    after_53:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80045E10
    if (ctx->r16 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80045E10;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_54;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_54:
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // bne         $v0, $s1, L_80045DEC
    if (ctx->r2 != ctx->r17) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80045DEC;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // sb          $v0, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // j           L_800485E4
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
L_80045DEC:
    // jal         0x80044DF8
    // nop

    sub_80044DF8(rdram, ctx);
    goto after_55;
    // nop

    after_55:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
    // sh          $zero, 0x38($s2)
    MEM_H(0X38, ctx->r18) = 0;
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_80045E10:
    // ori         $a1, $zero, 0x4000
    ctx->r5 = 0 | 0X4000;
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
L_80045E18:
    // jal         0x80044814
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    sub_80044814(rdram, ctx);
    goto after_56;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    after_56:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045E28:
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // lh          $a2, 0x2C($s2)
    ctx->r6 = MEM_H(0X2C, ctx->r18);
    // addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // jal         0x80042938
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80042938(rdram, ctx);
    goto after_57;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_57:
    // lb          $v1, 0x40($s2)
    ctx->r3 = MEM_B(0X40, ctx->r18);
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // beq         $v1, $zero, L_80045E84
    if (ctx->r3 == 0) {
        // sb          $v0, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r2;
        goto L_80045E84;
    }
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80045EAC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045EAC;
    }
    // nop

    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045E84:
    // ori         $a0, $zero, 0x64
    ctx->r4 = 0 | 0X64;
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_58;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_58:
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // sh          $zero, 0x38($s2)
    MEM_H(0X38, ctx->r18) = 0;
    // sh          $zero, 0x36($s2)
    MEM_H(0X36, ctx->r18) = 0;
    // j           L_800485E4
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
    goto L_800485E4;
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
L_80045EAC:
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_800485E4
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80048468
    // nop

    goto L_80048468;
    // nop

L_80045ED0:
    // lh          $v1, 0x40($s2)
    ctx->r3 = MEM_H(0X40, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80045F14
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_80045F14;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // nop

    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // nop

    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // ori         $s0, $zero, 0x3E8
    ctx->r16 = 0 | 0X3E8;
    // sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // sh          $zero, 0x68($sp)
    MEM_H(0X68, ctx->r29) = 0;
    // j           L_80045F6C
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    goto L_80045F6C;
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
L_80045F14:
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(0X2C, ctx->r2);
    // lhu         $s0, 0x1C($v0)
    ctx->r16 = MEM_HU(0X1C, ctx->r2);
    // sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(0X34, ctx->r2);
    // nop

    // sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(0X30, ctx->r2);
    // nop

    // sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // lwl         $v1, 0x53($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X53, ctx->r2);
    // lwr         $v1, 0x50($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X50, ctx->r2);
    // lwl         $a0, 0x57($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X57, ctx->r2);
    // lwr         $a0, 0x54($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X54, ctx->r2);
    // swl         $v1, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r3);
    // swr         $v1, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r3);
    // swl         $a0, 0x6F($sp)
    do_swl(rdram, 0X6F, ctx->r29, ctx->r4);
    // swr         $a0, 0x6C($sp)
    do_swr(rdram, 0X6C, ctx->r29, ctx->r4);
L_80045F6C:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_59;
    // nop

    after_59:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80062BF0
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_60;
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_60:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(0X3C, ctx->r29);
    // lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(0X40, ctx->r29);
    // addiu       $v0, $v0, -0x7D0
    ctx->r2 = ADD32(ctx->r2, -0X7D0);
    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_61;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_61:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80045FE4:
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // lh          $v1, 0x2C($s2)
    ctx->r3 = MEM_H(0X2C, ctx->r18);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // slti        $v1, $v1, 0xC00
    ctx->r3 = SIGNED(ctx->r3) < 0XC00 ? 1 : 0;
    // beq         $v1, $zero, L_80046014
    if (ctx->r3 == 0) {
        // sh          $v0, 0x36($s2)
        MEM_H(0X36, ctx->r18) = ctx->r2;
        goto L_80046014;
    }
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
L_80046014:
    // ori         $a0, $zero, 0xB4
    ctx->r4 = 0 | 0XB4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    sub_80044C74(rdram, ctx);
    goto after_62;
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    after_62:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800460A8
    if (ctx->r16 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800460A8;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // bne         $v0, $zero, L_80046060
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0x10
        ctx->r2 = ctx->r16 & 0X10;
        goto L_80046060;
    }
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_63;
    // nop

    after_63:
    // slti        $v0, $v0, 0xBB8
    ctx->r2 = SIGNED(ctx->r2) < 0XBB8 ? 1 : 0;
    // beq         $v0, $zero, L_80046060
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x10
        ctx->r2 = ctx->r16 & 0X10;
        goto L_80046060;
    }
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_64;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_64:
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
L_80046060:
    // beq         $v0, $zero, L_8004606C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004606C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
L_8004606C:
    // andi        $v0, $s0, 0x5
    ctx->r2 = ctx->r16 & 0X5;
    // beq         $v0, $zero, L_800460A4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800460A4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s1, $v0, L_8004608C
    if (ctx->r17 != ctx->r2) {
        // ori         $v1, $zero, 0x1
        ctx->r3 = 0 | 0X1;
        goto L_8004608C;
    }
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_800460A4
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    goto L_800460A4;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_8004608C:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // sb          $v1, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r3;
    // addiu       $v1, $zero, -0xC8
    ctx->r3 = ADD32(0, -0XC8);
    // sh          $v1, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_800460A4:
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_800460A8:
    // ori         $a1, $zero, 0x400
    ctx->r5 = 0 | 0X400;
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    // jal         0x80044814
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    sub_80044814(rdram, ctx);
    goto after_65;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    after_65:
    // j           L_800485D4
    // nop

    goto L_800485D4;
    // nop

L_800460C0:
    // lbu         $v1, 0x7($s2)
    ctx->r3 = MEM_BU(0X7, ctx->r18);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $v0, L_800460F8
    if (ctx->r3 != ctx->r2) {
        // ori         $a0, $zero, 0x32
        ctx->r4 = 0 | 0X32;
        goto L_800460F8;
    }
    // ori         $a0, $zero, 0x32
    ctx->r4 = 0 | 0X32;
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    // lh          $v1, 0x2C($s2)
    ctx->r3 = MEM_H(0X2C, ctx->r18);
    // nop

    // bgtz        $v1, L_800485E4
    if (SIGNED(ctx->r3) > 0) {
        // sh          $v0, 0x2E($s2)
        MEM_H(0X2E, ctx->r18) = ctx->r2;
        goto L_800485E4;
    }
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800460F8:
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // jal         0x80044C74
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    sub_80044C74(rdram, ctx);
    goto after_66;
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    after_66:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80046198
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0xF
        ctx->r2 = ctx->r16 & 0XF;
        goto L_80046198;
    }
    // andi        $v0, $s0, 0xF
    ctx->r2 = ctx->r16 & 0XF;
    // beq         $v0, $zero, L_80046190
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80046190;
    }
    // nop

    // bne         $s1, $zero, L_80046134
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80046134;
    }
    // nop

    // jal         0x80044DF8
    // nop

    sub_80044DF8(rdram, ctx);
    goto after_67;
    // nop

    after_67:
    // sh          $zero, 0x38($s2)
    MEM_H(0X38, ctx->r18) = 0;
    // j           L_80046190
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
    goto L_80046190;
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
L_80046134:
    // jal         0x80044DF8
    // nop

    sub_80044DF8(rdram, ctx);
    goto after_68;
    // nop

    after_68:
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E120
    // ori         $a3, $zero, 0x32
    ctx->r7 = 0 | 0X32;
    MAP_CollisionWithTile(rdram, ctx);
    goto after_69;
    // ori         $a3, $zero, 0x32
    ctx->r7 = 0 | 0X32;
    after_69:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A7C($a0)
    ctx->r4 = MEM_W(-0X2A7C, ctx->r4);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A74($v1)
    ctx->r3 = MEM_W(-0X2A74, ctx->r3);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004617C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004617C;
    }
    // nop

    // j           L_80046180
    // sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    goto L_80046180;
    // sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
L_8004617C:
    // sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
L_80046180:
    // lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(0X74, ctx->r29);
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // j           L_8004621C
    // subu        $s3, $v1, $v0
    ctx->r19 = SUB32(ctx->r3, ctx->r2);
    goto L_8004621C;
    // subu        $s3, $v1, $v0
    ctx->r19 = SUB32(ctx->r3, ctx->r2);
L_80046190:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80046198:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s1, $v0, L_800462B4
    if (ctx->r17 != ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800462B4;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a2, $zero, 0xBB8
    ctx->r6 = 0 | 0XBB8;
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // lh          $a1, 0x34($s2)
    ctx->r5 = MEM_H(0X34, ctx->r18);
    // addiu       $v0, $v0, -0x46
    ctx->r2 = ADD32(ctx->r2, -0X46);
    // jal         0x80015D18
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    FixedPointLerp(rdram, ctx);
    goto after_70;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    after_70:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lh          $a1, 0x38($s2)
    ctx->r5 = MEM_H(0X38, ctx->r18);
    // ori         $a2, $zero, 0xBB8
    ctx->r6 = 0 | 0XBB8;
    // jal         0x80015D18
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    FixedPointLerp(rdram, ctx);
    goto after_71;
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    after_71:
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A7C($a0)
    ctx->r4 = MEM_W(-0X2A7C, ctx->r4);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A74($v1)
    ctx->r3 = MEM_W(-0X2A74, ctx->r3);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800461FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800461FC;
    }
    // nop

    // j           L_80046200
    // sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    goto L_80046200;
    // sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
L_800461FC:
    // sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
L_80046200:
    // lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(0X74, ctx->r29);
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // nop

    // subu        $s3, $v0, $v1
    ctx->r19 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $s3, 0x1B58
    ctx->r2 = SIGNED(ctx->r19) < 0X1B58 ? 1 : 0;
    // bne         $v0, $zero, L_800462E0
    if (ctx->r2 != 0) {
        // ori         $s0, $zero, 0x3
        ctx->r16 = 0 | 0X3;
        goto L_800462E0;
    }
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
L_8004621C:
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // nop

    // sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // ori         $a1, $v0, 0x3
    ctx->r5 = ctx->r2 | 0X3;
    // ori         $v0, $zero, 0x67
    ctx->r2 = 0 | 0X67;
    // bne         $s4, $v0, L_80046254
    if (ctx->r20 != ctx->r2) {
        // ori         $a2, $zero, 0x7A
        ctx->r6 = 0 | 0X7A;
        goto L_80046254;
    }
    // ori         $a2, $zero, 0x7A
    ctx->r6 = 0 | 0X7A;
    // ori         $a2, $zero, 0x68
    ctx->r6 = 0 | 0X68;
L_80046254:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    SpawnParticleEntity(rdram, ctx);
    goto after_72;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_72:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // sra         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) >> 1;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sra         $v0, $s3, 4
    ctx->r2 = S32(ctx->r19) >> 4;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_73;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_73:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    PlayEntitySound(rdram, ctx);
    goto after_74;
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    after_74:
    // j           L_800462E0
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    goto L_800462E0;
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
L_800462B4:
    // bne         $s1, $zero, L_800462E0
    if (ctx->r17 != 0) {
        // ori         $s0, $zero, 0x3
        ctx->r16 = 0 | 0X3;
        goto L_800462E0;
    }
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    // lhu         $v0, 0x40($s2)
    ctx->r2 = MEM_HU(0X40, ctx->r18);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_800462E0
    if (SIGNED(ctx->r2) > 0) {
        // sh          $v1, 0x40($s2)
        MEM_H(0X40, ctx->r18) = ctx->r3;
        goto L_800462E0;
    }
    // sh          $v1, 0x40($s2)
    MEM_H(0X40, ctx->r18) = ctx->r3;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
L_800462E0:
    // jal         0x80062BF0
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    rand_recomp(rdram, ctx);
    goto after_75;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_75:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // jal         0x80062BF0
    // sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_76;
    // sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    after_76:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // jal         0x80062BF0
    // sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_77;
    // sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    after_77:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x65
    ctx->r6 = 0 | 0X65;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x80
    ctx->r2 = ADD32(ctx->r29, 0X80);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    SpawnParticleEntity(rdram, ctx);
    goto after_78;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_78:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_800485E4
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // j           L_800462E0
    // nop

    goto L_800462E0;
    // nop

L_80046368:
    // slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_800463DC
    if (ctx->r2 == 0) {
        // andi        $v0, $s1, 0x1
        ctx->r2 = ctx->r17 & 0X1;
        goto L_800463DC;
    }
    // andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
    // lh          $v1, 0x2E($s2)
    ctx->r3 = MEM_H(0X2E, ctx->r18);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DC50
    // nop

    sub_8005DC50(rdram, ctx);
    goto after_79;
    // nop

    after_79:
    // jal         0x8005DC50
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    sub_8005DC50(rdram, ctx);
    goto after_80;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_80:
    // sra         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) >> 3;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // ori         $a1, $v0, 0x3
    ctx->r5 = ctx->r2 | 0X3;
    // ori         $v0, $zero, 0x68
    ctx->r2 = 0 | 0X68;
    // bne         $s4, $v0, L_800463C0
    if (ctx->r20 != ctx->r2) {
        // ori         $a2, $zero, 0x36
        ctx->r6 = 0 | 0X36;
        goto L_800463C0;
    }
    // ori         $a2, $zero, 0x36
    ctx->r6 = 0 | 0X36;
    // ori         $a2, $zero, 0xB
    ctx->r6 = 0 | 0XB;
L_800463C0:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // addiu       $v0, $sp, 0x88
    ctx->r2 = ADD32(ctx->r29, 0X88);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    SpawnParticleEntity(rdram, ctx);
    goto after_81;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_81:
    // andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
L_800463DC:
    // lbu         $v1, 0x7($s2)
    ctx->r3 = MEM_BU(0X7, ctx->r18);
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sltiu       $v1, $v1, 0x9
    ctx->r3 = ctx->r3 < 0X9 ? 1 : 0;
    // beq         $v1, $zero, L_800478BC
    if (ctx->r3 == 0) {
        // sb          $v0, 0x4($s2)
        MEM_B(0X4, ctx->r18) = ctx->r2;
        goto L_800478BC;
    }
    // sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x80015990
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_80015990(rdram, ctx);
    goto after_82;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_82:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // slti        $v0, $s0, 0x7D01
    ctx->r2 = SIGNED(ctx->r16) < 0X7D01 ? 1 : 0;
    // beq         $v0, $zero, L_800478BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800478BC;
    }
    // nop

    // lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(0X7, ctx->r18);
    // jal         0x800601F4
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    FixedSin(rdram, ctx);
    goto after_83;
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    after_83:
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // ori         $v1, $zero, 0x7D00
    ctx->r3 = 0 | 0X7D00;
    // subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x1062
    ctx->r2 = S32(0X1062 << 16);
    // ori         $v0, $v0, 0x4DD3
    ctx->r2 = ctx->r2 | 0X4DD3;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
    // ori         $a1, $zero, 0xB4
    ctx->r5 = 0 | 0XB4;
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
    // ori         $a3, $zero, 0x7D00
    ctx->r7 = 0 | 0X7D00;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // subu        $s0, $v0, $v1
    ctx->r16 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // jal         0x8002EA88
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    TriggerLightFlash(rdram, ctx);
    goto after_84;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_84:
    // j           L_800478BC
    // nop

    goto L_800478BC;
    // nop

L_8004649C:
    // ori         $a0, $zero, 0x3800
    ctx->r4 = 0 | 0X3800;
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    // ori         $a3, $zero, 0x400
    ctx->r7 = 0 | 0X400;
    // lh          $a1, 0x40($s2)
    ctx->r5 = MEM_H(0X40, ctx->r18);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // jal         0x800446E0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800446E0(rdram, ctx);
    goto after_85;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_85:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_86;
    // nop

    after_86:
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // jal         0x80062BF0
    // sh          $v0, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_87;
    // sh          $v0, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r2;
    after_87:
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // jal         0x80062BF0
    // sh          $v0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_88;
    // sh          $v0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r2;
    after_88:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x65
    ctx->r6 = 0 | 0X65;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sh          $v0, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x90
    ctx->r2 = ADD32(ctx->r29, 0X90);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC00
    ctx->r2 = 0 | 0XC00;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // jal         0x80042D2C
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_89;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_89:
    // j           L_800478A8
    // nop

    goto L_800478A8;
    // nop

L_8004653C:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0x1000
    ctx->r4 = 0 | 0X1000;
    // ori         $a1, $zero, 0x400
    ctx->r5 = 0 | 0X400;
    // j           L_80046568
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    goto L_80046568;
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
L_80046554:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0x1000
    ctx->r4 = 0 | 0X1000;
    // ori         $a1, $zero, 0x800
    ctx->r5 = 0 | 0X800;
    // ori         $a2, $zero, 0x100
    ctx->r6 = 0 | 0X100;
L_80046568:
    // jal         0x800446E0
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    sub_800446E0(rdram, ctx);
    goto after_90;
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    after_90:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80046578:
    // j           L_80046584
    // ori         $s0, $zero, 0x33
    ctx->r16 = 0 | 0X33;
    goto L_80046584;
    // ori         $s0, $zero, 0x33
    ctx->r16 = 0 | 0X33;
L_80046580:
    // ori         $s0, $zero, 0x34
    ctx->r16 = 0 | 0X34;
L_80046584:
    // ori         $a0, $zero, 0x8C
    ctx->r4 = 0 | 0X8C;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    sub_80044C74(rdram, ctx);
    goto after_91;
    // addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    after_91:
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_800485E4;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_92;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_92:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800465BC:
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // lhu         $v1, 0x42($s2)
    ctx->r3 = MEM_HU(0X42, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    // lh          $v1, 0x2C($s2)
    ctx->r3 = MEM_H(0X2C, ctx->r18);
    // nop

    // slti        $v1, $v1, 0x300
    ctx->r3 = SIGNED(ctx->r3) < 0X300 ? 1 : 0;
    // bne         $v1, $zero, L_80046638
    if (ctx->r3 != 0) {
        // sh          $v0, 0x30($s2)
        MEM_H(0X30, ctx->r18) = ctx->r2;
        goto L_80046638;
    }
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // nop

    // sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // addiu       $v0, $v0, 0x3E8
    ctx->r2 = ADD32(ctx->r2, 0X3E8);
    // sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // ori         $a3, $zero, 0x7D0
    ctx->r7 = 0 | 0X7D0;
    // sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // lh          $a2, 0x2C($s2)
    ctx->r6 = MEM_H(0X2C, ctx->r18);
    // lh          $a1, 0x42($s2)
    ctx->r5 = MEM_H(0X42, ctx->r18);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lh          $v0, 0x44($s2)
    ctx->r2 = MEM_H(0X44, ctx->r18);
    // subu        $a1, $a2, $a1
    ctx->r5 = SUB32(ctx->r6, ctx->r5);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) << 2;
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // jal         0x80042938
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80042938(rdram, ctx);
    goto after_93;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_93:
L_80046638:
    // lh          $v1, 0x2C($s2)
    ctx->r3 = MEM_H(0X2C, ctx->r18);
    // lh          $v0, 0x40($s2)
    ctx->r2 = MEM_H(0X40, ctx->r18);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80048468
    // nop

    goto L_80048468;
    // nop

L_80046658:
    // ori         $a0, $zero, 0x4000
    ctx->r4 = 0 | 0X4000;
    // ori         $a1, $zero, 0x100
    ctx->r5 = 0 | 0X100;
    // j           L_80047898
    // ori         $a2, $zero, 0x20
    ctx->r6 = 0 | 0X20;
    goto L_80047898;
    // ori         $a2, $zero, 0x20
    ctx->r6 = 0 | 0X20;
L_80046668:
    // ori         $v0, $zero, 0x65
    ctx->r2 = 0 | 0X65;
    // beq         $s1, $v0, L_800478BC
    if (ctx->r17 == ctx->r2) {
        // slti        $v0, $s1, 0x66
        ctx->r2 = SIGNED(ctx->r17) < 0X66 ? 1 : 0;
        goto L_800478BC;
    }
    // slti        $v0, $s1, 0x66
    ctx->r2 = SIGNED(ctx->r17) < 0X66 ? 1 : 0;
    // beq         $v0, $zero, L_8004668C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x64
        ctx->r2 = 0 | 0X64;
        goto L_8004668C;
    }
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // beq         $s1, $v0, L_80046724
    if (ctx->r17 == ctx->r2) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_80046724;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // j           L_800466B0
    // nop

    goto L_800466B0;
    // nop

L_8004668C:
    // ori         $v0, $zero, 0x66
    ctx->r2 = 0 | 0X66;
    // beq         $s1, $v0, L_8004674C
    if (ctx->r17 == ctx->r2) {
        // ori         $v0, $zero, 0x6E
        ctx->r2 = 0 | 0X6E;
        goto L_8004674C;
    }
    // ori         $v0, $zero, 0x6E
    ctx->r2 = 0 | 0X6E;
    // bne         $s1, $v0, L_800466B0
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_800466B0;
    }
    // nop

L_800466A0:
    // ori         $a0, $zero, 0x3800
    ctx->r4 = 0 | 0X3800;
    // ori         $a1, $zero, 0x31F
    ctx->r5 = 0 | 0X31F;
    // j           L_80047898
    // ori         $a2, $zero, 0x46
    ctx->r6 = 0 | 0X46;
    goto L_80047898;
    // ori         $a2, $zero, 0x46
    ctx->r6 = 0 | 0X46;
L_800466B0:
    // lbu         $v0, 0x7($s2)
    ctx->r2 = MEM_BU(0X7, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800466D0
    if (ctx->r2 != 0) {
        // ori         $a3, $zero, 0xA0
        ctx->r7 = 0 | 0XA0;
        goto L_800466D0;
    }
    // ori         $a3, $zero, 0xA0
    ctx->r7 = 0 | 0XA0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x29
    ctx->r5 = 0 | 0X29;
    PlayEntitySound(rdram, ctx);
    goto after_94;
    // ori         $a1, $zero, 0x29
    ctx->r5 = 0 | 0X29;
    after_94:
    // ori         $a3, $zero, 0xA0
    ctx->r7 = 0 | 0XA0;
L_800466D0:
    // lbu         $v0, 0x7($s2)
    ctx->r2 = MEM_BU(0X7, ctx->r18);
    // lh          $a0, 0x40($s2)
    ctx->r4 = MEM_H(0X40, ctx->r18);
    // lh          $a1, 0x42($s2)
    ctx->r5 = MEM_H(0X42, ctx->r18);
    // lh          $a2, 0x44($s2)
    ctx->r6 = MEM_H(0X44, ctx->r18);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x1770
    ctx->r2 = 0 | 0X1770;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v1, 0x46($s2)
    ctx->r3 = MEM_H(0X46, ctx->r18);
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x8004435C
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    sub_8004435C(rdram, ctx);
    goto after_95;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_95:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80046778
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80046778;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    PlayEntitySound(rdram, ctx);
    goto after_96;
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    after_96:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_80046724:
    // ori         $a2, $zero, 0xC
    ctx->r6 = 0 | 0XC;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $s2, 0x24
    ctx->r2 = ADD32(ctx->r18, 0X24);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_97;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_97:
    // ori         $v1, $zero, 0x65
    ctx->r3 = 0 | 0X65;
    // sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
L_8004674C:
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // ori         $v1, $zero, 0x6E
    ctx->r3 = 0 | 0X6E;
    // sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
    // sh          $zero, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = 0;
    // sh          $zero, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = 0;
    // sb          $v1, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r3;
    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // j           L_800466A0
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    goto L_800466A0;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80046778:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // jal         0x80044814
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    sub_80044814(rdram, ctx);
    goto after_98;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    after_98:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    // lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(0X28, ctx->r4);
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // j           L_80047424
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    goto L_80047424;
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
L_800467BC:
    // slti        $v0, $s1, 0x64
    ctx->r2 = SIGNED(ctx->r17) < 0X64 ? 1 : 0;
    // beq         $v0, $zero, L_8004684C
    if (ctx->r2 == 0) {
        // addiu       $v0, $s1, -0x4
        ctx->r2 = ADD32(ctx->r17, -0X4);
        goto L_8004684C;
    }
    // addiu       $v0, $s1, -0x4
    ctx->r2 = ADD32(ctx->r17, -0X4);
    // sltiu       $v0, $v0, 0x43
    ctx->r2 = ctx->r2 < 0X43 ? 1 : 0;
    // bne         $v0, $zero, L_80046814
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x258
        ctx->r4 = 0 | 0X258;
        goto L_80046814;
    }
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
    // ori         $a0, $zero, 0x64
    ctx->r4 = 0 | 0X64;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // jal         0x80044C74
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    sub_80044C74(rdram, ctx);
    goto after_99;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    after_99:
    // bne         $v0, $zero, L_80046850
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_80046850;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // jal         0x80044814
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    sub_80044814(rdram, ctx);
    goto after_100;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    after_100:
    // j           L_800478BC
    // nop

    goto L_800478BC;
    // nop

L_80046814:
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // ori         $a3, $zero, 0x64
    ctx->r7 = 0 | 0X64;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x168
    ctx->r2 = 0 | 0X168;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8004435C
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8004435C(rdram, ctx);
    goto after_101;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_101:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80046884
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80046884;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
L_8004684C:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_80046850:
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $sp, 0xA0
    ctx->r2 = ADD32(ctx->r29, 0XA0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_102;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_102:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    PlayEntitySound(rdram, ctx);
    goto after_103;
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    after_103:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_800478BC
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    goto L_800478BC;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80046884:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // jal         0x80044814
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    sub_80044814(rdram, ctx);
    goto after_104;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    after_104:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    // lhu         $v0, 0x28($s2)
    ctx->r2 = MEM_HU(0X28, ctx->r18);
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x96
    ctx->r2 = ADD32(0, -0X96);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x8004489C
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8004489C(rdram, ctx);
    goto after_105;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_105:
    // j           L_800478BC
    // nop

    goto L_800478BC;
    // nop

L_800468D8:
    // beq         $s1, $zero, L_800468F0
    if (ctx->r17 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800468F0;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s1, $v0, L_800469D8
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_800469D8;
    }
    // nop

    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800468F0:
    // lbu         $v1, 0x41($s2)
    ctx->r3 = MEM_BU(0X41, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80046914
    if (ctx->r3 != ctx->r2) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_80046914;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80046900:
    // ori         $s0, $zero, 0x10
    ctx->r16 = 0 | 0X10;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80046968
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_80046968;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80046914:
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(0X1, ctx->r17);
    // lbu         $a1, 0xC($s1)
    ctx->r5 = MEM_BU(0XC, ctx->r17);
    // jal         0x8003706C
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    sub_8003706C(rdram, ctx);
    goto after_106;
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_106:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80046900
    if (ctx->r16 == 0) {
        // slti        $v0, $s0, 0x21
        ctx->r2 = SIGNED(ctx->r16) < 0X21 ? 1 : 0;
        goto L_80046900;
    }
    // slti        $v0, $s0, 0x21
    ctx->r2 = SIGNED(ctx->r16) < 0X21 ? 1 : 0;
    // bne         $v0, $zero, L_80046964
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 12
        ctx->r2 = S32(ctx->r16) << 12;
        goto L_80046964;
    }
    // sll         $v0, $s0, 12
    ctx->r2 = S32(ctx->r16) << 12;
    // bgez        $v0, L_8004695C
    if (SIGNED(ctx->r2) >= 0) {
        // ori         $s0, $zero, 0x20
        ctx->r16 = 0 | 0X20;
        goto L_8004695C;
    }
    // ori         $s0, $zero, 0x20
    ctx->r16 = 0 | 0X20;
    // addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
L_8004695C:
    // j           L_80046968
    // sra         $s1, $v0, 5
    ctx->r17 = S32(ctx->r2) >> 5;
    goto L_80046968;
    // sra         $s1, $v0, 5
    ctx->r17 = S32(ctx->r2) >> 5;
L_80046964:
    // ori         $s1, $zero, 0x1000
    ctx->r17 = 0 | 0X1000;
L_80046968:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sh          $v0, 0x42($s2)
    MEM_H(0X42, ctx->r18) = ctx->r2;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_800469CC
    if (ctx->r16 == ctx->r2) {
        // addiu       $s4, $s2, 0x34
        ctx->r20 = ADD32(ctx->r18, 0X34);
        goto L_800469CC;
    }
    // addiu       $s4, $s2, 0x34
    ctx->r20 = ADD32(ctx->r18, 0X34);
    // addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_8004698C:
    // ori         $a2, $zero, 0x69
    ctx->r6 = 0 | 0X69;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // sra         $v1, $s3, 12
    ctx->r3 = S32(ctx->r19) >> 12;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x1188($v0)
    ctx->r2 = MEM_W(0X1188, ctx->r2);
    // addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x41($s2)
    ctx->r2 = MEM_BU(0X41, ctx->r18);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // jal         0x80042D2C
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_107;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_107:
    // bne         $s0, $s5, L_8004698C
    if (ctx->r16 != ctx->r21) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_8004698C;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_800469CC:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_800485E4
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_800469D8:
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_800469FC
    if (ctx->r2 != 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_800469FC;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lh          $v0, 0x42($s2)
    ctx->r2 = MEM_H(0X42, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800485E4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800485E4;
    }
    // nop

L_800469FC:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x1280
    ctx->r5 = ADD32(ctx->r5, -0X1280);
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
    // ori         $t4, $zero, 0xFF
    ctx->r12 = 0 | 0XFF;
    // ori         $t3, $zero, 0x69
    ctx->r11 = 0 | 0X69;
    // addiu       $t2, $a1, 0x2408
    ctx->r10 = ADD32(ctx->r5, 0X2408);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // ori         $t1, $zero, 0x2
    ctx->r9 = 0 | 0X2;
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // addiu       $a0, $a1, 0x7
    ctx->r4 = ADD32(ctx->r5, 0X7);
L_80046A24:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // beq         $v0, $t4, L_80046A78
    if (ctx->r2 == ctx->r12) {
        // nop
    
        goto L_80046A78;
    }
    // nop

    // lbu         $v0, -0x6($a0)
    ctx->r2 = MEM_BU(-0X6, ctx->r4);
    // nop

    // bne         $v0, $t3, L_80046A78
    if (ctx->r2 != ctx->r11) {
        // nop
    
        goto L_80046A78;
    }
    // nop

    // lbu         $v1, 0x39($a0)
    ctx->r3 = MEM_BU(0X39, ctx->r4);
    // lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(0X0, ctx->r10);
    // nop

    // bne         $v1, $v0, L_80046A78
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80046A78;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // bne         $v0, $a3, L_80046A74
    if (ctx->r2 != ctx->r7) {
        // nop
    
        goto L_80046A74;
    }
    // nop

    // sh          $a3, 0x7($a0)
    MEM_H(0X7, ctx->r4) = ctx->r7;
    // j           L_80046A78
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    goto L_80046A78;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80046A74:
    // sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
L_80046A78:
    // addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t0, L_80046A24
    if (ctx->r6 != ctx->r8) {
        // addiu       $a1, $a1, 0x48
        ctx->r5 = ADD32(ctx->r5, 0X48);
        goto L_80046A24;
    }
    // addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    // lbu         $v1, 0x41($s2)
    ctx->r3 = MEM_BU(0X41, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80048464
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_80048464;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // lbu         $a0, 0x40($s2)
    ctx->r4 = MEM_BU(0X40, ctx->r18);
    // nop

    // beq         $a0, $zero, L_80048464
    if (ctx->r4 == 0) {
        // addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
        goto L_80048464;
    }
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800427C8
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_800427C8(rdram, ctx);
    goto after_108;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_108:
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // lbu         $a0, 0x41($s2)
    ctx->r4 = MEM_BU(0X41, ctx->r18);
    // lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(0X6, ctx->r16);
    // lhu         $a3, 0x8($s0)
    ctx->r7 = MEM_HU(0X8, ctx->r16);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(0XC, ctx->r16);
    // nop

    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // lhu         $v1, 0xE($s0)
    ctx->r3 = MEM_HU(0XE, ctx->r16);
    // nop

    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(0X10, ctx->r16);
    // nop

    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x12($s0)
    ctx->r3 = MEM_HU(0X12, ctx->r16);
    // nop

    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(0X14, ctx->r16);
    // nop

    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // lbu         $a1, 0x40($s2)
    ctx->r5 = MEM_BU(0X40, ctx->r18);
    // sll         $v1, $s3, 12
    ctx->r3 = S32(ctx->r19) << 12;
    // div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_80046B28
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80046B28;
    }
    // nop

    // break       7
    do_break(2147773220);
L_80046B28:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_80046B40
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80046B40;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80046B40
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80046B40;
    }
    // nop

    // break       6
    do_break(2147773244);
L_80046B40:
    // mflo        $v1
    ctx->r3 = lo;
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // addiu       $v1, $s1, 0x2C
    ctx->r3 = ADD32(ctx->r17, 0X2C);
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // jal         0x8003C718
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    ApplyDamage(rdram, ctx);
    goto after_109;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_109:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80046B74:
    // lhu         $v0, 0x28($s2)
    ctx->r2 = MEM_HU(0X28, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x320
    ctx->r2 = ADD32(ctx->r2, 0X320);
    // sh          $v0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $s1, $v0, L_80046C10
    if (ctx->r17 == ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80046C10;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v1, 0x41($s2)
    ctx->r3 = MEM_BU(0X41, ctx->r18);
    // nop

    // beq         $v1, $v0, L_80046C2C
    if (ctx->r3 == ctx->r2) {
        // sll         $s0, $v1, 5
        ctx->r16 = S32(ctx->r3) << 5;
        goto L_80046C2C;
    }
    // sll         $s0, $v1, 5
    ctx->r16 = S32(ctx->r3) << 5;
    // subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, -0x19F8
    ctx->r2 = ADD32(ctx->r2, -0X19F8);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lh          $a1, 0x42($s2)
    ctx->r5 = MEM_H(0X42, ctx->r18);
    // jal         0x8003EAC0
    // addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    sub_8003EAC0(rdram, ctx);
    goto after_110;
    // addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    after_110:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003EBC0
    // addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    sub_8003EBC0(rdram, ctx);
    goto after_111;
    // addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_111:
    // lw          $v1, 0xB0($sp)
    ctx->r3 = MEM_W(0XB0, ctx->r29);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r3;
    // lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(0XB4, ctx->r29);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r3;
    // lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(0XB8, ctx->r29);
    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_80046C58
    // sw          $v1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r3;
    goto L_80046C58;
    // sw          $v1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r3;
L_80046C10:
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // lhu         $v1, 0x36($s2)
    ctx->r3 = MEM_HU(0X36, ctx->r18);
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // sh          $v1, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r3;
L_80046C2C:
    // ori         $a0, $zero, 0x64
    ctx->r4 = 0 | 0X64;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_112;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_112:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800485E4
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0xF
        ctx->r2 = ctx->r16 & 0XF;
        goto L_800485E4;
    }
    // andi        $v0, $s0, 0xF
    ctx->r2 = ctx->r16 & 0XF;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80048468
    // nop

    goto L_80048468;
    // nop

L_80046C58:
    // beq         $s1, $zero, L_80046C70
    if (ctx->r17 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80046C70;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s1, $v0, L_80046D48
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_80046D48;
    }
    // nop

    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80046C70:
    // addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // ori         $a1, $zero, 0x12C
    ctx->r5 = 0 | 0X12C;
    // ori         $a2, $zero, 0x32
    ctx->r6 = 0 | 0X32;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    // ori         $v0, $zero, 0x96
    ctx->r2 = 0 | 0X96;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80044520
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_80044520(rdram, ctx);
    goto after_113;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_113:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // bne         $s0, $v0, L_80046CEC
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80046CEC;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1280
    ctx->r3 = ADD32(ctx->r3, -0X1280);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x42($a0)
    ctx->r2 = MEM_H(0X42, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80046CE0
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80046CE0;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r2;
L_80046CE0:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80046D48
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    goto L_80046D48;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80046CEC:
    // bne         $s0, $v0, L_800485E4
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A6C($v0)
    ctx->r2 = MEM_W(-0X2A6C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1280
    ctx->r3 = ADD32(ctx->r3, -0X1280);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x42($a0)
    ctx->r2 = MEM_H(0X42, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80048464
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80048464;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_80048464
    // sh          $v0, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r2;
    goto L_80048464;
    // sh          $v0, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r2;
L_80046D48:
    // lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(0XA0, ctx->r29);
    // lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(0XA4, ctx->r29);
    // lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(0XA8, ctx->r29);
    // lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(0XAC, ctx->r29);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // sw          $a0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r4;
    // sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // jal         0x80062BF0
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_114;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    after_114:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(0XB0, ctx->r29);
    // nop

    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    // lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(0XB4, ctx->r29);
    // nop

    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(0XB8, ctx->r29);
    // nop

    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // j           L_800485E4
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
L_80046DC4:
    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_80046E10
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80046E10;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // ori         $a1, $zero, 0x190
    ctx->r5 = 0 | 0X190;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    // sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // ori         $a3, $zero, 0xBB8
    ctx->r7 = 0 | 0XBB8;
    // sw          $v1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // j           L_80046E60
    // sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    goto L_80046E60;
    // sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
L_80046E10:
    // beq         $v1, $v0, L_80046F28
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $sp, 0xD0
        ctx->r4 = ADD32(ctx->r29, 0XD0);
        goto L_80046F28;
    }
    // addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // ori         $a1, $zero, 0x258
    ctx->r5 = 0 | 0X258;
    // sll         $a3, $v1, 5
    ctx->r7 = S32(ctx->r3) << 5;
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7) << 2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, -0x19F8
    ctx->r2 = ADD32(ctx->r2, -0X19F8);
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(0X2C, ctx->r7);
    // ori         $a2, $zero, 0x32
    ctx->r6 = 0 | 0X32;
    // sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1E($a3)
    ctx->r2 = MEM_HU(0X1E, ctx->r7);
    // lw          $v1, 0x30($a3)
    ctx->r3 = MEM_W(0X30, ctx->r7);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    // lw          $v0, 0x34($a3)
    ctx->r2 = MEM_W(0X34, ctx->r7);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
L_80046E60:
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80044520
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80044520(rdram, ctx);
    goto after_115;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_115:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80046F4C
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80046F4C;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80046E88:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A6C($a0)
    ctx->r4 = MEM_W(-0X2A6C, ctx->r4);
    // ori         $s0, $zero, 0xB
    ctx->r16 = 0 | 0XB;
    // addiu       $s4, $zero, -0x5A
    ctx->r20 = ADD32(0, -0X5A);
    // ori         $s3, $zero, 0x200
    ctx->r19 = 0 | 0X200;
    // jal         0x800428D0
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    sub_800428D0(rdram, ctx);
    goto after_116;
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    after_116:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80046EA8:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // jal         0x8004489C
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    sub_8004489C(rdram, ctx);
    goto after_117;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    after_117:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80046EA8
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80046EA8;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    // ori         $a3, $zero, 0x2000
    ctx->r7 = 0 | 0X2000;
    // ori         $v0, $zero, 0x4000
    ctx->r2 = 0 | 0X4000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // jal         0x80044B20
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80044B20(rdram, ctx);
    goto after_118;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_118:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80046F28:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // jal         0x80044C74
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    sub_80044C74(rdram, ctx);
    goto after_119;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    after_119:
    // bne         $v0, $zero, L_80046E88
    if (ctx->r2 != 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80046E88;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80046F4C:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
    // ori         $a3, $zero, 0xED8
    ctx->r7 = 0 | 0XED8;
    // addiu       $v0, $zero, -0x50
    ctx->r2 = ADD32(0, -0X50);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // j           L_800471C0
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    goto L_800471C0;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
L_80046F78:
    // j           L_80046F84
    // ori         $s4, $zero, 0x1DB0
    ctx->r20 = 0 | 0X1DB0;
    goto L_80046F84;
    // ori         $s4, $zero, 0x1DB0
    ctx->r20 = 0 | 0X1DB0;
L_80046F80:
    // ori         $s4, $zero, 0xED8
    ctx->r20 = 0 | 0XED8;
L_80046F84:
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // ori         $a1, $zero, 0x190
    ctx->r5 = 0 | 0X190;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // ori         $a3, $zero, 0xBB8
    ctx->r7 = 0 | 0XBB8;
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80044520
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_80044520(rdram, ctx);
    goto after_120;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_120:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // jal         0x80044814
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    sub_80044814(rdram, ctx);
    goto after_121;
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    after_121:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80047074
    if (ctx->r16 != ctx->r2) {
        // lui         $v0, 0x2AAA
        ctx->r2 = S32(0X2AAA << 16);
        goto L_80047074;
    }
    // lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A6C($a0)
    ctx->r4 = MEM_W(-0X2A6C, ctx->r4);
    // ori         $s0, $zero, 0xB
    ctx->r16 = 0 | 0XB;
    // addiu       $s5, $zero, -0x5A
    ctx->r21 = ADD32(0, -0X5A);
    // ori         $s3, $zero, 0x200
    ctx->r19 = 0 | 0X200;
    // jal         0x800428D0
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    sub_800428D0(rdram, ctx);
    goto after_122;
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    after_122:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80047014:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // jal         0x8004489C
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    sub_8004489C(rdram, ctx);
    goto after_123;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    after_123:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80047014
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80047014;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
L_80047074:
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // negu        $v1, $s4
    ctx->r3 = SUB32(0, ctx->r20);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x8004489C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8004489C(rdram, ctx);
    goto after_124;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_124:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800470CC:
    // beq         $s1, $zero, L_800470E4
    if (ctx->r17 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800470E4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s1, $v0, L_800471D4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_800471D4;
    }
    // nop

    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800470E4:
    // ori         $a0, $zero, 0x8C
    ctx->r4 = 0 | 0X8C;
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // jal         0x80044C74
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    sub_80044C74(rdram, ctx);
    goto after_125;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    after_125:
    // beq         $v0, $zero, L_80047194
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_80047194;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, -0x190
    ctx->r6 = ADD32(0, -0X190);
    // ori         $a3, $zero, 0x3C
    ctx->r7 = 0 | 0X3C;
    // lh          $v1, 0x34($s2)
    ctx->r3 = MEM_H(0X34, ctx->r18);
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // lh          $t0, 0x36($s2)
    ctx->r8 = MEM_H(0X36, ctx->r18);
    // lh          $t1, 0x38($s2)
    ctx->r9 = MEM_H(0X38, ctx->r18);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // subu        $v1, $v1, $t1
    ctx->r3 = SUB32(ctx->r3, ctx->r9);
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // jal         0x80044EC0
    // sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    sub_80044EC0(rdram, ctx);
    goto after_126;
    // sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    after_126:
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // ori         $a1, $zero, 0x3C
    ctx->r5 = 0 | 0X3C;
    // addiu       $a2, $zero, -0x14A
    ctx->r6 = ADD32(0, -0X14A);
    // jal         0x80044EC0
    // ori         $a3, $zero, 0x38
    ctx->r7 = 0 | 0X38;
    sub_80044EC0(rdram, ctx);
    goto after_127;
    // ori         $a3, $zero, 0x38
    ctx->r7 = 0 | 0X38;
    after_127:
    // ori         $a0, $zero, 0x8
    ctx->r4 = 0 | 0X8;
    // ori         $a1, $zero, 0x8C
    ctx->r5 = 0 | 0X8C;
    // addiu       $a2, $zero, -0xAA
    ctx->r6 = ADD32(0, -0XAA);
    // jal         0x80044EC0
    // ori         $a3, $zero, 0x28
    ctx->r7 = 0 | 0X28;
    sub_80044EC0(rdram, ctx);
    goto after_128;
    // ori         $a3, $zero, 0x28
    ctx->r7 = 0 | 0X28;
    after_128:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x25
    ctx->r5 = 0 | 0X25;
    PlayEntitySound(rdram, ctx);
    goto after_129;
    // ori         $a1, $zero, 0x25
    ctx->r5 = 0 | 0X25;
    after_129:
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // j           L_800485E4
    // sb          $zero, 0x8($s2)
    MEM_B(0X8, ctx->r18) = 0;
    goto L_800485E4;
    // sb          $zero, 0x8($s2)
    MEM_B(0X8, ctx->r18) = 0;
L_80047194:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
    // ori         $a3, $zero, 0x1770
    ctx->r7 = 0 | 0X1770;
    // addiu       $v0, $zero, -0x320
    ctx->r2 = ADD32(0, -0X320);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x400
    ctx->r2 = ADD32(0, -0X400);
L_800471C0:
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // jal         0x8004489C
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004489C(rdram, ctx);
    goto after_130;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_130:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800471D4:
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800485E4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800485E4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80048468
    // nop

    goto L_80048468;
    // nop

L_800471EC:
    // beq         $s1, $zero, L_80047204
    if (ctx->r17 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80047204;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s1, $v0, L_80047438
    if (ctx->r17 == ctx->r2) {
        // addiu       $a1, $sp, 0xF0
        ctx->r5 = ADD32(ctx->r29, 0XF0);
        goto L_80047438;
    }
    // addiu       $a1, $sp, 0xF0
    ctx->r5 = ADD32(ctx->r29, 0XF0);
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80047204:
    // addiu       $s1, $sp, 0xE0
    ctx->r17 = ADD32(ctx->r29, 0XE0);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // lhu         $a1, 0x42($s2)
    ctx->r5 = MEM_HU(0X42, ctx->r18);
    // lh          $v1, 0x34($s2)
    ctx->r3 = MEM_H(0X34, ctx->r18);
    // lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(0X14, ctx->r18);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // sw          $v1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r3;
    // lh          $v0, 0x36($s2)
    ctx->r2 = MEM_H(0X36, ctx->r18);
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // ori         $a1, $zero, 0x8C
    ctx->r5 = 0 | 0X8C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(0X38, ctx->r18);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800424C8
    // sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
    sub_800424C8(rdram, ctx);
    goto after_131;
    // sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
    after_131:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800473B0
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0xF
        ctx->r2 = ctx->r16 & 0XF;
        goto L_800473B0;
    }
    // andi        $v0, $s0, 0xF
    ctx->r2 = ctx->r16 & 0XF;
    // beq         $v0, $zero, L_800473B0
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800473B0;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // ori         $a1, $zero, 0x8C
    ctx->r5 = 0 | 0X8C;
    // sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // jal         0x800424C8
    // sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
    sub_800424C8(rdram, ctx);
    goto after_132;
    // sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
    after_132:
    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // beq         $v0, $zero, L_800473A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800473A8;
    }
    // nop

    // lh          $v0, 0x36($s2)
    ctx->r2 = MEM_H(0X36, ctx->r18);
    // nop

    // bgez        $v0, L_800472B4
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800472B4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // sh          $zero, 0x36($s2)
    MEM_H(0X36, ctx->r18) = 0;
    // j           L_800473B0
    // sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    goto L_800473B0;
    // sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
L_800472B4:
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // ori         $a3, $zero, 0x1F4
    ctx->r7 = 0 | 0X1F4;
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x1280
    ctx->r2 = ADD32(ctx->r2, -0X1280);
    // jal         0x80044814
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    sub_80044814(rdram, ctx);
    goto after_133;
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    after_133:
    // bne         $v0, $zero, L_80047384
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80047384;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lw          $s1, 0x14($s2)
    ctx->r17 = MEM_W(0X14, ctx->r18);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    // lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(0X14, ctx->r19);
    // lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(0X1C, ctx->r19);
    // lw          $s0, 0x1C($s2)
    ctx->r16 = MEM_W(0X1C, ctx->r18);
    // sh          $zero, 0x28($s2)
    MEM_H(0X28, ctx->r18) = 0;
    // subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // jal         0x80015804
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_134;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_134:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80015954
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    CalculateDistance(rdram, ctx);
    goto after_135;
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    after_135:
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
    // sh          $zero, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = 0;
    // jal         0x80062BF0
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_136;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    after_136:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sra         $v1, $v1, 15
    ctx->r3 = S32(ctx->r3) >> 15;
    // addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // sh          $v1, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r3;
    // j           L_800485E4
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80047384:
    // lbu         $v0, 0x40($s3)
    ctx->r2 = MEM_BU(0X40, ctx->r19);
    // nop

    // beq         $v0, $zero, L_80048468
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80048468;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v0, 0x40($s3)
    ctx->r2 = MEM_BU(0X40, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80048464
    // sb          $v0, 0x40($s3)
    MEM_B(0X40, ctx->r19) = ctx->r2;
    goto L_80048464;
    // sb          $v0, 0x40($s3)
    MEM_B(0X40, ctx->r19) = ctx->r2;
L_800473A8:
    // sh          $zero, 0x38($s2)
    MEM_H(0X38, ctx->r18) = 0;
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
L_800473B0:
    // lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(0XE0, ctx->r29);
    // nop

    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lw          $v0, 0xE4($sp)
    ctx->r2 = MEM_W(0XE4, ctx->r29);
    // nop

    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(0XE8, ctx->r29);
    // nop

    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x2A82($v0)
    ctx->r2 = MEM_HU(-0X2A82, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800473EC
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x2
        ctx->r3 = 0 | 0X2;
        goto L_800473EC;
    }
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
L_800473EC:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    // lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(0X28, ctx->r4);
    // ori         $a3, $zero, 0x1000
    ctx->r7 = 0 | 0X1000;
    // sb          $v1, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r3;
    // addiu       $v0, $v0, 0x12C
    ctx->r2 = ADD32(ctx->r2, 0X12C);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, -0x1F4
    ctx->r2 = ADD32(0, -0X1F4);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
L_80047424:
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x8004489C
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8004489C(rdram, ctx);
    goto after_137;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_137:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80047438:
    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // lh          $a0, 0x34($s2)
    ctx->r4 = MEM_H(0X34, ctx->r18);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1280
    ctx->r3 = ADD32(ctx->r3, -0X1280);
    // jal         0x80014FAC
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    sub_80014FAC(rdram, ctx);
    goto after_138;
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    after_138:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_H(0X38, ctx->r18);
    // lw          $v0, 0xF0($sp)
    ctx->r2 = MEM_W(0XF0, ctx->r29);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(0X14, ctx->r19);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_H(0X38, ctx->r18);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lw          $v0, 0xF4($sp)
    ctx->r2 = MEM_W(0XF4, ctx->r29);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lh          $a0, 0x36($s2)
    ctx->r4 = MEM_H(0X36, ctx->r18);
    // lh          $a2, 0x30($s2)
    ctx->r6 = MEM_H(0X30, ctx->r18);
    // lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(0X1C, ctx->r19);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80015D18
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    FixedPointLerp(rdram, ctx);
    goto after_139;
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    after_139:
    // lhu         $a0, 0x30($s2)
    ctx->r4 = MEM_HU(0X30, ctx->r18);
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x800601F4
    // sra         $a0, $a0, 17
    ctx->r4 = S32(ctx->r4) >> 17;
    FixedSin(rdram, ctx);
    goto after_140;
    // sra         $a0, $a0, 17
    ctx->r4 = S32(ctx->r4) >> 17;
    after_140:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // srl         $v1, $v1, 5
    ctx->r3 = S32(U32(ctx->r3) >> 5);
    // sh          $v1, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r3;
    // lh          $v1, 0x32($s2)
    ctx->r3 = MEM_H(0X32, ctx->r18);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80047548
    if (ctx->r2 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_80047548;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // lh          $v1, 0x2E($s2)
    ctx->r3 = MEM_H(0X2E, ctx->r18);
    // addiu       $v0, $a0, 0x800
    ctx->r2 = ADD32(ctx->r4, 0X800);
    // sh          $v0, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x90
    ctx->r2 = 0 | 0X90;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    sub_8002E4F4(rdram, ctx);
    goto after_141;
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    after_141:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80047548
    if (ctx->r16 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80047548;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x1388
    ctx->r5 = 0 | 0X1388;
    // jal         0x800427EC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_800427EC(rdram, ctx);
    goto after_142;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_142:
L_80047548:
    // lh          $v0, 0x30($s2)
    ctx->r2 = MEM_H(0X30, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80047584
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80047584;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x40($s3)
    ctx->r2 = MEM_BU(0X40, ctx->r19);
    // nop

    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // lbu         $v0, 0x40($s3)
    ctx->r2 = MEM_BU(0X40, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_800485E4
    // sb          $v0, 0x40($s3)
    MEM_B(0X40, ctx->r19) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x40($s3)
    MEM_B(0X40, ctx->r19) = ctx->r2;
L_80047584:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_143;
    // nop

    after_143:
    // slti        $v0, $v0, 0x800
    ctx->r2 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800485E4;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // ori         $a3, $zero, 0x1800
    ctx->r7 = 0 | 0X1800;
    // addiu       $v0, $zero, -0x60
    ctx->r2 = ADD32(0, -0X60);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x27
    ctx->r2 = 0 | 0X27;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x11
    ctx->r2 = ADD32(0, -0X11);
    // ori         $t0, $zero, 0x80
    ctx->r8 = 0 | 0X80;
    // addiu       $v1, $zero, -0x40
    ctx->r3 = ADD32(0, -0X40);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // jal         0x8004489C
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    sub_8004489C(rdram, ctx);
    goto after_144;
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_144:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800475F8:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s1, $v0, L_8004788C
    if (ctx->r17 == ctx->r2) {
        // slti        $v0, $s1, 0x2
        ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
        goto L_8004788C;
    }
    // slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8004761C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004761C;
    }
    // nop

    // beq         $s1, $zero, L_80047630
    if (ctx->r17 == 0) {
        // ori         $a0, $zero, 0xFA
        ctx->r4 = 0 | 0XFA;
        goto L_80047630;
    }
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
    // j           L_800478BC
    // nop

    goto L_800478BC;
    // nop

L_8004761C:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // beq         $s1, $v0, L_800476B8
    if (ctx->r17 == ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800476B8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_800478BC
    // nop

    goto L_800478BC;
    // nop

L_80047630:
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // jal         0x80044C74
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80044C74(rdram, ctx);
    goto after_145;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_145:
    // bne         $v0, $zero, L_80047658
    if (ctx->r2 != 0) {
        // addiu       $s0, $s2, 0x14
        ctx->r16 = ADD32(ctx->r18, 0X14);
        goto L_80047658;
    }
    // addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800476F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800476F0;
    }
    // nop

L_80047658:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // ori         $a2, $zero, 0x190
    ctx->r6 = 0 | 0X190;
    // ori         $a3, $zero, 0x2000
    ctx->r7 = 0 | 0X2000;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // jal         0x80044B20
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80044B20(rdram, ctx);
    goto after_146;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_146:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0xA
    ctx->r6 = 0 | 0XA;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $s2, 0x24
    ctx->r2 = ADD32(ctx->r18, 0X24);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_147;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_147:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // jal         0x8004248C
    // sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_148;
    // sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    after_148:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800476B8:
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
    // sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
    // sh          $zero, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = 0;
    // sh          $zero, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = 0;
    // sh          $v1, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r3;
    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // j           L_8004788C
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    goto L_8004788C;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_800476F0:
    // lhu         $v0, 0x12($s2)
    ctx->r2 = MEM_HU(0X12, ctx->r18);
    // lbu         $v1, 0x41($s2)
    ctx->r3 = MEM_BU(0X41, ctx->r18);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // beq         $v1, $zero, L_8004779C
    if (ctx->r3 == 0) {
        // sh          $v0, 0x12($s2)
        MEM_H(0X12, ctx->r18) = ctx->r2;
        goto L_8004779C;
    }
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x108
    ctx->r17 = ADD32(ctx->r29, 0X108);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80042BD4
    // addiu       $a3, $s2, 0x2C
    ctx->r7 = ADD32(ctx->r18, 0X2C);
    sub_80042BD4(rdram, ctx);
    goto after_149;
    // addiu       $a3, $s2, 0x2C
    ctx->r7 = ADD32(ctx->r18, 0X2C);
    after_149:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0xF8
    ctx->r5 = ADD32(ctx->r29, 0XF8);
    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(0X2C, ctx->r7);
    // addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // sw          $v0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1E($a3)
    ctx->r2 = MEM_HU(0X1E, ctx->r7);
    // lw          $v1, 0x30($a3)
    ctx->r3 = MEM_W(0X30, ctx->r7);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r3;
    // lw          $v0, 0x34($a3)
    ctx->r2 = MEM_W(0X34, ctx->r7);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x80014DB0
    // sw          $v0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r2;
    sub_80014DB0(rdram, ctx);
    goto after_150;
    // sw          $v0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r2;
    after_150:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x7
    ctx->r6 = 0 | 0X7;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // jal         0x80042D2C
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    SpawnParticleEntity(rdram, ctx);
    goto after_151;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_151:
    // lbu         $v0, 0x41($s2)
    ctx->r2 = MEM_BU(0X41, ctx->r18);
    // j           L_80047824
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    goto L_80047824;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8004779C:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_152;
    // nop

    after_152:
    // slti        $v0, $v0, 0x800
    ctx->r2 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_80047828
    if (ctx->r2 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_80047828;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $a3, $zero, 0x61A8
    ctx->r7 = 0 | 0X61A8;
    // lh          $a1, 0x26($s2)
    ctx->r5 = MEM_H(0X26, ctx->r18);
    // lh          $a2, 0x24($s2)
    ctx->r6 = MEM_H(0X24, ctx->r18);
    // ori         $v0, $zero, 0x320
    ctx->r2 = 0 | 0X320;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x118
    ctx->r2 = ADD32(ctx->r29, 0X118);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x200
    ctx->r2 = 0 | 0X200;
    // jal         0x8003D200
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D200(rdram, ctx);
    goto after_153;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_153:
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // beq         $a3, $zero, L_80047828
    if (ctx->r7 == 0) {
        // nop
    
        goto L_80047828;
    }
    // nop

    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, -0x19F8
    ctx->r4 = ADD32(ctx->r4, -0X19F8);
    // subu        $a0, $a3, $a0
    ctx->r4 = SUB32(ctx->r7, ctx->r4);
    // sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4) << 5;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v1, $v0, 15
    ctx->r3 = S32(ctx->r2) << 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_80047824:
    // sb          $v0, 0x41($s2)
    MEM_B(0X41, ctx->r18) = ctx->r2;
L_80047828:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_154;
    // nop

    after_154:
    // slti        $v0, $v0, 0x400
    ctx->r2 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // addiu       $a0, $s2, 0x14
        ctx->r4 = ADD32(ctx->r18, 0X14);
        goto L_800485E4;
    }
    // addiu       $a0, $s2, 0x14
    ctx->r4 = ADD32(ctx->r18, 0X14);
    // ori         $a3, $zero, 0x7530
    ctx->r7 = 0 | 0X7530;
    // lh          $a1, 0x26($s2)
    ctx->r5 = MEM_H(0X26, ctx->r18);
    // lh          $a2, 0x24($s2)
    ctx->r6 = MEM_H(0X24, ctx->r18);
    // ori         $v0, $zero, 0x320
    ctx->r2 = 0 | 0X320;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x118
    ctx->r2 = ADD32(ctx->r29, 0X118);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x200
    ctx->r2 = 0 | 0X200;
    // jal         0x8003D200
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D200(rdram, ctx);
    goto after_155;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_155:
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800485E4;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80044784
    // ori         $a1, $zero, 0x2F
    ctx->r5 = 0 | 0X2F;
    sub_80044784(rdram, ctx);
    goto after_156;
    // ori         $a1, $zero, 0x2F
    ctx->r5 = 0 | 0X2F;
    after_156:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80044784
    // ori         $a1, $zero, 0x32
    ctx->r5 = 0 | 0X32;
    sub_80044784(rdram, ctx);
    goto after_157;
    // ori         $a1, $zero, 0x32
    ctx->r5 = 0 | 0X32;
    after_157:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_8004788C:
    // ori         $a0, $zero, 0x4000
    ctx->r4 = 0 | 0X4000;
    // ori         $a1, $zero, 0x800
    ctx->r5 = 0 | 0X800;
    // ori         $a2, $zero, 0x4B
    ctx->r6 = 0 | 0X4B;
L_80047898:
    // ori         $a3, $zero, 0x400
    ctx->r7 = 0 | 0X400;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // jal         0x800446E0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800446E0(rdram, ctx);
    goto after_158;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_158:
L_800478A8:
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // j           L_800485E4
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_800478BC:
    // lbu         $v0, 0x7($s2)
    ctx->r2 = MEM_BU(0X7, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_800485E4
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_800478D0:
    // sltiu       $v0, $s1, 0x5
    ctx->r2 = ctx->r17 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17) << 2;
        goto L_800485E4;
    }
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x2978
    ctx->r1 = ADD32(ctx->r1, 0X2978);
    // addu        $at, $at, $v0
    gpr jr_addend_800478F0;
    jr_addend_800478F0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800478F0 >> 2) {
        case 0: goto L_800478F8; break;
        case 1: goto L_80047964; break;
        case 2: goto L_80047B30; break;
        case 3: goto L_80047D28; break;
        case 4: goto L_80047D70; break;
        default: switch_error(__func__, 0x800478F0, 0x80012978);
    }
    // nop

L_800478F8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s3, $s2, 0x34
    ctx->r19 = ADD32(ctx->r18, 0X34);
    // addiu       $s1, $s2, 0x24
    ctx->r17 = ADD32(ctx->r18, 0X24);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_80047908:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x6B
    ctx->r6 = 0 | 0X6B;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80042D2C
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    SpawnParticleEntity(rdram, ctx);
    goto after_159;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_159:
    // bne         $s0, $zero, L_80047934
    if (ctx->r16 != 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80047934;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // ori         $v0, $zero, 0x17
    ctx->r2 = 0 | 0X17;
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
L_80047934:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, 0x1188($v0)
    ctx->r2 = MEM_BU(0X1188, ctx->r2);
    // sb          $s0, 0x41($v1)
    MEM_B(0X41, ctx->r3) = ctx->r16;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r2;
    // slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80047908
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_80047908;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80047964:
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_H(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80047994
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xFA
        ctx->r4 = 0 | 0XFA;
        goto L_80047994;
    }
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
L_80047978:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
L_8004797C:
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // j           L_800485E4
    // sb          $v0, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r2;
L_80047994:
    // ori         $a1, $zero, 0x19
    ctx->r5 = 0 | 0X19;
    // ori         $a2, $zero, 0x20
    ctx->r6 = 0 | 0X20;
    // ori         $a3, $zero, 0xC8
    ctx->r7 = 0 | 0XC8;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8004435C
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8004435C(rdram, ctx);
    goto after_160;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_160:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80047A88
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80047A88;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A6C($v1)
    ctx->r3 = MEM_W(-0X2A6C, ctx->r3);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // bne         $v1, $v0, L_8004797C
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8004797C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // ori         $a1, $zero, 0x1388
    ctx->r5 = 0 | 0X1388;
    // jal         0x800427EC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_800427EC(rdram, ctx);
    goto after_161;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_161:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lbu         $v0, -0x2A68($v0)
    ctx->r2 = MEM_BU(-0X2A68, ctx->r2);
    // nop

    // sb          $v0, 0x46($s2)
    MEM_B(0X46, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x46($s2)
    ctx->r3 = MEM_BU(0X46, ctx->r18);
    // nop

    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0xE($s0)
    ctx->r2 = MEM_BU(0XE, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80047978
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80047978;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // sb          $v0, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x16
    ctx->r2 = 0 | 0X16;
    // sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // sb          $zero, 0x45($s2)
    MEM_B(0X45, ctx->r18) = 0;
    // sh          $zero, 0x28($s2)
    MEM_H(0X28, ctx->r18) = 0;
    // sh          $zero, 0x24($s2)
    MEM_H(0X24, ctx->r18) = 0;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(0X34, ctx->r16);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_162;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_162:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80047B30
    // sh          $v0, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r2;
    goto L_80047B30;
    // sh          $v0, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r2;
L_80047A88:
    // lbu         $v0, 0x44($s2)
    ctx->r2 = MEM_BU(0X44, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80047AAC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80047AAC;
    }
    // nop

    // sb          $zero, 0x44($s2)
    MEM_B(0X44, ctx->r18) = 0;
L_80047AAC:
    // lbu         $v1, 0x44($s2)
    ctx->r3 = MEM_BU(0X44, ctx->r18);
    // lbu         $a0, 0x45($s2)
    ctx->r4 = MEM_BU(0X45, ctx->r18);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0x40($s2)
    ctx->r3 = MEM_W(0X40, ctx->r18);
    // sll         $s3, $a0, 4
    ctx->r19 = S32(ctx->r4) << 4;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x45($s2)
    ctx->r2 = MEM_BU(0X45, ctx->r18);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // sb          $v0, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r2;
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x800601F4
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    FixedSin(rdram, ctx);
    goto after_163;
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_163:
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // nop

    // sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x28($s2)
    ctx->r2 = MEM_HU(0X28, ctx->r18);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x800602D0
    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    FixedCos(rdram, ctx);
    goto after_164;
    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    after_164:
    // lhu         $v1, 0x24($s2)
    ctx->r3 = MEM_HU(0X24, ctx->r18);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_800485E4
    // sh          $v1, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r3;
    goto L_800485E4;
    // sh          $v1, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r3;
L_80047B30:
    // lbu         $v1, 0x46($s2)
    ctx->r3 = MEM_BU(0X46, ctx->r18);
    // nop

    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x44($s2)
    ctx->r2 = MEM_BU(0X44, ctx->r18);
    // lhu         $s4, 0x1C($s0)
    ctx->r20 = MEM_HU(0X1C, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80047B84
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80047B84;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sb          $zero, 0x44($s2)
    MEM_B(0X44, ctx->r18) = 0;
L_80047B84:
    // jal         0x8003EBC0
    // addiu       $a1, $sp, 0xF0
    ctx->r5 = ADD32(ctx->r29, 0XF0);
    sub_8003EBC0(rdram, ctx);
    goto after_165;
    // addiu       $a1, $sp, 0xF0
    ctx->r5 = ADD32(ctx->r29, 0XF0);
    after_165:
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(0X8, ctx->r2);
    // lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(0XC, ctx->r2);
    // sw          $v1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r3;
    // sw          $a0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r4;
    // sw          $a1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r5;
    // sw          $a2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r6;
    // lhu         $v1, 0x1E($s0)
    ctx->r3 = MEM_HU(0X1E, ctx->r16);
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // lbu         $a2, 0x45($s2)
    ctx->r6 = MEM_BU(0X45, ctx->r18);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // sltiu       $v0, $a2, 0x11
    ctx->r2 = ctx->r6 < 0X11 ? 1 : 0;
    // bne         $v0, $zero, L_80047BE8
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80047BE8;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sltiu       $v0, $a2, 0x3C
    ctx->r2 = ctx->r6 < 0X3C ? 1 : 0;
    // bne         $v0, $zero, L_80047C30
    if (ctx->r2 != 0) {
        // lui         $a2, 0x1
        ctx->r6 = S32(0X1 << 16);
        goto L_80047C30;
    }
    // lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // j           L_800485E4
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80047BE8:
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x80015D18
    // sll         $a2, $a2, 9
    ctx->r6 = S32(ctx->r6) << 9;
    FixedPointLerp(rdram, ctx);
    goto after_166;
    // sll         $a2, $a2, 9
    ctx->r6 = S32(ctx->r6) << 9;
    after_166:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x45($s2)
    ctx->r2 = MEM_BU(0X45, ctx->r18);
    // lhu         $a1, 0x1E($s0)
    ctx->r5 = MEM_HU(0X1E, ctx->r16);
    // sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2) << 1;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) << 2;
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // jal         0x80015D18
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    FixedPointLerp(rdram, ctx);
    goto after_167;
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    after_167:
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
L_80047C30:
    // ori         $a2, $a2, 0x86A0
    ctx->r6 = ctx->r6 | 0X86A0;
    // div         $zero, $a2, $s4
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r20)));
    // bne         $s4, $zero, L_80047C44
    if (ctx->r20 != 0) {
        // nop
    
        goto L_80047C44;
    }
    // nop

    // break       7
    do_break(2147777600);
L_80047C44:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s4, $at, L_80047C5C
    if (ctx->r20 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80047C5C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_80047C5C
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_80047C5C;
    }
    // nop

    // break       6
    do_break(2147777624);
L_80047C5C:
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20) << 1;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // sra         $s4, $v0, 12
    ctx->r20 = S32(ctx->r2) >> 12;
    // lh          $s3, 0x2A($s2)
    ctx->r19 = MEM_H(0X2A, ctx->r18);
    // lbu         $a1, 0x45($s2)
    ctx->r5 = MEM_BU(0X45, ctx->r18);
    // lbu         $v1, 0x44($s2)
    ctx->r3 = MEM_BU(0X44, ctx->r18);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0x40($s2)
    ctx->r3 = MEM_W(0X40, ctx->r18);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // sb          $a1, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r5;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // addu        $a2, $s3, $a2
    ctx->r6 = ADD32(ctx->r19, ctx->r6);
    // jal         0x800601F4
    // sh          $a2, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r6;
    FixedSin(rdram, ctx);
    goto after_168;
    // sh          $a2, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r6;
    after_168:
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800602D0
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    FixedCos(rdram, ctx);
    goto after_169;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_169:
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $s0, $s3, 1
    ctx->r16 = S32(ctx->r19) << 1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800601F4
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    FixedSin(rdram, ctx);
    goto after_170;
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_170:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // negu        $v1, $s3
    ctx->r3 = SUB32(0, ctx->r19);
    // addiu       $v1, $v1, -0x400
    ctx->r3 = ADD32(ctx->r3, -0X400);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sh          $v1, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r3;
    // sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // jal         0x800602D0
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    FixedCos(rdram, ctx);
    goto after_171;
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    after_171:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // j           L_800485E4
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
L_80047D28:
    // lbu         $v0, 0x44($s2)
    ctx->r2 = MEM_BU(0X44, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80047D4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80047D4C;
    }
    // nop

    // sb          $zero, 0x44($s2)
    MEM_B(0X44, ctx->r18) = 0;
L_80047D4C:
    // lbu         $v0, 0x45($s2)
    ctx->r2 = MEM_BU(0X45, ctx->r18);
    // nop

    // beq         $v0, $zero, L_80047DDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047DDC;
    }
    // nop

    // lbu         $v0, 0x45($s2)
    ctx->r2 = MEM_BU(0X45, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_800485E4
    // sb          $v0, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r2;
L_80047D70:
    // ori         $s0, $zero, 0x1F
    ctx->r16 = 0 | 0X1F;
    // addiu       $s4, $zero, -0x5A
    ctx->r20 = ADD32(0, -0X5A);
    // ori         $s1, $zero, 0x200
    ctx->r17 = 0 | 0X200;
    // addiu       $s3, $zero, -0x100
    ctx->r19 = ADD32(0, -0X100);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80047D84:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x140
    ctx->r2 = ADD32(0, -0X140);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // jal         0x8004489C
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    sub_8004489C(rdram, ctx);
    goto after_172;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    after_172:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80047D84
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80047D84;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80047DDC:
    // lbu         $v1, 0x46($s2)
    ctx->r3 = MEM_BU(0X46, ctx->r18);
    // nop

    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // addiu       $v1, $zero, -0x801
    ctx->r3 = ADD32(0, -0X801);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // j           L_80048464
    // sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    goto L_80048464;
    // sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
L_80047E10:
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x1280
    ctx->r2 = ADD32(ctx->r2, -0X1280);
    // bne         $s1, $zero, L_80047E5C
    if (ctx->r17 != 0) {
        // addu        $a1, $v1, $v0
        ctx->r5 = ADD32(ctx->r3, ctx->r2);
        goto L_80047E5C;
    }
    // addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x7($a1)
    ctx->r2 = MEM_BU(0X7, ctx->r5);
    // nop

    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_80047E5C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80047E5C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lbu         $v1, 0x41($s2)
    ctx->r3 = MEM_BU(0X41, ctx->r18);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80047E5C:
    // lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(0X7, ctx->r5);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $v1, $v0, L_80048468
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80048468;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v0, 0x41($s2)
    ctx->r2 = MEM_BU(0X41, ctx->r18);
    // lbu         $a0, 0x44($a1)
    ctx->r4 = MEM_BU(0X44, ctx->r5);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // bgez        $a0, L_80047E90
    if (SIGNED(ctx->r4) >= 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_80047E90;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
L_80047E90:
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lw          $v1, 0x40($a1)
    ctx->r3 = MEM_W(0X40, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(0X8, ctx->r2);
    // lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(0XC, ctx->r2);
    // sw          $v1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r3;
    // sw          $a0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r4;
    // sw          $a1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r5;
    // sw          $a2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r6;
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x27($s2)
    do_swl(rdram, 0X27, ctx->r18, ctx->r3);
    // swr         $v1, 0x24($s2)
    do_swr(rdram, 0X24, ctx->r18, ctx->r3);
    // swl         $a0, 0x2B($s2)
    do_swl(rdram, 0X2B, ctx->r18, ctx->r4);
    // swr         $a0, 0x28($s2)
    do_swr(rdram, 0X28, ctx->r18, ctx->r4);
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80047EE8:
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // lhu         $a0, 0x42($s2)
    ctx->r4 = MEM_HU(0X42, ctx->r18);
    // lh          $v1, 0x34($s2)
    ctx->r3 = MEM_H(0X34, ctx->r18);
    // lw          $a1, 0x14($s2)
    ctx->r5 = MEM_W(0X14, ctx->r18);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r3;
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_H(0X38, ctx->r18);
    // lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(0X1C, ctx->r18);
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // lhu         $a1, 0x40($s2)
    ctx->r5 = MEM_HU(0X40, ctx->r18);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    // lh          $v1, 0x36($s2)
    ctx->r3 = MEM_H(0X36, ctx->r18);
    // lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(0X18, ctx->r18);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // j           L_800485E4
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    goto L_800485E4;
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
L_80047F44:
    // lbu         $v0, 0x7($s2)
    ctx->r2 = MEM_BU(0X7, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // lbu         $a0, 0x7($s2)
    ctx->r4 = MEM_BU(0X7, ctx->r18);
    // jal         0x800601F4
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    FixedSin(rdram, ctx);
    goto after_173;
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    after_173:
    // lh          $v1, 0x40($s2)
    ctx->r3 = MEM_H(0X40, ctx->r18);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v1, 0x7($s2)
    ctx->r3 = MEM_BU(0X7, ctx->r18);
    // nop

    // sltiu       $v1, $v1, 0x8
    ctx->r3 = ctx->r3 < 0X8 ? 1 : 0;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // bne         $v1, $zero, L_800485E4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x2E($s2)
        MEM_H(0X2E, ctx->r18) = ctx->r2;
        goto L_800485E4;
    }
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80047F90:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADA($v0)
    ctx->r2 = MEM_H(-0X4ADA, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80047FA8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80047FA8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80047FA8:
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // j           L_800485E4
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_80047FBC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AD8($v0)
    ctx->r2 = MEM_H(-0X4AD8, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80047FD4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80047FD4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80047FD4:
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // j           L_800485E4
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_80047FE8:
    // lh          $v1, 0xE($s2)
    ctx->r3 = MEM_H(0XE, ctx->r18);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // bne         $v1, $v0, L_80048030
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80048030;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B28
    ctx->r4 = ADD32(ctx->r4, -0X4B28);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B2A($v1)
    ctx->r3 = MEM_HU(-0X4B2A, ctx->r3);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80048030
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048030;
    }
    // nop

    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_80048030:
    // lh          $a0, 0xE($s2)
    ctx->r4 = MEM_H(0XE, ctx->r18);
    // jal         0x800601F4
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    FixedSin(rdram, ctx);
    goto after_174;
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    after_174:
    // ori         $a0, $zero, 0xE6
    ctx->r4 = 0 | 0XE6;
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
    // j           L_8004820C
    // ori         $a3, $zero, 0x59D8
    ctx->r7 = 0 | 0X59D8;
    goto L_8004820C;
    // ori         $a3, $zero, 0x59D8
    ctx->r7 = 0 | 0X59D8;
L_80048050:
    // lh          $v1, 0xE($s2)
    ctx->r3 = MEM_H(0XE, ctx->r18);
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // bne         $v1, $v0, L_80048068
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80048068;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = 0;
L_80048068:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_175;
    // nop

    after_175:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // jal         0x80062BF0
    // sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_176;
    // sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    after_176:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x65
    ctx->r6 = 0 | 0X65;
    // addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
    // sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x100
    ctx->r2 = ADD32(ctx->r29, 0X100);
    // sh          $zero, 0x104($sp)
    MEM_H(0X104, ctx->r29) = 0;
    // sh          $zero, 0x100($sp)
    MEM_H(0X100, ctx->r29) = 0;
    // sh          $zero, 0x102($sp)
    MEM_H(0X102, ctx->r29) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2BC
    ctx->r2 = 0 | 0X2BC;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1E
    ctx->r2 = ADD32(0, -0X1E);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
    // jal         0x80042D2C
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_177;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_177:
    // ori         $v1, $zero, 0x3
    ctx->r3 = 0 | 0X3;
    // sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
    // ori         $v1, $zero, 0xE
    ctx->r3 = 0 | 0XE;
    // sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // lh          $a0, 0xE($s2)
    ctx->r4 = MEM_H(0XE, ctx->r18);
    // jal         0x800601F4
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    FixedSin(rdram, ctx);
    goto after_178;
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    after_178:
    // ori         $a0, $zero, 0xA0
    ctx->r4 = 0 | 0XA0;
    // ori         $a1, $zero, 0xB4
    ctx->r5 = 0 | 0XB4;
    // j           L_80048208
    // ori         $a2, $zero, 0xDC
    ctx->r6 = 0 | 0XDC;
    goto L_80048208;
    // ori         $a2, $zero, 0xDC
    ctx->r6 = 0 | 0XDC;
L_80048110:
    // lh          $v1, 0xE($s2)
    ctx->r3 = MEM_H(0XE, ctx->r18);
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // bne         $v1, $v0, L_80048160
    if (ctx->r3 != ctx->r2) {
        // ori         $s0, $zero, 0x3
        ctx->r16 = 0 | 0X3;
        goto L_80048160;
    }
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B28
    ctx->r4 = ADD32(ctx->r4, -0X4B28);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x96
    ctx->r2 = ADD32(ctx->r2, 0X96);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B2A($v1)
    ctx->r3 = MEM_HU(-0X4B2A, ctx->r3);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80048158
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048158;
    }
    // nop

    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_80048158:
    // jal         0x80027280
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    sub_80027280(rdram, ctx);
    goto after_179;
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    after_179:
L_80048160:
    // sh          $zero, 0x144($sp)
    MEM_H(0X144, ctx->r29) = 0;
    // sh          $zero, 0x140($sp)
    MEM_H(0X140, ctx->r29) = 0;
    // sh          $zero, 0x142($sp)
    MEM_H(0X142, ctx->r29) = 0;
L_8004816C:
    // jal         0x80062BF0
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    rand_recomp(rdram, ctx);
    goto after_180;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_180:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // jal         0x80062BF0
    // sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_181;
    // sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    after_181:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x65
    ctx->r6 = 0 | 0X65;
    // addiu       $a3, $sp, 0x130
    ctx->r7 = ADD32(ctx->r29, 0X130);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
    // sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x140
    ctx->r2 = ADD32(ctx->r29, 0X140);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2BC
    ctx->r2 = 0 | 0X2BC;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1E
    ctx->r2 = ADD32(0, -0X1E);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
    // jal         0x80042D2C
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_182;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_182:
    // ori         $v1, $zero, 0x3
    ctx->r3 = 0 | 0X3;
    // sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
    // ori         $v1, $zero, 0xE
    ctx->r3 = 0 | 0XE;
    // bne         $s0, $zero, L_8004816C
    if (ctx->r16 != 0) {
        // sb          $v1, 0x8($v0)
        MEM_B(0X8, ctx->r2) = ctx->r3;
        goto L_8004816C;
    }
    // sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // lh          $a0, 0xE($s2)
    ctx->r4 = MEM_H(0XE, ctx->r18);
    // jal         0x800601F4
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    FixedSin(rdram, ctx);
    goto after_183;
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    after_183:
    // ori         $a0, $zero, 0xF0
    ctx->r4 = 0 | 0XF0;
    // ori         $a1, $zero, 0xF0
    ctx->r5 = 0 | 0XF0;
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
L_80048208:
    // ori         $a3, $zero, 0x4650
    ctx->r7 = 0 | 0X4650;
L_8004820C:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // jal         0x8002EA88
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    TriggerLightFlash(rdram, ctx);
    goto after_184;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_184:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80048224:
    // ori         $a0, $zero, 0x64
    ctx->r4 = 0 | 0X64;
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // jal         0x80044C74
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    sub_80044C74(rdram, ctx);
    goto after_185;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    after_185:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800485E4
    if (ctx->r16 == 0) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // jal         0x800428D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800428D0(rdram, ctx);
    goto after_186;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_186:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_8004825C:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0x4000
    ctx->r4 = 0 | 0X4000;
    // ori         $a1, $zero, 0x200
    ctx->r5 = 0 | 0X200;
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // jal         0x800446E0
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    sub_800446E0(rdram, ctx);
    goto after_187;
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    after_187:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_80048280:
    // lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(0X34, ctx->r18);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(0X18, ctx->r18);
    // lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(0X1C, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lh          $v0, 0x36($s2)
    ctx->r2 = MEM_H(0X36, ctx->r18);
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_H(0X38, ctx->r18);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xB0
    ctx->r2 = 0 | 0XB0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(0X18, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    sub_8002E4F4(rdram, ctx);
    goto after_188;
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    after_188:
    // bne         $v0, $zero, L_80048318
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_80048318;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $a1, 0x44($s2)
    ctx->r5 = MEM_W(0X44, ctx->r18);
    // lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(0X1C, ctx->r18);
    // jal         0x8002E120
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    MAP_CollisionWithTile(rdram, ctx);
    goto after_189;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_189:
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A7C($v1)
    ctx->r3 = MEM_W(-0X2A7C, ctx->r3);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004833C
    if (ctx->r2 != 0) {
        // ori         $s0, $zero, 0x1
        ctx->r16 = 0 | 0X1;
        goto L_8004833C;
    }
    // ori         $s0, $zero, 0x1
    ctx->r16 = 0 | 0X1;
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_80048318:
    // ori         $a2, $zero, 0x3
    ctx->r6 = 0 | 0X3;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_190;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_190:
    // j           L_80048468
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_80048468;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_8004833C:
    // addiu       $s3, $zero, -0xC8
    ctx->r19 = ADD32(0, -0XC8);
    // ori         $s1, $zero, 0x5
    ctx->r17 = 0 | 0X5;
L_80048344:
    // jal         0x80062BF0
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    rand_recomp(rdram, ctx);
    goto after_191;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_191:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sra         $a1, $a1, 15
    ctx->r5 = S32(ctx->r5) >> 15;
    // addiu       $a2, $zero, -0x3
    ctx->r6 = ADD32(0, -0X3);
    // ori         $a3, $zero, 0x1770
    ctx->r7 = 0 | 0X1770;
    // ori         $v0, $zero, 0x27
    ctx->r2 = 0 | 0X27;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // jal         0x8004489C
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004489C(rdram, ctx);
    goto after_192;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_192:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_800485E4
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_800485E4;
    }
    // nop

    // j           L_80048344
    // nop

    goto L_80048344;
    // nop

L_8004839C:
    // addiu       $a0, $sp, 0x148
    ctx->r4 = ADD32(ctx->r29, 0X148);
    // ori         $a1, $zero, 0x12C
    ctx->r5 = 0 | 0X12C;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // ori         $a2, $zero, 0x28
    ctx->r6 = 0 | 0X28;
    // sw          $v0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // ori         $a3, $zero, 0x7D0
    ctx->r7 = 0 | 0X7D0;
    // sw          $v1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80044520
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_80044520(rdram, ctx);
    goto after_193;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_193:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80048470
    if (ctx->r2 != ctx->r3) {
        // ori         $s0, $zero, 0xB
        ctx->r16 = 0 | 0XB;
        goto L_80048470;
    }
    // ori         $s0, $zero, 0xB
    ctx->r16 = 0 | 0XB;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A6C($a0)
    ctx->r4 = MEM_W(-0X2A6C, ctx->r4);
    // addiu       $s4, $zero, -0x5A
    ctx->r20 = ADD32(0, -0X5A);
    // ori         $s3, $zero, 0x200
    ctx->r19 = 0 | 0X200;
    // jal         0x800428D0
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    sub_800428D0(rdram, ctx);
    goto after_194;
    // addiu       $s1, $zero, -0x100
    ctx->r17 = ADD32(0, -0X100);
    after_194:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80048410:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // ori         $a3, $zero, 0xC00
    ctx->r7 = 0 | 0XC00;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // jal         0x8004489C
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    sub_8004489C(rdram, ctx);
    goto after_195;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    after_195:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80048410
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80048410;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80048464:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80048468:
    // j           L_800485E4
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    goto L_800485E4;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80048470:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_196;
    // nop

    after_196:
    // slti        $v0, $v0, 0x4000
    ctx->r2 = SIGNED(ctx->r2) < 0X4000 ? 1 : 0;
    // beq         $v0, $zero, L_800485E4
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_800485E4;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x6D
    ctx->r6 = 0 | 0X6D;
    // addiu       $a3, $s2, 0x14
    ctx->r7 = ADD32(ctx->r18, 0X14);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, 0x1188($v1)
    ctx->r3 = MEM_W(0X1188, ctx->r3);
    // addiu       $v0, $s2, 0x34
    ctx->r2 = ADD32(ctx->r18, 0X34);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    SpawnParticleEntity(rdram, ctx);
    goto after_197;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_197:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800484B0:
    // ori         $a1, $zero, 0x1F4
    ctx->r5 = 0 | 0X1F4;
    // ori         $a2, $zero, 0xF
    ctx->r6 = 0 | 0XF;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // lbu         $v1, 0x40($s2)
    ctx->r3 = MEM_BU(0X40, ctx->r18);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x126C
    ctx->r2 = ADD32(ctx->r2, -0X126C);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3) << 3;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // jal         0x80044520
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    sub_80044520(rdram, ctx);
    goto after_198;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_198:
    // j           L_800485E4
    // nop

    goto L_800485E4;
    // nop

L_800484F4:
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // lh          $v1, 0x2C($s2)
    ctx->r3 = MEM_H(0X2C, ctx->r18);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // slti        $v1, $v1, 0x1000
    ctx->r3 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // beq         $v1, $zero, L_80048524
    if (ctx->r3 == 0) {
        // sh          $v0, 0x36($s2)
        MEM_H(0X36, ctx->r18) = ctx->r2;
        goto L_80048524;
    }
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, 0X200);
    // sh          $v0, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
L_80048524:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_199;
    // nop

    after_199:
    // slti        $v0, $v0, 0x190
    ctx->r2 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // bne         $v0, $zero, L_80048568
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0xB4
        ctx->r4 = 0 | 0XB4;
        goto L_80048568;
    }
    // ori         $a0, $zero, 0xB4
    ctx->r4 = 0 | 0XB4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80044C74
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    sub_80044C74(rdram, ctx);
    goto after_200;
    // addiu       $a2, $zero, -0x12C
    ctx->r6 = ADD32(0, -0X12C);
    after_200:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800485D4
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x5
        ctx->r2 = ctx->r16 & 0X5;
        goto L_800485D4;
    }
    // andi        $v0, $s0, 0x5
    ctx->r2 = ctx->r16 & 0X5;
    // beq         $v0, $zero, L_800485D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800485D4;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // nop

    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_80048568:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_201;
    // nop

    after_201:
    // slti        $v0, $v0, 0x2000
    ctx->r2 = SIGNED(ctx->r2) < 0X2000 ? 1 : 0;
    // beq         $v0, $zero, L_800485CC
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_800485CC;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_202;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_202:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x2A
    ctx->r6 = 0 | 0X2A;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_203;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_203:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    PlayEntitySound(rdram, ctx);
    goto after_204;
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    after_204:
L_800485CC:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_800485D4:
    // lhu         $v0, 0x28($s2)
    ctx->r2 = MEM_HU(0X28, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0xA8C
    ctx->r2 = ADD32(ctx->r2, 0XA8C);
    // sh          $v0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r2;
L_800485E4:
    // lw          $ra, 0x198($sp)
    ctx->r31 = MEM_W(0X198, ctx->r29);
    // lw          $s5, 0x194($sp)
    ctx->r21 = MEM_W(0X194, ctx->r29);
    // lw          $s4, 0x190($sp)
    ctx->r20 = MEM_W(0X190, ctx->r29);
    // lw          $s3, 0x18C($sp)
    ctx->r19 = MEM_W(0X18C, ctx->r29);
    // lw          $s2, 0x188($sp)
    ctx->r18 = MEM_W(0X188, ctx->r29);
    // lw          $s1, 0x184($sp)
    ctx->r17 = MEM_W(0X184, ctx->r29);
    // lw          $s0, 0x180($sp)
    ctx->r16 = MEM_W(0X180, ctx->r29);
    // addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    // jr          $ra
    // nop

    return;
    // nop

;}
