#include "recomp.h"
#include "disable_warnings.h"

void sub_800177B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // nop

    // beq         $v0, $zero, L_800177C8
    if (ctx->r2 == 0) {
        // sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
        goto L_800177C8;
    }
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
L_800177C8:
    // jr          $ra
    // nop

    return;
    // nop

;}
