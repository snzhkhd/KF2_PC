#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libetc.h"

void SyncVSyncStatus(uint8_t* rdram, recomp_context* ctx)
{
    ctx->r2 = VSync(-1) + 240;
    ///*
    //ctx->r2 = 0;
    //*/
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $sp, $sp, -0x18
    //ctx->r29 = ADD32(ctx->r29, -0X18);
    //// sw          $ra, 0x10($sp)
    //MEM_W(0X10, ctx->r29) = ctx->r31;
    //// jal         0x8006263C
    //// addiu       $a0, $zero, -0x1
    //ctx->r4 = ADD32(0, -0X1);
    //KF_VSync(rdram, ctx);
    //goto after_0;
    //// addiu       $a0, $zero, -0x1
    //ctx->r4 = ADD32(0, -0X1);
    //after_0:
    //// addiu       $v0, $v0, 0xF0
    //ctx->r2 = ADD32(ctx->r2, 0XF0);
    //// lui         $at, 0x8007
    //ctx->r1 = S32(0X8007 << 16);
    //// sw          $v0, 0x62B8($at)
    //MEM_W(0X62B8, ctx->r1) = ctx->r2;
    //// lui         $at, 0x8007
    //ctx->r1 = S32(0X8007 << 16);
    //// sw          $zero, 0x62BC($at)
    //MEM_W(0X62BC, ctx->r1) = 0;
    //// lw          $ra, 0x10($sp)
    //ctx->r31 = MEM_W(0X10, ctx->r29);
    //// addiu       $sp, $sp, 0x18
    //ctx->r29 = ADD32(ctx->r29, 0X18);
    //// jr          $ra
    //// nop
    //
    //return;
    //// nop

    ;
}
