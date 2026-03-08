#include "recomp.h"
#include "disable_warnings.h"

void sub_8001DCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // sw          $s5, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // addiu       $t1, $t1, -0x4A66
    ctx->r9 = ADD32(ctx->r9, -0X4A66);
    // sw          $ra, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r31;
    // sw          $fp, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r30;
    // sw          $s7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r22;
    // sw          $s4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r20;
    // sw          $s3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r19;
    // sw          $s2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r18;
    // sw          $s1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r17;
    // sw          $s0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r16;
    // lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(0X0, ctx->r9);
    // addiu       $v1, $zero, -0x63
    ctx->r3 = ADD32(0, -0X63);
    // sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7CE8
    ctx->r1 = ADD32(ctx->r1, 0X7CE8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $a1, 0x0($at)
    ctx->r5 = MEM_HU(0X0, ctx->r1);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x6290
    ctx->r8 = ADD32(ctx->r8, -0X6290);
    // sw          $v1, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r3;
    // sh          $a1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r5;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7CEA
    ctx->r1 = ADD32(ctx->r1, 0X7CEA);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(0X0, ctx->r9);
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
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r5);
    // swr         $a1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r5);
    // swl         $a2, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r6);
    // swr         $a2, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r6);
    // swl         $a3, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r7);
    // swr         $a3, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r7);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a1, 0x17($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r2);
    // lwr         $a1, 0x14($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r5);
    // swr         $a1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r5);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7D04
    ctx->r1 = ADD32(ctx->r1, 0X7D04);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    // sh          $v1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r3;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7D06
    ctx->r1 = ADD32(ctx->r1, 0X7D06);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $t0, 0x18
    ctx->r3 = ADD32(ctx->r8, 0X18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
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
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // swl         $a1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r5);
    // swr         $a1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r5);
    // swl         $a2, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r6);
    // swr         $a2, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r6);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r3);
    // swr         $v1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r3);
    // swl         $a0, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r4);
    // swr         $a0, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r4);
    // bne         $s5, $s2, L_8001DFD0
    if (ctx->r21 != ctx->r18) {
        // addiu       $s7, $zero, -0x1
        ctx->r23 = ADD32(0, -0X1);
        goto L_8001DFD0;
    }
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // ori         $a1, $zero, 0x4A
    ctx->r5 = 0 | 0X4A;
    // sh          $a1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r5;
    // lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(0X0, ctx->r9);
    // ori         $v0, $zero, 0x6D
    ctx->r2 = 0 | 0X6D;
    // sh          $v0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r2;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $t0, -0x258
    ctx->r3 = ADD32(ctx->r8, -0X258);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // lwl         $a2, 0xB($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XB, ctx->r2);
    // lwr         $a2, 0x8($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X8, ctx->r2);
    // lwl         $a3, 0xF($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XF, ctx->r2);
    // lwr         $a3, 0xC($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0XC, ctx->r2);
    // swl         $v1, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r3);
    // swr         $v1, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r3);
    // swl         $a0, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r4);
    // swr         $a0, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r4);
    // swl         $a2, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r6);
    // swr         $a2, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r6);
    // swl         $a3, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r7);
    // swr         $a3, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r7);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r3);
    // swr         $v1, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r3);
    // swl         $a0, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r4);
    // swr         $a0, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r4);
    // sh          $a1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r5;
    // lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(0X0, ctx->r9);
    // ori         $v0, $zero, 0x7C
    ctx->r2 = 0 | 0X7C;
    // sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $t0, -0x240
    ctx->r3 = ADD32(ctx->r8, -0X240);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
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
    // swl         $v1, 0x73($sp)
    do_swl(rdram, 0X73, ctx->r29, ctx->r3);
    // swr         $v1, 0x70($sp)
    do_swr(rdram, 0X70, ctx->r29, ctx->r3);
    // swl         $a0, 0x77($sp)
    do_swl(rdram, 0X77, ctx->r29, ctx->r4);
    // swr         $a0, 0x74($sp)
    do_swr(rdram, 0X74, ctx->r29, ctx->r4);
    // swl         $a1, 0x7B($sp)
    do_swl(rdram, 0X7B, ctx->r29, ctx->r5);
    // swr         $a1, 0x78($sp)
    do_swr(rdram, 0X78, ctx->r29, ctx->r5);
    // swl         $a2, 0x7F($sp)
    do_swl(rdram, 0X7F, ctx->r29, ctx->r6);
    // swr         $a2, 0x7C($sp)
    do_swr(rdram, 0X7C, ctx->r29, ctx->r6);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x83($sp)
    do_swl(rdram, 0X83, ctx->r29, ctx->r3);
    // swr         $v1, 0x80($sp)
    do_swr(rdram, 0X80, ctx->r29, ctx->r3);
    // swl         $a0, 0x87($sp)
    do_swl(rdram, 0X87, ctx->r29, ctx->r4);
    // swr         $a0, 0x84($sp)
    do_swr(rdram, 0X84, ctx->r29, ctx->r4);
L_8001DFD0:
    // addiu       $s6, $zero, -0x63
    ctx->r22 = ADD32(0, -0X63);
    // lui         $fp, 0x8006
    ctx->r30 = S32(0X8006 << 16);
    // addiu       $fp, $fp, 0x7AE4
    ctx->r30 = ADD32(ctx->r30, 0X7AE4);
    // addu        $s4, $t1, $zero
    ctx->r20 = ADD32(ctx->r9, 0);
    // lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // addiu       $s3, $s3, 0x7CCC
    ctx->r19 = ADD32(ctx->r19, 0X7CCC);
L_8001DFE8:
    // lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(0XE0, ctx->r29);
    // nop

    // bne         $v0, $s7, L_8001E008
    if (ctx->r2 != ctx->r23) {
        // nop
    
        goto L_8001E008;
    }
    // nop

    // lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(0XE8, ctx->r29);
    // nop

    // beq         $v0, $s6, L_8001E010
    if (ctx->r2 == ctx->r22) {
        // nop
    
        goto L_8001E010;
    }
    // nop

L_8001E008:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8001E010:
    // lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(0XE0, ctx->r29);
    // nop

    // beq         $v1, $zero, L_8001E030
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001E030;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8001E038
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001E038;
    }
    // nop

    // j           L_8001E03C
    // nop

    goto L_8001E03C;
    // nop

