#include "recomp.h"
#include "disable_warnings.h"

void sub_800372AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // addiu       $s3, $s3, 0x7228
    ctx->r19 = ADD32(ctx->r19, 0X7228);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // ori         $s4, $zero, 0x7F
    ctx->r20 = 0 | 0X7F;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addiu       $s1, $s2, 0xE
    ctx->r17 = ADD32(ctx->r18, 0XE);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $s0, $s3, 0x5
    ctx->r16 = ADD32(ctx->r19, 0X5);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
L_800372E8:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // beq         $v0, $s5, L_80037394
    if (ctx->r2 == ctx->r21) {
        // nop
    
        goto L_80037394;
    }
    // nop

    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // lbu         $v0, -0xA($s1)
    ctx->r2 = MEM_BU(-0XA, ctx->r17);
    // nop

    // sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xC($s1)
    ctx->r2 = MEM_BU(-0XC, ctx->r17);
    // lbu         $a0, -0x3($s0)
    ctx->r4 = MEM_BU(-0X3, ctx->r16);
    // sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // lbu         $v0, -0xB($s1)
    ctx->r2 = MEM_BU(-0XB, ctx->r17);
    // nop

    // sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // lh          $v1, -0x2($s1)
    ctx->r3 = MEM_H(-0X2, ctx->r17);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x3($s0)
    MEM_W(0X3, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // lh          $v1, -0x4($s1)
    ctx->r3 = MEM_H(-0X4, ctx->r17);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xB($s0)
    MEM_W(0XB, ctx->r16) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $a1, 0x3($s0)
    ctx->r5 = MEM_W(0X3, ctx->r16);
    // lw          $a2, 0xB($s0)
    ctx->r6 = MEM_W(0XB, ctx->r16);
    // jal         0x8002E19C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    Map_GetCellData(rdram, ctx);
    goto after_0;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80062BF0
    // sw          $v0, 0x7($s0)
    MEM_W(0X7, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x7($s0)
    MEM_W(0X7, ctx->r16) = ctx->r2;
    after_1:
    // lbu         $v1, -0x2($s0)
    ctx->r3 = MEM_BU(-0X2, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // j           L_80037398
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    goto L_80037398;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_80037394:
    // sh          $s5, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r21;
L_80037398:
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s4, $v0, L_800372E8
    if (ctx->r20 != ctx->r2) {
        // addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
        goto L_800372E8;
    }
    // addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
