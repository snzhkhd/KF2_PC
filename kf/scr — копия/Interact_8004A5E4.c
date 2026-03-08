#include "recomp.h"
#include "disable_warnings.h"

void Interact_8004A5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $v0, $v0, 0x1F4
    ctx->r2 = ADD32(ctx->r2, 0X1F4);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $zero, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = 0;
    // jal         0x800487AC
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    IsFacingFountainTile(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // beq         $v0, $zero, L_8004A6A0
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x400
        ctx->r4 = 0 | 0X400;
        goto L_8004A6A0;
    }
    // ori         $a0, $zero, 0x400
    ctx->r4 = 0 | 0X400;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA0
    ctx->r2 = 0 | 0XA0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // jal         0x80049DE4
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80049DE4(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // ori         $a0, $zero, 0x400
    ctx->r4 = 0 | 0X400;
    // ori         $a1, $zero, 0x80
    ctx->r5 = 0 | 0X80;
    // ori         $a2, $zero, 0xA0
    ctx->r6 = 0 | 0XA0;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2A($v0)
    ctx->r2 = MEM_HU(-0X4B2A, ctx->r2);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B28($at)
    MEM_H(-0X4B28, ctx->r1) = ctx->r2;
    // jal         0x80049DE4
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    sub_80049DE4(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    after_2:
L_8004A6A0:
    // ori         $v0, $zero, 0xC80
    ctx->r2 = 0 | 0XC80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(0X24, ctx->r29);
    // lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(0X28, ctx->r29);
    // jal         0x8003D480
    // ori         $a3, $zero, 0x578
    ctx->r7 = 0 | 0X578;
    Entity_CheckWorldCollision(rdram, ctx);
    goto after_3;
    // ori         $a3, $zero, 0x578
    ctx->r7 = 0 | 0X578;
    after_3:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_8004A724
    if (ctx->r18 == ctx->r2) {
        // ori         $s5, $zero, 0x1
        ctx->r21 = 0 | 0X1;
        goto L_8004A724;
    }
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    // sll         $v0, $s2, 5
    ctx->r2 = S32(ctx->r18) << 5;
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(0X28, ctx->r29);
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
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(0X2, ctx->r20);
    // jal         0x80015798
    // ori         $a2, $zero, 0x12C
    ctx->r6 = 0 | 0X12C;
    Math_IsAngleInRange(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0x12C
    ctx->r6 = 0 | 0X12C;
    after_5:
    // beq         $v0, $zero, L_8004A728
    if (ctx->r2 == 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8004A728;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // jal         0x80048C30
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    InteractWithObj(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_8004A724:
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8004A728:
    // lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // addiu       $s6, $s6, -0x6810
    ctx->r22 = ADD32(ctx->r22, -0X6810);
    // addiu       $s7, $s6, -0x1E00
    ctx->r23 = ADD32(ctx->r22, -0X1E00);
    // ori         $s3, $zero, 0xFF
    ctx->r19 = 0 | 0XFF;
L_8004A738:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8004A73C:
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // ori         $a3, $zero, 0x9C4
    ctx->r7 = 0 | 0X9C4;
    // lh          $v0, 0x2($s4)
    ctx->r2 = MEM_H(0X2, ctx->r20);
    // ori         $v1, $zero, 0x200
    ctx->r3 = 0 | 0X200;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80038C0C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FindInteractableInCone(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_8004AC10
    if (ctx->r18 == ctx->r2) {
        // sll         $v0, $s2, 4
        ctx->r2 = S32(ctx->r18) << 4;
        goto L_8004AC10;
    }
    // sll         $v0, $s2, 4
    ctx->r2 = S32(ctx->r18) << 4;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
    // lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(0X6, ctx->r17);
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $s5, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r21;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // beq         $v1, $v0, L_8004AB84
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x13
        ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
        goto L_8004AB84;
    }
    // slti        $v0, $v1, 0x13
    ctx->r2 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
    // beq         $v0, $zero, L_8004A830
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x8
        ctx->r2 = 0 | 0X8;
        goto L_8004A830;
    }
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // beq         $v1, $v0, L_8004AA68
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x9
        ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
        goto L_8004AA68;
    }
    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8004A7F0
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_8004A7F0;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8004A7DC
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
        goto L_8004A7DC;
    }
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_8004A990
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8004A990;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_8004A968
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004A968;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A7DC:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // beq         $v1, $v0, L_8004AA8C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AA8C;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A7F0:
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // beq         $v1, $v0, L_8004AB68
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0xE
        ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
        goto L_8004AB68;
    }
    // slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // beq         $v0, $zero, L_8004A814
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x9
        ctx->r2 = 0 | 0X9;
        goto L_8004A814;
    }
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // beq         $v1, $v0, L_8004A8F8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004A8F8;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A814:
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // beq         $v1, $v0, L_8004ABE4
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF
        ctx->r2 = 0 | 0XF;
        goto L_8004ABE4;
    }
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // beq         $v1, $v0, L_8004AB0C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AB0C;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A830:
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // beq         $v1, $v0, L_8004A8D8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x41
        ctx->r2 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
        goto L_8004A8D8;
    }
    // slti        $v0, $v1, 0x41
    ctx->r2 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
    // beq         $v0, $zero, L_8004A880
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x15
        ctx->r2 = 0 | 0X15;
        goto L_8004A880;
    }
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // beq         $v1, $v0, L_8004A8F8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x16
        ctx->r2 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
        goto L_8004A8F8;
    }
    // slti        $v0, $v1, 0x16
    ctx->r2 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // beq         $v0, $zero, L_8004A864
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x14
        ctx->r2 = 0 | 0X14;
        goto L_8004A864;
    }
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // beq         $v1, $v0, L_8004AB68
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AB68;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A864:
    // ori         $v0, $zero, 0x16
    ctx->r2 = 0 | 0X16;
    // beq         $v1, $v0, L_8004AA68
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x20
        ctx->r2 = 0 | 0X20;
        goto L_8004AA68;
    }
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_8004AB2C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AB2C;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A880:
    // ori         $v0, $zero, 0x53
    ctx->r2 = 0 | 0X53;
    // beq         $v1, $v0, L_8004A950
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x54
        ctx->r2 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
        goto L_8004A950;
    }
    // slti        $v0, $v1, 0x54
    ctx->r2 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
    // beq         $v0, $zero, L_8004A8A4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x51
        ctx->r2 = 0 | 0X51;
        goto L_8004A8A4;
    }
    // ori         $v0, $zero, 0x51
    ctx->r2 = 0 | 0X51;
    // beq         $v1, $v0, L_8004AA40
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AA40;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004A8A4:
    // ori         $v0, $zero, 0xA5
    ctx->r2 = 0 | 0XA5;
    // beq         $v1, $v0, L_8004A8B8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004A8B8;
    }
    // nop

    // bne         $v1, $s3, L_8004AC04
    if (ctx->r3 != ctx->r19) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

