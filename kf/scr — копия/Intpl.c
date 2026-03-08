#include "recomp.h"
#include "disable_warnings.h"

void Intpl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lwc2        $9, 0x0($a0)
    gte_lwc2(rdram, ctx, 9, 4, 0);
    // lwc2        $10, 0x4($a0)
    gte_lwc2(rdram, ctx, 10, 4, 4);
    // lwc2        $11, 0x8($a0)
    gte_lwc2(rdram, ctx, 11, 4, 8);
    // mtc2        $a1, $8
    gte_mtc2(ctx, 5, 8);
    // nop

    // .word       0x4A980011                   # INVALID     $s4, $t8, 0x11 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A980011);
    // swc2        $22, 0x0($a2)
    gte_swc2(rdram, ctx, 22, 6, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
