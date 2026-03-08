#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"
//void sub_800678F8(uint8_t* rdram, recomp_context* ctx)

void KF_SetDefDrawEnv(uint8_t* rdram, recomp_context* ctx)
{
    DRAWENV* env = (DRAWENV*)GET_PTR(ctx->r4);
    int x = (int)ctx->r5;
    int y = (int)ctx->r6;
    int w = (int)ctx->r7;
    // Читаем 5-й аргумент со стека
    int h = (int)MEM_W(16, ctx->r29);

    if (env) {
        printf("[HLE GPU] SetDefDrawEnv(env=0x%08X, x=%d, y=%d, w=%d, h=%d)\n", ctx->r4, x, y, w, h);
        SetDefDrawEnv(env, x, y, w, h);

        // ВАЖНО: FromSoftware часто не включают 'isbg' (автоочистку) здесь, 
        // но если экран голубой - возможно она включилась.
        // Стандарт: env->isbg = 0; env->r0 = 0; env->g0 = 0; env->b0 = 0;
    }
    ctx->r2 = ctx->r4;
}