#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_card_info(uint8_t* rdram, recomp_context* ctx) {
    int chan = (int)ctx->r4; // Номер порта (0 или 1)

    ctx->r2 = (uint32_t)_card_info(chan);
    ;
}
