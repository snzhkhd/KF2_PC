#include "recomp.h"
#include "disable_warnings.h"

void ReadTMD_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x6EA8($a0)
    ctx->r4 = MEM_W(-0X6EA8, ctx->r4);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80065E90
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Engine_PackPrimitive(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // bltz        $a2, L_80065BC4
    if (SIGNED(ctx->r6) < 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80065BC4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, -0x6EB0($a1)
    ctx->r5 = MEM_W(-0X6EB0, ctx->r5);
    // lhu         $v0, 0x70($s0)
    ctx->r2 = MEM_HU(0X70, ctx->r16);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x6EAC($a0)
    ctx->r4 = MEM_W(-0X6EAC, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $a1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r5;
    // sw          $a0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r4;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x70($s0)
    ctx->r2 = MEM_HU(0X70, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x70($s0)
    ctx->r2 = MEM_HU(0X70, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(0X72, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(0X72, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(0X72, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x74($s0)
    ctx->r2 = MEM_HU(0X74, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x74($s0)
    ctx->r2 = MEM_HU(0X74, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x74($s0)
    ctx->r2 = MEM_HU(0X74, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x76($s0)
    ctx->r3 = MEM_HU(0X76, ctx->r16);
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, -0x6EA8($v0)
    ctx->r2 = MEM_W(-0X6EA8, ctx->r2);
    // lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(0X0, ctx->r3);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6EA8($at)
    MEM_W(-0X6EA8, ctx->r1) = ctx->r2;
    // sh          $v1, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r3;
    // lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(0X76, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(0X76, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x68($s0)
    ctx->r2 = MEM_HU(0X68, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x68($s0)
    ctx->r2 = MEM_HU(0X68, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x68($s0)
    ctx->r2 = MEM_HU(0X68, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x6A($s0)
    ctx->r2 = MEM_HU(0X6A, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x6A($s0)
    ctx->r2 = MEM_HU(0X6A, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x6A($s0)
    ctx->r2 = MEM_HU(0X6A, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(0X6C, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(0X6C, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(0X6C, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x6E($s0)
    ctx->r2 = MEM_HU(0X6E, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $v0, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6E($s0)
    ctx->r2 = MEM_HU(0X6E, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x6E($s0)
    ctx->r2 = MEM_HU(0X6E, ctx->r16);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v1, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // sh          $v1, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r3;
L_80065BC4:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
