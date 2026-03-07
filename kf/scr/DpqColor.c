#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/inline_c.h"
#include "psx/gtemac.h"
#include "psx/gtereg.h"

void KF_DpqColor(uint8_t* rdram, recomp_context* ctx) {
    CVECTOR* v0 = (CVECTOR*)GET_PTR(ctx->r4); // Входной цвет
    int p = (int)ctx->r5;               // Параметр глубины
    CVECTOR* v1 = (CVECTOR*)GET_PTR(ctx->r6); // Результирующий цвет

    if (v0 && v1) {
        ctx_to_gte(ctx);
        gte_DpqColor(v0, &p, v1);
        gte_to_ctx(ctx);
    }
}