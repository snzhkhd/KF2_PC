#include "recomp.h"
#include "disable_warnings.h"

void KF_CdFlush(uint8_t* rdram, recomp_context* ctx) 
{
    printf("CdFlush\n");
    ctx->r2 = 0;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, -0xB7C($v0)
    //ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    //// lui         $at, 0x8007
    //ctx->r1 = S32(0X8007 << 16);
    //// sw          $a0, -0xB7C($at)
    //MEM_W(-0XB7C, ctx->r1) = ctx->r4;
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
