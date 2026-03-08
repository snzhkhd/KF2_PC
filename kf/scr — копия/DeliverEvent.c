#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_DeliverEvent(uint8_t* rdram, recomp_context* ctx) {
    DeliverEvent((unsigned int)ctx->r4, (int)ctx->r5);
    ;
}
