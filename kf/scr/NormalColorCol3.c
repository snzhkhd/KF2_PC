#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_NormalColorCol3(uint8_t* rdram, recomp_context* ctx) {
    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r4);
    SVECTOR* v1 = (SVECTOR*)GET_PTR(ctx->r5);
    SVECTOR* v2 = (SVECTOR*)GET_PTR(ctx->r6);
    CVECTOR* v3 = (CVECTOR*)GET_PTR(ctx->r7); // Общий цвет для всех

    CVECTOR* v4 = (CVECTOR*)GET_PTR(MEM_W(16, ctx->r29));
    CVECTOR* v5 = (CVECTOR*)GET_PTR(MEM_W(20, ctx->r29));
    CVECTOR* v6 = (CVECTOR*)GET_PTR(MEM_W(24, ctx->r29));
    ctx_to_gte(ctx);
    NormalColorCol3(v0, v1, v2, v3, v4, v5, v6);
    gte_to_ctx(ctx);
}