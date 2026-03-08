#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x84C($v0)
    ctx->r2 = MEM_W(-0X84C, ctx->r2);
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
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
    // beq         $s6, $v0, L_8004FDE4
    if (ctx->r22 == ctx->r2) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_8004FDE4;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22) << 1;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s6
    ctx->r2 = SUB32(ctx->r2, ctx->r22);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x6A90
    ctx->r1 = ADD32(ctx->r1, 0X6A90);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a1, 0x0($at)
    ctx->r5 = MEM_W(0X0, ctx->r1);
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, -0x7F4C
    ctx->r16 = ADD32(ctx->r16, -0X7F4C);
    // jal         0x8004FE14
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    CdReadSector(rdram, ctx);
    goto after_0;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // beq         $v0, $v1, L_8004FBFC
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8004FBFC;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // blez        $v0, L_8004FDE8
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004FDE8;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3164
    ctx->r4 = ADD32(ctx->r4, 0X3164);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8004FDE8
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004FDE8;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004FBFC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004FC24
    if (ctx->r2 != 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8004FC24;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3184
    ctx->r4 = ADD32(ctx->r4, 0X3184);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8004FC24:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v0, $zero, L_8004FD90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FD90;
    }
    // nop

    // lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // addiu       $s5, $s5, 0x64B4
    ctx->r21 = ADD32(ctx->r21, 0X64B4);
    // addiu       $s3, $s5, 0x8
    ctx->r19 = ADD32(ctx->r21, 0X8);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
L_8004FC44:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004FD90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FD90;
    }
    // nop

    // lwl         $v0, 0x5($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X5, ctx->r16);
    // lwr         $v0, 0x2($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X2, ctx->r16);
    // nop

    // swl         $v0, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r2);
    // swr         $v0, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r2);
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // jal         0x8004CFC4
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    SectorToMSF(rdram, ctx);
    goto after_3;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_3:
    // addiu       $v0, $s5, 0x4
    ctx->r2 = ADD32(ctx->r21, 0X4);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lwl         $v1, 0xD($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XD, ctx->r16);
    // lwr         $v1, 0xA($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XA, ctx->r16);
    // nop

    // swl         $v1, 0x3($v0)
    do_swl(rdram, 0X3, ctx->r2, ctx->r3);
    // swr         $v1, 0x0($v0)
    do_swr(rdram, 0X0, ctx->r2, ctx->r3);
    // beq         $s2, $zero, L_8004FCA8
    if (ctx->r18 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004FCA8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s2, $v0, L_8004FCB8
    if (ctx->r18 == ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8004FCB8;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8004FCD8
    // nop

    goto L_8004FCD8;
    // nop

L_8004FCA8:
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // lhu         $v0, 0x31A0($v0)
    ctx->r2 = MEM_HU(0X31A0, ctx->r2);
    // j           L_8004FCF4
    // sh          $v0, 0x8($s5)
    MEM_H(0X8, ctx->r21) = ctx->r2;
    goto L_8004FCF4;
    // sh          $v0, 0x8($s5)
    MEM_H(0X8, ctx->r21) = ctx->r2;
L_8004FCB8:
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // lh          $v0, 0x31A4($v0)
    ctx->r2 = MEM_H(0X31A4, ctx->r2);
    // lui         $v1, 0x8001
    ctx->r3 = S32(0X8001 << 16);
    // lb          $v1, 0x31A6($v1)
    ctx->r3 = MEM_B(0X31A6, ctx->r3);
    // sh          $v0, 0x20($s5)
    MEM_H(0X20, ctx->r21) = ctx->r2;
    // sb          $v1, 0x22($s5)
    MEM_B(0X22, ctx->r21) = ctx->r3;
    // j           L_8004FCF4
    // nop

    goto L_8004FCF4;
    // nop

L_8004FCD8:
    // lbu         $a2, 0x20($s0)
    ctx->r6 = MEM_BU(0X20, ctx->r16);
    // jal         0x8004FE80
    // addiu       $a1, $s0, 0x21
    ctx->r5 = ADD32(ctx->r16, 0X21);
    sub_8004FE80(rdram, ctx);
    goto after_4;
    // addiu       $a1, $s0, 0x21
    ctx->r5 = ADD32(ctx->r16, 0X21);
    after_4:
    // lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(0X20, ctx->r16);
    // nop

    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8004FCF4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004FD60
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x18
        ctx->r20 = ADD32(ctx->r20, 0X18);
        goto L_8004FD60;
    }
    // addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x64B4
    ctx->r1 = ADD32(ctx->r1, 0X64B4);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lbu         $a1, 0x0($at)
    ctx->r5 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x64B5
    ctx->r1 = ADD32(ctx->r1, 0X64B5);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lbu         $a2, 0x0($at)
    ctx->r6 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x64B6
    ctx->r1 = ADD32(ctx->r1, 0X64B6);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lbu         $a3, 0x0($at)
    ctx->r7 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x64B8
    ctx->r1 = ADD32(ctx->r1, 0X64B8);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x31A8
    ctx->r4 = ADD32(ctx->r4, 0X31A8);
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // jal         0x80062BA0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    psx_printf(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
L_8004FD60:
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // slti        $v0, $s2, 0x40
    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8004FD90
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
        goto L_8004FD90;
    }
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x774C
    ctx->r2 = ADD32(ctx->r2, -0X774C);
    // sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8004FC44
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004FC44;
    }
    // nop

L_8004FD90:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s6, -0x84C($at)
    MEM_W(-0X84C, ctx->r1) = ctx->r22;
    // slti        $v0, $s2, 0x40
    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8004FDBC
    if (ctx->r2 == 0) {
        // sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18) << 1;
        goto L_8004FDBC;
    }
    // sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x64BC
    ctx->r1 = ADD32(ctx->r1, 0X64BC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, 0x0($at)
    MEM_B(0X0, ctx->r1) = 0;
L_8004FDBC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004FDE8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004FDE8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x31C4
    ctx->r4 = ADD32(ctx->r4, 0X31C4);
    // jal         0x80062BA0
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    psx_printf(rdram, ctx);
    goto after_6;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_6:
L_8004FDE4:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004FDE8:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
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

;}
