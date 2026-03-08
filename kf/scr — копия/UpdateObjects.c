#include "recomp.h"
#include "disable_warnings.h"

void UpdateObjects(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("UpdateObjects\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // addiu       $s4, $s4, -0x6810
    ctx->r20 = ADD32(ctx->r20, -0X6810);
    // ori         $t1, $zero, 0x18C
    ctx->r9 = 0 | 0X18C;
    // sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // ori         $s6, $zero, 0xFF
    ctx->r22 = 0 | 0XFF;
    // sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    // sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // addiu       $s7, $s7, -0x4A64
    ctx->r23 = ADD32(ctx->r23, -0X4A64);
    // sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // ori         $fp, $zero, 0x2
    ctx->r30 = 0 | 0X2;
    // sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // addiu       $s1, $s4, 0xA
    ctx->r17 = ADD32(ctx->r20, 0XA);
    // sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
L_8003999C:
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // nop

    // beq         $v0, $s6, L_8003B6F4
    if (ctx->r2 == ctx->r22) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $s4, 0x128($at)
    MEM_W(0X128, ctx->r1) = ctx->r20;
    // lhu         $v1, -0x4($s1)
    ctx->r3 = MEM_HU(-0X4, ctx->r17);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $s3, 0x124($at)
    MEM_W(0X124, ctx->r1) = ctx->r19;
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // nop

    // addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // sltiu       $v0, $v1, 0xE0
    ctx->r2 = ctx->r3 < 0XE0 ? 1 : 0;
    // beq         $v0, $zero, L_8003B6D8
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003B6D8;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1A18
    ctx->r1 = ADD32(ctx->r1, 0X1A18);
    // addu        $at, $at, $v0
    gpr jr_addend_80039A08;
    jr_addend_80039A08 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80039A08 >> 2) {
        case 0: goto L_80039A10; break;
        case 1: goto L_80039B70; break;
        case 2: goto L_80039DC4; break;
        case 3: goto L_8003A338; break;
        case 4: goto L_8003B6D8; break;
        case 5: goto L_8003B6D8; break;
        case 6: goto L_8003A0A0; break;
        case 7: goto L_8003AB80; break;
        case 8: goto L_8003B6D8; break;
        case 9: goto L_8003B6D8; break;
        case 10: goto L_8003B6D8; break;
        case 11: goto L_8003B6D8; break;
        case 12: goto L_8003B6D8; break;
        case 13: goto L_8003AEC4; break;
        case 14: goto L_8003A8EC; break;
        case 15: goto L_8003AF80; break;
        case 16: goto L_8003B04C; break;
        case 17: goto L_8003B080; break;
        case 18: goto L_8003B6D8; break;
        case 19: goto L_8003B6D8; break;
        case 20: goto L_8003A19C; break;
        case 21: goto L_8003B6D8; break;
        case 22: goto L_8003B6D8; break;
        case 23: goto L_8003B6D8; break;
        case 24: goto L_8003B6D8; break;
        case 25: goto L_8003B6D8; break;
        case 26: goto L_8003B6D8; break;
        case 27: goto L_8003B6D8; break;
        case 28: goto L_8003B6D8; break;
        case 29: goto L_8003B6D8; break;
        case 30: goto L_8003B6D8; break;
        case 31: goto L_8003B6D8; break;
        case 32: goto L_8003B580; break;
        case 33: goto L_8003B6D8; break;
        case 34: goto L_8003B6D8; break;
        case 35: goto L_8003B6D8; break;
        case 36: goto L_8003B6D8; break;
        case 37: goto L_8003B6D8; break;
        case 38: goto L_8003B6D8; break;
        case 39: goto L_8003B6D8; break;
        case 40: goto L_8003B6D8; break;
        case 41: goto L_8003B6D8; break;
        case 42: goto L_8003B6D8; break;
        case 43: goto L_8003B6D8; break;
        case 44: goto L_8003B6D8; break;
        case 45: goto L_8003B6D8; break;
        case 46: goto L_8003B6D8; break;
        case 47: goto L_8003B6D8; break;
        case 48: goto L_8003B6D8; break;
        case 49: goto L_8003B6D8; break;
        case 50: goto L_8003B6D8; break;
        case 51: goto L_8003B6D8; break;
        case 52: goto L_8003B6D8; break;
        case 53: goto L_8003B6D8; break;
        case 54: goto L_8003B6D8; break;
        case 55: goto L_8003B6D8; break;
        case 56: goto L_8003B6D8; break;
        case 57: goto L_8003B6D8; break;
        case 58: goto L_8003B6D8; break;
        case 59: goto L_8003B6D8; break;
        case 60: goto L_8003B6D8; break;
        case 61: goto L_8003B6D8; break;
        case 62: goto L_8003B6D8; break;
        case 63: goto L_8003B6D8; break;
        case 64: goto L_8003B6D8; break;
        case 65: goto L_8003B6D8; break;
        case 66: goto L_8003B6D8; break;
        case 67: goto L_8003B6D8; break;
        case 68: goto L_8003B6D8; break;
        case 69: goto L_8003B6D8; break;
        case 70: goto L_8003B6D8; break;
        case 71: goto L_8003B6D8; break;
        case 72: goto L_8003B6D8; break;
        case 73: goto L_8003B6D8; break;
        case 74: goto L_8003B6D8; break;
        case 75: goto L_8003B6D8; break;
        case 76: goto L_8003B6D8; break;
        case 77: goto L_8003B6D8; break;
        case 78: goto L_8003B6D8; break;
        case 79: goto L_8003ABC4; break;
        case 80: goto L_8003B6D8; break;
        case 81: goto L_8003A46C; break;
        case 82: goto L_8003A91C; break;
        case 83: goto L_8003B6D8; break;
        case 84: goto L_8003B6D8; break;
        case 85: goto L_8003B6D8; break;
        case 86: goto L_8003A5F0; break;
        case 87: goto L_8003A72C; break;
        case 88: goto L_8003B6D8; break;
        case 89: goto L_8003B6D8; break;
        case 90: goto L_8003B6D8; break;
        case 91: goto L_8003B6D8; break;
        case 92: goto L_8003B6D8; break;
        case 93: goto L_8003B6D8; break;
        case 94: goto L_8003B200; break;
        case 95: goto L_8003B2D8; break;
        case 96: goto L_8003B360; break;
        case 97: goto L_8003B6D8; break;
        case 98: goto L_8003B6D8; break;
        case 99: goto L_8003B6D8; break;
        case 100: goto L_8003B6D8; break;
        case 101: goto L_8003B6D8; break;
        case 102: goto L_8003B6D8; break;
        case 103: goto L_8003B6D8; break;
        case 104: goto L_8003B6D8; break;
        case 105: goto L_8003B6D8; break;
        case 106: goto L_8003B6D8; break;
        case 107: goto L_8003B6D8; break;
        case 108: goto L_8003B6D8; break;
        case 109: goto L_8003B6D8; break;
        case 110: goto L_8003B6D8; break;
        case 111: goto L_8003B6D8; break;
        case 112: goto L_8003B6D8; break;
        case 113: goto L_8003B6D8; break;
        case 114: goto L_8003B6D8; break;
        case 115: goto L_8003B6D8; break;
        case 116: goto L_8003B6D8; break;
        case 117: goto L_8003B6D8; break;
        case 118: goto L_8003B6D8; break;
        case 119: goto L_8003B6D8; break;
        case 120: goto L_8003B6D8; break;
        case 121: goto L_8003B6D8; break;
        case 122: goto L_8003B6D8; break;
        case 123: goto L_8003B6D8; break;
        case 124: goto L_8003B6D8; break;
        case 125: goto L_8003B6D8; break;
        case 126: goto L_8003B6D8; break;
        case 127: goto L_8003B6D8; break;
        case 128: goto L_8003B6D8; break;
        case 129: goto L_8003B6D8; break;
        case 130: goto L_8003B6D8; break;
        case 131: goto L_8003B6D8; break;
        case 132: goto L_8003B6D8; break;
        case 133: goto L_8003B6D8; break;
        case 134: goto L_8003B6D8; break;
        case 135: goto L_8003B6D8; break;
        case 136: goto L_8003B6D8; break;
        case 137: goto L_8003B6D8; break;
        case 138: goto L_8003B6D8; break;
        case 139: goto L_8003B6D8; break;
        case 140: goto L_8003B6D8; break;
        case 141: goto L_8003B6D8; break;
        case 142: goto L_8003B6D8; break;
        case 143: goto L_8003B6D8; break;
        case 144: goto L_8003B6D8; break;
        case 145: goto L_8003B6D8; break;
        case 146: goto L_8003B6D8; break;
        case 147: goto L_8003B6D8; break;
        case 148: goto L_8003B6D8; break;
        case 149: goto L_8003B6D8; break;
        case 150: goto L_8003B6D8; break;
        case 151: goto L_8003B6D8; break;
        case 152: goto L_8003B6D8; break;
        case 153: goto L_8003B6D8; break;
        case 154: goto L_8003B6D8; break;
        case 155: goto L_8003B6D8; break;
        case 156: goto L_8003B6D8; break;
        case 157: goto L_8003B6D8; break;
        case 158: goto L_8003B6D8; break;
        case 159: goto L_8003B6D8; break;
        case 160: goto L_8003B6D8; break;
        case 161: goto L_8003B6D8; break;
        case 162: goto L_8003B6D8; break;
        case 163: goto L_8003B6D8; break;
        case 164: goto L_8003B6D8; break;
        case 165: goto L_8003B6D8; break;
        case 166: goto L_8003B6D8; break;
        case 167: goto L_8003B6D8; break;
        case 168: goto L_8003B6D8; break;
        case 169: goto L_8003B6D8; break;
        case 170: goto L_8003B6D8; break;
        case 171: goto L_8003B6D8; break;
        case 172: goto L_8003B6D8; break;
        case 173: goto L_8003B6D8; break;
        case 174: goto L_8003B6D8; break;
        case 175: goto L_8003B6D8; break;
        case 176: goto L_8003B6D8; break;
        case 177: goto L_8003B6D8; break;
        case 178: goto L_8003B6D8; break;
        case 179: goto L_8003B6D8; break;
        case 180: goto L_8003B6D8; break;
        case 181: goto L_8003B6D8; break;
        case 182: goto L_8003B6D8; break;
        case 183: goto L_8003B6D8; break;
        case 184: goto L_8003B6D8; break;
        case 185: goto L_8003B6D8; break;
        case 186: goto L_8003B6D8; break;
        case 187: goto L_8003B6D8; break;
        case 188: goto L_8003B6D8; break;
        case 189: goto L_8003B6D8; break;
        case 190: goto L_8003B6D8; break;
        case 191: goto L_8003B6D8; break;
        case 192: goto L_8003B6D8; break;
        case 193: goto L_8003B6D8; break;
        case 194: goto L_8003B6D8; break;
        case 195: goto L_8003B6D8; break;
        case 196: goto L_8003B6D8; break;
        case 197: goto L_8003B6D8; break;
        case 198: goto L_8003B6D8; break;
        case 199: goto L_8003B6D8; break;
        case 200: goto L_8003B6D8; break;
        case 201: goto L_8003B6D8; break;
        case 202: goto L_8003B6D8; break;
        case 203: goto L_8003B6D8; break;
        case 204: goto L_8003B6D8; break;
        case 205: goto L_8003B6D8; break;
        case 206: goto L_8003B6D8; break;
        case 207: goto L_8003B6D8; break;
        case 208: goto L_8003B6D8; break;
        case 209: goto L_8003B6D8; break;
        case 210: goto L_8003B6D8; break;
        case 211: goto L_8003B6D8; break;
        case 212: goto L_8003B6D8; break;
        case 213: goto L_8003B6D8; break;
        case 214: goto L_8003B6D8; break;
        case 215: goto L_8003B6D8; break;
        case 216: goto L_8003B6D8; break;
        case 217: goto L_8003B6D8; break;
        case 218: goto L_8003B6D8; break;
        case 219: goto L_8003B6D8; break;
        case 220: goto L_8003B6D8; break;
        case 221: goto L_8003B6D8; break;
        case 222: goto L_8003AB10; break;
        case 223: goto L_8003B48C; break;
        default: switch_error(__func__, 0x80039A08, 0x80011A18);
    }
    // nop

L_80039A10:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_80039A54
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80039A54;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80039A38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039A38;
    }
    // nop

    // beq         $v1, $zero, L_8003B6F4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003AAFC
    // nop

    goto L_8003AAFC;
    // nop

