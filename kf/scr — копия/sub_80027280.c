#include "recomp.h"
#include "disable_warnings.h"

void sub_80027280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // beq         $v0, $zero, L_800272B8
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x2
        ctx->r2 = ctx->r4 & 0X2;
        goto L_800272B8;
    }
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4AE6
    ctx->r3 = ADD32(ctx->r3, -0X4AE6);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // bne         $v0, $zero, L_800272AC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_800272AC;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800272AC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE4($at)
    MEM_H(-0X4AE4, ctx->r1) = 0;
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
L_800272B8:
    // beq         $v0, $zero, L_800272EC
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x3
        ctx->r2 = ctx->r4 & 0X3;
        goto L_800272EC;
    }
    // andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4AE2
    ctx->r3 = ADD32(ctx->r3, -0X4AE2);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // bne         $v0, $zero, L_800272E0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_800272E0;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800272E0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE0($at)
    MEM_H(-0X4AE0, ctx->r1) = 0;
    // andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
L_800272EC:
    // beq         $v0, $zero, L_800272FC
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x5
        ctx->r2 = ctx->r4 & 0X5;
        goto L_800272FC;
    }
    // andi        $v0, $a0, 0x5
    ctx->r2 = ctx->r4 & 0X5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = 0;
L_800272FC:
    // beq         $v0, $zero, L_8002732C
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x4
        ctx->r2 = ctx->r4 & 0X4;
        goto L_8002732C;
    }
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4ADE
    ctx->r3 = ADD32(ctx->r3, -0X4ADE);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // bne         $v0, $zero, L_8002732C
    if (ctx->r2 != 0) {
        // andi        $v0, $a0, 0x4
        ctx->r2 = ctx->r4 & 0X4;
        goto L_8002732C;
    }
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
L_8002732C:
    // beq         $v0, $zero, L_8002733C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002733C;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4ADC($at)
    MEM_H(-0X4ADC, ctx->r1) = 0;
L_8002733C:
    // jr          $ra
    // nop

    return;
    // nop

;}
