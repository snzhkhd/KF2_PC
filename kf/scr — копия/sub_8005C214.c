#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x1910
    ctx->r1 = ADD32(ctx->r1, -0X1910);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8005C250
    if (ctx->r3 == ctx->r2) {
        // addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
        goto L_8005C250;
    }
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // j           L_8005C308
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8005C308;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005C250:
    // sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // jal         0x8005984C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005984C(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16) << 4;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(0X1, ctx->r2);
    // nop

    // sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // nop

    // sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(0X3, ctx->r2);
    // nop

    // sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(0X4, ctx->r2);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sh          $v1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r3;
L_8005C308:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
