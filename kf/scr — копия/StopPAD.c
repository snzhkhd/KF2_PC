#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_StopPAD(uint8_t* rdram, recomp_context* ctx) {
    StopPAD();
}
