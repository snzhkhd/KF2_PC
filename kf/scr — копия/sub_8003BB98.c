#include "recomp.h"
#include "disable_warnings.h"

void sub_8003BB98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // lw          $s2, 0x79B4($s2)
    ctx->r18 = MEM_W(0X79B4, ctx->r18);
    // bne         $v1, $v0, L_8003BBD4
    if (ctx->r3 != ctx->r2) {
        // addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
        goto L_8003BBD4;
    }
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // j           L_8003C018
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8003C018;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003BBD4:
    // addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // sltiu       $v0, $v1, 0x83
    ctx->r2 = ctx->r3 < 0X83 ? 1 : 0;
    // beq         $v0, $zero, L_8003BFB0
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003BFB0;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1DD4
    ctx->r1 = ADD32(ctx->r1, 0X1DD4);
    // addu        $at, $at, $v0
    gpr jr_addend_8003BBF8;
    jr_addend_8003BBF8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003BBF8 >> 2) {
        case 0: goto L_8003BFA8; break;
        case 1: goto L_8003BFA8; break;
        case 2: goto L_8003BD30; break;
        case 3: goto L_8003BC00; break;
        case 4: goto L_8003BFB0; break;
        case 5: goto L_8003BFB0; break;
        case 6: goto L_8003BFB0; break;
        case 7: goto L_8003BC9C; break;
        case 8: goto L_8003BFB0; break;
        case 9: goto L_8003BEBC; break;
        case 10: goto L_8003BFB0; break;
        case 11: goto L_8003BC00; break;
        case 12: goto L_8003BFB0; break;
        case 13: goto L_8003BFB0; break;
        case 14: goto L_8003BFB0; break;
        case 15: goto L_8003BFB0; break;
        case 16: goto L_8003BD30; break;
        case 17: goto L_8003BF18; break;
        case 18: goto L_8003BF18; break;
        case 19: goto L_8003BFB0; break;
        case 20: goto L_8003BFA8; break;
        case 21: goto L_8003BD30; break;
        case 22: goto L_8003BD30; break;
        case 23: goto L_8003BE34; break;
        case 24: goto L_8003BFB0; break;
        case 25: goto L_8003BF94; break;
        case 26: goto L_8003BFB0; break;
        case 27: goto L_8003BFB0; break;
        case 28: goto L_8003BFB0; break;
        case 29: goto L_8003BFB0; break;
        case 30: goto L_8003BFB0; break;
        case 31: goto L_8003BFB0; break;
        case 32: goto L_8003BFB0; break;
        case 33: goto L_8003BFB0; break;
        case 34: goto L_8003BFB0; break;
        case 35: goto L_8003BFB0; break;
        case 36: goto L_8003BFB0; break;
        case 37: goto L_8003BFB0; break;
        case 38: goto L_8003BFB0; break;
        case 39: goto L_8003BFB0; break;
        case 40: goto L_8003BFB0; break;
        case 41: goto L_8003BFB0; break;
        case 42: goto L_8003BFB0; break;
        case 43: goto L_8003BFB0; break;
        case 44: goto L_8003BFB0; break;
        case 45: goto L_8003BFB0; break;
        case 46: goto L_8003BFB0; break;
        case 47: goto L_8003BFB0; break;
        case 48: goto L_8003BFB0; break;
        case 49: goto L_8003BFB0; break;
        case 50: goto L_8003BFB0; break;
        case 51: goto L_8003BFB0; break;
        case 52: goto L_8003BFB0; break;
        case 53: goto L_8003BFB0; break;
        case 54: goto L_8003BFB0; break;
        case 55: goto L_8003BFB0; break;
        case 56: goto L_8003BFB0; break;
        case 57: goto L_8003BFB0; break;
        case 58: goto L_8003BFB0; break;
        case 59: goto L_8003BFB0; break;
        case 60: goto L_8003BFB0; break;
        case 61: goto L_8003BFB0; break;
        case 62: goto L_8003BFB0; break;
        case 63: goto L_8003BFB0; break;
        case 64: goto L_8003BFB0; break;
        case 65: goto L_8003BFB0; break;
        case 66: goto L_8003BFB0; break;
        case 67: goto L_8003BFB0; break;
        case 68: goto L_8003BFB0; break;
        case 69: goto L_8003BFB0; break;
        case 70: goto L_8003BFB0; break;
        case 71: goto L_8003BFB0; break;
        case 72: goto L_8003BFB0; break;
        case 73: goto L_8003BFB0; break;
        case 74: goto L_8003BFB0; break;
        case 75: goto L_8003BFB0; break;
        case 76: goto L_8003BFB0; break;
        case 77: goto L_8003BFB0; break;
        case 78: goto L_8003BFB0; break;
        case 79: goto L_8003BFB0; break;
        case 80: goto L_8003BFB0; break;
        case 81: goto L_8003BFB0; break;
        case 82: goto L_8003BFB0; break;
        case 83: goto L_8003BFB0; break;
        case 84: goto L_8003BFB0; break;
        case 85: goto L_8003BFB0; break;
        case 86: goto L_8003BFB0; break;
        case 87: goto L_8003BFB0; break;
        case 88: goto L_8003BFB0; break;
        case 89: goto L_8003BFB0; break;
        case 90: goto L_8003BFB0; break;
        case 91: goto L_8003BFB0; break;
        case 92: goto L_8003BFB0; break;
        case 93: goto L_8003BFB0; break;
        case 94: goto L_8003BFB0; break;
        case 95: goto L_8003BFB0; break;
        case 96: goto L_8003BFB0; break;
        case 97: goto L_8003BFB0; break;
        case 98: goto L_8003BFB0; break;
        case 99: goto L_8003BFB0; break;
        case 100: goto L_8003BFB0; break;
        case 101: goto L_8003BFB0; break;
        case 102: goto L_8003BFB0; break;
        case 103: goto L_8003BFB0; break;
        case 104: goto L_8003BFB0; break;
        case 105: goto L_8003BFB0; break;
        case 106: goto L_8003BFB0; break;
        case 107: goto L_8003BFB0; break;
        case 108: goto L_8003BFB0; break;
        case 109: goto L_8003BFB0; break;
        case 110: goto L_8003BF8C; break;
        case 111: goto L_8003BFB0; break;
        case 112: goto L_8003BFB0; break;
        case 113: goto L_8003BFB0; break;
        case 114: goto L_8003BFB0; break;
        case 115: goto L_8003BFB0; break;
        case 116: goto L_8003BFB0; break;
        case 117: goto L_8003BFB0; break;
        case 118: goto L_8003BFB0; break;
        case 119: goto L_8003BFB0; break;
        case 120: goto L_8003BFB0; break;
        case 121: goto L_8003BFB0; break;
        case 122: goto L_8003BFB0; break;
        case 123: goto L_8003BFB0; break;
        case 124: goto L_8003BFB0; break;
        case 125: goto L_8003BFB0; break;
        case 126: goto L_8003BFB0; break;
        case 127: goto L_8003BFB0; break;
        case 128: goto L_8003BFB0; break;
        case 129: goto L_8003BFB0; break;
        case 130: goto L_8003BD30; break;
        default: switch_error(__func__, 0x8003BBF8, 0x80011DD4);
    }
    // nop

