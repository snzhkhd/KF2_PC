#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"


void KF_SetDQB(uint8_t* rdram, recomp_context* ctx) {
    // Аргумент iDQB в r4 (a0)
    SetDQB((int)ctx->r4);
}
