#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_ApplyRotMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // mtc2        $t0, $0
    gte_mtc2(ctx, 8, 0);
    // mtc2        $t1, $1
    gte_mtc2(ctx, 9, 1);
    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // swc2        $9, 0x0($a1)
    gte_swc2(rdram, ctx, 9, 5, 0);
    // swc2        $10, 0x4($a1)
    gte_swc2(rdram, ctx, 10, 5, 4);
    // swc2        $11, 0x8($a1)
    gte_swc2(rdram, ctx, 11, 5, 8);
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // jr          $ra
    // nop

    return;
    // nop
}