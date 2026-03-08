#include "recomp.h"
#include "disable_warnings.h"

void KF_TMDCurrentSet(uint8_t* rdram, recomp_context* ctx) 
{

    // printf("[KFTMDCurrentSet] tmdID=%d KFTMDPointers[0]=%08X\n",
        // (int)ctx->r4,
        // MEM_W(0, 0x80190240));

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x240
    ctx->r1 = ADD32(ctx->r1, 0X240);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v0, 0x250($at)
    MEM_W(0X250, ctx->r1) = ctx->r2;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