L_8004A8B8:
    // lbu         $a0, 0x3F($s1)
    ctx->r4 = MEM_BU(0X3F, ctx->r17);
    // nop

    // beq         $a0, $s3, L_8004AC04
    if (ctx->r4 == ctx->r19) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // jal         0x80035CC4
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    MessageQueuePush(rdram, ctx);
    goto after_8;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_8:
    // j           L_8004A73C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_8004A73C;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8004A8D8:
    // jal         0x80049EFC
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80049EFC(rdram, ctx);
    goto after_9;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // beq         $v0, $s3, L_8004AC10
    if (ctx->r2 == ctx->r19) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8004AC10;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // j           L_8004A738
    // nop

    goto L_8004A738;
    // nop

L_8004A8F8:
    // lhu         $v1, 0x3A($s1)
    ctx->r3 = MEM_HU(0X3A, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8004AAF8
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3) << 4;
        goto L_8004AAF8;
    }
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s0, $v0, $s6
    ctx->r16 = ADD32(ctx->r2, ctx->r22);
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // beq         $v0, $s3, L_8004AAF8
    if (ctx->r2 == ctx->r19) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8004AAF8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lbu         $v0, 0x40($s1)
    ctx->r2 = MEM_BU(0X40, ctx->r17);
    // sb          $s3, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r19;
    // jal         0x80049EFC
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    sub_80049EFC(rdram, ctx);
    goto after_10;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    after_10:
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // bne         $v0, $s3, L_8004AC04
    if (ctx->r2 != ctx->r19) {
        // sb          $zero, 0x38($s0)
        MEM_B(0X38, ctx->r16) = 0;
        goto L_8004AC04;
    }
    // sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_8004AC04
    // sh          $v0, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r2;
    goto L_8004AC04;
    // sh          $v0, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r2;
