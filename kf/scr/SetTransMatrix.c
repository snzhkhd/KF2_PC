#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetTransMatrix(uint8_t* rdram, recomp_context* ctx)
{
    // r4 (a0) содержит PS1-адрес структуры MATRIX
    MATRIX* m = (MATRIX*)GET_PTR(ctx->r4);

    if (m) {
        ctx_to_gte(ctx);
        SetTransMatrix(m);
        gte_to_ctx(ctx);
    }
}