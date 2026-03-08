#include "recomp.h"
#include "disable_warnings.h"

void sub_8005A400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) >> 14;
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // addu        $s5, $v0, $v1
    ctx->r21 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(0X4, ctx->r21);
    // lbu         $s0, 0x12($s5)
    ctx->r16 = MEM_BU(0X12, ctx->r21);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r2;
    // lbu         $s3, 0x0($v1)
    ctx->r19 = MEM_BU(0X0, ctx->r3);
    // ori         $v0, $zero, 0x79
    ctx->r2 = 0 | 0X79;
    // sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // bne         $v0, $zero, L_8005A6D8
    if (ctx->r2 != 0) {
        // addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
        goto L_8005A6D8;
    }
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x32FC
    ctx->r1 = ADD32(ctx->r1, 0X32FC);
    // addu        $at, $at, $v0
    gpr jr_addend_8005A4A4;
    jr_addend_8005A4A4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8005A4A4 >> 2) {
        case 0: goto L_8005A4AC; break;
        case 1: goto L_8005A6D8; break;
        case 2: goto L_8005A6D8; break;
        case 3: goto L_8005A6D8; break;
        case 4: goto L_8005A6D8; break;
        case 5: goto L_8005A6D8; break;
        case 6: goto L_8005A4B4; break;
        case 7: goto L_8005A4D4; break;
        case 8: goto L_8005A6D8; break;
        case 9: goto L_8005A6D8; break;
        case 10: goto L_8005A528; break;
        case 11: goto L_8005A57C; break;
        case 12: goto L_8005A6D8; break;
        case 13: goto L_8005A6D8; break;
        case 14: goto L_8005A6D8; break;
        case 15: goto L_8005A6D8; break;
        case 16: goto L_8005A6D8; break;
        case 17: goto L_8005A6D8; break;
        case 18: goto L_8005A6D8; break;
        case 19: goto L_8005A6D8; break;
        case 20: goto L_8005A6D8; break;
        case 21: goto L_8005A6D8; break;
        case 22: goto L_8005A6D8; break;
        case 23: goto L_8005A6D8; break;
        case 24: goto L_8005A6D8; break;
        case 25: goto L_8005A6D8; break;
        case 26: goto L_8005A6D8; break;
        case 27: goto L_8005A6D8; break;
        case 28: goto L_8005A6D8; break;
        case 29: goto L_8005A6D8; break;
        case 30: goto L_8005A6D8; break;
        case 31: goto L_8005A6D8; break;
        case 32: goto L_8005A6D8; break;
        case 33: goto L_8005A6D8; break;
        case 34: goto L_8005A6D8; break;
        case 35: goto L_8005A6D8; break;
        case 36: goto L_8005A6D8; break;
        case 37: goto L_8005A6D8; break;
        case 38: goto L_8005A6D8; break;
        case 39: goto L_8005A6D8; break;
        case 40: goto L_8005A6D8; break;
        case 41: goto L_8005A6D8; break;
        case 42: goto L_8005A6D8; break;
        case 43: goto L_8005A6D8; break;
        case 44: goto L_8005A6D8; break;
        case 45: goto L_8005A6D8; break;
        case 46: goto L_8005A6D8; break;
        case 47: goto L_8005A6D8; break;
        case 48: goto L_8005A6D8; break;
        case 49: goto L_8005A6D8; break;
        case 50: goto L_8005A6D8; break;
        case 51: goto L_8005A6D8; break;
        case 52: goto L_8005A6D8; break;
        case 53: goto L_8005A6D8; break;
        case 54: goto L_8005A6D8; break;
        case 55: goto L_8005A6D8; break;
        case 56: goto L_8005A6D8; break;
        case 57: goto L_8005A6D8; break;
        case 58: goto L_8005A6D8; break;
        case 59: goto L_8005A6D8; break;
        case 60: goto L_8005A6D8; break;
        case 61: goto L_8005A6D8; break;
        case 62: goto L_8005A6D8; break;
        case 63: goto L_8005A6D8; break;
        case 64: goto L_8005A5DC; break;
        case 65: goto L_8005A608; break;
        case 66: goto L_8005A6D8; break;
        case 67: goto L_8005A6D8; break;
        case 68: goto L_8005A6D8; break;
        case 69: goto L_8005A6D8; break;
        case 70: goto L_8005A6D8; break;
        case 71: goto L_8005A6D8; break;
        case 72: goto L_8005A6D8; break;
        case 73: goto L_8005A6D8; break;
        case 74: goto L_8005A6D8; break;
        case 75: goto L_8005A6D8; break;
        case 76: goto L_8005A6D8; break;
        case 77: goto L_8005A6D8; break;
        case 78: goto L_8005A6D8; break;
        case 79: goto L_8005A6D8; break;
        case 80: goto L_8005A6D8; break;
        case 81: goto L_8005A6D8; break;
        case 82: goto L_8005A6D8; break;
        case 83: goto L_8005A6D8; break;
        case 84: goto L_8005A6D8; break;
        case 85: goto L_8005A6D8; break;
        case 86: goto L_8005A6D8; break;
        case 87: goto L_8005A6D8; break;
        case 88: goto L_8005A6D8; break;
        case 89: goto L_8005A6D8; break;
        case 90: goto L_8005A6D8; break;
        case 91: goto L_8005A628; break;
        case 92: goto L_8005A6D8; break;
        case 93: goto L_8005A6D8; break;
        case 94: goto L_8005A6D8; break;
        case 95: goto L_8005A6D8; break;
        case 96: goto L_8005A6D8; break;
        case 97: goto L_8005A6D8; break;
        case 98: goto L_8005A63C; break;
        case 99: goto L_8005A65C; break;
        case 100: goto L_8005A67C; break;
        case 101: goto L_8005A69C; break;
        case 102: goto L_8005A6D8; break;
        case 103: goto L_8005A6D8; break;
        case 104: goto L_8005A6D8; break;
        case 105: goto L_8005A6D8; break;
        case 106: goto L_8005A6D8; break;
        case 107: goto L_8005A6D8; break;
        case 108: goto L_8005A6D8; break;
        case 109: goto L_8005A6D8; break;
        case 110: goto L_8005A6D8; break;
        case 111: goto L_8005A6D8; break;
        case 112: goto L_8005A6D8; break;
        case 113: goto L_8005A6D8; break;
        case 114: goto L_8005A6D8; break;
        case 115: goto L_8005A6D8; break;
        case 116: goto L_8005A6D8; break;
        case 117: goto L_8005A6D8; break;
        case 118: goto L_8005A6D8; break;
        case 119: goto L_8005A6D8; break;
        case 120: goto L_8005A6D8; break;
        case 121: goto L_8005A6BC; break;
        default: switch_error(__func__, 0x8005A4A4, 0x800132FC);
    }
    // nop