L_8004A950:
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8004AC04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

L_8004A960:
    // j           L_8004AC04
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
    goto L_8004AC04;
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
L_8004A968:
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8004AC04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // beq         $v0, $s3, L_8004A960
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8004A960;
    }
    // nop

    // j           L_8004AAF8
    // nop

    goto L_8004AAF8;
    // nop

L_8004A990:
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8004AC04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 < 0XFC ? 1 : 0;
    // bne         $v0, $zero, L_8004AA14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AA14;
    }
    // nop

    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8004A9E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004A9E0;
    }
    // nop

    // lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(0X2, ctx->r20);
    // lh          $a1, 0x26($s1)
    ctx->r5 = MEM_H(0X26, ctx->r17);
    // jal         0x80015798
    // ori         $a2, $zero, 0x384
    ctx->r6 = 0 | 0X384;
    Math_IsAngleInRange(rdram, ctx);
    goto after_11;
    // ori         $a2, $zero, 0x384
    ctx->r6 = 0 | 0X384;
    after_11:
    // bne         $v0, $zero, L_8004A960
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004A960;
    }
    // nop

L_8004A9E0:
    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8004AA14
    if (ctx->r2 == 0) {
        // ori         $a2, $zero, 0x384
        ctx->r6 = 0 | 0X384;
        goto L_8004AA14;
    }
    // ori         $a2, $zero, 0x384
    ctx->r6 = 0 | 0X384;
    // lhu         $a1, 0x26($s1)
    ctx->r5 = MEM_HU(0X26, ctx->r17);
    // lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(0X2, ctx->r20);
    // addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x80015798
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_12;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_12:
    // bne         $v0, $zero, L_8004A960
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004A960;
    }
    // nop

L_8004AA14:
    // lbu         $v1, 0x38($s1)
    ctx->r3 = MEM_BU(0X38, ctx->r17);
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // bne         $v1, $v0, L_8004AAF8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004AAF8;
    }
    // nop

    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lbu         $v0, -0x2181($v0)
    ctx->r2 = MEM_BU(-0X2181, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004AAF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004AAF8;
    }
    // nop

    // j           L_8004AC04
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
    goto L_8004AC04;
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
L_8004AA40:
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8004AC04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // bne         $v0, $s3, L_8004AC04
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // j           L_8004AC04
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
    goto L_8004AC04;
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
L_8004AA68:
    // ori         $a2, $zero, 0x155
    ctx->r6 = 0 | 0X155;
    // lhu         $a1, 0x26($s1)
    ctx->r5 = MEM_HU(0X26, ctx->r17);
    // lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(0X2, ctx->r20);
    // addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x80015798
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_13;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_13:
    // beq         $v0, $zero, L_8004AC04
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

