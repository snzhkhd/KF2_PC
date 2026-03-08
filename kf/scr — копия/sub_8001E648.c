#include "recomp.h"
#include "disable_warnings.h"

void sub_8001E648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $a3, $zero, 0x4A
    ctx->r7 = 0 | 0X4A;
    // ori         $v0, $zero, 0x62
    ctx->r2 = 0 | 0X62;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x4A66
    ctx->r6 = ADD32(ctx->r6, -0X4A66);
    // sh          $a3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r7;
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(0X0, ctx->r6);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x6380
    ctx->r5 = ADD32(ctx->r5, -0X6380);
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
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $t0, 0x7($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X7, ctx->r2);
    // lwr         $t0, 0x4($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X4, ctx->r2);
    // lwl         $t1, 0xB($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0XB, ctx->r2);
    // lwr         $t1, 0x8($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0X8, ctx->r2);
    // lwl         $t2, 0xF($v0)
    ctx->r10 = do_lwl(rdram, ctx->r10, 0XF, ctx->r2);
    // lwr         $t2, 0xC($v0)
    ctx->r10 = do_lwr(rdram, ctx->r10, 0XC, ctx->r2);
    // swl         $v1, 0x7($a0)
    do_swl(rdram, 0X7, ctx->r4, ctx->r3);
    // swr         $v1, 0x4($a0)
    do_swr(rdram, 0X4, ctx->r4, ctx->r3);
    // swl         $t0, 0xB($a0)
    do_swl(rdram, 0XB, ctx->r4, ctx->r8);
    // swr         $t0, 0x8($a0)
    do_swr(rdram, 0X8, ctx->r4, ctx->r8);
    // swl         $t1, 0xF($a0)
    do_swl(rdram, 0XF, ctx->r4, ctx->r9);
    // swr         $t1, 0xC($a0)
    do_swr(rdram, 0XC, ctx->r4, ctx->r9);
    // swl         $t2, 0x13($a0)
    do_swl(rdram, 0X13, ctx->r4, ctx->r10);
    // swr         $t2, 0x10($a0)
    do_swr(rdram, 0X10, ctx->r4, ctx->r10);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $t0, 0x17($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X17, ctx->r2);
    // lwr         $t0, 0x14($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X14, ctx->r2);
    // swl         $v1, 0x17($a0)
    do_swl(rdram, 0X17, ctx->r4, ctx->r3);
    // swr         $v1, 0x14($a0)
    do_swr(rdram, 0X14, ctx->r4, ctx->r3);
    // swl         $t0, 0x1B($a0)
    do_swl(rdram, 0X1B, ctx->r4, ctx->r8);
    // swr         $t0, 0x18($a0)
    do_swr(rdram, 0X18, ctx->r4, ctx->r8);
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // ori         $v0, $zero, 0x71
    ctx->r2 = 0 | 0X71;
    // sh          $a3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r7;
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(0X0, ctx->r6);
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
    // addiu       $v1, $a1, 0x18
    ctx->r3 = ADD32(ctx->r5, 0X18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $t0, 0x7($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X7, ctx->r2);
    // lwr         $t0, 0x4($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X4, ctx->r2);
    // lwl         $t1, 0xB($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0XB, ctx->r2);
    // lwr         $t1, 0x8($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0X8, ctx->r2);
    // lwl         $t2, 0xF($v0)
    ctx->r10 = do_lwl(rdram, ctx->r10, 0XF, ctx->r2);
    // lwr         $t2, 0xC($v0)
    ctx->r10 = do_lwr(rdram, ctx->r10, 0XC, ctx->r2);
    // swl         $v1, 0x7($a0)
    do_swl(rdram, 0X7, ctx->r4, ctx->r3);
    // swr         $v1, 0x4($a0)
    do_swr(rdram, 0X4, ctx->r4, ctx->r3);
    // swl         $t0, 0xB($a0)
    do_swl(rdram, 0XB, ctx->r4, ctx->r8);
    // swr         $t0, 0x8($a0)
    do_swr(rdram, 0X8, ctx->r4, ctx->r8);
    // swl         $t1, 0xF($a0)
    do_swl(rdram, 0XF, ctx->r4, ctx->r9);
    // swr         $t1, 0xC($a0)
    do_swr(rdram, 0XC, ctx->r4, ctx->r9);
    // swl         $t2, 0x13($a0)
    do_swl(rdram, 0X13, ctx->r4, ctx->r10);
    // swr         $t2, 0x10($a0)
    do_swr(rdram, 0X10, ctx->r4, ctx->r10);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $t0, 0x17($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X17, ctx->r2);
    // lwr         $t0, 0x14($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X14, ctx->r2);
    // swl         $v1, 0x17($a0)
    do_swl(rdram, 0X17, ctx->r4, ctx->r3);
    // swr         $v1, 0x14($a0)
    do_swr(rdram, 0X14, ctx->r4, ctx->r3);
    // swl         $t0, 0x1B($a0)
    do_swl(rdram, 0X1B, ctx->r4, ctx->r8);
    // swr         $t0, 0x18($a0)
    do_swr(rdram, 0X18, ctx->r4, ctx->r8);
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sh          $a3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r7;
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(0X0, ctx->r6);
    // addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
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
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a1, 0x7($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r2);
    // lwr         $a1, 0x4($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r2);
    // lwl         $a2, 0xB($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XB, ctx->r2);
    // lwr         $a2, 0x8($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X8, ctx->r2);
    // lwl         $a3, 0xF($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XF, ctx->r2);
    // lwr         $a3, 0xC($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0XC, ctx->r2);
    // swl         $v1, 0x7($a0)
    do_swl(rdram, 0X7, ctx->r4, ctx->r3);
    // swr         $v1, 0x4($a0)
    do_swr(rdram, 0X4, ctx->r4, ctx->r3);
    // swl         $a1, 0xB($a0)
    do_swl(rdram, 0XB, ctx->r4, ctx->r5);
    // swr         $a1, 0x8($a0)
    do_swr(rdram, 0X8, ctx->r4, ctx->r5);
    // swl         $a2, 0xF($a0)
    do_swl(rdram, 0XF, ctx->r4, ctx->r6);
    // swr         $a2, 0xC($a0)
    do_swr(rdram, 0XC, ctx->r4, ctx->r6);
    // swl         $a3, 0x13($a0)
    do_swl(rdram, 0X13, ctx->r4, ctx->r7);
    // swr         $a3, 0x10($a0)
    do_swr(rdram, 0X10, ctx->r4, ctx->r7);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a1, 0x17($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r2);
    // lwr         $a1, 0x14($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r2);
    // swl         $v1, 0x17($a0)
    do_swl(rdram, 0X17, ctx->r4, ctx->r3);
    // swr         $v1, 0x14($a0)
    do_swr(rdram, 0X14, ctx->r4, ctx->r3);
    // swl         $a1, 0x1B($a0)
    do_swl(rdram, 0X1B, ctx->r4, ctx->r5);
    // swr         $a1, 0x18($a0)
    do_swr(rdram, 0X18, ctx->r4, ctx->r5);
    // jr          $ra
    // nop

    return;
    // nop

;}
