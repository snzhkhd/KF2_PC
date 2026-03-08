#include "..//kf_cd.h"
#include "disable_warnings.h"


void KF_CdReadyCallback(uint8_t* rdram, recomp_context* ctx) {
	KFCD_CdReadyCallback(rdram, ctx);
}


//void KF_CdReadyCallback(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB80($v0)
//    ctx->r2 = MEM_W(-0XB80, ctx->r2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $a0, -0xB80($at)
//    MEM_W(-0XB80, ctx->r1) = ctx->r4;
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
