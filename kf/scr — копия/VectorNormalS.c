#include "recomp.h"
#include "disable_warnings.h"

void VectorNormalS(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(0X8, ctx->r4);
    // b           L_80060C38
    recomp_vram_call(rdram, ctx, 0x80060C38);
    return;
    // addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
;}
