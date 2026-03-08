#include "recomp.h"
#include "disable_warnings.h"

void OnCDReadComplete(uint8_t* rdram, recomp_context* ctx) 
{
 // printf("OnCDReadComplete\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jr          $ra
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
;}
