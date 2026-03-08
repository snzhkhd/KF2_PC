#include "recomp.h"
#include "disable_warnings.h"
#include "psx/gtereg.h"

void sub_8005F2C8(uint8_t* rdram, recomp_context* ctx) 
{
    //// Дамп матрицы вращения (R11-R33) из GTE ctrl
    //printf("[RTPS] R=%04X %04X %04X | %04X %04X %04X | %04X %04X %04X\n",
    //    ctx->cp2c[0] & 0xFFFF, ctx->cp2c[0] >> 16,
    //    ctx->cp2c[1] & 0xFFFF, ctx->cp2c[1] >> 16,
    //    ctx->cp2c[2] & 0xFFFF,
    //    ctx->cp2c[3] & 0xFFFF, ctx->cp2c[3] >> 16,
    //    ctx->cp2c[4] & 0xFFFF, ctx->cp2c[4] >> 16);
    //printf("[RTPS] TRX=%d TRY=%d TRZ=%d H=%d\n",
    //    (int32_t)ctx->cp2c[5], (int32_t)ctx->cp2c[6],
    //    (int32_t)ctx->cp2c[7], ctx->cp2c[26] & 0xFFFF);
    //printf("sub_8005F2C8\n");
    // a0 = вектор (SVECTOR*), a1 = SXY out, a2 = SZ out, a3 = flags out
    uint32_t vec_addr = ctx->r4;
    uint32_t sxy_addr = ctx->r5;
    uint32_t sz_addr = ctx->r6;
    uint32_t* flags = (uint32_t*)GET_PTR(ctx->r7);

    // lwc2 $0, 0($a0) / lwc2 $1, 4($a0)
    ctx->cp2d[0] = MEM_W(0, vec_addr);
    ctx->cp2d[1] = MEM_W(4, vec_addr);

    // cop2 0x180001 = RTPS
    ctx_to_gte(ctx);
    GTE_operator(0x180001);
    gte_to_ctx(ctx);

    // swc2 $14, 0($a1) → SXY2 (cp2d[14])
    WRITE_W(sxy_addr, ctx->cp2d[14]);
    // swc2 $8, 0($a2) → SZ (cp2d[8])  
    WRITE_W(sz_addr, ctx->cp2d[8]);

    // cfc2 $v1, $31 → FLAG register (cp2c[31])
    ctx->r3 = ctx->cp2c[31];
    // mfc2 $v0, $19 → IR3 (cp2d[11])
    ctx->r2 = ctx->cp2d[11] >> 2; // >> 2 как в оригинале

    if (flags)
        *flags = ctx->r3;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lwc2        $0, 0x0($a0)
    //gte_lwc2(rdram, ctx, 0, 4, 0);
    //// lwc2        $1, 0x4($a0)
    //gte_lwc2(rdram, ctx, 1, 4, 4);
    //// nop

    //// .word       0x4A180001                   # INVALID     $s0, $t8, 0x1 # 00000000 <InstrIdType: CPU_COP2>
    //gte_command(ctx, 0x4A180001);
    //// swc2        $14, 0x0($a1)
    //gte_swc2(rdram, ctx, 14, 5, 0);
    //// swc2        $8, 0x0($a2)
    //gte_swc2(rdram, ctx, 8, 6, 0);
    //// cfc2        $v1, $31
    //ctx->r3 = gte_cfc2(ctx, 31);
    //// mfc2        $v0, $19
    //ctx->r2 = gte_mfc2(ctx, 19);
    //// sw          $v1, 0x0($a3)
    //MEM_W(0X0, ctx->r7) = ctx->r3;
    //// jr          $ra
    //// sra         $v0, $v0, 2
    //ctx->r2 = S32(ctx->r2) >> 2;
    //return;
    //// sra         $v0, $v0, 2
    //ctx->r2 = S32(ctx->r2) >> 2;
;}
