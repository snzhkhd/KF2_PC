#include "recomp.h"
#include "disable_warnings.h"

void VectorNormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(0X8, ctx->r4);
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
    // sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // jr          $ra
    // sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    return;
    // sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
;}
