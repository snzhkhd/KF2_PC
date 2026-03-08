#include "recomp.h"
#include "disable_warnings.h"

void sub_8003ECE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79B4($s0)
    ctx->r16 = MEM_W(0X79B4, ctx->r16);
    // lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(0X30, ctx->r29);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lh          $v0, 0x58($s0)
    ctx->r2 = MEM_H(0X58, ctx->r16);
    // lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(0X34, ctx->r29);
    // blez        $v0, L_8003ED28
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_8003ED28;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // j           L_8003ED38
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    goto L_8003ED38;
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8003ED28:
    // bgez        $v0, L_8003ED38
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003ED38;
    }
    // nop

    // addu        $s1, $t2, $zero
    ctx->r17 = ADD32(ctx->r10, 0);
    // negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
L_8003ED38:
    // lh          $v1, 0x52($s0)
    ctx->r3 = MEM_H(0X52, ctx->r16);
    // nop

    // slti        $v0, $v1, 0xB
    ctx->r2 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // bne         $v0, $zero, L_8003ED60
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0xA
        ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
        goto L_8003ED60;
    }
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003ED78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003ED78;
    }
    // nop

    // j           L_8003ED78
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    goto L_8003ED78;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
L_8003ED60:
    // beq         $v0, $zero, L_8003ED78
    if (ctx->r2 == 0) {
        // negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
        goto L_8003ED78;
    }
    // negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003ED78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003ED78;
    }
    // nop

    // addu        $s1, $t1, $zero
    ctx->r17 = ADD32(ctx->r9, 0);
L_8003ED78:
    // lbu         $v1, 0xC($s0)
    ctx->r3 = MEM_BU(0XC, ctx->r16);
    // nop

    // bne         $v1, $a0, L_8003EDB8
    if (ctx->r3 != ctx->r4) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003EDB8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8003D824
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8003D824(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003D8B4
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003D8B4(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // beq         $v0, $zero, L_8003EE98
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003EE98;
    }
    // nop

    // jal         0x8003C27C
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    sub_8003C27C(rdram, ctx);
    goto after_2;
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_2:
    // j           L_8003EE98
    // nop

    goto L_8003EE98;
    // nop

L_8003EDB8:
    // bne         $v1, $t2, L_8003EDE4
    if (ctx->r3 != ctx->r10) {
        // nop
    
        goto L_8003EDE4;
    }
    // nop

    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003EE58
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003EE58;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // beq         $s1, $v1, L_8003EE98
    if (ctx->r17 == ctx->r3) {
        // sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5) << 16;
        goto L_8003EE98;
    }
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // j           L_8003EE74
    // nop

    goto L_8003EE74;
    // nop

L_8003EDE4:
    // bne         $v1, $a2, L_8003EE10
    if (ctx->r3 != ctx->r6) {
        // nop
    
        goto L_8003EE10;
    }
    // nop

    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003EE58
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003EE58;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // beq         $s1, $v1, L_8003EE98
    if (ctx->r17 == ctx->r3) {
        // sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5) << 16;
        goto L_8003EE98;
    }
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // j           L_8003EE74
    // nop

    goto L_8003EE74;
    // nop

L_8003EE10:
    // bne         $v1, $a3, L_8003EE3C
    if (ctx->r3 != ctx->r7) {
        // nop
    
        goto L_8003EE3C;
    }
    // nop

    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003EE58
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003EE58;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // beq         $s1, $v1, L_8003EE98
    if (ctx->r17 == ctx->r3) {
        // sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5) << 16;
        goto L_8003EE98;
    }
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // j           L_8003EE74
    // nop

    goto L_8003EE74;
    // nop

L_8003EE3C:
    // bne         $v1, $t1, L_8003EE98
    if (ctx->r3 != ctx->r9) {
        // nop
    
        goto L_8003EE98;
    }
    // nop

    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x800
    ctx->r2 = ctx->r2 < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_8003EE6C
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003EE6C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8003EE58:
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8003D858
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8003D858(rdram, ctx);
    goto after_3;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_3:
    // j           L_8003EE98
    // nop

    goto L_8003EE98;
    // nop

L_8003EE6C:
    // beq         $s1, $t1, L_8003EE98
    if (ctx->r17 == ctx->r9) {
        // sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5) << 16;
        goto L_8003EE98;
    }
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
L_8003EE74:
    // jal         0x8003D858
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8003D858(rdram, ctx);
    goto after_4;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_4:
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8003EE98
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003EE98;
    }
    // nop

    // jal         0x8003C250
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    sub_8003C250(rdram, ctx);
    goto after_5;
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_5:
L_8003EE98:
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
