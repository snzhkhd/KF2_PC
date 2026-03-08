#include "recomp.h"
#include "disable_warnings.h"

void NormalClipS(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // mfc2        $v0, $24
    ctx->r2 = gte_mfc2(ctx, 24);
    // jr          $ra
    // nop

    return;
    // nop

;}
