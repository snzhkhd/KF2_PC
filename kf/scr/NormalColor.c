#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_NormalColor(uint8_t* rdram, recomp_context* ctx) {
    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r4); // Нормаль
    CVECTOR* v1 = (CVECTOR*)GET_PTR(ctx->r5); // Результат (Цвет)
    ctx_to_gte(ctx);
    NormalColor(v0, v1);
    gte_to_ctx(ctx);
}