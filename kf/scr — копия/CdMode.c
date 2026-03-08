#include "recomp.h"
#include "disable_warnings.h"

void KF_CdMode(uint8_t* rdram, recomp_context* ctx) 
{
    printf("KF_CdMode\n");
    ctx->r2 = 0;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lbu         $v0, -0xB67($v0)
    //ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
