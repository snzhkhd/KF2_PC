#include "recomp.h"
#include "disable_warnings.h"

void sub_8005208C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a0, $v0, L_800520A8
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_800520A8;
    }
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x79C($at)
    MEM_W(-0X79C, ctx->r1) = 0;
    // j           L_800520B0
    // nop

    goto L_800520B0;
    // nop

L_800520A8:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x79C($at)
    MEM_W(-0X79C, ctx->r1) = ctx->r2;
L_800520B0:
    // jr          $ra
    // nop

    return;
    // nop

;}
