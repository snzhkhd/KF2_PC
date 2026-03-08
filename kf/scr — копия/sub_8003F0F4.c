#include "recomp.h"
#include "disable_warnings.h"

void sub_8003F0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // sw          $s5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // addiu       $s3, $sp, 0xC8
    ctx->r19 = ADD32(ctx->r29, 0XC8);
    // sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s2, $s2, -0x4A64
    ctx->r18 = ADD32(ctx->r18, -0X4A64);
    // sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // sw          $a1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r5;
    // lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // lw          $s1, 0x79B4($s1)
    ctx->r17 = MEM_W(0X79B4, ctx->r17);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $ra, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r31;
    // bne         $a1, $v0, L_8003F17C
    if (ctx->r5 != ctx->r2) {
        // sw          $s0, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r16;
        goto L_8003F17C;
    }
    // sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // addiu       $s3, $sp, 0xD4
    ctx->r19 = ADD32(ctx->r29, 0XD4);
    // lhu         $v0, 0xCC($sp)
    ctx->r2 = MEM_HU(0XCC, ctx->r29);
    // addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xD0($sp)
    ctx->r2 = MEM_HU(0XD0, ctx->r29);
    // addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xD4($sp)
    ctx->r2 = MEM_HU(0XD4, ctx->r29);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x80015614
    // sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    sub_80015614(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    after_0:
    // j           L_8003F23C
    // nop

    goto L_8003F23C;
    // nop

