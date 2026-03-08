#include "recomp.h"
#include "disable_warnings.h"

void DrawPlayerStat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // addiu       $s3, $s3, 0x7AB4
    ctx->r19 = ADD32(ctx->r19, 0X7AB4);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // ori         $v0, $zero, 0xA8
    ctx->r2 = 0 | 0XA8;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // lui         $s6, 0x801A
    ctx->r22 = S32(0X801A << 16);
    // addiu       $s6, $s6, -0x4A66
    ctx->r22 = ADD32(ctx->r22, -0X4A66);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1E
    ctx->r2 = 0 | 0X1E;
    // sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(0X0, ctx->r22);
    // lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // addiu       $s7, $s7, -0x6668
    ctx->r23 = ADD32(ctx->r23, -0X6668);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
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
    goto after_0;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4B3C($a0)
    ctx->r4 = MEM_W(-0X4B3C, ctx->r4);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addiu       $v0, $v0, 0x4D
    ctx->r2 = ADD32(ctx->r2, 0X4D);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // jal         0x80024B24
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // addiu       $s1, $s3, -0xC
    ctx->r17 = ADD32(ctx->r19, -0XC);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(0X0, ctx->r22);
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
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
    // addiu       $v1, $s7, 0x18
    ctx->r3 = ADD32(ctx->r23, 0X18);
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
    goto after_3;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_3:
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(0X3A, ctx->r29);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4B34($a0)
    ctx->r4 = MEM_BU(-0X4B34, ctx->r4);
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_4;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_5;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // sb          $v0, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sb          $v0, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // ori         $s4, $zero, 0xFF
    ctx->r20 = 0 | 0XFF;
    // sb          $s4, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r20;
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
    // jal         0x80023E20
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    ui_DrawText(rdram, ctx);
    goto after_6;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_6:
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B28($a0)
    ctx->r4 = MEM_HU(-0X4B28, ctx->r4);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x3A($sp)
    ctx->r3 = MEM_HU(0X3A, ctx->r29);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // addiu       $v1, $v1, 0x17
    ctx->r3 = ADD32(ctx->r3, 0X17);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // jal         0x80024B24
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_7;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_7:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_8;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // ori         $s5, $zero, 0x14
    ctx->r21 = 0 | 0X14;
    // sb          $s5, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r21;
    // sb          $s4, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r20;
    // addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // jal         0x80023FD4
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    DrawHUDNumberString(rdram, ctx);
    goto after_9;
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    after_9:
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B2A($a0)
    ctx->r4 = MEM_HU(-0X4B2A, ctx->r4);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_10;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_10:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_11;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // ori         $v1, $zero, 0xC
    ctx->r3 = 0 | 0XC;
    // sb          $v1, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
    // jal         0x80023E20
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    ui_DrawText(rdram, ctx);
    goto after_12;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    after_12:
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B24($a0)
    ctx->r4 = MEM_HU(-0X4B24, ctx->r4);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x3A($sp)
    ctx->r3 = MEM_HU(0X3A, ctx->r29);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // addiu       $v1, $v1, 0x17
    ctx->r3 = ADD32(ctx->r3, 0X17);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // jal         0x80024B24
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_13;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_13:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_14;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_14:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sb          $s5, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r21;
    // sb          $s4, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r20;
    // addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // jal         0x80023FD4
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    DrawHUDNumberString(rdram, ctx);
    goto after_15;
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    after_15:
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B26($a0)
    ctx->r4 = MEM_HU(-0X4B26, ctx->r4);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // jal         0x80024B24
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_16;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_16:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_17;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_17:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(0X0, ctx->r22);
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
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
    // addiu       $v1, $s7, 0x3A8
    ctx->r3 = ADD32(ctx->r23, 0X3A8);
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
    goto after_18;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_18:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B14($a0)
    ctx->r4 = MEM_HU(-0X4B14, ctx->r4);
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
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_19;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_19:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_20;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_20:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(0X0, ctx->r22);
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
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
    // addiu       $v1, $s7, 0x3C0
    ctx->r3 = ADD32(ctx->r23, 0X3C0);
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
    goto after_21;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_21:
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B12($a0)
    ctx->r4 = MEM_HU(-0X4B12, ctx->r4);
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
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    FormatHUDNumber(rdram, ctx);
    goto after_22;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_22:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80023FD4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_23;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_23:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(0X0, ctx->r22);
    // addiu       $v0, $v0, 0x17
    ctx->r2 = ADD32(ctx->r2, 0X17);
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
    // addiu       $v1, $s7, 0x60
    ctx->r3 = ADD32(ctx->r23, 0X60);
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
    goto after_24;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_24:
    // ori         $s2, $zero, 0x17
    ctx->r18 = 0 | 0X17;
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x3A($sp)
    ctx->r3 = MEM_HU(0X3A, ctx->r29);
    // addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADC($v0)
    ctx->r2 = MEM_H(-0X4ADC, ctx->r2);
    // addiu       $v1, $v1, 0x17
    ctx->r3 = ADD32(ctx->r3, 0X17);
    // beq         $v0, $zero, L_800210B0
    if (ctx->r2 == 0) {
        // sh          $v1, 0x3A($sp)
        MEM_H(0X3A, ctx->r29) = ctx->r3;
        goto L_800210B0;
    }
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(0X0, ctx->r22);
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
    // j           L_800211B0
    // addiu       $v1, $s7, 0x78
    ctx->r3 = ADD32(ctx->r23, 0X78);
    goto L_800211B0;
    // addiu       $v1, $s7, 0x78
    ctx->r3 = ADD32(ctx->r23, 0X78);
