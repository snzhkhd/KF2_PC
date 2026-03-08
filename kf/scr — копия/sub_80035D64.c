#include "recomp.h"
#include "disable_warnings.h"

void sub_80035D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5) << 4;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // jr          $ra
    // sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
;}
