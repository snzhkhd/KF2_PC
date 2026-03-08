#include "recomp.h"
#include "disable_warnings.h"

void Lzc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mtc2        $a0, $30
    gte_mtc2(ctx, 4, 30);
    // nop

    // nop

    // mfc2        $v0, $31
    ctx->r2 = gte_mfc2(ctx, 31);
    // jr          $ra
    // nop

    return;
    // nop

;}
