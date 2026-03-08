#include "recomp.h"
#include "disable_warnings.h"

void Heap_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $a1, -0x10
    ctx->r2 = ADD32(ctx->r5, -0X10);
    // addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // jr          $ra
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
;}
