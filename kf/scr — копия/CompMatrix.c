#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

// MATRIX* CompMatrix(MATRIX* m0, MATRIX* m1, MATRIX* m2);
void KF_CompMatrix(uint8_t* rdram, recomp_context* ctx) {
    MATRIX* m0 = (MATRIX*)GET_PTR(ctx->r4); // a0
    MATRIX* m1 = (MATRIX*)GET_PTR(ctx->r5); // a1
    MATRIX* m2 = (MATRIX*)GET_PTR(ctx->r6); // a2 - результат (m0 * m1)

    if (m0 && m1 && m2) 
    {
        ctx_to_gte(ctx);
        CompMatrix(m0, m1, m2);
        gte_to_ctx(ctx);
    }

    // Возвращаем в v0 адрес результирующей матрицы (из r6)
    ctx->r2 = ctx->r6;
}