#include "recomp.h"
#include "disable_warnings.h"

void sub_8002FD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x9000
    ctx->r3 = ctx->r3 | 0X9000;
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, 0x4DDC
    ctx->r5 = ADD32(ctx->r5, 0X4DDC);
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sb          $v0, 0x138($at)
    MEM_B(0X138, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // addiu       $v0, $v0, -0x1580
    ctx->r2 = ADD32(ctx->r2, -0X1580);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x13C($at)
    MEM_W(0X13C, ctx->r1) = ctx->r2;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x140($at)
    MEM_W(0X140, ctx->r1) = ctx->r2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x144($at)
    MEM_W(0X144, ctx->r1) = ctx->r2;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = ctx->r2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x4DF6($at)
    MEM_B(0X4DF6, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x4DF4($at)
    MEM_B(0X4DF4, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x4DF5($at)
    MEM_B(0X4DF5, ctx->r1) = 0;
L_8002FE0C:
    // sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_8002FE0C
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_8002FE0C;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0x4E0C
    ctx->r3 = ADD32(ctx->r3, 0X4E0C);
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8002FE38:
    // sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $a0, L_8002FE38
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
        goto L_8002FE38;
    }
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x4DF9($at)
    MEM_B(0X4DF9, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $zero, 0x7224($at)
    MEM_W(0X7224, ctx->r1) = 0;
    // jal         0x800370CC
    // nop

    sub_800370CC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
