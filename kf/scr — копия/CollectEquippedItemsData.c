#include "recomp.h"
#include "disable_warnings.h"

void CollectEquippedItemsData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA1($v0)
    ctx->r2 = MEM_BU(-0X4AA1, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA5($v1)
    ctx->r3 = MEM_BU(-0X4AA5, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A7A($a0)
    ctx->r4 = MEM_BU(-0X4A7A, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x4A7C($a1)
    ctx->r5 = MEM_BU(-0X4A7C, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lbu         $a2, -0x4A7B($a2)
    ctx->r6 = MEM_BU(-0X4A7B, ctx->r6);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lbu         $a3, -0x4A79($a3)
    ctx->r7 = MEM_BU(-0X4A79, ctx->r7);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lbu         $t0, -0x4A78($t0)
    ctx->r8 = MEM_BU(-0X4A78, ctx->r8);
    // lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // lbu         $t1, -0x4A77($t1)
    ctx->r9 = MEM_BU(-0X4A77, ctx->r9);
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // lbu         $t2, -0x4A76($t2)
    ctx->r10 = MEM_BU(-0X4A76, ctx->r10);
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // sb          $v1, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA4($v1)
    ctx->r3 = MEM_BU(-0X4AA4, ctx->r3);
    // sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $a0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r4;
    // sb          $a1, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r5;
    // sb          $a2, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r6;
    // sb          $a3, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r7;
    // sb          $t0, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r8;
    // sb          $t1, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r9;
    // bne         $v1, $v0, L_8001ADB4
    if (ctx->r3 != ctx->r2) {
        // sb          $t2, 0x8($sp)
        MEM_B(0X8, ctx->r29) = ctx->r10;
        goto L_8001ADB4;
    }
    // sb          $t2, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r10;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA3($v0)
    ctx->r2 = MEM_BU(-0X4AA3, ctx->r2);
    // j           L_8001ADB8
    // sb          $v0, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r2;
    goto L_8001ADB8;
    // sb          $v0, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r2;
L_8001ADB4:
    // sb          $v1, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r3;
L_8001ADB8:
    // addu        $t0, $sp, $zero
    ctx->r8 = ADD32(ctx->r29, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $t1, $zero, 0xFF
    ctx->r9 = 0 | 0XFF;
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // addiu       $t2, $t2, -0x4A66
    ctx->r10 = ADD32(ctx->r10, -0X4A66);
L_8001ADCC:
    // lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(0X0, ctx->r8);
    // nop

    // beq         $v1, $t1, L_8001AED0
    if (ctx->r3 == ctx->r9) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001AED0;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a3, $v0, L_8001AE04
    if (ctx->r7 == ctx->r2) {
        // nop
    
        goto L_8001AE04;
    }
    // nop

    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // bne         $a3, $v0, L_8001AE30
    if (ctx->r7 != ctx->r2) {
        // nop
    
        goto L_8001AE30;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA4($v0)
    ctx->r2 = MEM_BU(-0X4AA4, ctx->r2);
    // nop

    // beq         $v0, $t1, L_8001AE30
    if (ctx->r2 == ctx->r9) {
        // nop
    
        goto L_8001AE30;
    }
    // nop

L_8001AE04:
    // lh          $v0, 0x0($t2)
    ctx->r2 = MEM_H(0X0, ctx->r10);
    // nop

    // sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2) << 4;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x3218
    ctx->r3 = ADD32(ctx->r3, -0X3218);
    // j           L_8001AE64
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    goto L_8001AE64;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
L_8001AE30:
    // lh          $v1, 0x0($t2)
    ctx->r3 = MEM_H(0X0, ctx->r10);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2) << 4;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(0X0, ctx->r8);
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x53D8
    ctx->r3 = ADD32(ctx->r3, -0X53D8);
L_8001AE64:
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lwl         $v0, 0x3($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r4);
    // lwr         $v0, 0x0($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r4);
    // lwl         $v1, 0x7($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r4);
    // lwr         $v1, 0x4($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r4);
    // lwl         $a1, 0xB($a0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r4);
    // lwr         $a1, 0x8($a0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r4);
    // lwl         $a2, 0xF($a0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XF, ctx->r4);
    // lwr         $a2, 0xC($a0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0XC, ctx->r4);
    // swl         $v0, 0x3($t3)
    do_swl(rdram, 0X3, ctx->r11, ctx->r2);
    // swr         $v0, 0x0($t3)
    do_swr(rdram, 0X0, ctx->r11, ctx->r2);
    // swl         $v1, 0x7($t3)
    do_swl(rdram, 0X7, ctx->r11, ctx->r3);
    // swr         $v1, 0x4($t3)
    do_swr(rdram, 0X4, ctx->r11, ctx->r3);
    // swl         $a1, 0xB($t3)
    do_swl(rdram, 0XB, ctx->r11, ctx->r5);
    // swr         $a1, 0x8($t3)
    do_swr(rdram, 0X8, ctx->r11, ctx->r5);
    // swl         $a2, 0xF($t3)
    do_swl(rdram, 0XF, ctx->r11, ctx->r6);
    // swr         $a2, 0xC($t3)
    do_swr(rdram, 0XC, ctx->r11, ctx->r6);
    // lwl         $v0, 0x13($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r4);
    // lwr         $v0, 0x10($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r4);
    // lwl         $v1, 0x17($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X17, ctx->r4);
    // lwr         $v1, 0x14($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X14, ctx->r4);
    // swl         $v0, 0x13($t3)
    do_swl(rdram, 0X13, ctx->r11, ctx->r2);
    // swr         $v0, 0x10($t3)
    do_swr(rdram, 0X10, ctx->r11, ctx->r2);
    // swl         $v1, 0x17($t3)
    do_swl(rdram, 0X17, ctx->r11, ctx->r3);
    // j           L_8001AED4
    // swr         $v1, 0x14($t3)
    do_swr(rdram, 0X14, ctx->r11, ctx->r3);
    goto L_8001AED4;
    // swr         $v1, 0x14($t3)
    do_swr(rdram, 0X14, ctx->r11, ctx->r3);
L_8001AED0:
    // sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
L_8001AED4:
    // addiu       $t3, $t3, 0x18
    ctx->r11 = ADD32(ctx->r11, 0X18);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slti        $v0, $a3, 0xA
    ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_8001ADCC
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_8001ADCC;
    }
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // jr          $ra
    // nop

    return;
    // nop

;}
