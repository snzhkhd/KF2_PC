#include "recomp.h"
#include "disable_warnings.h"

void sub_800518A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // addiu       $a2, $sp, 0x4
    ctx->r6 = ADD32(ctx->r29, 0X4);
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // beq         $a0, $a3, L_80051928
    if (ctx->r4 == ctx->r7) {
        // sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
        goto L_80051928;
    }
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800518E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800518E0;
    }
    // nop

    // beq         $a0, $zero, L_80051998
    if (ctx->r4 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80051998;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80051B44
    // nop

    goto L_80051B44;
    // nop

L_800518E0:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $a0, $v0, L_800518FC
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_800518FC;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $a0, $v0, L_80051A04
    if (ctx->r4 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80051A04;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80051B44
    // nop

    goto L_80051B44;
    // nop

L_800518FC:
    // lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(0X4, ctx->r29);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7A8($v0)
    ctx->r2 = MEM_W(-0X7A8, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // srlv        $v0, $a0, $v0
    ctx->r2 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, -0x7D0($at)
    MEM_H(-0X7D0, ctx->r1) = ctx->r2;
    // sh          $v0, 0x1A6($v1)
    MEM_H(0X1A6, ctx->r3) = ctx->r2;
    // j           L_80051B44
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80051B44;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80051928:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x7CC($a1)
    ctx->r5 = MEM_W(-0X7CC, ctx->r5);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lhu         $a0, -0x7D0($a0)
    ctx->r4 = MEM_HU(-0X7D0, ctx->r4);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x780($at)
    MEM_W(-0X780, ctx->r1) = 0;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // beq         $v0, $a0, L_80051970
    if (ctx->r2 == ctx->r4) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_80051970;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80051954:
    // slti        $v0, $v1, 0xF01
    ctx->r2 = SIGNED(ctx->r3) < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_80051B44
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_80051B44;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // nop

    // bne         $v0, $a0, L_80051954
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80051954;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80051970:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // nop

    // lhu         $a0, 0x1AA($v1)
    ctx->r4 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // andi        $v0, $a0, 0xFFCF
    ctx->r2 = ctx->r4 & 0XFFCF;
    // ori         $a0, $v0, 0x20
    ctx->r4 = ctx->r2 | 0X20;
    // sh          $a0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r4;
    // j           L_80051B44
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80051B44;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80051998:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x7CC($a1)
    ctx->r5 = MEM_W(-0X7CC, ctx->r5);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lhu         $a0, -0x7D0($a0)
    ctx->r4 = MEM_HU(-0X7D0, ctx->r4);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a3, -0x780($at)
    MEM_W(-0X780, ctx->r1) = ctx->r7;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // beq         $v0, $a0, L_800519E0
    if (ctx->r2 == ctx->r4) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_800519E0;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800519C4:
    // slti        $v0, $v1, 0xF01
    ctx->r2 = SIGNED(ctx->r3) < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_80051B44
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_80051B44;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // nop

    // bne         $v0, $a0, L_800519C4
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_800519C4;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800519E0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $a0, 0x1AA($v0)
    ctx->r4 = MEM_HU(0X1AA, ctx->r2);
    // nop

    // ori         $a0, $a0, 0x30
    ctx->r4 = ctx->r4 | 0X30;
    // sh          $a0, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = ctx->r4;
    // j           L_80051B44
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80051B44;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80051A04:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x780($v0)
    ctx->r2 = MEM_W(-0X780, ctx->r2);
    // nop

    // bne         $v0, $a3, L_80051A1C
    if (ctx->r2 != ctx->r7) {
        // ori         $a0, $zero, 0x20
        ctx->r4 = 0 | 0X20;
        goto L_80051A1C;
    }
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    // ori         $a0, $zero, 0x30
    ctx->r4 = 0 | 0X30;
L_80051A1C:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x7CC($a1)
    ctx->r5 = MEM_W(-0X7CC, ctx->r5);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r5);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // beq         $v0, $a0, L_80051A5C
    if (ctx->r2 == ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80051A5C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80051A3C:
    // slti        $v0, $v1, 0xF01
    ctx->r2 = SIGNED(ctx->r3) < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_80051B44
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_80051B44;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r5);
    // nop

    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // bne         $v0, $a0, L_80051A3C
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80051A3C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80051A5C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x780($v1)
    ctx->r3 = MEM_W(-0X780, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80051A90
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0xF0FF
        ctx->r3 = S32(0XF0FF << 16);
        goto L_80051A90;
    }
    // lui         $v1, 0xF0FF
    ctx->r3 = S32(0XF0FF << 16);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7B8($a0)
    ctx->r4 = MEM_W(-0X7B8, ctx->r4);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // j           L_80051AAC
    // lui         $v1, 0x2200
    ctx->r3 = S32(0X2200 << 16);
    goto L_80051AAC;
    // lui         $v1, 0x2200
    ctx->r3 = S32(0X2200 << 16);
L_80051A90:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7B8($a0)
    ctx->r4 = MEM_W(-0X7B8, ctx->r4);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $v1, 0x2000
    ctx->r3 = S32(0X2000 << 16);
L_80051AAC:
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // lw          $a0, -0x4($a2)
    ctx->r4 = MEM_W(-0X4, ctx->r6);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x7C8($a1)
    ctx->r5 = MEM_W(-0X7C8, ctx->r5);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, -0x77C($at)
    MEM_W(-0X77C, ctx->r1) = ctx->r4;
    // lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(0X0, ctx->r6);
    // lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // srl         $v1, $a0, 6
    ctx->r3 = S32(U32(ctx->r4) >> 6);
    // andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x77C($a0)
    ctx->r4 = MEM_W(-0X77C, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, -0x778($at)
    MEM_W(-0X778, ctx->r1) = ctx->r3;
    // sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x778($v0)
    ctx->r2 = MEM_W(-0X778, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7C4($v1)
    ctx->r3 = MEM_W(-0X7C4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x780($v1)
    ctx->r3 = MEM_W(-0X780, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80051B30
    if (ctx->r3 != ctx->r2) {
        // ori         $a2, $a2, 0x201
        ctx->r6 = ctx->r6 | 0X201;
        goto L_80051B30;
    }
    // ori         $a2, $a2, 0x201
    ctx->r6 = ctx->r6 | 0X201;
    // lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // ori         $a2, $a2, 0x200
    ctx->r6 = ctx->r6 | 0X200;
L_80051B30:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7C0($v0)
    ctx->r2 = MEM_W(-0X7C0, ctx->r2);
    // nop

    // sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80051B44:
    // jr          $ra
    // nop

    return;
    // nop

;}
