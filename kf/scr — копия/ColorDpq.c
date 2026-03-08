#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_ColorDpq(uint8_t* rdram, recomp_context* ctx) {
    // a0, a1, a2, a3 Ч все 4 регистра задействованы
    VECTOR* v0 = (VECTOR*)GET_PTR(ctx->r4);  // ¬ходной вектор света
    CVECTOR* v1 = (CVECTOR*)GET_PTR(ctx->r5); // Ѕазовый цвет (RGB)
    int      p = (int)ctx->r6;               // «начение дистанции (туман)
    CVECTOR* v2 = (CVECTOR*)GET_PTR(ctx->r7); // –езультат (куда записать)

    if (v0 && v1 && v2) 
    {
        ctx_to_gte(ctx);
        ColorDpq(v0, v1, p, v2);
        gte_to_ctx(ctx);
    }
}