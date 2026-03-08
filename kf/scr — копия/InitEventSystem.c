#include "recomp.h"
#include "disable_warnings.h"

void InitEventSystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80062840
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x7C98
    ctx->r7 = ADD32(ctx->r7, 0X7C98);
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, -0x5A54
    ctx->r16 = ADD32(ctx->r16, -0X5A54);
    // jal         0x80062AB0
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    KF_OpenEvent(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_1:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $a0, -0x5A58($at)
    MEM_W(-0X5A58, ctx->r1) = ctx->r4;
    // jal         0x80062870
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    KF_EnableEvent(rdram, ctx);
    goto after_2;
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    after_2:
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $zero, -0x5A50($at)
    MEM_W(-0X5A50, ctx->r1) = 0;
L_80019040:
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80019040
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
        goto L_80019040;
    }
    // addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x7FAC
    ctx->r7 = ADD32(ctx->r7, 0X7FAC);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x57BC
    ctx->r3 = ADD32(ctx->r3, -0X57BC);
    // addiu       $v0, $v1, -0x280
    ctx->r2 = ADD32(ctx->r3, -0X280);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x57B8($at)
    MEM_W(-0X57B8, ctx->r1) = ctx->r2;
    // jal         0x80062AB0
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    KF_OpenEvent(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_3:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x7DB4
    ctx->r7 = ADD32(ctx->r7, 0X7DB4);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5A4C($at)
    MEM_W(-0X5A4C, ctx->r1) = ctx->r2;
    // jal         0x80062AB0
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    KF_OpenEvent(rdram, ctx);
    goto after_4;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_4:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // ori         $a1, $zero, 0x40
    ctx->r5 = 0 | 0X40;
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x7F2C
    ctx->r7 = ADD32(ctx->r7, 0X7F2C);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5A48($at)
    MEM_W(-0X5A48, ctx->r1) = ctx->r2;
    // jal         0x80062AB0
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    KF_OpenEvent(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_5:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A4C($a0)
    ctx->r4 = MEM_W(-0X5A4C, ctx->r4);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5A40($at)
    MEM_W(-0X5A40, ctx->r1) = ctx->r2;
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A48($a0)
    ctx->r4 = MEM_W(-0X5A48, ctx->r4);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A40($a0)
    ctx->r4 = MEM_W(-0X5A40, ctx->r4);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_9;
    // nop

    after_9:
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
