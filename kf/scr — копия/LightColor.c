#include "recomp.h"
#include "disable_warnings.h"

void LightColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lwc2        $9, 0x0($a0)
    gte_lwc2(rdram, ctx, 9, 4, 0);
    // lwc2        $10, 0x4($a0)
    gte_lwc2(rdram, ctx, 10, 4, 4);
    // lwc2        $11, 0x8($a0)
    gte_lwc2(rdram, ctx, 11, 4, 8);
    // nop

    // .word       0x4A4DA412                   # INVALID     $s2, $t5, -0x5BEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A4DA412);
    // swc2        $9, 0x0($a1)
    gte_swc2(rdram, ctx, 9, 5, 0);
    // swc2        $10, 0x4($a1)
    gte_swc2(rdram, ctx, 10, 5, 4);
    // swc2        $11, 0x8($a1)
    gte_swc2(rdram, ctx, 11, 5, 8);
    // jr          $ra
    // nop

    return;
    // nop

;}
