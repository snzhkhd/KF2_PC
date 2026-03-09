#include "recomp.h"
#include "disable_warnings.h"

void MOLoadedCallback(uint8_t* rdram, recomp_context* ctx) 
{
    //uint32_t data_addr = ctx->r4; // или откуда берётся указатель
    //printf("[MO loaded] addr=%08X\n", data_addr);
    //uint8_t* p = (uint8_t*)GET_PTR(data_addr);
    //printf("[MO hex] %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",
    //    p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11]);
    //printf("[MO TMD] id=%08X flags=%08X nobj=%d\n",
    //    *(uint32_t*)p, *(uint32_t*)(p + 4), *(uint32_t*)(p + 8));

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // jal         0x80030130
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    KF_TMDIndicesToOffsets(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80017B9C
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    MO_Something01Set(rdram, ctx);
    goto after_1;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    after_1:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop
    return;
    // nop

;}
