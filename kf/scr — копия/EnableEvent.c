#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_EnableEvent(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint32_t)EnableEvent((unsigned int)ctx->r4);
}