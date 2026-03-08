#include "recomp.h"
#include "disable_warnings.h"

void SsVabOpenHeadWithMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x438
    ctx->r29 = ADD32(ctx->r29, -0X438);
    // sw          $ra, 0x434($sp)
    MEM_W(0X434, ctx->r29) = ctx->r31;
    // sw          $s6, 0x430($sp)
    MEM_W(0X430, ctx->r29) = ctx->r22;
    // sw          $s5, 0x42C($sp)
    MEM_W(0X42C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x428($sp)
    MEM_W(0X428, ctx->r29) = ctx->r20;
    // sw          $s3, 0x424($sp)
    MEM_W(0X424, ctx->r29) = ctx->r19;
    // sw          $s2, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r18;
    // sw          $s1, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r16;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // ori         $s2, $zero, 0x10
    ctx->r18 = 0 | 0X10;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // jal         0x800520B8
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    sub_800520B8(rdram, ctx);
    goto after_0;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    after_0:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // bne         $v0, $v1, L_80053514
    if (ctx->r2 != ctx->r3) {
        // addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
        goto L_80053514;
    }
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // j           L_800538D0
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800538D0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80053514:
    // jal         0x8005208C
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_8005208C(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_1:
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_800535E8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800535E8;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8005358C
    if (ctx->r3 != ctx->r2) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005358C;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80053538:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8005356C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005356C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80053538
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_80053538;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // j           L_800535D8
    // nop

    goto L_800535D8;
    // nop

L_8005356C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x1064($v0)
    ctx->r2 = MEM_HU(-0X1064, ctx->r2);
    // j           L_800535C8
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    goto L_800535C8;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
L_8005358C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // bne         $v0, $zero, L_800535D8
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_800535D8;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x1064($v0)
    ctx->r2 = MEM_HU(-0X1064, ctx->r2);
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
L_800535C8:
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0x1064($at)
    MEM_H(-0X1064, ctx->r1) = ctx->r2;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_800535D8:
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_800535F8
    if (ctx->r2 != 0) {
        // addu        $a2, $s3, $zero
        ctx->r6 = ADD32(ctx->r19, 0);
        goto L_800535F8;
    }
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
L_800535E8:
    // jal         0x8005208C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005208C(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // j           L_800538D0
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800538D0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800535F8:
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x1F74
    ctx->r1 = ADD32(ctx->r1, -0X1F74);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a2, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r6;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(0X0, ctx->r7);
    // lui         $v1, 0x56
    ctx->r3 = S32(0X56 << 16);
    // ori         $v1, $v1, 0x4142
    ctx->r3 = ctx->r3 | 0X4142;
    // srl         $v0, $a1, 8
    ctx->r2 = S32(U32(ctx->r5) >> 8);
    // beq         $v0, $v1, L_80053640
    if (ctx->r2 == ctx->r3) {
        // addiu       $a2, $a2, 0x20
        ctx->r6 = ADD32(ctx->r6, 0X20);
        goto L_80053640;
    }
    // addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
    // j           L_800537E4
    // nop

    goto L_800537E4;
    // nop

L_80053640:
    // andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // bne         $v1, $v0, L_80053668
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_80053668;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // nop

    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80053668
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_80053668;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
L_80053668:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, -0x2568($at)
    MEM_H(-0X2568, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x12($a3)
    ctx->r2 = MEM_HU(0X12, ctx->r7);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lh          $v1, -0x2568($v1)
    ctx->r3 = MEM_H(-0X2568, ctx->r3);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800537D0
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_800537D0;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2110
    ctx->r1 = ADD32(ctx->r1, -0X2110);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a2, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r6;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $a2, $s3, $v0
    ctx->r6 = ADD32(ctx->r19, ctx->r2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // blez        $v1, L_800536E4
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_800536E4;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
L_800536C0:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_800536D4
    if (ctx->r2 == 0) {
        // sw          $s0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r16;
        goto L_800536D4;
    }
    // sw          $s0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r16;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800536D4:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_800536C0
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_800536C0;
    }
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800536E4:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x1F2C
    ctx->r1 = ADD32(ctx->r1, -0X1F2C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a2, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r6;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // lhu         $v0, 0x12($a3)
    ctx->r2 = MEM_HU(0X12, ctx->r7);
    // addiu       $t0, $sp, 0x410
    ctx->r8 = ADD32(ctx->r29, 0X410);
    // lbu         $s4, 0x16($a3)
    ctx->r20 = MEM_BU(0X16, ctx->r7);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20) << 2;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_80053720:
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80053754
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80053754;
    }
    // nop

    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // lhu         $a1, 0x0($a2)
    ctx->r5 = MEM_HU(0X0, ctx->r6);
    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80053744
    if (ctx->r2 != 0) {
        // sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5) << 2;
        goto L_80053744;
    }
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5) << 3;
L_80053744:
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80053754:
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // slt         $v0, $v1, $t0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_80053720
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_80053720;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x101C
    ctx->r1 = ADD32(ctx->r1, -0X101C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a2, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r6;
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // bne         $v0, $zero, L_800537BC
    if (ctx->r2 != 0) {
        // addu        $a3, $s6, $zero
        ctx->r7 = ADD32(ctx->r22, 0);
        goto L_800537BC;
    }
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // jal         0x800538F8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_SpuMalloc(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a3, $v0, L_800537C0
    if (ctx->r7 != ctx->r2) {
        // addu        $v1, $a3, $s0
        ctx->r3 = ADD32(ctx->r7, ctx->r16);
        goto L_800537C0;
    }
    // addu        $v1, $a3, $s0
    ctx->r3 = ADD32(ctx->r7, ctx->r16);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
    // j           L_800537E4
    // nop

    goto L_800537E4;
    // nop

L_800537BC:
    // addu        $v1, $a3, $s0
    ctx->r3 = ADD32(ctx->r7, ctx->r16);
L_800537C0:
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8005380C
    if (ctx->r2 == 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_8005380C;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_800537D0:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
L_800537E4:
    // jal         0x8005208C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005208C(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x1064($v1)
    ctx->r3 = MEM_HU(-0X1064, ctx->r3);
    // nop

    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v1, -0x1064($at)
    MEM_H(-0X1064, ctx->r1) = ctx->r3;
    // j           L_800538D0
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800538D0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005380C:
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x105C
    ctx->r1 = ADD32(ctx->r1, -0X105C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a3, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r7;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // slti        $v0, $v1, 0x0
    ctx->r2 = SIGNED(ctx->r3) < 0X0 ? 1 : 0;
    // bne         $v0, $zero, L_800538A0
    if (ctx->r2 != 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_800538A0;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_8005383C:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // bne         $v0, $zero, L_80053874
    if (ctx->r2 != 0) {
        // srl         $v1, $a1, 31
        ctx->r3 = S32(U32(ctx->r5) >> 31);
        goto L_80053874;
    }
    // srl         $v1, $a1, 31
    ctx->r3 = S32(U32(ctx->r5) >> 31);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // addu        $v0, $a3, $s0
    ctx->r2 = ADD32(ctx->r7, ctx->r16);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // j           L_80053890
    // sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    goto L_80053890;
    // sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
L_80053874:
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // addu        $v0, $a3, $s0
    ctx->r2 = ADD32(ctx->r7, ctx->r16);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
L_80053890:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8005383C
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8005383C;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800538A0:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x10A4
    ctx->r1 = ADD32(ctx->r1, -0X10A4);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sw          $s0, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r16;
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
L_800538D0:
    // lw          $ra, 0x434($sp)
    ctx->r31 = MEM_W(0X434, ctx->r29);
    // lw          $s6, 0x430($sp)
    ctx->r22 = MEM_W(0X430, ctx->r29);
    // lw          $s5, 0x42C($sp)
    ctx->r21 = MEM_W(0X42C, ctx->r29);
    // lw          $s4, 0x428($sp)
    ctx->r20 = MEM_W(0X428, ctx->r29);
    // lw          $s3, 0x424($sp)
    ctx->r19 = MEM_W(0X424, ctx->r29);
    // lw          $s2, 0x420($sp)
    ctx->r18 = MEM_W(0X420, ctx->r29);
    // lw          $s1, 0x41C($sp)
    ctx->r17 = MEM_W(0X41C, ctx->r29);
    // lw          $s0, 0x418($sp)
    ctx->r16 = MEM_W(0X418, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x438
    ctx->r29 = ADD32(ctx->r29, 0X438);
    return;
    // addiu       $sp, $sp, 0x438
    ctx->r29 = ADD32(ctx->r29, 0X438);
;}
