#include "recomp.h"
#include "disable_warnings.h"

void SetFadeColor(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $a0, 0x4DF9($at)
    MEM_B(0X4DF9, ctx->r1) = ctx->r4;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $a1, 0x4DFA($at)
    MEM_B(0X4DFA, ctx->r1) = ctx->r5;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $a2, 0x4DFB($at)
    MEM_B(0X4DFB, ctx->r1) = ctx->r6;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $a3, 0x4DFC($at)
    MEM_B(0X4DFC, ctx->r1) = ctx->r7;
    // jr          $ra
    // nop

    return;
    // nop

;}
