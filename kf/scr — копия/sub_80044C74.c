#include "recomp.h"
#include "disable_warnings.h"

void sub_80044C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // lw          $s0, 0x1184($s0)
    ctx->r16 = MEM_W(0X1184, ctx->r16);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // lh          $v0, 0x34($s0)
    ctx->r2 = MEM_H(0X34, ctx->r16);
    // lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(0X14, ctx->r16);
    // lw          $a3, 0x18($s0)
    ctx->r7 = MEM_W(0X18, ctx->r16);
    // lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(0X1C, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(0X36, ctx->r16);
    // lh          $v1, 0x38($s0)
    ctx->r3 = MEM_H(0X38, ctx->r16);
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // jal         0x800424C8
    // sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    sub_800424C8(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    after_0:
    // lbu         $v1, 0xD($s0)
    ctx->r3 = MEM_BU(0XD, ctx->r16);
    // nop

    // beq         $v1, $zero, L_80044DA8
    if (ctx->r3 == 0) {
        // addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
        goto L_80044DA8;
    }
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 17
    ctx->r3 = S32(ctx->r2) >> 17;
    // sh          $v1, 0x1A8($gp)
    MEM_H(0X1A8, ctx->r28) = ctx->r3;
    // lhu         $v0, 0x36($s0)
    ctx->r2 = MEM_HU(0X36, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 17
    ctx->r6 = S32(ctx->r2) >> 17;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $a2, 0x646A($at)
    MEM_H(0X646A, ctx->r1) = ctx->r6;
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 17
    ctx->r7 = S32(ctx->r2) >> 17;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $a3, 0x646C($at)
    MEM_H(0X646C, ctx->r1) = ctx->r7;
    // bne         $a1, $zero, L_80044DA8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80044DA8;
    }
    // nop

    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // jal         0x800424C8
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_800424C8(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // beq         $a1, $zero, L_80044DA8
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80044DA8;
    }
    // nop

    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // nop

    // sh          $v0, 0x1A8($gp)
    MEM_H(0X1A8, ctx->r28) = ctx->r2;
    // lhu         $v0, 0x36($s0)
    ctx->r2 = MEM_HU(0X36, ctx->r16);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, 0x646A($at)
    MEM_H(0X646A, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, 0x646C($at)
    MEM_H(0X646C, ctx->r1) = ctx->r2;
L_80044DA8:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x2A82($v0)
    ctx->r2 = MEM_HU(-0X2A82, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80044DC0
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_80044DC0;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_80044DC0:
    // lhu         $v1, 0x28($s0)
    ctx->r3 = MEM_HU(0X28, ctx->r16);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // sb          $a0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r4;
    // subu        $v1, $v1, $s3
    ctx->r3 = SUB32(ctx->r3, ctx->r19);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
