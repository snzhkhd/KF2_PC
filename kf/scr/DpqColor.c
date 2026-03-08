#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/inline_c.h"
#include "psx/gtemac.h"
#include "psx/gtereg.h"

void KF_DpqColor(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // lwc2        $6, 0x0($a0)
    gte_lwc2(rdram, ctx, 6, 4, 0);
    // mtc2        $a1, $8
    gte_mtc2(ctx, 5, 8);
    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // swc2        $22, 0x0($a2)
    gte_swc2(rdram, ctx, 22, 6, 0);
    // jr          $ra
    // nop

    return;
    // nop
}