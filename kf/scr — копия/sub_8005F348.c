#include "recomp.h"
#include "disable_warnings.h"

void sub_8005F348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lwc2        $0, 0x0($a0)
    gte_lwc2(rdram, ctx, 0, 4, 0);
    // lwc2        $1, 0x4($a0)
    gte_lwc2(rdram, ctx, 1, 4, 4);
    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($a1)
    gte_swc2(rdram, ctx, 25, 5, 0);
    // swc2        $26, 0x4($a1)
    gte_swc2(rdram, ctx, 26, 5, 4);
    // swc2        $27, 0x8($a1)
    gte_swc2(rdram, ctx, 27, 5, 8);
    // cfc2        $v0, $31
    ctx->r2 = gte_cfc2(ctx, 31);
    // jr          $ra
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    return;
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
;}
