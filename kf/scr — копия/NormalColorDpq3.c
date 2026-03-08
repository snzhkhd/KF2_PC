#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/gtemac.h"
#include "psx/inline_c.h"

#include "psx/gtereg.h"
#include <string>

void KF_NormalColorDpq3(uint8_t* rdram, recomp_context* ctx) 
{
    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r4);
    SVECTOR* v1 = (SVECTOR*)GET_PTR(ctx->r5);
    SVECTOR* v2 = (SVECTOR*)GET_PTR(ctx->r6);
    CVECTOR* v3 = (CVECTOR*)GET_PTR(ctx->r7);
    long     p = (long)(int32_t)MEM_W(16, ctx->r29);
    CVECTOR* v4 = (CVECTOR*)GET_PTR(MEM_W(20, ctx->r29));
    CVECTOR* v5 = (CVECTOR*)GET_PTR(MEM_W(24, ctx->r29));
    CVECTOR* v6 = (CVECTOR*)GET_PTR(MEM_W(28, ctx->r29));

    ctx_to_gte(ctx);
    gte_NormalColorDpq3(v0, v1, v2, v3, &p, v4, v5, v6);
    gte_to_ctx(ctx);
}













//void KF_NormalColorDpq3(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lwc2        $0, 0x0($a0)
//    gte_lwc2(rdram, ctx, 0, 4, 0);
//    // lwc2        $1, 0x4($a0)
//    gte_lwc2(rdram, ctx, 1, 4, 4);
//    // lwc2        $2, 0x0($a1)
//    gte_lwc2(rdram, ctx, 2, 5, 0);
//    // lwc2        $3, 0x4($a1)
//    gte_lwc2(rdram, ctx, 3, 5, 4);
//    // lwc2        $4, 0x0($a2)
//    gte_lwc2(rdram, ctx, 4, 6, 0);
//    // lwc2        $5, 0x4($a2)
//    gte_lwc2(rdram, ctx, 5, 6, 4);
//    // lwc2        $6, 0x0($a3)
//    gte_lwc2(rdram, ctx, 6, 7, 0);
//    // lwc2        $8, 0x10($sp)
//    gte_lwc2(rdram, ctx, 8, 29, 16);
//    // nop
//
//    // .word       0x4AF80416                   # INVALID     $s7, $t8, 0x416 # 00000000 <InstrIdType: CPU_COP2>
//    gte_command(ctx, 0x4AF80416);
//    // lw          $t0, 0x14($sp)
//    ctx->r8 = MEM_W(0X14, ctx->r29);
//    // lw          $t1, 0x18($sp)
//    ctx->r9 = MEM_W(0X18, ctx->r29);
//    // lw          $t2, 0x1C($sp)
//    ctx->r10 = MEM_W(0X1C, ctx->r29);
//    // swc2        $20, 0x0($t0)
//    gte_swc2(rdram, ctx, 20, 8, 0);
//    // swc2        $21, 0x0($t1)
//    gte_swc2(rdram, ctx, 21, 9, 0);
//    // swc2        $22, 0x0($t2)
//    gte_swc2(rdram, ctx, 22, 10, 0);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
