#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xC50
    ctx->r29 = ADD32(ctx->r29, -0XC50);
    // sw          $s1, 0xC3C($sp)
    MEM_W(0XC3C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0xC38($sp)
    MEM_W(0XC38, ctx->r29) = ctx->r16;
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // sw          $ra, 0xC48($sp)
    MEM_W(0XC48, ctx->r29) = ctx->r31;
    // sw          $s3, 0xC44($sp)
    MEM_W(0XC44, ctx->r29) = ctx->r19;
    // sw          $s2, 0xC40($sp)
    MEM_W(0XC40, ctx->r29) = ctx->r18;
L_8004AEFC:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a3, L_8004AF38
    if (ctx->r2 == ctx->r7) {
        // nop
    
        goto L_8004AF38;
    }
    // nop

    // bne         $v0, $a2, L_8004AF38
    if (ctx->r2 != ctx->r6) {
        // nop
    
        goto L_8004AF38;
    }
    // nop

    // sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(0X9, ctx->r3);
    // nop

    // bne         $v0, $a0, L_8004AF30
    if (ctx->r2 != ctx->r4) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004AF30;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8004AF34
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    goto L_8004AF34;
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
L_8004AF30:
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8004AF34:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004AF38:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0xC8
    ctx->r2 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
    // bne         $v0, $zero, L_8004AEFC
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x7C
        ctx->r3 = ADD32(ctx->r3, 0X7C);
        goto L_8004AEFC;
    }
    // addiu       $v1, $v1, 0x7C
    ctx->r3 = ADD32(ctx->r3, 0X7C);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x46E8
    ctx->r4 = ADD32(ctx->r4, 0X46E8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // ori         $a2, $zero, 0x70
    ctx->r6 = 0 | 0X70;
L_8004AF68:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // beq         $v0, $a3, L_8004AFC8
    if (ctx->r2 == ctx->r7) {
        // nop
    
        goto L_8004AFC8;
    }
    // nop

    // lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(0X38, ctx->r4);
    // nop

    // beq         $v1, $zero, L_8004AFB8
    if (ctx->r3 == 0) {
        // addiu       $a0, $a0, 0x78
        ctx->r4 = ADD32(ctx->r4, 0X78);
        goto L_8004AFB8;
    }
    // addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $a2, L_8004AFB8
    if (ctx->r2 != ctx->r6) {
        // nop
    
        goto L_8004AFB8;
    }
    // nop

    // sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(0X10, ctx->r3);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x13($v1)
    ctx->r2 = MEM_BU(0X13, ctx->r3);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004AFB8:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x28
    ctx->r2 = SIGNED(ctx->r5) < 0X28 ? 1 : 0;
    // bne         $v0, $zero, L_8004AF68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AF68;
    }
    // nop

L_8004AFC8:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // ori         $a2, $zero, 0xFD
    ctx->r6 = 0 | 0XFD;
    // lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // addiu       $a0, $a0, -0x67D7
    ctx->r4 = ADD32(ctx->r4, -0X67D7);
L_8004AFE8:
    // lhu         $v1, -0x33($a0)
    ctx->r3 = MEM_HU(-0X33, ctx->r4);
    // nop

    // bne         $v1, $a3, L_8004B000
    if (ctx->r3 != ctx->r7) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8004B000;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // j           L_8004B268
    // sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    goto L_8004B268;
    // sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
