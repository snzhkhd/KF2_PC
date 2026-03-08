#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/gtemac.h"
#include "psx/inline_c.h"

#include "psx/gtereg.h"
#include <string>

void KF_NormalColorDpq(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("NormalColorDpq\n");

    SVECTOR* v0 = (SVECTOR*)GET_PTR(ctx->r4);
    CVECTOR* v1 = (CVECTOR*)GET_PTR(ctx->r5);
    int      p = (int)ctx->r6;
    CVECTOR* v2 = (CVECTOR*)GET_PTR(ctx->r7);
    ctx_to_gte(ctx);
    gte_NormalColorDpq(v0, v1, &p, v2);  // макрос работает на gteRegs
    gte_to_ctx(ctx);
}