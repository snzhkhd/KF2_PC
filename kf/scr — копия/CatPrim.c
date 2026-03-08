#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_CatPrim(uint8_t* rdram, recomp_context* ctx)
{

    void* p0 = GET_PTR(ctx->r4);
    void* p1 = GET_PTR(ctx->r5);

    if (p0 && p1)
        CatPrim(p0, p1);
    ;
}
