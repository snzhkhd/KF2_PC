#include "recomp.h"
#include "disable_warnings.h"

void Map_InitializeObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // lw          $fp, -0x5A50($fp)
    ctx->r30 = MEM_W(-0X5A50, ctx->r30);
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // addiu       $s2, $s2, -0x6810
    ctx->r18 = ADD32(ctx->r18, -0X6810);
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // ori         $s7, $zero, 0x15D
    ctx->r23 = 0 | 0X15D;
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // ori         $s4, $zero, 0xFF
    ctx->r20 = 0 | 0XFF;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // ori         $s6, $zero, 0x1
    ctx->r22 = 0 | 0X1;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addiu       $s3, $s5, 0xC
    ctx->r19 = ADD32(ctx->r21, 0XC);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
L_80038360:
    // lhu         $v1, -0x8($s3)
    ctx->r3 = MEM_HU(-0X8, ctx->r19);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_80038378
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80038378;
    }
    // nop

    // j           L_80038384
    // sh          $s4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r20;
    goto L_80038384;
    // sh          $s4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r20;
L_80038378:
    // lhu         $v0, -0x8($s3)
    ctx->r2 = MEM_HU(-0X8, ctx->r19);
    // nop

    // sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_80038384:
    // lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(0X4, ctx->r16);
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // beq         $a0, $s4, L_80038AA0
    if (ctx->r4 == ctx->r20) {
        // sb          $a1, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r5;
        goto L_80038AA0;
    }
    // sb          $a1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r5;
    // ori         $t0, $zero, 0x80
    ctx->r8 = 0 | 0X80;
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // sb          $t0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r8;
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // lhu         $v1, -0x6($s3)
    ctx->r3 = MEM_HU(-0X6, ctx->r19);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r2;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sh          $v1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(0X0, ctx->r21);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(0X3, ctx->r17);
    // nop

    // sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // lhu         $v1, 0xA($s1)
    ctx->r3 = MEM_HU(0XA, ctx->r17);
    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // sb          $a1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r5;
    // sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8003841C
    if (ctx->r2 == 0) {
        // sh          $v1, 0xC($s0)
        MEM_H(0XC, ctx->r16) = ctx->r3;
        goto L_8003841C;
    }
    // sh          $v1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r3;
    // sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_8003841C:
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xA($s3)
    ctx->r2 = MEM_BU(-0XA, ctx->r19);
    // lh          $v1, -0x2($s3)
    ctx->r3 = MEM_H(-0X2, ctx->r19);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x12($s0)
    MEM_W(0X12, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xB($s3)
    ctx->r2 = MEM_BU(-0XB, ctx->r19);
    // lh          $v1, -0x4($s3)
    ctx->r3 = MEM_H(-0X4, ctx->r19);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1A($s0)
    MEM_W(0X1A, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xB($s3)
    ctx->r2 = MEM_BU(-0XB, ctx->r19);
    // lbu         $a0, -0xA($s3)
    ctx->r4 = MEM_BU(-0XA, ctx->r19);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // nop

    // beq         $a0, $s6, L_80038498
    if (ctx->r4 == ctx->r22) {
        // addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
        goto L_80038498;
    }
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
L_80038498:
    // addiu       $a0, $s2, 0x40
    ctx->r4 = ADD32(ctx->r18, 0X40);
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // lh          $v1, 0x0($s3)
    ctx->r3 = MEM_H(0X0, ctx->r19);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r3;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(0X8, ctx->r19);
    // sw          $v0, 0x36($s0)
    MEM_W(0X36, ctx->r16) = ctx->r2;
    // sw          $v1, 0x3A($s0)
    MEM_W(0X3A, ctx->r16) = ctx->r3;
    // jal         0x80062B80
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
    memset_recomp(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
    after_0:
    // lhu         $a2, 0x4($s1)
    ctx->r6 = MEM_HU(0X4, ctx->r17);
    // nop

    // beq         $a2, $zero, L_800384EC
    if (ctx->r6 == 0) {
        // nop
    
        goto L_800384EC;
    }
    // nop

    // lw          $a0, 0x12($s0)
    ctx->r4 = MEM_W(0X12, ctx->r16);
    // lw          $a1, 0x1A($s0)
    ctx->r5 = MEM_W(0X1A, ctx->r16);
    // jal         0x8002E25C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_1;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_1:
L_800384EC:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // sltiu       $v0, $v1, 0xFE
    ctx->r2 = ctx->r3 < 0XFE ? 1 : 0;
    // beq         $v0, $zero, L_80038A70
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80038A70;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1580
    ctx->r1 = ADD32(ctx->r1, 0X1580);
    // addu        $at, $at, $v0
    gpr jr_addend_80038518;
    jr_addend_80038518 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80038518 >> 2) {
        case 0: goto L_800385C4; break;
        case 1: goto L_80038678; break;
        case 2: goto L_80038604; break;
        case 3: goto L_80038718; break;
        case 4: goto L_80038A70; break;
        case 5: goto L_80038A70; break;
        case 6: goto L_80038700; break;
        case 7: goto L_80038A48; break;
        case 8: goto L_80038A70; break;
        case 9: goto L_800389E4; break;
        case 10: goto L_80038A70; break;
        case 11: goto L_800387FC; break;
        case 12: goto L_80038A70; break;
        case 13: goto L_80038A30; break;
        case 14: goto L_80038A70; break;
        case 15: goto L_80038A3C; break;
        case 16: goto L_80038A1C; break;
        case 17: goto L_800389EC; break;
        case 18: goto L_800389E4; break;
        case 19: goto L_80038A5C; break;
        case 20: goto L_8003870C; break;
        case 21: goto L_80038A70; break;
        case 22: goto L_80038A70; break;
        case 23: goto L_80038A70; break;
        case 24: goto L_80038A70; break;
        case 25: goto L_80038A70; break;
        case 26: goto L_80038A70; break;
        case 27: goto L_80038A70; break;
        case 28: goto L_80038A70; break;
        case 29: goto L_80038860; break;
        case 30: goto L_80038A70; break;
        case 31: goto L_80038A8C; break;
        case 32: goto L_800387D8; break;
        case 33: goto L_80038A70; break;
        case 34: goto L_80038A70; break;
        case 35: goto L_80038A70; break;
        case 36: goto L_80038A70; break;
        case 37: goto L_80038A70; break;
        case 38: goto L_80038A70; break;
        case 39: goto L_80038A70; break;
        case 40: goto L_80038A70; break;
        case 41: goto L_80038A70; break;
        case 42: goto L_80038A70; break;
        case 43: goto L_80038A70; break;
        case 44: goto L_80038A70; break;
        case 45: goto L_80038A70; break;
        case 46: goto L_800389F8; break;
        case 47: goto L_80038A70; break;
        case 48: goto L_80038A70; break;
        case 49: goto L_80038A70; break;
        case 50: goto L_80038A70; break;
        case 51: goto L_80038A70; break;
        case 52: goto L_80038A70; break;
        case 53: goto L_80038A70; break;
        case 54: goto L_80038A70; break;
        case 55: goto L_80038A70; break;
        case 56: goto L_80038A70; break;
        case 57: goto L_80038A70; break;
        case 58: goto L_80038A70; break;
        case 59: goto L_80038A70; break;
        case 60: goto L_80038A70; break;
        case 61: goto L_80038A70; break;
        case 62: goto L_80038520; break;
        case 63: goto L_80038A70; break;
        case 64: goto L_80038A70; break;
        case 65: goto L_80038A70; break;
        case 66: goto L_80038A70; break;
        case 67: goto L_80038A70; break;
        case 68: goto L_80038A70; break;
        case 69: goto L_80038A70; break;
        case 70: goto L_80038A70; break;
        case 71: goto L_80038A70; break;
        case 72: goto L_80038A70; break;
        case 73: goto L_80038A70; break;
        case 74: goto L_80038A70; break;
        case 75: goto L_80038A70; break;
        case 76: goto L_80038A70; break;
        case 77: goto L_80038A70; break;
        case 78: goto L_80038A70; break;
        case 79: goto L_80038914; break;
        case 80: goto L_80038A70; break;
        case 81: goto L_800386E8; break;
        case 82: goto L_80038894; break;
        case 83: goto L_80038A70; break;
        case 84: goto L_80038A70; break;
        case 85: goto L_80038A70; break;
        case 86: goto L_80038944; break;
        case 87: goto L_80038958; break;
        case 88: goto L_80038A70; break;
        case 89: goto L_80038A70; break;
        case 90: goto L_80038A70; break;
        case 91: goto L_80038A70; break;
        case 92: goto L_80038A70; break;
        case 93: goto L_80038A70; break;
        case 94: goto L_80038A70; break;
        case 95: goto L_80038A70; break;
        case 96: goto L_80038A70; break;
        case 97: goto L_80038A70; break;
        case 98: goto L_80038A70; break;
        case 99: goto L_80038A70; break;
        case 100: goto L_80038A70; break;
        case 101: goto L_80038A70; break;
        case 102: goto L_80038A70; break;
        case 103: goto L_80038A70; break;
        case 104: goto L_80038A70; break;
        case 105: goto L_80038A70; break;
        case 106: goto L_80038A70; break;
        case 107: goto L_80038A70; break;
        case 108: goto L_80038A70; break;
        case 109: goto L_80038A70; break;
        case 110: goto L_80038A70; break;
        case 111: goto L_80038A70; break;
        case 112: goto L_80038A70; break;
        case 113: goto L_80038A70; break;
        case 114: goto L_80038A70; break;
        case 115: goto L_80038A70; break;
        case 116: goto L_80038A70; break;
        case 117: goto L_80038A70; break;
        case 118: goto L_80038A70; break;
        case 119: goto L_80038A70; break;
        case 120: goto L_80038A70; break;
        case 121: goto L_80038A70; break;
        case 122: goto L_80038A70; break;
        case 123: goto L_80038A70; break;
        case 124: goto L_80038A70; break;
        case 125: goto L_80038A70; break;
        case 126: goto L_80038A70; break;
        case 127: goto L_80038A70; break;
        case 128: goto L_80038A70; break;
        case 129: goto L_80038A70; break;
        case 130: goto L_80038A70; break;
        case 131: goto L_80038A70; break;
        case 132: goto L_80038A70; break;
        case 133: goto L_80038A70; break;
        case 134: goto L_80038A70; break;
        case 135: goto L_80038A70; break;
        case 136: goto L_80038A70; break;
        case 137: goto L_80038A70; break;
        case 138: goto L_80038A70; break;
        case 139: goto L_80038A70; break;
        case 140: goto L_80038A70; break;
        case 141: goto L_80038A70; break;
        case 142: goto L_80038A70; break;
        case 143: goto L_80038A70; break;
        case 144: goto L_80038A70; break;
        case 145: goto L_80038A70; break;
        case 146: goto L_80038A70; break;
        case 147: goto L_80038A70; break;
        case 148: goto L_80038A70; break;
        case 149: goto L_80038A70; break;
        case 150: goto L_80038A70; break;
        case 151: goto L_80038A70; break;
        case 152: goto L_80038A70; break;
        case 153: goto L_80038A70; break;
        case 154: goto L_80038A70; break;
        case 155: goto L_80038A70; break;
        case 156: goto L_80038A70; break;
        case 157: goto L_80038A70; break;
        case 158: goto L_80038A70; break;
        case 159: goto L_80038A70; break;
        case 160: goto L_80038A70; break;
        case 161: goto L_80038A70; break;
        case 162: goto L_80038A70; break;
        case 163: goto L_80038A70; break;
        case 164: goto L_80038A70; break;
        case 165: goto L_80038A70; break;
        case 166: goto L_80038A70; break;
        case 167: goto L_80038A70; break;
        case 168: goto L_80038A70; break;
        case 169: goto L_80038A70; break;
        case 170: goto L_80038A70; break;
        case 171: goto L_80038A70; break;
        case 172: goto L_80038A70; break;
        case 173: goto L_80038A70; break;
        case 174: goto L_80038A70; break;
        case 175: goto L_80038A70; break;
        case 176: goto L_80038A70; break;
        case 177: goto L_80038A70; break;
        case 178: goto L_80038A70; break;
        case 179: goto L_80038A70; break;
        case 180: goto L_80038A70; break;
        case 181: goto L_80038A70; break;
        case 182: goto L_80038A70; break;
        case 183: goto L_80038A70; break;
        case 184: goto L_80038A70; break;
        case 185: goto L_80038A70; break;
        case 186: goto L_80038A70; break;
        case 187: goto L_80038A70; break;
        case 188: goto L_80038A70; break;
        case 189: goto L_80038A70; break;
        case 190: goto L_80038A70; break;
        case 191: goto L_80038A70; break;
        case 192: goto L_80038A70; break;
        case 193: goto L_80038A70; break;
        case 194: goto L_80038A70; break;
        case 195: goto L_80038A70; break;
        case 196: goto L_80038A70; break;
        case 197: goto L_80038A70; break;
        case 198: goto L_80038A70; break;
        case 199: goto L_80038A70; break;
        case 200: goto L_80038A70; break;
        case 201: goto L_80038A70; break;
        case 202: goto L_80038A70; break;
        case 203: goto L_80038A70; break;
        case 204: goto L_80038A70; break;
        case 205: goto L_80038A70; break;
        case 206: goto L_80038A70; break;
        case 207: goto L_80038A70; break;
        case 208: goto L_80038A70; break;
        case 209: goto L_80038A70; break;
        case 210: goto L_80038A70; break;
        case 211: goto L_80038A70; break;
        case 212: goto L_80038A70; break;
        case 213: goto L_80038A70; break;
        case 214: goto L_80038A70; break;
        case 215: goto L_80038A70; break;
        case 216: goto L_80038A70; break;
        case 217: goto L_80038A70; break;
        case 218: goto L_80038A70; break;
        case 219: goto L_80038A70; break;
        case 220: goto L_80038A70; break;
        case 221: goto L_80038A70; break;
        case 222: goto L_80038730; break;
        case 223: goto L_800387E8; break;
        case 224: goto L_80038A64; break;
        case 225: goto L_80038A70; break;
        case 226: goto L_80038A70; break;
        case 227: goto L_80038A70; break;
        case 228: goto L_80038A70; break;
        case 229: goto L_80038A70; break;
        case 230: goto L_80038A70; break;
        case 231: goto L_80038A70; break;
        case 232: goto L_80038A70; break;
        case 233: goto L_80038A70; break;
        case 234: goto L_80038A70; break;
        case 235: goto L_80038A70; break;
        case 236: goto L_80038A70; break;
        case 237: goto L_80038A70; break;
        case 238: goto L_80038888; break;
        case 239: goto L_80038A70; break;
        case 240: goto L_80038A70; break;
        case 241: goto L_80038A70; break;
        case 242: goto L_80038A70; break;
        case 243: goto L_80038A70; break;
        case 244: goto L_80038A70; break;
        case 245: goto L_80038A70; break;
        case 246: goto L_80038A70; break;
        case 247: goto L_80038A70; break;
        case 248: goto L_80038A70; break;
        case 249: goto L_80038A70; break;
        case 250: goto L_80038A70; break;
        case 251: goto L_80038A70; break;
        case 252: goto L_80038A70; break;
        case 253: goto L_80038A8C; break;
        default: switch_error(__func__, 0x80038518, 0x80011580);
    }
    // nop

L_80038520:
    // lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(0X1, ctx->r17);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_80038A8C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80038A8C;
    }
    // nop

    // lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(0X38, ctx->r16);
    // nop

    // beq         $v0, $s4, L_80038550
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_80038550;
    }
    // nop

    // lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(0X38, ctx->r16);
    // nop

    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