L_80039A38:
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // beq         $v1, $v0, L_80039ADC
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x15
        ctx->r2 = 0 | 0X15;
        goto L_80039ADC;
    }
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // beq         $v1, $v0, L_80039B48
    if (ctx->r3 == ctx->r2) {
        // ori         $v1, $zero, 0xFFB8
        ctx->r3 = 0 | 0XFFB8;
        goto L_80039B48;
    }
    // ori         $v1, $zero, 0xFFB8
    ctx->r3 = 0 | 0XFFB8;
    // j           L_8003AAFC
    // nop

    goto L_8003AAFC;
    // nop

L_80039A54:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80039A70
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80039A70;
    }
    // nop

    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_0;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_0:
L_80039A70:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xC18
    ctx->r2 = 0 | 0XC18;
    // bne         $v1, $v0, L_80039ABC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80039ABC;
    }
    // nop

    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lh          $a3, 0x1C($s1)
    ctx->r7 = MEM_H(0X1C, ctx->r17);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0xC50
    ctx->r2 = ADD32(ctx->r2, -0XC50);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // lw          $a1, 0xA($s1)
    ctx->r5 = MEM_W(0XA, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x80037A1C
    // nop

    Map_ApplyBlueprint(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80039ABC:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sh          $fp, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r30;
    goto L_8003B6F4;
    // sh          $fp, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r30;
L_80039ADC:
    // ori         $v0, $zero, 0xC80
    ctx->r2 = 0 | 0XC80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC0
    ctx->r2 = 0 | 0XC0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0xE($s1)
    ctx->r5 = MEM_W(0XE, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x700
    ctx->r7 = 0 | 0X700;
    sub_8002E4F4(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0x700
    ctx->r7 = 0 | 0X700;
    after_2:
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lh          $a3, 0x1C($s1)
    ctx->r7 = MEM_H(0X1C, ctx->r17);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0xC50
    ctx->r2 = ADD32(ctx->r2, -0XC50);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // lw          $a1, 0xA($s1)
    ctx->r5 = MEM_W(0XA, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x80037A1C
    // nop

    Map_ApplyBlueprint(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // j           L_8003AC8C
    // nop

    goto L_8003AC8C;
    // nop

L_80039B48:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_80039B68:
    // j           L_8003B6F4
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    goto L_8003B6F4;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
L_80039B70:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_80039BE0
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80039BE0;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80039B98
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039B98;
    }
    // nop

    // beq         $v1, $zero, L_80039BB4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80039BB4;
    }
    // nop

    // j           L_8003AAFC
    // nop

    goto L_8003AAFC;
    // nop

L_80039B98:
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // beq         $v1, $v0, L_80039CC4
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x15
        ctx->r2 = 0 | 0X15;
        goto L_80039CC4;
    }
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // beq         $v1, $v0, L_80039D6C
    if (ctx->r3 == ctx->r2) {
        // ori         $v1, $zero, 0xFFB8
        ctx->r3 = 0 | 0XFFB8;
        goto L_80039D6C;
    }
    // ori         $v1, $zero, 0xFFB8
    ctx->r3 = 0 | 0XFFB8;
    // j           L_8003AAFC
    // nop

    goto L_8003AAFC;
    // nop

L_80039BB4:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // addiu       $v0, $v1, 0x6A
    ctx->r2 = ADD32(ctx->r3, 0X6A);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x31
    ctx->r2 = ctx->r2 < 0X31 ? 1 : 0;
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
        goto L_8003B6F4;
    }
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003B6F4
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    goto L_8003B6F4;
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
L_80039BE0:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80039C44
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80039C44;
    }
    // nop

    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $v1, 0x31($s1)
    ctx->r3 = MEM_BU(0X31, ctx->r17);
    // lbu         $a1, 0xD($s3)
    ctx->r5 = MEM_BU(0XD, ctx->r19);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xD($s3)
    ctx->r2 = MEM_BU(0XD, ctx->r19);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xE($s3)
    ctx->r2 = MEM_BU(0XE, ctx->r19);
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $v1, 0x1C($s1)
    ctx->r3 = MEM_H(0X1C, ctx->r17);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80037C0C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_4;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_5;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_5:
L_80039C44:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xC18
    ctx->r2 = 0 | 0XC18;
    // bne         $v1, $v0, L_80039CA8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80039CA8;
    }
    // nop

    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $a1, 0x31($s1)
    ctx->r5 = MEM_BU(0X31, ctx->r17);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xD($s3)
    ctx->r2 = MEM_BU(0XD, ctx->r19);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xE($s3)
    ctx->r2 = MEM_BU(0XE, ctx->r19);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $v1, 0x1C($s1)
    ctx->r3 = MEM_H(0X1C, ctx->r17);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80037C0C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_6;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
L_80039CA8:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // j           L_8003B1DC
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8003B1DC;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80039CC4:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // addiu       $v0, $v1, 0x6A
    ctx->r2 = ADD32(ctx->r3, 0X6A);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x31
    ctx->r2 = ctx->r2 < 0X31 ? 1 : 0;
    // beq         $v0, $zero, L_80039CE8
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
        goto L_80039CE8;
    }
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

