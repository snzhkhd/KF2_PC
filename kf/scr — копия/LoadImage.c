#include "recomp.h"
#include "disable_warnings.h"

void LoadImageWithCallback(uint8_t* rdram, recomp_context* ctx) 
{
    KF_LoadImage(rdram, ctx);
    
    uint32_t* p_stream = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    if (p_stream && *p_stream) 
    {
        

        uint32_t stream = *p_stream;
        uint32_t callback_addr = MEM_W(20, stream); // CDStream+20
        if (callback_addr) 
        {
            recomp_func_t cb = lookup_recomp_func(callback_addr);

            if (cb) {
            //    printf("[LoadImageWithCallback] LoadImage done, calling OnCDReadComplete\n");
                ctx->r4 = stream;
                cb(rdram, ctx);
            }

            /*uint32_t ww = MEM_W(24, stream);
            printf("[LoadImage] ww=0x%08X\n", ww);*/
        }
    }
    return;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $sp, $sp, -0x20
    //ctx->r29 = ADD32(ctx->r29, -0X20);
    //// sw          $s0, 0x10($sp)
    //MEM_W(0X10, ctx->r29) = ctx->r16;
    //// addu        $s0, $a0, $zero
    //ctx->r16 = ADD32(ctx->r4, 0);
    //// sw          $s1, 0x14($sp)
    //MEM_W(0X14, ctx->r29) = ctx->r17;
    //// addu        $s1, $a1, $zero
    //ctx->r17 = ADD32(ctx->r5, 0);
    //// lui         $a0, 0x8001
    //ctx->r4 = S32(0X8001 << 16);
    //// addiu       $a0, $a0, 0x3770
    //ctx->r4 = ADD32(ctx->r4, 0X3770);
    //// sw          $ra, 0x18($sp)
    //MEM_W(0X18, ctx->r29) = ctx->r31;
    //// jal         0x8006313C
    //// addu        $a1, $s0, $zero
    //ctx->r5 = ADD32(ctx->r16, 0);
    //JustReturn2(rdram, ctx);
    //goto after_0;
    //// addu        $a1, $s0, $zero
    //ctx->r5 = ADD32(ctx->r16, 0);
    //after_0:
    //// addu        $a1, $s0, $zero
    //ctx->r5 = ADD32(ctx->r16, 0);
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x6198($v0)
    //ctx->r2 = MEM_W(0X6198, ctx->r2);
    //// ori         $a2, $zero, 0x8
    //ctx->r6 = 0 | 0X8;
    //// lw          $a0, 0x20($v0)
    //ctx->r4 = MEM_W(0X20, ctx->r2);
    //// lw          $v0, 0x8($v0)
    //ctx->r2 = MEM_W(0X8, ctx->r2);
    //// nop

    //// jalr        $v0
    //// addu        $a3, $s1, $zero
    //ctx->r7 = ADD32(ctx->r17, 0);
    //LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    //goto after_1;
    //// addu        $a3, $s1, $zero
    //ctx->r7 = ADD32(ctx->r17, 0);
    //after_1:
    //// lw          $ra, 0x18($sp)
    //ctx->r31 = MEM_W(0X18, ctx->r29);
    //// lw          $s1, 0x14($sp)
    //ctx->r17 = MEM_W(0X14, ctx->r29);
    //// lw          $s0, 0x10($sp)
    //ctx->r16 = MEM_W(0X10, ctx->r29);
    //// addiu       $sp, $sp, 0x20
    //ctx->r29 = ADD32(ctx->r29, 0X20);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
