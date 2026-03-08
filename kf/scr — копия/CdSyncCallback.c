#include "..//kf_cd.h"
#include "disable_warnings.h"

void KF_CdSyncCallback(uint8_t* rdram, recomp_context* ctx) 
{
	KFCD_CdSyncCallback(rdram, ctx);
}

//void KF_CdSyncCallback(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB84($v0)
//    ctx->r2 = MEM_W(-0XB84, ctx->r2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $a0, -0xB84($at)
//    MEM_W(-0XB84, ctx->r1) = ctx->r4;
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
