#include "recomp.h"
#include "disable_warnings.h"

void SpawnProjectile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // bne         $a0, $zero, L_80038F34
    if (ctx->r4 != 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80038F34;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, 0x132
    ctx->r16 = ADD32(ctx->r16, 0X132);
    // j           L_80038F40
    // ori         $a0, $zero, 0x172
    ctx->r4 = 0 | 0X172;
    goto L_80038F40;
    // ori         $a0, $zero, 0x172
    ctx->r4 = 0 | 0X172;
L_80038F34:
    // ori         $a0, $zero, 0x168
    ctx->r4 = 0 | 0X168;
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
L_80038F40:
    // lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(0X0, ctx->r16);
    // jal         0x80038E6C
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    FindFreeOrOldestProjectileSlot(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    after_0:
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // sh          $v1, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r3;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // jal         0x80038004
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80038004(rdram, ctx);
    goto after_1;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(0X6, ctx->r17);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // sll         $s0, $v1, 1
    ctx->r16 = S32(ctx->r3) << 1;
    // sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $v0, $v0, 0x79F0
    ctx->r2 = ADD32(ctx->r2, 0X79F0);
    // jal         0x80062BF0
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    rand_recomp(rdram, ctx);
    goto after_2;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_2:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // nop

    // addiu       $v1, $v0, -0x10
    ctx->r3 = ADD32(ctx->r2, -0X10);
    // sltiu       $v0, $v1, 0x11
    ctx->r2 = ctx->r3 < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_80039038
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80039038;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1978
    ctx->r1 = ADD32(ctx->r1, 0X1978);
    // addu        $at, $at, $v0
    gpr jr_addend_80038FE0;
    jr_addend_80038FE0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80038FE0 >> 2) {
        case 0: goto L_80038FE8; break;
        case 1: goto L_80039010; break;
        case 2: goto L_80039010; break;
        case 3: goto L_80038FE8; break;
        case 4: goto L_80039010; break;
        case 5: goto L_80039010; break;
        case 6: goto L_80038FE8; break;
        case 7: goto L_80038FFC; break;
        case 8: goto L_80039010; break;
        case 9: goto L_80039010; break;
        case 10: goto L_80039038; break;
        case 11: goto L_80039038; break;
        case 12: goto L_80039038; break;
        case 13: goto L_80039038; break;
        case 14: goto L_80039038; break;
        case 15: goto L_80039038; break;
        case 16: goto L_80039010; break;
        default: switch_error(__func__, 0x80038FE0, 0x80011978);
    }
    // nop

L_80038FE8:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80038E4C
    // ori         $a1, $zero, 0x60
    ctx->r5 = 0 | 0X60;
    SetProjectileModel(rdram, ctx);
    goto after_3;
    // ori         $a1, $zero, 0x60
    ctx->r5 = 0 | 0X60;
    after_3:
    // j           L_8003903C
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_8003903C;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80038FFC:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80038E4C
    // ori         $a1, $zero, 0x61
    ctx->r5 = 0 | 0X61;
    SetProjectileModel(rdram, ctx);
    goto after_4;
    // ori         $a1, $zero, 0x61
    ctx->r5 = 0 | 0X61;
    after_4:
    // j           L_8003903C
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    goto L_8003903C;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_80039010:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80038E4C
    // ori         $a1, $zero, 0x62
    ctx->r5 = 0 | 0X62;
    SetProjectileModel(rdram, ctx);
    goto after_5;
    // ori         $a1, $zero, 0x62
    ctx->r5 = 0 | 0X62;
    after_5:
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // ori         $v0, $zero, 0x67
    ctx->r2 = 0 | 0X67;
    // bne         $v1, $v0, L_80039034
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x400
        ctx->r2 = 0 | 0X400;
        goto L_80039034;
    }
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // j           L_80039038
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
    goto L_80039038;
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
L_80039034:
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
L_80039038:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_8003903C:
    // sh          $zero, 0x3E($s1)
    MEM_H(0X3E, ctx->r17) = 0;
    // sb          $v0, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r2;
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
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
