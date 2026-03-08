#include "recomp.h"
#include "disable_warnings.h"

void GetIntrMask(uint8_t* rdram, recomp_context* ctx) 
{
    ctx->r2 = 0;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x60D4($v0)
    //ctx->r2 = MEM_W(0X60D4, ctx->r2);
    //// nop

    //// lhu         $v0, 0x0($v0)
    //ctx->r2 = MEM_HU(0X0, ctx->r2);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
