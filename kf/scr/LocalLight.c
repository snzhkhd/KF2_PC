#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_LocalLight(uint8_t* rdram, recomp_context* ctx) {
    // a0 (r4) - нормаль (вход)
    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r4);
    // a1 (r5) - цвет (результат, long vector)
    VECTOR* v1 = (VECTOR*)GET_PTR(ctx->r5);

    if (v0 && v1) {
        ctx_to_gte(ctx);
        LocalLight(v0, v1);
        gte_to_ctx(ctx);
    }

    ;
}
