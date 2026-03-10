#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "psx/libetc.h"
#include <chrono>
#include <SDL2/SDL_timer.h>



static auto g_lastFrameTime = std::chrono::steady_clock::now();
const double FRAME_INTERVAL = 1.0 / 24.0; 

static auto g_lastSeqTime = std::chrono::steady_clock::now();
static double g_seqAccumulator = 0.0;
const double SEQ_TICK_INTERVAL = 1.0 / 60.0; // 60Hz

void SEQ_Update(uint8_t* rdram, recomp_context* ctx)
{
    auto now = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(now - g_lastSeqTime).count();

    g_lastSeqTime = now;
    g_seqAccumulator += elapsed;
    while (g_seqAccumulator >= SEQ_TICK_INTERVAL)
    {
        KF_SsSeqCalledTbyT(rdram, ctx);
        g_seqAccumulator -= SEQ_TICK_INTERVAL;
    }
}


void KF_VSync(uint8_t* rdram, recomp_context* ctx) 
{

    // Тик SEQ секвенсора
    uint32_t saved_r4 = ctx->r4;
    uint32_t saved_ra = ctx->r31;

    static int vsync_count = 0;
    static auto vsync_start = std::chrono::steady_clock::now();
    vsync_count++;
    auto now = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(now - g_lastFrameTime).count();

   /* auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - vsync_start).count();
    if (ms >= 1000) {
        printf("[VSync] calls/sec: %d\n", vsync_count);
        vsync_count = 0;
        vsync_start = now;
    }*/




    if (elapsed < FRAME_INTERVAL) {
        int sleepMs = (int)((FRAME_INTERVAL - elapsed) * 1000.0);
        if (sleepMs > 1) SDL_Delay(sleepMs);
    }
    g_lastFrameTime = std::chrono::steady_clock::now();


  
    SEQ_Update(rdram, ctx);
   


   


    ctx->r4 = saved_r4;
    ctx->r31 = saved_ra;

    g_vsync_pending = true;

    int mode = (int32_t)ctx->r4;
    ctx->r2 = 0;// VSync(mode == 0 ? 1 : mode);
    WRITE_W(0x1F801814, 0x1C000000);
}
