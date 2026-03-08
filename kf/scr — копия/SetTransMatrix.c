#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetTransMatrix(uint8_t* rdram, recomp_context* ctx)
{
    //MATRIX* m = (MATRIX*)GET_PTR(ctx->r4);
    //if (!m) return;
    //// ctc2 $5-$7 — translation vector (offset +20,+24,+28)
    //ctx->cp2c[5] = *(uint32_t*)((uint8_t*)m + 20); // TRX
    //ctx->cp2c[6] = *(uint32_t*)((uint8_t*)m + 24); // TRY
    //ctx->cp2c[7] = *(uint32_t*)((uint8_t*)m + 28); // TRZ
    MATRIX* m = (MATRIX*)GET_PTR(ctx->r4);

    if (m) {
        ctx_to_gte(ctx);
        SetTransMatrix(m);
        gte_to_ctx(ctx);
    }
}