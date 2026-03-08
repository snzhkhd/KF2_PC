#include "recomp.h"
#include "disable_warnings.h"

void GPU_Cmd_SetBaseParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // jr          $ra
    // sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
;}
