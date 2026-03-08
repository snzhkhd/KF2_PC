#include "recomp.h"
#include "disable_warnings.h"

void sub_800422B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // addiu       $s3, $s3, -0x19F8
    ctx->r19 = ADD32(ctx->r19, -0X19F8);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // ori         $s5, $zero, 0xC7
    ctx->r21 = 0 | 0XC7;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // ori         $s7, $zero, 0xFF
    ctx->r23 = 0 | 0XFF;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s3, 0x9
    ctx->r16 = ADD32(ctx->r19, 0X9);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $s4, 0xE
    ctx->r17 = ADD32(ctx->r20, 0XE);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
L_80042300:
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // nop

    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // nop

    // beq         $v0, $s7, L_80042438
    if (ctx->r2 == ctx->r23) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80042438;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lbu         $v0, -0xD($s1)
    ctx->r2 = MEM_BU(-0XD, ctx->r17);
    // sb          $zero, -0x5($s0)
    MEM_B(-0X5, ctx->r16) = 0;
    // sb          $v0, -0x7($s0)
    MEM_B(-0X7, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xC($s1)
    ctx->r2 = MEM_BU(-0XC, ctx->r17);
    // lbu         $v1, -0x7($s0)
    ctx->r3 = MEM_BU(-0X7, ctx->r16);
    // sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x7($s1)
    ctx->r2 = MEM_BU(-0X7, ctx->r17);
    // nop

    // sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xB($s1)
    ctx->r2 = MEM_BU(-0XB, ctx->r17);
    // nop

    // sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xA($s1)
    ctx->r2 = MEM_BU(-0XA, ctx->r17);
    // nop

    // sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // nop

    // sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // nop

    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lhu         $v0, -0x6($s1)
    ctx->r2 = MEM_HU(-0X6, ctx->r17);
    // nop

    // sh          $v0, 0x17($s0)
    MEM_H(0X17, ctx->r16) = ctx->r2;
    // lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(-0X4, ctx->r17);
    // nop

    // sh          $v0, 0x19($s0)
    MEM_H(0X19, ctx->r16) = ctx->r2;
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // sh          $v0, 0x1B($s0)
    MEM_H(0X1B, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // sb          $s7, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r23;
    // sw          $zero, 0x57($s0)
    MEM_W(0X57, ctx->r16) = 0;
    // sh          $v0, 0x1D($s0)
    MEM_H(0X1D, ctx->r16) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x46E8
    ctx->r3 = ADD32(ctx->r3, 0X46E8);
    // jal         0x8003B848
    // addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    Entity_LoadStats(rdram, ctx);
    goto after_0;
    // addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    after_0:
    // jal         0x8003B784
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    Entity_UpdatePhysics(rdram, ctx);
    goto after_1;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // lw          $v0, 0x1F($s0)
    ctx->r2 = MEM_W(0X1F, ctx->r16);
    // lbu         $v1, 0x9($s2)
    ctx->r3 = MEM_BU(0X9, ctx->r18);
    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8004243C
    if (ctx->r2 == 0) {
        // sb          $v1, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r3;
        goto L_8004243C;
    }
    // sb          $v1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // bne         $v1, $v0, L_8004242C
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8004242C;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // lh          $v0, 0x1B($s0)
    ctx->r2 = MEM_H(0X1B, ctx->r16);
    // nop

    // bne         $v0, $s6, L_80042410
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_80042410;
    }
    // nop

    // lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(0X1A, ctx->r18);
    // nop

    // sh          $v0, 0x1B($s0)
    MEM_H(0X1B, ctx->r16) = ctx->r2;
L_80042410:
    // lh          $v0, 0x1D($s0)
    ctx->r2 = MEM_H(0X1D, ctx->r16);
    // nop

    // bne         $v0, $s6, L_8004243C
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8004243C;
    }
    // nop

    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // j           L_8004243C
    // sh          $v0, 0x1D($s0)
    MEM_H(0X1D, ctx->r16) = ctx->r2;
    goto L_8004243C;
    // sh          $v0, 0x1D($s0)
    MEM_H(0X1D, ctx->r16) = ctx->r2;
L_8004242C:
    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // j           L_8004243C
    // sh          $zero, 0x1D($s0)
    MEM_H(0X1D, ctx->r16) = 0;
    goto L_8004243C;
    // sh          $zero, 0x1D($s0)
    MEM_H(0X1D, ctx->r16) = 0;
L_80042438:
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8004243C:
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // addiu       $s3, $s3, 0x7C
    ctx->r19 = ADD32(ctx->r19, 0X7C);
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_80042300
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80042300;
    }
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
