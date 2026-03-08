#include "recomp.h"
#include "disable_warnings.h"

void Entities_UpdateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // addiu       $s1, $s1, -0x19F8
    ctx->r17 = ADD32(ctx->r17, -0X19F8);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // addiu       $s2, $s2, 0x79CC
    ctx->r18 = ADD32(ctx->r18, 0X79CC);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // addiu       $s4, $s4, -0x4A64
    ctx->r20 = ADD32(ctx->r20, -0X4A64);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, 0x42
    ctx->r16 = ADD32(ctx->r17, 0X42);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79C8($at)
    MEM_W(0X79C8, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = 0;
L_800420B0:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_800421E4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800421E4;
    }
    // nop

    // jal         0x8003D748
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    Entity_SetContext(rdram, ctx);
    goto after_0;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // lw          $v0, -0xC($s2)
    ctx->r2 = MEM_W(-0XC, ctx->r18);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v1, $v0, L_80042108
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80042108;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4B32($v0)
    ctx->r2 = MEM_BU(-0X4B32, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80042108
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042108;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A6F($v0)
    ctx->r2 = MEM_BU(-0X4A6F, ctx->r2);
    // nop

    // bne         $v0, $s3, L_80042110
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80042110;
    }
    // nop

L_80042108:
    // jal         0x8003C2B4
    // nop

    Entity_UpdateDetection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80042110:
    // lbu         $v0, -0x39($s0)
    ctx->r2 = MEM_BU(-0X39, ctx->r16);
    // nop

    // bne         $v0, $s3, L_80042158
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80042158;
    }
    // nop

    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // lw          $v0, -0x4($s2)
    ctx->r2 = MEM_W(-0X4, ctx->r18);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // bne         $v1, $v0, L_80042140
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80042140;
    }
    // nop

    // jal         0x8003C138
    // nop

    Entity_UpdateAIByDistance(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80042140:
    // jal         0x8003FBF8
    // nop

    UpdateEnemyAI(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $v0, -0x4($s2)
    ctx->r2 = MEM_W(-0X4, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
L_80042158:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79B0($v0)
    ctx->r2 = MEM_W(0X79B0, ctx->r2);
    // nop

    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_800421E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800421E4;
    }
    // nop

    // lh          $v0, -0x20($s0)
    ctx->r2 = MEM_H(-0X20, ctx->r16);
    // nop

    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(0X14, ctx->r3);
    // nop

    // sw          $v0, -0x16($s0)
    MEM_W(-0X16, ctx->r16) = ctx->r2;
    // lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(0X18, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x1F4
    ctx->r2 = ADD32(ctx->r2, -0X1F4);
    // sw          $v0, -0x12($s0)
    MEM_W(-0X12, ctx->r16) = ctx->r2;
    // lw          $v1, 0x1C($v1)
    ctx->r3 = MEM_W(0X1C, ctx->r3);
    // lbu         $v0, -0x39($s0)
    ctx->r2 = MEM_BU(-0X39, ctx->r16);
    // nop

    // bne         $v0, $s3, L_800421E4
    if (ctx->r2 != ctx->r19) {
        // sw          $v1, -0xE($s0)
        MEM_W(-0XE, ctx->r16) = ctx->r3;
        goto L_800421E4;
    }
    // sw          $v1, -0xE($s0)
    MEM_W(-0XE, ctx->r16) = ctx->r3;
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $v0, -0x16($s0)
    ctx->r2 = MEM_W(-0X16, ctx->r16);
    // lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(0X8, ctx->r20);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // jal         0x80015804
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_4;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    after_4:
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800421E4:
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x79C0
    ctx->r3 = ADD32(ctx->r3, 0X79C0);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // bne         $v0, $zero, L_800420B0
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x7C
        ctx->r17 = ADD32(ctx->r17, 0X7C);
        goto L_800420B0;
    }
    // addiu       $s1, $s1, 0x7C
    ctx->r17 = ADD32(ctx->r17, 0X7C);
    // lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(0XC, ctx->r3);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8003D748
    // sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    Entity_SetContext(rdram, ctx);
    goto after_5;
    // sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    after_5:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
