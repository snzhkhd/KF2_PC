#include "recomp.h"
#include "disable_warnings.h"

void SsSetAutoKeyOffMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4AA5($at)
    MEM_B(-0X4AA5, ctx->r1) = ctx->r4;
    // jr          $ra
    // nop

    return;
    // nop

;}
