#include "recomp.h"
#include "disable_warnings.h"

void Player_Spawn(uint8_t* rdram, recomp_context* ctx) 
{
    printf("Player_Spawn\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A14($v0)
    ctx->r2 = MEM_HU(-0X4A14, ctx->r2);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4AC8($at)
    MEM_W(-0X4AC8, ctx->r1) = 0;
    // bne         $v0, $zero, L_80027CCC
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_80027CCC;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_80027CCC:
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A64($a1)
    ctx->r5 = MEM_W(-0X4A64, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A5C($a2)
    ctx->r6 = MEM_W(-0X4A5C, ctx->r6);
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // jal         0x8002E19C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    Map_GetCellData(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r2;
    // jal         0x80025E30
    // nop

    Player_CheckHeadroom(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B32($at)
    MEM_B(-0X4B32, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = 0;
    // jal         0x80027C38
    // nop

    Player_ResetMovement(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // jal         0x8002E25C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_3;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_3:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
