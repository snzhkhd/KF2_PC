#include "recomp.h"
#include "disable_warnings.h"

void AverageSZ4_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // .word       0x4B68002E                   # INVALID     $k1, $t0, 0x2E # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B68002E);
    // mfc2        $v0, $7
    ctx->r2 = gte_mfc2(ctx, 7);
    // jr          $ra
    // nop

    return;
    // nop

;}
