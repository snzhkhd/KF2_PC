#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetDefDispEnv(uint8_t* rdram, recomp_context* ctx)
{
    DISPENV* env = (DISPENV*)GET_PTR(ctx->r4);
    int x = (int)ctx->r5;
    int y = (int)ctx->r6;
    int w = (int)ctx->r7;
    int h = (int)MEM_W(16, ctx->r29);

    if (env) {
        printf("[HLE GPU] SetDefDispEnv(env=0x%08X, x=%d, y=%d, w=%d, h=%d)\n", ctx->r4, x, y, w, h);
        SetDefDispEnv(env, x, y, w, h);
    }
    ctx->r2 = ctx->r4;
}