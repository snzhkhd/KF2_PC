#include "recomp.h"
#include "disable_warnings.h"

void LoadImageWithCallback(uint8_t* rdram, recomp_context* ctx) 
{

    KF_LoadImage(rdram, ctx);

    //uint32_t* p_stream = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    //if (p_stream && *p_stream) 
    //{
    //    

    //    uint32_t stream = *p_stream;
    //    uint32_t callback_addr = MEM_W(20, stream); // CDStream+20
    //    if (callback_addr) 
    //    {
    //        recomp_func_t cb = lookup_recomp_func(callback_addr);

    //        if (cb) {
    //          //  printf("[LoadImageWithCallback] LoadImage done, calling  0x%08X\n", callback_addr);
    //            ctx->r4 = MEM_W(12, stream);;
    //            cb(rdram, ctx);
    //        }

    //       /* uint32_t ww = MEM_W(24, stream);
    //        printf("[LoadImage] ww=0x%08X\n", ww);*/
    //    }
    //}
    ctx->r2 = 0;
    return;


;}