L_80039CE8:
    // ori         $v0, $zero, 0xC80
    ctx->r2 = 0 | 0XC80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC0
    ctx->r2 = 0 | 0XC0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0xE($s1)
    ctx->r5 = MEM_W(0XE, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x1130
    ctx->r7 = 0 | 0X1130;
    sub_8002E4F4(rdram, ctx);
    goto after_7;
    // ori         $a3, $zero, 0x1130
    ctx->r7 = 0 | 0X1130;
    after_7:
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x15
        ctx->r2 = 0 | 0X15;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $v1, 0x31($s1)
    ctx->r3 = MEM_BU(0X31, ctx->r17);
    // lbu         $a1, 0xD($s3)
    ctx->r5 = MEM_BU(0XD, ctx->r19);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xD($s3)
    ctx->r2 = MEM_BU(0XD, ctx->r19);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xE($s3)
    ctx->r2 = MEM_BU(0XE, ctx->r19);
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $v1, 0x1C($s1)
    ctx->r3 = MEM_H(0X1C, ctx->r17);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80037C0C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_8;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_8:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // j           L_8003AC8C
    // nop

    goto L_8003AC8C;
    // nop

L_80039D6C:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $a1, 0xD($s3)
    ctx->r5 = MEM_BU(0XD, ctx->r19);
    // lbu         $v1, 0x31($s1)
    ctx->r3 = MEM_BU(0X31, ctx->r17);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xD($s3)
    ctx->r2 = MEM_BU(0XD, ctx->r19);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xE($s3)
    ctx->r2 = MEM_BU(0XE, ctx->r19);
    // j           L_8003A6DC
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    goto L_8003A6DC;
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
L_80039DC4:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $v0, -0x7($s1)
    ctx->r2 = MEM_BU(-0X7, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80039E28
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039E28;
    }
    // nop

    // lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(0X0, ctx->r23);
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $v0, 0x8($s7)
    ctx->r2 = MEM_W(0X8, ctx->r23);
    // lw          $a1, 0x12($s1)
    ctx->r5 = MEM_W(0X12, ctx->r17);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_9;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_9:
    // lhu         $v1, 0x38($s1)
    ctx->r3 = MEM_HU(0X38, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80039E24
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0xC8
        ctx->r2 = ADD32(0, -0XC8);
        goto L_80039E24;
    }
    // addiu       $v0, $zero, -0xC8
    ctx->r2 = ADD32(0, -0XC8);
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
L_80039E24:
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_80039E28:
    // lbu         $v1, 0x33($s1)
    ctx->r3 = MEM_BU(0X33, ctx->r17);
    // nop

    // beq         $v1, $s6, L_80039EAC
    if (ctx->r3 == ctx->r22) {
        // sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3) << 4;
        goto L_80039EAC;
    }
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(0X3, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80039EB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039EB0;
    }
    // nop

    // lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(0X0, ctx->r23);
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // lw          $v0, 0x8($s7)
    ctx->r2 = MEM_W(0X8, ctx->r23);
    // lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(0X1C, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_10;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_10:
    // lhu         $v1, 0x38($s1)
    ctx->r3 = MEM_HU(0X38, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80039EA0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80039EA0;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // j           L_80039EB0
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_80039EB0;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80039EA0:
    // addiu       $v0, $zero, -0xC8
    ctx->r2 = ADD32(0, -0XC8);
    // j           L_80039EB0
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_80039EB0;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80039EAC:
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80039EB0:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // bne         $v0, $s5, L_80039ED4
    if (ctx->r2 != ctx->r21) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80039ED4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // sh          $zero, 0x36($s1)
    MEM_H(0X36, ctx->r17) = 0;
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_11;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_11:
L_80039ED4:
    // lhu         $v0, 0x36($s1)
    ctx->r2 = MEM_HU(0X36, ctx->r17);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r3;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_80039F70
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x81
        ctx->r4 = 0 | 0X81;
        goto L_80039F70;
    }
    // ori         $a0, $zero, 0x81
    ctx->r4 = 0 | 0X81;
    // lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(0X1C, ctx->r17);
    // sb          $a0, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r4;
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // beq         $s2, $zero, L_80039F1C
    if (ctx->r18 == 0) {
        // sh          $v0, 0x1C($s1)
        MEM_H(0X1C, ctx->r17) = ctx->r2;
        goto L_80039F1C;
    }
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // sb          $a0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r4;
    // addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_80039F1C:
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // bne         $v1, $v0, L_80039F60
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1F
        ctx->r2 = 0 | 0X1F;
        goto L_80039F60;
    }
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $a1, 0x31($s1)
    ctx->r5 = MEM_BU(0X31, ctx->r17);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(0X30, ctx->r17);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80037C0C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_12;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_12:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_80039F60:
    // bne         $v1, $v0, L_8003B6F4
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x118
        ctx->r2 = 0 | 0X118;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x118
    ctx->r2 = 0 | 0X118;
    // j           L_8003B6F4
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
L_80039F70:
    // slti        $v0, $v1, 0x12C
    ctx->r2 = SIGNED(ctx->r3) < 0X12C ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x14C
        ctx->r2 = SIGNED(ctx->r3) < 0X14C ? 1 : 0;
        goto L_8003B6F4;
    }
    // slti        $v0, $v1, 0x14C
    ctx->r2 = SIGNED(ctx->r3) < 0X14C ? 1 : 0;
    // beq         $v0, $zero, L_8003A07C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x12C
        ctx->r2 = 0 | 0X12C;
        goto L_8003A07C;
    }
    // ori         $v0, $zero, 0x12C
    ctx->r2 = 0 | 0X12C;
    // bne         $v1, $v0, L_8003A054
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, -0x700
        ctx->r2 = ADD32(0, -0X700);
        goto L_8003A054;
    }
    // addiu       $v0, $zero, -0x700
    ctx->r2 = ADD32(0, -0X700);
    // addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    // sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // lh          $a0, 0x38($s1)
    ctx->r4 = MEM_H(0X38, ctx->r17);
    // jal         0x80015378
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015378(rdram, ctx);
    goto after_13;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_13:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // jal         0x8005DF04
    // addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    KF_ApplyMatrix(rdram, ctx);
    goto after_14;
    // addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_14:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // lw          $v1, 0xA($s1)
    ctx->r3 = MEM_W(0XA, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // lw          $v1, 0x12($s1)
    ctx->r3 = MEM_W(0X12, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(0X2, ctx->r17);
    // ori         $v0, $zero, 0xC0
    ctx->r2 = 0 | 0XC0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(0X48, ctx->r29);
    // lw          $a1, 0xE($s1)
    ctx->r5 = MEM_W(0XE, ctx->r17);
    // lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(0X50, ctx->r29);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0xBB8
    ctx->r7 = 0 | 0XBB8;
    sub_8002E4F4(rdram, ctx);
    goto after_15;
    // ori         $a3, $zero, 0xBB8
    ctx->r7 = 0 | 0XBB8;
    after_15:
    // beq         $v0, $zero, L_8003A014
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x12C
        ctx->r2 = 0 | 0X12C;
        goto L_8003A014;
    }
    // ori         $v0, $zero, 0x12C
    ctx->r2 = 0 | 0X12C;
    // j           L_8003B6F4
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
L_8003A014:
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $a1, 0x31($s1)
    ctx->r5 = MEM_BU(0X31, ctx->r17);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(0X30, ctx->r17);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
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
    goto after_16;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_16:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_17;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_17:
L_8003A054:
    // lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(0X1C, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // beq         $s2, $zero, L_8003B6F4
    if (ctx->r18 == 0) {
        // sh          $v0, 0x1C($s1)
        MEM_H(0X1C, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x26($s2)
    ctx->r2 = MEM_HU(0X26, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // j           L_8003B6F4
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_8003A07C:
    // ori         $v1, $zero, 0x80
    ctx->r3 = 0 | 0X80;
    // addiu       $v0, $zero, -0x32
    ctx->r2 = ADD32(0, -0X32);
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // sb          $v1, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r3;
    // beq         $s2, $zero, L_8003B6F4
    if (ctx->r18 == 0) {
        // sh          $v0, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    // sb          $v1, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r3;
    // j           L_8003B6F4
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_8003A0A0:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_8003A0F8
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003A0F8;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003A0C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A0C8;
    }
    // nop

    // beq         $v1, $zero, L_8003A0D8
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_8003A0D8;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A0C8:
    // beq         $v1, $fp, L_8003A130
    if (ctx->r3 == ctx->r30) {
        // ori         $a0, $zero, 0xA00
        ctx->r4 = 0 | 0XA00;
        goto L_8003A130;
    }
    // ori         $a0, $zero, 0xA00
    ctx->r4 = 0 | 0XA00;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A0D8:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8003A244
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xA00
        ctx->r2 = 0 | 0XA00;
        goto L_8003A244;
    }
    // ori         $v0, $zero, 0xA00
    ctx->r2 = 0 | 0XA00;
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sh          $t1, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r9;
    goto L_8003B6F4;
    // sh          $t1, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r9;
L_8003A0F8:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_8003B6F4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, -0x10
        ctx->r2 = ADD32(0, -0X10);
        goto L_8003B6F4;
    }
    // addiu       $v0, $zero, -0x10
    ctx->r2 = ADD32(0, -0X10);
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lbu         $a2, 0x0($s4)
    ctx->r6 = MEM_BU(0X0, ctx->r20);
    // jal         0x8003804C
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    sub_8003804C(rdram, ctx);
    goto after_18;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_18:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // j           L_8003AC8C
    // nop

    goto L_8003AC8C;
    // nop

L_8003A130:
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    // lh          $a1, 0x1A($s1)
    ctx->r5 = MEM_H(0X1A, ctx->r17);
    // lh          $a2, 0x36($s1)
    ctx->r6 = MEM_H(0X36, ctx->r17);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // jal         0x80014ED4
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80014ED4(rdram, ctx);
    goto after_19;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_19:
    // lhu         $v1, 0x1A($s1)
    ctx->r3 = MEM_HU(0X1A, ctx->r17);
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sh          $v1, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r3;
    // slti        $v1, $v1, 0xC00
    ctx->r3 = SIGNED(ctx->r3) < 0XC00 ? 1 : 0;
    // beq         $v1, $zero, L_8003A174
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8003A174;
    }
    // nop

    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // jal         0x8003804C
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    sub_8003804C(rdram, ctx);
    goto after_20;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    after_20:
L_8003A174:
    // lh          $v0, 0x36($s1)
    ctx->r2 = MEM_H(0X36, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xA00
        ctx->r2 = 0 | 0XA00;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0xA00
    ctx->r2 = 0 | 0XA00;
    // lh          $v1, 0x1A($s1)
    ctx->r3 = MEM_H(0X1A, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8003B6F4
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_8003A464
    // nop

    goto L_8003A464;
    // nop

L_8003A19C:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_8003A268
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003A268;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003A1C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A1C4;
    }
    // nop

    // beq         $v1, $zero, L_8003A1DC
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_8003A1DC;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A1C4:
    // beq         $v1, $fp, L_8003A2A0
    if (ctx->r3 == ctx->r30) {
        // ori         $t1, $zero, 0x3
        ctx->r9 = 0 | 0X3;
        goto L_8003A2A0;
    }
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // beq         $v1, $t1, L_8003A30C
    if (ctx->r3 == ctx->r9) {
        // ori         $a1, $zero, 0xD44
        ctx->r5 = 0 | 0XD44;
        goto L_8003A30C;
    }
    // ori         $a1, $zero, 0xD44
    ctx->r5 = 0 | 0XD44;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A1DC:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8003A244
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $sp, 0x40
        ctx->r5 = ADD32(ctx->r29, 0X40);
        goto L_8003A244;
    }
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // lhu         $a0, 0x1C($s1)
    ctx->r4 = MEM_HU(0X1C, ctx->r17);
    // ori         $v0, $zero, 0xD44
    ctx->r2 = 0 | 0XD44;
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80014FAC
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80014FAC(rdram, ctx);
    goto after_21;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_21:
    // ori         $a0, $zero, 0xA0
    ctx->r4 = 0 | 0XA0;
    // jal         0x8001565C
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    sub_8001565C(rdram, ctx);
    goto after_22;
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_22:
    // lw          $v0, 0xA($s1)
    ctx->r2 = MEM_W(0XA, ctx->r17);
    // lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(0X40, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x12($s1)
    ctx->r3 = MEM_W(0X12, ctx->r17);
    // sw          $v0, 0xA($s1)
    MEM_W(0XA, ctx->r17) = ctx->r2;
    // lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(0X44, ctx->r29);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // j           L_8003B6F4
    // sw          $v1, 0x12($s1)
    MEM_W(0X12, ctx->r17) = ctx->r3;
    goto L_8003B6F4;
    // sw          $v1, 0x12($s1)
    MEM_W(0X12, ctx->r17) = ctx->r3;
L_8003A244:
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // jal         0x8003804C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003804C(rdram, ctx);
    goto after_23;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_23:
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // jal         0x8003804C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003804C(rdram, ctx);
    goto after_24;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_24:
    // j           L_8003B6F4
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    goto L_8003B6F4;
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
L_8003A268:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_8003B6F4
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lbu         $a2, 0x0($s4)
    ctx->r6 = MEM_BU(0X0, ctx->r20);
    // jal         0x8003804C
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    sub_8003804C(rdram, ctx);
    goto after_25;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_25:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // j           L_8003AC8C
    // nop

    goto L_8003AC8C;
    // nop

L_8003A2A0:
    // addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // lhu         $a0, 0x1C($s1)
    ctx->r4 = MEM_HU(0X1C, ctx->r17);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80014FAC
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80014FAC(rdram, ctx);
    goto after_26;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_26:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // jal         0x8001565C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8001565C(rdram, ctx);
    goto after_27;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_27:
    // lw          $v0, 0xA($s1)
    ctx->r2 = MEM_W(0XA, ctx->r17);
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x12($s1)
    ctx->r3 = MEM_W(0X12, ctx->r17);
    // sw          $v0, 0xA($s1)
    MEM_W(0XA, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x36($s1)
    ctx->r2 = MEM_HU(0X36, ctx->r17);
    // lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(0X4C, ctx->r29);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // sw          $v1, 0x12($s1)
        MEM_W(0X12, ctx->r17) = ctx->r3;
        goto L_8003B6F4;
    }
    // sw          $v1, 0x12($s1)
    MEM_W(0X12, ctx->r17) = ctx->r3;
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // j           L_8003A458
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    goto L_8003A458;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
L_8003A30C:
    // lh          $a0, 0x1A($s1)
    ctx->r4 = MEM_H(0X1A, ctx->r17);
    // jal         0x80014C84
    // ori         $a2, $zero, 0x32
    ctx->r6 = 0 | 0X32;
    sub_80014C84(rdram, ctx);
    goto after_28;
    // ori         $a2, $zero, 0x32
    ctx->r6 = 0 | 0X32;
    after_28:
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // ori         $v1, $zero, 0xD44
    ctx->r3 = 0 | 0XD44;
    // bne         $v0, $v1, L_8003B6F4
    if (ctx->r2 != ctx->r3) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // j           L_8003A588
    // nop

    goto L_8003A588;
    // nop

L_8003A338:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_8003A3E0
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003A3E0;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003A360
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A360;
    }
    // nop

    // beq         $v1, $zero, L_8003A370
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8003A370;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A360:
    // beq         $v1, $fp, L_8003A428
    if (ctx->r3 == ctx->r30) {
        // nop
    
        goto L_8003A428;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A370:
    // lhu         $v1, 0x30($s1)
    ctx->r3 = MEM_HU(0X30, ctx->r17);
    // nop

    // beq         $v1, $v0, L_8003A3A4
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3) << 4;
        goto L_8003A3A4;
    }
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(0XE, ctx->r2);
    // nop

    // addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // sh          $v1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r3;
