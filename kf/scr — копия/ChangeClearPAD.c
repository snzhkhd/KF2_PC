#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_ChangeClearPAD(uint8_t* rdram, recomp_context* ctx) {
    int mode = (int)ctx->r4;
    // В Psy-X это обычно управляет тем, очищать ли буфер при чтении
    ChangeClearPAD(mode);
    ;
}
