#include "recomp.h"
#include "disable_warnings.h"

void sub_800213E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7AB4
    ctx->r16 = ADD32(ctx->r16, 0X7AB4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4A66
    ctx->r17 = ADD32(ctx->r17, -0X4A66);
    // ori         $t0, $zero, 0x1C
    ctx->r8 = 0 | 0X1C;
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(0X0, ctx->r17);
    // lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // addiu       $s5, $s5, -0x6638
    ctx->r21 = ADD32(ctx->r21, -0X6638);
    // sh          $t0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r8;
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
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $fp, $s5, 0x330
    ctx->r30 = ADD32(ctx->r21, 0X330);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B0C($a0)
    ctx->r4 = MEM_HU(-0X4B0C, ctx->r4);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_2;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // addiu       $s3, $s0, -0xC
    ctx->r19 = ADD32(ctx->r16, -0XC);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_3;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s6, $s5, 0x348
    ctx->r22 = ADD32(ctx->r21, 0X348);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_4;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_4:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B0A($a0)
    ctx->r4 = MEM_HU(-0X4B0A, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_5;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_6;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_6:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s7, $s5, 0x360
    ctx->r23 = ADD32(ctx->r21, 0X360);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_7;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_7:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B08($a0)
    ctx->r4 = MEM_HU(-0X4B08, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_8;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_9;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_9:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $s5, 0x450
    ctx->r3 = ADD32(ctx->r21, 0X450);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_10;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_10:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B06($a0)
    ctx->r4 = MEM_HU(-0X4B06, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_11;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_11:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_12;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_12:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x61D0
    ctx->r8 = ADD32(ctx->r8, -0X61D0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_13;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_13:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B04($a0)
    ctx->r4 = MEM_HU(-0X4B04, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_14;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_14:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_15;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_15:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x61B8
    ctx->r8 = ADD32(ctx->r8, -0X61B8);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_16;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_16:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B02($a0)
    ctx->r4 = MEM_HU(-0X4B02, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_17;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_17:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_18;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_18:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x61A0
    ctx->r8 = ADD32(ctx->r8, -0X61A0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_19;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_19:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B00($a0)
    ctx->r4 = MEM_HU(-0X4B00, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_20;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_20:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_21;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_21:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x6188
    ctx->r8 = ADD32(ctx->r8, -0X6188);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_22;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_22:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AFE($a0)
    ctx->r4 = MEM_HU(-0X4AFE, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_23;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_23:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_24;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_24:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0xA8
    ctx->r2 = 0 | 0XA8;
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // ori         $t0, $zero, 0x1C
    ctx->r8 = 0 | 0X1C;
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // sh          $t0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r8;
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $s5, 0x18
    ctx->r3 = ADD32(ctx->r21, 0X18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_25;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_25:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_26;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_26:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AFA($a0)
    ctx->r4 = MEM_HU(-0X4AFA, ctx->r4);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_27;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_27:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_28;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_28:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_29;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_29:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AF8($a0)
    ctx->r4 = MEM_HU(-0X4AF8, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_30;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_30:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_31;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_31:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_32;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_32:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AF6($a0)
    ctx->r4 = MEM_HU(-0X4AF6, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_33;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_33:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_34;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_34:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $s5, 0x4C8
    ctx->r3 = ADD32(ctx->r21, 0X4C8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_35;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_35:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AF4($a0)
    ctx->r4 = MEM_HU(-0X4AF4, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_36;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_36:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_37;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_37:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s5, $s5, 0x4E0
    ctx->r21 = ADD32(ctx->r21, 0X4E0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_38;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_38:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AF2($a0)
    ctx->r4 = MEM_HU(-0X4AF2, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_39;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_39:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_40;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_40:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x61D0
    ctx->r8 = ADD32(ctx->r8, -0X61D0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_41;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_41:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AF0($a0)
    ctx->r4 = MEM_HU(-0X4AF0, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_42;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_42:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_43;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_43:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x61B8
    ctx->r8 = ADD32(ctx->r8, -0X61B8);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_44;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_44:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AEE($a0)
    ctx->r4 = MEM_HU(-0X4AEE, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_45;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_45:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_46;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_46:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x61A0
    ctx->r8 = ADD32(ctx->r8, -0X61A0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_47;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_47:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AEC($a0)
    ctx->r4 = MEM_HU(-0X4AEC, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_48;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_48:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_49;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_49:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // addiu       $t0, $t0, -0x6188
    ctx->r8 = ADD32(ctx->r8, -0X6188);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a2, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r6);
    // swr         $a2, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r6);
    // swl         $a3, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r7);
    // swr         $a3, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r7);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a2, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r6);
    // swr         $a2, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r6);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_50;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_50:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AEA($a0)
    ctx->r4 = MEM_HU(-0X4AEA, ctx->r4);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    FormatHUDNumber(rdram, ctx);
    goto after_51;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_51:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_52;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_52:
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // ori         $a2, $zero, 0x8C
    ctx->r6 = 0 | 0X8C;
    // ori         $a3, $zero, 0xCD
    ctx->r7 = 0 | 0XCD;
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // ori         $s0, $zero, 0x2
    ctx->r16 = 0 | 0X2;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // jal         0x80024298
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    DrawTextureNPatch(rdram, ctx);
    goto after_53;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_53:
    // ori         $a0, $zero, 0xA1
    ctx->r4 = 0 | 0XA1;
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // ori         $a2, $zero, 0x8C
    ctx->r6 = 0 | 0X8C;
    // ori         $a3, $zero, 0xCD
    ctx->r7 = 0 | 0XCD;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // jal         0x80024298
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    DrawTextureNPatch(rdram, ctx);
    goto after_54;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_54:
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
