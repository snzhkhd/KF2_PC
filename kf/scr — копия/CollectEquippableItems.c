#include "recomp.h"
#include "disable_warnings.h"

void CollectEquippableItems(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x4A66
    ctx->r8 = ADD32(ctx->r8, -0X4A66);
    // lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(0X0, ctx->r8);
    // lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(0X14, ctx->r29);
    // lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(0X10, ctx->r29);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2) << 4;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5) << 6;
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x53D8
    ctx->r3 = ADD32(ctx->r3, -0X53D8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $t3, $a1, $v0
    ctx->r11 = ADD32(ctx->r5, ctx->r2);
    // addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // slt         $v0, $a2, $t5
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // beq         $v0, $zero, L_80019F8C
    if (ctx->r2 == 0) {
        // addu        $t1, $a0, $a2
        ctx->r9 = ADD32(ctx->r4, ctx->r6);
        goto L_80019F8C;
    }
    // addu        $t1, $a0, $a2
    ctx->r9 = ADD32(ctx->r4, ctx->r6);
    // addiu       $t0, $t0, -0x3B
    ctx->r8 = ADD32(ctx->r8, -0X3B);
L_80019E38:
    // lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(0X0, ctx->r9);
    // nop

    // beq         $v0, $zero, L_80019F78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019F78;
    }
    // nop

    // lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(0X0, ctx->r9);
    // nop

    // sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x25($t0)
    ctx->r2 = MEM_BU(0X25, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x26($t0)
    ctx->r2 = MEM_BU(0X26, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x27($t0)
    ctx->r2 = MEM_BU(0X27, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x28($t0)
    ctx->r2 = MEM_BU(0X28, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x29($t0)
    ctx->r2 = MEM_BU(0X29, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x2A($t0)
    ctx->r2 = MEM_BU(0X2A, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, 0x2B($t0)
    ctx->r2 = MEM_BU(0X2B, ctx->r8);
    // nop

    // beq         $a2, $v0, L_80019EE4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80019EE4;
    }
    // nop

    // lbu         $v0, -0x2($t0)
    ctx->r2 = MEM_BU(-0X2, ctx->r8);
    // nop

    // bne         $a2, $v0, L_80019EF4
    if (ctx->r6 != ctx->r2) {
        // nop
    
        goto L_80019EF4;
    }
    // nop

L_80019EE4:
    // lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(0X0, ctx->r10);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
L_80019EF4:
    // lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(0X0, ctx->r10);
    // nop

    // beq         $v0, $zero, L_80019F78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019F78;
    }
    // nop

    // lwl         $v0, 0x3($t3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r11);
    // lwr         $v0, 0x0($t3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r11);
    // lwl         $v1, 0x7($t3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r11);
    // lwr         $v1, 0x4($t3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r11);
    // lwl         $a0, 0xB($t3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r11);
    // lwr         $a0, 0x8($t3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r11);
    // lwl         $a1, 0xF($t3)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r11);
    // lwr         $a1, 0xC($t3)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r11);
    // swl         $v0, 0x3($t4)
    do_swl(rdram, 0X3, ctx->r12, ctx->r2);
    // swr         $v0, 0x0($t4)
    do_swr(rdram, 0X0, ctx->r12, ctx->r2);
    // swl         $v1, 0x7($t4)
    do_swl(rdram, 0X7, ctx->r12, ctx->r3);
    // swr         $v1, 0x4($t4)
    do_swr(rdram, 0X4, ctx->r12, ctx->r3);
    // swl         $a0, 0xB($t4)
    do_swl(rdram, 0XB, ctx->r12, ctx->r4);
    // swr         $a0, 0x8($t4)
    do_swr(rdram, 0X8, ctx->r12, ctx->r4);
    // swl         $a1, 0xF($t4)
    do_swl(rdram, 0XF, ctx->r12, ctx->r5);
    // swr         $a1, 0xC($t4)
    do_swr(rdram, 0XC, ctx->r12, ctx->r5);
    // lwl         $v0, 0x13($t3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r11);
    // lwr         $v0, 0x10($t3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r11);
    // lwl         $v1, 0x17($t3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X17, ctx->r11);
    // lwr         $v1, 0x14($t3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X14, ctx->r11);
    // swl         $v0, 0x13($t4)
    do_swl(rdram, 0X13, ctx->r12, ctx->r2);
    // swr         $v0, 0x10($t4)
    do_swr(rdram, 0X10, ctx->r12, ctx->r2);
    // swl         $v1, 0x17($t4)
    do_swl(rdram, 0X17, ctx->r12, ctx->r3);
    // swr         $v1, 0x14($t4)
    do_swr(rdram, 0X14, ctx->r12, ctx->r3);
    // sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // addiu       $t4, $t4, 0x18
    ctx->r12 = ADD32(ctx->r12, 0X18);
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
L_80019F78:
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $a2, $t5
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // bne         $v0, $zero, L_80019E38
    if (ctx->r2 != 0) {
        // addiu       $t3, $t3, 0x18
        ctx->r11 = ADD32(ctx->r11, 0X18);
        goto L_80019E38;
    }
    // addiu       $t3, $t3, 0x18
    ctx->r11 = ADD32(ctx->r11, 0X18);
L_80019F8C:
    // jr          $ra
    // addu        $v0, $t6, $zero
    ctx->r2 = ADD32(ctx->r14, 0);
    return;
    // addu        $v0, $t6, $zero
    ctx->r2 = ADD32(ctx->r14, 0);
;}
