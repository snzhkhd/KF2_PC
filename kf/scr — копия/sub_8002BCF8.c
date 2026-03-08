#include "recomp.h"
#include "disable_warnings.h"

void sub_8002BCF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s2, $s2, -0x4A6F
    ctx->r18 = ADD32(ctx->r18, -0X4A6F);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8002BEB4
    if (ctx->r3 != ctx->r2) {
        // addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
        goto L_8002BEB4;
    }
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // lbu         $a0, 0x83($s2)
    ctx->r4 = MEM_BU(0X83, ctx->r18);
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // subu        $v1, $s1, $v1
    ctx->r3 = SUB32(ctx->r17, ctx->r3);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2) << 8;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) << 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // bne         $a0, $v0, L_8002BEB4
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8002BEB4;
    }
    // nop

    // lw          $a2, 0x40($s1)
    ctx->r6 = MEM_W(0X40, ctx->r17);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A44($v0)
    ctx->r2 = MEM_HU(-0X4A44, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A34($v1)
    ctx->r3 = MEM_HU(-0X4A34, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4A32($a0)
    ctx->r4 = MEM_HU(-0X4A32, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4A30($a1)
    ctx->r5 = MEM_HU(-0X4A30, ctx->r5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A34($at)
    MEM_H(-0X4A34, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = 0;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A42($v0)
    ctx->r2 = MEM_HU(-0X4A42, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A40($v1)
    ctx->r3 = MEM_HU(-0X4A40, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A42($at)
    MEM_H(-0X4A42, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4A40($at)
    MEM_H(-0X4A40, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8002BE44
    if (ctx->r2 != 0) {
        // addiu       $s0, $sp, 0x18
        ctx->r16 = ADD32(ctx->r29, 0X18);
        goto L_8002BE44;
    }
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // lh          $v1, 0xC($a2)
    ctx->r3 = MEM_H(0XC, ctx->r6);
    // lh          $v0, 0x38($a2)
    ctx->r2 = MEM_H(0X38, ctx->r6);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lh          $v1, 0xE($a2)
    ctx->r3 = MEM_H(0XE, ctx->r6);
    // lh          $v0, 0x38($a2)
    ctx->r2 = MEM_H(0X38, ctx->r6);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, 0X200);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lh          $v1, 0x10($a2)
    ctx->r3 = MEM_H(0X10, ctx->r6);
    // lh          $v0, 0x38($a2)
    ctx->r2 = MEM_H(0X38, ctx->r6);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // jal         0x8002BF24
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    sub_8002BF24(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    after_0:
    // j           L_8002BEB4
    // nop

    goto L_8002BEB4;
    // nop

L_8002BE44:
    // lhu         $a0, 0x26($s1)
    ctx->r4 = MEM_HU(0X26, ctx->r17);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80014FAC
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80014FAC(rdram, ctx);
    goto after_1;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_1:
    // ori         $a0, $zero, 0x384
    ctx->r4 = 0 | 0X384;
    // jal         0x8001565C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8001565C(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // sb          $zero, 0x83($s2)
    MEM_B(0X83, ctx->r18) = 0;
    // lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(0X14, ctx->r17);
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49E8($at)
    MEM_W(-0X49E8, ctx->r1) = ctx->r2;
    // lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(0X1C, ctx->r17);
    // lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(0X1C, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49E0($at)
    MEM_W(-0X49E0, ctx->r1) = ctx->r2;
    // lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(0X18, ctx->r17);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x49E4($at)
    MEM_W(-0X49E4, ctx->r1) = ctx->r2;
L_8002BEB4:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
