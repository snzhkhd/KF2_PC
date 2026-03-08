#include "recomp.h"
#include "disable_warnings.h"

void IsFacingFountainTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(0X2, ctx->r16);
    // jal         0x800601F4
    // nop

    FixedSin(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(0X2, ctx->r16);
    // lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(0X0, ctx->r17);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // jal         0x800602D0
    // subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    FixedCos(rdram, ctx);
    goto after_1;
    // subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v1, $zero, 0x6A4
    ctx->r3 = 0 | 0X6A4;
    // sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2) << 1;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6) << 3;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6) << 5;
    // lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(0X8, ctx->r17);
    // sra         $a2, $a2, 12
    ctx->r6 = S32(ctx->r6) >> 12;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(0X4, ctx->r17);
    // jal         0x8002E120
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    MAP_CollisionWithTile(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_2:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A88($v0)
    ctx->r2 = MEM_W(-0X2A88, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // xori        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 ^ 0X20;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