L_8004B000:
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // addiu       $at, $at, 0x79F0
    ctx->r1 = ADD32(ctx->r1, 0X79F0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // nop

    // sltiu       $v0, $v1, 0xA5
    ctx->r2 = ctx->r3 < 0XA5 ? 1 : 0;
    // beq         $v0, $zero, L_8004B260
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8004B260;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x2A5C
    ctx->r1 = ADD32(ctx->r1, 0X2A5C);
    // addu        $at, $at, $v0
    gpr jr_addend_8004B03C;
    jr_addend_8004B03C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8004B03C >> 2) {
        case 0: goto L_8004B230; break;
        case 1: goto L_8004B260; break;
        case 2: goto L_8004B230; break;
        case 3: goto L_8004B230; break;
        case 4: goto L_8004B230; break;
        case 5: goto L_8004B230; break;
        case 6: goto L_8004B260; break;
        case 7: goto L_8004B260; break;
        case 8: goto L_8004B230; break;
        case 9: goto L_8004B260; break;
        case 10: goto L_8004B260; break;
        case 11: goto L_8004B260; break;
        case 12: goto L_8004B260; break;
        case 13: goto L_8004B260; break;
        case 14: goto L_8004B260; break;
        case 15: goto L_8004B240; break;
        case 16: goto L_8004B260; break;
        case 17: goto L_8004B240; break;
        case 18: goto L_8004B260; break;
        case 19: goto L_8004B260; break;
        case 20: goto L_8004B260; break;
        case 21: goto L_8004B260; break;
        case 22: goto L_8004B230; break;
        case 23: goto L_8004B260; break;
        case 24: goto L_8004B260; break;
        case 25: goto L_8004B260; break;
        case 26: goto L_8004B260; break;
        case 27: goto L_8004B260; break;
        case 28: goto L_8004B260; break;
        case 29: goto L_8004B260; break;
        case 30: goto L_8004B260; break;
        case 31: goto L_8004B260; break;
        case 32: goto L_8004B260; break;
        case 33: goto L_8004B260; break;
        case 34: goto L_8004B260; break;
        case 35: goto L_8004B260; break;
        case 36: goto L_8004B260; break;
        case 37: goto L_8004B260; break;
        case 38: goto L_8004B260; break;
        case 39: goto L_8004B260; break;
        case 40: goto L_8004B260; break;
        case 41: goto L_8004B260; break;
        case 42: goto L_8004B260; break;
        case 43: goto L_8004B260; break;
        case 44: goto L_8004B260; break;
        case 45: goto L_8004B260; break;
        case 46: goto L_8004B260; break;
        case 47: goto L_8004B260; break;
        case 48: goto L_8004B260; break;
        case 49: goto L_8004B260; break;
        case 50: goto L_8004B260; break;
        case 51: goto L_8004B260; break;
        case 52: goto L_8004B260; break;
        case 53: goto L_8004B260; break;
        case 54: goto L_8004B260; break;
        case 55: goto L_8004B260; break;
        case 56: goto L_8004B260; break;
        case 57: goto L_8004B260; break;
        case 58: goto L_8004B260; break;
        case 59: goto L_8004B260; break;
        case 60: goto L_8004B260; break;
        case 61: goto L_8004B260; break;
        case 62: goto L_8004B260; break;
        case 63: goto L_8004B260; break;
        case 64: goto L_8004B044; break;
        case 65: goto L_8004B260; break;
        case 66: goto L_8004B260; break;
        case 67: goto L_8004B260; break;
        case 68: goto L_8004B260; break;
        case 69: goto L_8004B260; break;
        case 70: goto L_8004B260; break;
        case 71: goto L_8004B260; break;
        case 72: goto L_8004B260; break;
        case 73: goto L_8004B260; break;
        case 74: goto L_8004B260; break;
        case 75: goto L_8004B260; break;
        case 76: goto L_8004B260; break;
        case 77: goto L_8004B260; break;
        case 78: goto L_8004B260; break;
        case 79: goto L_8004B260; break;
        case 80: goto L_8004B230; break;
        case 81: goto L_8004B230; break;
        case 82: goto L_8004B260; break;
        case 83: goto L_8004B21C; break;
        case 84: goto L_8004B230; break;
        case 85: goto L_8004B260; break;
        case 86: goto L_8004B260; break;
        case 87: goto L_8004B260; break;
        case 88: goto L_8004B230; break;
        case 89: goto L_8004B260; break;
        case 90: goto L_8004B260; break;
        case 91: goto L_8004B260; break;
        case 92: goto L_8004B260; break;
        case 93: goto L_8004B260; break;
        case 94: goto L_8004B260; break;
        case 95: goto L_8004B230; break;
        case 96: goto L_8004B260; break;
        case 97: goto L_8004B260; break;
        case 98: goto L_8004B260; break;
        case 99: goto L_8004B260; break;
        case 100: goto L_8004B260; break;
        case 101: goto L_8004B260; break;
        case 102: goto L_8004B260; break;
        case 103: goto L_8004B260; break;
        case 104: goto L_8004B260; break;
        case 105: goto L_8004B260; break;
        case 106: goto L_8004B260; break;
        case 107: goto L_8004B260; break;
        case 108: goto L_8004B260; break;
        case 109: goto L_8004B260; break;
        case 110: goto L_8004B260; break;
        case 111: goto L_8004B260; break;
        case 112: goto L_8004B260; break;
        case 113: goto L_8004B260; break;
        case 114: goto L_8004B260; break;
        case 115: goto L_8004B260; break;
        case 116: goto L_8004B260; break;
        case 117: goto L_8004B260; break;
        case 118: goto L_8004B260; break;
        case 119: goto L_8004B260; break;
        case 120: goto L_8004B260; break;
        case 121: goto L_8004B260; break;
        case 122: goto L_8004B260; break;
        case 123: goto L_8004B260; break;
        case 124: goto L_8004B260; break;
        case 125: goto L_8004B260; break;
        case 126: goto L_8004B260; break;
        case 127: goto L_8004B260; break;
        case 128: goto L_8004B260; break;
        case 129: goto L_8004B260; break;
        case 130: goto L_8004B260; break;
        case 131: goto L_8004B260; break;
        case 132: goto L_8004B260; break;
        case 133: goto L_8004B260; break;
        case 134: goto L_8004B260; break;
        case 135: goto L_8004B260; break;
        case 136: goto L_8004B260; break;
        case 137: goto L_8004B260; break;
        case 138: goto L_8004B260; break;
        case 139: goto L_8004B260; break;
        case 140: goto L_8004B260; break;
        case 141: goto L_8004B260; break;
        case 142: goto L_8004B260; break;
        case 143: goto L_8004B260; break;
        case 144: goto L_8004B260; break;
        case 145: goto L_8004B260; break;
        case 146: goto L_8004B260; break;
        case 147: goto L_8004B260; break;
        case 148: goto L_8004B260; break;
        case 149: goto L_8004B260; break;
        case 150: goto L_8004B260; break;
        case 151: goto L_8004B260; break;
        case 152: goto L_8004B260; break;
        case 153: goto L_8004B260; break;
        case 154: goto L_8004B260; break;
        case 155: goto L_8004B260; break;
        case 156: goto L_8004B260; break;
        case 157: goto L_8004B260; break;
        case 158: goto L_8004B260; break;
        case 159: goto L_8004B260; break;
        case 160: goto L_8004B230; break;
        case 161: goto L_8004B230; break;
        case 162: goto L_8004B260; break;
        case 163: goto L_8004B230; break;
        case 164: goto L_8004B230; break;
        default: switch_error(__func__, 0x8004B03C, 0x80012A5C);
    }
    // nop

