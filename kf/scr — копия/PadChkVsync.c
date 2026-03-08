#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libpad.h"

void KF_PadChkVsync(uint8_t* rdram, recomp_context* ctx) {
    
    ctx->r2 = PadChkVsync();
;}