L_8003A3A4:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_8003A3CC
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8003A3CC;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lbu         $a2, 0xC($s3)
    ctx->r6 = MEM_BU(0XC, ctx->r19);
    // jal         0x80038120
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    sub_80038120(rdram, ctx);
    goto after_29;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_29:
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // j           L_8003A460
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8003A460;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003A3CC:
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // jal         0x8003804C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003804C(rdram, ctx);
    goto after_30;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_30:
    // j           L_8003B6F4
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    goto L_8003B6F4;
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
L_8003A3E0:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_8003B6F4
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lbu         $a2, 0x0($s4)
    ctx->r6 = MEM_BU(0X0, ctx->r20);
    // jal         0x8003804C
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    sub_8003804C(rdram, ctx);
    goto after_31;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_31:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_32;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_32:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lbu         $a2, 0xC($s3)
    ctx->r6 = MEM_BU(0XC, ctx->r19);
    // jal         0x80038120
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    sub_80038120(rdram, ctx);
    goto after_33;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_33:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A428:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $a1, $zero, 0x2
        ctx->r5 = 0 | 0X2;
        goto L_8003B6F4;
    }
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003A458:
    // jal         0x8003804C
    // nop

    sub_8003804C(rdram, ctx);
    goto after_34;
    // nop

    after_34:
L_8003A460:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
L_8003A464:
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003A46C:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003B6F4;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1D98
    ctx->r1 = ADD32(ctx->r1, 0X1D98);
    // addu        $at, $at, $v0
    gpr jr_addend_8003A498;
    jr_addend_8003A498 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003A498 >> 2) {
        case 0: goto L_8003A4A0; break;
        case 1: goto L_8003A508; break;
        case 2: goto L_8003A590; break;
        case 3: goto L_8003A5B4; break;
        case 4: goto L_8003B6F4; break;
        case 5: goto L_8003B6F4; break;
        case 6: goto L_8003B6F4; break;
        case 7: goto L_8003B6F4; break;
        case 8: goto L_8003A5D8; break;
        default: switch_error(__func__, 0x8003A498, 0x80011D98);
    }
    // nop

