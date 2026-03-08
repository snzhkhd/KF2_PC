#include "recomp.h"
#include "disable_warnings.h"

void UseConsumableItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8001A348
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x47
        ctx->r2 = 0 | 0X47;
        goto L_8001A348;
    }
    // ori         $v0, $zero, 0x47
    ctx->r2 = 0 | 0X47;
    // bne         $s0, $v0, L_8001A144
    if (ctx->r16 != ctx->r2) {
        // ori         $v0, $zero, 0x48
        ctx->r2 = 0 | 0X48;
        goto L_8001A144;
    }
    // ori         $v0, $zero, 0x48
    ctx->r2 = 0 | 0X48;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4ADC
    ctx->r3 = ADD32(ctx->r3, -0X4ADC);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // blez        $v0, L_8001A10C
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8001A10C;
    }
    // nop

    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8001A10C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADE($v0)
    ctx->r2 = MEM_H(-0X4ADE, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // bne         $v0, $zero, L_8001A12C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_8001A12C;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADE($at)
    MEM_H(-0X4ADE, ctx->r1) = ctx->r2;
L_8001A12C:
    // jal         0x8001A3F8
    // nop

    sub_8001A3F8(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x8001A3C8
    // nop

    sub_8001A3C8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8001A254
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
    goto L_8001A254;
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
L_8001A144:
    // bne         $s0, $v0, L_8001A160
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8001A160;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B24
    ctx->r3 = ADD32(ctx->r3, -0X4B24);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_8001A24C
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    goto L_8001A24C;
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_8001A160:
    // ori         $v0, $zero, 0x49
    ctx->r2 = 0 | 0X49;
    // bne         $s0, $v0, L_8001A190
    if (ctx->r16 != ctx->r2) {
        // ori         $v0, $zero, 0x4A
        ctx->r2 = 0 | 0X4A;
        goto L_8001A190;
    }
    // ori         $v0, $zero, 0x4A
    ctx->r2 = 0 | 0X4A;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B16
    ctx->r3 = ADD32(ctx->r3, -0X4B16);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x80026430
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    CalculatePlayerStats(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    after_2:
    // j           L_8001A254
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
    goto L_8001A254;
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
L_8001A190:
    // bne         $s0, $v0, L_8001A1AC
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8001A1AC;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B28
    ctx->r3 = ADD32(ctx->r3, -0X4B28);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_8001A24C
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    goto L_8001A24C;
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_8001A1AC:
    // ori         $v0, $zero, 0x4B
    ctx->r2 = 0 | 0X4B;
    // bne         $s0, $v0, L_8001A1D4
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8001A1D4;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B28
    ctx->r3 = ADD32(ctx->r3, -0X4B28);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = 0;
    // j           L_8001A24C
    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    goto L_8001A24C;
    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_8001A1D4:
    // ori         $v0, $zero, 0x4C
    ctx->r2 = 0 | 0X4C;
    // bne         $s0, $v0, L_8001A210
    if (ctx->r16 != ctx->r2) {
        // ori         $v0, $zero, 0x4D
        ctx->r2 = 0 | 0X4D;
        goto L_8001A210;
    }
    // ori         $v0, $zero, 0x4D
    ctx->r2 = 0 | 0X4D;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2A($v0)
    ctx->r2 = MEM_HU(-0X4B2A, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B26($v1)
    ctx->r3 = MEM_HU(-0X4B26, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B28($at)
    MEM_H(-0X4B28, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r3;
    // jal         0x8001A35C
    // nop

    sub_8001A35C(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8001A254
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
    goto L_8001A254;
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
L_8001A210:
    // bne         $s0, $v0, L_8001A22C
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8001A22C;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B28
    ctx->r3 = ADD32(ctx->r3, -0X4B28);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_8001A24C
    // addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    goto L_8001A24C;
    // addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
L_8001A22C:
    // ori         $v0, $zero, 0x4E
    ctx->r2 = 0 | 0X4E;
    // bne         $s0, $v0, L_8001A254
    if (ctx->r16 != ctx->r2) {
        // ori         $v0, $zero, 0x4F
        ctx->r2 = 0 | 0X4F;
        goto L_8001A254;
    }
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B24
    ctx->r3 = ADD32(ctx->r3, -0X4B24);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x32
    ctx->r2 = ADD32(ctx->r2, 0X32);
L_8001A24C:
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x4F
    ctx->r2 = 0 | 0X4F;
L_8001A254:
    // beq         $s0, $v0, L_8001A28C
    if (ctx->r16 == ctx->r2) {
        // ori         $v0, $zero, 0x50
        ctx->r2 = 0 | 0X50;
        goto L_8001A28C;
    }
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // bne         $s0, $v0, L_8001A294
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8001A294;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x4B28
    ctx->r2 = ADD32(ctx->r2, -0X4B28);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B24($a0)
    ctx->r4 = MEM_HU(-0X4B24, ctx->r4);
    // addiu       $v1, $v1, 0x64
    ctx->r3 = ADD32(ctx->r3, 0X64);
    // addiu       $a0, $a0, 0x32
    ctx->r4 = ADD32(ctx->r4, 0X32);
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r4;
L_8001A28C:
    // jal         0x8001A35C
    // nop

    sub_8001A35C(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8001A294:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B28
    ctx->r4 = ADD32(ctx->r4, -0X4B28);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B2A($v1)
    ctx->r3 = MEM_HU(-0X4B2A, ctx->r3);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8001A2BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001A2BC;
    }
    // nop

    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_8001A2BC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B24($v0)
    ctx->r2 = MEM_HU(-0X4B24, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B26($v1)
    ctx->r3 = MEM_HU(-0X4B26, ctx->r3);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8001A2E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001A2E4;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B24($at)
    MEM_H(-0X4B24, ctx->r1) = ctx->r3;
L_8001A2E4:
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // addiu       $v0, $s0, -0x4D
    ctx->r2 = ADD32(ctx->r16, -0X4D);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001A328
    if (ctx->r2 != 0) {
        // addiu       $v0, $s0, -0x4F
        ctx->r2 = ADD32(ctx->r16, -0X4F);
        goto L_8001A328;
    }
    // addiu       $v0, $s0, -0x4F
    ctx->r2 = ADD32(ctx->r16, -0X4F);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8001A340
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001A340;
    }
    // nop

L_8001A328:
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // addiu       $v1, $v1, -0x213E
    ctx->r3 = ADD32(ctx->r3, -0X213E);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8001A340:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0xD
    ctx->r4 = 0 | 0XD;
    PlaySfx(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0xD
    ctx->r4 = 0 | 0XD;
    after_5:
L_8001A348:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
