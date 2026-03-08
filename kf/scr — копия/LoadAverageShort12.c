#include "recomp.h"
#include "disable_warnings.h"

void LoadAverageShort12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(0X4, ctx->r4);
    // sra         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8) >> 16;
    // andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // andi        $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 & 0XFFFF;
    // mtc2        $a2, $8
    gte_mtc2(ctx, 6, 8);
    // mtc2        $t0, $9
    gte_mtc2(ctx, 8, 9);
    // mtc2        $t1, $10
    gte_mtc2(ctx, 9, 10);
    // mtc2        $t2, $11
    gte_mtc2(ctx, 10, 11);
    // nop

    // .word       0x4B98003D                   # INVALID     $gp, $t8, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B98003D);
    // lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(0X0, ctx->r5);
    // lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(0X4, ctx->r5);
    // sra         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8) >> 16;
    // andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // andi        $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 & 0XFFFF;
    // mfc2        $v0, $31
    ctx->r2 = gte_mfc2(ctx, 31);
    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
    // mtc2        $t0, $9
    gte_mtc2(ctx, 8, 9);
    // mtc2        $t1, $10
    gte_mtc2(ctx, 9, 10);
    // mtc2        $t2, $11
    gte_mtc2(ctx, 10, 11);
    // nop

    // .word       0x4BA8003E                   # INVALID     $sp, $t0, 0x3E # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4BA8003E);
    // mfc2        $t0, $9
    ctx->r8 = gte_mfc2(ctx, 9);
    // mfc2        $t1, $10
    ctx->r9 = gte_mfc2(ctx, 10);
    // andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(0X10, ctx->r29);
    // mfc2        $t2, $11
    ctx->r10 = gte_mfc2(ctx, 11);
    // sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // jr          $ra
    // nop

    return;
    // nop

;}