L_8003A4A0:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_35;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_35:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // beq         $v1, $fp, L_8003A4E4
    if (ctx->r3 == ctx->r30) {
        // slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
        goto L_8003A4E4;
    }
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8003A4D4
    if (ctx->r2 != 0) {
        // ori         $t1, $zero, 0x3
        ctx->r9 = 0 | 0X3;
        goto L_8003A4D4;
    }
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // beq         $v1, $t1, L_8003A4F8
    if (ctx->r3 == ctx->r9) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003A4F8;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A4D4:
    // bltz        $v1, L_8003B6F4
    if (SIGNED(ctx->r3) < 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_8003B1E0
    // nop

    goto L_8003B1E0;
    // nop

L_8003A4E4:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_8003B6F4
    // sb          $v0, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sb          $v0, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r2;
L_8003A4F8:
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_8003B6F4
    // sb          $v0, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sb          $v0, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r2;
L_8003A508:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003A530:
    // lbu         $a0, 0x2F($s1)
    ctx->r4 = MEM_BU(0X2F, ctx->r17);
    // jal         0x80039190
    // nop

    sub_80039190(rdram, ctx);
    goto after_36;
    // nop

    after_36:
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // beq         $v1, $s5, L_8003A578
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003A578;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003A564
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A564;
    }
    // nop

    // beq         $v1, $zero, L_8003B484
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x63
        ctx->r2 = 0 | 0X63;
        goto L_8003B484;
    }
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A564:
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003B6F4
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    goto L_8003B6F4;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
L_8003A578:
    // lbu         $a1, 0xF($s3)
    ctx->r5 = MEM_BU(0XF, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_37;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_37:
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
L_8003A588:
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003A590:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // ori         $v1, $zero, 0xFF00
    ctx->r3 = 0 | 0XFF00;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003A530
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    goto L_8003A530;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_8003A5B4:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // ori         $v1, $zero, 0xFF00
    ctx->r3 = 0 | 0XFF00;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0x63
        ctx->r2 = 0 | 0X63;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // j           L_8003B484
    // nop

    goto L_8003B484;
    // nop

L_8003A5D8:
    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // bne         $v0, $t1, L_80039B68
    if (ctx->r2 != ctx->r9) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_80039B68;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // j           L_80039B68
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_80039B68;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003A5F0:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $fp, L_8003A690
    if (ctx->r3 == ctx->r30) {
        // slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
        goto L_8003A690;
    }
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_8003A618
    if (ctx->r2 == 0) {
        // ori         $t1, $zero, 0x3
        ctx->r9 = 0 | 0X3;
        goto L_8003A618;
    }
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // beq         $v1, $s5, L_8003A628
    if (ctx->r3 == ctx->r21) {
        // nop
    
        goto L_8003A628;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A618:
    // beq         $v1, $t1, L_8003A700
    if (ctx->r3 == ctx->r9) {
        // nop
    
        goto L_8003A700;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A628:
    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8003A648
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A648;
    }
    // nop

    // beq         $v0, $s5, L_8003A64C
    if (ctx->r2 == ctx->r21) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003A64C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_8003A65C
    // nop

    goto L_8003A65C;
    // nop

L_8003A648:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8003A64C:
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80037F78
    // ori         $a1, $zero, 0x44
    ctx->r5 = 0 | 0X44;
    sub_80037F78(rdram, ctx);
    goto after_38;
    // ori         $a1, $zero, 0x44
    ctx->r5 = 0 | 0X44;
    after_38:
L_8003A65C:
    // lbu         $v0, 0x31($s1)
    ctx->r2 = MEM_BU(0X31, ctx->r17);
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $v1, 0x32($s1)
    ctx->r3 = MEM_BU(0X32, ctx->r17);
    // lbu         $a1, 0x34($s1)
    ctx->r5 = MEM_BU(0X34, ctx->r17);
    // lbu         $a2, 0x33($s1)
    ctx->r6 = MEM_BU(0X33, ctx->r17);
    // lbu         $a3, 0x30($s1)
    ctx->r7 = MEM_BU(0X30, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(0X34, ctx->r17);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x35($s1)
    ctx->r2 = MEM_BU(0X35, ctx->r17);
    // j           L_8003A6DC
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    goto L_8003A6DC;
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
L_8003A690:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // ori         $v1, $zero, 0xFFC0
    ctx->r3 = 0 | 0XFFC0;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0x63
        ctx->r2 = 0 | 0X63;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x31($s1)
    ctx->r2 = MEM_BU(0X31, ctx->r17);
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
    // lbu         $a1, 0x32($s1)
    ctx->r5 = MEM_BU(0X32, ctx->r17);
    // lbu         $a2, 0x33($s1)
    ctx->r6 = MEM_BU(0X33, ctx->r17);
    // lbu         $a3, 0x30($s1)
    ctx->r7 = MEM_BU(0X30, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(0X34, ctx->r17);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x35($s1)
    ctx->r2 = MEM_BU(0X35, ctx->r17);
L_8003A6DC:
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $v1, 0x1C($s1)
    ctx->r3 = MEM_H(0X1C, ctx->r17);
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x80037C0C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Map_CopyTileBlock(rdram, ctx);
    goto after_39;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_39:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A700:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // j           L_8003B480
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8003B480;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003A72C:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003B6F4;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1DC0
    ctx->r1 = ADD32(ctx->r1, 0X1DC0);
    // addu        $at, $at, $v0
    gpr jr_addend_8003A758;
    jr_addend_8003A758 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003A758 >> 2) {
        case 0: goto L_8003A760; break;
        case 1: goto L_8003A77C; break;
        case 2: goto L_8003A804; break;
        case 3: goto L_8003A834; break;
        case 4: goto L_8003A860; break;
        default: switch_error(__func__, 0x8003A758, 0x80011DC0);
    }
    // nop

L_8003A760:
    // lhu         $v0, 0x30($s1)
    ctx->r2 = MEM_HU(0X30, ctx->r17);
    // lbu         $a0, 0x38($s1)
    ctx->r4 = MEM_BU(0X38, ctx->r17);
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // sh          $v1, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r3;
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sb          $a0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r4;
    goto L_8003B6F4;
    // sb          $a0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r4;
L_8003A77C:
    // lhu         $v1, 0x36($s1)
    ctx->r3 = MEM_HU(0X36, ctx->r17);
    // nop

    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $zero, L_8003B6F4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x36($s1)
        MEM_H(0X36, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // lw          $v1, 0x12($s1)
    ctx->r3 = MEM_W(0X12, ctx->r17);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
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
    // lw          $v1, 0xA($s1)
    ctx->r3 = MEM_W(0XA, ctx->r17);
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
    // lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(0X0, ctx->r20);
    // nop

    // beq         $v1, $s5, L_8003A7E8
    if (ctx->r3 == ctx->r21) {
        // addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_8003A7E8;
    }
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_8003A7E8:
    // ori         $v0, $zero, 0x74
    ctx->r2 = 0 | 0X74;
    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80037F78
    // ori         $a1, $zero, 0xE3
    ctx->r5 = 0 | 0XE3;
    sub_80037F78(rdram, ctx);
    goto after_40;
    // ori         $a1, $zero, 0xE3
    ctx->r5 = 0 | 0XE3;
    after_40:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003A804:
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // ori         $v1, $zero, 0xFF00
    ctx->r3 = 0 | 0XFF00;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // lhu         $v1, 0x32($s1)
    ctx->r3 = MEM_HU(0X32, ctx->r17);
    // sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sh          $v1, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r3;
    goto L_8003B6F4;
    // sh          $v1, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r3;
L_8003A834:
    // lhu         $v1, 0x36($s1)
    ctx->r3 = MEM_HU(0X36, ctx->r17);
    // nop

    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $zero, L_8003B6F4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x36($s1)
        MEM_H(0X36, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80037F78
    // ori         $a1, $zero, 0xE3
    ctx->r5 = 0 | 0XE3;
    sub_80037F78(rdram, ctx);
    goto after_41;
    // ori         $a1, $zero, 0xE3
    ctx->r5 = 0 | 0XE3;
    after_41:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003A860:
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1000
        ctx->r2 = 0 | 0X1000;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // lw          $v1, 0x12($s1)
    ctx->r3 = MEM_W(0X12, ctx->r17);
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x428C
    ctx->r2 = ADD32(ctx->r2, -0X428C);
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
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
    // lw          $v1, 0xA($s1)
    ctx->r3 = MEM_W(0XA, ctx->r17);
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
    // lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(0X0, ctx->r20);
    // nop

    // beq         $v1, $s5, L_8003A8DC
    if (ctx->r3 == ctx->r21) {
        // addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_8003A8DC;
    }
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_8003A8DC:
    // ori         $v0, $zero, 0x75
    ctx->r2 = 0 | 0X75;
    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // j           L_8003B6F4
    // sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    goto L_8003B6F4;
    // sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8003A8EC:
    // lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(0X1C, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x800601F4
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    FixedSin(rdram, ctx);
    goto after_42;
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    after_42:
    // lw          $v1, 0x36($s1)
    ctx->r3 = MEM_W(0X36, ctx->r17);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8003B6F4
    // sw          $v0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sw          $v0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r2;
L_8003A91C:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_8003AA24
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003AA24;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003A944
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A944;
    }
    // nop

    // beq         $v1, $zero, L_8003A960
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8003A960;
    }
    // nop

    // j           L_8003AAFC
    // nop

    goto L_8003AAFC;
    // nop

L_8003A944:
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_8003AA6C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x63
        ctx->r2 = 0 | 0X63;
        goto L_8003AA6C;
    }
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // beq         $v1, $v0, L_8003B6F4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003AAFC
    // nop

    goto L_8003AAFC;
    // nop

L_8003A960:
    // lbu         $a2, 0x31($s1)
    ctx->r6 = MEM_BU(0X31, ctx->r17);
    // lbu         $v0, 0x2F($s1)
    ctx->r2 = MEM_BU(0X2F, ctx->r17);
    // lbu         $a3, 0x32($s1)
    ctx->r7 = MEM_BU(0X32, ctx->r17);
    // addiu       $a0, $a2, -0x1
    ctx->r4 = ADD32(ctx->r6, -0X1);
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    // lbu         $v0, 0x33($s1)
    ctx->r2 = MEM_BU(0X33, ctx->r17);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // jal         0x8003955C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003955C(rdram, ctx);
    goto after_43;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_43:
    // bne         $v0, $zero, L_8003A9B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003A9B8;
    }
    // nop

    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // nop

    // bne         $v0, $s6, L_8003B6F4
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

L_8003A9B8:
    // lbu         $a0, 0x36($s1)
    ctx->r4 = MEM_BU(0X36, ctx->r17);
    // lh          $a3, 0x1C($s1)
    ctx->r7 = MEM_H(0X1C, ctx->r17);
    // lbu         $v1, 0xE($s3)
    ctx->r3 = MEM_BU(0XE, ctx->r19);
    // lbu         $a1, 0x34($s1)
    ctx->r5 = MEM_BU(0X34, ctx->r17);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
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
    // lw          $a1, 0xA($s1)
    ctx->r5 = MEM_W(0XA, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x80037A1C
    // nop

    Map_ApplyBlueprint(rdram, ctx);
    goto after_44;
    // nop

    after_44:
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    // sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    // sh          $v0, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
L_8003AA24:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(0X34, ctx->r17);
    // sb          $s5, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r21;
    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8003B1DC
    if (ctx->r2 == 0) {
        // sh          $zero, 0x0($s1)
        MEM_H(0X0, ctx->r17) = 0;
        goto L_8003B1DC;
    }
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
    goto L_8003B6F4;
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
L_8003AA6C:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $a0, 0x36($s1)
    ctx->r4 = MEM_BU(0X36, ctx->r17);
    // lh          $a3, 0x1C($s1)
    ctx->r7 = MEM_H(0X1C, ctx->r17);
    // sb          $zero, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = 0;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // lbu         $v1, 0xE($s3)
    ctx->r3 = MEM_BU(0XE, ctx->r19);
    // lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(0X34, ctx->r17);
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
    // lw          $a1, 0xA($s1)
    ctx->r5 = MEM_W(0XA, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x80037A1C
    // nop

    Map_ApplyBlueprint(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // sh          $zero, 0x26($s1)
    MEM_H(0X26, ctx->r17) = 0;
    // sh          $zero, 0x24($s1)
    MEM_H(0X24, ctx->r17) = 0;
    // j           L_8003B6F4
    // sh          $zero, 0x22($s1)
    MEM_H(0X22, ctx->r17) = 0;
    goto L_8003B6F4;
    // sh          $zero, 0x22($s1)
    MEM_H(0X22, ctx->r17) = 0;
L_8003AAFC:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003AB10:
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0x12($s1)
    ctx->r5 = MEM_W(0X12, ctx->r17);
    // lbu         $a2, 0x2E($s1)
    ctx->r6 = MEM_BU(0X2E, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // jal         0x8003955C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003955C(rdram, ctx);
    goto after_46;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_46:
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(0X34, ctx->r17);
    // lbu         $a0, 0x30($s1)
    ctx->r4 = MEM_BU(0X30, ctx->r17);
    // lbu         $a1, 0x31($s1)
    ctx->r5 = MEM_BU(0X31, ctx->r17);
    // lbu         $a2, 0x32($s1)
    ctx->r6 = MEM_BU(0X32, ctx->r17);
    // lbu         $a3, 0x33($s1)
    ctx->r7 = MEM_BU(0X33, ctx->r17);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lb          $v0, 0x36($s1)
    ctx->r2 = MEM_B(0X36, ctx->r17);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lb          $v0, 0x37($s1)
    ctx->r2 = MEM_B(0X37, ctx->r17);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lb          $v0, 0x38($s1)
    ctx->r2 = MEM_B(0X38, ctx->r17);
    // jal         0x800166F8
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_800166F8(rdram, ctx);
    goto after_47;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_47:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003AB80:
    // lhu         $v1, 0x30($s1)
    ctx->r3 = MEM_HU(0X30, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8003ABBC
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3) << 4;
        goto L_8003ABBC;
    }
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // nop

    // beq         $v0, $s6, L_8003ABBC
    if (ctx->r2 == ctx->r22) {
        // nop
    
        goto L_8003ABBC;
    }
    // nop

    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // sb          $zero, 0x38($v1)
    MEM_B(0X38, ctx->r3) = 0;
L_8003ABBC:
    // j           L_8003B6F4
    // sb          $s6, -0x6($s1)
    MEM_B(-0X6, ctx->r17) = ctx->r22;
    goto L_8003B6F4;
    // sb          $s6, -0x6($s1)
    MEM_B(-0X6, ctx->r17) = ctx->r22;
L_8003ABC4:
    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v1, $s5, L_8003AC9C
    if (ctx->r3 == ctx->r21) {
        // sll         $s0, $v0, 2
        ctx->r16 = S32(ctx->r2) << 2;
        goto L_8003AC9C;
    }
    // sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2) << 2;
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003ABF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003ABF4;
    }
    // nop

    // beq         $v1, $zero, L_8003AC0C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8003AC0C;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003ABF4:
    // beq         $v1, $fp, L_8003AE4C
    if (ctx->r3 == ctx->r30) {
        // ori         $t1, $zero, 0x3
        ctx->r9 = 0 | 0X3;
        goto L_8003AE4C;
    }
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // beq         $v1, $t1, L_8003AE98
    if (ctx->r3 == ctx->r9) {
        // nop
    
        goto L_8003AE98;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003AC0C:
    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003AC38
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_8003AC38;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sb          $s5, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r21;
    // j           L_8003B6F4
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003AC38:
    // lbu         $a2, 0x31($s1)
    ctx->r6 = MEM_BU(0X31, ctx->r17);
    // nop

    // beq         $a2, $v0, L_8003B6F4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // beq         $a2, $s6, L_8003AC78
    if (ctx->r6 == ctx->r22) {
        // nop
    
        goto L_8003AC78;
    }
    // nop

    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0x12($s1)
    ctx->r5 = MEM_W(0X12, ctx->r17);
    // lbu         $a3, 0x32($s1)
    ctx->r7 = MEM_BU(0X32, ctx->r17);
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // jal         0x8003955C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003955C(rdram, ctx);
    goto after_48;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_48:
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

L_8003AC78:
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sb          $zero, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = 0;
    // sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    // lbu         $a1, 0x16($s3)
    ctx->r5 = MEM_BU(0X16, ctx->r19);
L_8003AC8C:
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_49;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_49:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003AC9C:
    // lbu         $v0, 0x31($s1)
    ctx->r2 = MEM_BU(0X31, ctx->r17);
    // nop

    // beq         $v0, $s6, L_8003ACF8
    if (ctx->r2 == ctx->r22) {
        // nop
    
        goto L_8003ACF8;
    }
    // nop

    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // bne         $v1, $zero, L_8003ACD8
    if (ctx->r3 != 0) {
        // sltiu       $v0, $v1, 0x5DC
        ctx->r2 = ctx->r3 < 0X5DC ? 1 : 0;
        goto L_8003ACD8;
    }
    // sltiu       $v0, $v1, 0x5DC
    ctx->r2 = ctx->r3 < 0X5DC ? 1 : 0;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lbu         $a2, 0x17($s3)
    ctx->r6 = MEM_BU(0X17, ctx->r19);
    // jal         0x80038120
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    sub_80038120(rdram, ctx);
    goto after_50;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_50:
    // lbu         $a1, 0x16($s3)
    ctx->r5 = MEM_BU(0X16, ctx->r19);
    // j           L_8003ACF0
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    goto L_8003ACF0;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
L_8003ACD8:
    // bne         $v0, $zero, L_8003ACF8
    if (ctx->r2 != 0) {
        // addiu       $v0, $s0, 0x5DC
        ctx->r2 = ADD32(ctx->r16, 0X5DC);
        goto L_8003ACF8;
    }
    // addiu       $v0, $s0, 0x5DC
    ctx->r2 = ADD32(ctx->r16, 0X5DC);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003ACF8
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8003ACF8;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // ori         $a1, $zero, 0x4E
    ctx->r5 = 0 | 0X4E;
L_8003ACF0:
    // jal         0x80037F78
    // nop

    sub_80037F78(rdram, ctx);
    goto after_51;
    // nop

    after_51:
L_8003ACF8:
    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003AD2C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1000
        ctx->r2 = 0 | 0X1000;
        goto L_8003AD2C;
    }
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8003AD2C
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003AD2C;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // j           L_8003B6F4
    // sb          $s5, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r21;
    goto L_8003B6F4;
    // sb          $s5, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r21;
L_8003AD2C:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003AD9C
    if (ctx->r2 != 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8003AD9C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lbu         $v0, 0x31($s1)
    ctx->r2 = MEM_BU(0X31, ctx->r17);
    // nop

    // beq         $v0, $s6, L_8003AD7C
    if (ctx->r2 == ctx->r22) {
        // nop
    
        goto L_8003AD7C;
    }
    // nop

    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // lbu         $a2, 0x17($s3)
    ctx->r6 = MEM_BU(0X17, ctx->r19);
    // jal         0x80038120
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80038120(rdram, ctx);
    goto after_52;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_52:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003AD7C:
    // lbu         $a1, 0x16($s3)
    ctx->r5 = MEM_BU(0X16, ctx->r19);
    // jal         0x80037F78
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80037F78(rdram, ctx);
    goto after_53;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_53:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
L_8003AD9C:
    // lhu         $a1, 0xC($s3)
    ctx->r5 = MEM_HU(0XC, ctx->r19);
    // jal         0x80039448
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    sub_80039448(rdram, ctx);
    goto after_54;
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_54:
    // lhu         $a3, 0xE($s3)
    ctx->r7 = MEM_HU(0XE, ctx->r19);
    // lhu         $v1, 0x10($s3)
    ctx->r3 = MEM_HU(0X10, ctx->r19);
    // ori         $v0, $zero, 0x90
    ctx->r2 = 0 | 0X90;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(0X40, ctx->r29);
    // lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(0X44, ctx->r29);
    // lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(0X48, ctx->r29);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_55;
    // nop

    after_55:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_8003B578
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8003B578;
    }
    // nop

    // lbu         $v0, 0x36($s1)
    ctx->r2 = MEM_BU(0X36, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $a1, $zero, 0x20
        ctx->r5 = 0 | 0X20;
        goto L_8003B6F4;
    }
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // lbu         $v0, 0x2F($s1)
    ctx->r2 = MEM_BU(0X2F, ctx->r17);
    // sb          $s5, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r21;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x12($s3)
    ctx->r2 = MEM_BU(0X12, ctx->r19);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x13($s3)
    ctx->r2 = MEM_BU(0X13, ctx->r19);
    // ori         $a2, $zero, 0x1388
    ctx->r6 = 0 | 0X1388;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x14($s3)
    ctx->r2 = MEM_BU(0X14, ctx->r19);
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x15($s3)
    ctx->r3 = MEM_BU(0X15, ctx->r19);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // jal         0x800425A0
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    sub_800425A0(rdram, ctx);
    goto after_56;
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_56:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003AE4C:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8003B6F4;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // bne         $v1, $s6, L_8003B6F4
    if (ctx->r3 != ctx->r22) {
        // sh          $v0, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, -0x9($s1)
    MEM_B(-0X9, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003AE98:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003B6F4
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    goto L_8003B6F4;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
L_8003AEC4:
    // lbu         $v1, 0x2F($s1)
    ctx->r3 = MEM_BU(0X2F, ctx->r17);
    // lhu         $a0, -0x2($s1)
    ctx->r4 = MEM_HU(-0X2, ctx->r17);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x320
    ctx->r3 = ADD32(ctx->r3, -0X320);
    // beq         $a0, $zero, L_8003AF54
    if (ctx->r4 == 0) {
        // addu        $a1, $v0, $v1
        ctx->r5 = ADD32(ctx->r2, ctx->r3);
        goto L_8003AF54;
    }
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // nop

    // bne         $v0, $s6, L_8003AF54
    if (ctx->r2 != ctx->r22) {
        // ori         $v0, $zero, 0x73
        ctx->r2 = 0 | 0X73;
        goto L_8003AF54;
    }
    // ori         $v0, $zero, 0x73
    ctx->r2 = 0 | 0X73;
    // lbu         $v1, 0x2E($s1)
    ctx->r3 = MEM_BU(0X2E, ctx->r17);
    // nop

    // beq         $v1, $v0, L_8003AF34
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x74
        ctx->r2 = SIGNED(ctx->r3) < 0X74 ? 1 : 0;
        goto L_8003AF34;
    }
    // slti        $v0, $v1, 0x74
    ctx->r2 = SIGNED(ctx->r3) < 0X74 ? 1 : 0;
    // beq         $v0, $zero, L_8003AF20
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x72
        ctx->r2 = 0 | 0X72;
        goto L_8003AF20;
    }
    // ori         $v0, $zero, 0x72
    ctx->r2 = 0 | 0X72;
    // beq         $v1, $v0, L_8003AF38
    if (ctx->r3 == ctx->r2) {
        // ori         $v1, $zero, 0x28
        ctx->r3 = 0 | 0X28;
        goto L_8003AF38;
    }
    // ori         $v1, $zero, 0x28
    ctx->r3 = 0 | 0X28;
    // j           L_8003AF50
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
    goto L_8003AF50;
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
L_8003AF20:
    // ori         $v0, $zero, 0x74
    ctx->r2 = 0 | 0X74;
    // beq         $v1, $v0, L_8003AF38
    if (ctx->r3 == ctx->r2) {
        // ori         $v1, $zero, 0x30
        ctx->r3 = 0 | 0X30;
        goto L_8003AF38;
    }
    // ori         $v1, $zero, 0x30
    ctx->r3 = 0 | 0X30;
    // j           L_8003AF50
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
    goto L_8003AF50;
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
L_8003AF34:
    // ori         $v1, $zero, 0x2C
    ctx->r3 = 0 | 0X2C;
L_8003AF38:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
L_8003AF50:
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
L_8003AF54:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // addiu       $a2, $a2, 0x6380
    ctx->r6 = ADD32(ctx->r6, 0X6380);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // addiu       $a3, $a3, 0x6388
    ctx->r7 = ADD32(ctx->r7, 0X6388);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // jal         0x800395EC
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_800395EC(rdram, ctx);
    goto after_57;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_57:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003AF80:
    // lbu         $v0, 0x2F($s1)
    ctx->r2 = MEM_BU(0X2F, ctx->r17);
    // lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8003AFEC
    if (ctx->r2 == 0) {
        // addu        $a1, $v1, $a0
        ctx->r5 = ADD32(ctx->r3, ctx->r4);
        goto L_8003AFEC;
    }
    // addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // nop

    // bne         $v0, $s6, L_8003AFEC
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8003AFEC;
    }
    // nop

    // lbu         $v1, 0x31($s1)
    ctx->r3 = MEM_BU(0X31, ctx->r17);
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
    // sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v1, $a0, -0x64F0
    ctx->r3 = ADD32(ctx->r4, -0X64F0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(0X30, ctx->r17);
    // lbu         $a0, 0x38($v0)
    ctx->r4 = MEM_BU(0X38, ctx->r2);
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $a0, $a0, $v1
    ctx->r4 = ctx->r4 & ctx->r3;
    // sb          $a0, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r4;
L_8003AFEC:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // addiu       $a2, $a2, 0x6390
    ctx->r6 = ADD32(ctx->r6, 0X6390);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // addiu       $a3, $a3, 0x6398
    ctx->r7 = ADD32(ctx->r7, 0X6398);
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x800395EC
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_800395EC(rdram, ctx);
    goto after_58;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_58:
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $v1, 0x31($s1)
    ctx->r3 = MEM_BU(0X31, ctx->r17);
    // lbu         $a0, 0x30($s1)
    ctx->r4 = MEM_BU(0X30, ctx->r17);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x38($v0)
    ctx->r3 = MEM_BU(0X38, ctx->r2);
    // nop

    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // j           L_8003B6F4
    // sb          $v1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r3;
    goto L_8003B6F4;
    // sb          $v1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r3;
L_8003B04C:
    // lw          $v0, 0x36($s1)
    ctx->r2 = MEM_W(0X36, ctx->r17);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x5A50($v1)
    ctx->r3 = MEM_W(-0X5A50, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // bgez        $v0, L_8003B6F4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v0, $v1, 0x1E
        ctx->r2 = ADD32(ctx->r3, 0X1E);
        goto L_8003B6F4;
    }
    // addiu       $v0, $v1, 0x1E
    ctx->r2 = ADD32(ctx->r3, 0X1E);
    // sw          $v0, 0x36($s1)
    MEM_W(0X36, ctx->r17) = ctx->r2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80037F78
    // ori         $a1, $zero, 0xEE
    ctx->r5 = 0 | 0XEE;
    sub_80037F78(rdram, ctx);
    goto after_59;
    // ori         $a1, $zero, 0xEE
    ctx->r5 = 0 | 0XEE;
    after_59:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B080:
    // lhu         $v0, 0x30($s1)
    ctx->r2 = MEM_HU(0X30, ctx->r17);
    // lhu         $a0, -0x2($s1)
    ctx->r4 = MEM_HU(-0X2, ctx->r17);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // beq         $a0, $s5, L_8003B160
    if (ctx->r4 == ctx->r21) {
        // addu        $s0, $v1, $v0
        ctx->r16 = ADD32(ctx->r3, ctx->r2);
        goto L_8003B160;
    }
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003B0C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B0C0;
    }
    // nop

    // beq         $a0, $zero, L_8003B0D0
    if (ctx->r4 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8003B0D0;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B0C0:
    // beq         $a0, $fp, L_8003B1E8
    if (ctx->r4 == ctx->r30) {
        // nop
    
        goto L_8003B1E8;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B0D0:
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // jal         0x80039448
    // addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    sub_80039448(rdram, ctx);
    goto after_60;
    // addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    after_60:
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // nop

    // beq         $v1, $v0, L_8003B6F4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lwl         $v0, 0x1D($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1D, ctx->r17);
    // lwr         $v0, 0x1A($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X1A, ctx->r17);
    // lwl         $v1, 0x21($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X21, ctx->r17);
    // lwr         $v1, 0x1E($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X1E, ctx->r17);
    // swl         $v0, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r2);
    // swr         $v0, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r2);
    // swl         $v1, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r3);
    // swr         $v1, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r3);
    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // nop

    // beq         $v0, $s6, L_8003B1C8
    if (ctx->r2 == ctx->r22) {
        // ori         $v0, $zero, 0x4C
        ctx->r2 = 0 | 0X4C;
        goto L_8003B1C8;
    }
    // ori         $v0, $zero, 0x4C
    ctx->r2 = 0 | 0X4C;
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // sb          $s6, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r22;
    // addiu       $v1, $v1, 0x12C
    ctx->r3 = ADD32(ctx->r3, 0X12C);
    // sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2E($s1)
    ctx->r2 = MEM_BU(0X2E, ctx->r17);
    // nop

    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // j           L_8003B6F4
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    goto L_8003B6F4;
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
L_8003B160:
    // lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // lbu         $s2, -0x2144($s2)
    ctx->r18 = MEM_BU(-0X2144, ctx->r18);
    // nop

    // slti        $v0, $s2, 0x10
    ctx->r2 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8003B6F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_61;
    // nop

    after_61:
    // sll         $v1, $s2, 11
    ctx->r3 = S32(ctx->r18) << 11;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(0X30, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // lhu         $v1, 0x30($s0)
    ctx->r3 = MEM_HU(0X30, ctx->r16);
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // srl         $v1, $v1, 5
    ctx->r3 = S32(U32(ctx->r3) >> 5);
    // sb          $v1, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r3;
    // lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(0X2C, ctx->r16);
    // nop

    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

L_8003B1C8:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x62
    ctx->r5 = 0 | 0X62;
    // sb          $s6, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = ctx->r22;
    // jal         0x80038E4C
    // sb          $s6, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r22;
    SetProjectileModel(rdram, ctx);
    goto after_62;
    // sb          $s6, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r22;
    after_62:
L_8003B1DC:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8003B1E0:
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003B1E8:
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // bne         $v0, $s6, L_8003B6F4
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // j           L_8003B6F4
    // sb          $zero, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = 0;
    goto L_8003B6F4;
    // sb          $zero, 0x2E($s1)
    MEM_B(0X2E, ctx->r17) = 0;
L_8003B200:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8003B220
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B220;
    }
    // nop

    // beq         $v0, $s5, L_8003B2A0
    if (ctx->r2 == ctx->r21) {
        // nop
    
        goto L_8003B2A0;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B220:
    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // lhu         $a3, 0x4($s3)
    ctx->r7 = MEM_HU(0X4, ctx->r19);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0xE($s1)
    ctx->r5 = MEM_W(0XE, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x8002E120
    // nop

    MAP_CollisionWithTile(rdram, ctx);
    goto after_63;
    // nop

    after_63:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A82($v1)
    ctx->r3 = MEM_HU(-0X2A82, ctx->r3);
    // nop

    // bne         $v1, $zero, L_8003B25C
    if (ctx->r3 != 0) {
        // addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
        goto L_8003B25C;
    }
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_8003B25C:
    // sb          $a0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r4;
    // lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(0X34, ctx->r17);
    // lw          $v1, 0xE($s1)
    ctx->r3 = MEM_W(0XE, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x34($s1)
    ctx->r2 = MEM_HU(0X34, ctx->r17);
    // lw          $v1, 0xE($s1)
    ctx->r3 = MEM_W(0XE, ctx->r17);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // slt         $v1, $v1, $a1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v1, $zero, L_8003B6F4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x34($s1)
        MEM_H(0X34, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sw          $a1, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r5;
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // j           L_8003B6F4
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
    goto L_8003B6F4;
    // sh          $s5, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r21;
L_8003B2A0:
    // lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(0X1E, ctx->r17);
    // lhu         $v1, 0x34($s1)
    ctx->r3 = MEM_HU(0X34, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x34($s1)
    ctx->r2 = MEM_HU(0X34, ctx->r17);
    // lh          $v1, 0x1E($s1)
    ctx->r3 = MEM_H(0X1E, ctx->r17);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // slti        $v1, $v1, 0x400
    ctx->r3 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // bne         $v1, $zero, L_8003B6F4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x34($s1)
        MEM_H(0X34, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // j           L_8003B480
    // sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    goto L_8003B480;
    // sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
L_8003B2D8:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // lhu         $a3, 0x4($s3)
    ctx->r7 = MEM_HU(0X4, ctx->r19);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0xE($s1)
    ctx->r5 = MEM_W(0XE, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x8002E120
    // nop

    MAP_CollisionWithTile(rdram, ctx);
    goto after_64;
    // nop

    after_64:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A82($v1)
    ctx->r3 = MEM_HU(-0X2A82, ctx->r3);
    // nop

    // bne         $v1, $zero, L_8003B324
    if (ctx->r3 != 0) {
        // addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
        goto L_8003B324;
    }
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_8003B324:
    // sb          $a0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r4;
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // lhu         $v1, 0x1C($s1)
    ctx->r3 = MEM_HU(0X1C, ctx->r17);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // sw          $v0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r2;
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // sh          $v1, 0x1C($s1)
        MEM_H(0X1C, ctx->r17) = ctx->r3;
        goto L_8003B6F4;
    }
    // sh          $v1, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r3;
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // sw          $a1, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r5;
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003B360:
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // nop

    // sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003B450
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B450;
    }
    // nop

    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // lhu         $a3, 0x4($s3)
    ctx->r7 = MEM_HU(0X4, ctx->r19);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0xE($s1)
    ctx->r5 = MEM_W(0XE, ctx->r17);
    // lw          $a2, 0x12($s1)
    ctx->r6 = MEM_W(0X12, ctx->r17);
    // jal         0x8002E120
    // nop

    MAP_CollisionWithTile(rdram, ctx);
    goto after_65;
    // nop

    after_65:
    // ori         $a3, $zero, 0x2
    ctx->r7 = 0 | 0X2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A82($v1)
    ctx->r3 = MEM_HU(-0X2A82, ctx->r3);
    // nop

    // bne         $v1, $zero, L_8003B3B0
    if (ctx->r3 != 0) {
        // addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
        goto L_8003B3B0;
    }
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
L_8003B3B0:
    // addiu       $a0, $s4, 0x14
    ctx->r4 = ADD32(ctx->r20, 0X14);
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // ori         $a2, $zero, 0x1770
    ctx->r6 = 0 | 0X1770;
    // sb          $a3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r7;
    // lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(0X34, ctx->r17);
    // lw          $v1, 0xE($s1)
    ctx->r3 = MEM_W(0XE, ctx->r17);
    // ori         $a3, $zero, 0x12C
    ctx->r7 = 0 | 0X12C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80044814
    // sw          $v0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r2;
    sub_80044814(rdram, ctx);
    goto after_66;
    // sw          $v0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r2;
    after_66:
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // lh          $v1, 0x1A($s1)
    ctx->r3 = MEM_H(0X1A, ctx->r17);
    // bne         $v0, $zero, L_8003B3EC
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0xA0
        ctx->r2 = ADD32(ctx->r3, -0XA0);
        goto L_8003B3EC;
    }
    // addiu       $v0, $v1, -0xA0
    ctx->r2 = ADD32(ctx->r3, -0XA0);
    // addiu       $v0, $v1, 0xA0
    ctx->r2 = ADD32(ctx->r3, 0XA0);
L_8003B3EC:
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // lhu         $v0, 0x34($s1)
    ctx->r2 = MEM_HU(0X34, ctx->r17);
    // sh          $v1, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r3;
    // addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // sra         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) >> 16;
    // bltz        $v1, L_8003B6F4
    if (SIGNED(ctx->r3) < 0) {
        // sh          $v0, 0x34($s1)
        MEM_H(0X34, ctx->r17) = ctx->r2;
        goto L_8003B6F4;
    }
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // nop

    // slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x50
        ctx->r2 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
        goto L_8003B6F4;
    }
    // slti        $v0, $v1, 0x50
    ctx->r2 = SIGNED(ctx->r3) < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8003B434
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003B434;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $s0, 0xE($s1)
    MEM_W(0XE, ctx->r17) = ctx->r16;
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003B434:
    // sra         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4) >> 17;
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // j           L_8003B6F4
    // sh          $v1, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r3;
    goto L_8003B6F4;
    // sh          $v1, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r3;
L_8003B450:
    // bne         $v1, $fp, L_8003B6F4
    if (ctx->r3 != ctx->r30) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lh          $a0, 0x1A($s1)
    ctx->r4 = MEM_H(0X1A, ctx->r17);
    // lh          $a1, 0x20($s1)
    ctx->r5 = MEM_H(0X20, ctx->r17);
    // jal         0x80014C84
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
    sub_80014C84(rdram, ctx);
    goto after_67;
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
    after_67:
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lh          $v1, 0x20($s1)
    ctx->r3 = MEM_H(0X20, ctx->r17);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8003B6F4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

L_8003B480:
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
L_8003B484:
    // j           L_8003B6F4
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
L_8003B48C:
    // lw          $a0, 0xA($s1)
    ctx->r4 = MEM_W(0XA, ctx->r17);
    // lw          $a1, 0x12($s1)
    ctx->r5 = MEM_W(0X12, ctx->r17);
    // lbu         $a2, 0x2E($s1)
    ctx->r6 = MEM_BU(0X2E, ctx->r17);
    // lbu         $a3, 0x2F($s1)
    ctx->r7 = MEM_BU(0X2F, ctx->r17);
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // jal         0x8003955C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003955C(rdram, ctx);
    goto after_68;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_68:
    // beq         $v0, $zero, L_8003B578
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B578;
    }
    // nop

    // lbu         $v0, 0x36($s1)
    ctx->r2 = MEM_BU(0X36, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003B6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B6F4;
    }
    // nop

    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // bne         $v0, $zero, L_8003B4E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B4E0;
    }
    // nop

    // sb          $s5, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r21;
L_8003B4E0:
    // lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(0X30, ctx->r17);
    // nop

    // andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // beq         $v1, $s5, L_8003B540
    if (ctx->r3 == ctx->r21) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003B540;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003B50C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B50C;
    }
    // nop

    // beq         $v1, $zero, L_8003B51C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8003B51C;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B50C:
    // beq         $v1, $fp, L_8003B554
    if (ctx->r3 == ctx->r30) {
        // nop
    
        goto L_8003B554;
    }
    // nop

    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B51C:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(0XC, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_69;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_69:
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B540:
    // lbu         $a0, 0x31($s1)
    ctx->r4 = MEM_BU(0X31, ctx->r17);
    // jal         0x80039190
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    sub_80039190(rdram, ctx);
    goto after_70;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    after_70:
    // j           L_8003B6F8
    // nop

    goto L_8003B6F8;
    // nop

L_8003B554:
    // lbu         $v1, 0x31($s1)
    ctx->r3 = MEM_BU(0X31, ctx->r17);
    // lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(0X32, ctx->r17);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x51DC
    ctx->r1 = ADD32(ctx->r1, 0X51DC);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // j           L_8003B6F8
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    goto L_8003B6F8;
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B578:
    // j           L_8003B6F4
    // sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    goto L_8003B6F4;
    // sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
L_8003B580:
    // lw          $v0, 0xE($s1)
    ctx->r2 = MEM_W(0XE, ctx->r17);
    // lbu         $a0, 0x2E($s1)
    ctx->r4 = MEM_BU(0X2E, ctx->r17);
    // lbu         $a1, 0x2F($s1)
    ctx->r5 = MEM_BU(0X2F, ctx->r17);
    // lbu         $a2, 0x30($s1)
    ctx->r6 = MEM_BU(0X30, ctx->r17);
    // lbu         $a3, 0x31($s1)
    ctx->r7 = MEM_BU(0X31, ctx->r17);
    // jal         0x8003955C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003955C(rdram, ctx);
    goto after_71;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_71:
    // beq         $v0, $zero, L_8003B6BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B6BC;
    }
    // nop

    // lbu         $v0, 0x36($s1)
    ctx->r2 = MEM_BU(0X36, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003B6C0
    if (ctx->r2 != 0) {
        // ori         $s0, $zero, 0x18C
        ctx->r16 = 0 | 0X18C;
        goto L_8003B6C0;
    }
    // ori         $s0, $zero, 0x18C
    ctx->r16 = 0 | 0X18C;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    // jal         0x80014570
    // ori         $a1, $zero, 0x6E
    ctx->r5 = 0 | 0X6E;
    PlaySoundEffect(rdram, ctx);
    goto after_72;
    // ori         $a1, $zero, 0x6E
    ctx->r5 = 0 | 0X6E;
    after_72:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // jal         0x80039898
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    FadeScreenIn(rdram, ctx);
    goto after_73;
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    after_73:
    // ori         $a0, $zero, 0x22
    ctx->r4 = 0 | 0X22;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
L_8003B5E0:
    // lbu         $v0, -0x3C($v1)
    ctx->r2 = MEM_BU(-0X3C, ctx->r3);
    // nop

    // bne         $v0, $a0, L_8003B5F4
    if (ctx->r2 != ctx->r4) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8003B5F4;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sb          $s5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r21;
L_8003B5F4:
    // bne         $s0, $zero, L_8003B5E0
    if (ctx->r16 != 0) {
        // addiu       $v1, $v1, 0x44
        ctx->r3 = ADD32(ctx->r3, 0X44);
        goto L_8003B5E0;
    }
    // addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(0X0, ctx->r23);
    // lw          $a1, 0x8($s7)
    ctx->r5 = MEM_W(0X8, ctx->r23);
    // jal         0x8002E25C
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_74;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_74:
    // lbu         $v0, 0x32($s1)
    ctx->r2 = MEM_BU(0X32, ctx->r17);
    // nop

    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x33($s1)
    ctx->r2 = MEM_BU(0X33, ctx->r17);
    // nop

    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sw          $v0, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(0X34, ctx->r17);
    // nop

    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // andi        $v0, $v0, 0x5
    ctx->r2 = ctx->r2 & 0X5;
    // sh          $v0, 0x50($s7)
    MEM_H(0X50, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x35($s1)
    ctx->r2 = MEM_BU(0X35, ctx->r17);
    // nop

    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x80027CA8
    // sh          $v0, 0x22($s7)
    MEM_H(0X22, ctx->r23) = ctx->r2;
    Player_Spawn(rdram, ctx);
    goto after_75;
    // sh          $v0, 0x22($s7)
    MEM_H(0X22, ctx->r23) = ctx->r2;
    after_75:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x22($s7)
    ctx->r2 = MEM_HU(0X22, ctx->r23);
    // lhu         $v1, 0x2A($s7)
    ctx->r3 = MEM_HU(0X2A, ctx->r23);
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x32($s7)
    ctx->r3 = MEM_HU(0X32, ctx->r23);
    // lhu         $t0, 0x3A($s7)
    ctx->r8 = MEM_HU(0X3A, ctx->r23);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // jal         0x80039898
    // sh          $v0, 0x1A($s7)
    MEM_H(0X1A, ctx->r23) = ctx->r2;
    FadeScreenIn(rdram, ctx);
    goto after_76;
    // sh          $v0, 0x1A($s7)
    MEM_H(0X1A, ctx->r23) = ctx->r2;
    after_76:
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80033F94
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    SetFadeColor(rdram, ctx);
    goto after_77;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_77:
    // j           L_8003B6C0
    // nop

    goto L_8003B6C0;
    // nop

L_8003B6BC:
    // sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
L_8003B6C0:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // j           L_8003B6F4
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8003B6F4;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003B6D8:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(0X24, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_78;
    // nop

    after_78:
L_8003B6F4:
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_8003B6F8:
    // lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(0X78, ctx->r29);
    // addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // bne         $t1, $zero, L_8003999C
    if (ctx->r9 != 0) {
        // sw          $t1, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r9;
        goto L_8003999C;
    }
    // sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $zero, 0x128($at)
    MEM_W(0X128, ctx->r1) = 0;
    // lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(0XA4, ctx->r29);
    // lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(0XA0, ctx->r29);
    // lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(0X9C, ctx->r29);
    // lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(0X98, ctx->r29);
    // lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(0X94, ctx->r29);
    // lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(0X90, ctx->r29);
    // lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(0X8C, ctx->r29);
    // lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(0X88, ctx->r29);
    // lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(0X84, ctx->r29);
    // lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(0X80, ctx->r29);
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // jr          $ra
    // nop

    return;
    // nop

;}
