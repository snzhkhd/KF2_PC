#include "recomp.h"
#include "disable_warnings.h"

void AverageZ3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mtc2        $a0, $17
    gte_mtc2(ctx, 4, 17);
    // mtc2        $a1, $18
    gte_mtc2(ctx, 5, 18);
    // mtc2        $a2, $19
    gte_mtc2(ctx, 6, 19);
    // nop

    // .word       0x4B58002D                   # INVALID     $k0, $t8, 0x2D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B58002D);
    // mfc2        $v0, $7
    ctx->r2 = gte_mfc2(ctx, 7);
    // jr          $ra
    // nop

    return;
    // nop

;}
