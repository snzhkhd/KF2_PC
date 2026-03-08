#include "recomp.h"
#include "disable_warnings.h"

void Player_ResetMovement(uint8_t* rdram, recomp_context* ctx) 
{
    printf("Player_ResetMovement\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lhu         $v0, 0x62CC($v0)
    ctx->r2 = MEM_HU(0X62CC, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lhu         $v1, 0x62D4($v1)
    ctx->r3 = MEM_HU(0X62D4, ctx->r3);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lhu         $a0, 0x62D8($a0)
    ctx->r4 = MEM_HU(0X62D8, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A0C($at)
    MEM_H(-0X4A0C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A0A($at)
    MEM_H(-0X4A0A, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A0E($at)
    MEM_H(-0X4A0E, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = 0;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lhu         $a0, 0x62DC($a0)
    ctx->r4 = MEM_HU(0X62DC, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x49FA($v1)
    ctx->r3 = MEM_HU(-0X49FA, ctx->r3);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x49FA($at)
    MEM_H(-0X49FA, ctx->r1) = ctx->r3;
    // jr          $ra
    // nop

    return;
    // nop

;}
