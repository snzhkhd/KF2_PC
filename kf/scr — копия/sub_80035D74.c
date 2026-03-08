#include "recomp.h"
#include "disable_warnings.h"

void sub_80035D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // addiu       $a2, $a2, 0x4DF6
    ctx->r6 = ADD32(ctx->r6, 0X4DF6);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80035F30
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80035F30;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80035DB4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035DB4;
    }
    // nop

    // beq         $v1, $zero, L_80035DD0
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80035DD0;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_8003606C
    // nop

    goto L_8003606C;
    // nop

L_80035DB4:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_80035F68
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80035F68;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_80035F94
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80035F94;
    }
    // nop

    // j           L_8003606C
    // nop

    goto L_8003606C;
    // nop

L_80035DD0:
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lbu         $v1, 0x4DF4($v1)
    ctx->r3 = MEM_BU(0X4DF4, ctx->r3);
    // nop

    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x4DDC
    ctx->r1 = ADD32(ctx->r1, 0X4DDC);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $a0, 0x0($at)
    ctx->r4 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $a0, $v0, L_8003606C
    if (ctx->r4 == ctx->r2) {
        // ori         $s1, $zero, 0x1
        ctx->r17 = 0 | 0X1;
        goto L_8003606C;
    }
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sb          $s1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r17;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x4DF7($at)
    MEM_B(0X4DF7, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x4DF8($at)
    MEM_B(0X4DF8, ctx->r1) = 0;
    // bne         $a0, $v0, L_80035EB4
    if (ctx->r4 != ctx->r2) {
        // lui         $v0, 0x38E3
        ctx->r2 = S32(0X38E3 << 16);
        goto L_80035EB4;
    }
    // lui         $v0, 0x38E3
    ctx->r2 = S32(0X38E3 << 16);
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, -0x1DC8
    ctx->r16 = ADD32(ctx->r16, -0X1DC8);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x1DB5($at)
    MEM_B(-0X1DB5, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x2A
    ctx->r2 = 0 | 0X2A;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x1DB4($at)
    MEM_B(-0X1DB4, ctx->r1) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $s1, -0x1DB6($at)
    MEM_B(-0X1DB6, ctx->r1) = ctx->r17;
    // lhu         $a0, -0x12($v0)
    ctx->r4 = MEM_HU(-0X12, ctx->r2);
    // addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x80024B24
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FormatHUDNumber(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // lbu         $a1, 0x1B($sp)
    ctx->r5 = MEM_BU(0X1B, ctx->r29);
    // addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // jal         0x80035D64
    // sb          $s1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r17;
    sub_80035D64(rdram, ctx);
    goto after_1;
    // sb          $s1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r17;
    after_1:
    // lbu         $a1, 0x1A($sp)
    ctx->r5 = MEM_BU(0X1A, ctx->r29);
    // addiu       $a0, $s0, 0x36
    ctx->r4 = ADD32(ctx->r16, 0X36);
    // jal         0x80035D64
    // sb          $s1, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r17;
    sub_80035D64(rdram, ctx);
    goto after_2;
    // sb          $s1, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r17;
    after_2:
    // lbu         $a1, 0x19($sp)
    ctx->r5 = MEM_BU(0X19, ctx->r29);
    // addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // jal         0x80035D64
    // sb          $s1, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r17;
    sub_80035D64(rdram, ctx);
    goto after_3;
    // sb          $s1, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r17;
    after_3:
    // lbu         $a1, 0x18($sp)
    ctx->r5 = MEM_BU(0X18, ctx->r29);
    // addiu       $a0, $s0, 0x5A
    ctx->r4 = ADD32(ctx->r16, 0X5A);
    // jal         0x80035D64
    // sb          $s1, 0x5A($s0)
    MEM_B(0X5A, ctx->r16) = ctx->r17;
    sub_80035D64(rdram, ctx);
    goto after_4;
    // sb          $s1, 0x5A($s0)
    MEM_B(0X5A, ctx->r16) = ctx->r17;
    after_4:
    // j           L_8003606C
    // nop

    goto L_8003606C;
    // nop

L_80035EB4:
    // ori         $v0, $v0, 0x8E39
    ctx->r2 = ctx->r2 | 0X8E39;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $s1, -0x1DC8($at)
    MEM_B(-0X1DC8, ctx->r1) = ctx->r17;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1D6E($at)
    MEM_B(-0X1D6E, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1D80($at)
    MEM_B(-0X1D80, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1D92($at)
    MEM_B(-0X1D92, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1DA4($at)
    MEM_B(-0X1DA4, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1DB6($at)
    MEM_B(-0X1DB6, ctx->r1) = 0;
    // mfhi        $v1
    ctx->r3 = hi;
    // srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v1, $v1, 7
    ctx->r3 = S32(ctx->r3) << 7;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1DC7($at)
    MEM_B(-0X1DC7, ctx->r1) = ctx->r3;
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1DC6($at)
    MEM_B(-0X1DC6, ctx->r1) = ctx->r3;
    // j           L_8003606C
    // nop

    goto L_8003606C;
    // nop

L_80035F30:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF8($v0)
    ctx->r2 = MEM_BU(0X4DF8, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x4DF8($at)
    MEM_B(0X4DF8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF8($v0)
    ctx->r2 = MEM_BU(0X4DF8, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x64
    ctx->r2 = ctx->r2 < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_8003606C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003606C;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_8003606C
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    goto L_8003606C;
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80035F68:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF7($v0)
    ctx->r2 = MEM_BU(0X4DF7, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x4DF7($at)
    MEM_B(0X4DF7, ctx->r1) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_8003606C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003606C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_8003606C
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    goto L_8003606C;
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80035F94:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF8($v0)
    ctx->r2 = MEM_BU(0X4DF8, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0xEC
    ctx->r2 = ADD32(ctx->r2, 0XEC);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x4DF8($at)
    MEM_B(0X4DF8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF8($v0)
    ctx->r2 = MEM_BU(0X4DF8, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8003606C
    if (ctx->r2 != 0) {
        // addiu       $a0, $a2, -0x2
        ctx->r4 = ADD32(ctx->r6, -0X2);
        goto L_8003606C;
    }
    // addiu       $a0, $a2, -0x2
    ctx->r4 = ADD32(ctx->r6, -0X2);
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF4($v0)
    ctx->r2 = MEM_BU(0X4DF4, ctx->r2);
    // ori         $a1, $zero, 0x15
    ctx->r5 = 0 | 0X15;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1D6E($at)
    MEM_B(-0X1D6E, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1D80($at)
    MEM_B(-0X1D80, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1D92($at)
    MEM_B(-0X1D92, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1DA4($at)
    MEM_B(-0X1DA4, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1DB6($at)
    MEM_B(-0X1DB6, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x1DC8($at)
    MEM_B(-0X1DC8, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x4DDC
    ctx->r1 = ADD32(ctx->r1, 0X4DDC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
L_80036010:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x4DDC
    ctx->r1 = ADD32(ctx->r1, 0X4DDC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $a2, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r6;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x4DDC
    ctx->r1 = ADD32(ctx->r1, 0X4DDC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // bne         $v1, $v0, L_80036068
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80036068;
    }
    // nop

    // bne         $v1, $a1, L_80036010
    if (ctx->r3 != ctx->r5) {
        // nop
    
        goto L_80036010;
    }
    // nop

L_80036068:
    // sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_8003606C:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
