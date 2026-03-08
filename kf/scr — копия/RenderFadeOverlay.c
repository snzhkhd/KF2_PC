#include "recomp.h"
#include "disable_warnings.h"

void RenderFadeOverlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(0X8, ctx->r3);
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(0X58, ctx->r29);
    // lbu         $t0, 0x30($sp)
    ctx->r8 = MEM_BU(0X30, ctx->r29);
    // lbu         $t1, 0x34($sp)
    ctx->r9 = MEM_BU(0X34, ctx->r29);
    // lbu         $t8, 0x38($sp)
    ctx->r24 = MEM_BU(0X38, ctx->r29);
    // lbu         $t9, 0x3C($sp)
    ctx->r25 = MEM_BU(0X3C, ctx->r29);
    // lhu         $t6, 0x44($sp)
    ctx->r14 = MEM_HU(0X44, ctx->r29);
    // lhu         $t7, 0x48($sp)
    ctx->r15 = MEM_HU(0X48, ctx->r29);
    // lbu         $t3, 0x4C($sp)
    ctx->r11 = MEM_BU(0X4C, ctx->r29);
    // lbu         $t4, 0x50($sp)
    ctx->r12 = MEM_BU(0X50, ctx->r29);
    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // lbu         $t5, 0x54($sp)
    ctx->r13 = MEM_BU(0X54, ctx->r29);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // lbu         $v1, 0x40($sp)
    ctx->r3 = MEM_BU(0X40, ctx->r29);
    // bne         $v0, $zero, L_80033D9C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x9
        ctx->r2 = 0 | 0X9;
        goto L_80033D9C;
    }
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // ori         $t2, $zero, 0x2C
    ctx->r10 = 0 | 0X2C;
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80033D10
    if (ctx->r3 == ctx->r2) {
        // sb          $t2, 0x7($a1)
        MEM_B(0X7, ctx->r5) = ctx->r10;
        goto L_80033D10;
    }
    // sb          $t2, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r10;
    // beq         $v1, $zero, L_80033D10
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x2E
        ctx->r2 = 0 | 0X2E;
        goto L_80033D10;
    }
    // ori         $v0, $zero, 0x2E
    ctx->r2 = 0 | 0X2E;
    // sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
L_80033D10:
    // addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // sb          $v0, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r2;
    // sb          $v0, 0x25($a1)
    MEM_B(0X25, ctx->r5) = ctx->r2;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // sh          $v0, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r2;
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // sb          $t3, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r11;
    // sb          $t4, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r12;
    // sb          $t5, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r13;
    // sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // sh          $t7, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r15;
    // sb          $t0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r8;
    // sb          $t1, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r9;
    // sb          $v1, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r3;
    // sb          $t1, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r9;
    // sb          $t0, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r8;
    // sb          $v1, 0x24($a1)
    MEM_B(0X24, ctx->r5) = ctx->r3;
    // sh          $v0, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r2;
    // blez        $a0, L_80033D9C
    if (SIGNED(ctx->r4) <= 0) {
        // sh          $v0, 0x1A($a1)
        MEM_H(0X1A, ctx->r5) = ctx->r2;
        goto L_80033D9C;
    }
    // sh          $v0, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r2;
    // sltiu       $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 < 0X2000 ? 1 : 0;
    // beq         $v0, $zero, L_80033D9C
    if (ctx->r2 == 0) {
        // sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4) << 2;
        goto L_80033D9C;
    }
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x15C($v0)
    ctx->r2 = MEM_W(0X15C, ctx->r2);
    // jal         0x80067238
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
L_80033D9C:
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
