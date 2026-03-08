#include "recomp.h"
#include "disable_warnings.h"

void sub_80048B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // addiu       $at, $at, 0x4720
    ctx->r1 = ADD32(ctx->r1, 0X4720);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $s0, 0x0($at)
    ctx->r16 = MEM_W(0X0, ctx->r1);
    // nop

    // addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // addiu       $a0, $s0, 0x17
    ctx->r4 = ADD32(ctx->r16, 0X17);
L_80048B54:
    // lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(0X0, ctx->r5);
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
L_80048B5C:
    // beq         $v1, $v0, L_80048BA4
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_80048BA4;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_80048B5C
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xF1
        ctx->r2 = 0 | 0XF1;
        goto L_80048B5C;
    }
    // ori         $v0, $zero, 0xF1
    ctx->r2 = 0 | 0XF1;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80048B94
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80048B94;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $a1, 0xEC
    ctx->r2 = ADD32(ctx->r5, 0XEC);
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // j           L_80048C18
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    goto L_80048C18;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80048B90:
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
L_80048B94:
    // nop

    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // j           L_80048C18
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    goto L_80048C18;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
L_80048BA4:
    // lbu         $v0, -0x2($a0)
    ctx->r2 = MEM_BU(-0X2, ctx->r4);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(-0X1, ctx->r4);
    // nop

    // bne         $v1, $v0, L_80048C0C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80048C0C;
    }
    // nop

    // lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(0X0, ctx->r4);
    // jal         0x80048AB4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80048AB4(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80048BF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048BF4;
    }
    // nop

    // sb          $a0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r4;
L_80048BF4:
    // lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(0X1, ctx->r17);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sb          $v0, 0x51DB($at)
    MEM_B(0X51DB, ctx->r1) = ctx->r2;
    // j           L_80048B90
    // sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    goto L_80048B90;
    // sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
L_80048C0C:
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // j           L_80048B54
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    goto L_80048B54;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80048C18:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
