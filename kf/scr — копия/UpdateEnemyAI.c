#include "recomp.h"
#include "disable_warnings.h"

void UpdateEnemyAI(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // sw          $s3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // lw          $s3, 0x79B4($s3)
    ctx->r19 = MEM_W(0X79B4, ctx->r19);
    // sw          $s5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r21;
    // lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // lw          $s5, 0x79B0($s5)
    ctx->r21 = MEM_W(0X79B0, ctx->r21);
    // sw          $ra, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r31;
    // sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    // sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // lw          $s4, 0x60($s3)
    ctx->r20 = MEM_W(0X60, ctx->r19);
    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // bne         $v0, $zero, L_8003FC40
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003FC40;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // ori         $v0, $zero, 0x93
    ctx->r2 = 0 | 0X93;
L_8003FC40:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, 0x79AC($at)
    MEM_W(0X79AC, ctx->r1) = ctx->r2;
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // lhu         $a2, 0x1C($s3)
    ctx->r6 = MEM_HU(0X1C, ctx->r19);
    // jal         0x8002E25C
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // lbu         $v1, 0x4($s4)
    ctx->r3 = MEM_BU(0X4, ctx->r20);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8003FD90
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003FD90;
    }
    // nop

    // lhu         $v0, 0xA($s4)
    ctx->r2 = MEM_HU(0XA, ctx->r20);
    // lhu         $v1, 0xA($s4)
    ctx->r3 = MEM_HU(0XA, ctx->r20);
    // andi        $s0, $v0, 0x3FFF
    ctx->r16 = ctx->r2 & 0X3FFF;
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // ori         $v0, $zero, 0x4000
    ctx->r2 = 0 | 0X4000;
    // beq         $v1, $v0, L_8003FCEC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x4001
        ctx->r2 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
        goto L_8003FCEC;
    }
    // slti        $v0, $v1, 0x4001
    ctx->r2 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
    // beq         $v0, $zero, L_8003FCA0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003FCA0;
    }
    // nop

    // beq         $v1, $zero, L_8003FCB4
    if (ctx->r3 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8003FCB4;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8003FD90
    // nop

    goto L_8003FD90;
    // nop

L_8003FCA0:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // beq         $v1, $v0, L_8003FCCC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003FCCC;
    }
    // nop

    // j           L_8003FD90
    // nop

    goto L_8003FD90;
    // nop

L_8003FCB4:
    // jal         0x8003D8B4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // beq         $v0, $zero, L_8003FD90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003FD90;
    }
    // nop

    // j           L_8003FD88
    // nop

    goto L_8003FD88;
    // nop

L_8003FCCC:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $v0, $zero, L_8003FD90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003FD90;
    }
    // nop

    // j           L_8003FD88
    // nop

    goto L_8003FD88;
    // nop

L_8003FCEC:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79C0($v0)
    ctx->r2 = MEM_W(0X79C0, ctx->r2);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // bne         $s0, $zero, L_8003FD28
    if (ctx->r16 != 0) {
        // nop
    
        goto L_8003FD28;
    }
    // nop

    // break       7
    do_break(2147745060);
L_8003FD28:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_8003FD40
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003FD40;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003FD40
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003FD40;
    }
    // nop

    // break       6
    do_break(2147745084);
L_8003FD40:
    // mfhi        $a0
    ctx->r4 = hi;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79CC($v0)
    ctx->r2 = MEM_W(0X79CC, ctx->r2);
    // nop

    // div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // bne         $s0, $zero, L_8003FD60
    if (ctx->r16 != 0) {
        // nop
    
        goto L_8003FD60;
    }
    // nop

    // break       7
    do_break(2147745116);
L_8003FD60:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_8003FD78
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003FD78;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003FD78
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003FD78;
    }
    // nop

    // break       6
    do_break(2147745140);
L_8003FD78:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $a0, L_8003FD90
    if (ctx->r3 != ctx->r4) {
        // nop
    
        goto L_8003FD90;
    }
    // nop

L_8003FD88:
    // jal         0x8003FB58
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003FB58(rdram, ctx);
    goto after_3;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_3:
L_8003FD90:
    // lbu         $v1, 0xE($s3)
    ctx->r3 = MEM_BU(0XE, ctx->r19);
    // nop

    // sltiu       $v0, $v1, 0xF1
    ctx->r2 = ctx->r3 < 0XF1 ? 1 : 0;
    // beq         $v0, $zero, L_80041E00
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80041E00;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x21D4
    ctx->r1 = ADD32(ctx->r1, 0X21D4);
    // addu        $at, $at, $v0
    gpr jr_addend_8003FDB8;
    jr_addend_8003FDB8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003FDB8 >> 2) {
        case 0: goto L_80040098; break;
        case 1: goto L_800400F4; break;
        case 2: goto L_8003FDC0; break;
        case 3: goto L_8003FE38; break;
        case 4: goto L_80040A98; break;
        case 5: goto L_80040328; break;
        case 6: goto L_80041E00; break;
        case 7: goto L_80041E00; break;
        case 8: goto L_80041E00; break;
        case 9: goto L_80040680; break;
        case 10: goto L_80040878; break;
        case 11: goto L_80040D98; break;
        case 12: goto L_80040180; break;
        case 13: goto L_80040504; break;
        case 14: goto L_80041118; break;
        case 15: goto L_80041244; break;
        case 16: goto L_80040180; break;
        case 17: goto L_80040504; break;
        case 18: goto L_80041014; break;
        case 19: goto L_800412B8; break;
        case 20: goto L_80041374; break;
        case 21: goto L_80041444; break;
        case 22: goto L_8004141C; break;
        case 23: goto L_80040B38; break;
        case 24: goto L_80040C74; break;
        case 25: goto L_80041734; break;
        case 26: goto L_8004163C; break;
        case 27: goto L_80041964; break;
        case 28: goto L_80041B84; break;
        case 29: goto L_80041B14; break;
        case 30: goto L_80041C78; break;
        case 31: goto L_80041E00; break;
        case 32: goto L_80041E00; break;
        case 33: goto L_80041E00; break;
        case 34: goto L_80041E00; break;
        case 35: goto L_80041E00; break;
        case 36: goto L_80041E00; break;
        case 37: goto L_80041E00; break;
        case 38: goto L_80041E00; break;
        case 39: goto L_80041E00; break;
        case 40: goto L_80041E00; break;
        case 41: goto L_80041E00; break;
        case 42: goto L_80041E00; break;
        case 43: goto L_80041E00; break;
        case 44: goto L_80041E00; break;
        case 45: goto L_80041E00; break;
        case 46: goto L_80041E00; break;
        case 47: goto L_80041E00; break;
        case 48: goto L_80041E00; break;
        case 49: goto L_80041E00; break;
        case 50: goto L_80041E00; break;
        case 51: goto L_80041E00; break;
        case 52: goto L_80041E00; break;
        case 53: goto L_80041E00; break;
        case 54: goto L_80041E00; break;
        case 55: goto L_80041E00; break;
        case 56: goto L_80041E00; break;
        case 57: goto L_80041E00; break;
        case 58: goto L_80041E00; break;
        case 59: goto L_80041E00; break;
        case 60: goto L_80041E00; break;
        case 61: goto L_80041E00; break;
        case 62: goto L_80041E00; break;
        case 63: goto L_80041E00; break;
        case 64: goto L_80041E00; break;
        case 65: goto L_80041E00; break;
        case 66: goto L_80041E00; break;
        case 67: goto L_80041E00; break;
        case 68: goto L_80041E00; break;
        case 69: goto L_80041E00; break;
        case 70: goto L_80041E00; break;
        case 71: goto L_80041E00; break;
        case 72: goto L_80041E00; break;
        case 73: goto L_80041E00; break;
        case 74: goto L_80041E00; break;
        case 75: goto L_80041E00; break;
        case 76: goto L_80041E00; break;
        case 77: goto L_80041E00; break;
        case 78: goto L_80041E00; break;
        case 79: goto L_80041E00; break;
        case 80: goto L_80041E00; break;
        case 81: goto L_80041E00; break;
        case 82: goto L_80041E00; break;
        case 83: goto L_80041E00; break;
        case 84: goto L_80041E00; break;
        case 85: goto L_80041E00; break;
        case 86: goto L_80041E00; break;
        case 87: goto L_80041E00; break;
        case 88: goto L_80041E00; break;
        case 89: goto L_80041E00; break;
        case 90: goto L_80041E00; break;
        case 91: goto L_80041E00; break;
        case 92: goto L_80041E00; break;
        case 93: goto L_80041E00; break;
        case 94: goto L_80041E00; break;
        case 95: goto L_80041E00; break;
        case 96: goto L_80041E00; break;
        case 97: goto L_80041E00; break;
        case 98: goto L_80041E00; break;
        case 99: goto L_80041E00; break;
        case 100: goto L_80041E00; break;
        case 101: goto L_80041E00; break;
        case 102: goto L_80041E00; break;
        case 103: goto L_80041E00; break;
        case 104: goto L_80041E00; break;
        case 105: goto L_80041E00; break;
        case 106: goto L_80041E00; break;
        case 107: goto L_80041E00; break;
        case 108: goto L_80041E00; break;
        case 109: goto L_80041E00; break;
        case 110: goto L_80041E00; break;
        case 111: goto L_80041E00; break;
        case 112: goto L_80041E00; break;
        case 113: goto L_80041E00; break;
        case 114: goto L_80041E00; break;
        case 115: goto L_80041E00; break;
        case 116: goto L_80041E00; break;
        case 117: goto L_80041E00; break;
        case 118: goto L_80041E00; break;
        case 119: goto L_80041E00; break;
        case 120: goto L_80041E00; break;
        case 121: goto L_80041E00; break;
        case 122: goto L_80041E00; break;
        case 123: goto L_80041E00; break;
        case 124: goto L_80041E00; break;
        case 125: goto L_80041E00; break;
        case 126: goto L_80041E00; break;
        case 127: goto L_80041E00; break;
        case 128: goto L_80041E00; break;
        case 129: goto L_80041E00; break;
        case 130: goto L_80041E00; break;
        case 131: goto L_80041E00; break;
        case 132: goto L_80041E00; break;
        case 133: goto L_80041E00; break;
        case 134: goto L_80041E00; break;
        case 135: goto L_80041E00; break;
        case 136: goto L_80041E00; break;
        case 137: goto L_80041E00; break;
        case 138: goto L_80041E00; break;
        case 139: goto L_80041E00; break;
        case 140: goto L_80041E00; break;
        case 141: goto L_80041E00; break;
        case 142: goto L_80041E00; break;
        case 143: goto L_80041E00; break;
        case 144: goto L_80041E00; break;
        case 145: goto L_80041E00; break;
        case 146: goto L_80041E00; break;
        case 147: goto L_80041E00; break;
        case 148: goto L_80041E00; break;
        case 149: goto L_80041E00; break;
        case 150: goto L_80041E00; break;
        case 151: goto L_80041E00; break;
        case 152: goto L_80041E00; break;
        case 153: goto L_80041E00; break;
        case 154: goto L_80041E00; break;
        case 155: goto L_80041E00; break;
        case 156: goto L_80041E00; break;
        case 157: goto L_80041E00; break;
        case 158: goto L_80041E00; break;
        case 159: goto L_80041E00; break;
        case 160: goto L_80041E00; break;
        case 161: goto L_80041E00; break;
        case 162: goto L_80041E00; break;
        case 163: goto L_80041E00; break;
        case 164: goto L_80041E00; break;
        case 165: goto L_80041E00; break;
        case 166: goto L_80041E00; break;
        case 167: goto L_80041E00; break;
        case 168: goto L_80041E00; break;
        case 169: goto L_80041E00; break;
        case 170: goto L_80041E00; break;
        case 171: goto L_80041E00; break;
        case 172: goto L_80041E00; break;
        case 173: goto L_80041E00; break;
        case 174: goto L_80041E00; break;
        case 175: goto L_80041E00; break;
        case 176: goto L_80041E00; break;
        case 177: goto L_80041E00; break;
        case 178: goto L_80041E00; break;
        case 179: goto L_80041E00; break;
        case 180: goto L_80041E00; break;
        case 181: goto L_80041E00; break;
        case 182: goto L_80041E00; break;
        case 183: goto L_80041E00; break;
        case 184: goto L_80041E00; break;
        case 185: goto L_80041E00; break;
        case 186: goto L_80041E00; break;
        case 187: goto L_80041E00; break;
        case 188: goto L_80041E00; break;
        case 189: goto L_80041E00; break;
        case 190: goto L_80041E00; break;
        case 191: goto L_80041E00; break;
        case 192: goto L_80041E00; break;
        case 193: goto L_80041E00; break;
        case 194: goto L_80041E00; break;
        case 195: goto L_80041E00; break;
        case 196: goto L_80041E00; break;
        case 197: goto L_80041E00; break;
        case 198: goto L_80041E00; break;
        case 199: goto L_80041E00; break;
        case 200: goto L_80041E00; break;
        case 201: goto L_80041E00; break;
        case 202: goto L_80041E00; break;
        case 203: goto L_80041E00; break;
        case 204: goto L_80041E00; break;
        case 205: goto L_80041E00; break;
        case 206: goto L_80041E00; break;
        case 207: goto L_80041E00; break;
        case 208: goto L_80041E00; break;
        case 209: goto L_80041E00; break;
        case 210: goto L_80041E00; break;
        case 211: goto L_80041E00; break;
        case 212: goto L_80041E00; break;
        case 213: goto L_80041E00; break;
        case 214: goto L_80041E00; break;
        case 215: goto L_80041E00; break;
        case 216: goto L_80041E00; break;
        case 217: goto L_80041E00; break;
        case 218: goto L_80041E00; break;
        case 219: goto L_80041E00; break;
        case 220: goto L_80041E00; break;
        case 221: goto L_80041E00; break;
        case 222: goto L_80041E00; break;
        case 223: goto L_80041E00; break;
        case 224: goto L_80041E00; break;
        case 225: goto L_80041E00; break;
        case 226: goto L_80041E00; break;
        case 227: goto L_80041E00; break;
        case 228: goto L_80041E00; break;
        case 229: goto L_80041E00; break;
        case 230: goto L_80041E00; break;
        case 231: goto L_80041E00; break;
        case 232: goto L_80041E00; break;
        case 233: goto L_80041E00; break;
        case 234: goto L_80041E00; break;
        case 235: goto L_80041E00; break;
        case 236: goto L_80041E00; break;
        case 237: goto L_80041E00; break;
        case 238: goto L_80041E00; break;
        case 239: goto L_80041E00; break;
        case 240: goto L_80041DF0; break;
        default: switch_error(__func__, 0x8003FDB8, 0x800121D4);
    }
    // nop

