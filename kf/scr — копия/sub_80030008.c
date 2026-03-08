#include "recomp.h"
#include "disable_warnings.h"

void sub_80030008(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8002FFD4
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sub_8002FFD4(rdram, ctx);
    goto after_0;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x250($v1)
    ctx->r3 = MEM_W(0X250, ctx->r3);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v0, 0xB54($at)
    MEM_W(0XB54, ctx->r1) = ctx->r2;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop
   /* printf("[sub_80030008] a1=%d g_CurrentPrimitiveBuffer=%08X dword_80190B54=%08X\n",
        (int)(ctx->r4 & 0xFFFF),
        MEM_W(0x250, S32(0x8019 << 16)),
        ctx->r2);*/
    return;
    return;
    // nop

;}
