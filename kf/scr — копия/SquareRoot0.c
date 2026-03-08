#include "recomp.h"
#include "disable_warnings.h"

#include "psx/libgte.h"

void KF_SquareRoot0(uint8_t* rdram, recomp_context* ctx)
{

    int a = (int)ctx->r4;
    ctx_to_gte(ctx);
    int result = SquareRoot0(a);
    gte_to_ctx(ctx);
    ctx->r2 = (uint32_t)result;

    ;
}