L_8004AA8C:
    // lbu         $v1, 0x38($s1)
    ctx->r3 = MEM_BU(0X38, ctx->r17);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // beq         $v1, $v0, L_8004AAAC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AAAC;
    }
    // nop

    // beq         $v1, $s3, L_8004AAF0
    if (ctx->r3 == ctx->r19) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_8004AAF0;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // j           L_8004AAF8
    // nop

    goto L_8004AAF8;
    // nop

L_8004AAAC:
    // lhu         $a0, 0x3A($s1)
    ctx->r4 = MEM_HU(0X3A, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_8004AACC
    if (ctx->r4 != ctx->r2) {
        // sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4) << 4;
        goto L_8004AACC;
    }
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
L_8004AABC:
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    MessageQueuePush(rdram, ctx);
    goto after_14;
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    after_14:
    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004AACC:
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(0X6, ctx->r2);
    // nop

    // beq         $v0, $s3, L_8004AABC
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8004AABC;
    }
    // nop

    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004AAF0:
    // j           L_8004AC04
    // sb          $v0, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r2;
    goto L_8004AC04;
    // sb          $v0, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r2;
L_8004AAF8:
    // lbu         $a0, 0x3F($s1)
    ctx->r4 = MEM_BU(0X3F, ctx->r17);
    // jal         0x80035CC4
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    MessageQueuePush(rdram, ctx);
    goto after_15;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_15:
    // j           L_8004A73C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_8004A73C;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8004AB0C:
    // lbu         $v0, 0x38($s1)
    ctx->r2 = MEM_BU(0X38, ctx->r17);
    // nop

    // bne         $v0, $s3, L_8004AC04
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // jal         0x80035CC4
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    MessageQueuePush(rdram, ctx);
    goto after_16;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_16:
    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004AB2C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A6F($v0)
    ctx->r2 = MEM_BU(-0X4A6F, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8004AC04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004AC04;
    }
    // nop

    // jal         0x8002BED0
    // andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    sub_8002BED0(rdram, ctx);
    goto after_17;
    // andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_17:
    // lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(0X40, ctx->r17);
    // nop

    // lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(0X1, ctx->r4);
    // nop

    // bne         $v0, $s5, L_8004AC04
    if (ctx->r2 != ctx->r21) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8004AC04;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // j           L_8004AC04
    // sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    goto L_8004AC04;
    // sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
L_8004AB68:
    // lhu         $a1, 0x38($s1)
    ctx->r5 = MEM_HU(0X38, ctx->r17);
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    // jal         0x800378A0
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    LoadPopupsTexturOrTalk(rdram, ctx);
    goto after_18;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_18:
    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004AB84:
    // ori         $a0, $zero, 0x200
    ctx->r4 = 0 | 0X200;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC8
    ctx->r2 = 0 | 0XC8;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80049DE4
    // sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    sub_80049DE4(rdram, ctx);
    goto after_19;
    // sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_19:
    // ori         $a0, $zero, 0x200
    ctx->r4 = 0 | 0X200;
    // ori         $a1, $zero, 0x80
    ctx->r5 = 0 | 0X80;
    // ori         $a2, $zero, 0xC8
    ctx->r6 = 0 | 0XC8;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2A($v0)
    ctx->r2 = MEM_HU(-0X4B2A, ctx->r2);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B28($at)
    MEM_H(-0X4B28, ctx->r1) = ctx->r2;
    // jal         0x80049DE4
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    sub_80049DE4(rdram, ctx);
    goto after_20;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    after_20:
    // j           L_8004A738
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_8004A738;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8004ABE4:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79D8($a0)
    ctx->r4 = MEM_BU(0X79D8, ctx->r4);
    // jal         0x8004AEC4
    // nop

    sub_8004AEC4(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // jal         0x8002BA60
    // nop

    HideInGameUI(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // jal         0x8001D770
    // nop

    sub_8001D770(rdram, ctx);
    goto after_23;
    // nop

    after_23:
L_8004AC04:
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // j           L_8004A73C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_8004A73C;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8004AC10:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_24;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_24:
    // lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(0X50, ctx->r29);
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
