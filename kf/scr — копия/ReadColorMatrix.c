#include "recomp.h"
#include "disable_warnings.h"

void ReadColorMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // cfc2        $t0, $16
    ctx->r8 = gte_cfc2(ctx, 16);
    // cfc2        $t1, $17
    ctx->r9 = gte_cfc2(ctx, 17);
    // cfc2        $t2, $18
    ctx->r10 = gte_cfc2(ctx, 18);
    // cfc2        $t3, $19
    ctx->r11 = gte_cfc2(ctx, 19);
    // cfc2        $t4, $20
    ctx->r12 = gte_cfc2(ctx, 20);
    // sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // sw          $t4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r12;
    // cfc2        $t0, $21
    ctx->r8 = gte_cfc2(ctx, 21);
    // cfc2        $t1, $22
    ctx->r9 = gte_cfc2(ctx, 22);
    // cfc2        $t2, $23
    ctx->r10 = gte_cfc2(ctx, 23);
    // sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // jr          $ra
    // nop

    return;
    // nop

;}