L_8005A4AC:
    // j           L_8005A6D8
    // sh          $s3, 0x4C($s5)
    MEM_H(0X4C, ctx->r21) = ctx->r19;
    goto L_8005A6D8;
    // sh          $s3, 0x4C($s5)
    MEM_H(0X4C, ctx->r21) = ctx->r19;
L_8005A4B4:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8005AEE0
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_8005AEE0(rdram, ctx);
    goto after_0;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_0:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A4D4:
    // sll         $s2, $s1, 16
    ctx->r18 = S32(ctx->r17) << 16;
    // sra         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18) >> 16;
    // sll         $a0, $s2, 8
    ctx->r4 = S32(ctx->r18) << 8;
    // sll         $s1, $s4, 16
    ctx->r17 = S32(ctx->r20) << 16;
    // addu        $v0, $s5, $s0
    ctx->r2 = ADD32(ctx->r21, ctx->r16);
    // lbu         $a2, 0x2C($v0)
    ctx->r6 = MEM_BU(0X2C, ctx->r2);
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // lh          $a1, 0x4C($s5)
    ctx->r5 = MEM_H(0X4C, ctx->r21);
    // lbu         $v0, 0x17($v0)
    ctx->r2 = MEM_BU(0X17, ctx->r2);
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x80058120
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80058120(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16) << 1;
    // addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // sh          $s3, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r19;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8005BB50
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_8005BB50(rdram, ctx);
    goto after_2;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // j           L_8005A6F0
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
    goto L_8005A6F0;
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
L_8005A528:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addu        $s2, $s5, $v0
    ctx->r18 = ADD32(ctx->r21, ctx->r2);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lh          $a1, 0x4C($s5)
    ctx->r5 = MEM_H(0X4C, ctx->r21);
    // lbu         $a2, 0x2C($s2)
    ctx->r6 = MEM_BU(0X2C, ctx->r18);
    // lh          $a3, 0x4E($v0)
    ctx->r7 = MEM_H(0X4E, ctx->r2);
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) << 16;
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // sll         $a0, $s1, 8
    ctx->r4 = S32(ctx->r17) << 8;
    // sll         $s0, $s4, 16
    ctx->r16 = S32(ctx->r20) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // jal         0x80058120
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80058120(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_3:
    // sb          $s3, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r19;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8005BB50
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8005BB50(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // j           L_8005A6F0
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
    goto L_8005A6F0;
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
L_8005A57C:
    // addu        $s2, $s5, $s0
    ctx->r18 = ADD32(ctx->r21, ctx->r16);
    // lh          $a0, 0x4C($s5)
    ctx->r4 = MEM_H(0X4C, ctx->r21);
    // lbu         $a1, 0x2C($s2)
    ctx->r5 = MEM_BU(0X2C, ctx->r18);
    // jal         0x80057FA0
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80057FA0(rdram, ctx);
    goto after_5;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_5:
    // sll         $s3, $s1, 16
    ctx->r19 = S32(ctx->r17) << 16;
    // sra         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19) >> 16;
    // sll         $a0, $s3, 8
    ctx->r4 = S32(ctx->r19) << 8;
    // sll         $s1, $s4, 16
    ctx->r17 = S32(ctx->r20) << 16;
    // sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16) << 1;
    // addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // lh          $a1, 0x4C($s5)
    ctx->r5 = MEM_H(0X4C, ctx->r21);
    // lbu         $a2, 0x2C($s2)
    ctx->r6 = MEM_BU(0X2C, ctx->r18);
    // lh          $a3, 0x4E($s0)
    ctx->r7 = MEM_H(0X4E, ctx->r16);
    // lbu         $v0, 0x17($s2)
    ctx->r2 = MEM_BU(0X17, ctx->r18);
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    // jal         0x80058120
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80058120(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8005BB50
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_8005BB50(rdram, ctx);
    goto after_7;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_7:
    // j           L_8005A6F0
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
    goto L_8005A6F0;
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
L_8005A5DC:
    // sltiu       $v0, $s3, 0x40
    ctx->r2 = ctx->r19 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8005A5F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005A5F8;
    }
    // nop

    // jal         0x8005C31C
    // nop

    _SsVmDamperOff(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_8005A6DC
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    goto L_8005A6DC;
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
L_8005A5F8:
    // jal         0x8005C0F8
    // nop

    sub_8005C0F8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_8005A6DC
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    goto L_8005A6DC;
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
L_8005A608:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8005A964
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_8005A964(rdram, ctx);
    goto after_10;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_10:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A628:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x800525C0
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_800525C0(rdram, ctx);
    goto after_11;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_11:
    // j           L_8005A6DC
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    goto L_8005A6DC;
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
L_8005A63C:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8005AB78
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_8005AB78(rdram, ctx);
    goto after_12;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_12:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A65C:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8005ACA4
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_8005ACA4(rdram, ctx);
    goto after_13;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_13:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A67C:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8005ADF0
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_8005ADF0(rdram, ctx);
    goto after_14;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_14:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A69C:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8005AE68
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_8005AE68(rdram, ctx);
    goto after_15;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_15:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A6BC:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // jal         0x8005AAB0
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005AAB0(rdram, ctx);
    goto after_16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_16:
    // j           L_8005A6F0
    // nop

    goto L_8005A6F0;
    // nop

L_8005A6D8:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
L_8005A6DC:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_17;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_17:
    // sw          $v0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->r2;
L_8005A6F0:
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
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
