#include "recomp.h"
#include "disable_warnings.h"

void AverageSZ3(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mtc2        $a0, $12
    gte_mtc2(ctx, 4, 12);
    // mtc2        $a2, $14
    gte_mtc2(ctx, 6, 14);
    // mtc2        $a1, $13
    gte_mtc2(ctx, 5, 13);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // mfc2        $v0, $24
    ctx->r2 = gte_mfc2(ctx, 24);
    // jr          $ra
    // nop

    return;
    // nop

;}
