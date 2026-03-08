#include "recomp.h"
#include "disable_warnings.h"

void SpawnMagicProjectile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // sltiu       $v0, $a0, 0x35
    ctx->r2 = ctx->r4 < 0X35 ? 1 : 0;
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_80028D30
    if (ctx->r2 == 0) {
        // sw          $a0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r4;
        goto L_80028D30;
    }
    // sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1284
    ctx->r1 = ADD32(ctx->r1, 0X1284);
    // addu        $at, $at, $v0
    gpr jr_addend_800284EC;
    jr_addend_800284EC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800284EC >> 2) {
        case 0: goto L_8002868C; break;
        case 1: goto L_80028A20; break;
        case 2: goto L_80028524; break;
        case 3: goto L_8002855C; break;
        case 4: goto L_800287F4; break;
        case 5: goto L_800288B8; break;
        case 6: goto L_80028978; break;
        case 7: goto L_800284F4; break;
        case 8: goto L_80028934; break;
        case 9: goto L_8002892C; break;
        case 10: goto L_80028970; break;
        case 11: goto L_80028830; break;
        case 12: goto L_80028980; break;
        case 13: goto L_8002871C; break;
        case 14: goto L_80028CDC; break;
        case 15: goto L_80028C64; break;
        case 16: goto L_80028CF4; break;
        case 17: goto L_80028CA0; break;
        case 18: goto L_80028D30; break;
        case 19: goto L_80028D0C; break;
        case 20: goto L_80028D30; break;
        case 21: goto L_80028D30; break;
        case 22: goto L_80028D30; break;
        case 23: goto L_80028D30; break;
        case 24: goto L_80028D30; break;
        case 25: goto L_80028D30; break;
        case 26: goto L_80028D30; break;
        case 27: goto L_80028D30; break;
        case 28: goto L_80028D30; break;
        case 29: goto L_80028D30; break;
        case 30: goto L_80028D30; break;
        case 31: goto L_80028D30; break;
        case 32: goto L_80028D30; break;
        case 33: goto L_80028D30; break;
        case 34: goto L_80028C28; break;
        case 35: goto L_80028C28; break;
        case 36: goto L_80028D30; break;
        case 37: goto L_80028D30; break;
        case 38: goto L_80028C28; break;
        case 39: goto L_80028BA0; break;
        case 40: goto L_80028B98; break;
        case 41: goto L_80028D30; break;
        case 42: goto L_80028A30; break;
        case 43: goto L_80028A28; break;
        case 44: goto L_80028B58; break;
        case 45: goto L_80028B78; break;
        case 46: goto L_80028D30; break;
        case 47: goto L_80028D30; break;
        case 48: goto L_80028D30; break;
        case 49: goto L_80028BE4; break;
        case 50: goto L_80028BF8; break;
        case 51: goto L_800287E4; break;
        case 52: goto L_800287EC; break;
        default: switch_error(__func__, 0x800284EC, 0x80011284);
    }
    // nop

L_800284F4:
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
L_800284F8:
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_0;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_0:
L_80028508:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_8002850C:
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // j           L_80028D28
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    goto L_80028D28;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_80028524:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x13
    ctx->r5 = 0 | 0X13;
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x4A64
    ctx->r7 = ADD32(ctx->r7, -0X4A64);
    // ori         $v1, $zero, 0x1000
    ctx->r3 = 0 | 0X1000;
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x80042D2C
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    SpawnParticleEntity(rdram, ctx);
    goto after_1;
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // j           L_80028D30
    // nop

    goto L_80028D30;
    // nop

L_8002855C:
    // ori         $a0, $zero, 0x1388
    ctx->r4 = 0 | 0X1388;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_2;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_2:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $zero, L_800285A8
    if (ctx->r16 != 0) {
        // lui         $a1, 0x1B4E
        ctx->r5 = S32(0X1B4E << 16);
        goto L_800285A8;
    }
    // lui         $a1, 0x1B4E
    ctx->r5 = S32(0X1B4E << 16);
    // lh          $v0, 0x40($sp)
    ctx->r2 = MEM_H(0X40, ctx->r29);
    // lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(0X30, ctx->r29);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lh          $v0, 0x44($sp)
    ctx->r2 = MEM_H(0X44, ctx->r29);
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // j           L_8002866C
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8002866C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_800285A8:
    // lh          $v1, 0x50($s0)
    ctx->r3 = MEM_H(0X50, ctx->r16);
    // ori         $a1, $a1, 0x81B5
    ctx->r5 = ctx->r5 | 0X81B5;
    // sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) << 14;
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lh          $v1, 0x52($s0)
    ctx->r3 = MEM_H(0X52, ctx->r16);
    // nop

    // sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) << 14;
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(0X30, ctx->r16);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lh          $v1, 0x54($s0)
    ctx->r3 = MEM_H(0X54, ctx->r16);
    // nop

    // sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) << 14;
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(0X34, ctx->r16);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(0X34, ctx->r29);
    // lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(0X38, ctx->r29);
    // jal         0x8002E318
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    CollisionWithTilemap(rdram, ctx);
    goto after_3;
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    after_3:
    // beq         $v0, $zero, L_80028674
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80028674;
    }
    // nop

    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // nop

    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
