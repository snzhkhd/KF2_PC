#include "recomp.h"
#include "disable_warnings.h"

void sub_8001EA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // ori         $v0, $zero, 0x4A
    ctx->r2 = 0 | 0X4A;
    // sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
    // ori         $v0, $zero, 0x62
    ctx->r2 = 0 | 0X62;
    // sh          $v0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a1, $v0, L_8001EB98
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_8001EB98;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // nop

    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6455
    ctx->r1 = ADD32(ctx->r1, -0X6455);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6458
    ctx->r1 = ADD32(ctx->r1, -0X6458);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6451
    ctx->r1 = ADD32(ctx->r1, -0X6451);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6454
    ctx->r1 = ADD32(ctx->r1, -0X6454);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x644D
    ctx->r1 = ADD32(ctx->r1, -0X644D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6450
    ctx->r1 = ADD32(ctx->r1, -0X6450);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6449
    ctx->r1 = ADD32(ctx->r1, -0X6449);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x644C
    ctx->r1 = ADD32(ctx->r1, -0X644C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // swl         $v1, 0x7($t2)
    do_swl(rdram, 0X7, ctx->r10, ctx->r3);
    // swr         $v1, 0x4($t2)
    do_swr(rdram, 0X4, ctx->r10, ctx->r3);
    // swl         $a0, 0xB($t2)
    do_swl(rdram, 0XB, ctx->r10, ctx->r4);
    // swr         $a0, 0x8($t2)
    do_swr(rdram, 0X8, ctx->r10, ctx->r4);
    // swl         $a1, 0xF($t2)
    do_swl(rdram, 0XF, ctx->r10, ctx->r5);
    // swr         $a1, 0xC($t2)
    do_swr(rdram, 0XC, ctx->r10, ctx->r5);
    // swl         $a2, 0x13($t2)
    do_swl(rdram, 0X13, ctx->r10, ctx->r6);
    // swr         $a2, 0x10($t2)
    do_swr(rdram, 0X10, ctx->r10, ctx->r6);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6445
    ctx->r1 = ADD32(ctx->r1, -0X6445);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6448
    ctx->r1 = ADD32(ctx->r1, -0X6448);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6441
    ctx->r1 = ADD32(ctx->r1, -0X6441);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6444
    ctx->r1 = ADD32(ctx->r1, -0X6444);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // swl         $v1, 0x17($t2)
    do_swl(rdram, 0X17, ctx->r10, ctx->r3);
    // swr         $v1, 0x14($t2)
    do_swr(rdram, 0X14, ctx->r10, ctx->r3);
    // swl         $a0, 0x1B($t2)
    do_swl(rdram, 0X1B, ctx->r10, ctx->r4);
    // swr         $a0, 0x18($t2)
    do_swr(rdram, 0X18, ctx->r10, ctx->r4);
    // j           L_8001ECAC
    // addiu       $t2, $t2, 0x1C
    ctx->r10 = ADD32(ctx->r10, 0X1C);
    goto L_8001ECAC;
    // addiu       $t2, $t2, 0x1C
    ctx->r10 = ADD32(ctx->r10, 0X1C);
L_8001EB98:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // nop

    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63C5
    ctx->r1 = ADD32(ctx->r1, -0X63C5);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63C8
    ctx->r1 = ADD32(ctx->r1, -0X63C8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63C1
    ctx->r1 = ADD32(ctx->r1, -0X63C1);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63C4
    ctx->r1 = ADD32(ctx->r1, -0X63C4);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63BD
    ctx->r1 = ADD32(ctx->r1, -0X63BD);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63C0
    ctx->r1 = ADD32(ctx->r1, -0X63C0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63B9
    ctx->r1 = ADD32(ctx->r1, -0X63B9);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63BC
    ctx->r1 = ADD32(ctx->r1, -0X63BC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // swl         $v1, 0x7($t2)
    do_swl(rdram, 0X7, ctx->r10, ctx->r3);
    // swr         $v1, 0x4($t2)
    do_swr(rdram, 0X4, ctx->r10, ctx->r3);
    // swl         $a0, 0xB($t2)
    do_swl(rdram, 0XB, ctx->r10, ctx->r4);
    // swr         $a0, 0x8($t2)
    do_swr(rdram, 0X8, ctx->r10, ctx->r4);
    // swl         $a1, 0xF($t2)
    do_swl(rdram, 0XF, ctx->r10, ctx->r5);
    // swr         $a1, 0xC($t2)
    do_swr(rdram, 0XC, ctx->r10, ctx->r5);
    // swl         $a2, 0x13($t2)
    do_swl(rdram, 0X13, ctx->r10, ctx->r6);
    // swr         $a2, 0x10($t2)
    do_swr(rdram, 0X10, ctx->r10, ctx->r6);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63B5
    ctx->r1 = ADD32(ctx->r1, -0X63B5);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63B8
    ctx->r1 = ADD32(ctx->r1, -0X63B8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63B1
    ctx->r1 = ADD32(ctx->r1, -0X63B1);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x63B4
    ctx->r1 = ADD32(ctx->r1, -0X63B4);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // swl         $v1, 0x17($t2)
    do_swl(rdram, 0X17, ctx->r10, ctx->r3);
    // swr         $v1, 0x14($t2)
    do_swr(rdram, 0X14, ctx->r10, ctx->r3);
    // swl         $a0, 0x1B($t2)
    do_swl(rdram, 0X1B, ctx->r10, ctx->r4);
    // swr         $a0, 0x18($t2)
    do_swr(rdram, 0X18, ctx->r10, ctx->r4);
    // addiu       $t2, $t2, 0x1C
    ctx->r10 = ADD32(ctx->r10, 0X1C);
L_8001ECAC:
    // ori         $a2, $zero, 0x4A
    ctx->r6 = 0 | 0X4A;
    // ori         $v0, $zero, 0x71
    ctx->r2 = 0 | 0X71;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A66
    ctx->r5 = ADD32(ctx->r5, -0X4A66);
    // sh          $a2, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r6;
    // sh          $v0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r2;
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(0X0, ctx->r5);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x6500
    ctx->r4 = ADD32(ctx->r4, -0X6500);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a3, 0x7($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X7, ctx->r2);
    // lwr         $a3, 0x4($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X4, ctx->r2);
    // lwl         $t0, 0xB($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XB, ctx->r2);
    // lwr         $t0, 0x8($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X8, ctx->r2);
    // lwl         $t1, 0xF($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0XF, ctx->r2);
    // lwr         $t1, 0xC($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0XC, ctx->r2);
    // swl         $v1, 0x7($t2)
    do_swl(rdram, 0X7, ctx->r10, ctx->r3);
    // swr         $v1, 0x4($t2)
    do_swr(rdram, 0X4, ctx->r10, ctx->r3);
    // swl         $a3, 0xB($t2)
    do_swl(rdram, 0XB, ctx->r10, ctx->r7);
    // swr         $a3, 0x8($t2)
    do_swr(rdram, 0X8, ctx->r10, ctx->r7);
    // swl         $t0, 0xF($t2)
    do_swl(rdram, 0XF, ctx->r10, ctx->r8);
    // swr         $t0, 0xC($t2)
    do_swr(rdram, 0XC, ctx->r10, ctx->r8);
    // swl         $t1, 0x13($t2)
    do_swl(rdram, 0X13, ctx->r10, ctx->r9);
    // swr         $t1, 0x10($t2)
    do_swr(rdram, 0X10, ctx->r10, ctx->r9);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a3, 0x17($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X17, ctx->r2);
    // lwr         $a3, 0x14($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X14, ctx->r2);
    // swl         $v1, 0x17($t2)
    do_swl(rdram, 0X17, ctx->r10, ctx->r3);
    // swr         $v1, 0x14($t2)
    do_swr(rdram, 0X14, ctx->r10, ctx->r3);
    // swl         $a3, 0x1B($t2)
    do_swl(rdram, 0X1B, ctx->r10, ctx->r7);
    // swr         $a3, 0x18($t2)
    do_swr(rdram, 0X18, ctx->r10, ctx->r7);
    // addiu       $t2, $t2, 0x1C
    ctx->r10 = ADD32(ctx->r10, 0X1C);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sh          $a2, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r6;
    // sh          $v0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r2;
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(0X0, ctx->r5);
    // addiu       $a0, $a0, -0x198
    ctx->r4 = ADD32(ctx->r4, -0X198);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // lwl         $a1, 0xB($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r2);
    // lwr         $a1, 0x8($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r2);
    // lwl         $a2, 0xF($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XF, ctx->r2);
    // lwr         $a2, 0xC($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0XC, ctx->r2);
    // swl         $v1, 0x7($t2)
    do_swl(rdram, 0X7, ctx->r10, ctx->r3);
    // swr         $v1, 0x4($t2)
    do_swr(rdram, 0X4, ctx->r10, ctx->r3);
    // swl         $a0, 0xB($t2)
    do_swl(rdram, 0XB, ctx->r10, ctx->r4);
    // swr         $a0, 0x8($t2)
    do_swr(rdram, 0X8, ctx->r10, ctx->r4);
    // swl         $a1, 0xF($t2)
    do_swl(rdram, 0XF, ctx->r10, ctx->r5);
    // swr         $a1, 0xC($t2)
    do_swr(rdram, 0XC, ctx->r10, ctx->r5);
    // swl         $a2, 0x13($t2)
    do_swl(rdram, 0X13, ctx->r10, ctx->r6);
    // swr         $a2, 0x10($t2)
    do_swr(rdram, 0X10, ctx->r10, ctx->r6);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x17($t2)
    do_swl(rdram, 0X17, ctx->r10, ctx->r3);
    // swr         $v1, 0x14($t2)
    do_swr(rdram, 0X14, ctx->r10, ctx->r3);
    // swl         $a0, 0x1B($t2)
    do_swl(rdram, 0X1B, ctx->r10, ctx->r4);
    // swr         $a0, 0x18($t2)
    do_swr(rdram, 0X18, ctx->r10, ctx->r4);
    // jr          $ra
    // nop

    return;
    // nop

;}
