#include "recomp.h"
#include "disable_warnings.h"

void GPU_Cmd_FinalizeAndAdvance(uint8_t* rdram, recomp_context* ctx) 
{
    //uint32_t size_words = ctx->r4;  // 20 для квада
    //uint32_t gp = 0x800762C0;
    //uint32_t prim_ptr = MEM_W(0xF0, gp);  // текущий примитив

    //// Дамп примитива
    //uint32_t* prim = (uint32_t*)GET_PTR(prim_ptr);
    //printf("[FinalizeAndAdvance] size=%d prim=0x%08X type=%02X\n",
    //    size_words, prim_ptr, prim ? (prim[0] >> 24) & 0xFF : 0xFF);
    //if (prim) {
    //    for (int i = 0; i < (int)size_words && i < 12; i++)
    //        printf("  [%d] = 0x%08X\n", i, prim[i]);
    //}

    printf("[GPU_Cmd] FinalizeAndAdvance called, writing to gp+240=0x%08X\n",
        MEM_W(0xF0, ctx->r28));
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x15C($a0)
    ctx->r4 = MEM_W(0X15C, ctx->r4);
    // lw          $a1, 0xF0($gp)
    ctx->r5 = MEM_W(0XF0, ctx->r28);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80067238
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // sw          $v0, 0xF0($gp)
    MEM_W(0XF0, ctx->r28) = ctx->r2;
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