L_8002866C:
    // nop

    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80028674:
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // ori         $a2, $zero, 0x72
    ctx->r6 = 0 | 0X72;
    // j           L_80028D28
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    goto L_80028D28;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
L_8002868C:
    // ori         $a0, $zero, 0x1388
    ctx->r4 = 0 | 0X1388;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_4;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_4:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800286E0
    if (ctx->r16 == 0) {
        // ori         $t2, $zero, 0xFF
        ctx->r10 = 0 | 0XFF;
        goto L_800286E0;
    }
    // ori         $t2, $zero, 0xFF
    ctx->r10 = 0 | 0XFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, -0x19F8
    ctx->r2 = ADD32(ctx->r2, -0X19F8);
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $a0, $v1, 15
    ctx->r4 = S32(ctx->r3) << 15;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sra         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3) >> 2;
L_800286E0:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // ori         $a2, $zero, 0x6F
    ctx->r6 = 0 | 0X6F;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lh          $v0, 0x40($sp)
    ctx->r2 = MEM_H(0X40, ctx->r29);
    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // lh          $v1, 0x44($sp)
    ctx->r3 = MEM_H(0X44, ctx->r29);
    // lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80028D28
    // sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    goto L_80028D28;
    // sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
L_8002871C:
    // lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // addiu       $s1, $s1, -0x1E00
    ctx->r17 = ADD32(ctx->r17, -0X1E00);
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    // addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
L_8002872C:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A24
    ctx->r5 = ADD32(ctx->r5, -0X4A24);
    // lwl         $v0, 0x3($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r17);
    // lwr         $v0, 0x0($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r17);
    // lwl         $v1, 0x7($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r17);
    // lwr         $v1, 0x4($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r17);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
    // ori         $a0, $zero, 0x320
    ctx->r4 = 0 | 0X320;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_5;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_5:
    // jal         0x80062BF0
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    rand_recomp(rdram, ctx);
    goto after_6;
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    after_6:
    // lhu         $v1, 0x40($sp)
    ctx->r3 = MEM_HU(0X40, ctx->r29);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_7;
    // sh          $v1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r3;
    after_7:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // lhu         $v1, 0x42($sp)
    ctx->r3 = MEM_HU(0X42, ctx->r29);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_8;
    // sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    after_8:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // lhu         $v1, 0x44($sp)
    ctx->r3 = MEM_HU(0X44, ctx->r29);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r3;
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // jal         0x80042D2C
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    SpawnParticleEntity(rdram, ctx);
    goto after_9;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_9:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80028D30
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_80028D30;
    }
    // nop

    // j           L_8002872C
    // nop

    goto L_8002872C;
    // nop

L_800287E4:
    // j           L_800287F0
    // ori         $v0, $zero, 0x76
    ctx->r2 = 0 | 0X76;
    goto L_800287F0;
    // ori         $v0, $zero, 0x76
    ctx->r2 = 0 | 0X76;
L_800287EC:
    // ori         $v0, $zero, 0x77
    ctx->r2 = 0 | 0X77;
L_800287F0:
    // sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
L_800287F4:
    // ori         $a0, $zero, 0x2BC
    ctx->r4 = 0 | 0X2BC;
L_800287F8:
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_10;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_10:
L_80028808:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_8002880C:
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x4A4C
    ctx->r2 = ADD32(ctx->r2, -0X4A4C);
    // j           L_80028D28
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    goto L_80028D28;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_80028830:
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    CalculateTrajectory(rdram, ctx);
    goto after_11;
    // addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_11:
    // lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(0X54, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80028888
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x1B4E
        ctx->r2 = S32(0X1B4E << 16);
        goto L_80028888;
    }
    // lui         $v0, 0x1B4E
    ctx->r2 = S32(0X1B4E << 16);
    // ori         $v0, $v0, 0x81B5
    ctx->r2 = ctx->r2 | 0X81B5;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80028890
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80028890;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_80028890
    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    goto L_80028890;
    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80028888:
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80028890:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // ori         $a2, $zero, 0x67
    ctx->r6 = 0 | 0X67;
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(0X54, ctx->r29);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // j           L_80028D28
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    goto L_80028D28;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_800288B8:
    // ori         $a0, $zero, 0xC8
    ctx->r4 = 0 | 0XC8;
