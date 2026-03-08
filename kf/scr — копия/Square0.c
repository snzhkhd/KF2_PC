#include "recomp.h"
#include "disable_warnings.h"

void Square0(uint8_t* rdram, recomp_context* ctx) {
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

    // .word       0x4AA00428                   # INVALID     $s5, $zero, 0x428 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AA00428);
    // swc2        $25, 0x0($a1)
    gte_swc2(rdram, ctx, 25, 5, 0);
    // swc2        $26, 0x4($a1)
    gte_swc2(rdram, ctx, 26, 5, 4);
    // swc2        $27, 0x8($a1)
    gte_swc2(rdram, ctx, 27, 5, 8);
    // jr          $ra
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