L_80038550:
    // lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(0X39, ctx->r16);
    // nop

    // beq         $v0, $s4, L_80038570
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_80038570;
    }
    // nop

    // lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(0X39, ctx->r16);
    // nop

    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
L_80038570:
    // lbu         $v0, 0x3A($s0)
    ctx->r2 = MEM_BU(0X3A, ctx->r16);
    // nop

    // beq         $v0, $s4, L_80038590
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_80038590;
    }
    // nop

    // lbu         $v0, 0x3A($s0)
    ctx->r2 = MEM_BU(0X3A, ctx->r16);
    // nop

    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
L_80038590:
    // lbu         $v0, 0x37($s0)
    ctx->r2 = MEM_BU(0X37, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80038A8C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80038A8C;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lw          $v1, 0x16($s0)
    ctx->r3 = MEM_W(0X16, ctx->r16);
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $s6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r22;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // j           L_80038A8C
    // sw          $v1, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r3;
    goto L_80038A8C;
    // sw          $v1, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r3;
L_800385C4:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lh          $a3, 0x24($s0)
    ctx->r7 = MEM_H(0X24, ctx->r16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0xC50
    ctx->r2 = ADD32(ctx->r2, -0XC50);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // lw          $a1, 0x12($s0)
    ctx->r5 = MEM_W(0X12, ctx->r16);
    // lw          $a2, 0x1A($s0)
    ctx->r6 = MEM_W(0X1A, ctx->r16);
    // jal         0x80037A1C
    // nop

    Map_ApplyBlueprint(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_80038A8C
    // nop

    goto L_80038A8C;
    // nop

L_80038604:
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lbu         $a1, 0x39($s0)
    ctx->r5 = MEM_BU(0X39, ctx->r16);
    // lbu         $a2, 0x3A($s0)
    ctx->r6 = MEM_BU(0X3A, ctx->r16);
    // lbu         $a3, 0x37($s0)
    ctx->r7 = MEM_BU(0X37, ctx->r16);
    // lbu         $v1, 0x38($s0)
    ctx->r3 = MEM_BU(0X38, ctx->r16);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // jal         0x80037C0C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_3;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_3:
    // ori         $a2, $zero, 0xBB8
    ctx->r6 = 0 | 0XBB8;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // lw          $a0, 0x12($s0)
    ctx->r4 = MEM_W(0X12, ctx->r16);
    // lw          $a1, 0x1A($s0)
    ctx->r5 = MEM_W(0X1A, ctx->r16);
    // lhu         $v1, 0x24($s0)
    ctx->r3 = MEM_HU(0X24, ctx->r16);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x3E7
    ctx->r2 = 0 | 0X3E7;
    // sh          $v0, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r2;
    // jal         0x8002E25C
    // sh          $v1, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r3;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_4;
    // sh          $v1, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r3;
    after_4:
    // j           L_80038A8C
    // nop

    goto L_80038A8C;
    // nop

L_80038678:
    // lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(0X38, ctx->r16);
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(0XD, ctx->r17);
    // lbu         $v1, 0x39($s0)
    ctx->r3 = MEM_BU(0X39, ctx->r16);
    // lbu         $a2, 0x3A($s0)
    ctx->r6 = MEM_BU(0X3A, ctx->r16);
    // lbu         $a3, 0x37($s0)
    ctx->r7 = MEM_BU(0X37, ctx->r16);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xD($s1)
    ctx->r2 = MEM_BU(0XD, ctx->r17);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xE($s1)
    ctx->r2 = MEM_BU(0XE, ctx->r17);
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $v1, 0x24($s0)
    ctx->r3 = MEM_H(0X24, ctx->r16);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80037C0C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_5;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_5:
    // ori         $a2, $zero, 0x1130
    ctx->r6 = 0 | 0X1130;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // lw          $a0, 0x12($s0)
    ctx->r4 = MEM_W(0X12, ctx->r16);
    // lw          $a1, 0x1A($s0)
    ctx->r5 = MEM_W(0X1A, ctx->r16);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // jal         0x8002E25C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_6;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    after_6:
    // j           L_80038A8C
    // nop

    goto L_80038A8C;
    // nop

L_800386E8:
    // ori         $v0, $zero, 0x53
    ctx->r2 = 0 | 0X53;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // j           L_80038A8C
    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
L_80038700:
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // j           L_80038A8C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_8003870C:
    // ori         $v0, $zero, 0x16
    ctx->r2 = 0 | 0X16;
    // j           L_80038A8C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80038718:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // lbu         $a2, 0xC($s1)
    ctx->r6 = MEM_BU(0XC, ctx->r17);
    // j           L_80038934
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_80038934;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80038730:
    // ori         $v0, $zero, 0xE0
    ctx->r2 = 0 | 0XE0;
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lh          $v1, -0x2($s3)
    ctx->r3 = MEM_H(-0X2, ctx->r19);
    // lw          $v0, 0x12($s0)
    ctx->r2 = MEM_W(0X12, ctx->r16);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x12($s0)
    MEM_W(0X12, ctx->r16) = ctx->r2;
    // lh          $v1, -0x4($s3)
    ctx->r3 = MEM_H(-0X4, ctx->r19);
    // lw          $v0, 0x1A($s0)
    ctx->r2 = MEM_W(0X1A, ctx->r16);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1A($s0)
    MEM_W(0X1A, ctx->r16) = ctx->r2;
    // lh          $v1, 0x0($s3)
    ctx->r3 = MEM_H(0X0, ctx->r19);
    // lw          $v0, 0x16($s0)
    ctx->r2 = MEM_W(0X16, ctx->r16);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r2;
    // lh          $v0, -0x2($s3)
    ctx->r2 = MEM_H(-0X2, ctx->r19);
    // nop

    // bne         $v0, $s4, L_80038798
    if (ctx->r2 != ctx->r20) {
        // ori         $v0, $zero, 0x7F
        ctx->r2 = 0 | 0X7F;
        goto L_80038798;
    }
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r2;
    // j           L_80038A8C
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
L_80038798:
    // lbu         $v0, -0x2($s3)
    ctx->r2 = MEM_BU(-0X2, ctx->r19);
    // lbu         $v1, -0xA($s3)
    ctx->r3 = MEM_BU(-0XA, ctx->r19);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x4($s3)
    ctx->r2 = MEM_BU(-0X4, ctx->r19);
    // lbu         $a0, -0xB($s3)
    ctx->r4 = MEM_BU(-0XB, ctx->r19);
    // lw          $v1, 0x16($s0)
    ctx->r3 = MEM_W(0X16, ctx->r16);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sb          $v0, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // sra         $v1, $v1, 7
    ctx->r3 = S32(ctx->r3) >> 7;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_80038A8C
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
L_800387D8:
    // ori         $v0, $zero, 0x22
    ctx->r2 = 0 | 0X22;
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // j           L_800387F0
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    goto L_800387F0;
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
L_800387E8:
    // ori         $v0, $zero, 0xE1
    ctx->r2 = 0 | 0XE1;
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
L_800387F0:
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // j           L_80038A8C
    // sb          $zero, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = 0;
    goto L_80038A8C;
    // sb          $zero, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = 0;
L_800387FC:
    // lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(0X38, ctx->r16);
    // nop

    // beq         $v0, $s4, L_8003881C
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_8003881C;
    }
    // nop

    // lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(0X38, ctx->r16);
    // nop

    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
L_8003881C:
    // lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(0X39, ctx->r16);
    // nop

    // beq         $v0, $s4, L_8003883C
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_8003883C;
    }
    // nop

    // lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(0X39, ctx->r16);
    // nop

    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
L_8003883C:
    // lbu         $v0, 0x3A($s0)
    ctx->r2 = MEM_BU(0X3A, ctx->r16);
    // nop

    // beq         $v0, $s4, L_80038A8C
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_80038A8C;
    }
    // nop

    // lbu         $v0, 0x3A($s0)
    ctx->r2 = MEM_BU(0X3A, ctx->r16);
    // nop

    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // j           L_80038A8C
    // sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
