#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $v0, -0x1F34($at)
    MEM_H(-0X1F34, ctx->r1) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
