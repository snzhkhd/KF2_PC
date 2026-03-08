#include "recomp.h"
#include "disable_warnings.h"

void KF_PlayerCopyPositionRotation(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("GatherCameraContext\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // nop

    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // nop

    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A08($v0)
    ctx->r2 = MEM_H(-0X4A08, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4A04($a2)
    ctx->r6 = MEM_H(-0X4A04, ctx->r6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4C($v0)
    ctx->r2 = MEM_HU(-0X4A4C, ctx->r2);
    // nop

    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4A($v0)
    ctx->r2 = MEM_HU(-0X4A4A, ctx->r2);
    // nop

    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A48($v0)
    ctx->r2 = MEM_HU(-0X4A48, ctx->r2);
    // jr          $ra
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    return;
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
;}
