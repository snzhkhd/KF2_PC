#include "recomp.h"
#include "disable_warnings.h"

void Entity_UpdateDetection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // addiu       $s5, $s5, 0x79B4
    ctx->r21 = ADD32(ctx->r21, 0X79B4);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(0X0, ctx->r21);
    // lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // lw          $s3, 0x79B0($s3)
    ctx->r19 = MEM_W(0X79B0, ctx->r19);
    // lbu         $v1, 0x9($s0)
    ctx->r3 = MEM_BU(0X9, ctx->r16);
    // lbu         $s4, 0x0($s0)
    ctx->r20 = MEM_BU(0X0, ctx->r16);
    // beq         $v1, $s1, L_8003C4E0
    if (ctx->r3 == ctx->r17) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003C4E0;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003C314
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C314;
    }
    // nop

    // beq         $v1, $zero, L_8003C328
    if (ctx->r3 == 0) {
        // addiu       $a0, $s0, 0x2C
        ctx->r4 = ADD32(ctx->r16, 0X2C);
        goto L_8003C328;
    }
    // addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // j           L_8003C5B4
    // nop

    goto L_8003C5B4;
    // nop

L_8003C314:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_8003C53C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $s4, -0x3
        ctx->r2 = ADD32(ctx->r20, -0X3);
        goto L_8003C53C;
    }
    // addiu       $v0, $s4, -0x3
    ctx->r2 = ADD32(ctx->r20, -0X3);
    // j           L_8003C5B4
    // nop

    goto L_8003C5B4;
    // nop

L_8003C328:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A64($a1)
    ctx->r5 = MEM_W(-0X4A64, ctx->r5);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4A5C($a3)
    ctx->r7 = MEM_W(-0X4A5C, ctx->r7);
    // lbu         $v0, 0xA($s3)
    ctx->r2 = MEM_BU(0XA, ctx->r19);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // jal         0x80015A88
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    GetDistanceIfInRange(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_8003C5B4
    if (ctx->r18 == ctx->r2) {
        // addiu       $v0, $s4, -0x3
        ctx->r2 = ADD32(ctx->r20, -0X3);
        goto L_8003C5B4;
    }
    // addiu       $v0, $s4, -0x3
    ctx->r2 = ADD32(ctx->r20, -0X3);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003C3A4
    if (ctx->r2 == 0) {
        // andi        $v1, $s4, 0xFF
        ctx->r3 = ctx->r20 & 0XFF;
        goto L_8003C3A4;
    }
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79BC($v0)
    ctx->r2 = MEM_W(0X79BC, ctx->r2);
    // nop

    // lbu         $v0, 0x9($v0)
    ctx->r2 = MEM_BU(0X9, ctx->r2);
    // nop

    // bne         $v0, $s1, L_8003C5B4
    if (ctx->r2 != ctx->r17) {
        // nop
    
        goto L_8003C5B4;
    }
    // nop

    // lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(0X0, ctx->r21);
    // jal         0x8003BA7C
    // nop

    Entity_Alert(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8003C4B8
    // nop

    goto L_8003C4B8;
    // nop

L_8003C3A4:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $v0, L_8003C3E0
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8003C3E0;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $s1, 0xA($s0)
    ctx->r17 = MEM_BU(0XA, ctx->r16);
    // nop

    // beq         $s1, $v0, L_8003C444
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003C444;
    }
    // nop

    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003C444
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C444;
    }
    // nop

    // j           L_8003C5B4
    // nop

    goto L_8003C5B4;
    // nop

L_8003C3E0:
    // lbu         $v0, 0xA($s3)
    ctx->r2 = MEM_BU(0XA, ctx->r19);
    // nop

    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003C40C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C40C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4B32($v0)
    ctx->r2 = MEM_BU(-0X4B32, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8003C4C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C4C8;
    }
    // nop

