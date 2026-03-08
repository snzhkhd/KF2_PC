#include "recomp.h"
#include "disable_warnings.h"

void sub_8002BCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x49EC($at)
    MEM_B(-0X49EC, ctx->r1) = ctx->r4;
    // jr          $ra
    // nop

    return;
    // nop

;}
