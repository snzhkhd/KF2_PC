#include "recomp.h"
#include "disable_warnings.h"

void sub_8001E810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x4A
    ctx->r2 = 0 | 0X4A;
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
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
    // addiu       $at, $at, -0x643D
    ctx->r1 = ADD32(ctx->r1, -0X643D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6440
    ctx->r1 = ADD32(ctx->r1, -0X6440);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6439
    ctx->r1 = ADD32(ctx->r1, -0X6439);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x643C
    ctx->r1 = ADD32(ctx->r1, -0X643C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6435
    ctx->r1 = ADD32(ctx->r1, -0X6435);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6438
    ctx->r1 = ADD32(ctx->r1, -0X6438);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6431
    ctx->r1 = ADD32(ctx->r1, -0X6431);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a3, 0x0($at)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6434
    ctx->r1 = ADD32(ctx->r1, -0X6434);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a3, 0x0($at)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X0, ctx->r1);
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
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x642D
    ctx->r1 = ADD32(ctx->r1, -0X642D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6430
    ctx->r1 = ADD32(ctx->r1, -0X6430);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6429
    ctx->r1 = ADD32(ctx->r1, -0X6429);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x642C
    ctx->r1 = ADD32(ctx->r1, -0X642C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
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