L_8001E030:
    // j           L_8001E03C
    // sw          $zero, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = 0;
    goto L_8001E03C;
    // sw          $zero, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = 0;
L_8001E038:
    // sw          $s7, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r23;
L_8001E03C:
    // lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(0XE8, ctx->r29);
    // nop

    // bne         $v0, $s6, L_8001E14C
    if (ctx->r2 != ctx->r22) {
        // addiu       $v0, $sp, 0xE8
        ctx->r2 = ADD32(ctx->r29, 0XE8);
        goto L_8001E14C;
    }
    // addiu       $v0, $sp, 0xE8
    ctx->r2 = ADD32(ctx->r29, 0XE8);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // jal         0x80020420
    // addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    MenuInputProcess(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0xE4
    ctx->r7 = ADD32(ctx->r29, 0XE4);
    after_1:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $s1, 0x8006
    ctx->r17 = S32(0X8006 << 16);
    // addiu       $s1, $s1, 0x7AB4
    ctx->r17 = ADD32(ctx->r17, 0X7AB4);
L_8001E074:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // lw          $a3, 0xE4($sp)
    ctx->r7 = MEM_W(0XE4, ctx->r29);
    // jal         0x80023294
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    ApplyViewTransforms(rdram, ctx);
    goto after_3;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(0X0, ctx->r20);
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) << 5;
    // addu        $a1, $a1, $s3
    ctx->r5 = ADD32(ctx->r5, ctx->r19);
    // jal         0x80023944
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    ui_DrawFrame(rdram, ctx);
    goto after_4;
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    after_4:
    // lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(0X0, ctx->r20);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) << 5;
    // addu        $a1, $a1, $s3
    ctx->r5 = ADD32(ctx->r5, ctx->r19);
    // jal         0x80023E20
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    ui_DrawText(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    after_5:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s5, $v0, L_8001E130
    if (ctx->r21 != ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8001E130;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    ui_DrawText(rdram, ctx);
    goto after_6;
    // addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_6:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    ui_DrawText(rdram, ctx);
    goto after_7;
    // addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_7:
    // ori         $a0, $zero, 0x38
    ctx->r4 = 0 | 0X38;
    // ori         $a1, $zero, 0x5B
    ctx->r5 = 0 | 0X5B;
    // ori         $a2, $zero, 0xCE
    ctx->r6 = 0 | 0XCE;
    // ori         $a3, $zero, 0x42
    ctx->r7 = 0 | 0X42;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80024298
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    DrawTextureNPatch(rdram, ctx);
    goto after_8;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
L_8001E130:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_9;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_9:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001E074
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001E074;
    }
    // nop

    // j           L_8001DFE8
    // nop

    goto L_8001DFE8;
    // nop

L_8001E14C:
    // lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(0XE8, ctx->r29);
    // lw          $ra, 0x114($sp)
    ctx->r31 = MEM_W(0X114, ctx->r29);
    // lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(0X110, ctx->r29);
    // lw          $s7, 0x10C($sp)
    ctx->r23 = MEM_W(0X10C, ctx->r29);
    // lw          $s6, 0x108($sp)
    ctx->r22 = MEM_W(0X108, ctx->r29);
    // lw          $s5, 0x104($sp)
    ctx->r21 = MEM_W(0X104, ctx->r29);
    // lw          $s4, 0x100($sp)
    ctx->r20 = MEM_W(0X100, ctx->r29);
    // lw          $s3, 0xFC($sp)
    ctx->r19 = MEM_W(0XFC, ctx->r29);
    // lw          $s2, 0xF8($sp)
    ctx->r18 = MEM_W(0XF8, ctx->r29);
    // lw          $s1, 0xF4($sp)
    ctx->r17 = MEM_W(0XF4, ctx->r29);
    // lw          $s0, 0xF0($sp)
    ctx->r16 = MEM_W(0XF0, ctx->r29);
    // addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // jr          $ra
    // nop

    return;
    // nop

;}
