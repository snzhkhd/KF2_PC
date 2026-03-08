#include "recomp.h"
#include "disable_warnings.h"

void sub_800511C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lhu         $v0, -0x7D0($v0)
    ctx->r2 = MEM_HU(-0X7D0, ctx->r2);
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lhu         $a1, 0x1AE($v1)
    ctx->r5 = MEM_HU(0X1AE, ctx->r3);
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sh          $v0, 0x1A6($v1)
    MEM_H(0X1A6, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_80051260
    if (ctx->r2 == 0) {
        // andi        $s4, $a1, 0x7FF
        ctx->r20 = ctx->r5 & 0X7FF;
        goto L_80051260;
    }
    // andi        $s4, $a1, 0x7FF
    ctx->r20 = ctx->r5 & 0X7FF;
L_80051220:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80051220
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051220;
    }
    // nop

L_80051260:
    // beq         $s1, $zero, L_80051448
    if (ctx->r17 == 0) {
        // sltiu       $v0, $s1, 0x41
        ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
        goto L_80051448;
    }
    // sltiu       $v0, $s1, 0x41
    ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
    // ori         $s3, $zero, 0xD
    ctx->r19 = 0 | 0XD;
L_8005126C:
    // bne         $v0, $zero, L_80051278
    if (ctx->r2 != 0) {
        // addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
        goto L_80051278;
    }
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // ori         $s0, $zero, 0x40
    ctx->r16 = 0 | 0X40;
L_80051278:
    // blez        $s0, L_800512A4
    if (SIGNED(ctx->r16) <= 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_800512A4;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7CC($a0)
    ctx->r4 = MEM_W(-0X7CC, ctx->r4);
L_80051288:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // sh          $v0, 0x1A8($a0)
    MEM_H(0X1A8, ctx->r4) = ctx->r2;
    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_80051288
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051288;
    }
    // nop

L_800512A4:
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
    // ori         $a0, $v0, 0x10
    ctx->r4 = ctx->r2 | 0X10;
    // sh          $a0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r4;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_800512FC
    // nop

    goto L_800512FC;
    // nop

L_800512D4:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_800512FC:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800512D4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800512D4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x7D4($at)
    MEM_W(-0X7D4, ctx->r1) = 0;
    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8005139C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005139C;
    }
    // nop

L_80051338:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7D4($v0)
    ctx->r2 = MEM_W(-0X7D4, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7D4($at)
    MEM_W(-0X7D4, ctx->r1) = ctx->r2;
    // slti        $v0, $v0, 0x1389
    ctx->r2 = SIGNED(ctx->r2) < 0X1389 ? 1 : 0;
    // bne         $v0, $zero, L_8005137C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005137C;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x321C
    ctx->r5 = ADD32(ctx->r5, 0X321C);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8005139C
    // nop

    goto L_8005139C;
    // nop

L_8005137C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // bne         $v0, $zero, L_80051338
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051338;
    }
    // nop

L_8005139C:
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_800513D4
    // nop

    goto L_800513D4;
    // nop

L_800513AC:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_800513D4:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800513AC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800513AC;
    }
    // nop

    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80051424
    // nop

    goto L_80051424;
    // nop

L_800513FC:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_80051424:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800513FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800513FC;
    }
    // nop

    // subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // bne         $s1, $zero, L_8005126C
    if (ctx->r17 != 0) {
        // sltiu       $v0, $s1, 0x41
        ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
        goto L_8005126C;
    }
    // sltiu       $v0, $s1, 0x41
    ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
L_80051448:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $a0, 0x1AA($v0)
    ctx->r4 = MEM_HU(0X1AA, ctx->r2);
    // nop

    // andi        $a0, $a0, 0xFFCF
    ctx->r4 = ctx->r4 & 0XFFCF;
    // sh          $a0, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = ctx->r4;
    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // andi        $a1, $s4, 0xFFFF
    ctx->r5 = ctx->r20 & 0XFFFF;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x7D4($at)
    MEM_W(-0X7D4, ctx->r1) = 0;
    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // beq         $v0, $a1, L_800514E4
    if (ctx->r2 == ctx->r5) {
        // nop
    
        goto L_800514E4;
    }
    // nop

L_80051480:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7D4($v0)
    ctx->r2 = MEM_W(-0X7D4, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7D4($at)
    MEM_W(-0X7D4, ctx->r1) = ctx->r2;
    // slti        $v0, $v0, 0x1389
    ctx->r2 = SIGNED(ctx->r2) < 0X1389 ? 1 : 0;
    // bne         $v0, $zero, L_800514C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800514C4;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x3230
    ctx->r5 = ADD32(ctx->r5, 0X3230);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_800514E4
    // nop

    goto L_800514E4;
    // nop

L_800514C4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // bne         $v0, $a1, L_80051480
    if (ctx->r2 != ctx->r5) {
        // nop
    
        goto L_80051480;
    }
    // nop

L_800514E4:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
