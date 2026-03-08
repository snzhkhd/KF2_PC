#include "recomp.h"
#include "disable_warnings.h"

void CollectAvailableSpells(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
    // addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x3218
    ctx->r5 = ADD32(ctx->r5, -0X3218);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(0X14, ctx->r29);
    // lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(0X10, ctx->r29);
    // sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2) << 4;
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6) << 5;
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // slt         $v0, $a3, $t4
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r12) ? 1 : 0;
    // beq         $v0, $zero, L_8001AAEC
    if (ctx->r2 == 0) {
        // addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
        goto L_8001AAEC;
    }
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // ori         $t6, $zero, 0x1
    ctx->r14 = 0 | 0X1;
L_8001AA4C:
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // nop

    // bne         $v0, $t6, L_8001AAD8
    if (ctx->r2 != ctx->r14) {
        // nop
    
        goto L_8001AAD8;
    }
    // nop

    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($t1)
    do_swl(rdram, 0X3, ctx->r9, ctx->r2);
    // swr         $v0, 0x0($t1)
    do_swr(rdram, 0X0, ctx->r9, ctx->r2);
    // swl         $v1, 0x7($t1)
    do_swl(rdram, 0X7, ctx->r9, ctx->r3);
    // swr         $v1, 0x4($t1)
    do_swr(rdram, 0X4, ctx->r9, ctx->r3);
    // swl         $a0, 0xB($t1)
    do_swl(rdram, 0XB, ctx->r9, ctx->r4);
    // swr         $a0, 0x8($t1)
    do_swr(rdram, 0X8, ctx->r9, ctx->r4);
    // swl         $a1, 0xF($t1)
    do_swl(rdram, 0XF, ctx->r9, ctx->r5);
    // swr         $a1, 0xC($t1)
    do_swr(rdram, 0XC, ctx->r9, ctx->r5);
    // lwl         $v0, 0x13($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r6);
    // lwr         $v0, 0x10($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r6);
    // lwl         $v1, 0x17($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X17, ctx->r6);
    // lwr         $v1, 0x14($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X14, ctx->r6);
    // swl         $v0, 0x13($t1)
    do_swl(rdram, 0X13, ctx->r9, ctx->r2);
    // swr         $v0, 0x10($t1)
    do_swr(rdram, 0X10, ctx->r9, ctx->r2);
    // swl         $v1, 0x17($t1)
    do_swl(rdram, 0X17, ctx->r9, ctx->r3);
    // swr         $v1, 0x14($t1)
    do_swr(rdram, 0X14, ctx->r9, ctx->r3);
    // addiu       $t1, $t1, 0x18
    ctx->r9 = ADD32(ctx->r9, 0X18);
    // lhu         $v0, 0x16($t0)
    ctx->r2 = MEM_HU(0X16, ctx->r8);
    // addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // sb          $a3, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r7;
    // addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_8001AAD8:
    // addiu       $t0, $t0, 0x1A
    ctx->r8 = ADD32(ctx->r8, 0X1A);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slt         $v0, $a3, $t4
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r12) ? 1 : 0;
    // bne         $v0, $zero, L_8001AA4C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
        goto L_8001AA4C;
    }
    // addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
L_8001AAEC:
    // jr          $ra
    // addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
    return;
    // addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
;}
