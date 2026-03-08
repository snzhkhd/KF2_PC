#include "recomp.h"
#include "disable_warnings.h"

void IsConsumable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // slti        $v1, $a0, 0x51
    ctx->r3 = SIGNED(ctx->r4) < 0X51 ? 1 : 0;
    // beq         $v1, $zero, L_8002B3B0
    if (ctx->r3 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8002B3B0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // slti        $v0, $a0, 0x47
    ctx->r2 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_8002B3B0:
    // jr          $ra
    // nop

    return;
    // nop

;}