L_800288BC:
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_12;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_12:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8002890C
    if (ctx->r16 == 0) {
        // ori         $t2, $zero, 0xFF
        ctx->r10 = 0 | 0XFF;
        goto L_8002890C;
    }
    // ori         $t2, $zero, 0xFF
    ctx->r10 = 0 | 0XFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, -0x19F8
    ctx->r2 = ADD32(ctx->r2, -0X19F8);
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $a0, $v1, 15
    ctx->r4 = S32(ctx->r3) << 15;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sra         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3) >> 2;
L_8002890C:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // j           L_80028D28
    // sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    goto L_80028D28;
    // sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
L_8002892C:
    // j           L_800288BC
    // ori         $a0, $zero, 0x1F4
    ctx->r4 = 0 | 0X1F4;
    goto L_800288BC;
    // ori         $a0, $zero, 0x1F4
    ctx->r4 = 0 | 0X1F4;
L_80028934:
    // ori         $a0, $zero, 0x2BC
    ctx->r4 = 0 | 0X2BC;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_13;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_13:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // ori         $a2, $zero, 0x6A
    ctx->r6 = 0 | 0X6A;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x4A4C
    ctx->r2 = ADD32(ctx->r2, -0X4A4C);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // j           L_80028D28
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    goto L_80028D28;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_80028970:
    // j           L_800287F8
    // ori         $a0, $zero, 0x12C
    ctx->r4 = 0 | 0X12C;
    goto L_800287F8;
    // ori         $a0, $zero, 0x12C
    ctx->r4 = 0 | 0X12C;
L_80028978:
    // j           L_800287F8
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
    goto L_800287F8;
    // ori         $a0, $zero, 0xFA
    ctx->r4 = 0 | 0XFA;
L_80028980:
    // ori         $a0, $zero, 0x96
    ctx->r4 = 0 | 0X96;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A4A
    ctx->r16 = ADD32(ctx->r16, -0X4A4A);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A24($v0)
    ctx->r2 = MEM_HU(-0X4A24, ctx->r2);
    // lhu         $s1, 0x0($s0)
    ctx->r17 = MEM_HU(0X0, ctx->r16);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $s1, $v0
    ctx->r2 = SUB32(ctx->r17, ctx->r2);
    // jal         0x800282F0
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    CalculateTrajectory(rdram, ctx);
    goto after_14;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_14:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A24($v0)
    ctx->r2 = MEM_HU(-0X4A24, ctx->r2);
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = ctx->r2;
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // sh          $s1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r17;
    // addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // ori         $v0, $zero, 0x258
    ctx->r2 = 0 | 0X258;
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
    // ori         $v0, $zero, 0x8C
    ctx->r2 = 0 | 0X8C;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA0
    ctx->r2 = 0 | 0XA0;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // jal         0x80042D2C
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_15;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_15:
    // j           L_80028D30
    // nop

    goto L_80028D30;
    // nop

L_80028A20:
    // j           L_800284F8
    // ori         $a0, $zero, 0x1F4
    ctx->r4 = 0 | 0X1F4;
    goto L_800284F8;
    // ori         $a0, $zero, 0x1F4
    ctx->r4 = 0 | 0X1F4;
L_80028A28:
    // j           L_80028A34
    // ori         $v0, $zero, 0x73
    ctx->r2 = 0 | 0X73;
    goto L_80028A34;
    // ori         $v0, $zero, 0x73
    ctx->r2 = 0 | 0X73;
L_80028A30:
    // ori         $v0, $zero, 0x71
    ctx->r2 = 0 | 0X71;
