#include "recomp.h"
#include "disable_warnings.h"

void sub_800234CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // ori         $v0, $zero, 0xB7
    ctx->r2 = 0 | 0XB7;
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // bne         $s1, $v0, L_80023614
    if (ctx->r17 != ctx->r2) {
        // sw          $s0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r16;
        goto L_80023614;
    }
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
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
    // addiu       $at, $at, -0x613D
    ctx->r1 = ADD32(ctx->r1, -0X613D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6140
    ctx->r1 = ADD32(ctx->r1, -0X6140);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6139
    ctx->r1 = ADD32(ctx->r1, -0X6139);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x613C
    ctx->r1 = ADD32(ctx->r1, -0X613C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6135
    ctx->r1 = ADD32(ctx->r1, -0X6135);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6138
    ctx->r1 = ADD32(ctx->r1, -0X6138);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6131
    ctx->r1 = ADD32(ctx->r1, -0X6131);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6134
    ctx->r1 = ADD32(ctx->r1, -0X6134);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r4);
    // swr         $a0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r4);
    // swl         $a1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r5);
    // swr         $a1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r5);
    // swl         $a2, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r6);
    // swr         $a2, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r6);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x612D
    ctx->r1 = ADD32(ctx->r1, -0X612D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6130
    ctx->r1 = ADD32(ctx->r1, -0X6130);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6129
    ctx->r1 = ADD32(ctx->r1, -0X6129);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x612C
    ctx->r1 = ADD32(ctx->r1, -0X612C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a0, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r4);
    // swr         $a0, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r4);
    // j           L_80023724
    // nop

    goto L_80023724;
    // nop

L_80023614:
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
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x655C
    ctx->r1 = ADD32(ctx->r1, -0X655C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6555
    ctx->r1 = ADD32(ctx->r1, -0X6555);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6558
    ctx->r1 = ADD32(ctx->r1, -0X6558);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6551
    ctx->r1 = ADD32(ctx->r1, -0X6551);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6554
    ctx->r1 = ADD32(ctx->r1, -0X6554);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r4);
    // swr         $a0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r4);
    // swl         $a1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r5);
    // swr         $a1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r5);
    // swl         $a2, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r6);
    // swr         $a2, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r6);
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
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x654C
    ctx->r1 = ADD32(ctx->r1, -0X654C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a0, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r4);
    // swr         $a0, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r4);
L_80023724:
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7AE4
    ctx->r16 = ADD32(ctx->r16, 0X7AE4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80023944
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawFrame(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // addiu       $a0, $s0, -0x30
    ctx->r4 = ADD32(ctx->r16, -0X30);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // bne         $s1, $v0, L_80023778
    if (ctx->r17 != ctx->r2) {
        // sh          $v1, 0x3A($sp)
        MEM_H(0X3A, ctx->r29) = ctx->r3;
        goto L_80023778;
    }
    // sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // lbu         $a0, -0x2130($a0)
    ctx->r4 = MEM_BU(-0X2130, ctx->r4);
    // j           L_8002378C
    // ori         $a3, $zero, 0x6
    ctx->r7 = 0 | 0X6;
    goto L_8002378C;
    // ori         $a3, $zero, 0x6
    ctx->r7 = 0 | 0X6;
L_80023778:
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x2
    ctx->r7 = 0 | 0X2;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4B10($a0)
    ctx->r4 = MEM_W(-0X4B10, ctx->r4);
L_8002378C:
    // addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // jal         0x80024B24
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FormatHUDNumber(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7AA8
    ctx->r16 = ADD32(ctx->r16, 0X7AA8);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
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
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $s1, $v0, L_80023928
    if (ctx->r17 == ctx->r2) {
        // addiu       $a0, $s0, 0x3C
        ctx->r4 = ADD32(ctx->r16, 0X3C);
        goto L_80023928;
    }
    // addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4A66($a2)
    ctx->r6 = MEM_H(-0X4A66, ctx->r6);
    // ori         $v0, $zero, 0xB7
    ctx->r2 = 0 | 0XB7;
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x3D
    ctx->r2 = 0 | 0X3D;
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
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6125
    ctx->r1 = ADD32(ctx->r1, -0X6125);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6128
    ctx->r1 = ADD32(ctx->r1, -0X6128);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6121
    ctx->r1 = ADD32(ctx->r1, -0X6121);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6124
    ctx->r1 = ADD32(ctx->r1, -0X6124);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x611D
    ctx->r1 = ADD32(ctx->r1, -0X611D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a3, 0x0($at)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6120
    ctx->r1 = ADD32(ctx->r1, -0X6120);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a3, 0x0($at)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6119
    ctx->r1 = ADD32(ctx->r1, -0X6119);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t0, 0x0($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x611C
    ctx->r1 = ADD32(ctx->r1, -0X611C);
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
    // addiu       $at, $at, -0x6115
    ctx->r1 = ADD32(ctx->r1, -0X6115);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6118
    ctx->r1 = ADD32(ctx->r1, -0X6118);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6111
    ctx->r1 = ADD32(ctx->r1, -0X6111);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6114
    ctx->r1 = ADD32(ctx->r1, -0X6114);
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
    // jal         0x80023944
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawFrame(rdram, ctx);
    goto after_4;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_4:
    // addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // jal         0x80023E20
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    ui_DrawText(rdram, ctx);
    goto after_5;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_5:
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // lw          $a0, 0x6C($gp)
    ctx->r4 = MEM_W(0X6C, ctx->r28);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addiu       $v0, $v0, 0x5B
    ctx->r2 = ADD32(ctx->r2, 0X5B);
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
    goto after_6;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80023FD4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    DrawHUDNumberString(rdram, ctx);
    goto after_7;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
L_80023928:
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
