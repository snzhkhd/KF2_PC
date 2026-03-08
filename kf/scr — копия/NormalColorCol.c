#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_NormalColorCol(uint8_t* rdram, recomp_context* ctx)     {
    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r4); // Нормаль
    CVECTOR* v1 = (CVECTOR*)GET_PTR(ctx->r5); // Цвет материала
    CVECTOR* v2 = (CVECTOR*)GET_PTR(ctx->r6); // Результат
    ctx_to_gte(ctx);
    NormalColorCol(v0, v1, v2);
    gte_to_ctx(ctx);
}