#include "recomp.h"
#include "disable_warnings.h"

void sub_800395EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(0X60, ctx->r29);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // beq         $v1, $zero, L_80039644
    if (ctx->r3 == 0) {
        // addu        $s6, $a3, $zero
        ctx->r22 = ADD32(ctx->r7, 0);
        goto L_80039644;
    }
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80039728
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80039728;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8003986C
    // nop

    goto L_8003986C;
    // nop

L_80039644:
    // lbu         $v1, 0x38($s2)
    ctx->r3 = MEM_BU(0X38, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8003986C
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8003986C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8003966C
    if (ctx->r2 != 0) {
        // addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
        goto L_8003966C;
    }
    // addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // j           L_80039670
    // sb          $zero, 0x40($s2)
    MEM_B(0X40, ctx->r18) = 0;
    goto L_80039670;
    // sb          $zero, 0x40($s2)
    MEM_B(0X40, ctx->r18) = 0;
L_8003966C:
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
L_80039670:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80038004
    // sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    sub_80038004(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    after_0:
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // beq         $s5, $zero, L_8003969C
    if (ctx->r21 == 0) {
        // sb          $v0, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r2;
        goto L_8003969C;
    }
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // j           L_800396A4
    // sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    goto L_800396A4;
    // sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
L_8003969C:
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800396A4:
    // addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x80015614
    // addiu       $a2, $s1, 0x14
    ctx->r6 = ADD32(ctx->r17, 0X14);
    sub_80015614(rdram, ctx);
    goto after_1;
    // addiu       $a2, $s1, 0x14
    ctx->r6 = ADD32(ctx->r17, 0X14);
    after_1:
    // lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(0X14, ctx->r17);
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(0X18, ctx->r17);
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(0X1C, ctx->r17);
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2) << 8;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) << 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // lhu         $v1, 0x26($s2)
    ctx->r3 = MEM_HU(0X26, ctx->r18);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sh          $v0, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r2;
    // sh          $v1, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r3;
L_80039728:
    // beq         $s5, $zero, L_8003975C
    if (ctx->r21 == 0) {
        // addiu       $s0, $s2, 0x24
        ctx->r16 = ADD32(ctx->r18, 0X24);
        goto L_8003975C;
    }
    // addiu       $s0, $s2, 0x24
    ctx->r16 = ADD32(ctx->r18, 0X24);
    // lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(0XA, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0xCC
    ctx->r2 = ADD32(ctx->r2, 0XCC);
    // sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(0XA, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80039760
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80039760;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
L_8003975C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80039760:
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x80015614
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80015614(rdram, ctx);
    goto after_2;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // jal         0x80015614
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    sub_80015614(rdram, ctx);
    goto after_3;
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x40($s2)
    MEM_B(0X40, ctx->r18) = ctx->r2;
    // lbu         $s0, 0x40($s2)
    ctx->r16 = MEM_BU(0X40, ctx->r18);
    // nop

    // sll         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16) << 12;
    // div         $zero, $s0, $s3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r19)));
    // bne         $s3, $zero, L_800397A8
    if (ctx->r19 != 0) {
        // nop
    
        goto L_800397A8;
    }
    // nop

    // break       7
    do_break(2147719076);
L_800397A8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s3, $at, L_800397C0
    if (ctx->r19 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800397C0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s0, $at, L_800397C0
    if (ctx->r16 != ctx->r1) {
        // nop
    
        goto L_800397C0;
    }
    // nop

    // break       6
    do_break(2147719100);
L_800397C0:
    // mflo        $s0
    ctx->r16 = lo;
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(0X20, ctx->r29);
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_4;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(0X14, ctx->r29);
    // lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(0X24, ctx->r29);
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_5;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(0X28, ctx->r29);
    // jal         0x80015D18
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    FixedPointLerp(rdram, ctx);
    goto after_6;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(0X1C, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x40($s2)
    ctx->r2 = MEM_BU(0X40, ctx->r18);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_80039868
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80039868;
    }
    // nop

    // beq         $s5, $zero, L_80039848
    if (ctx->r21 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80039848;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
L_80039848:
    // jal         0x80037F78
    // ori         $a1, $zero, 0x42
    ctx->r5 = 0 | 0X42;
    sub_80037F78(rdram, ctx);
    goto after_7;
    // ori         $a1, $zero, 0x42
    ctx->r5 = 0 | 0X42;
    after_7:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // sb          $v1, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r3;
    // ori         $v1, $zero, 0x63
    ctx->r3 = 0 | 0X63;
    // j           L_8003986C
    // sh          $v1, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r3;
    goto L_8003986C;
    // sh          $v1, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r3;
L_80039868:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003986C:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
