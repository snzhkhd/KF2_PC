#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D8E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // lw          $s2, 0x79B4($s2)
    ctx->r18 = MEM_W(0X79B4, ctx->r18);
    // bne         $v0, $zero, L_8003D93C
    if (ctx->r2 != 0) {
        // addu        $fp, $a1, $zero
        ctx->r30 = ADD32(ctx->r5, 0);
        goto L_8003D93C;
    }
    // addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(0X4, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8003DD7C
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8003DD7C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003D93C:
    // lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(0X28, ctx->r29);
    // sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // lh          $s3, 0x0($t0)
    ctx->r19 = MEM_H(0X0, ctx->r8);
    // lh          $s0, 0x4($t0)
    ctx->r16 = MEM_H(0X4, ctx->r8);
    // addu        $s7, $s3, $zero
    ctx->r23 = ADD32(ctx->r19, 0);
    // addu        $s6, $s0, $zero
    ctx->r22 = ADD32(ctx->r16, 0);
L_8003D95C:
    // lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(0X2C, ctx->r18);
    // nop

    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(0X34, ctx->r18);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lhu         $a3, 0x1C($s2)
    ctx->r7 = MEM_HU(0X1C, ctx->r18);
    // lhu         $v1, 0x1E($s2)
    ctx->r3 = MEM_HU(0X1E, ctx->r18);
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(0X30, ctx->r18);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // bne         $s5, $zero, L_8003DB14
    if (ctx->r21 != 0) {
        // andi        $v0, $fp, 0x3
        ctx->r2 = ctx->r30 & 0X3;
        goto L_8003DB14;
    }
    // andi        $v0, $fp, 0x3
    ctx->r2 = ctx->r30 & 0X3;
L_8003D9C0:
    // lbu         $v0, 0xD($s2)
    ctx->r2 = MEM_BU(0XD, ctx->r18);
    // nop

    // bne         $v0, $zero, L_8003DAFC
    if (ctx->r2 != 0) {
        // andi        $v0, $fp, 0x24
        ctx->r2 = ctx->r30 & 0X24;
        goto L_8003DAFC;
    }
    // andi        $v0, $fp, 0x24
    ctx->r2 = ctx->r30 & 0X24;
    // beq         $v0, $zero, L_8003DAFC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DAFC;
    }
    // nop

    // lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // lw          $s4, -0x2A7C($s4)
    ctx->r20 = MEM_W(-0X2A7C, ctx->r20);
    // beq         $s3, $zero, L_8003DA0C
    if (ctx->r19 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8003DA0C;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // blez        $s3, L_8003D9FC
    if (SIGNED(ctx->r19) <= 0) {
        // nop
    
        goto L_8003D9FC;
    }
    // nop

    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // j           L_8003DA0C
    // sll         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2) << 1;
    goto L_8003DA0C;
    // sll         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2) << 1;
L_8003D9FC:
    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2) << 1;
L_8003DA0C:
    // beq         $s0, $zero, L_8003DA38
    if (ctx->r16 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8003DA38;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // blez        $s0, L_8003DA28
    if (SIGNED(ctx->r16) <= 0) {
        // nop
    
        goto L_8003DA28;
    }
    // nop

    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // j           L_8003DA38
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_8003DA38;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_8003DA28:
    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_8003DA38:
    // lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(0X34, ctx->r18);
    // lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(0X28, ctx->r18);
    // lhu         $a3, 0x1C($s2)
    ctx->r7 = MEM_HU(0X1C, ctx->r18);
    // addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // lhu         $v0, 0x1E($s2)
    ctx->r2 = MEM_HU(0X1E, ctx->r18);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(0X30, ctx->r18);
    // jal         0x8002E318
    // nop

    CollisionWithTilemap(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A7C($v1)
    ctx->r3 = MEM_W(-0X2A7C, ctx->r3);
    // nop

    // slt         $v0, $s4, $v1
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003DA88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DA88;
    }
    // nop

    // addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_8003DA88:
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(0X28, ctx->r18);
    // lhu         $v0, 0x1E($s2)
    ctx->r2 = MEM_HU(0X1E, ctx->r18);
    // lhu         $a3, 0x1C($s2)
    ctx->r7 = MEM_HU(0X1C, ctx->r18);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(0X30, ctx->r18);
    // lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(0X34, ctx->r18);
    // jal         0x8002E318
    // addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    CollisionWithTilemap(rdram, ctx);
    goto after_2;
    // addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_2:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A7C($v1)
    ctx->r3 = MEM_W(-0X2A7C, ctx->r3);
    // nop

    // slt         $v0, $s4, $v1
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003DAD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DAD4;
    }
    // nop

    // addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_8003DAD4:
    // lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(0X30, ctx->r18);
    // addiu       $v1, $s4, -0x44C
    ctx->r3 = ADD32(ctx->r20, -0X44C);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003DAFC
    if (ctx->r2 == 0) {
        // andi        $v0, $fp, 0x4
        ctx->r2 = ctx->r30 & 0X4;
        goto L_8003DAFC;
    }
    // andi        $v0, $fp, 0x4
    ctx->r2 = ctx->r30 & 0X4;
    // lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(0X48, ctx->r29);
    // nop

    // ori         $t0, $t0, 0x100
    ctx->r8 = ctx->r8 | 0X100;
    // bne         $v0, $zero, L_8003DC4C
    if (ctx->r2 != 0) {
        // sw          $t0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r8;
        goto L_8003DC4C;
    }
    // sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
