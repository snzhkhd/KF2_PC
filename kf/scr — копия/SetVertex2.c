#include "recomp.h"
#include "disable_warnings.h"

void SetVertex2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lwc2        $4, 0x0($a0)
    gte_lwc2(rdram, ctx, 4, 4, 0);
    // lwc2        $5, 0x4($a0)
    gte_lwc2(rdram, ctx, 5, 4, 4);
    // jr          $ra
    // nop

    return;
    // nop

;}
