#include "recomp.h"
#include "disable_warnings.h"

void OuterProduct12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // cfc2        $t5, $0
    ctx->r13 = gte_cfc2(ctx, 0);
    // cfc2        $t6, $2
    ctx->r14 = gte_cfc2(ctx, 2);
    // cfc2        $t7, $4
    ctx->r15 = gte_cfc2(ctx, 4);
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(0X8, ctx->r4);
    // ctc2        $t0, $0
    gte_ctc2(ctx, 8, 0);
    // ctc2        $t1, $2
    gte_ctc2(ctx, 9, 2);
    // ctc2        $t2, $4
    gte_ctc2(ctx, 10, 4);
    // lwc2        $11, 0x8($a1)
    gte_lwc2(rdram, ctx, 11, 5, 8);
    // lwc2        $9, 0x0($a1)
    gte_lwc2(rdram, ctx, 9, 5, 0);
    // lwc2        $10, 0x4($a1)
    gte_lwc2(rdram, ctx, 10, 5, 4);
    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // swc2        $25, 0x0($a2)
    gte_swc2(rdram, ctx, 25, 6, 0);
    // swc2        $26, 0x4($a2)
    gte_swc2(rdram, ctx, 26, 6, 4);
    // swc2        $27, 0x8($a2)
    gte_swc2(rdram, ctx, 27, 6, 8);
    // ctc2        $t5, $0
    gte_ctc2(ctx, 13, 0);
    // ctc2        $t6, $2
    gte_ctc2(ctx, 14, 2);
    // ctc2        $t7, $4
    gte_ctc2(ctx, 15, 4);
    // jr          $ra
    // nop

    return;
    // nop

;}