L_8004B044:
    // lbu         $v1, -0x35($a0)
    ctx->r3 = MEM_BU(-0X35, ctx->r4);
    // ori         $v0, $zero, 0x62
    ctx->r2 = 0 | 0X62;
    // beq         $v1, $v0, L_8004B178
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF2
        ctx->r2 = 0 | 0XF2;
        goto L_8004B178;
    }
    // ori         $v0, $zero, 0xF2
    ctx->r2 = 0 | 0XF2;
    // slti        $v0, $v1, 0x63
    ctx->r2 = SIGNED(ctx->r3) < 0X63 ? 1 : 0;
    // beq         $v0, $zero, L_8004B07C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x60
        ctx->r2 = 0 | 0X60;
        goto L_8004B07C;
    }
    // ori         $v0, $zero, 0x60
    ctx->r2 = 0 | 0X60;
    // beq         $v1, $v0, L_8004B090
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_8004B090;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // ori         $v0, $zero, 0x61
    ctx->r2 = 0 | 0X61;
    // beq         $v1, $v0, L_8004B10C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_8004B10C;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // j           L_8004B210
    // sb          $a2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r6;
    goto L_8004B210;
    // sb          $a2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r6;
L_8004B07C:
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // beq         $v1, $v0, L_8004B1F4
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF3
        ctx->r2 = 0 | 0XF3;
        goto L_8004B1F4;
    }
    // ori         $v0, $zero, 0xF3
    ctx->r2 = 0 | 0XF3;
    // j           L_8004B210
    // sb          $a2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r6;
    goto L_8004B210;
    // sb          $a2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r6;
