#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libetc.h"


void KF_StopCallback(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint32_t)StopCallback();
}