L_8003FDC0:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8003FDE0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_8003FDE0;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8003FDE0:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003FE08
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003FE08;
    }
    // nop

    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // bne         $v0, $zero, L_8003FE14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003FE14;
    }
    // nop

L_8003FE08:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_5;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_5:
L_8003FE14:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_800407C8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800407C8;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_800407C8
    // nop

    goto L_800407C8;
    // nop

L_8003FE38:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // lh          $s0, 0x70($s3)
    ctx->r16 = MEM_H(0X70, ctx->r19);
    // bne         $v0, $zero, L_8003FE70
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_8003FE70;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r2;
L_8003FE70:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // nop

    // bne         $v1, $zero, L_8003FFAC
    if (ctx->r3 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8003FFAC;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0x400
    ctx->r2 = ctx->r2 < 0X400 ? 1 : 0;
    // bne         $v0, $zero, L_8003FEA8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003FEA8;
    }
    // nop

    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

L_8003FEA8:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_8;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8003D8B4
    // ori         $a1, $zero, 0x800
    ctx->r5 = 0 | 0X800;
    sub_8003D8B4(rdram, ctx);
    goto after_9;
    // ori         $a1, $zero, 0x800
    ctx->r5 = 0 | 0X800;
    after_9:
    // beq         $v0, $zero, L_8003FF80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003FF80;
    }
    // nop

    // lhu         $a0, 0x30($s5)
    ctx->r4 = MEM_HU(0X30, ctx->r21);
    // jal         0x80015CC8
    // nop

    sub_80015CC8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lhu         $v1, 0x30($s5)
    ctx->r3 = MEM_HU(0X30, ctx->r21);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // beq         $a0, $zero, L_8003FF00
    if (ctx->r4 == 0) {
        // addiu       $a1, $s3, 0x2C
        ctx->r5 = ADD32(ctx->r19, 0X2C);
        goto L_8003FF00;
    }
    // addiu       $a1, $s3, 0x2C
    ctx->r5 = ADD32(ctx->r19, 0X2C);
    // lhu         $a2, 0x1E($s3)
    ctx->r6 = MEM_HU(0X1E, ctx->r19);
    // nop

    // srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // jal         0x80039068
    // negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    sub_80039068(rdram, ctx);
    goto after_11;
    // negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    after_11:
L_8003FF00:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // nop

    // beq         $v1, $zero, L_8003FF18
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8003FF18;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // bne         $v1, $v0, L_8003FF54
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8003FF54;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8003FF18:
    // lbu         $v1, 0xC($s4)
    ctx->r3 = MEM_BU(0XC, ctx->r20);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8003FF80
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003FF80;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lbu         $v1, 0xD($s4)
    ctx->r3 = MEM_BU(0XD, ctx->r20);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003FF80
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_8003FF80;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // lhu         $a3, 0x1E($s3)
    ctx->r7 = MEM_HU(0X1E, ctx->r19);
    // lbu         $a1, 0xC($s4)
    ctx->r5 = MEM_BU(0XC, ctx->r20);
    // j           L_8003FF74
    // addiu       $a2, $s3, 0x2C
    ctx->r6 = ADD32(ctx->r19, 0X2C);
    goto L_8003FF74;
    // addiu       $a2, $s3, 0x2C
    ctx->r6 = ADD32(ctx->r19, 0X2C);
L_8003FF54:
    // bne         $v1, $v0, L_8003FF80
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8003FF80;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $a1, 0xB($s3)
    ctx->r5 = MEM_BU(0XB, ctx->r19);
    // nop

    // beq         $a1, $v0, L_8003FF80
    if (ctx->r5 == ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8003FF80;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $a3, 0x1E($s3)
    ctx->r7 = MEM_HU(0X1E, ctx->r19);
    // addiu       $a2, $s3, 0x2C
    ctx->r6 = ADD32(ctx->r19, 0X2C);
L_8003FF74:
    // srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // jal         0x80038EF4
    // negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    SpawnProjectile(rdram, ctx);
    goto after_13;
    // negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    after_13:
L_8003FF80:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // beq         $v0, $zero, L_800407C4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xF
        ctx->r2 = 0 | 0XF;
        goto L_800407C4;
    }
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // lhu         $v0, 0x8($s4)
    ctx->r2 = MEM_HU(0X8, ctx->r20);
    // nop

    // bne         $v0, $zero, L_800407C8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF
        ctx->r2 = 0 | 0XF;
        goto L_800407C8;
    }
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // j           L_800407C8
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_800407C8;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_8003FFAC:
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // beq         $v1, $v0, L_80041E1C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_80041E1C;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // slti        $v0, $s0, 0x14
    ctx->r2 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
    // bne         $v0, $zero, L_800407C8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x14
        ctx->r2 = 0 | 0X14;
        goto L_800407C8;
    }
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // bne         $s0, $v0, L_8003FFEC
    if (ctx->r16 != ctx->r2) {
        // slti        $v0, $s0, 0x26
        ctx->r2 = SIGNED(ctx->r16) < 0X26 ? 1 : 0;
        goto L_8003FFEC;
    }
    // slti        $v0, $s0, 0x26
    ctx->r2 = SIGNED(ctx->r16) < 0X26 ? 1 : 0;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // sb          $v0, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sh          $v0, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_800407C8
    // sb          $v0, 0x13($s3)
    MEM_B(0X13, ctx->r19) = ctx->r2;
    goto L_800407C8;
    // sb          $v0, 0x13($s3)
    MEM_B(0X13, ctx->r19) = ctx->r2;
L_8003FFEC:
    // beq         $v0, $zero, L_80040020
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040020;
    }
    // nop

    // lh          $v0, 0x16($s3)
    ctx->r2 = MEM_H(0X16, ctx->r19);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_80040014
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0xC0
        ctx->r2 = ADD32(ctx->r3, 0XC0);
        goto L_80040014;
    }
    // addiu       $v0, $v1, 0xC0
    ctx->r2 = ADD32(ctx->r3, 0XC0);
    // j           L_800407C8
    // sh          $v0, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r2;
    goto L_800407C8;
    // sh          $v0, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r2;
L_80040014:
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // j           L_800407C8
    // sh          $v0, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r2;
    goto L_800407C8;
    // sh          $v0, 0x16($s3)
    MEM_H(0X16, ctx->r19) = ctx->r2;
L_80040020:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x4C($v0)
    ctx->r2 = MEM_W(0X4C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_14;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_14:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8004005C
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8004005C;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // jal         0x8003B984
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003B984(rdram, ctx);
    goto after_15;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_15:
    // j           L_800407C8
    // nop

    goto L_800407C8;
    // nop

L_8004005C:
    // bne         $v1, $v0, L_8004006C
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8004006C;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // j           L_80040088
    // sb          $zero, 0x9($s3)
    MEM_B(0X9, ctx->r19) = 0;
    goto L_80040088;
    // sb          $zero, 0x9($s3)
    MEM_B(0X9, ctx->r19) = 0;
L_8004006C:
    // bne         $v1, $v0, L_80040084
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80040084;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // j           L_800407C8
    // sb          $zero, 0x9($s3)
    MEM_B(0X9, ctx->r19) = 0;
    goto L_800407C8;
    // sb          $zero, 0x9($s3)
    MEM_B(0X9, ctx->r19) = 0;
L_80040084:
    // sb          $v0, 0x9($s3)
    MEM_B(0X9, ctx->r19) = ctx->r2;
L_80040088:
    // jal         0x8003B784
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    Entity_UpdatePhysics(rdram, ctx);
    goto after_16;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_16:
    // j           L_800407C8
    // nop

    goto L_800407C8;
    // nop

L_80040098:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_800400B8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_800400B8;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_17;
    // nop

    after_17:
L_800400B8:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D824
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D824(rdram, ctx);
    goto after_18;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_18:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $a2, 0x8($s4)
    ctx->r6 = MEM_HU(0X8, ctx->r20);
    // lh          $a0, 0x18($s3)
    ctx->r4 = MEM_H(0X18, ctx->r19);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // jal         0x80015798
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_19;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_19:
    // beq         $v0, $zero, L_80041950
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_80041950;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // j           L_80041950
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    goto L_80041950;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
L_800400F4:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040120
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_80040120;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // j           L_80040164
    // nop

    goto L_80040164;
    // nop

L_80040120:
    // lh          $a0, 0x64($s3)
    ctx->r4 = MEM_H(0X64, ctx->r19);
    // lhu         $a1, 0xC($s4)
    ctx->r5 = MEM_HU(0XC, ctx->r20);
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // lbu         $a3, 0x3($s5)
    ctx->r7 = MEM_BU(0X3, ctx->r21);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8003E75C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003E75C(rdram, ctx);
    goto after_21;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_21:
    // bne         $v0, $zero, L_80040164
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040164;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // lbu         $v1, 0x10($s4)
    ctx->r3 = MEM_BU(0X10, ctx->r20);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040174
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040174;
    }
    // nop

L_80040164:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x64($s3)
    MEM_H(0X64, ctx->r19) = ctx->r2;
L_80040174:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // j           L_80041A44
    // nop

    goto L_80041A44;
    // nop

