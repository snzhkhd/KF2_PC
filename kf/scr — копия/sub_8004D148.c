#include "recomp.h"
#include "disable_warnings.h"

//проверка статуса прерываний (sub_8004D148)
void sub_8004D148(uint8_t* rdram, recomp_context* ctx)
{
    ctx->r2 = 0;
    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8C4($v1)
    ctx->r3 = MEM_W(-0X8C4, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x8B8($a0)
    ctx->r4 = MEM_W(-0X8B8, ctx->r4);
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8004D1A8
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8004D1A8;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // j           L_8004D678
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004D678;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004D198:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
L_8004D1A8:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // lbu         $v1, 0x10($sp)
    ctx->r3 = MEM_BU(0X10, ctx->r29);
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v1, $v0, L_8004D198
    if (ctx->r3 != ctx->r2) {
        // addiu       $v1, $sp, 0x18
        ctx->r3 = ADD32(ctx->r29, 0X18);
        goto L_8004D198;
    }
    // addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8004D1C0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8004D208
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x8
        ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
        goto L_8004D208;
    }
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C0($v0)
    ctx->r2 = MEM_W(-0X8C0, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8004D1C0
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D1C0;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
L_8004D208:
    // beq         $v0, $zero, L_8004D228
    if (ctx->r2 == 0) {
        // addiu       $v0, $sp, 0x18
        ctx->r2 = ADD32(ctx->r29, 0X18);
        goto L_8004D228;
    }
    // addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_8004D214:
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8004D214
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D214;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004D228:
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
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8BC($v0)
    ctx->r2 = MEM_W(-0X8BC, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // ori         $v1, $zero, 0x3
    ctx->r3 = 0 | 0X3;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $v1, L_8004D298
    if (ctx->r2 != ctx->r3) {
        // nop

        goto L_8004D298;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x9C4
    ctx->r1 = ADD32(ctx->r1, -0X9C4);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8004D2FC
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D2FC;
    }
    // nop

L_8004D298:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB78($v0)
    ctx->r2 = MEM_W(-0XB78, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8004D2DC
    if (ctx->r2 != 0) {
        // nop

        goto L_8004D2DC;
    }
    // nop

    // lbu         $v0, 0x18($sp)
    ctx->r2 = MEM_BU(0X18, ctx->r29);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8004D2DC
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D2DC;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB70($v0)
    ctx->r2 = MEM_W(-0XB70, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0xB70($at)
    MEM_W(-0XB70, ctx->r1) = ctx->r2;
L_8004D2DC:
    // lbu         $v0, 0x18($sp)
    ctx->r2 = MEM_BU(0X18, ctx->r29);
    // lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(0X19, ctx->r29);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // andi        $s0, $v0, 0x1D
    ctx->r16 = ctx->r2 & 0X1D;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0xB78($at)
    MEM_W(-0XB78, ctx->r1) = ctx->r2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, -0xB74($at)
    MEM_W(-0XB74, ctx->r1) = ctx->r3;
L_8004D2FC:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // ori         $v1, $zero, 0x5
    ctx->r3 = 0 | 0X5;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $v1, L_8004D370
    if (ctx->r2 != ctx->r3) {
        // nop

        goto L_8004D370;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2EA4
    ctx->r4 = ADD32(ctx->r4, 0X2EA4);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // blez        $v0, L_8004D370
    if (SIGNED(ctx->r2) <= 0) {
        // nop

        goto L_8004D370;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, -0xB78($a2)
    ctx->r6 = MEM_W(-0XB78, ctx->r6);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // lw          $a3, -0xB74($a3)
    ctx->r7 = MEM_W(-0XB74, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0xB64
    ctx->r1 = ADD32(ctx->r1, -0XB64);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a1, 0x0($at)
    ctx->r5 = MEM_W(0X0, ctx->r1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2EB0
    ctx->r4 = ADD32(ctx->r4, 0X2EB0);
    // jal         0x80062BA0
    // nop

    ps1_printf(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_8004D370:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8004D650
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8004D650;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x2EEC
    ctx->r1 = ADD32(ctx->r1, 0X2EEC);
    // addu        $at, $at, $v0
    gpr jr_addend_8004D39C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8004D39C >> 2) {
        case 0: goto L_8004D4F4; break;
        case 1: goto L_8004D4A8; break;
        case 2: goto L_8004D3A4; break;
        case 3: goto L_8004D540; break;
        case 4: goto L_8004D5C8; break;
        default: switch_error(__func__, 0x8004D39C, 0x80012EEC);
    }
    // nop

L_8004D3A4:
    // beq         $s0, $zero, L_8004D3F0
    if (ctx->r16 == 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8004D3F0;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x8AC
    ctx->r3 = ADD32(ctx->r3, -0X8AC);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6490
    ctx->r3 = ADD32(ctx->r3, 0X6490);
    // beq         $v1, $zero, L_8004D4EC
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D4EC;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D3D0:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D3D0
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D3D0;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // j           L_8004D678
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    goto L_8004D678;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8004D3F0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0xAC4
    ctx->r1 = ADD32(ctx->r1, -0XAC4);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8004D460
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8004D460;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x8AC
    ctx->r3 = ADD32(ctx->r3, -0X8AC);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6490
    ctx->r3 = ADD32(ctx->r3, 0X6490);
    // beq         $v1, $zero, L_8004D458
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D458;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D440:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D440
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D440;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004D458:
    // j           L_8004D678
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8004D678;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004D460:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x8AC
    ctx->r3 = ADD32(ctx->r3, -0X8AC);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6490
    ctx->r3 = ADD32(ctx->r3, 0X6490);
    // beq         $v1, $zero, L_8004D4EC
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D4EC;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D488:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D488
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D488;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // j           L_8004D678
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    goto L_8004D678;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8004D4A8:
    // beq         $s0, $zero, L_8004D4B4
    if (ctx->r16 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8004D4B4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_8004D4B4:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x8AC($at)
    MEM_B(-0X8AC, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6490
    ctx->r3 = ADD32(ctx->r3, 0X6490);
    // beq         $v1, $zero, L_8004D4EC
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D4EC;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D4D4:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D4D4
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D4D4;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004D4EC:
    // j           L_8004D678
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    goto L_8004D678;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8004D4F4:
    // beq         $s0, $zero, L_8004D500
    if (ctx->r16 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004D500;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_8004D500:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x8AB($at)
    MEM_B(-0X8AB, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6498
    ctx->r3 = ADD32(ctx->r3, 0X6498);
    // beq         $v1, $zero, L_8004D5C0
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D5C0;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D520:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D520
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D520;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // j           L_8004D678
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    goto L_8004D678;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
L_8004D540:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x64A0
    ctx->r4 = ADD32(ctx->r4, 0X64A0);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x8AA($at)
    MEM_B(-0X8AA, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, -0x8AA($v1)
    ctx->r3 = MEM_BU(-0X8AA, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x8AB
    ctx->r2 = ADD32(ctx->r2, -0X8AB);
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // beq         $a0, $zero, L_8004D590
    if (ctx->r4 == 0) {
        // ori         $v1, $zero, 0x7
        ctx->r3 = 0 | 0X7;
        goto L_8004D590;
    }
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D578:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $a2, L_8004D578
    if (ctx->r3 != ctx->r6) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8004D578;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8004D590:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6498
    ctx->r3 = ADD32(ctx->r3, 0X6498);
    // beq         $v1, $zero, L_8004D5C0
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D5C0;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D5A8:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D5A8
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D5A8;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004D5C0:
    // j           L_8004D678
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    goto L_8004D678;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
L_8004D5C8:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6490
    ctx->r4 = ADD32(ctx->r4, 0X6490);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x8AB($at)
    MEM_B(-0X8AB, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, -0x8AB($v1)
    ctx->r3 = MEM_BU(-0X8AB, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x8AC
    ctx->r2 = ADD32(ctx->r2, -0X8AC);
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // beq         $a0, $zero, L_8004D618
    if (ctx->r4 == 0) {
        // ori         $v1, $zero, 0x7
        ctx->r3 = 0 | 0X7;
        goto L_8004D618;
    }
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D600:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $a2, L_8004D600
    if (ctx->r3 != ctx->r6) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8004D600;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8004D618:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x6498
    ctx->r3 = ADD32(ctx->r3, 0X6498);
    // beq         $v1, $zero, L_8004D648
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_8004D648;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004D630:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8004D630
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8004D630;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004D648:
    // j           L_8004D678
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    goto L_8004D678;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
L_8004D650:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2ECC
    ctx->r4 = ADD32(ctx->r4, 0X2ECC);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lbu         $a1, 0x10($sp)
    ctx->r5 = MEM_BU(0X10, ctx->r29);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2EE0
    ctx->r4 = ADD32(ctx->r4, 0X2EE0);
    // jal         0x80062BA0
    // nop

    ps1_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004D678:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop
    */
    ;
}
