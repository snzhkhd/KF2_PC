#include "recomp.h"
#include "disable_warnings.h"

void sub_8005476C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x63
    ctx->r16 = 0 | 0X63;
    // ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // lbu         $t4, -0x1921($t4)
    ctx->r12 = MEM_BU(-0X1921, ctx->r12);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49D8($v0)
    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
    // ori         $t1, $zero, 0x63
    ctx->r9 = 0 | 0X63;
    // beq         $v0, $zero, L_80054900
    if (ctx->r2 == 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_80054900;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
L_800547A8:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // bne         $v0, $zero, L_800547FC
    if (ctx->r2 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_800547FC;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AA
    ctx->r1 = ADD32(ctx->r1, -0X75AA);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // bne         $v0, $zero, L_800547FC
    if (ctx->r2 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_800547FC;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // j           L_80054900
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    goto L_80054900;
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
L_800547FC:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7598
    ctx->r1 = ADD32(ctx->r1, -0X7598);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lh          $a2, 0x0($at)
    ctx->r6 = MEM_H(0X0, ctx->r1);
    // andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    // slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80054860
    if (ctx->r2 == 0) {
        // addu        $a1, $a2, $zero
        ctx->r5 = ADD32(ctx->r6, 0);
        goto L_80054860;
    }
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AA
    ctx->r1 = ADD32(ctx->r1, -0X75AA);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $t3, 0x0($at)
    ctx->r11 = MEM_HU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $t0, 0x0($at)
    ctx->r8 = MEM_HU(0X0, ctx->r1);
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // j           L_800548E4
    // ori         $t2, $zero, 0x1
    ctx->r10 = 0 | 0X1;
    goto L_800548E4;
    // ori         $t2, $zero, 0x1
    ctx->r10 = 0 | 0X1;
L_80054860:
    // bne         $a2, $a0, L_800548E4
    if (ctx->r6 != ctx->r4) {
        // andi        $a0, $t3, 0xFFFF
        ctx->r4 = ctx->r11 & 0XFFFF;
        goto L_800548E4;
    }
    // andi        $a0, $t3, 0xFFFF
    ctx->r4 = ctx->r11 & 0XFFFF;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AA
    ctx->r1 = ADD32(ctx->r1, -0X75AA);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $a1, 0x0($at)
    ctx->r5 = MEM_HU(0X0, ctx->r1);
    // nop

    // sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_800548B0
    if (ctx->r2 == 0) {
        // addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_800548B0;
    }
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AA
    ctx->r1 = ADD32(ctx->r1, -0X75AA);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $t3, 0x0($at)
    ctx->r11 = MEM_HU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $t0, 0x0($at)
    ctx->r8 = MEM_HU(0X0, ctx->r1);
    // j           L_800548E4
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    goto L_800548E4;
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
L_800548B0:
    // bne         $a1, $a0, L_800548E4
    if (ctx->r5 != ctx->r4) {
        // nop
    
        goto L_800548E4;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800548E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800548E4;
    }
    // nop

    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
L_800548E4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800547A8
    if (ctx->r2 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_800547A8;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
L_80054900:
    // andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // bne         $v1, $v0, L_80054920
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t2, 0xFF
        ctx->r2 = ctx->r10 & 0XFF;
        goto L_80054920;
    }
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // bne         $v0, $zero, L_80054920
    if (ctx->r2 != 0) {
        // addu        $s0, $t1, $zero
        ctx->r16 = ADD32(ctx->r9, 0);
        goto L_80054920;
    }
    // addu        $s0, $t1, $zero
    ctx->r16 = ADD32(ctx->r9, 0);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // lbu         $s0, -0x49D8($s0)
    ctx->r16 = MEM_BU(-0X49D8, ctx->r16);
L_80054920:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x49D8($a0)
    ctx->r4 = MEM_BU(-0X49D8, ctx->r4);
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_800549FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800549FC;
    }
    // nop

    // beq         $a0, $zero, L_80054990
    if (ctx->r4 == 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_80054990;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, -0x75B0
    ctx->r5 = ADD32(ctx->r5, -0X75B0);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_8005494C:
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_8005494C
    if (ctx->r2 != 0) {
        // andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
        goto L_8005494C;
    }
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_80054990:
    // andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1921($v1)
    ctx->r3 = MEM_BU(-0X1921, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $a0, 0x0($at)
    ctx->r4 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7598
    ctx->r1 = ADD32(ctx->r1, -0X7598);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $a0, $v0, L_80054A00
    if (ctx->r4 != ctx->r2) {
        // andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
        goto L_80054A00;
    }
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // jal         0x80059720
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    sub_80059720(rdram, ctx);
    goto after_0;
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_0:
L_800549FC:
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
L_80054A00:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