L_80028A34:
    // sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // addiu       $s1, $s1, -0x1E28
    ctx->r17 = ADD32(ctx->r17, -0X1E28);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A24
    ctx->r16 = ADD32(ctx->r16, -0X4A24);
    // lwl         $v0, 0x3($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r17);
    // lwr         $v0, 0x0($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r17);
    // lwl         $v1, 0x7($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r17);
    // lwr         $v1, 0x4($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r17);
    // swl         $v0, 0x3($s0)
    do_swl(rdram, 0X3, ctx->r16, ctx->r2);
    // swr         $v0, 0x0($s0)
    do_swr(rdram, 0X0, ctx->r16, ctx->r2);
    // swl         $v1, 0x7($s0)
    do_swl(rdram, 0X7, ctx->r16, ctx->r3);
    // swr         $v1, 0x4($s0)
    do_swr(rdram, 0X4, ctx->r16, ctx->r3);
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_16;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_16:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // addiu       $s0, $s0, -0x28
    ctx->r16 = ADD32(ctx->r16, -0X28);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // jal         0x80042D2C
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    SpawnParticleEntity(rdram, ctx);
    goto after_17;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_17:
    // beq         $v0, $zero, L_80028D30
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_80028D30;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1280
    ctx->r4 = ADD32(ctx->r4, -0X1280);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3) << 6;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 15
    ctx->r2 = S32(ctx->r3) << 15;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2) >> 3;
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80028AE8:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A24
    ctx->r5 = ADD32(ctx->r5, -0X4A24);
    // lwl         $v0, 0x3($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r17);
    // lwr         $v0, 0x0($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r17);
    // lwl         $v1, 0x7($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r17);
    // lwr         $v1, 0x4($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r17);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
    // ori         $a0, $zero, 0x258
    ctx->r4 = 0 | 0X258;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_18;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_18:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $a2, 0x6($s1)
    ctx->r6 = MEM_BU(0X6, ctx->r17);
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // jal         0x80042D2C
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    SpawnParticleEntity(rdram, ctx);
    goto after_19;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_19:
    // beq         $s0, $s4, L_80028D30
    if (ctx->r16 == ctx->r20) {
        // nop
    
        goto L_80028D30;
    }
    // nop

    // j           L_80028AE8
    // nop

    goto L_80028AE8;
    // nop

L_80028B58:
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_20;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_20:
    // ori         $v0, $zero, 0x75
    ctx->r2 = 0 | 0X75;
    // j           L_80028808
    // sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    goto L_80028808;
    // sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
L_80028B78:
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_21;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_21:
    // ori         $v0, $zero, 0x74
    ctx->r2 = 0 | 0X74;
    // j           L_80028508
    // sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    goto L_80028508;
    // sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
L_80028B98:
    // j           L_800287F8
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
    goto L_800287F8;
    // ori         $a0, $zero, 0x3E8
    ctx->r4 = 0 | 0X3E8;
L_80028BA0:
    // ori         $a0, $zero, 0x32
    ctx->r4 = 0 | 0X32;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_22;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_22:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(0X8, ctx->r2);
    // lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(0XC, ctx->r2);
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // j           L_8002880C
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    goto L_8002880C;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_80028BE4:
    // ori         $a0, $zero, 0x226
    ctx->r4 = 0 | 0X226;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_23;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_23:
L_80028BF8:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(0X8, ctx->r2);
    // lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(0XC, ctx->r2);
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // j           L_8002850C
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    goto L_8002850C;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_80028C28:
    // ori         $a0, $zero, 0x384
    ctx->r4 = 0 | 0X384;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x800282F0
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    CalculateTrajectory(rdram, ctx);
    goto after_24;
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_24:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $a2, 0x70($sp)
    ctx->r6 = MEM_BU(0X70, ctx->r29);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x4A4C
    ctx->r2 = ADD32(ctx->r2, -0X4A4C);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // j           L_80028D28
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    goto L_80028D28;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_80028C64:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // ori         $a2, $zero, 0xF
    ctx->r6 = 0 | 0XF;
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x4A64
    ctx->r7 = ADD32(ctx->r7, -0X4A64);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // jal         0x80042D2C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_25;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_25:
    // ori         $v0, $zero, 0x384
    ctx->r2 = 0 | 0X384;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADA($at)
    MEM_H(-0X4ADA, ctx->r1) = ctx->r2;
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // j           L_80028D30
    // nop

    goto L_80028D30;
    // nop

L_80028CA0:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // ori         $a2, $zero, 0x11
    ctx->r6 = 0 | 0X11;
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x4A64
    ctx->r7 = ADD32(ctx->r7, -0X4A64);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // jal         0x80042D2C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_27;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_27:
    // ori         $v0, $zero, 0x384
    ctx->r2 = 0 | 0X384;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD8($at)
    MEM_H(-0X4AD8, ctx->r1) = ctx->r2;
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_28;
    // nop

    after_28:
    // j           L_80028D30
    // nop

    goto L_80028D30;
    // nop

L_80028CDC:
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // j           L_80028D20
    // ori         $a2, $zero, 0xE
    ctx->r6 = 0 | 0XE;
    goto L_80028D20;
    // ori         $a2, $zero, 0xE
    ctx->r6 = 0 | 0XE;
L_80028CF4:
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // j           L_80028D20
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
    goto L_80028D20;
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
L_80028D0C:
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // ori         $a2, $zero, 0x13
    ctx->r6 = 0 | 0X13;
L_80028D20:
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x4A64
    ctx->r7 = ADD32(ctx->r7, -0X4A64);
L_80028D28:
    // jal         0x80042D2C
    // nop

    SpawnParticleEntity(rdram, ctx);
    goto after_29;
    // nop

    after_29:
L_80028D30:
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
