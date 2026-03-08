#include "recomp.h"
#include "disable_warnings.h"

void SsUtSetVVol_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bne         $a0, $at, L_80059470
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80059470;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80059470
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80059470;
    }
    // nop

    // break       6
    do_break(2147849324);
L_80059470:
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sh          $a1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r5;
    // sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
    // jr          $ra
    // nop

    return;
    // nop

;}