L_80040180:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040204
    if (ctx->r2 != 0) {
        // addiu       $a0, $s3, 0x72
        ctx->r4 = ADD32(ctx->r19, 0X72);
        goto L_80040204;
    }
    // addiu       $a0, $s3, 0x72
    ctx->r4 = ADD32(ctx->r19, 0X72);
    // lbu         $a0, 0x6($s3)
    ctx->r4 = MEM_BU(0X6, ctx->r19);
    // lbu         $a1, 0x8($s3)
    ctx->r5 = MEM_BU(0X8, ctx->r19);
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lh          $v0, 0x24($s3)
    ctx->r2 = MEM_H(0X24, ctx->r19);
    // lbu         $a2, 0x7($s3)
    ctx->r6 = MEM_BU(0X7, ctx->r19);
    // lhu         $a3, 0x1C($s3)
    ctx->r7 = MEM_HU(0X1C, ctx->r19);
    // sll         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) << 11;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lh          $v0, 0x22($s3)
    ctx->r2 = MEM_H(0X22, ctx->r19);
    // sll         $a2, $a2, 11
    ctx->r6 = S32(ctx->r6) << 11;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lhu         $v0, 0x1E($s3)
    ctx->r2 = MEM_HU(0X1E, ctx->r19);
    // sh          $zero, 0x76($s3)
    MEM_H(0X76, ctx->r19) = 0;
    // sh          $zero, 0x74($s3)
    MEM_H(0X74, ctx->r19) = 0;
    // sh          $zero, 0x72($s3)
    MEM_H(0X72, ctx->r19) = 0;
    // jal         0x8002E19C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    Map_GetCellData(rdram, ctx);
    goto after_24;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_24:
    // lhu         $v1, 0x26($s3)
    ctx->r3 = MEM_HU(0X26, ctx->r19);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x78($s3)
    MEM_H(0X78, ctx->r19) = ctx->r3;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    sub_8003C27C(rdram, ctx);
    goto after_25;
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    after_25:
    // jal         0x8003E038
    // nop

    sub_8003E038(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // j           L_800402B8
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    goto L_800402B8;
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
L_80040204:
    // lhu         $a1, 0xC($s4)
    ctx->r5 = MEM_HU(0XC, ctx->r20);
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // lbu         $a3, 0x3($s5)
    ctx->r7 = MEM_BU(0X3, ctx->r21);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8003EA30
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003EA30(rdram, ctx);
    goto after_27;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_27:
    // jal         0x80062BF0
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rand_recomp(rdram, ctx);
    goto after_28;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_28:
    // lbu         $v1, 0x13($s4)
    ctx->r3 = MEM_BU(0X13, ctx->r20);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040244
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040244;
    }
    // nop

    // ori         $s0, $s0, 0x1
    ctx->r16 = ctx->r16 | 0X1;
L_80040244:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // lbu         $v1, 0x13($s4)
    ctx->r3 = MEM_BU(0X13, ctx->r20);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040264
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040264;
    }
    // nop

    // ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
L_80040264:
    // lh          $a1, 0x78($s3)
    ctx->r5 = MEM_H(0X78, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(0X30, ctx->r19);
    // addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80040290
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040290;
    }
    // nop

    // lbu         $v1, 0x12($s4)
    ctx->r3 = MEM_BU(0X12, ctx->r20);
    // lhu         $v0, 0x52($s3)
    ctx->r2 = MEM_HU(0X52, ctx->r19);
    // j           L_800402B0
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_800402B0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80040290:
    // subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800402B8
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x1
        ctx->r2 = ctx->r16 & 0X1;
        goto L_800402B8;
    }
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    // lbu         $v0, 0x12($s4)
    ctx->r2 = MEM_BU(0X12, ctx->r20);
    // lhu         $v1, 0x52($s3)
    ctx->r3 = MEM_HU(0X52, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_800402B0:
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
L_800402B8:
    // beq         $v0, $zero, L_800402D4
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_800402D4;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x74($s3)
    MEM_H(0X74, ctx->r19) = ctx->r2;
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_800402D4:
    // beq         $v0, $zero, L_800402F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800402F0;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
L_800402F0:
    // lbu         $v1, 0xE($s3)
    ctx->r3 = MEM_BU(0XE, ctx->r19);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // bne         $v1, $v0, L_8004031C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004031C;
    }
    // nop

    // lbu         $v0, 0x17($s4)
    ctx->r2 = MEM_BU(0X17, ctx->r20);
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // lbu         $a1, 0x14($s4)
    ctx->r5 = MEM_BU(0X14, ctx->r20);
    // lbu         $a2, 0x15($s4)
    ctx->r6 = MEM_BU(0X15, ctx->r20);
    // lbu         $a3, 0x16($s4)
    ctx->r7 = MEM_BU(0X16, ctx->r20);
    // j           L_80040660
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    goto L_80040660;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8004031C:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // j           L_80041A44
    // nop

    goto L_80041A44;
    // nop

L_80040328:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040398
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_80040398;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // lbu         $v1, 0x10($s3)
    ctx->r3 = MEM_BU(0X10, ctx->r19);
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // beq         $v1, $v0, L_80040384
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x13
        ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
        goto L_80040384;
    }
    // slti        $v0, $v1, 0x13
    ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
    // beq         $v0, $zero, L_80040370
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_80040370;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $v1, $v0, L_80040388
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80040388;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80040394
    // sb          $zero, 0x70($s3)
    MEM_B(0X70, ctx->r19) = 0;
    goto L_80040394;
    // sb          $zero, 0x70($s3)
    MEM_B(0X70, ctx->r19) = 0;
L_80040370:
    // slti        $v0, $v1, 0x19
    ctx->r2 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
    // beq         $v0, $zero, L_80040390
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x17
        ctx->r2 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
        goto L_80040390;
    }
    // slti        $v0, $v1, 0x17
    ctx->r2 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
    // bne         $v0, $zero, L_80040390
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040390;
    }
    // nop

L_80040384:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80040388:
    // j           L_80040394
    // sb          $v0, 0x70($s3)
    MEM_B(0X70, ctx->r19) = ctx->r2;
    goto L_80040394;
    // sb          $v0, 0x70($s3)
    MEM_B(0X70, ctx->r19) = ctx->r2;
L_80040390:
    // sb          $zero, 0x70($s3)
    MEM_B(0X70, ctx->r19) = 0;
L_80040394:
    // sb          $zero, 0x71($s3)
    MEM_B(0X71, ctx->r19) = 0;
L_80040398:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_33;
    // nop

    after_33:
    // slti        $v0, $v0, 0x1770
    ctx->r2 = SIGNED(ctx->r2) < 0X1770 ? 1 : 0;
    // beq         $v0, $zero, L_80040404
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040404;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015954
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    CalculateDistance(rdram, ctx);
    goto after_34;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_34:
    // lhu         $v1, 0x16($s4)
    ctx->r3 = MEM_HU(0X16, ctx->r20);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v1, $zero, L_800403EC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800403EC;
    }
    // nop

    // j           L_80040404
    // sb          $zero, 0x70($s3)
    MEM_B(0X70, ctx->r19) = 0;
    goto L_80040404;
    // sb          $zero, 0x70($s3)
    MEM_B(0X70, ctx->r19) = 0;
L_800403EC:
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80040404
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80040404;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x70($s3)
    MEM_B(0X70, ctx->r19) = ctx->r2;
L_80040404:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_35;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_35:
    // ori         $t0, $zero, 0x21
    ctx->r8 = 0 | 0X21;
    // lbu         $v1, 0x71($s3)
    ctx->r3 = MEM_BU(0X71, ctx->r19);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // bne         $v1, $zero, L_80040440
    if (ctx->r3 != 0) {
        // sh          $a0, 0x64($s3)
        MEM_H(0X64, ctx->r19) = ctx->r4;
        goto L_80040440;
    }
    // sh          $a0, 0x64($s3)
    MEM_H(0X64, ctx->r19) = ctx->r4;
    // ori         $t0, $zero, 0x5
    ctx->r8 = 0 | 0X5;
L_80040440:
    // lbu         $v0, 0x70($s3)
    ctx->r2 = MEM_BU(0X70, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8004047C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004047C;
    }
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lhu         $a1, 0xC($s4)
    ctx->r5 = MEM_HU(0XC, ctx->r20);
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // lbu         $a3, 0x3($s5)
    ctx->r7 = MEM_BU(0X3, ctx->r21);
    // lbu         $v0, 0x4($s5)
    ctx->r2 = MEM_BU(0X4, ctx->r21);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // jal         0x8003E75C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003E75C(rdram, ctx);
    goto after_36;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_36:
    // j           L_8004049C
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    goto L_8004049C;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8004047C:
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lhu         $a1, 0xC($s4)
    ctx->r5 = MEM_HU(0XC, ctx->r20);
    // lbu         $a2, 0x3($s5)
    ctx->r6 = MEM_BU(0X3, ctx->r21);
    // jal         0x8003E540
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    sub_8003E540(rdram, ctx);
    goto after_37;
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    after_37:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8004049C:
    // andi        $v0, $s0, 0x100
    ctx->r2 = ctx->r16 & 0X100;
    // beq         $v0, $zero, L_800404DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800404DC;
    }
    // nop

    // lbu         $v0, 0x71($s3)
    ctx->r2 = MEM_BU(0X71, ctx->r19);
    // nop

    // bne         $v0, $zero, L_800404F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800404F8;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_38;
    // nop

    after_38:
    // lhu         $v1, 0x18($s4)
    ctx->r3 = MEM_HU(0X18, ctx->r20);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800404E0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800404E0;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_800404F8
    // sb          $v0, 0x71($s3)
    MEM_B(0X71, ctx->r19) = ctx->r2;
    goto L_800404F8;
    // sb          $v0, 0x71($s3)
    MEM_B(0X71, ctx->r19) = ctx->r2;
L_800404DC:
    // sb          $zero, 0x71($s3)
    MEM_B(0X71, ctx->r19) = 0;
L_800404E0:
    // beq         $s0, $zero, L_800404F8
    if (ctx->r16 == 0) {
        // nop
    
        goto L_800404F8;
    }
    // nop

    // lbu         $v0, 0x70($s3)
    ctx->r2 = MEM_BU(0X70, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // sb          $v0, 0x70($s3)
    MEM_B(0X70, ctx->r19) = ctx->r2;
L_800404F8:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // j           L_80041A44
    // nop

    goto L_80041A44;
    // nop

L_80040504:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040528
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80040528;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
L_80040528:
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // lw          $s2, -0x4A64($s2)
    ctx->r18 = MEM_W(-0X4A64, ctx->r18);
    // lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(0X2C, ctx->r19);
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // lw          $s1, -0x4A60($s1)
    ctx->r17 = MEM_W(-0X4A60, ctx->r17);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // lw          $s0, -0x4A5C($s0)
    ctx->r16 = MEM_W(-0X4A5C, ctx->r16);
    // subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(0X30, ctx->r19);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, -0x640
    ctx->r17 = ADD32(ctx->r17, -0X640);
    // lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(0X34, ctx->r19);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // jal         0x80015990
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80015990(rdram, ctx);
    goto after_40;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_40:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $s3, 0x72
    ctx->r7 = ADD32(ctx->r19, 0X72);
    // jal         0x800159DC
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    Math_VectorToAngles(rdram, ctx);
    goto after_41;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_41:
    // lh          $v1, 0x72($s3)
    ctx->r3 = MEM_H(0X72, ctx->r19);
    // nop

    // slti        $v0, $v1, 0xE01
    ctx->r2 = SIGNED(ctx->r3) < 0XE01 ? 1 : 0;
    // bne         $v0, $zero, L_800405A0
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x201
        ctx->r2 = SIGNED(ctx->r3) < 0X201 ? 1 : 0;
        goto L_800405A0;
    }
    // slti        $v0, $v1, 0x201
    ctx->r2 = SIGNED(ctx->r3) < 0X201 ? 1 : 0;
    // j           L_800405A8
    // ori         $v0, $zero, 0xE00
    ctx->r2 = 0 | 0XE00;
    goto L_800405A8;
    // ori         $v0, $zero, 0xE00
    ctx->r2 = 0 | 0XE00;
L_800405A0:
    // bne         $v0, $zero, L_800405AC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x200
        ctx->r2 = 0 | 0X200;
        goto L_800405AC;
    }
    // ori         $v0, $zero, 0x200
    ctx->r2 = 0 | 0X200;
L_800405A8:
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
L_800405AC:
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800405C8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_800405C8;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // j           L_800405E4
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    goto L_800405E4;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
L_800405C8:
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_800405E8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800405E8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
L_800405E4:
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
L_800405E8:
    // lh          $v0, 0x70($s3)
    ctx->r2 = MEM_H(0X70, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040600
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x200
        ctx->r2 = ADD32(0, -0X200);
        goto L_80040600;
    }
    // addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // j           L_80040618
    // addiu       $a0, $s3, 0x72
    ctx->r4 = ADD32(ctx->r19, 0X72);
    goto L_80040618;
    // addiu       $a0, $s3, 0x72
    ctx->r4 = ADD32(ctx->r19, 0X72);