L_8004B090:
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x33($a0)
    ctx->r2 = MEM_BU(-0X33, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x25($a0)
    ctx->r2 = MEM_W(-0X25, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x25($a0)
    ctx->r2 = MEM_W(-0X25, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x1D($a0)
    ctx->r2 = MEM_W(-0X1D, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x1D($a0)
    ctx->r2 = MEM_W(-0X1D, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x21($a0)
    ctx->r2 = MEM_BU(-0X21, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x21($a0)
    ctx->r2 = MEM_W(-0X21, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lhu         $v0, -0x13($a0)
    ctx->r2 = MEM_HU(-0X13, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8004B264
    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    goto L_8004B264;
    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
L_8004B10C:
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x33($a0)
    ctx->r2 = MEM_BU(-0X33, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x25($a0)
    ctx->r2 = MEM_W(-0X25, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x25($a0)
    ctx->r2 = MEM_W(-0X25, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x1D($a0)
    ctx->r2 = MEM_W(-0X1D, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x1D($a0)
    ctx->r2 = MEM_W(-0X1D, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x21($a0)
    ctx->r2 = MEM_BU(-0X21, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x21($a0)
    ctx->r2 = MEM_W(-0X21, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8004B264
    // srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    goto L_8004B264;
    // srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
L_8004B178:
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x33($a0)
    ctx->r2 = MEM_BU(-0X33, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x25($a0)
    ctx->r2 = MEM_W(-0X25, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x25($a0)
    ctx->r2 = MEM_W(-0X25, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x1D($a0)
    ctx->r2 = MEM_W(-0X1D, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x1D($a0)
    ctx->r2 = MEM_W(-0X1D, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x21($a0)
    ctx->r2 = MEM_BU(-0X21, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, -0x21($a0)
    ctx->r2 = MEM_W(-0X21, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1($a0)
    ctx->r2 = MEM_HU(0X1, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8004B264
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    goto L_8004B264;
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
L_8004B1F4:
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x33($a0)
    ctx->r2 = MEM_BU(-0X33, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(-0X1, ctx->r4);
    // j           L_8004B264
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_8004B264;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004B210:
    // lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(-0X1, ctx->r4);
    // j           L_8004B264
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_8004B264;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004B21C:
    // lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(-0X1, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004B26C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004B26C;
    }
    // nop

L_8004B230:
    // sb          $a2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r6;
    // lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(-0X1, ctx->r4);
    // j           L_8004B264
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_8004B264;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004B240:
    // ori         $v0, $zero, 0xF4
    ctx->r2 = 0 | 0XF4;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(-0X1, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // j           L_8004B264
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_8004B264;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004B260:
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
L_8004B264:
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8004B268:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8004B26C:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x18C
    ctx->r2 = SIGNED(ctx->r5) < 0X18C ? 1 : 0;
    // bne         $v0, $zero, L_8004AFE8
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x44
        ctx->r4 = ADD32(ctx->r4, 0X44);
        goto L_8004AFE8;
    }
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // jal         0x8004AD48
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_8004AD48(rdram, ctx);
    goto after_0;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // jal         0x8004AD98
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_8004AD98(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // addu        $s3, $v0, $s1
    ctx->r19 = ADD32(ctx->r2, ctx->r17);
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // beq         $v0, $zero, L_8004B2B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B2B0;
    }
    // nop

    // jal         0x80017B7C
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    sub_80017B7C(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
L_8004B2B0:
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // addiu       $a0, $a0, 0x529C
    ctx->r4 = ADD32(ctx->r4, 0X529C);
    // addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // subu        $v0, $s0, $s2
    ctx->r2 = SUB32(ctx->r16, ctx->r18);
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // and         $s0, $v0, $v1
    ctx->r16 = ctx->r2 & ctx->r3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80017AC4
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    FMOAllocateBuffer(rdram, ctx);
    goto after_3;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_3:
    // beq         $v0, $zero, L_8004B2FC
    if (ctx->r2 == 0) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8004B2FC;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x80017684
    // sra         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16) >> 2;
    MemcpyDword(rdram, ctx);
    goto after_4;
    // sra         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16) >> 2;
    after_4:
    // jal         0x8004AE08
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8004AE08(rdram, ctx);
    goto after_5;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // jal         0x8004AE54
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8004AE54(rdram, ctx);
    goto after_6;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
L_8004B2FC:
    // lw          $ra, 0xC48($sp)
    ctx->r31 = MEM_W(0XC48, ctx->r29);
    // lw          $s3, 0xC44($sp)
    ctx->r19 = MEM_W(0XC44, ctx->r29);
    // lw          $s2, 0xC40($sp)
    ctx->r18 = MEM_W(0XC40, ctx->r29);
    // lw          $s1, 0xC3C($sp)
    ctx->r17 = MEM_W(0XC3C, ctx->r29);
    // lw          $s0, 0xC38($sp)
    ctx->r16 = MEM_W(0XC38, ctx->r29);
    // addiu       $sp, $sp, 0xC50
    ctx->r29 = ADD32(ctx->r29, 0XC50);
    // jr          $ra
    // nop

    return;
    // nop

;}
