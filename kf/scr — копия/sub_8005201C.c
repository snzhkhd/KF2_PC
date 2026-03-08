#include "recomp.h"
#include "disable_warnings.h"

void sub_8005201C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a0, $zero, L_80052034
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80052034;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a0, $v0, L_80052038
    if (ctx->r4 != ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80052038;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80052038
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80052038;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80052034:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80052038:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, -0x770($at)
    MEM_W(-0X770, ctx->r1) = ctx->r4;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7B4($at)
    MEM_W(-0X7B4, ctx->r1) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
