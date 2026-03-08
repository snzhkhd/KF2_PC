#include "recomp.h"
#include "disable_warnings.h"

void sub_8004489C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(0X80, ctx->r29);
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(0X84, ctx->r29);
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // addiu       $s0, $sp, 0x8C
    ctx->r16 = ADD32(ctx->r29, 0X8C);
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(0X88, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a1, $v0, L_800448F4
    if (ctx->r5 != ctx->r2) {
        // sw          $ra, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r31;
        goto L_800448F4;
    }
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // j           L_80044904
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    goto L_80044904;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800448F4:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // jal         0x80042AEC
    // addiu       $a3, $s2, 0x2C
    ctx->r7 = ADD32(ctx->r18, 0X2C);
    sub_80042AEC(rdram, ctx);
    goto after_0;
    // addiu       $a3, $s2, 0x2C
    ctx->r7 = ADD32(ctx->r18, 0X2C);
    after_0:
L_80044904:
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // beq         $s1, $v0, L_8004496C
    if (ctx->r17 == ctx->r2) {
        // slti        $v0, $s1, -0x1
        ctx->r2 = SIGNED(ctx->r17) < -0X1 ? 1 : 0;
        goto L_8004496C;
    }
    // slti        $v0, $s1, -0x1
    ctx->r2 = SIGNED(ctx->r17) < -0X1 ? 1 : 0;
    // beq         $v0, $zero, L_80044928
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
        goto L_80044928;
    }
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // beq         $s1, $v0, L_800449E0
    if (ctx->r17 == ctx->r2) {
        // addiu       $a0, $s2, 0x24
        ctx->r4 = ADD32(ctx->r18, 0X24);
        goto L_800449E0;
    }
    // addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    // j           L_800449F8
    // nop

    goto L_800449F8;
    // nop

L_80044928:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_800449F8
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $s2, 0x24
        ctx->r4 = ADD32(ctx->r18, 0X24);
        goto L_800449F8;
    }
    // addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(0X8, ctx->r16);
    // lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(0XC, ctx->r16);
    // jal         0x80042AEC
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    sub_80042AEC(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_1:
    // lhu         $v0, 0x40($sp)
    ctx->r2 = MEM_HU(0X40, ctx->r29);
    // lhu         $v1, 0x44($sp)
    ctx->r3 = MEM_HU(0X44, ctx->r29);
    // lhu         $a0, 0x48($sp)
    ctx->r4 = MEM_HU(0X48, ctx->r29);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    // sh          $a0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r4;
    // lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(0X4, ctx->r16);
    // j           L_80044A30
    // nop

    goto L_80044A30;
    // nop

L_8004496C:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80062BF0
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    after_3:
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(0X10, ctx->r16);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80062BF0
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_4;
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    after_4:
    // lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(0X14, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x18($s0)
    ctx->r3 = MEM_HU(0X18, ctx->r16);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80044A90
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    goto L_80044A90;
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_800449E0:
    // sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(0X4, ctx->r16);
    // j           L_80044A30
    // nop

    goto L_80044A30;
    // nop

L_800449F8:
    // jal         0x80015538
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_5;
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // ori         $a0, $zero, 0x1E
    ctx->r4 = 0 | 0X1E;
    // jal         0x80015694
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    sub_80015694(rdram, ctx);
    goto after_6;
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // lhu         $v0, 0x28($sp)
    ctx->r2 = MEM_HU(0X28, ctx->r29);
    // lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(0X2C, ctx->r29);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(0X2A, ctx->r29);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
L_80044A30:
    // lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(0X34, ctx->r18);
    // nop

    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x28($sp)
    ctx->r3 = MEM_HU(0X28, ctx->r29);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r3;
    // lh          $v0, 0x36($s2)
    ctx->r2 = MEM_H(0X36, ctx->r18);
    // nop

    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x2A($sp)
    ctx->r3 = MEM_HU(0X2A, ctx->r29);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(0X38, ctx->r18);
    // nop

    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(0X2C, ctx->r29);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
L_80044A90:
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(0X34, ctx->r29);
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // ori         $a2, $zero, 0x65
    ctx->r6 = 0 | 0X65;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(0X8C, ctx->r29);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // jal         0x80042D2C
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
