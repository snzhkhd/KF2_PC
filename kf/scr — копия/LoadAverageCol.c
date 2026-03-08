#include "recomp.h"
#include "disable_warnings.h"

void LoadAverageCol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(0X0, ctx->r4);
    // lbu         $t1, 0x1($a0)
    ctx->r9 = MEM_BU(0X1, ctx->r4);
    // lbu         $t2, 0x2($a0)
    ctx->r10 = MEM_BU(0X2, ctx->r4);
    // mtc2        $a2, $8
    gte_mtc2(ctx, 6, 8);
    // mtc2        $t0, $9
    gte_mtc2(ctx, 8, 9);
    // mtc2        $t1, $10
    gte_mtc2(ctx, 9, 10);
    // mtc2        $t2, $11
    gte_mtc2(ctx, 10, 11);
    // nop

    // .word       0x4B90003D                   # INVALID     $gp, $s0, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B90003D);
    // lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(0X0, ctx->r5);
    // lbu         $t1, 0x1($a1)
    ctx->r9 = MEM_BU(0X1, ctx->r5);
    // lbu         $t2, 0x2($a1)
    ctx->r10 = MEM_BU(0X2, ctx->r5);
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
    // addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // .word       0x4BA0003E                   # INVALID     $sp, $zero, 0x3E # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4BA0003E);
    // lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(0X10, ctx->r29);
    // mfc2        $t0, $25
    ctx->r8 = gte_mfc2(ctx, 25);
    // mfc2        $t1, $26
    ctx->r9 = gte_mfc2(ctx, 26);
    // mfc2        $t2, $27
    ctx->r10 = gte_mfc2(ctx, 27);
    // srav        $t0, $t0, $t3
    ctx->r8 = S32(ctx->r8) >> (ctx->r11 & 31);
    // srav        $t1, $t1, $t3
    ctx->r9 = S32(ctx->r9) >> (ctx->r11 & 31);
    // srav        $t2, $t2, $t3
    ctx->r10 = S32(ctx->r10) >> (ctx->r11 & 31);
    // sb          $t0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r8;
    // sb          $t1, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r9;
    // sb          $t2, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r10;
    // jr          $ra
    // nop

    return;
    // nop

;}
