#include "recomp.h"
#include "disable_warnings.h"

void Player_StrengthPowerUP(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B1C
    ctx->r3 = ADD32(ctx->r3, -0X4B1C);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x64
    ctx->r2 = ctx->r2 < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_80026B6C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026B6C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B18($v0)
    ctx->r2 = MEM_HU(-0X4B18, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B18($at)
    MEM_H(-0X4B18, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B18($v0)
    ctx->r2 = MEM_HU(-0X4B18, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x3E8
    ctx->r2 = ctx->r2 < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80026B5C
    if (ctx->r2 != 0) {
        // sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
        goto L_80026B5C;
    }
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // ori         $v0, $zero, 0x3E7
    ctx->r2 = 0 | 0X3E7;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B18($at)
    MEM_H(-0X4B18, ctx->r1) = ctx->r2;
    // j           L_80026B64
    // nop

    goto L_80026B64;
    // nop

L_80026B5C:
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x1F
    ctx->r4 = 0 | 0X1F;
    MessageQueuePush(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x1F
    ctx->r4 = 0 | 0X1F;
    after_0:
L_80026B64:
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80026B6C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
