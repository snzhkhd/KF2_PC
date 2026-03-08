#include "recomp.h"
#include "disable_warnings.h"

#include "psx/libgte.h" 

void KF_ApplyMatrix(uint8_t* rdram, recomp_context* ctx)
{
    MATRIX* m = (MATRIX*)GET_PTR(ctx->r4);  // a0
    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r5); // a1
    VECTOR* v1 = (VECTOR*)GET_PTR(ctx->r6);  // a2
    ctx_to_gte(ctx);
    ApplyMatrix(m, v0, v1);
    gte_to_ctx(ctx);
    ctx->r2 = ctx->r6; // Возвращаем указатель на результат (v1)
}

