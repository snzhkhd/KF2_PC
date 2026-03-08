#include "recomp.h"
#include "disable_warnings.h"

void VectorNormalSS(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(0X0, ctx->r4);
    // lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(0X2, ctx->r4);
    // lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(0X4, ctx->r4);
    // nop

    // addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
    // jal         0x80060C54
    // nop

    sub_80060C54(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $ra, $a3, $zero
    ctx->r31 = ADD32(ctx->r7, 0);
    // sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // jr          $ra
    // sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
    return;
    // sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
;}
