#include "recomp.h"
#include "disable_warnings.h"

void FindInteractableInCone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // lw          $fp, 0x94($sp)
    ctx->r30 = MEM_W(0X94, ctx->r29);
    // slti        $a0, $a0, 0x18C
    ctx->r4 = SIGNED(ctx->r4) < 0X18C ? 1 : 0;
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // beq         $a0, $zero, L_80038E14
    if (ctx->r4 == 0) {
        // sw          $s0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r16;
        goto L_80038E14;
    }
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // addiu       $s4, $v0, 0x14
    ctx->r20 = ADD32(ctx->r2, 0X14);
L_80038C7C:
    // lhu         $v1, -0x16($s2)
    ctx->r3 = MEM_HU(-0X16, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80038DF4
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_80038DF4;
    }
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
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // bne         $v1, $v0, L_80038D58
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x700
        ctx->r2 = 0 | 0X700;
        goto L_80038D58;
    }
    // ori         $v0, $zero, 0x700
    ctx->r2 = 0 | 0X700;
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // lh          $a0, 0xA($s2)
    ctx->r4 = MEM_H(0XA, ctx->r18);
    // jal         0x80015378
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015378(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // jal         0x8005DF04
    // addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    KF_ApplyMatrix(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(0X8, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, -0x10($s2)
    ctx->r2 = MEM_HU(-0X10, ctx->r18);
    // sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(0X28, ctx->r29);
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(0X30, ctx->r29);
    // jal         0x80015A88
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    GetDistanceIfInRange(rdram, ctx);
    goto after_2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_2:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80038DF8
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $s5, 0x1
        ctx->r2 = ADD32(ctx->r21, 0X1);
        goto L_80038DF8;
    }
    // addiu       $v0, $s5, 0x1
    ctx->r2 = ADD32(ctx->r21, 0X1);
    // lw          $v1, -0x8($s2)
    ctx->r3 = MEM_W(-0X8, ctx->r18);
    // lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(0X28, ctx->r29);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(0X30, ctx->r29);
    // j           L_80038DBC
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    goto L_80038DBC;
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
L_80038D58:
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(0X8, ctx->r19);
    // jal         0x80015A88
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    GetDistanceIfInRange(rdram, ctx);
    goto after_3;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_3:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80038DF8
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $s5, 0x1
        ctx->r2 = ADD32(ctx->r21, 0X1);
        goto L_80038DF8;
    }
    // addiu       $v0, $s5, 0x1
    ctx->r2 = ADD32(ctx->r21, 0X1);
    // lbu         $v0, -0x19($s2)
    ctx->r2 = MEM_BU(-0X19, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // bne         $v0, $zero, L_80038DEC
    if (ctx->r2 != 0) {
        // sll         $v0, $s5, 16
        ctx->r2 = S32(ctx->r21) << 16;
        goto L_80038DEC;
    }
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // lw          $v1, -0x8($s2)
    ctx->r3 = MEM_W(-0X8, ctx->r18);
    // lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(0X0, ctx->r19);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(0X8, ctx->r19);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
L_80038DBC:
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_4;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_4:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30) << 16;
    // lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(0X90, ctx->r29);
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
    // jal         0x80015798
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_5;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_5:
    // beq         $v0, $zero, L_80038DF4
    if (ctx->r2 == 0) {
        // sll         $v0, $s5, 16
        ctx->r2 = S32(ctx->r21) << 16;
        goto L_80038DF4;
    }
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
L_80038DEC:
    // j           L_80038E18
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    goto L_80038E18;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_80038DF4:
    // addiu       $v0, $s5, 0x1
    ctx->r2 = ADD32(ctx->r21, 0X1);
L_80038DF8:
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // addiu       $s2, $s2, 0x44
    ctx->r18 = ADD32(ctx->r18, 0X44);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x18C
    ctx->r2 = SIGNED(ctx->r2) < 0X18C ? 1 : 0;
    // bne         $v0, $zero, L_80038C7C
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x44
        ctx->r20 = ADD32(ctx->r20, 0X44);
        goto L_80038C7C;
    }
    // addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
L_80038E14:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80038E18:
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
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
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