L_800210B0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AE6($v0)
    ctx->r2 = MEM_H(-0X4AE6, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800210E8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800210E8;
    }
    // nop

    // lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(0X0, ctx->r22);
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
    // j           L_800211B0
    // addiu       $v1, $s7, 0x90
    ctx->r3 = ADD32(ctx->r23, 0X90);
    goto L_800211B0;
    // addiu       $v1, $s7, 0x90
    ctx->r3 = ADD32(ctx->r23, 0X90);
L_800210E8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADE($v0)
    ctx->r2 = MEM_H(-0X4ADE, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80021120
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80021120;
    }
    // nop

    // lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(0X0, ctx->r22);
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
    // j           L_800211B0
    // addiu       $v1, $s7, 0xA8
    ctx->r3 = ADD32(ctx->r23, 0XA8);
    goto L_800211B0;
    // addiu       $v1, $s7, 0xA8
    ctx->r3 = ADD32(ctx->r23, 0XA8);
L_80021120:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AE8($v0)
    ctx->r2 = MEM_H(-0X4AE8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80021158
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80021158;
    }
    // nop

    // lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(0X0, ctx->r22);
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
    // j           L_800211B0
    // addiu       $v1, $s7, 0xC0
    ctx->r3 = ADD32(ctx->r23, 0XC0);
    goto L_800211B0;
    // addiu       $v1, $s7, 0xC0
    ctx->r3 = ADD32(ctx->r23, 0XC0);
L_80021158:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AE2($v0)
    ctx->r2 = MEM_H(-0X4AE2, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80021190
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80021190;
    }
    // nop

    // lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(0X0, ctx->r22);
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
    // j           L_800211B0
    // addiu       $v1, $s7, 0xD8
    ctx->r3 = ADD32(ctx->r23, 0XD8);
    goto L_800211B0;
    // addiu       $v1, $s7, 0xD8
    ctx->r3 = ADD32(ctx->r23, 0XD8);
L_80021190:
    // lh          $v0, 0x0($s6)
    ctx->r2 = MEM_H(0X0, ctx->r22);
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
    // addiu       $v1, $s7, 0xF0
    ctx->r3 = ADD32(ctx->r23, 0XF0);
L_800211B0:
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
    // swl         $v1, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r3);
    // swr         $v1, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r3);
    // swl         $a0, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r4);
    // swr         $a0, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r4);
    // swl         $a1, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r5);
    // swr         $a1, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r5);
    // swl         $a2, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r6);
    // swr         $a2, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r6);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r3);
    // swr         $v1, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r3);
    // swl         $a0, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r4);
    // swr         $a0, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r4);
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7AB4
    ctx->r16 = ADD32(ctx->r16, 0X7AB4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // jal         0x80023E20
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ui_DrawText(rdram, ctx);
    goto after_25;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_25:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4A66($a2)
    ctx->r6 = MEM_H(-0X4A66, ctx->r6);
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
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
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x655D
    ctx->r1 = ADD32(ctx->r1, -0X655D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6560
    ctx->r1 = ADD32(ctx->r1, -0X6560);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6559
    ctx->r1 = ADD32(ctx->r1, -0X6559);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x655C
    ctx->r1 = ADD32(ctx->r1, -0X655C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6555
    ctx->r1 = ADD32(ctx->r1, -0X6555);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a3, 0x0($at)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6558
    ctx->r1 = ADD32(ctx->r1, -0X6558);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a3, 0x0($at)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6551
    ctx->r1 = ADD32(ctx->r1, -0X6551);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t0, 0x0($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6554
    ctx->r1 = ADD32(ctx->r1, -0X6554);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t0, 0x0($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X0, ctx->r1);
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
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x654D
    ctx->r1 = ADD32(ctx->r1, -0X654D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6550
    ctx->r1 = ADD32(ctx->r1, -0X6550);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6549
    ctx->r1 = ADD32(ctx->r1, -0X6549);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x654C
    ctx->r1 = ADD32(ctx->r1, -0X654C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
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
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4B10($a0)
    ctx->r4 = MEM_W(-0X4B10, ctx->r4);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x3A($sp)
    ctx->r3 = MEM_HU(0X3A, ctx->r29);
    // addiu       $v0, $v0, 0x4D
    ctx->r2 = ADD32(ctx->r2, 0X4D);
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // jal         0x80024B24
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FormatHUDNumber(rdram, ctx);
    goto after_27;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_27:
    // addiu       $a0, $s0, -0xC
    ctx->r4 = ADD32(ctx->r16, -0XC);
    // jal         0x80023FD4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_28;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_28:
    // ori         $a0, $zero, 0xA1
    ctx->r4 = 0 | 0XA1;
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // ori         $a2, $zero, 0x8C
    ctx->r6 = 0 | 0X8C;
    // ori         $a3, $zero, 0xCD
    ctx->r7 = 0 | 0XCD;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // jal         0x80024298
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    DrawTextureNPatch(rdram, ctx);
    goto after_29;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_29:
    // lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(0X78, ctx->r29);
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