L_80040600:
    // sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x74($s3)
    ctx->r2 = MEM_HU(0X74, ctx->r19);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
L_80040618:
    // lhu         $a1, 0xC($s4)
    ctx->r5 = MEM_HU(0XC, ctx->r20);
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // lbu         $a3, 0x3($s5)
    ctx->r7 = MEM_BU(0X3, ctx->r21);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8003EA30
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003EA30(rdram, ctx);
    goto after_42;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_42:
    // lbu         $v1, 0xE($s3)
    ctx->r3 = MEM_BU(0XE, ctx->r19);
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // bne         $v1, $v0, L_80040674
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80040674;
    }
    // nop

    // lbu         $v0, 0x1B($s4)
    ctx->r2 = MEM_BU(0X1B, ctx->r20);
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // lbu         $a1, 0x18($s4)
    ctx->r5 = MEM_BU(0X18, ctx->r20);
    // lbu         $a2, 0x19($s4)
    ctx->r6 = MEM_BU(0X19, ctx->r20);
    // lbu         $a3, 0x1A($s4)
    ctx->r7 = MEM_BU(0X1A, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80040660:
    // lhu         $v0, 0x8($s4)
    ctx->r2 = MEM_HU(0X8, ctx->r20);
    // jal         0x8003ECE8
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8003ECE8(rdram, ctx);
    goto after_43;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_43:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80040674:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // j           L_80041A44
    // nop

    goto L_80041A44;
    // nop

L_80040680:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_800406A4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_800406A4;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    // lbu         $a0, 0x14($s4)
    ctx->r4 = MEM_BU(0X14, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_44;
    // nop

    after_44:
L_800406A4:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80040768
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80040768;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800406CC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800406CC;
    }
    // nop

    // beq         $v1, $zero, L_800406E8
    if (ctx->r3 == 0) {
        // ori         $a3, $zero, 0x5
        ctx->r7 = 0 | 0X5;
        goto L_800406E8;
    }
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800406CC:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_800407E0
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_800407E0;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_80040834
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80040834;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800406E8:
    // lhu         $a1, 0x12($s4)
    ctx->r5 = MEM_HU(0X12, ctx->r20);
    // lhu         $a0, 0x42($s3)
    ctx->r4 = MEM_HU(0X42, ctx->r19);
    // lbu         $a2, 0x3($s5)
    ctx->r6 = MEM_BU(0X3, ctx->r21);
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x8003E540
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_8003E540(rdram, ctx);
    goto after_45;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_45:
    // bne         $v0, $zero, L_80040750
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80040750;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D824
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D824(rdram, ctx);
    goto after_46;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_46:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015954
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    CalculateDistance(rdram, ctx);
    goto after_47;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_47:
    // lhu         $v1, 0xE($s4)
    ctx->r3 = MEM_HU(0XE, ctx->r20);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80041E1C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80040750:
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_48;
    // nop

    after_48:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80040768:
    // lbu         $a1, 0x16($s4)
    ctx->r5 = MEM_BU(0X16, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_49;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_49:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_800407C8
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_800407C8;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A64($a1)
    ctx->r5 = MEM_W(-0X4A64, ctx->r5);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4A5C($a3)
    ctx->r7 = MEM_W(-0X4A5C, ctx->r7);
    // lbu         $v0, 0x17($s4)
    ctx->r2 = MEM_BU(0X17, ctx->r20);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A60($a2)
    ctx->r6 = MEM_W(-0X4A60, ctx->r6);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x10($s4)
    ctx->r2 = MEM_HU(0X10, ctx->r20);
    // addiu       $a2, $a2, -0x1F4
    ctx->r6 = ADD32(ctx->r6, -0X1F4);
    // jal         0x8003DF98
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8003DF98(rdram, ctx);
    goto after_50;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_50:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_800407F0
    if (SIGNED(ctx->r2) <= 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_800407F0;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_800407C4:
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_800407C8:
    // lbu         $a0, 0x3($s5)
    ctx->r4 = MEM_BU(0X3, ctx->r21);
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    // jal         0x8003E414
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    sub_8003E414(rdram, ctx);
    goto after_51;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    after_51:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800407E0:
    // lbu         $v0, 0xD($s3)
    ctx->r2 = MEM_BU(0XD, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8004080C
    if (ctx->r2 != 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8004080C;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800407F0:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x15($s4)
    ctx->r4 = MEM_BU(0X15, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_52;
    // nop

    after_52:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_8004080C:
    // lh          $a0, 0x42($s3)
    ctx->r4 = MEM_H(0X42, ctx->r19);
    // lh          $a1, 0x68($s3)
    ctx->r5 = MEM_H(0X68, ctx->r19);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // jal         0x8003E75C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003E75C(rdram, ctx);
    goto after_53;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_53:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80040834:
    // lbu         $a1, 0x16($s4)
    ctx->r5 = MEM_BU(0X16, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_54;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_54:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8004085C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004085C;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_55;
    // nop

    after_55:
L_8004085C:
    // lhu         $a0, 0x68($s3)
    ctx->r4 = MEM_HU(0X68, ctx->r19);
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x8003E414
    // sra         $a0, $a0, 20
    ctx->r4 = S32(ctx->r4) >> 20;
    sub_8003E414(rdram, ctx);
    goto after_56;
    // sra         $a0, $a0, 20
    ctx->r4 = S32(ctx->r4) >> 20;
    after_56:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80040878:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_800408A0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_800408A0;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_57;
    // nop

    after_57:
    // jal         0x8003E038
    // nop

    sub_8003E038(rdram, ctx);
    goto after_58;
    // nop

    after_58:
L_800408A0:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_59;
    // nop

    after_59:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_800408F0
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x1000
        ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
        goto L_800408F0;
    }
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // lhu         $v0, 0x50($s3)
    ctx->r2 = MEM_HU(0X50, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80040938
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80040938;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // j           L_80040938
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    goto L_80040938;
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
L_800408F0:
    // beq         $v0, $zero, L_80040938
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040938;
    }
    // nop

    // lhu         $v0, 0x50($s3)
    ctx->r2 = MEM_HU(0X50, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040938
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040938;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
L_80040938:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_60;
    // nop

    after_60:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_80040988
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x1000
        ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
        goto L_80040988;
    }
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // lhu         $v0, 0x54($s3)
    ctx->r2 = MEM_HU(0X54, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_800409D0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800409D0;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // j           L_800409D0
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    goto L_800409D0;
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
L_80040988:
    // beq         $v0, $zero, L_800409D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800409D0;
    }
    // nop

    // lhu         $v0, 0x54($s3)
    ctx->r2 = MEM_HU(0X54, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800409D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800409D0;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
L_800409D0:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_61;
    // nop

    after_61:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_80040A20
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x1000
        ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
        goto L_80040A20;
    }
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // lhu         $v0, 0x52($s3)
    ctx->r2 = MEM_HU(0X52, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80040A68
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80040A68;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // j           L_80040A68
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    goto L_80040A68;
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
L_80040A20:
    // beq         $v0, $zero, L_80040A68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040A68;
    }
    // nop

    // lhu         $v0, 0x52($s3)
    ctx->r2 = MEM_HU(0X52, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040A68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040A68;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
L_80040A68:
    // jal         0x8003DDB0
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    sub_8003DDB0(rdram, ctx);
    goto after_62;
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    after_62:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D824
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D824(rdram, ctx);
    goto after_63;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_63:
    // lh          $a0, 0x50($s3)
    ctx->r4 = MEM_H(0X50, ctx->r19);
    // lh          $a1, 0x54($s3)
    ctx->r5 = MEM_H(0X54, ctx->r19);
    // jal         0x80015804
    // nop

    Math_Atan2_Fixed(rdram, ctx);
    goto after_64;
    // nop

    after_64:
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // j           L_80041000
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    goto L_80041000;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80040A98:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040AB8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80040AB8;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_65;
    // nop

    after_65:
L_80040AB8:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_66;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_66:
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // jal         0x8003D8B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_67;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_67:
    // beq         $v0, $zero, L_80040B10
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80040B10;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $v0, 0x12($s4)
    ctx->r2 = MEM_HU(0X12, ctx->r20);
    // lbu         $a1, 0xE($s4)
    ctx->r5 = MEM_BU(0XE, ctx->r20);
    // lbu         $a2, 0xF($s4)
    ctx->r6 = MEM_BU(0XF, ctx->r20);
    // lbu         $a3, 0x10($s4)
    ctx->r7 = MEM_BU(0X10, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($s4)
    ctx->r2 = MEM_BU(0X11, ctx->r20);
    // jal         0x8003D090
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D090(rdram, ctx);
    goto after_68;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_68:
L_80040B10:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80040B2C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040B2C;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_69;
    // nop

    after_69:
L_80040B2C:
    // lbu         $a0, 0xD($s4)
    ctx->r4 = MEM_BU(0XD, ctx->r20);
    // j           L_80041954
    // nop

    goto L_80041954;
    // nop

L_80040B38:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040B64
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80040B64;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // nop

    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_70;
    // nop

    after_70:
L_80040B64:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_71;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_71:
    // lhu         $a1, 0x70($s3)
    ctx->r5 = MEM_HU(0X70, ctx->r19);
    // jal         0x8003D8B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_72;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_72:
    // beq         $v0, $zero, L_80040BF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040BF4;
    }
    // nop

    // lhu         $v0, 0x70($s3)
    ctx->r2 = MEM_HU(0X70, ctx->r19);
    // lhu         $v1, 0x28($s4)
    ctx->r3 = MEM_HU(0X28, ctx->r20);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0x26($s4)
    ctx->r3 = MEM_HU(0X26, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80040BB4
    if (ctx->r3 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80040BB4;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
L_80040BB4:
    // lhu         $v0, 0x12($s4)
    ctx->r2 = MEM_HU(0X12, ctx->r20);
    // lbu         $a1, 0xE($s4)
    ctx->r5 = MEM_BU(0XE, ctx->r20);
    // lbu         $a2, 0xF($s4)
    ctx->r6 = MEM_BU(0XF, ctx->r20);
    // lbu         $a3, 0x10($s4)
    ctx->r7 = MEM_BU(0X10, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($s4)
    ctx->r2 = MEM_BU(0X11, ctx->r20);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // jal         0x8003D090
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D090(rdram, ctx);
    goto after_73;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_73:
L_80040BF4:
    // lhu         $a1, 0x2A($s4)
    ctx->r5 = MEM_HU(0X2A, ctx->r20);
    // nop

    // beq         $a1, $zero, L_80040C4C
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80040C4C;
    }
    // nop

    // jal         0x8003D8B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_74;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_74:
    // beq         $v0, $zero, L_80040C4C
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80040C4C;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $v0, 0x20($s4)
    ctx->r2 = MEM_HU(0X20, ctx->r20);
    // lbu         $a1, 0x1C($s4)
    ctx->r5 = MEM_BU(0X1C, ctx->r20);
    // lbu         $a2, 0x1D($s4)
    ctx->r6 = MEM_BU(0X1D, ctx->r20);
    // lbu         $a3, 0x1E($s4)
    ctx->r7 = MEM_BU(0X1E, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x22($s4)
    ctx->r2 = MEM_HU(0X22, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x24($s4)
    ctx->r2 = MEM_HU(0X24, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x1F($s4)
    ctx->r2 = MEM_BU(0X1F, ctx->r20);
    // jal         0x8003D090
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D090(rdram, ctx);
    goto after_75;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_75:
L_80040C4C:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80040C68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040C68;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_76;
    // nop

    after_76:
L_80040C68:
    // lbu         $a0, 0xD($s4)
    ctx->r4 = MEM_BU(0XD, ctx->r20);
    // j           L_80041954
    // nop

    goto L_80041954;
    // nop

L_80040C74:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040C94
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80040C94;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_77;
    // nop

    after_77:
L_80040C94:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_78;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_78:
    // lhu         $v1, 0x18($s3)
    ctx->r3 = MEM_HU(0X18, ctx->r19);
    // lhu         $v0, 0x22($s4)
    ctx->r2 = MEM_HU(0X22, ctx->r20);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_80040CC4
    if (ctx->r2 != 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_80040CC4;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lh          $s0, 0x26($s4)
    ctx->r16 = MEM_H(0X26, ctx->r20);
    // j           L_80040CF0
    // nop

    goto L_80040CF0;
    // nop

L_80040CC4:
    // lhu         $v0, 0x20($s4)
    ctx->r2 = MEM_HU(0X20, ctx->r20);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_80040CE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040CE8;
    }
    // nop

    // lhu         $s1, 0x1C($s4)
    ctx->r17 = MEM_HU(0X1C, ctx->r20);
    // lh          $s0, 0x24($s4)
    ctx->r16 = MEM_H(0X24, ctx->r20);
    // j           L_80040CF0
    // nop

    goto L_80040CF0;
    // nop

L_80040CE8:
    // lhu         $s1, 0x1C($s4)
    ctx->r17 = MEM_HU(0X1C, ctx->r20);
    // lbu         $s0, 0xD($s4)
    ctx->r16 = MEM_BU(0XD, ctx->r20);
L_80040CF0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_79;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_79:
    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x64($s3)
    MEM_H(0X64, ctx->r19) = ctx->r2;
    // lhu         $a2, 0x1E($s4)
    ctx->r6 = MEM_HU(0X1E, ctx->r20);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8003E75C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003E75C(rdram, ctx);
    goto after_80;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_80:
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // jal         0x8003D8B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_81;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_81:
    // beq         $v0, $zero, L_80041294
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041294;
    }
    // nop

    // lhu         $v0, 0x12($s4)
    ctx->r2 = MEM_HU(0X12, ctx->r20);
    // lbu         $a1, 0xE($s4)
    ctx->r5 = MEM_BU(0XE, ctx->r20);
    // lbu         $a2, 0xF($s4)
    ctx->r6 = MEM_BU(0XF, ctx->r20);
    // lbu         $a3, 0x10($s4)
    ctx->r7 = MEM_BU(0X10, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($s4)
    ctx->r2 = MEM_BU(0X11, ctx->r20);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003D090
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D090(rdram, ctx);
    goto after_82;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_82:
    // j           L_80041294
    // nop

    goto L_80041294;
    // nop

L_80040D98:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040DC0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80040DC0;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_83;
    // nop

    after_83:
    // jal         0x8003E038
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    sub_8003E038(rdram, ctx);
    goto after_84;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    after_84:
L_80040DC0:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80040E70
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80040E70;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80040DE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040DE8;
    }
    // nop

    // beq         $v1, $zero, L_80040E04
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80040E04;
    }
    // nop

    // j           L_80040FE8
    // nop

    goto L_80040FE8;
    // nop

L_80040DE8:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_80040F84
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80040F84;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_80040FB0
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80040FB0;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_80040FE8
    // nop

    goto L_80040FE8;
    // nop

L_80040E04:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_85;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_85:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80040FE0
    if (ctx->r2 != 0) {
        // addiu       $a3, $sp, 0x30
        ctx->r7 = ADD32(ctx->r29, 0X30);
        goto L_80040FE0;
    }
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(0X30, ctx->r19);
    // lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(0X34, ctx->r19);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x800159DC
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    Math_VectorToAngles(rdram, ctx);
    goto after_86;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_86:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // jal         0x80015538
    // addiu       $a1, $s3, 0x72
    ctx->r5 = ADD32(ctx->r19, 0X72);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_87;
    // addiu       $a1, $s3, 0x72
    ctx->r5 = ADD32(ctx->r19, 0X72);
    after_87:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80040FE0
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80040FE0;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80040E70:
    // lwl         $v0, 0x75($s3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X75, ctx->r19);
    // lwr         $v0, 0x72($s3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X72, ctx->r19);
    // lwl         $v1, 0x79($s3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X79, ctx->r19);
    // lwr         $v1, 0x76($s3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X76, ctx->r19);
    // swl         $v0, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r2);
    // swr         $v0, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r2);
    // swl         $v1, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r3);
    // swr         $v1, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r3);
    // lwl         $v0, 0x43($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X43, ctx->r29);
    // lwr         $v0, 0x40($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X40, ctx->r29);
    // lwl         $v1, 0x47($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X47, ctx->r29);
    // lwr         $v1, 0x44($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X44, ctx->r29);
    // swl         $v0, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r2);
    // swr         $v0, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r2);
    // swl         $v1, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r3);
    // swr         $v1, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r3);
    // lh          $a0, 0x14($s4)
    ctx->r4 = MEM_H(0X14, ctx->r20);
    // jal         0x80015694
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    sub_80015694(rdram, ctx);
    goto after_88;
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_88:
    // lh          $a0, 0x18($s4)
    ctx->r4 = MEM_H(0X18, ctx->r20);
    // jal         0x80015694
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    sub_80015694(rdram, ctx);
    goto after_89;
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_89:
    // lh          $a0, 0x50($s3)
    ctx->r4 = MEM_H(0X50, ctx->r19);
    // lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(0X38, ctx->r29);
    // lh          $a2, 0x40($sp)
    ctx->r6 = MEM_H(0X40, ctx->r29);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_90;
    // nop

    after_90:
    // lh          $a0, 0x52($s3)
    ctx->r4 = MEM_H(0X52, ctx->r19);
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    // lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(0X3A, ctx->r29);
    // lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(0X42, ctx->r29);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_91;
    // nop

    after_91:
    // lh          $a0, 0x54($s3)
    ctx->r4 = MEM_H(0X54, ctx->r19);
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    // lh          $a1, 0x3C($sp)
    ctx->r5 = MEM_H(0X3C, ctx->r29);
    // lh          $a2, 0x44($sp)
    ctx->r6 = MEM_H(0X44, ctx->r29);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_92;
    // nop

    after_92:
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // jal         0x8003DDB0
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    sub_8003DDB0(rdram, ctx);
    goto after_93;
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    after_93:
    // beq         $v0, $zero, L_80040F6C
    if (ctx->r2 == 0) {
        // andi        $v0, $v0, 0x80
        ctx->r2 = ctx->r2 & 0X80;
        goto L_80040F6C;
    }
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80040F64
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1000
        ctx->r2 = 0 | 0X1000;
        goto L_80040F64;
    }
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // lhu         $a0, 0xE($s4)
    ctx->r4 = MEM_HU(0XE, ctx->r20);
    // lhu         $a1, 0x10($s4)
    ctx->r5 = MEM_HU(0X10, ctx->r20);
    // lhu         $a2, 0x12($s4)
    ctx->r6 = MEM_HU(0X12, ctx->r20);
    // lbu         $a3, 0xD($s4)
    ctx->r7 = MEM_BU(0XD, ctx->r20);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $s3, 0x2C
    ctx->r2 = ADD32(ctx->r19, 0X2C);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // jal         0x80027344
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    ApplyStatusEffect(rdram, ctx);
    goto after_94;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_94:
L_80040F64:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80040F6C:
    // lhu         $v0, 0x40($s3)
    ctx->r2 = MEM_HU(0X40, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // j           L_80040FE8
    // sh          $v0, 0x40($s3)
    MEM_H(0X40, ctx->r19) = ctx->r2;
    goto L_80040FE8;
    // sh          $v0, 0x40($s3)
    MEM_H(0X40, ctx->r19) = ctx->r2;
L_80040F84:
    // lhu         $v0, 0x40($s3)
    ctx->r2 = MEM_HU(0X40, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x40($s3)
    MEM_H(0X40, ctx->r19) = ctx->r2;
    // sltiu       $v0, $v0, 0x100
    ctx->r2 = ctx->r2 < 0X100 ? 1 : 0;
    // beq         $v0, $zero, L_80040FE0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80040FE0;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $zero, 0x40($s3)
    MEM_H(0X40, ctx->r19) = 0;
    // j           L_80040FE0
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80040FE0;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80040FB0:
    // lhu         $a1, 0x8($s4)
    ctx->r5 = MEM_HU(0X8, ctx->r20);
    // nop

    // negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8003D858
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8003D858(rdram, ctx);
    goto after_95;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_95:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80040FE0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040FE0;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_96;
    // nop

    after_96:
L_80040FE0:
    // jal         0x8003DDB0
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    sub_8003DDB0(rdram, ctx);
    goto after_97;
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    after_97:
L_80040FE8:
    // lh          $a0, 0x50($s3)
    ctx->r4 = MEM_H(0X50, ctx->r19);
    // lh          $a1, 0x54($s3)
    ctx->r5 = MEM_H(0X54, ctx->r19);
    // jal         0x80015804
    // nop

    Math_Atan2_Fixed(rdram, ctx);
    goto after_98;
    // nop

    after_98:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $a2, 0x16($s4)
    ctx->r6 = MEM_HU(0X16, ctx->r20);
L_80041000:
    // lbu         $a3, 0x4($s5)
    ctx->r7 = MEM_BU(0X4, ctx->r21);
    // jal         0x8003E608
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    sub_8003E608(rdram, ctx);
    goto after_99;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_99:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80041014:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041034
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041034;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_100;
    // nop

    after_100:
L_80041034:
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // lw          $s2, -0x4A64($s2)
    ctx->r18 = MEM_W(-0X4A64, ctx->r18);
    // lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(0X2C, ctx->r19);
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // lw          $s1, -0x4A60($s1)
    ctx->r17 = MEM_W(-0X4A60, ctx->r17);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // lw          $s0, -0x4A5C($s0)
    ctx->r16 = MEM_W(-0X4A5C, ctx->r16);
    // subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(0X30, ctx->r19);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, -0x640
    ctx->r17 = ADD32(ctx->r17, -0X640);
    // lw          $v0, 0x34($s3)
    ctx->r2 = MEM_W(0X34, ctx->r19);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // jal         0x80015990
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80015990(rdram, ctx);
    goto after_101;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_101:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $s0, $s3, 0x72
    ctx->r16 = ADD32(ctx->r19, 0X72);
    // jal         0x800159DC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    Math_VectorToAngles(rdram, ctx);
    goto after_102;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_102:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $a1, 0x1C($s4)
    ctx->r5 = MEM_HU(0X1C, ctx->r20);
    // lhu         $a2, 0x1E($s4)
    ctx->r6 = MEM_HU(0X1E, ctx->r20);
    // lbu         $a3, 0xD($s4)
    ctx->r7 = MEM_BU(0XD, ctx->r20);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8003EA30
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003EA30(rdram, ctx);
    goto after_103;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_103:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_104;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_104:
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // jal         0x8003D8B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_105;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_105:
    // beq         $v0, $zero, L_80041294
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041294;
    }
    // nop

    // lhu         $v0, 0x12($s4)
    ctx->r2 = MEM_HU(0X12, ctx->r20);
    // lbu         $a1, 0xE($s4)
    ctx->r5 = MEM_BU(0XE, ctx->r20);
    // lbu         $a2, 0xF($s4)
    ctx->r6 = MEM_BU(0XF, ctx->r20);
    // lbu         $a3, 0x10($s4)
    ctx->r7 = MEM_BU(0X10, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($s4)
    ctx->r2 = MEM_BU(0X11, ctx->r20);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003D090
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D090(rdram, ctx);
    goto after_106;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_106:
    // j           L_80041294
    // nop

    goto L_80041294;
    // nop

L_80041118:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, 0x79BC($a0)
    ctx->r4 = MEM_W(0X79BC, ctx->r4);
    // bne         $v0, $zero, L_80041134
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_80041134;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
L_80041134:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_800411B0
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_800411B0;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8004115C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004115C;
    }
    // nop

    // beq         $v1, $zero, L_80041178
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80041178;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_8004115C:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_800411DC
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_800411DC;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_8004121C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004121C;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80041178:
    // lh          $v0, 0x58($a0)
    ctx->r2 = MEM_H(0X58, ctx->r4);
    // nop

    // blez        $v0, L_8004119C
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8004119C;
    }
    // nop

    // lbu         $a0, 0xD($s4)
    ctx->r4 = MEM_BU(0XD, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_107;
    // nop

    after_107:
    // j           L_800414F4
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_800414F4;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004119C:
    // bgez        $v0, L_80041E1C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

    // lbu         $a0, 0xC($s4)
    ctx->r4 = MEM_BU(0XC, ctx->r20);
    // j           L_80041A80
    // nop

    goto L_80041A80;
    // nop

L_800411B0:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_800411F0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800411F0;
    }
    // nop

    // lh          $v0, 0x58($a0)
    ctx->r2 = MEM_H(0X58, ctx->r4);
    // nop

    // bgtz        $v0, L_80041E1C
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80041E1C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_80041214
    // nop

    goto L_80041214;
    // nop

L_800411DC:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_80041204
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041204;
    }
    // nop

L_800411F0:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // j           L_80041E1C
    // sh          $v0, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r2;
    goto L_80041E1C;
    // sh          $v0, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r2;
L_80041204:
    // lh          $v0, 0x58($a0)
    ctx->r2 = MEM_H(0X58, ctx->r4);
    // nop

    // bltz        $v0, L_80041E1C
    if (SIGNED(ctx->r2) < 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80041E1C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
L_80041214:
    // j           L_80041E1C
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80041E1C;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_8004121C:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sh          $v0, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

    // j           L_80041E1C
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    goto L_80041E1C;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
L_80041244:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041264
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041264;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_108;
    // nop

    after_108:
L_80041264:
    // lh          $a0, 0x64($s3)
    ctx->r4 = MEM_H(0X64, ctx->r19);
    // lhu         $a1, 0xC($s4)
    ctx->r5 = MEM_HU(0XC, ctx->r20);
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // lbu         $a3, 0x3($s5)
    ctx->r7 = MEM_BU(0X3, ctx->r21);
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8003E75C
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    sub_8003E75C(rdram, ctx);
    goto after_109;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_109:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_110;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_110:
L_80041294:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

L_800412A8:
    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_111;
    // nop

    after_111:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800412B8:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_800412DC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_800412DC;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_112;
    // nop

    after_112:
L_800412DC:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_80041344
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x11
        ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
        goto L_80041344;
    }
    // slti        $v0, $v1, 0x11
    ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_80041304
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041304;
    }
    // nop

    // beq         $v1, $zero, L_80041318
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80041318;
    }
    // nop

    // j           L_80041950
    // nop

    goto L_80041950;
    // nop

L_80041304:
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_80041360
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80041360;
    }
    // nop

    // j           L_80041950
    // nop

    goto L_80041950;
    // nop

L_80041318:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_113;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_113:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80041950
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80041950;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80041950
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80041950;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80041344:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AAC($v1)
    ctx->r3 = MEM_H(-0X4AAC, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80041950
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x20
        ctx->r2 = 0 | 0X20;
        goto L_80041950;
    }
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // j           L_80041950
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80041950;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80041360:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_114;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_114:
    // j           L_80041934
    // nop

    goto L_80041934;
    // nop

L_80041374:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_800413A8
    if (ctx->r2 != 0) {
        // ori         $a2, $zero, 0x3E8
        ctx->r6 = 0 | 0X3E8;
        goto L_800413A8;
    }
    // ori         $a2, $zero, 0x3E8
    ctx->r6 = 0 | 0X3E8;
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x12($s4)
    ctx->r2 = MEM_HU(0X12, ctx->r20);
    // nop

    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C27C
    // nop

    sub_8003C27C(rdram, ctx);
    goto after_115;
    // nop

    after_115:
    // ori         $a2, $zero, 0x3E8
    ctx->r6 = 0 | 0X3E8;
L_800413A8:
    // ori         $a3, $zero, 0x5
    ctx->r7 = 0 | 0X5;
    // lhu         $a0, 0x42($s3)
    ctx->r4 = MEM_HU(0X42, ctx->r19);
    // lhu         $a1, 0x10($s4)
    ctx->r5 = MEM_HU(0X10, ctx->r20);
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x8003E540
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_8003E540(rdram, ctx);
    goto after_116;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_116:
    // beq         $v0, $zero, L_800413D0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800413D0;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_800413D0:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D824
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D824(rdram, ctx);
    goto after_117;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_117:
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // lhu         $a0, 0x8($s4)
    ctx->r4 = MEM_HU(0X8, ctx->r20);
    // lhu         $v1, 0x18($s3)
    ctx->r3 = MEM_HU(0X18, ctx->r19);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_80041E1C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

    // lhu         $v0, 0x70($s3)
    ctx->r2 = MEM_HU(0X70, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_80041E1C;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // j           L_800412A8
    // sh          $v0, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r2;
    goto L_800412A8;
    // sh          $v0, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r2;
L_8004141C:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041360
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041360;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_118;
    // nop

    after_118:
    // j           L_80041360
    // nop

    goto L_80041360;
    // nop

L_80041444:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041480
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041480;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_119;
    // nop

    after_119:
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // nop

    // sh          $v0, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sh          $v0, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r2;
L_80041480:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_800414FC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_800414FC;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800414A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800414A8;
    }
    // nop

    // beq         $v1, $zero, L_800414BC
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800414BC;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800414A8:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_800415D0
    if (ctx->r3 == ctx->r2) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_800415D0;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800414BC:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015954
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    CalculateDistance(rdram, ctx);
    goto after_120;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_120:
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80041E1C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80041E1C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800414F4:
    // j           L_80041E1C
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80041E1C;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_800414FC:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_121;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_121:
    // lhu         $a0, 0x14($s4)
    ctx->r4 = MEM_HU(0X14, ctx->r20);
    // lhu         $a1, 0x12($s5)
    ctx->r5 = MEM_HU(0X12, ctx->r21);
    // lhu         $a2, 0x18($s3)
    ctx->r6 = MEM_HU(0X18, ctx->r19);
    // jal         0x80015D18
    // nop

    FixedPointLerp(rdram, ctx);
    goto after_122;
    // nop

    after_122:
    // sh          $v0, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r2;
    // lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(0X16, ctx->r20);
    // lhu         $a1, 0x14($s5)
    ctx->r5 = MEM_HU(0X14, ctx->r21);
    // lhu         $a2, 0x18($s3)
    ctx->r6 = MEM_HU(0X18, ctx->r19);
    // jal         0x80015D18
    // nop

    FixedPointLerp(rdram, ctx);
    goto after_123;
    // nop

    after_123:
    // lhu         $v1, 0x18($s3)
    ctx->r3 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 < 0XFFF ? 1 : 0;
    // bne         $v1, $zero, L_8004157C
    if (ctx->r3 != 0) {
        // sh          $v0, 0x1E($s3)
        MEM_H(0X1E, ctx->r19) = ctx->r2;
        goto L_8004157C;
    }
    // sh          $v0, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x12($s5)
    ctx->r2 = MEM_HU(0X12, ctx->r21);
    // nop

    // sh          $v0, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r2;
    // lhu         $v1, 0x14($s5)
    ctx->r3 = MEM_HU(0X14, ctx->r21);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // sh          $v1, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r3;
    // lhu         $v0, 0x10($s4)
    ctx->r2 = MEM_HU(0X10, ctx->r20);
    // nop

    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x18($s4)
    ctx->r4 = MEM_BU(0X18, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_124;
    // nop

    after_124:
L_8004157C:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // lhu         $v1, 0x12($s4)
    ctx->r3 = MEM_HU(0X12, ctx->r20);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80041E1C;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // addiu       $s0, $s0, 0x79AC
    ctx->r16 = ADD32(ctx->r16, 0X79AC);
    // addiu       $v0, $zero, -0x21
    ctx->r2 = ADD32(0, -0X21);
    // lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(0X0, ctx->r16);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lh          $a0, 0x64($s3)
    ctx->r4 = MEM_H(0X64, ctx->r19);
    // lhu         $a1, 0xE($s4)
    ctx->r5 = MEM_HU(0XE, ctx->r20);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8003E75C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8003E75C(rdram, ctx);
    goto after_125;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_125:
    // j           L_80041E1C
    // sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    goto L_80041E1C;
    // sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_800415D0:
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // addiu       $s0, $s0, 0x79AC
    ctx->r16 = ADD32(ctx->r16, 0X79AC);
    // addiu       $v0, $zero, -0x21
    ctx->r2 = ADD32(0, -0X21);
    // lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(0X0, ctx->r16);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lh          $a0, 0x64($s3)
    ctx->r4 = MEM_H(0X64, ctx->r19);
    // lhu         $a1, 0xE($s4)
    ctx->r5 = MEM_HU(0XE, ctx->r20);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8003E75C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8003E75C(rdram, ctx);
    goto after_126;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_126:
    // lhu         $v0, 0x72($s3)
    ctx->r2 = MEM_HU(0X72, ctx->r19);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8004162C
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8004162C;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_127;
    // nop

    after_127:
L_8004162C:
    // sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // lbu         $a1, 0x19($s4)
    ctx->r5 = MEM_BU(0X19, ctx->r20);
    // j           L_80041A44
    // nop

    goto L_80041A44;
    // nop

L_8004163C:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8004166C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_8004166C;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_128;
    // nop

    after_128:
    // sh          $zero, 0x4C($s3)
    MEM_H(0X4C, ctx->r19) = 0;
    // sh          $zero, 0x4A($s3)
    MEM_H(0X4A, ctx->r19) = 0;
    // sh          $zero, 0x48($s3)
    MEM_H(0X48, ctx->r19) = 0;
L_8004166C:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // nop

    // beq         $v1, $zero, L_8004168C
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004168C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80041724
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80041724;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_8004168C:
    // lhu         $v1, 0x20($s3)
    ctx->r3 = MEM_HU(0X20, ctx->r19);
    // nop

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
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

    // lh          $v0, 0x24($a0)
    ctx->r2 = MEM_H(0X24, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80041E1C
    if (ctx->r2 == 0) {
        // slti        $v0, $v0, 0xC00
        ctx->r2 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
        goto L_80041E1C;
    }
    // slti        $v0, $v0, 0xC00
    ctx->r2 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
    // beq         $v0, $zero, L_80041E1C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80041E1C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x12($s5)
    ctx->r2 = MEM_HU(0X12, ctx->r21);
    // nop

    // sh          $v0, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r2;
    // lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(0X30, ctx->r19);
    // lhu         $v1, 0x14($s5)
    ctx->r3 = MEM_HU(0X14, ctx->r21);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // sh          $v1, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r3;
    // lhu         $v0, 0x32($s5)
    ctx->r2 = MEM_HU(0X32, ctx->r21);
    // nop

    // sh          $v0, 0x4C($s3)
    MEM_H(0X4C, ctx->r19) = ctx->r2;
    // sh          $v0, 0x4A($s3)
    MEM_H(0X4A, ctx->r19) = ctx->r2;
    // sh          $v0, 0x48($s3)
    MEM_H(0X48, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(0X26, ctx->r4);
    // nop

    // sh          $v0, 0x42($s3)
    MEM_H(0X42, ctx->r19) = ctx->r2;
L_80041724:
    // lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(0X30, ctx->r19);
    // lhu         $v1, 0x72($s3)
    ctx->r3 = MEM_HU(0X72, ctx->r19);
    // j           L_80041B64
    // sb          $zero, 0xD($s3)
    MEM_B(0XD, ctx->r19) = 0;
    goto L_80041B64;
    // sb          $zero, 0xD($s3)
    MEM_B(0XD, ctx->r19) = 0;
L_80041734:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041778
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041778;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_129;
    // nop

    after_129:
    // lhu         $v0, 0xE($s4)
    ctx->r2 = MEM_HU(0XE, ctx->r20);
    // sh          $zero, 0x72($s3)
    MEM_H(0X72, ctx->r19) = 0;
    // sh          $zero, 0x74($s3)
    MEM_H(0X74, ctx->r19) = 0;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // lbu         $v1, 0x7($s4)
    ctx->r3 = MEM_BU(0X7, ctx->r20);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80041778
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80041778;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sb          $v0, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r2;
L_80041778:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_130;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_130:
    // lhu         $a1, 0x70($s3)
    ctx->r5 = MEM_HU(0X70, ctx->r19);
    // jal         0x8003D8B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_131;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_131:
    // beq         $v0, $zero, L_80041934
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041934;
    }
    // nop

    // lhu         $v0, 0x70($s3)
    ctx->r2 = MEM_HU(0X70, ctx->r19);
    // lhu         $v1, 0x12($s4)
    ctx->r3 = MEM_HU(0X12, ctx->r20);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0x10($s4)
    ctx->r3 = MEM_HU(0X10, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_800417C8
    if (ctx->r3 == 0) {
        // ori         $s1, $zero, 0x1
        ctx->r17 = 0 | 0X1;
        goto L_800417C8;
    }
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
L_800417C8:
    // lh          $v0, 0x72($s3)
    ctx->r2 = MEM_H(0X72, ctx->r19);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
    // addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
L_800417DC:
    // lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(0X0, ctx->r16);
    // lhu         $a0, 0x72($s3)
    ctx->r4 = MEM_HU(0X72, ctx->r19);
    // nop

    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // bne         $a2, $v0, L_80041808
    if (ctx->r6 != ctx->r2) {
        // addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_80041808;
    }
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s0, $s4, 0x1A
    ctx->r16 = ADD32(ctx->r20, 0X1A);
    // j           L_800417DC
    // sh          $zero, 0x72($s3)
    MEM_H(0X72, ctx->r19) = 0;
    goto L_800417DC;
    // sh          $zero, 0x72($s3)
    MEM_H(0X72, ctx->r19) = 0;
L_80041808:
    // ori         $v0, $zero, 0x8001
    ctx->r2 = 0 | 0X8001;
    // bne         $a2, $v0, L_80041828
    if (ctx->r6 != ctx->r2) {
        // ori         $v0, $zero, 0x8003
        ctx->r2 = 0 | 0X8003;
        goto L_80041828;
    }
    // ori         $v0, $zero, 0x8003
    ctx->r2 = 0 | 0X8003;
    // lhu         $s1, 0x0($s0)
    ctx->r17 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // j           L_800417DC
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    goto L_800417DC;
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
L_80041828:
    // bne         $a2, $v0, L_80041848
    if (ctx->r6 != ctx->r2) {
        // ori         $v0, $zero, 0x8002
        ctx->r2 = 0 | 0X8002;
        goto L_80041848;
    }
    // ori         $v0, $zero, 0x8002
    ctx->r2 = 0 | 0X8002;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // j           L_800417DC
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    goto L_800417DC;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80041848:
    // bne         $a2, $v0, L_800418BC
    if (ctx->r6 != ctx->r2) {
        // ori         $v0, $zero, 0x8004
        ctx->r2 = 0 | 0X8004;
        goto L_800418BC;
    }
    // ori         $v0, $zero, 0x8004
    ctx->r2 = 0 | 0X8004;
    // lhu         $a3, 0x0($s0)
    ctx->r7 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lbu         $a0, 0xC($s4)
    ctx->r4 = MEM_BU(0XC, ctx->r20);
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8) << 16;
    // sra         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // jal         0x8003F0F4
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    sub_8003F0F4(rdram, ctx);
    goto after_132;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_132:
    // j           L_8004191C
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8004191C;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800418BC:
    // bne         $a2, $v0, L_800418FC
    if (ctx->r6 != ctx->r2) {
        // sll         $a3, $s1, 1
        ctx->r7 = S32(ctx->r17) << 1;
        goto L_800418FC;
    }
    // sll         $a3, $s1, 1
    ctx->r7 = S32(ctx->r17) << 1;
    // lhu         $a3, 0x0($s0)
    ctx->r7 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lbu         $a0, 0xC($s4)
    ctx->r4 = MEM_BU(0XC, ctx->r20);
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // j           L_80041914
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    goto L_80041914;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
L_800418FC:
    // addu        $a3, $s0, $a3
    ctx->r7 = ADD32(ctx->r16, ctx->r7);
    // lbu         $a0, 0xC($s4)
    ctx->r4 = MEM_BU(0XC, ctx->r20);
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // lh          $v0, 0x74($s3)
    ctx->r2 = MEM_H(0X74, ctx->r19);
    // addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80041914:
    // jal         0x8003F0F4
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    sub_8003F0F4(rdram, ctx);
    goto after_133;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    after_133:
L_8004191C:
    // bne         $s1, $zero, L_800417DC
    if (ctx->r17 != 0) {
        // nop
    
        goto L_800417DC;
    }
    // nop

    // lhu         $v0, 0x74($s3)
    ctx->r2 = MEM_HU(0X74, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x74($s3)
    MEM_H(0X74, ctx->r19) = ctx->r2;
L_80041934:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80041950
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80041950;
    }
    // nop

    // jal         0x8003C220
    // nop

    sub_8003C220(rdram, ctx);
    goto after_134;
    // nop

    after_134:
L_80041950:
    // lbu         $a0, 0x3($s5)
    ctx->r4 = MEM_BU(0X3, ctx->r21);
L_80041954:
    // jal         0x8003E414
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    sub_8003E414(rdram, ctx);
    goto after_135;
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    after_135:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80041964:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041990
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_80041990;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $zero, 0x70($s3)
    MEM_H(0X70, ctx->r19) = 0;
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x16($s4)
    ctx->r4 = MEM_BU(0X16, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_136;
    // nop

    after_136:
L_80041990:
    // lh          $v1, 0x70($s3)
    ctx->r3 = MEM_H(0X70, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80041A54
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80041A54;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800419B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800419B8;
    }
    // nop

    // beq         $v1, $zero, L_800419CC
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800419CC;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800419B8:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_80041A94
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80041A94;
    }
    // nop

    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_800419CC:
    // lhu         $a2, 0xE($s4)
    ctx->r6 = MEM_HU(0XE, ctx->r20);
    // nop

    // beq         $a2, $zero, L_80041A3C
    if (ctx->r6 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80041A3C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lbu         $a0, 0x8($s3)
    ctx->r4 = MEM_BU(0X8, ctx->r19);
    // lh          $v0, 0x24($s3)
    ctx->r2 = MEM_H(0X24, ctx->r19);
    // lbu         $a1, 0x7($s3)
    ctx->r5 = MEM_BU(0X7, ctx->r19);
    // lh          $v1, 0x22($s3)
    ctx->r3 = MEM_H(0X22, ctx->r19);
    // lhu         $a3, 0x10($s4)
    ctx->r7 = MEM_HU(0X10, ctx->r20);
    // sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) << 11;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lh          $v0, 0x72($s3)
    ctx->r2 = MEM_H(0X72, ctx->r19);
    // sll         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) << 11;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s5)
    ctx->r2 = MEM_BU(0X3, ctx->r21);
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(0X4, ctx->r21);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x8003E7D0
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    sub_8003E7D0(rdram, ctx);
    goto after_137;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_137:
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80041A40
    if (ctx->r2 != ctx->r3) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80041A40;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80041A3C:
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80041A40:
    // lbu         $a1, 0x17($s4)
    ctx->r5 = MEM_BU(0X17, ctx->r20);
L_80041A44:
    // jal         0x8003D824
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D824(rdram, ctx);
    goto after_138;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_138:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80041A54:
    // lhu         $a1, 0x20($s3)
    ctx->r5 = MEM_HU(0X20, ctx->r19);
    // lhu         $a2, 0x10($s4)
    ctx->r6 = MEM_HU(0X10, ctx->r20);
    // lbu         $a3, 0x4($s5)
    ctx->r7 = MEM_BU(0X4, ctx->r21);
    // jal         0x8003E608
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003E608(rdram, ctx);
    goto after_139;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_139:
    // lh          $v1, 0x42($s3)
    ctx->r3 = MEM_H(0X42, ctx->r19);
    // lhu         $v0, 0x20($s3)
    ctx->r2 = MEM_HU(0X20, ctx->r19);
    // nop

    // bne         $v1, $v0, L_80041E1C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80041E1C;
    }
    // nop

    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
L_80041A80:
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_140;
    // nop

    after_140:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_80041E1C
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80041E1C;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80041A94:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_141;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_141:
    // lhu         $a0, 0x12($s5)
    ctx->r4 = MEM_HU(0X12, ctx->r21);
    // lhu         $a1, 0x12($s4)
    ctx->r5 = MEM_HU(0X12, ctx->r20);
    // lhu         $a2, 0x18($s3)
    ctx->r6 = MEM_HU(0X18, ctx->r19);
    // jal         0x80015D18
    // nop

    FixedPointLerp(rdram, ctx);
    goto after_142;
    // nop

    after_142:
    // sh          $v0, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r2;
    // lhu         $a0, 0x14($s5)
    ctx->r4 = MEM_HU(0X14, ctx->r21);
    // lhu         $a1, 0x14($s4)
    ctx->r5 = MEM_HU(0X14, ctx->r20);
    // lhu         $a2, 0x18($s3)
    ctx->r6 = MEM_HU(0X18, ctx->r19);
    // jal         0x80015D18
    // nop

    FixedPointLerp(rdram, ctx);
    goto after_143;
    // nop

    after_143:
    // lhu         $v1, 0x18($s3)
    ctx->r3 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 < 0XFFF ? 1 : 0;
    // bne         $v1, $zero, L_80041E1C
    if (ctx->r3 != 0) {
        // sh          $v0, 0x1E($s3)
        MEM_H(0X1E, ctx->r19) = ctx->r2;
        goto L_80041E1C;
    }
    // sh          $v0, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x12($s4)
    ctx->r2 = MEM_HU(0X12, ctx->r20);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sh          $v0, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // ori         $a1, $zero, 0x15
    ctx->r5 = 0 | 0X15;
    // jal         0x8003C184
    // sh          $v0, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r2;
    EntityClass_GetActionSequence(rdram, ctx);
    goto after_144;
    // sh          $v0, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = ctx->r2;
    after_144:
    // beq         $v0, $zero, L_800412A8
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_800412A8;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8003BB60
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    Entity_ApplySequence(rdram, ctx);
    goto after_145;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_145:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80041B14:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041B44
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041B44;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_146;
    // nop

    after_146:
    // jal         0x8003E038
    // nop

    sub_8003E038(rdram, ctx);
    goto after_147;
    // nop

    after_147:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sh          $v0, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r2;
L_80041B44:
    // lhu         $v0, 0x40($s3)
    ctx->r2 = MEM_HU(0X40, ctx->r19);
    // lhu         $v1, 0x42($s3)
    ctx->r3 = MEM_HU(0X42, ctx->r19);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x40($s3)
    MEM_H(0X40, ctx->r19) = ctx->r2;
    // lw          $v0, 0x30($s3)
    ctx->r2 = MEM_W(0X30, ctx->r19);
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // sh          $v1, 0x42($s3)
    MEM_H(0X42, ctx->r19) = ctx->r3;
    // lhu         $v1, 0x72($s3)
    ctx->r3 = MEM_HU(0X72, ctx->r19);
L_80041B64:
    // addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sh          $v1, 0x72($s3)
    MEM_H(0X72, ctx->r19) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // bne         $v1, $zero, L_80041E1C
    if (ctx->r3 != 0) {
        // sw          $v0, 0x30($s3)
        MEM_W(0X30, ctx->r19) = ctx->r2;
        goto L_80041E1C;
    }
    // sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // j           L_800412A8
    // nop

    goto L_800412A8;
    // nop

L_80041B84:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041BC8
    if (ctx->r2 != 0) {
        // addiu       $a0, $s3, 0x50
        ctx->r4 = ADD32(ctx->r19, 0X50);
        goto L_80041BC8;
    }
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_148;
    // nop

    after_148:
    // jal         0x8003E038
    // nop

    sub_8003E038(rdram, ctx);
    goto after_149;
    // nop

    after_149:
    // ori         $a0, $zero, 0x1B
    ctx->r4 = 0 | 0X1B;
    // addiu       $a1, $s3, 0x2C
    ctx->r5 = ADD32(ctx->r19, 0X2C);
    // ori         $a2, $zero, 0x78
    ctx->r6 = 0 | 0X78;
    // jal         0x800143E0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800143E0(rdram, ctx);
    goto after_150;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_150:
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
L_80041BC8:
    // lhu         $v0, 0x40($s3)
    ctx->r2 = MEM_HU(0X40, ctx->r19);
    // lhu         $v1, 0x42($s3)
    ctx->r3 = MEM_HU(0X42, ctx->r19);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // sh          $v0, 0x40($s3)
    MEM_H(0X40, ctx->r19) = ctx->r2;
    // jal         0x8003DDB0
    // sh          $v1, 0x42($s3)
    MEM_H(0X42, ctx->r19) = ctx->r3;
    sub_8003DDB0(rdram, ctx);
    goto after_151;
    // sh          $v1, 0x42($s3)
    MEM_H(0X42, ctx->r19) = ctx->r3;
    after_151:
    // beq         $v0, $zero, L_80041E1C
    if (ctx->r2 == 0) {
        // andi        $v0, $v0, 0x80
        ctx->r2 = ctx->r2 & 0X80;
        goto L_80041E1C;
    }
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80041C58
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80041C58;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // lhu         $a0, 0xE($s4)
    ctx->r4 = MEM_HU(0XE, ctx->r20);
    // lhu         $a1, 0x10($s4)
    ctx->r5 = MEM_HU(0X10, ctx->r20);
    // lhu         $a2, 0x12($s4)
    ctx->r6 = MEM_HU(0X12, ctx->r20);
    // lhu         $a3, 0xC($s4)
    ctx->r7 = MEM_HU(0XC, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1A($s4)
    ctx->r2 = MEM_HU(0X1A, ctx->r20);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x1C($s4)
    ctx->r3 = MEM_HU(0X1C, ctx->r20);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $s3, 0x2C
    ctx->r2 = ADD32(ctx->r19, 0X2C);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // jal         0x80027344
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    ApplyStatusEffect(rdram, ctx);
    goto after_152;
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_152:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80041C58:
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    Entity_ChangeState(rdram, ctx);
    goto after_153;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    after_153:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // sh          $zero, 0x54($s3)
    MEM_H(0X54, ctx->r19) = 0;
    // sh          $zero, 0x52($s3)
    MEM_H(0X52, ctx->r19) = 0;
    // sh          $zero, 0x50($s3)
    MEM_H(0X50, ctx->r19) = 0;
    // j           L_80041E1C
    // sb          $v0, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r2;
    goto L_80041E1C;
    // sb          $v0, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r2;
L_80041C78:
    // lbu         $v0, 0xF($s3)
    ctx->r2 = MEM_BU(0XF, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80041CA0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80041CA0;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // jal         0x8003C250
    // nop

    sub_8003C250(rdram, ctx);
    goto after_154;
    // nop

    after_154:
    // jal         0x8003E038
    // nop

    sub_8003E038(rdram, ctx);
    goto after_155;
    // nop

    after_155:
L_80041CA0:
    // lh          $v0, 0x50($s3)
    ctx->r2 = MEM_H(0X50, ctx->r19);
    // lw          $v1, 0x2C($s3)
    ctx->r3 = MEM_W(0X2C, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lh          $v0, 0x52($s3)
    ctx->r2 = MEM_H(0X52, ctx->r19);
    // lw          $v1, 0x30($s3)
    ctx->r3 = MEM_W(0X30, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x54($s3)
    ctx->r2 = MEM_H(0X54, ctx->r19);
    // lw          $v1, 0x34($s3)
    ctx->r3 = MEM_W(0X34, ctx->r19);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // lhu         $a3, 0x1C($s3)
    ctx->r7 = MEM_HU(0X1C, ctx->r19);
    // lhu         $v1, 0x1E($s3)
    ctx->r3 = MEM_HU(0X1E, ctx->r19);
    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(0X48, ctx->r29);
    // lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(0X4C, ctx->r29);
    // lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(0X50, ctx->r29);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_156;
    // nop

    after_156:
    // bne         $v0, $zero, L_80041D40
    if (ctx->r2 != 0) {
        // andi        $v0, $v0, 0x80
        ctx->r2 = ctx->r2 & 0X80;
        goto L_80041D40;
    }
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
L_80041D1C:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // nop

    // sw          $v0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r2;
    // lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(0X4C, ctx->r29);
    // nop

    // sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // j           L_80041DBC
    // sw          $v0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r2;
    goto L_80041DBC;
    // sw          $v0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r2;
L_80041D40:
    // beq         $v0, $zero, L_80041DB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041DB0;
    }
    // nop

    // lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(0X14, ctx->r20);
    // lhu         $a0, 0xE($s4)
    ctx->r4 = MEM_HU(0XE, ctx->r20);
    // lhu         $a1, 0x10($s4)
    ctx->r5 = MEM_HU(0X10, ctx->r20);
    // lhu         $a2, 0x12($s4)
    ctx->r6 = MEM_HU(0X12, ctx->r20);
    // lhu         $a3, 0xC($s4)
    ctx->r7 = MEM_HU(0XC, ctx->r20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($s4)
    ctx->r2 = MEM_HU(0X16, ctx->r20);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1A($s4)
    ctx->r2 = MEM_HU(0X1A, ctx->r20);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x1C($s4)
    ctx->r3 = MEM_HU(0X1C, ctx->r20);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $s3, 0x2C
    ctx->r2 = ADD32(ctx->r19, 0X2C);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // jal         0x80027344
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    ApplyStatusEffect(rdram, ctx);
    goto after_157;
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_157:
    // j           L_80041D1C
    // nop

    goto L_80041D1C;
    // nop

L_80041DB0:
    // sh          $zero, 0x54($s3)
    MEM_H(0X54, ctx->r19) = 0;
    // sh          $zero, 0x52($s3)
    MEM_H(0X52, ctx->r19) = 0;
    // sh          $zero, 0x50($s3)
    MEM_H(0X50, ctx->r19) = 0;
L_80041DBC:
    // lh          $a1, 0x8($s4)
    ctx->r5 = MEM_H(0X8, ctx->r20);
    // jal         0x8003D858
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8003D858(rdram, ctx);
    goto after_158;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_158:
    // lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(0X18, ctx->r19);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80041E1C
    if (ctx->r2 != 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80041E1C;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    Entity_ChangeState(rdram, ctx);
    goto after_159;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    after_159:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80041E1C
    // sb          $v0, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r2;
    goto L_80041E1C;
    // sb          $v0, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r2;
L_80041DF0:
    // jal         0x8003E038
    // nop

    sub_8003E038(rdram, ctx);
    goto after_160;
    // nop

    after_160:
    // j           L_80041E1C
    // nop

    goto L_80041E1C;
    // nop

L_80041E00:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_161;
    // nop

    after_161:
L_80041E1C:
    // lw          $v1, 0x28($s3)
    ctx->r3 = MEM_W(0X28, ctx->r19);
    // nop

    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_80042000
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80042000;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79BC($s0)
    ctx->r16 = MEM_W(0X79BC, ctx->r16);
    // bne         $a0, $v0, L_80041E88
    if (ctx->r4 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80041E88;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $zero, 0x3($s3)
    MEM_B(0X3, ctx->r19) = 0;
    // lbu         $v1, 0x9($s0)
    ctx->r3 = MEM_BU(0X9, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80041E60
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80041E60;
    }
    // nop

    // j           L_80042018
    // sb          $zero, 0x9($s3)
    MEM_B(0X9, ctx->r19) = 0;
    goto L_80042018;
    // sb          $zero, 0x9($s3)
    MEM_B(0X9, ctx->r19) = 0;
L_80041E60:
    // lbu         $v0, 0xE($s0)
    ctx->r2 = MEM_BU(0XE, ctx->r16);
    // nop

    // bne         $v0, $a0, L_80041F5C
    if (ctx->r2 != ctx->r4) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80041F5C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0xE($s3)
    MEM_B(0XE, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // j           L_80042018
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
    goto L_80042018;
    // sh          $v0, 0x70($s3)
    MEM_H(0X70, ctx->r19) = ctx->r2;
L_80041E88:
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // nop

    // sb          $v0, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r2;
    // lbu         $v1, 0x9($s0)
    ctx->r3 = MEM_BU(0X9, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80041F5C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v1, $zero, -0x11
        ctx->r3 = ADD32(0, -0X11);
        goto L_80041F5C;
    }
    // addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // lhu         $a3, 0x1C($s3)
    ctx->r7 = MEM_HU(0X1C, ctx->r19);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lhu         $v1, 0x1E($s3)
    ctx->r3 = MEM_HU(0X1E, ctx->r19);
    // ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // sw          $v0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0x81
    ctx->r2 = 0 | 0X81;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(0X30, ctx->r19);
    // lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(0X34, ctx->r19);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_162;
    // nop

    after_162:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // beq         $v0, $zero, L_80041F04
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0xF
        ctx->r2 = ctx->r4 & 0XF;
        goto L_80041F04;
    }
    // andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(0X2C, ctx->r19);
    // lhu         $v1, 0x1C($s3)
    ctx->r3 = MEM_HU(0X1C, ctx->r19);
    // addiu       $v0, $v0, 0x320
    ctx->r2 = ADD32(ctx->r2, 0X320);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r2;
    // andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
L_80041F04:
    // beq         $v0, $zero, L_80041F1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041F1C;
    }
    // nop

    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // nop

    // ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // sw          $v0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r2;
L_80041F1C:
    // lw          $v0, 0x28($s3)
    ctx->r2 = MEM_W(0X28, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_80041F38
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80041F38;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    Entity_ChangeState(rdram, ctx);
    goto after_163;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    after_163:
L_80041F38:
    // lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(0X50, ctx->r16);
    // nop

    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x52($s0)
    ctx->r2 = MEM_HU(0X52, ctx->r16);
    // nop

    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(0X54, ctx->r16);
    // j           L_80042018
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    goto L_80042018;
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
L_80041F5C:
    // lwl         $v0, 0x43($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X43, ctx->r16);
    // lwr         $v0, 0x40($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X40, ctx->r16);
    // lwl         $v1, 0x47($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X47, ctx->r16);
    // lwr         $v1, 0x44($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X44, ctx->r16);
    // swl         $v0, 0x43($s3)
    do_swl(rdram, 0X43, ctx->r19, ctx->r2);
    // swr         $v0, 0x40($s3)
    do_swr(rdram, 0X40, ctx->r19, ctx->r2);
    // swl         $v1, 0x47($s3)
    do_swl(rdram, 0X47, ctx->r19, ctx->r3);
    // swr         $v1, 0x44($s3)
    do_swr(rdram, 0X44, ctx->r19, ctx->r3);
    // lhu         $v0, 0x40($s3)
    ctx->r2 = MEM_HU(0X40, ctx->r19);
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x42($s3)
    ctx->r2 = MEM_HU(0X42, ctx->r19);
    // addiu       $a1, $s5, 0xC
    ctx->r5 = ADD32(ctx->r21, 0XC);
    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x44($s3)
    ctx->r2 = MEM_HU(0X44, ctx->r19);
    // addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // jal         0x80015614
    // sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    sub_80015614(rdram, ctx);
    goto after_164;
    // sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    after_164:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lh          $a1, 0x24($s3)
    ctx->r5 = MEM_H(0X24, ctx->r19);
    // jal         0x8003EAC0
    // addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    sub_8003EAC0(rdram, ctx);
    goto after_165;
    // addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_165:
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(0X68, ctx->r29);
    // lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(0X58, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r2;
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(0X6C, ctx->r29);
    // lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(0X5C, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(0X70, ctx->r29);
    // lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(0X60, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // j           L_80042018
    // sw          $v0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r2;
    goto L_80042018;
    // sw          $v0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r2;
L_80042000:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // bne         $v0, $zero, L_80042018
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042018;
    }
    // nop

    // jal         0x8003E04C
    // nop

    UpdateObjectVerticalMovement(rdram, ctx);
    goto after_166;
    // nop

    after_166:
L_80042018:
    // lbu         $v1, 0x9($s3)
    ctx->r3 = MEM_BU(0X9, ctx->r19);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8004203C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004203C;
    }
    // nop

    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(0X34, ctx->r19);
    // lhu         $a2, 0x1C($s3)
    ctx->r6 = MEM_HU(0X1C, ctx->r19);
    // jal         0x8002E25C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_167;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_167:
L_8004203C:
    // lw          $ra, 0xA0($sp)
    ctx->r31 = MEM_W(0XA0, ctx->r29);
    // lw          $s5, 0x9C($sp)
    ctx->r21 = MEM_W(0X9C, ctx->r29);
    // lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(0X98, ctx->r29);
    // lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(0X94, ctx->r29);
    // lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(0X90, ctx->r29);
    // lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(0X8C, ctx->r29);
    // lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(0X88, ctx->r29);
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // jr          $ra
    // nop

    return;
    // nop

;}
