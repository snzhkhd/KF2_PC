#include "recomp.h"
#include "disable_warnings.h"

void InitPlayerStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x6E6C($v1)
    ctx->r3 = MEM_HU(-0X6E6C, ctx->r3);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lhu         $a1, -0x6E6A($a1)
    ctx->r5 = MEM_HU(-0X6E6A, ctx->r5);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lhu         $a2, -0x6E68($a2)
    ctx->r6 = MEM_HU(-0X6E68, ctx->r6);
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // lhu         $a3, -0x6E66($a3)
    ctx->r7 = MEM_HU(-0X6E66, ctx->r7);
    // lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // lw          $t0, -0x6E64($t0)
    ctx->r8 = MEM_W(-0X6E64, ctx->r8);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B34($at)
    MEM_B(-0X4B34, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4B3C($at)
    MEM_W(-0X4B3C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4B10($at)
    MEM_W(-0X4B10, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A00($at)
    MEM_H(-0X4A00, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x49FE($at)
    MEM_H(-0X49FE, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A7C($at)
    MEM_B(-0X4A7C, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A7B($at)
    MEM_B(-0X4A7B, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A79($at)
    MEM_B(-0X4A79, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A78($at)
    MEM_B(-0X4A78, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A7A($at)
    MEM_B(-0X4A7A, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A77($at)
    MEM_B(-0X4A77, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A76($at)
    MEM_B(-0X4A76, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a1, -0x4B26($at)
    MEM_H(-0X4B26, ctx->r1) = ctx->r5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B2A($at)
    MEM_H(-0X4B2A, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a2, -0x4B18($at)
    MEM_H(-0X4B18, ctx->r1) = ctx->r6;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a3, -0x4B16($at)
    MEM_H(-0X4B16, ctx->r1) = ctx->r7;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $t0, -0x4B38($at)
    MEM_W(-0X4B38, ctx->r1) = ctx->r8;
    // jal         0x80027ED0
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    sub_80027ED0(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    after_0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4AC0($at)
    MEM_W(-0X4AC0, ctx->r1) = 0;
    // jal         0x80027E70
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    SsSetAutoKeyOffMode(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    after_1:
    // jal         0x8002810C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002810C(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // jal         0x80027E80
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    sub_80027E80(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    after_3:
    // jal         0x80027EA8
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    sub_80027EA8(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    after_4:
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x1800
    ctx->r4 = ctx->r4 | 0X1800;
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x1900
    ctx->r6 = ADD32(ctx->r6, -0X1900);
    // ori         $a1, $zero, 0x3F
    ctx->r5 = 0 | 0X3F;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // ori         $v0, $zero, 0x9C4
    ctx->r2 = 0 | 0X9C4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A42($at)
    MEM_H(-0X4A42, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, -0x3200
    ctx->r2 = ADD32(0, -0X3200);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A44($at)
    MEM_H(-0X4A44, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A40($at)
    MEM_H(-0X4A40, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $a0, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A14($at)
    MEM_H(-0X4A14, ctx->r1) = ctx->r2;
L_80027BA4:
    // sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a3, L_80027BA4
    if (ctx->r5 != ctx->r7) {
        // addiu       $a2, $a2, 0x1A
        ctx->r6 = ADD32(ctx->r6, 0X1A);
        goto L_80027BA4;
    }
    // addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    // jal         0x80027994
    // nop

    ResetPlayerBuffers(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
