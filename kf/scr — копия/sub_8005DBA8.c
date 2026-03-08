#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetDQA(uint8_t* rdram, recomp_context* ctx) {
    // Аргумент iDQA в r4 (a0)
    SetDQA((int)ctx->r4);
}