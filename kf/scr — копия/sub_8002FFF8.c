#include "recomp.h"
#include "disable_warnings.h"

void sub_8002FFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $a0, 0xB54($at)
    MEM_W(0XB54, ctx->r1) = ctx->r4;
    // jr          $ra
    // nop

    return;
    // nop

;}
