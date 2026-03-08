#include "recomp.h"
#include "disable_warnings.h"


void KF_NormalColorDpq(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // lwc2        $0, 0x0($a0)
    gte_lwc2(rdram, ctx, 0, 4, 0);
    // lwc2        $1, 0x4($a0)
    gte_lwc2(rdram, ctx, 1, 4, 4);
    // lwc2        $6, 0x0($a1)
    gte_lwc2(rdram, ctx, 6, 5, 0);
    // mtc2        $a2, $8
    gte_mtc2(ctx, 6, 8);
    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // swc2        $22, 0x0($a3)
    gte_swc2(rdram, ctx, 22, 7, 0);
    // jr          $ra
    // nop

    return;
    // nop

}