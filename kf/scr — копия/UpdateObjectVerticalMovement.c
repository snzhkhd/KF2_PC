#include "recomp.h"
#include "disable_warnings.h"

void UpdateObjectVerticalMovement(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79B4($s0)
    ctx->r16 = MEM_W(0X79B4, ctx->r16);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(0X30, ctx->r16);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // lw          $s2, 0x79B0($s2)
    ctx->r18 = MEM_W(0X79B0, ctx->r18);
    // jal         0x8002E120
    // nop

    MAP_CollisionWithTile(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $s3, 0x801E
    ctx->r19 = S32(0X801E << 16);
    // addiu       $s3, $s3, -0x2A82
    ctx->r19 = ADD32(ctx->r19, -0X2A82);
    // lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(0X0, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8003E0C0
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x2
        ctx->r3 = 0 | 0X2;
        goto L_8003E0C0;
    }
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
L_8003E0C0:
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8003E0E8
    if (ctx->r2 == 0) {
        // sb          $v1, 0x3($s0)
        MEM_B(0X3, ctx->r16) = ctx->r3;
        goto L_8003E0E8;
    }
    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A80($v0)
    ctx->r2 = MEM_W(-0X2A80, ctx->r2);
    // nop

    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A7C($at)
    MEM_W(-0X2A7C, ctx->r1) = ctx->r2;
L_8003E0E8:
    // lbu         $v1, 0xD($s0)
    ctx->r3 = MEM_BU(0XD, ctx->r16);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_8003E2A8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
        goto L_8003E2A8;
    }
    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_8003E118
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E118;
    }
    // nop

    // beq         $v1, $zero, L_8003E12C
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003E12C;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_8003E168
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003E168;
    }
    // nop

    // j           L_8003E3F4
    // nop

    goto L_8003E3F4;
    // nop

L_8003E118:
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // beq         $v1, $v0, L_8003E2F4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003E2F4;
    }
    // nop

    // j           L_8003E3F4
    // nop

    goto L_8003E3F4;
    // nop

L_8003E12C:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A7C($v1)
    ctx->r3 = MEM_W(-0X2A7C, ctx->r3);
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_8003E158
    if (SIGNED(ctx->r3) >= 0) {
        // ori         $v0, $zero, 0x20
        ctx->r2 = 0 | 0X20;
        goto L_8003E158;
    }
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
    // j           L_8003E3F4
    // sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    goto L_8003E3F4;
    // sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
L_8003E158:
    // blez        $v1, L_8003E3F4
    if (SIGNED(ctx->r3) <= 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003E3F4;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_8003E3EC
    // nop

    goto L_8003E3EC;
    // nop

L_8003E168:
    // lh          $v1, 0x52($s0)
    ctx->r3 = MEM_H(0X52, ctx->r16);
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // jal         0x8002E4F4
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_8002E4F4(rdram, ctx);
    goto after_1;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // bne         $s1, $zero, L_8003E1D4
    if (ctx->r17 != 0) {
        // ori         $v0, $zero, 0x80
        ctx->r2 = 0 | 0X80;
        goto L_8003E1D4;
    }
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
L_8003E1B8:
    // sw          $s3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r19;
    // lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(0X5, ctx->r18);
    // lhu         $v1, 0x52($s0)
    ctx->r3 = MEM_HU(0X52, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8003E3F4
    // sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    goto L_8003E3F4;
    // sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
L_8003E1D4:
    // bne         $s1, $v0, L_8003E234
    if (ctx->r17 != ctx->r2) {
        // andi        $v0, $s1, 0x4
        ctx->r2 = ctx->r17 & 0X4;
        goto L_8003E234;
    }
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // lh          $v0, 0x52($s0)
    ctx->r2 = MEM_H(0X52, ctx->r16);
    // nop

    // slti        $v0, $v0, 0x29
    ctx->r2 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // bne         $v0, $zero, L_8003E234
    if (ctx->r2 != 0) {
        // andi        $v0, $s1, 0x4
        ctx->r2 = ctx->r17 & 0X4;
        goto L_8003E234;
    }
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lbu         $a1, 0x6($s2)
    ctx->r5 = MEM_BU(0X6, ctx->r18);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // jal         0x80027344
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    ApplyStatusEffect(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
L_8003E234:
    // beq         $v0, $zero, L_8003E28C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E28C;
    }
    // nop

    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8003E274
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E274;
    }
    // nop

    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A80($v1)
    ctx->r3 = MEM_W(-0X2A80, ctx->r3);
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8003E1B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003E1B8;
    }
    // nop

    // j           L_8003E284
    // sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    goto L_8003E284;
    // sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
L_8003E274:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // nop

    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_8003E284:
    // j           L_8003E2EC
    // sh          $zero, 0x52($s0)
    MEM_H(0X52, ctx->r16) = 0;
    goto L_8003E2EC;
    // sh          $zero, 0x52($s0)
    MEM_H(0X52, ctx->r16) = 0;
L_8003E28C:
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // bne         $v0, $zero, L_8003E1B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003E1B8;
    }
    // nop

    // j           L_8003E3F4
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    goto L_8003E3F4;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
L_8003E2A8:
    // lh          $v0, 0x52($s0)
    ctx->r2 = MEM_H(0X52, ctx->r16);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // lhu         $a0, 0x52($s0)
    ctx->r4 = MEM_HU(0X52, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // sh          $a0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r4;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A7C($v1)
    ctx->r3 = MEM_W(-0X2A7C, ctx->r3);
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003E2E8
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_8003E2E8;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // bltz        $v0, L_8003E3F4
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8003E3F4;
    }
    // nop

L_8003E2E8:
    // sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
L_8003E2EC:
    // j           L_8003E3F4
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    goto L_8003E3F4;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
L_8003E2F4:
    // lh          $v0, 0x6A($s0)
    ctx->r2 = MEM_H(0X6A, ctx->r16);
    // lh          $a0, 0x52($s0)
    ctx->r4 = MEM_H(0X52, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // lh          $v0, 0x6C($s0)
    ctx->r2 = MEM_H(0X6C, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(0X3C, ctx->r16);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // addu        $s1, $a1, $v0
    ctx->r17 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8002E4F4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8002E4F4(rdram, ctx);
    goto after_3;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bne         $v1, $zero, L_8003E3A0
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0x80
        ctx->r2 = 0 | 0X80;
        goto L_8003E3A0;
    }
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // lhu         $v0, 0x52($s0)
    ctx->r2 = MEM_HU(0X52, ctx->r16);
    // sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(0X0, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8003E398
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x2
        ctx->r3 = 0 | 0X2;
        goto L_8003E398;
    }
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
L_8003E398:
    // j           L_8003E3F4
    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    goto L_8003E3F4;
    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
L_8003E3A0:
    // bne         $v1, $v0, L_8003E3EC
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8003E3EC;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lbu         $a1, 0x6($s2)
    ctx->r5 = MEM_BU(0X6, ctx->r18);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // jal         0x80027344
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    ApplyStatusEffect(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
L_8003E3EC:
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // sh          $zero, 0x52($s0)
    MEM_H(0X52, ctx->r16) = 0;
L_8003E3F4:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