L_8003DAFC:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // sw          $v0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r2;
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // j           L_8003DD5C
    // sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
    goto L_8003DD5C;
    // sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
L_8003DB14:
    // lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(0X48, ctx->r29);
    // nop

    // or          $t0, $t0, $s5
    ctx->r8 = ctx->r8 | ctx->r21;
    // beq         $v0, $zero, L_8003DD5C
    if (ctx->r2 == 0) {
        // sw          $t0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r8;
        goto L_8003DD5C;
    }
    // sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // andi        $v0, $s5, 0xB0
    ctx->r2 = ctx->r21 & 0XB0;
    // beq         $v0, $zero, L_8003DBF4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003DBF4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(0X40, ctx->r29);
    // nop

    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // beq         $t0, $v0, L_8003DD5C
    if (ctx->r8 == ctx->r2) {
        // sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
        goto L_8003DD5C;
    }
    // sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // jal         0x8002E394
    // nop

    sub_8002E394(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A5C($v1)
    ctx->r3 = MEM_W(-0X2A5C, ctx->r3);
    // lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(0X2C, ctx->r18);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A54($v0)
    ctx->r2 = MEM_W(-0X2A54, ctx->r2);
    // lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(0X34, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_4;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_4:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80015804
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_5;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // jal         0x800157D4
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_800157D4(rdram, ctx);
    goto after_6;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_6:
    // bne         $v0, $zero, L_8003DBA4
    if (ctx->r2 != 0) {
        // addiu       $v0, $s1, 0x400
        ctx->r2 = ADD32(ctx->r17, 0X400);
        goto L_8003DBA4;
    }
    // addiu       $v0, $s1, 0x400
    ctx->r2 = ADD32(ctx->r17, 0X400);
    // addiu       $v0, $s1, -0x400
    ctx->r2 = ADD32(ctx->r17, -0X400);
L_8003DBA4:
    // andi        $s1, $v0, 0xFFF
    ctx->r17 = ctx->r2 & 0XFFF;
    // mult        $s3, $s3
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    KF_SquareRoot0(rdram, ctx);
    goto after_7;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_7:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800601F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    FixedSin(rdram, ctx);
    goto after_8;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_8:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // mflo        $v0
    ctx->r2 = lo;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x800602D0
    // sra         $s3, $v0, 13
    ctx->r19 = S32(ctx->r2) >> 13;
    FixedCos(rdram, ctx);
    goto after_9;
    // sra         $s3, $v0, 13
    ctx->r19 = S32(ctx->r2) >> 13;
    after_9:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8003D95C
    // sra         $s0, $v0, 13
    ctx->r16 = S32(ctx->r2) >> 13;
    goto L_8003D95C;
    // sra         $s0, $v0, 13
    ctx->r16 = S32(ctx->r2) >> 13;
L_8003DBF4:
    // andi        $v0, $fp, 0x10
    ctx->r2 = ctx->r30 & 0X10;
    // bne         $v0, $zero, L_8003DC44
    if (ctx->r2 != 0) {
        // andi        $v0, $s5, 0x1
        ctx->r2 = ctx->r21 & 0X1;
        goto L_8003DC44;
    }
    // andi        $v0, $s5, 0x1
    ctx->r2 = ctx->r21 & 0X1;
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // bne         $v0, $zero, L_8003DC4C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x6
        ctx->r2 = ADD32(0, -0X6);
        goto L_8003DC4C;
    }
    // addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
    // and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // bne         $v0, $zero, L_8003DC44
    if (ctx->r2 != 0) {
        // andi        $v0, $s5, 0x1
        ctx->r2 = ctx->r21 & 0X1;
        goto L_8003DC44;
    }
    // andi        $v0, $s5, 0x1
    ctx->r2 = ctx->r21 & 0X1;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(0X30, ctx->r18);
    // addiu       $v0, $v0, 0x320
    ctx->r2 = ADD32(ctx->r2, 0X320);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003D9C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003D9C0;
    }
    // nop

    // j           L_8003DC4C
    // nop

    goto L_8003DC4C;
    // nop

