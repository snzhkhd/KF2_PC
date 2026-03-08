#include "recomp.h"
#include "disable_warnings.h"

void SetVertexTri(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lwc2        $0, 0x0($a0)
    gte_lwc2(rdram, ctx, 0, 4, 0);
    // lwc2        $1, 0x4($a0)
    gte_lwc2(rdram, ctx, 1, 4, 4);
    // lwc2        $2, 0x0($a1)
    gte_lwc2(rdram, ctx, 2, 5, 0);
    // lwc2        $3, 0x4($a1)
    gte_lwc2(rdram, ctx, 3, 5, 4);
    // lwc2        $4, 0x0($a2)
    gte_lwc2(rdram, ctx, 4, 6, 0);
    // lwc2        $5, 0x4($a2)
    gte_lwc2(rdram, ctx, 5, 6, 4);
    // jr          $ra
    // nop

    return;
    // nop

;}