L_8003C40C:
    // beq         $v1, $s1, L_8003C444
    if (ctx->r3 == ctx->r17) {
        // nop
    
        goto L_8003C444;
    }
    // nop

    // bne         $v1, $zero, L_8003C4C8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003C4C8;
    }
    // nop

    // lbu         $s1, 0xA($s0)
    ctx->r17 = MEM_BU(0XA, ctx->r16);
    // nop

    // beq         $s1, $zero, L_8003C4CC
    if (ctx->r17 == 0) {
        // andi        $v1, $s4, 0xFF
        ctx->r3 = ctx->r20 & 0XFF;
        goto L_8003C4CC;
    }
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003C4CC
    if (ctx->r2 != 0) {
        // andi        $v1, $s4, 0xFF
        ctx->r3 = ctx->r20 & 0XFF;
        goto L_8003C4CC;
    }
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
L_8003C444:
    // lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(0X14, ctx->r19);
    // lhu         $a3, 0x12($s3)
    ctx->r7 = MEM_HU(0X12, ctx->r19);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(0X30, ctx->r16);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // jal         0x8003D480
    // nop

    Entity_CheckWorldCollision(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8003C4CC
    if (ctx->r2 != ctx->r3) {
        // andi        $v1, $s4, 0xFF
        ctx->r3 = ctx->r20 & 0XFF;
        goto L_8003C4CC;
    }
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, 0x79B4($a0)
    ctx->r4 = MEM_W(0X79B4, ctx->r4);
    // jal         0x8003BA7C
    // nop

    Entity_Alert(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8003C184
    // ori         $a1, $zero, 0x15
    ctx->r5 = 0 | 0X15;
    EntityClass_GetActionSequence(rdram, ctx);
    goto after_6;
    // ori         $a1, $zero, 0x15
    ctx->r5 = 0 | 0X15;
    after_6:
    // bne         $v0, $zero, L_8003C4A8
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003C4A8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8003C184
    // ori         $a1, $zero, 0x1A
    ctx->r5 = 0 | 0X1A;
    EntityClass_GetActionSequence(rdram, ctx);
    goto after_7;
    // ori         $a1, $zero, 0x1A
    ctx->r5 = 0 | 0X1A;
    after_7:
    // beq         $v0, $zero, L_8003C4B8
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003C4B8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8003C4A8:
    // jal         0x8003BB60
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    Entity_ApplySequence(rdram, ctx);
    goto after_8;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_8:
    // j           L_8003C5B4
    // nop

    goto L_8003C5B4;
    // nop

L_8003C4B8:
    // jal         0x8003C038
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    Entity_SelectAction(rdram, ctx);
    goto after_9;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_9:
    // j           L_8003C5B4
    // nop

    goto L_8003C5B4;
    // nop

L_8003C4C8:
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
L_8003C4CC:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_8003C5B4
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8003C5B4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_8003C5B4
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    goto L_8003C5B4;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
L_8003C4E0:
    // addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A64($a1)
    ctx->r5 = MEM_W(-0X4A64, ctx->r5);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4A5C($a3)
    ctx->r7 = MEM_W(-0X4A5C, ctx->r7);
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // jal         0x80015A88
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    GetDistanceIfInRange(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8003C5B4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8003C5B4;
    }
    // nop

    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(0X34, ctx->r16);
    // lhu         $a2, 0x1C($s0)
    ctx->r6 = MEM_HU(0X1C, ctx->r16);
    // jal         0x8002E25C
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_11;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_11:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_8003C5AC
    // sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    goto L_8003C5AC;
    // sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
L_8003C53C:
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003C56C
    if (ctx->r2 == 0) {
        // addiu       $a0, $s0, 0x2C
        ctx->r4 = ADD32(ctx->r16, 0X2C);
        goto L_8003C56C;
    }
    // addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79BC($v0)
    ctx->r2 = MEM_W(0X79BC, ctx->r2);
    // nop

    // lbu         $v0, 0x9($v0)
    ctx->r2 = MEM_BU(0X9, ctx->r2);
    // nop

    // beq         $v0, $s1, L_8003C5B4
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_8003C5B4;
    }
    // nop

    // j           L_8003C5A8
    // sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
    goto L_8003C5A8;
    // sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
L_8003C56C:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A64($a1)
    ctx->r5 = MEM_W(-0X4A64, ctx->r5);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4A5C($a3)
    ctx->r7 = MEM_W(-0X4A5C, ctx->r7);
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // jal         0x80015A88
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    GetDistanceIfInRange(rdram, ctx);
    goto after_12;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8003C5B4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8003C5B4;
    }
    // nop

    // sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
L_8003C5A8:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8003C5AC:
    // jal         0x8003B784
    // nop

    Entity_UpdatePhysics(rdram, ctx);
    goto after_13;
    // nop

    after_13:
L_8003C5B4:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
