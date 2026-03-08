#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_DisableEvent(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (uint32_t)DisableEvent((unsigned int)ctx->r4);
    ;
}
