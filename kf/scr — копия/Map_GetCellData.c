#include "recomp.h"
#include "disable_warnings.h"

void Map_GetCellData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sra         $v0, $a2, 11
    ctx->r2 = S32(ctx->r6) >> 11;
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
    // sra         $a1, $t0, 11
    ctx->r5 = S32(ctx->r8) >> 11;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // addiu       $a1, $a1, -0x428C
    ctx->r5 = ADD32(ctx->r5, -0X428C);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(0X30, ctx->r29);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $a0, $v0, L_8002E208
    if (ctx->r4 != ctx->r2) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_8002E208;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0x2A82($at)
    MEM_H(-0X2A82, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x6($v1)
    ctx->r2 = MEM_BU(0X6, ctx->r3);
    // j           L_8002E21C
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_8002E21C;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8002E208:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $zero, -0x2A82($at)
    MEM_H(-0X2A82, ctx->r1) = 0;
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8002E21C:
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A80($at)
    MEM_W(-0X2A80, ctx->r1) = ctx->r2;
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, -0x2A80($a1)
    ctx->r5 = MEM_W(-0X2A80, ctx->r5);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v1, -0x2A8C($at)
    MEM_W(-0X2A8C, ctx->r1) = ctx->r3;
    // jal         0x8002D5C0
    // sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Map_CalculatePhysics(rdram, ctx);
    goto after_0;
    // sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
