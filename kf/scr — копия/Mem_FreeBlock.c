#include "recomp.h"
#include "disable_warnings.h"

void Mem_FreeBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(-0X4, ctx->r4);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // jr          $ra
    // sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    return;
    // sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
;}