L_80038860:
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // lhu         $v1, 0x3C($s0)
    ctx->r3 = MEM_HU(0X3C, ctx->r16);
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $fp, $v0
    ctx->r2 = ADD32(ctx->r30, ctx->r2);
    // j           L_80038A8C
    // sw          $v0, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sw          $v0, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r2;
L_80038888:
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // j           L_80038A8C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80038894:
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // lbu         $a0, 0x3E($s0)
    ctx->r4 = MEM_BU(0X3E, ctx->r16);
    // lh          $a3, 0x24($s0)
    ctx->r7 = MEM_H(0X24, ctx->r16);
    // ori         $v0, $zero, 0x54
    ctx->r2 = 0 | 0X54;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lbu         $v1, 0xE($s1)
    ctx->r3 = MEM_BU(0XE, ctx->r17);
    // lbu         $v0, 0x3C($s0)
    ctx->r2 = MEM_BU(0X3C, ctx->r16);
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0xD40
    ctx->r3 = ADD32(ctx->r3, -0XD40);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a1, 0x12($s0)
    ctx->r5 = MEM_W(0X12, ctx->r16);
    // lw          $a2, 0x1A($s0)
    ctx->r6 = MEM_W(0X1A, ctx->r16);
    // jal         0x80037A1C
    // nop

    Map_ApplyBlueprint(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // j           L_80038A8C
    // sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    goto L_80038A8C;
    // sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
L_80038914:
    // lbu         $v1, 0x39($s0)
    ctx->r3 = MEM_BU(0X39, ctx->r16);
    // ori         $v0, $zero, 0x51
    ctx->r2 = 0 | 0X51;
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // beq         $v1, $s4, L_80038A8C
    if (ctx->r3 == ctx->r20) {
        // sb          $zero, 0x3E($s0)
        MEM_B(0X3E, ctx->r16) = 0;
        goto L_80038A8C;
    }
    // sb          $zero, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = 0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lbu         $a2, 0x17($s1)
    ctx->r6 = MEM_BU(0X17, ctx->r17);
L_80038934:
    // jal         0x80038120
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80038120(rdram, ctx);
    goto after_8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // j           L_80038A8C
    // nop

    goto L_80038A8C;
    // nop

L_80038944:
    // ori         $v0, $zero, 0x58
    ctx->r2 = 0 | 0X58;
    // sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // j           L_80038A8C
    // sh          $s6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r22;
    goto L_80038A8C;
    // sh          $s6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r22;
L_80038958:
    // ori         $v0, $zero, 0x59
    ctx->r2 = 0 | 0X59;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x16($s0)
    ctx->r2 = MEM_W(0X16, ctx->r16);
    // lw          $v1, 0x1A($s0)
    ctx->r3 = MEM_W(0X1A, ctx->r16);
    // sb          $s6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r22;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // sw          $v0, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
    // lw          $v1, 0x12($s0)
    ctx->r3 = MEM_W(0X12, ctx->r16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // nop

    // beq         $v1, $s6, L_800389D0
    if (ctx->r3 == ctx->r22) {
        // addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_800389D0;
    }
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_800389D0:
    // ori         $v0, $zero, 0x75
    ctx->r2 = 0 | 0X75;
    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
L_800389E4:
    // j           L_80038A8C
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    goto L_80038A8C;
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
L_800389EC:
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // j           L_80038A8C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_800389F8:
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x3A($s0)
    ctx->r2 = MEM_BU(0X3A, ctx->r16);
    // lw          $v1, 0x16($s0)
    ctx->r3 = MEM_W(0X16, ctx->r16);
    // sb          $s6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r22;
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // j           L_80038A8C
    // sw          $v1, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r3;
    goto L_80038A8C;
    // sw          $v1, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r3;
L_80038A1C:
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // addiu       $v0, $fp, 0x1E
    ctx->r2 = ADD32(ctx->r30, 0X1E);
    // j           L_80038A8C
    // sw          $v0, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sw          $v0, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = ctx->r2;
L_80038A30:
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // j           L_80038A8C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80038A3C:
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // j           L_80038A8C
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80038A48:
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // j           L_80038A8C
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
    goto L_80038A8C;
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
L_80038A5C:
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
L_80038A64:
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // j           L_800389E4
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
    goto L_800389E4;
    // sb          $v0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r2;
L_80038A70:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_9;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_9:
L_80038A8C:
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // ori         $v0, $zero, 0xA3
    ctx->r2 = 0 | 0XA3;
    // bne         $v1, $v0, L_80038AA0
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80038AA0;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_80038AA0:
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // addiu       $s5, $s5, 0x18
    ctx->r21 = ADD32(ctx->r21, 0X18);
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s7, $v0, L_80038360
    if (ctx->r23 != ctx->r2) {
        // addiu       $s2, $s2, 0x44
        ctx->r18 = ADD32(ctx->r18, 0X44);
        goto L_80038360;
    }
    // addiu       $s2, $s2, 0x44
    ctx->r18 = ADD32(ctx->r18, 0X44);
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
