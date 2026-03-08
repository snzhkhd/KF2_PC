#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_render.h"
#include "psx/libetc.h"
#include "pad/PsyX_pad.h"
#include "SDL2/SDL_keyboard.h"



void KF_PadRead(uint8_t* rdram, recomp_context* ctx) 
{
    u_short raw = *(u_short*)&g_pad1_buf[2];

    // Меняем байты местами
    raw = ((raw >> 8) & 0xFF) | ((raw << 8) & 0xFF00);

    u_short buttons = ~raw;

    //if (buttons != 0)
    //    printf("[PAD] buttons=0x%04X\n", buttons);


    //printf("[PAD] before swap: 0x%04X\n", raw);
    //raw = ((raw >> 8) & 0xFF) | ((raw << 8) & 0xFF00);
    //printf("[PAD] after swap: 0x%04X\n", raw);

    //printf("[PAD] buttons: 0x%04X\n", buttons);

    //8019B606 g_PadKey
    uint16_t btn = *(uint16_t*)GET_PTR(0x8019B606);
    //printf("btn <%d>\n",btn);
    static bool save = false;
    if (!save && btn == 256)
    {
        save = true;
        GR_SaveVRAM("vram_debug_game.gta", 0, 0, 1024, 512, 0);
        save = false;
        ctx->r2 = (uint32_t)buttons;
        btn = 0;
        return;
    }

    ctx->r2 = (uint32_t)buttons;
}

//void KF_PadRead(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // jal         0x80062830
//    // nop
//
//    PAD_dr(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, -0x6FF8($v0)
//    ctx->r2 = MEM_W(-0X6FF8, ctx->r2);
//    // nop
//
//    // nor         $v0, $zero, $v0
//    ctx->r2 = ~(0 | ctx->r2);
//    // lw          $ra, 0x10($sp)
//    ctx->r31 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
