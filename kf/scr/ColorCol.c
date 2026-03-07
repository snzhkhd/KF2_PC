#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_ColorCol(uint8_t* rdram, recomp_context* ctx) {
    VECTOR* v0 = (VECTOR*)GET_PTR(ctx->r4);  // Вектор света
    CVECTOR* v1 = (CVECTOR*)GET_PTR(ctx->r5); // Цвет материала
    CVECTOR* v2 = (CVECTOR*)GET_PTR(ctx->r6); // Результат

    if (v0 && v1 && v2) {
        ctx_to_gte(ctx);
        ColorCol(v0, v1, v2);
        gte_to_ctx(ctx);
    }
}