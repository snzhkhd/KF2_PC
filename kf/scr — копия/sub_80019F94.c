#include "recomp.h"
#include "disable_warnings.h"

void sub_80019F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
    // addu        $t4, $a2, $zero
    ctx->r12 = ADD32(ctx->r6, 0);
    // addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A66($v1)
    ctx->r3 = MEM_H(-0X4A66, ctx->r3);
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
    // sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6) << 1;
    // addu        $v0, $t1, $a2
    ctx->r2 = ADD32(ctx->r9, ctx->r6);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x53D8
    ctx->r3 = ADD32(ctx->r3, -0X53D8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $t2, $a1, $v0
    ctx->r10 = ADD32(ctx->r5, ctx->r2);
    // addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // slt         $v0, $a2, $t5
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // beq         $v0, $zero, L_8001A0B4
    if (ctx->r2 == 0) {
        // addu        $t0, $a0, $a2
        ctx->r8 = ADD32(ctx->r4, ctx->r6);
        goto L_8001A0B4;
    }
    // addu        $t0, $a0, $a2
    ctx->r8 = ADD32(ctx->r4, ctx->r6);
    // ori         $t7, $zero, 0xC350
    ctx->r15 = 0 | 0XC350;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x2048
    ctx->r2 = ADD32(ctx->r2, -0X2048);
    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
L_8001A000:
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // nop

    // beq         $v0, $zero, L_8001A09C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001A09C;
    }
    // nop

    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // beq         $v0, $t7, L_8001A09C
    if (ctx->r2 == ctx->r15) {
        // nop
    
        goto L_8001A09C;
    }
    // nop

    // lwl         $v0, 0x3($t2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r10);
    // lwr         $v0, 0x0($t2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r10);
    // lwl         $v1, 0x7($t2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r10);
    // lwr         $v1, 0x4($t2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r10);
    // lwl         $a0, 0xB($t2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r10);
    // lwr         $a0, 0x8($t2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r10);
    // lwl         $a1, 0xF($t2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r10);
    // lwr         $a1, 0xC($t2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r10);
    // swl         $v0, 0x3($t3)
    do_swl(rdram, 0X3, ctx->r11, ctx->r2);
    // swr         $v0, 0x0($t3)
    do_swr(rdram, 0X0, ctx->r11, ctx->r2);
    // swl         $v1, 0x7($t3)
    do_swl(rdram, 0X7, ctx->r11, ctx->r3);
    // swr         $v1, 0x4($t3)
    do_swr(rdram, 0X4, ctx->r11, ctx->r3);
    // swl         $a0, 0xB($t3)
    do_swl(rdram, 0XB, ctx->r11, ctx->r4);
    // swr         $a0, 0x8($t3)
    do_swr(rdram, 0X8, ctx->r11, ctx->r4);
    // swl         $a1, 0xF($t3)
    do_swl(rdram, 0XF, ctx->r11, ctx->r5);
    // swr         $a1, 0xC($t3)
    do_swr(rdram, 0XC, ctx->r11, ctx->r5);
    // lwl         $v0, 0x13($t2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r10);
    // lwr         $v0, 0x10($t2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r10);
    // lwl         $v1, 0x17($t2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X17, ctx->r10);
    // lwr         $v1, 0x14($t2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X14, ctx->r10);
    // swl         $v0, 0x13($t3)
    do_swl(rdram, 0X13, ctx->r11, ctx->r2);
    // swr         $v0, 0x10($t3)
    do_swr(rdram, 0X10, ctx->r11, ctx->r2);
    // swl         $v1, 0x17($t3)
    do_swl(rdram, 0X17, ctx->r11, ctx->r3);
    // swr         $v1, 0x14($t3)
    do_swr(rdram, 0X14, ctx->r11, ctx->r3);
    // addiu       $t3, $t3, 0x18
    ctx->r11 = ADD32(ctx->r11, 0X18);
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // sb          $v0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r2;
    // addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8001A09C:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // addiu       $t2, $t2, 0x18
    ctx->r10 = ADD32(ctx->r10, 0X18);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $a2, $t5
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // bne         $v0, $zero, L_8001A000
    if (ctx->r2 != 0) {
        // addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_8001A000;
    }
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_8001A0B4:
    // jr          $ra
    // addu        $v0, $t6, $zero
    ctx->r2 = ADD32(ctx->r14, 0);
    return;
    // addu        $v0, $t6, $zero
    ctx->r2 = ADD32(ctx->r14, 0);
;}