L_8003F17C:
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // bne         $a1, $v0, L_8003F234
    if (ctx->r5 != ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003F234;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(0XCC, ctx->r29);
    // jal         0x8003EAC0
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    sub_8003EAC0(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_1:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lw          $a1, 0xD0($sp)
    ctx->r5 = MEM_W(0XD0, ctx->r29);
    // jal         0x8003EAC0
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    sub_8003EAC0(rdram, ctx);
    goto after_2;
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // addiu       $s3, $sp, 0xD4
    ctx->r19 = ADD32(ctx->r29, 0XD4);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(0X40, ctx->r29);
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // lw          $s0, 0xD4($sp)
    ctx->r16 = MEM_W(0XD4, ctx->r29);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(0X2C, ctx->r17);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x80015D18
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    FixedPointLerp(rdram, ctx);
    goto after_3;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_3:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(0X44, ctx->r29);
    // lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(0X54, ctx->r29);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(0X30, ctx->r17);
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // jal         0x80015D18
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    FixedPointLerp(rdram, ctx);
    goto after_4;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_4:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A5C($a0)
    ctx->r4 = MEM_W(-0X4A5C, ctx->r4);
    // lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(0X48, ctx->r29);
    // lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(0X58, ctx->r29);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(0X34, ctx->r17);
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // jal         0x80015D18
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    FixedPointLerp(rdram, ctx);
    goto after_5;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_5:
    // j           L_8003F23C
    // sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    goto L_8003F23C;
    // sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
L_8003F234:
    // jal         0x8003EAC0
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    sub_8003EAC0(rdram, ctx);
    goto after_6;
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_6:
L_8003F23C:
    // lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(0X2C, ctx->r17);
    // lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(0X40, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(0X30, ctx->r17);
    // lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(0X44, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(0X34, ctx->r17);
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $s5, -0x1
    ctx->r3 = ADD32(ctx->r21, -0X1);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // sltiu       $v0, $v1, 0x7B
    ctx->r2 = ctx->r3 < 0X7B ? 1 : 0;
    // beq         $v0, $zero, L_8003FAC0
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003FAC0;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1FE4
    ctx->r1 = ADD32(ctx->r1, 0X1FE4);
    // addu        $at, $at, $v0
    gpr jr_addend_8003F29C;
    jr_addend_8003F29C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003F29C >> 2) {
        case 0: goto L_8003F5C0; break;
        case 1: goto L_8003F4F0; break;
        case 2: goto L_8003FAC0; break;
        case 3: goto L_8003F3D0; break;
        case 4: goto L_8003FAC0; break;
        case 5: goto L_8003FAC0; break;
        case 6: goto L_8003F2B4; break;
        case 7: goto L_8003FAC0; break;
        case 8: goto L_8003F484; break;
        case 9: goto L_8003FAC0; break;
        case 10: goto L_8003FAC0; break;
        case 11: goto L_8003F624; break;
        case 12: goto L_8003FAC0; break;
        case 13: goto L_8003FAC0; break;
        case 14: goto L_8003FAC0; break;
        case 15: goto L_8003FAC0; break;
        case 16: goto L_8003FAC0; break;
        case 17: goto L_8003FAC0; break;
        case 18: goto L_8003FAC0; break;
        case 19: goto L_8003FAC0; break;
        case 20: goto L_8003FAC0; break;
        case 21: goto L_8003F528; break;
        case 22: goto L_8003F538; break;
        case 23: goto L_8003F4E0; break;
        case 24: goto L_8003FAC0; break;
        case 25: goto L_8003F5D0; break;
        case 26: goto L_8003F5D0; break;
        case 27: goto L_8003F5C0; break;
        case 28: goto L_8003F990; break;
        case 29: goto L_8003FAC0; break;
        case 30: goto L_8003F990; break;
        case 31: goto L_8003F2B4; break;
        case 32: goto L_8003F484; break;
        case 33: goto L_8003FAC0; break;
        case 34: goto L_8003FAC0; break;
        case 35: goto L_8003FAC0; break;
        case 36: goto L_8003FAC0; break;
        case 37: goto L_8003FAC0; break;
        case 38: goto L_8003FAC0; break;
        case 39: goto L_8003F3E0; break;
        case 40: goto L_8003FAC0; break;
        case 41: goto L_8003FAC0; break;
        case 42: goto L_8003FAC0; break;
        case 43: goto L_8003FAC0; break;
        case 44: goto L_8003FAC0; break;
        case 45: goto L_8003FAC0; break;
        case 46: goto L_8003FAC0; break;
        case 47: goto L_8003FAC0; break;
        case 48: goto L_8003FAC0; break;
        case 49: goto L_8003FAC0; break;
        case 50: goto L_8003FAC0; break;
        case 51: goto L_8003FAC0; break;
        case 52: goto L_8003FAC0; break;
        case 53: goto L_8003FAC0; break;
        case 54: goto L_8003FAC0; break;
        case 55: goto L_8003FAC0; break;
        case 56: goto L_8003FAC0; break;
        case 57: goto L_8003FAC0; break;
        case 58: goto L_8003FAC0; break;
        case 59: goto L_8003FAC0; break;
        case 60: goto L_8003FAC0; break;
        case 61: goto L_8003FAC0; break;
        case 62: goto L_8003FAC0; break;
        case 63: goto L_8003FAC0; break;
        case 64: goto L_8003FAC0; break;
        case 65: goto L_8003FAC0; break;
        case 66: goto L_8003FAC0; break;
        case 67: goto L_8003FAC0; break;
        case 68: goto L_8003FAC0; break;
        case 69: goto L_8003FAC0; break;
        case 70: goto L_8003FAC0; break;
        case 71: goto L_8003FAC0; break;
        case 72: goto L_8003FAC0; break;
        case 73: goto L_8003FAC0; break;
        case 74: goto L_8003FAC0; break;
        case 75: goto L_8003FAC0; break;
        case 76: goto L_8003FAC0; break;
        case 77: goto L_8003FAC0; break;
        case 78: goto L_8003FAC0; break;
        case 79: goto L_8003FAC0; break;
        case 80: goto L_8003FAC0; break;
        case 81: goto L_8003FAC0; break;
        case 82: goto L_8003FAC0; break;
        case 83: goto L_8003FAC0; break;
        case 84: goto L_8003FAC0; break;
        case 85: goto L_8003FAC0; break;
        case 86: goto L_8003FAC0; break;
        case 87: goto L_8003FAC0; break;
        case 88: goto L_8003FAC0; break;
        case 89: goto L_8003FAC0; break;
        case 90: goto L_8003FAC0; break;
        case 91: goto L_8003FAC0; break;
        case 92: goto L_8003FAC0; break;
        case 93: goto L_8003FAC0; break;
        case 94: goto L_8003FAC0; break;
        case 95: goto L_8003FAC0; break;
        case 96: goto L_8003FAC0; break;
        case 97: goto L_8003FAC0; break;
        case 98: goto L_8003FAC0; break;
        case 99: goto L_8003FAC0; break;
        case 100: goto L_8003FAC0; break;
        case 101: goto L_8003FAC0; break;
        case 102: goto L_8003FAC0; break;
        case 103: goto L_8003FAC0; break;
        case 104: goto L_8003FAC0; break;
        case 105: goto L_8003FAC0; break;
        case 106: goto L_8003FAC0; break;
        case 107: goto L_8003F578; break;
        case 108: goto L_8003FAC0; break;
        case 109: goto L_8003F744; break;
        case 110: goto L_8003FAC0; break;
        case 111: goto L_8003F868; break;
        case 112: goto L_8003FAC0; break;
        case 113: goto L_8003FAC0; break;
        case 114: goto L_8003FAC0; break;
        case 115: goto L_8003FAC0; break;
        case 116: goto L_8003FAC0; break;
        case 117: goto L_8003FAC0; break;
        case 118: goto L_8003FAC0; break;
        case 119: goto L_8003F6BC; break;
        case 120: goto L_8003F328; break;
        case 121: goto L_8003FAC0; break;
        case 122: goto L_8003F2A4; break;
        default: switch_error(__func__, 0x8003F29C, 0x80011FE4);
    }
    // nop

L_8003F2A4:
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8003F2C8
    if (ctx->r2 != 0) {
        // ori         $s5, $zero, 0x20
        ctx->r21 = 0 | 0X20;
        goto L_8003F2C8;
    }
    // ori         $s5, $zero, 0x20
    ctx->r21 = 0 | 0X20;
L_8003F2B4:
    // ori         $a0, $zero, 0x23
    ctx->r4 = 0 | 0X23;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // ori         $a2, $zero, 0x6E
    ctx->r6 = 0 | 0X6E;
    // jal         0x800143E0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800143E0(rdram, ctx);
    goto after_7;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
L_8003F2C8:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a2, $zero, 0x1F4
    ctx->r6 = 0 | 0X1F4;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_8;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_8:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // jal         0x80042D2C
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    SpawnParticleEntity(rdram, ctx);
    goto after_9;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_9:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_8003FAC0
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003FAC0;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_8003FAC0
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
    goto L_8003FAC0;
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
L_8003F328:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a2, $zero, 0x258
    ctx->r6 = 0 | 0X258;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_10:
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(0X34, ctx->r29);
    // lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(0X4, ctx->r18);
    // lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(0X8, ctx->r18);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x80015990
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_80015990(rdram, ctx);
    goto after_11;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_11:
    // lui         $v1, 0x1B4E
    ctx->r3 = S32(0X1B4E << 16);
    // ori         $v1, $v1, 0x81B5
    ctx->r3 = ctx->r3 | 0X81B5;
    // addiu       $v0, $v0, -0x7D0
    ctx->r2 = ADD32(ctx->r2, -0X7D0);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) >> 6;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_8003F3B0
    if (SIGNED(ctx->r3) >= 0) {
        // andi        $a0, $s4, 0xFF
        ctx->r4 = ctx->r20 & 0XFF;
        goto L_8003F3B0;
    }
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8003F3B0:
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    SpawnParticleEntity(rdram, ctx);
    goto after_12;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_12:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F3D0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // j           L_8003F5DC
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    goto L_8003F5DC;
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
L_8003F3E0:
    // addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(0X34, ctx->r29);
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(0X38, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // addiu       $a1, $a1, 0x640
    ctx->r5 = ADD32(ctx->r5, 0X640);
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // subu        $a2, $v1, $a2
    ctx->r6 = SUB32(ctx->r3, ctx->r6);
    // jal         0x800159DC
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_VectorToAngles(rdram, ctx);
    goto after_13;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_13:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // jal         0x80015538
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_14;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_14:
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
    // jal         0x80015694
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015694(rdram, ctx);
    goto after_15;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_15:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lh          $v0, 0x70($sp)
    ctx->r2 = MEM_H(0X70, ctx->r29);
    // lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(0X30, ctx->r29);
    // lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(0X34, ctx->r29);
    // lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lh          $v0, 0x72($sp)
    ctx->r2 = MEM_H(0X72, ctx->r29);
    // lh          $v1, 0x74($sp)
    ctx->r3 = MEM_H(0X74, ctx->r29);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    SpawnParticleEntity(rdram, ctx);
    goto after_16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_16:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F484:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a2, $zero, 0x190
    ctx->r6 = 0 | 0X190;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_17;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_17:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_18;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_18:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F4E0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // j           L_8003F5DC
    // ori         $a2, $zero, 0xFA
    ctx->r6 = 0 | 0XFA;
    goto L_8003F5DC;
    // ori         $a2, $zero, 0xFA
    ctx->r6 = 0 | 0XFA;
L_8003F4F0:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // ori         $v1, $zero, 0x1000
    ctx->r3 = 0 | 0X1000;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    SpawnParticleEntity(rdram, ctx);
    goto after_19;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_19:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F528:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // j           L_8003F5DC
    // ori         $a2, $zero, 0x190
    ctx->r6 = 0 | 0X190;
    goto L_8003F5DC;
    // ori         $a2, $zero, 0x190
    ctx->r6 = 0 | 0X190;
L_8003F538:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79C0($v0)
    ctx->r2 = MEM_W(0X79C0, ctx->r2);
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(0XC8, ctx->r29);
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // jal         0x80042D2C
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_20;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_20:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F578:
    // addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // jal         0x80015538
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_21;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_21:
    // ori         $a0, $zero, 0x226
    ctx->r4 = 0 | 0X226;
    // jal         0x80015694
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015694(rdram, ctx);
    goto after_22;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_22:
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // ori         $a2, $zero, 0x7
    ctx->r6 = 0 | 0X7;
    // jal         0x80042D2C
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    SpawnParticleEntity(rdram, ctx);
    goto after_23;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_23:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_8003FAC0
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8003FAC0;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // j           L_8003FAC0
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
    goto L_8003FAC0;
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
L_8003F5C0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // j           L_8003F5DC
    // ori         $a2, $zero, 0x1F4
    ctx->r6 = 0 | 0X1F4;
    goto L_8003F5DC;
    // ori         $a2, $zero, 0x1F4
    ctx->r6 = 0 | 0X1F4;
L_8003F5D0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a2, $zero, 0x12C
    ctx->r6 = 0 | 0X12C;
L_8003F5DC:
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_24;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_24:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // jal         0x80042D2C
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    SpawnParticleEntity(rdram, ctx);
    goto after_25;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_25:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F624:
    // addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(0X60, ctx->r29);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(0X64, ctx->r29);
    // lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(0X34, ctx->r29);
    // lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(0X38, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(0X68, ctx->r29);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x800159DC
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    Math_VectorToAngles(rdram, ctx);
    goto after_26;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_26:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // jal         0x80015538
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_27;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_27:
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    // jal         0x80015694
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015694(rdram, ctx);
    goto after_28;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_28:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // ori         $v0, $zero, 0x1F4
    ctx->r2 = 0 | 0X1F4;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x8C
    ctx->r2 = 0 | 0X8C;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80042D2C
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_29;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_29:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F6BC:
    // jal         0x80062BF0
    // andi        $s1, $s4, 0xFF
    ctx->r17 = ctx->r20 & 0XFF;
    rand_recomp(rdram, ctx);
    goto after_30;
    // andi        $s1, $s4, 0xFF
    ctx->r17 = ctx->r20 & 0XFF;
    after_30:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x1000
    ctx->r2 = ADD32(ctx->r2, -0X1000);
    // jal         0x80062BF0
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_31;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_31:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $s0, $s5, 0xFF
    ctx->r16 = ctx->r21 & 0XFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // addiu       $v0, $v0, -0x1000
    ctx->r2 = ADD32(ctx->r2, -0X1000);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, -0x1388
    ctx->r3 = ADD32(ctx->r3, -0X1388);
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // jal         0x80042D2C
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    SpawnParticleEntity(rdram, ctx);
    goto after_32;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_32:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // jal         0x80042D2C
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    SpawnParticleEntity(rdram, ctx);
    goto after_33;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_33:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F744:
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // nop

    // lhu         $s3, 0x4($v0)
    ctx->r19 = MEM_HU(0X4, ctx->r2);
    // jal         0x8003B748
    // nop

    sub_8003B748(rdram, ctx);
    goto after_34;
    // nop

    after_34:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003FAC0
    if (ctx->r16 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003FAC0;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a2, $zero, 0x190
    ctx->r6 = 0 | 0X190;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
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
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_35;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_35:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // sb          $s3, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r19;
    // sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(0X6, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // sll         $v0, $s3, 4
    ctx->r2 = S32(ctx->r19) << 4;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x46E8
    ctx->r3 = ADD32(ctx->r3, 0X46E8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(0X34, ctx->r2);
    // nop

    // sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x9($v0)
    ctx->r2 = MEM_BU(0X9, ctx->r2);
    // nop

    // sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // nop

    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(0X34, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003B8BC
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    Entity_EnterCombatState(rdram, ctx);
    goto after_36;
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    after_36:
    // lwl         $v0, 0x73($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X73, ctx->r29);
    // lwr         $v0, 0x70($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X70, ctx->r29);
    // lwl         $v1, 0x77($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X77, ctx->r29);
    // lwr         $v1, 0x74($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X74, ctx->r29);
    // swl         $v0, 0x53($s0)
    do_swl(rdram, 0X53, ctx->r16, ctx->r2);
    // swr         $v0, 0x50($s0)
    do_swr(rdram, 0X50, ctx->r16, ctx->r2);
    // swl         $v1, 0x57($s0)
    do_swl(rdram, 0X57, ctx->r16, ctx->r3);
    // swr         $v1, 0x54($s0)
    do_swr(rdram, 0X54, ctx->r16, ctx->r3);
    // lwl         $v0, 0x43($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X43, ctx->r17);
    // lwr         $v0, 0x40($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X40, ctx->r17);
    // lwl         $v1, 0x47($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X47, ctx->r17);
    // lwr         $v1, 0x44($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X44, ctx->r17);
    // swl         $v0, 0x43($s0)
    do_swl(rdram, 0X43, ctx->r16, ctx->r2);
    // swr         $v0, 0x40($s0)
    do_swr(rdram, 0X40, ctx->r16, ctx->r2);
    // swl         $v1, 0x47($s0)
    do_swl(rdram, 0X47, ctx->r16, ctx->r3);
    // swr         $v1, 0x44($s0)
    do_swr(rdram, 0X44, ctx->r16, ctx->r3);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x1D
    ctx->r5 = 0 | 0X1D;
    Entity_ChangeState(rdram, ctx);
    goto after_37;
    // ori         $a1, $zero, 0x1D
    ctx->r5 = 0 | 0X1D;
    after_37:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F868:
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // nop

    // lhu         $s3, 0x4($v0)
    ctx->r19 = MEM_HU(0X4, ctx->r2);
    // jal         0x8003B748
    // nop

    sub_8003B748(rdram, ctx);
    goto after_38;
    // nop

    after_38:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003FAC0
    if (ctx->r16 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003FAC0;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a2, $zero, 0xFA
    ctx->r6 = 0 | 0XFA;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
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
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x8003EEB0
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003EEB0(rdram, ctx);
    goto after_39;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_39:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // sb          $s3, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r19;
    // sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(0X6, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // sll         $v0, $s3, 4
    ctx->r2 = S32(ctx->r19) << 4;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x46E8
    ctx->r3 = ADD32(ctx->r3, 0X46E8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(0X34, ctx->r2);
    // nop

    // sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x9($v0)
    ctx->r3 = MEM_BU(0X9, ctx->r2);
    // nop

    // sb          $v1, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r3;
    // lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(0X30, ctx->r29);
    // nop

    // sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
    // lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(0X14, ctx->r2);
    // lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(0X34, ctx->r29);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003B8BC
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    Entity_EnterCombatState(rdram, ctx);
    goto after_40;
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    after_40:
    // lwl         $v0, 0x73($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X73, ctx->r29);
    // lwr         $v0, 0x70($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X70, ctx->r29);
    // lwl         $v1, 0x77($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X77, ctx->r29);
    // lwr         $v1, 0x74($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X74, ctx->r29);
    // swl         $v0, 0x53($s0)
    do_swl(rdram, 0X53, ctx->r16, ctx->r2);
    // swr         $v0, 0x50($s0)
    do_swr(rdram, 0X50, ctx->r16, ctx->r2);
    // swl         $v1, 0x57($s0)
    do_swl(rdram, 0X57, ctx->r16, ctx->r3);
    // swr         $v1, 0x54($s0)
    do_swr(rdram, 0X54, ctx->r16, ctx->r3);
    // lwl         $v0, 0x43($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X43, ctx->r17);
    // lwr         $v0, 0x40($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X40, ctx->r17);
    // lwl         $v1, 0x47($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X47, ctx->r17);
    // lwr         $v1, 0x44($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X44, ctx->r17);
    // swl         $v0, 0x43($s0)
    do_swl(rdram, 0X43, ctx->r16, ctx->r2);
    // swr         $v0, 0x40($s0)
    do_swr(rdram, 0X40, ctx->r16, ctx->r2);
    // swl         $v1, 0x47($s0)
    do_swl(rdram, 0X47, ctx->r16, ctx->r3);
    // swr         $v1, 0x44($s0)
    do_swr(rdram, 0X44, ctx->r16, ctx->r3);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003C1CC
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
    Entity_ChangeState(rdram, ctx);
    goto after_41;
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
    after_41:
    // j           L_8003FAC0
    // nop

    goto L_8003FAC0;
    // nop

L_8003F990:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(0X8, ctx->r18);
    // lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(0XC, ctx->r18);
    // sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // ori         $s0, $zero, 0x6
    ctx->r16 = 0 | 0X6;
L_8003F9B4:
    // lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(0X88, ctx->r29);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(0X90, ctx->r29);
    // lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(0X38, ctx->r29);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015954
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    CalculateDistance(rdram, ctx);
    goto after_42;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_42:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    // lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(0X34, ctx->r29);
    // lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(0X8C, ctx->r29);
    // ori         $v0, $zero, 0x320
    ctx->r2 = 0 | 0X320;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $a2, $a2, 0x578
    ctx->r6 = ADD32(ctx->r6, 0X578);
    // jal         0x80015DD0
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    sub_80015DD0(rdram, ctx);
    goto after_43;
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    after_43:
    // beq         $v0, $zero, L_8003FA18
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8003FA18;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_8003FA18:
    // beq         $s0, $zero, L_8003FA40
    if (ctx->r16 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8003FA40;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A54
    ctx->r5 = ADD32(ctx->r5, -0X4A54);
    // lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(0X98, ctx->r29);
    // addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    // jal         0x80016168
    // sra         $a2, $a2, 6
    ctx->r6 = S32(ctx->r6) >> 6;
    sub_80016168(rdram, ctx);
    goto after_44;
    // sra         $a2, $a2, 6
    ctx->r6 = S32(ctx->r6) >> 6;
    after_44:
    // j           L_8003F9B4
    // nop

    goto L_8003F9B4;
    // nop

L_8003FA40:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v1, 0x9C($sp)
    ctx->r3 = MEM_H(0X9C, ctx->r29);
    // ori         $v0, $zero, 0xC00
    ctx->r2 = 0 | 0XC00;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x8003EEB0
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    sub_8003EEB0(rdram, ctx);
    goto after_45;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_45:
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // lhu         $v1, 0x9C($sp)
    ctx->r3 = MEM_HU(0X9C, ctx->r29);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // sh          $v0, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // sh          $zero, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = 0;
    // sh          $v1, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_46;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_46:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_8003FAC0
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x32
        ctx->r2 = 0 | 0X32;
        goto L_8003FAC0;
    }
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // lhu         $v1, 0x34($sp)
    ctx->r3 = MEM_HU(0X34, ctx->r29);
    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    // sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // sh          $v1, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r3;
L_8003FAC0:
    // lw          $ra, 0xB8($sp)
    ctx->r31 = MEM_W(0XB8, ctx->r29);
    // lw          $s5, 0xB4($sp)
    ctx->r21 = MEM_W(0XB4, ctx->r29);
    // lw          $s4, 0xB0($sp)
    ctx->r20 = MEM_W(0XB0, ctx->r29);
    // lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(0XAC, ctx->r29);
    // lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(0XA8, ctx->r29);
    // lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(0XA4, ctx->r29);
    // lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(0XA0, ctx->r29);
    // addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // jr          $ra
    // nop

    return;
    // nop

;}
