#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libetc.h"

void KF_CheckCallback(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = 0;// (uint32_t)CheckCallback();
}
