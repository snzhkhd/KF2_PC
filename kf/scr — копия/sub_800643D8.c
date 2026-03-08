#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "psx/libetc.h"

void sub_800643D8(uint8_t* rdram, recomp_context* ctx)
{
    printf("sub_800643D8\n");
    PsyX_UpdateInput();

    // 2. Формируем статус: Ready (0x1C) + мигающий бит 31 (Field)
    uint32_t field_bit = (VSync(-1) & 1) ? 0x80000000 : 0;
    ctx->r2 = 0x1C000000 | field_bit;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x6274($v0)
    //ctx->r2 = MEM_W(0X6274, ctx->r2);
    //// nop

    //// lw          $v0, 0x0($v0)
    //ctx->r2 = MEM_W(0X0, ctx->r2);
    //// jr          $ra
    //// nop

    //return;
    //// nop

    ;
}
