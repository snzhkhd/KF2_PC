#include "recomp.h"
#include "disable_warnings.h"

void DMACallback(uint8_t* rdram, recomp_context* ctx) 
{
    //callbalck
    sub_80050A2C(rdram, ctx);
    ctx->r2 = 0;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x60CC($v0)
    //ctx->r2 = MEM_W(0X60CC, ctx->r2);
    //// addiu       $sp, $sp, -0x18
    //ctx->r29 = ADD32(ctx->r29, -0X18);
    //// sw          $ra, 0x10($sp)
    //MEM_W(0X10, ctx->r29) = ctx->r31;
    //// lw          $v0, 0x4($v0)
    //ctx->r2 = MEM_W(0X4, ctx->r2);
    //// nop

    //// jalr        $v0
    //// nop

    //LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    //goto after_0;
    //// nop

    //after_0:
    //// lw          $ra, 0x10($sp)
    //ctx->r31 = MEM_W(0X10, ctx->r29);
    //// addiu       $sp, $sp, 0x18
    //ctx->r29 = ADD32(ctx->r29, 0X18);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
