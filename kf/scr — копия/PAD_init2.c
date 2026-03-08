#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libetc.h"
#include "psx/libpad.h"

void PAD_init2(uint8_t* rdram, recomp_context* ctx) 
{
    int mode = (int)ctx->r4;
    PadInit(mode);
    extern u_char g_pad1_buf[34];
    extern u_char g_pad2_buf[34];
    PadInitDirect(g_pad1_buf, g_pad2_buf);
    PadStartCom();

    //8019B606 g_PadKey
    //8019B608 g_PadKey_Alt 
    //uint16_t initial = *(uint16_t*)GET_PTR(0x8019B606);
    //*(uint16_t*)GET_PTR(0x8019B608) = initial;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $t2, $zero, 0xB0
    //ctx->r10 = ADD32(0, 0XB0);
    //// jr          $t2
    //// addiu       $t1, $zero, 0x15
    //ctx->r9 = ADD32(0, 0X15);
    //LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    //return;
    //// addiu       $t1, $zero, 0x15
    //ctx->r9 = ADD32(0, 0X15);
;}
