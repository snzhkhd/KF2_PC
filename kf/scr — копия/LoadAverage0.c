#include "recomp.h"
#include "disable_warnings.h"

void LoadAverage0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mtc2        $a2, $8
    gte_mtc2(ctx, 6, 8);
    // lwc2        $9, 0x0($a0)
    gte_lwc2(rdram, ctx, 9, 4, 0);
    // lwc2        $10, 0x4($a0)
    gte_lwc2(rdram, ctx, 10, 4, 4);
    // lwc2        $11, 0x8($a0)
    gte_lwc2(rdram, ctx, 11, 4, 8);
    // nop

    // .word       0x4B90003D                   # INVALID     $gp, $s0, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B90003D);
    // mfc2        $v0, $31
    ctx->r2 = gte_mfc2(ctx, 31);
    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
    // lwc2        $9, 0x0($a1)
    gte_lwc2(rdram, ctx, 9, 5, 0);
    // lwc2        $10, 0x4($a1)
    gte_lwc2(rdram, ctx, 10, 5, 4);
    // lwc2        $11, 0x8($a1)
    gte_lwc2(rdram, ctx, 11, 5, 8);
    // nop

    // .word       0x4BA0003E                   # INVALID     $sp, $zero, 0x3E # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4BA0003E);
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // nop

    // swc2        $9, 0x0($t0)
    gte_swc2(rdram, ctx, 9, 8, 0);
    // swc2        $10, 0x4($t0)
    gte_swc2(rdram, ctx, 10, 8, 4);
    // swc2        $11, 0x8($t0)
    gte_swc2(rdram, ctx, 11, 8, 8);
    // jr          $ra
    // nop

    return;
    // nop

;}
