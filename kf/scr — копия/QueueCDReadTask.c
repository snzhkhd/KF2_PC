#include "recomp.h"
#include "disable_warnings.h"

void QueueCDReadTask(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[LOG] QueueCDReadTask called.\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // addiu       $a2, $a2, -0x5754
    ctx->r6 = ADD32(ctx->r6, -0X5754);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x7370
    ctx->r7 = ADD32(ctx->r7, 0X7370);
    // jal         0x800185AC
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    PrepareReadTask(rdram, ctx);
    goto after_0;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