L_8003BC00:
    // lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(0X60, ctx->r18);
    // nop

    // bne         $s1, $v0, L_8003BC30
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_8003BC30;
    }
    // nop

    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003C014
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003C014;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(0X3, ctx->r17);
    // j           L_8003C008
    // nop

    goto L_8003C008;
    // nop

L_8003BC30:
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003BC54
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003BC54;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(0X2, ctx->r17);
    // jal         0x80015C80
    // nop

    AI_GetRandomizedWeight(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8003BC54:
    // lbu         $v1, 0xE($s2)
    ctx->r3 = MEM_BU(0XE, ctx->r18);
    // nop

    // slti        $v0, $v1, 0x19
    ctx->r2 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
    // beq         $v0, $zero, L_8003BC88
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x17
        ctx->r2 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
        goto L_8003BC88;
    }
    // slti        $v0, $v1, 0x17
    ctx->r2 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
    // beq         $v0, $zero, L_8003BC94
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8003BC94;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $v1, $v0, L_8003BC94
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x12
        ctx->r2 = 0 | 0X12;
        goto L_8003BC94;
    }
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // beq         $v1, $v0, L_8003BC94
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003BC94;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // j           L_8003C018
    // nop

    goto L_8003C018;
    // nop

L_8003BC88:
    // ori         $v0, $zero, 0x84
    ctx->r2 = 0 | 0X84;
    // bne         $v1, $v0, L_8003C018
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003C018;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8003BC94:
    // j           L_8003C014
    // sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16) << 1;
    goto L_8003C014;
    // sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16) << 1;
