#include "recomp.h"
#include "disable_warnings.h"

void Player_LevelUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // ori         $v1, $v1, 0x423F
    ctx->r3 = ctx->r3 | 0X423F;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4B3C
    ctx->r5 = ADD32(ctx->r5, -0X4B3C);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // slt         $a0, $v1, $a0
    ctx->r4 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $a0, $zero, L_80026C5C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80026C5C;
    }
    // nop

    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_80026C5C:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4B38($v1)
    ctx->r3 = MEM_W(-0X4B38, ctx->r3);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80026E1C
    if (ctx->r2 != 0) {
        // addiu       $s0, $a1, 0x8
        ctx->r16 = ADD32(ctx->r5, 0X8);
        goto L_80026E1C;
    }
    // addiu       $s0, $a1, 0x8
    ctx->r16 = ADD32(ctx->r5, 0X8);
    // addiu       $s1, $a1, 0x12
    ctx->r17 = ADD32(ctx->r5, 0X12);
    // ori         $s2, $zero, 0x3E7
    ctx->r18 = 0 | 0X3E7;
L_80026C80:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // beq         $v0, $zero, L_80026E1C
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_80026E1C;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // sltiu       $v0, $v1, 0x64
    ctx->r2 = ctx->r3 < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_80026D30
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026D30;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x69C8($v1)
    ctx->r3 = MEM_HU(-0X69C8, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x69D4($a0)
    ctx->r4 = MEM_HU(-0X69D4, ctx->r4);
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x69C6($v1)
    ctx->r3 = MEM_HU(-0X69C6, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x69D2($a0)
    ctx->r4 = MEM_HU(-0X69D2, ctx->r4);
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x69C4($a0)
    ctx->r4 = MEM_HU(-0X69C4, ctx->r4);
    // lhu         $v1, 0x1E($s0)
    ctx->r3 = MEM_HU(0X1E, ctx->r16);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lhu         $a1, -0x69C2($a1)
    ctx->r5 = MEM_HU(-0X69C2, ctx->r5);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, -0x69C0($v0)
    ctx->r2 = MEM_W(-0X69C0, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x69CC($v1)
    ctx->r3 = MEM_W(-0X69CC, ctx->r3);
    // lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(-0X4, ctx->r16);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_80026D8C
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    goto L_80026D8C;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80026D30:
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x6E6C
    ctx->r3 = ADD32(ctx->r3, -0X6E6C);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
L_80026D8C:
    // nop

    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x3E8
    ctx->r2 = ctx->r2 < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80026DAC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026DAC;
    }
    // nop

    // sh          $s2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r18;
L_80026DAC:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x3E8
    ctx->r2 = ctx->r2 < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80026DC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026DC4;
    }
    // nop

    // sh          $s2, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r18;
L_80026DC4:
    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x3E8
    ctx->r2 = ctx->r2 < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80026DDC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026DDC;
    }
    // nop

    // sh          $s2, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r18;
L_80026DDC:
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x3E8
    ctx->r2 = ctx->r2 < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80026DF4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026DF4;
    }
    // nop

    // sh          $s2, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r18;
L_80026DF4:
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80035CC4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    MessageQueuePush(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // lw          $v0, -0x12($s1)
    ctx->r2 = MEM_W(-0X12, ctx->r17);
    // lw          $v1, -0xE($s1)
    ctx->r3 = MEM_W(-0XE, ctx->r17);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80026C80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026C80;
    }
    // nop

L_80026E1C:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
