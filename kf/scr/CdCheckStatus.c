#include "recomp.h"
#include "disable_warnings.h"

void CdCheckStatus(uint8_t* rdram, recomp_context* ctx) 
{

    int a1 = ctx->r4;
    uint8_t* a2 = (uint8_t*)ctx->r5;
    // 1. Имитируем, что диск готов
     // По смещению 0 в статусе обычно лежит "Ready" (например 0x01 или 0x02)
    uint32_t* regs = (uint32_t*)GET_PTR(0x80076498);    //g_CdStatusRegisters
    regs[0] = 0x01; // Успех / Ready

    // 2. Если игра просит скопировать статус в массив a2
    if (a2) {
        // Копируем наш "фейковый" статус в память игры
        for (int i = 0; i < 8; i++) a2[i] = ((uint8_t*)regs)[i];
    }
    ctx->r2 = 0;
    return; // Возвращаем 0 (статус ОК)
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8004EBB0
    // nop

    CdWaitForCompletion(rdram, ctx);
    goto after_0;
    // nop

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