L_8003BC9C:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003BFA8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BFA8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(0X30, ctx->r18);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_8003BCE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BCE8;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_8003C018
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003C018;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8003BCE8:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(0X34, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_2;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_2:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lh          $a0, 0x42($s2)
    ctx->r4 = MEM_H(0X42, ctx->r18);
    // jal         0x80015798
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    Math_IsAngleInRange(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    after_3:
    // bne         $v0, $zero, L_8003BFE8
    if (ctx->r2 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003BFE8;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // j           L_8003C018
    // nop

    goto L_8003C018;
    // nop

L_8003BD30:
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // bne         $v0, $zero, L_8003C014
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003C014;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lhu         $v0, 0x1A($s1)
    ctx->r2 = MEM_HU(0X1A, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003C014
    if (ctx->r2 != 0) {
        // ori         $a3, $zero, 0x834
        ctx->r7 = 0 | 0X834;
        goto L_8003C014;
    }
    // ori         $a3, $zero, 0x834
    ctx->r7 = 0 | 0X834;
    // lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(0X30, ctx->r18);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A60($a2)
    ctx->r6 = MEM_W(-0X4A60, ctx->r6);
    // lhu         $a1, 0x1E($s2)
    ctx->r5 = MEM_HU(0X1E, ctx->r18);
    // jal         0x80015A58
    // addiu       $a2, $a2, 0xC8
    ctx->r6 = ADD32(ctx->r6, 0XC8);
    Math_IsTargetInVerticalRange(rdram, ctx);
    goto after_4;
    // addiu       $a2, $a2, 0xC8
    ctx->r6 = ADD32(ctx->r6, 0XC8);
    after_4:
    // beq         $v0, $zero, L_8003BFA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BFA8;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(0X34, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_5;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_5:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lbu         $a2, 0x10($s1)
    ctx->r6 = MEM_BU(0X10, ctx->r17);
    // lh          $a0, 0x42($s2)
    ctx->r4 = MEM_H(0X42, ctx->r18);
    // jal         0x80015798
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    Math_IsAngleInRange(rdram, ctx);
    goto after_6;
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    after_6:
    // beq         $v0, $zero, L_8003BFA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BFA8;
    }
    // nop

    // lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(0X60, ctx->r18);
    // nop

    // bne         $s1, $v0, L_8003BDD8
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_8003BDD8;
    }
    // nop

    // lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(0X3, ctx->r17);
    // j           L_8003C008
    // nop

    goto L_8003C008;
    // nop

L_8003BDD8:
    // lbu         $s0, 0x2($s1)
    ctx->r16 = MEM_BU(0X2, ctx->r17);
    // lbu         $v1, 0xE($s1)
    ctx->r3 = MEM_BU(0XE, ctx->r17);
    // lhu         $v0, 0x1A($s1)
    ctx->r2 = MEM_HU(0X1A, ctx->r17);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003BE04
    if (ctx->r2 != 0) {
        // lui         $v0, 0x5555
        ctx->r2 = S32(0X5555 << 16);
        goto L_8003BE04;
    }
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // j           L_8003BE18
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    goto L_8003BE18;
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
L_8003BE04:
    // slt         $v0, $s3, $v1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8003C008
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003C008;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
L_8003BE18:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $s0, 31
    ctx->r3 = S32(ctx->r16) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // j           L_8003C008
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_8003C008;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8003BE34:
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // bne         $v0, $zero, L_8003C014
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003C014;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lhu         $v0, 0x16($s1)
    ctx->r2 = MEM_HU(0X16, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003C018
    if (ctx->r2 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003C018;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // nop

    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003C018
    if (ctx->r2 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003C018;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(0X34, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_7;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_7:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lbu         $a2, 0xD($s1)
    ctx->r6 = MEM_BU(0XD, ctx->r17);
    // lh          $a0, 0x42($s2)
    ctx->r4 = MEM_H(0X42, ctx->r18);
    // jal         0x80015798
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    Math_IsAngleInRange(rdram, ctx);
    goto after_8;
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    after_8:
    // bne         $v0, $zero, L_8003BFE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BFE8;
    }
    // nop

    // j           L_8003C014
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_8003C014;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003BEBC:
    // lhu         $v0, 0x1A($s1)
    ctx->r2 = MEM_HU(0X1A, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003C014
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003C014;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(0X34, ctx->r18);
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
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lh          $a0, 0x42($s2)
    ctx->r4 = MEM_H(0X42, ctx->r18);
    // jal         0x80015798
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    Math_IsAngleInRange(rdram, ctx);
    goto after_10;
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    after_10:
    // bne         $v0, $zero, L_8003BFE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BFE8;
    }
    // nop

    // j           L_8003C014
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_8003C014;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003BF18:
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8003C014
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003C014;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AAC($v1)
    ctx->r3 = MEM_H(-0X4AAC, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8003C018
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003C018;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(0X34, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_11;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_11:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lbu         $a2, 0xC($s1)
    ctx->r6 = MEM_BU(0XC, ctx->r17);
    // lh          $a0, 0x42($s2)
    ctx->r4 = MEM_H(0X42, ctx->r18);
    // jal         0x80015798
    // sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6) << 5;
    Math_IsAngleInRange(rdram, ctx);
    goto after_12;
    // sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6) << 5;
    after_12:
    // bne         $v0, $zero, L_8003BFE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BFE8;
    }
    // nop

    // j           L_8003C014
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_8003C014;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003BF8C:
    // j           L_8003C014
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    goto L_8003C014;
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_8003BF94:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003BFE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BFE8;
    }
    // nop

L_8003BFA8:
    // j           L_8003C014
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_8003C014;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003BFB0:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8003BFE8
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003BFE8;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(0X40, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_13;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_13:
    // beq         $v0, $zero, L_8003C018
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8003C018;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8003BFE8:
    // lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(0X60, ctx->r18);
    // nop

    // bne         $s1, $v0, L_8003C004
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_8003C004;
    }
    // nop

    // lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(0X3, ctx->r17);
    // j           L_8003C008
    // nop

    goto L_8003C008;
    // nop

L_8003C004:
    // lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(0X2, ctx->r17);
L_8003C008:
    // jal         0x80015C80
    // nop

    AI_GetRandomizedWeight(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8003C014:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8003C018:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
