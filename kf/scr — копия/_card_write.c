#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_card_write(uint8_t* rdram, recomp_context* ctx) {
    int chan = (int)ctx->r4;
    int block = (int)ctx->r5;
    uint8_t* buf = (uint8_t*)GET_PTR(ctx->r6);

    //Psy-X
    ctx->r2 = (uint32_t)_card_write(chan, block, buf);
    ;
}
