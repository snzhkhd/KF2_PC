#include "recomp.h"
#include "disable_warnings.h"

// проверка завершения (sub_8004E73C)
void sub_8004E73C(uint8_t* rdram, recomp_context* ctx)
{
    ctx->r2 = 0;
    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x8A8
    ctx->r4 = ADD32(ctx->r4, -0X8A8);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // blez        $v1, L_8004EA7C
    if (SIGNED(ctx->r3) <= 0) {
        // nop

        goto L_8004EA7C;
    }
    // nop

    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // ori         $s3, $zero, 0x7
    ctx->r19 = 0 | 0X7;
    // addiu       $s2, $s5, 0x10
    ctx->r18 = ADD32(ctx->r21, 0X10);
L_8004E798:
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_8004E90C
    if (ctx->r2 == 0) {
        // nop

        goto L_8004E90C;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2FA0
    ctx->r4 = ADD32(ctx->r4, 0X2FA0);
    // jal         0x80062C20
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    sub_80062C20(rdram, ctx);
    goto after_0;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_0:
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lbu         $a2, -0xB6C($a2)
    ctx->r6 = MEM_BU(-0XB6C, ctx->r6);
    // lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(0X0, ctx->r21);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // lbu         $a3, -0xB6B($a3)
    ctx->r7 = MEM_BU(-0XB6B, ctx->r7);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB6A($v0)
    ctx->r2 = MEM_BU(-0XB6A, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2FB0
    ctx->r4 = ADD32(ctx->r4, 0X2FB0);
    // jal         0x80062BA0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ps1_printf(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x880($v0)
    ctx->r2 = MEM_W(-0X880, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0xB70($v1)
    ctx->r3 = MEM_W(-0XB70, ctx->r3);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004E8D8
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x9
        ctx->r4 = 0 | 0X9;
        goto L_8004E8D8;
    }
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // lw          $s1, -0xB88($s1)
    ctx->r17 = MEM_W(-0XB88, ctx->r17);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB78($v0)
    ctx->r2 = MEM_W(-0XB78, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8004E878
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_8004E878;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_8004E830:
    // bne         $v0, $zero, L_8004E848
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004E848;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2F34
    ctx->r4 = ADD32(ctx->r4, 0X2F34);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8004E848:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8004DBE0(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB78($v0)
    ctx->r2 = MEM_W(-0XB78, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8004E830
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
        goto L_8004E830;
    }
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_8004E878:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x87C
    ctx->r5 = ADD32(ctx->r5, -0X87C);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8004DBE0(rdram, ctx);
    goto after_4;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // beq         $v0, $zero, L_8004E8BC
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_8004E8BC;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8004DBE0(rdram, ctx);
    goto after_5;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2F44
    ctx->r4 = ADD32(ctx->r4, 0X2F44);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_8004E878
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    goto L_8004E878;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_8004E8BC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB70($v0)
    ctx->r2 = MEM_W(-0XB70, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s1, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r17;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x880($at)
    MEM_W(-0X880, ctx->r1) = ctx->r2;
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
L_8004E8D8:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8004DBE0(rdram, ctx);
    goto after_7;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // bne         $v0, $zero, L_8004EA5C
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_8004EA5C;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0xB6C
    ctx->r5 = ADD32(ctx->r5, -0XB6C);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8004DBE0(rdram, ctx);
    goto after_8;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // bne         $v0, $zero, L_8004EA5C
    if (ctx->r2 != 0) {
        // nop

        goto L_8004EA5C;
    }
    // nop

L_8004E90C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $s4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r20;
    // j           L_8004E954
    // nop

    goto L_8004E954;
    // nop

L_8004E924:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $s4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r20;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // sb          $s3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r19;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8BC($v0)
    ctx->r2 = MEM_W(-0X8BC, ctx->r2);
    // nop

    // sb          $s3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r19;
L_8004E954:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $zero, L_8004E924
    if (ctx->r2 != 0) {
        // nop

        goto L_8004E924;
    }
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x8AA($at)
    MEM_B(-0X8AA, ctx->r1) = 0;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, -0x8AA($v1)
    ctx->r3 = MEM_BU(-0X8AA, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x8AB
    ctx->r2 = ADD32(ctx->r2, -0X8AB);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0xB68($at)
    MEM_B(-0XB68, ctx->r1) = 0;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8C4($v1)
    ctx->r3 = MEM_W(-0X8C4, ctx->r3);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x8AC($at)
    MEM_B(-0X8AC, ctx->r1) = ctx->r2;
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8B4($v1)
    ctx->r3 = MEM_W(-0X8B4, ctx->r3);
    // ori         $v0, $zero, 0x1325
    ctx->r2 = 0 | 0X1325;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, -0xB68($v1)
    ctx->r3 = MEM_BU(-0XB68, ctx->r3);
    // sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // beq         $v0, $v1, L_8004EA04
    if (ctx->r2 == ctx->r3) {
        // ori         $a0, $zero, 0xE
        ctx->r4 = 0 | 0XE;
        goto L_8004EA04;
    }
    // ori         $a0, $zero, 0xE
    ctx->r4 = 0 | 0XE;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8004DBE0(rdram, ctx);
    goto after_9;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_9:
    // bne         $v0, $zero, L_8004EA5C
    if (ctx->r2 != 0) {
        // nop

        goto L_8004EA5C;
    }
    // nop

L_8004EA04:
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // lw          $v1, -0x8($s2)
    ctx->r3 = MEM_W(-0X8, ctx->r18);
    // lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // addiu       $v0, $v0, -0xE5C
    ctx->r2 = ADD32(ctx->r2, -0XE5C);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
    // sw          $v1, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r3;
    // jal         0x8004DBE0
    // nop

    sub_8004DBE0(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lw          $v0, -0xC($s2)
    ctx->r2 = MEM_W(-0XC, ctx->r18);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // jal         0x8006263C
    // nop

    KF_VSync(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, 0X1E0);
    // sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // j           L_8004EA90
    // nop

    goto L_8004EA90;
    // nop

L_8004EA5C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x8A8
    ctx->r4 = ADD32(ctx->r4, -0X8A8);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // bgtz        $v1, L_8004E798
    if (SIGNED(ctx->r3) > 0) {
        // nop

        goto L_8004E798;
    }
    // nop

L_8004EA7C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x890
    ctx->r2 = ADD32(ctx->r2, -0X890);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
L_8004EA90:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop
    */
    ;
}
