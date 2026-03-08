#include "recomp.h"
#include "disable_warnings.h"

void _SsVmDamperOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $zero, -0x1F34($at)
    MEM_H(-0X1F34, ctx->r1) = 0;
    // jr          $ra
    // nop

    return;
    // nop

;}
