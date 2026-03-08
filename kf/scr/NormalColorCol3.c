#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_NormalColorCol3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // lwc2        $0, 0x0($a0)
    gte_lwc2(rdram, ctx, 0, 4, 0);
    // lwc2        $1, 0x4($a0)
    gte_lwc2(rdram, ctx, 1, 4, 4);
    // lwc2        $2, 0x0($a1)
    gte_lwc2(rdram, ctx, 2, 5, 0);
    // lwc2        $3, 0x4($a1)
    gte_lwc2(rdram, ctx, 3, 5, 4);
    // lwc2        $4, 0x0($a2)
    gte_lwc2(rdram, ctx, 4, 6, 0);
    // lwc2        $5, 0x4($a2)
    gte_lwc2(rdram, ctx, 5, 6, 4);
    // lwc2        $6, 0x0($a3)
    gte_lwc2(rdram, ctx, 6, 7, 0);
    // nop

    // .word       0x4B18043F                   # INVALID     $t8, $t8, 0x43F # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B18043F);
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
}