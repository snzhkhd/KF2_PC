#include "recomp.h"
#include "disable_warnings.h"

void GsGetWorkBase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x5040($v0)
    ctx->r2 = MEM_W(0X5040, ctx->r2);
    // jr          $ra
    // nop

    return;
    // nop

;}
