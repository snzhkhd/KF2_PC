#include "recomp.h"
#include "disable_warnings.h"

void GPU_Cmd_SetupFlatGrayQuad(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("[GPU_Cmd] GPU_Cmd_SetupFlatGrayQuad called, writing to gp+240=0x%08X\n",
        // MEM_W(0xF0, ctx->r28));
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x800673A0
    // nop

    GPU_Cmd_SetBaseParams(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $v1, $zero, 0x68
    ctx->r3 = 0 | 0X68;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
