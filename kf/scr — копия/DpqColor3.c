#include "recomp.h"
#include "disable_warnings.h"

void DpqColor3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lwc2        $20, 0x0($a0)
    gte_lwc2(rdram, ctx, 20, 4, 0);
    // lwc2        $21, 0x0($a1)
    gte_lwc2(rdram, ctx, 21, 5, 0);
    // lwc2        $22, 0x0($a2)
    gte_lwc2(rdram, ctx, 22, 6, 0);
    // lwc2        $6, 0x0($a2)
    gte_lwc2(rdram, ctx, 6, 6, 0);
    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
    // nop

    // .word       0x4AF8002A                   # INVALID     $s7, $t8, 0x2A # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AF8002A);
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(0X14, ctx->r29);
    // lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(0X18, ctx->r29);
    // swc2        $20, 0x0($t0)
    gte_swc2(rdram, ctx, 20, 8, 0);
    // swc2        $21, 0x0($t1)
    gte_swc2(rdram, ctx, 21, 9, 0);
    // swc2        $22, 0x0($t2)
    gte_swc2(rdram, ctx, 22, 10, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
