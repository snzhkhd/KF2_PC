#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_SetRotMatrix(uint8_t* rdram, recomp_context* ctx) 
{
    MATRIX* m = (MATRIX*)GET_PTR(ctx->r4);
    if (!m) return;
    //static int frame = 0;
    //if (frame++ % 60 == 0) {
    //    printf("[RotMatrix] %d %d %d | %d %d %d | %d %d %d\n",
    //        m->m[0][0], m->m[0][1], m->m[0][2],
    //        m->m[1][0], m->m[1][1], m->m[1][2],
    //        m->m[2][0], m->m[2][1], m->m[2][2]);
    //    printf("[Trans] %d %d %d\n",
    //        *(int32_t*)((uint8_t*)m + 20),
    //        *(int32_t*)((uint8_t*)m + 24),
    //        *(int32_t*)((uint8_t*)m + 28));
    //}
    // оригинальный код
    ctx_to_gte(ctx);
    SetRotMatrix(m);
    gte_to_ctx(ctx);
}
