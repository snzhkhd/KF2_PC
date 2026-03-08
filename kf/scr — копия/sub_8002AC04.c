#include "recomp.h"
#include "disable_warnings.h"

void sub_8002AC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x49FA($v1)
    ctx->r3 = MEM_HU(-0X49FA, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6300($v0)
    ctx->r2 = MEM_W(0X6300, ctx->r2);
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8002AC74
    if (ctx->r2 == 0) {
        // sw          $ra, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r31;
        goto L_8002AC74;
    }
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F0($v0)
    ctx->r2 = MEM_W(-0X49F0, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A0C($v1)
    ctx->r3 = MEM_HU(-0X4A0C, ctx->r3);
    // sra         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) >> 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002AD60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002AD60;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F0($v0)
    ctx->r2 = MEM_HU(-0X49F0, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = ctx->r2;
    // j           L_8002AD60
    // nop

    goto L_8002AD60;
    // nop

L_8002AC74:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62FC($v0)
    ctx->r2 = MEM_W(0X62FC, ctx->r2);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8002ACE4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002ACE4;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F0($v0)
    ctx->r2 = MEM_W(-0X49F0, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A0C($v1)
    ctx->r3 = MEM_HU(-0X4A0C, ctx->r3);
    // sra         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8002AD60
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002AD60;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F0($v0)
    ctx->r2 = MEM_HU(-0X49F0, ctx->r2);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = ctx->r2;
    // j           L_8002AD60
    // nop

    goto L_8002AD60;
    // nop

L_8002ACE4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A0C($v0)
    ctx->r2 = MEM_H(-0X4A0C, ctx->r2);
    // nop

    // blez        $v0, L_8002AD28
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002AD28;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F0($v0)
    ctx->r2 = MEM_W(-0X49F0, ctx->r2);
    // nop

    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8002AD58
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8002AD58;
    }
    // nop

    // j           L_8002AD60
    // nop

    goto L_8002AD60;
    // nop

L_8002AD28:
    // bgez        $v0, L_8002AD60
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8002AD60;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F0($v0)
    ctx->r2 = MEM_W(-0X49F0, ctx->r2);
    // nop

    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002AD60
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8002AD60;
    }
    // nop

L_8002AD58:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = 0;
L_8002AD60:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4A42
    ctx->r4 = ADD32(ctx->r4, -0X4A42);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A0C($v1)
    ctx->r3 = MEM_HU(-0X4A0C, ctx->r3);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x49FA($a1)
    ctx->r5 = MEM_HU(-0X49FA, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62E8($v1)
    ctx->r3 = MEM_W(0X62E8, ctx->r3);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // and         $v1, $a1, $v1
    ctx->r3 = ctx->r5 & ctx->r3;
    // beq         $v1, $zero, L_8002ADD4
    if (ctx->r3 == 0) {
        // sh          $v0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_8002ADD4;
    }
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A0A($v0)
    ctx->r2 = MEM_HU(-0X4A0A, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x21
    ctx->r2 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // bne         $v0, $zero, L_8002AE80
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x20
        ctx->r2 = 0 | 0X20;
        goto L_8002AE80;
    }
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = ctx->r2;
    // j           L_8002AE80
    // nop

    goto L_8002AE80;
    // nop

L_8002ADD4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F0($v0)
    ctx->r2 = MEM_W(0X62F0, ctx->r2);
    // nop

    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8002AE28
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002AE28;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A0A($v0)
    ctx->r2 = MEM_HU(-0X4A0A, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0x20
    ctx->r2 = SIGNED(ctx->r2) < -0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8002AE80
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x20
        ctx->r2 = ADD32(0, -0X20);
        goto L_8002AE80;
    }
    // addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = ctx->r2;
    // j           L_8002AE80
    // nop

    goto L_8002AE80;
    // nop

L_8002AE28:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A0A($v1)
    ctx->r3 = MEM_H(-0X4A0A, ctx->r3);
    // nop

    // blez        $v1, L_8002AE5C
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8002AE5C;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8002AE78
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8002AE78;
    }
    // nop

    // j           L_8002AE80
    // nop

    goto L_8002AE80;
    // nop

L_8002AE5C:
    // bgez        $v1, L_8002AE80
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $v0, $v0, 0x3
        ctx->r2 = ADD32(ctx->r2, 0X3);
        goto L_8002AE80;
    }
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002AEC8
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8002AEC8;
    }
    // nop

L_8002AE78:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = 0;
L_8002AE80:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A0A($v0)
    ctx->r2 = MEM_H(-0X4A0A, ctx->r2);
    // nop

    // blez        $v0, L_8002AED0
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002AED0;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4A44($a0)
    ctx->r4 = MEM_HU(-0X4A44, ctx->r4);
    // nop

    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = ctx->r4;
    // jal         0x800157D4
    // ori         $a1, $zero, 0x2BC
    ctx->r5 = 0 | 0X2BC;
    sub_800157D4(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0x2BC
    ctx->r5 = 0 | 0X2BC;
    after_0:
    // beq         $v0, $zero, L_8002AF10
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2BC
        ctx->r2 = 0 | 0X2BC;
        goto L_8002AF10;
    }
    // ori         $v0, $zero, 0x2BC
    ctx->r2 = 0 | 0X2BC;
    // j           L_8002AF08
    // nop

    goto L_8002AF08;
    // nop

L_8002AEC8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A0A($v0)
    ctx->r2 = MEM_H(-0X4A0A, ctx->r2);
L_8002AED0:
    // nop

    // bgez        $v0, L_8002AF10
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002AF10;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4A44($a1)
    ctx->r5 = MEM_HU(-0X4A44, ctx->r5);
    // nop

    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // andi        $a1, $a1, 0xFFF
    ctx->r5 = ctx->r5 & 0XFFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a1, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = ctx->r5;
    // jal         0x800157D4
    // addiu       $a0, $zero, -0x2BC
    ctx->r4 = ADD32(0, -0X2BC);
    sub_800157D4(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x2BC
    ctx->r4 = ADD32(0, -0X2BC);
    after_1:
    // beq         $v0, $zero, L_8002AF10
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2BC
        ctx->r2 = ADD32(0, -0X2BC);
        goto L_8002AF10;
    }
    // addiu       $v0, $zero, -0x2BC
    ctx->r2 = ADD32(0, -0X2BC);
L_8002AF08:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = ctx->r2;
L_8002AF10:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
