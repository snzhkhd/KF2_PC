#include "recomp.h"
#include "disable_warnings.h"

void sub_80050C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7BC($a0)
    ctx->r4 = MEM_W(-0X7BC, ctx->r4);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0xB
    ctx->r3 = S32(0XB << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // sh          $zero, 0x180($v0)
    MEM_H(0X180, ctx->r2) = 0;
    // sh          $zero, 0x182($v0)
    MEM_H(0X182, ctx->r2) = 0;
    // sh          $zero, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = 0;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x7B4($at)
    MEM_W(-0X7B4, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x7B0($at)
    MEM_W(-0X7B0, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $zero, -0x7D0($at)
    MEM_H(-0X7D0, ctx->r1) = 0;
    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_80050D30
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050D30;
    }
    // nop

L_80050CF0:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80050CF0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050CF0;
    }
    // nop

L_80050D30:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // sh          $zero, 0x180($v0)
    MEM_H(0X180, ctx->r2) = 0;
    // sh          $zero, 0x182($v0)
    MEM_H(0X182, ctx->r2) = 0;
    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x7D4($at)
    MEM_W(-0X7D4, ctx->r1) = 0;
    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // beq         $v0, $zero, L_80050DC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050DC0;
    }
    // nop

L_80050D5C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7D4($v0)
    ctx->r2 = MEM_W(-0X7D4, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7D4($at)
    MEM_W(-0X7D4, ctx->r1) = ctx->r2;
    // slti        $v0, $v0, 0x1389
    ctx->r2 = SIGNED(ctx->r2) < 0X1389 ? 1 : 0;
    // bne         $v0, $zero, L_80050DA0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050DA0;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x320C
    ctx->r5 = ADD32(ctx->r5, 0X320C);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80050DC0
    // nop

    goto L_80050DC0;
    // nop

L_80050DA0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // bne         $v0, $zero, L_80050D5C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050D5C;
    }
    // nop

L_80050DC0:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7AC($at)
    MEM_W(-0X7AC, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7A8($at)
    MEM_W(-0X7A8, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7A4($at)
    MEM_W(-0X7A4, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7A0($at)
    MEM_W(-0X7A0, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sh          $v0, 0x1AC($v1)
    MEM_H(0X1AC, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $zero, 0x184($v1)
    MEM_H(0X184, ctx->r3) = 0;
    // sh          $zero, 0x186($v1)
    MEM_H(0X186, ctx->r3) = 0;
    // sh          $v0, 0x18C($v1)
    MEM_H(0X18C, ctx->r3) = ctx->r2;
    // sh          $v0, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r2;
    // sh          $zero, 0x198($v1)
    MEM_H(0X198, ctx->r3) = 0;
    // sh          $zero, 0x19A($v1)
    MEM_H(0X19A, ctx->r3) = 0;
    // bne         $s0, $zero, L_80051184
    if (ctx->r16 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80051184;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x790
    ctx->r4 = ADD32(ctx->r4, -0X790);
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // ori         $v0, $zero, 0x200
    ctx->r2 = 0 | 0X200;
    // sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // sh          $zero, 0x192($v1)
    MEM_H(0X192, ctx->r3) = 0;
    // sh          $zero, 0x194($v1)
    MEM_H(0X194, ctx->r3) = 0;
    // sh          $zero, 0x196($v1)
    MEM_H(0X196, ctx->r3) = 0;
    // sh          $zero, 0x1B0($v1)
    MEM_H(0X1B0, ctx->r3) = 0;
    // sh          $zero, 0x1B2($v1)
    MEM_H(0X1B2, ctx->r3) = 0;
    // sh          $zero, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = 0;
    // sh          $zero, 0x1B6($v1)
    MEM_H(0X1B6, ctx->r3) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, -0x7D0($at)
    MEM_H(-0X7D0, ctx->r1) = ctx->r2;
    // jal         0x800511C4
    // nop

    sub_800511C4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a2, $zero, 0x3FFF
    ctx->r6 = 0 | 0X3FFF;
    // ori         $a1, $zero, 0x200
    ctx->r5 = 0 | 0X200;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
L_80050E78:
    // nop

    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80050E78
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_80050E78;
    }
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // nop

    // lhu         $v0, 0x188($v1)
    ctx->r2 = MEM_HU(0X188, ctx->r3);
    // nop

    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x188($v1)
    MEM_H(0X188, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x18A($v1)
    ctx->r2 = MEM_HU(0X18A, ctx->r3);
    // nop

    // ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // sh          $v0, 0x18A($v1)
    MEM_H(0X18A, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80050F0C
    // nop

    goto L_80050F0C;
    // nop

L_80050EE4:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_80050F0C:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80050EE4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80050EE4;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80050F5C
    // nop

    goto L_80050F5C;
    // nop

L_80050F34:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_80050F5C:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80050F34
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80050F34;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80050FAC
    // nop

    goto L_80050FAC;
    // nop

L_80050F84:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_80050FAC:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80050F84
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80050F84;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80050FFC
    // nop

    goto L_80050FFC;
    // nop

L_80050FD4:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_80050FFC:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80050FD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050FD4;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // nop

    // lhu         $v0, 0x18C($v1)
    ctx->r2 = MEM_HU(0X18C, ctx->r3);
    // nop

    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x18C($v1)
    MEM_H(0X18C, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x18E($v1)
    ctx->r2 = MEM_HU(0X18E, ctx->r3);
    // nop

    // ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // sh          $v0, 0x18E($v1)
    MEM_H(0X18E, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_8005107C
    // nop

    goto L_8005107C;
    // nop

L_80051054:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_8005107C:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80051054
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80051054;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_800510CC
    // nop

    goto L_800510CC;
    // nop

L_800510A4:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_800510CC:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800510A4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_800510A4;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_8005111C
    // nop

    goto L_8005111C;
    // nop

L_800510F4:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_8005111C:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800510F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_800510F4;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_8005116C
    // nop

    goto L_8005116C;
    // nop

L_80051144:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_8005116C:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80051144
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80051144;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80051184:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7CC($a0)
    ctx->r4 = MEM_W(-0X7CC, ctx->r4);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, -0x79C($at)
    MEM_W(-0X79C, ctx->r1) = ctx->r3;
    // ori         $v1, $zero, 0xC000
    ctx->r3 = 0 | 0XC000;
    // sh          $v1, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x798($at)
    MEM_W(-0X798, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
