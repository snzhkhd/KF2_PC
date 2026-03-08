#include "recomp.h"
#include "disable_warnings.h"

void sub_80017C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5A54
    ctx->r2 = ADD32(ctx->r2, -0X5A54);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A50($a0)
    ctx->r4 = MEM_W(-0X5A50, ctx->r4);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $a0, -0x5A50($at)
    MEM_W(-0X5A50, ctx->r1) = ctx->r4;
    // jr          $ra
    // nop

    return;
    // nop

;}