L_8003DC44:
    // beq         $v0, $zero, L_8003DCF4
    if (ctx->r2 == 0) {
        // andi        $v0, $s5, 0x2
        ctx->r2 = ctx->r21 & 0X2;
        goto L_8003DCF4;
    }
    // andi        $v0, $s5, 0x2
    ctx->r2 = ctx->r21 & 0X2;
L_8003DC4C:
    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // nop

    // beq         $t0, $zero, L_8003DC68
    if (ctx->r8 == 0) {
        // nop
    
        goto L_8003DC68;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // j           L_8003DD5C
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    goto L_8003DD5C;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_8003DC68:
    // beq         $s3, $zero, L_8003DCA8
    if (ctx->r19 == 0) {
        // andi        $v0, $fp, 0x1
        ctx->r2 = ctx->r30 & 0X1;
        goto L_8003DCA8;
    }
    // andi        $v0, $fp, 0x1
    ctx->r2 = ctx->r30 & 0X1;
    // beq         $v0, $zero, L_8003DCA0
    if (ctx->r2 == 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_8003DCA0;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // mult        $s7, $s7
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // mult        $s6, $s6
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    KF_SquareRoot0(rdram, ctx);
    goto after_10;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_10:
    // bgtz        $s6, L_8003D95C
    if (SIGNED(ctx->r22) > 0) {
        // addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
        goto L_8003D95C;
    }
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // j           L_8003D95C
    // negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    goto L_8003D95C;
    // negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_8003DCA0:
    // j           L_8003D95C
    // addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
    goto L_8003D95C;
    // addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
L_8003DCA8:
    // beq         $s0, $zero, L_8003DCF0
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8003DCF0;
    }
    // nop

    // beq         $v0, $zero, L_8003DCE0
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003DCE0;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // mult        $s7, $s7
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // mult        $s6, $s6
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    KF_SquareRoot0(rdram, ctx);
    goto after_11;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_11:
    // bgtz        $s7, L_8003DCE4
    if (SIGNED(ctx->r23) > 0) {
        // addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
        goto L_8003DCE4;
    }
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // j           L_8003DCE4
    // negu        $s3, $s3
    ctx->r19 = SUB32(0, ctx->r19);
    goto L_8003DCE4;
    // negu        $s3, $s3
    ctx->r19 = SUB32(0, ctx->r19);
L_8003DCE0:
    // addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
L_8003DCE4:
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // j           L_8003D95C
    // sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    goto L_8003D95C;
    // sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_8003DCF0:
    // andi        $v0, $s5, 0x2
    ctx->r2 = ctx->r21 & 0X2;
L_8003DCF4:
    // beq         $v0, $zero, L_8003DD5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DD5C;
    }
    // nop

    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // nop

    // bne         $t0, $zero, L_8003DC4C
    if (ctx->r8 != 0) {
        // nop
    
        goto L_8003DC4C;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A88($v0)
    ctx->r2 = MEM_W(-0X2A88, ctx->r2);
    // nop

    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // nop

    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $zero, L_8003DD38
    if (ctx->r3 == 0) {
        // ori         $t0, $zero, 0x1
        ctx->r8 = 0 | 0X1;
        goto L_8003DD38;
    }
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $v0, L_8003DD48
    if (ctx->r3 != ctx->r2) {
        // subu        $v0, $s7, $s6
        ctx->r2 = SUB32(ctx->r23, ctx->r22);
        goto L_8003DD48;
    }
    // subu        $v0, $s7, $s6
    ctx->r2 = SUB32(ctx->r23, ctx->r22);
L_8003DD38:
    // addu        $v0, $s7, $s6
    ctx->r2 = ADD32(ctx->r23, ctx->r22);
    // sra         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) >> 1;
    // j           L_8003DD54
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    goto L_8003DD54;
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
L_8003DD48:
    // sra         $s3, $v0, 1
    ctx->r19 = S32(ctx->r2) >> 1;
    // negu        $s0, $s3
    ctx->r16 = SUB32(0, ctx->r19);
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
L_8003DD54:
    // j           L_8003D95C
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    goto L_8003D95C;
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_8003DD5C:
    // andi        $v0, $fp, 0x8
    ctx->r2 = ctx->r30 & 0X8;
    // beq         $v0, $zero, L_8003DD78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DD78;
    }
    // nop

    // lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(0X28, ctx->r29);
    // nop

    // sh          $s3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r19;
    // sh          $s0, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r16;
L_8003DD78:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
L_8003DD7C:
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
