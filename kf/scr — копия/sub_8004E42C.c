#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2F88
    ctx->r4 = ADD32(ctx->r4, 0X2F88);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80062C20
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80062C20(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2F94
    ctx->r4 = ADD32(ctx->r4, 0X2F94);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x878
    ctx->r5 = ADD32(ctx->r5, -0X878);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x8A8
    ctx->r3 = ADD32(ctx->r3, -0X8A8);
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0xB67($at)
    MEM_B(-0XB67, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0xB68($at)
    MEM_B(-0XB68, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB74($at)
    MEM_W(-0XB74, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB78($at)
    MEM_W(-0XB78, ctx->r1) = 0;
L_8004E4A0:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $a0, L_8004E4A0
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8004E4A0;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // jal         0x80061B54
    // nop

    KF_ResetCallback(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // addiu       $a1, $a1, -0xF3C
    ctx->r5 = ADD32(ctx->r5, -0XF3C);
    // jal         0x80061B84
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    InterruptCallback(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    after_3:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8C4($v1)
    ctx->r3 = MEM_W(-0X8C4, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
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
    // beq         $v0, $zero, L_8004E54C
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_8004E54C;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
L_8004E4FC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8BC($v0)
    ctx->r2 = MEM_W(-0X8BC, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
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
    // bne         $v0, $zero, L_8004E4FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004E4FC;
    }
    // nop

L_8004E54C:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
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
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
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
    // jal         0x8004DBE0
    // nop

    CD_cw_8004DBE0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB78($v0)
    ctx->r2 = MEM_W(-0XB78, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8004E5E8
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8004E5E8;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_5;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
L_8004E5E8:
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
    // beq         $v0, $zero, L_8004E6D8
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_8004E6D8;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
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
    // beq         $v0, $zero, L_8004E678
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_8004E678;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_8004E630:
    // bne         $v0, $zero, L_8004E648
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8004E648;
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
    goto after_6;
    // nop

    after_6:
L_8004E648:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_7;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB78($v0)
    ctx->r2 = MEM_W(-0XB78, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8004E630
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
        goto L_8004E630;
    }
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_8004E678:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x87C
    ctx->r5 = ADD32(ctx->r5, -0X87C);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_8;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // beq         $v0, $zero, L_8004E6BC
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_8004E6BC;
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
    CD_cw_8004DBE0(rdram, ctx);
    goto after_9;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_9:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2F44
    ctx->r4 = ADD32(ctx->r4, 0X2F44);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // j           L_8004E678
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    goto L_8004E678;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_8004E6BC:
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
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
L_8004E6D8:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_11;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // bne         $v0, $zero, L_8004E724
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004E724;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // ori         $a0, $zero, 0xC
    ctx->r4 = 0 | 0XC;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_12;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // bne         $v0, $zero, L_8004E724
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004E724;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8004D68C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    InitDmaChannel(rdram, ctx);
    goto after_13;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8004E724:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
