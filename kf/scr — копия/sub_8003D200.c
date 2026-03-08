#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(0X98, ctx->r29);
    // sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(0XA4, ctx->r29);
    // sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // ori         $s7, $zero, 0x7530
    ctx->r23 = 0 | 0X7530;
    // sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // addiu       $s4, $s4, -0x19F8
    ctx->r20 = ADD32(ctx->r20, -0X19F8);
    // sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(0X9C, ctx->r29);
    // ori         $s6, $zero, 0xC7
    ctx->r22 = 0 | 0XC7;
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(0XA0, ctx->r29);
    // addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // sh          $a1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r5;
    // sh          $a2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r6;
    // sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
L_8003D274:
    // lbu         $v1, 0x9($s1)
    ctx->r3 = MEM_BU(0X9, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8003D424
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8003D424;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lbu         $v1, 0xE($s1)
    ctx->r3 = MEM_BU(0XE, ctx->r17);
    // nop

    // beq         $v1, $v0, L_8003D424
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003D424;
    }
    // nop

    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79B4($v0)
    ctx->r2 = MEM_W(0X79B4, ctx->r2);
    // nop

    // beq         $s4, $v0, L_8003D424
    if (ctx->r20 == ctx->r2) {
        // lui         $t0, 0x2
        ctx->r8 = S32(0X2 << 16);
        goto L_8003D424;
    }
    // lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(0X28, ctx->r17);
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // beq         $v0, $zero, L_8003D2C0
    if (ctx->r2 == 0) {
        // addiu       $a0, $s4, 0x2C
        ctx->r4 = ADD32(ctx->r20, 0X2C);
        goto L_8003D2C0;
    }
    // addiu       $a0, $s4, 0x2C
    ctx->r4 = ADD32(ctx->r20, 0X2C);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
L_8003D2C0:
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(0X0, ctx->r19);
    // lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(0X8, ctx->r19);
    // jal         0x80015A88
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    GetDistanceIfInRange(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_8003D424
    if (ctx->r18 == ctx->r2) {
        // addiu       $a3, $sp, 0x20
        ctx->r7 = ADD32(ctx->r29, 0X20);
        goto L_8003D424;
    }
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(0X2C, ctx->r17);
    // lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(0X0, ctx->r19);
    // lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(0X30, ctx->r17);
    // lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(0X4, ctx->r19);
    // lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(0X8, ctx->r19);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(0X34, ctx->r17);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x800159DC
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    Math_VectorToAngles(rdram, ctx);
    goto after_1;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_1:
    // lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(0X22, ctx->r29);
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // nop

    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003D340
    if (ctx->r2 != 0) {
        // sh          $v1, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r3;
        goto L_8003D340;
    }
    // sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
L_8003D340:
    // lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(0X20, ctx->r29);
    // lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(0X30, ctx->r29);
    // nop

    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003D36C
    if (ctx->r2 != 0) {
        // sh          $v1, 0x20($sp)
        MEM_H(0X20, ctx->r29) = ctx->r3;
        goto L_8003D36C;
    }
    // sh          $v1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r3;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
L_8003D36C:
    // lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(0X28, ctx->r17);
    // lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // beq         $v0, $zero, L_8003D3A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003D3A8;
    }
    // nop

    // bltz        $s5, L_8003D3A8
    if (SIGNED(ctx->r21) < 0) {
        // nop
    
        goto L_8003D3A8;
    }
    // nop

    // sra         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18) >> 2;
    // lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(0X20, ctx->r29);
    // lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(0X22, ctx->r29);
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // j           L_8003D3D8
    // sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    goto L_8003D3D8;
    // sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
L_8003D3A8:
    // lh          $v0, 0x22($sp)
    ctx->r2 = MEM_H(0X22, ctx->r29);
    // lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(0X40, ctx->r29);
    // nop

    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003D424
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003D424;
    }
    // nop

    // lh          $v0, 0x20($sp)
    ctx->r2 = MEM_H(0X20, ctx->r29);
    // lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(0X48, ctx->r29);
    // nop

    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003D424
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003D424;
    }
    // nop

L_8003D3D8:
    // lh          $v0, 0x22($sp)
    ctx->r2 = MEM_H(0X22, ctx->r29);
    // lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(0X20, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v1, $s2, 7
    ctx->r3 = S32(ctx->r18) >> 7;
    // blez        $s5, L_8003D40C
    if (SIGNED(ctx->r21) <= 0) {
        // addu        $s0, $v0, $v1
        ctx->r16 = ADD32(ctx->r2, ctx->r3);
        goto L_8003D40C;
    }
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_8003D40C:
    // slt         $v0, $s0, $s7
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r23) ? 1 : 0;
    // beq         $v0, $zero, L_8003D424
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003D424;
    }
    // nop

    // addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    // sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // addu        $fp, $s2, $zero
    ctx->r30 = ADD32(ctx->r18, 0);
L_8003D424:
    // addiu       $s1, $s1, 0x7C
    ctx->r17 = ADD32(ctx->r17, 0X7C);
    // addiu       $s4, $s4, 0x7C
    ctx->r20 = ADD32(ctx->r20, 0X7C);
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_8003D274
    if (ctx->r2 != 0) {
        // addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8003D274;
    }
    // addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(0X50, ctx->r29);
    // nop

    // sw          $fp, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r30;
    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(0X84, ctx->r29);
    // lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(0X80, ctx->r29);
    // lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(0X7C, ctx->r29);
    // lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(0X78, ctx->r29);
    // lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(0X74, ctx->r29);
    // lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(0X70, ctx->r29);
    // lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // jr          $ra
    // nop

    return;
    // nop

;}
