#include "recomp.h"
#include "disable_warnings.h"

void FAsyncLoadSomething_0005(uint8_t* rdram, recomp_context* ctx) 
{
    //uint8_t* stream = (uint8_t*)GET_PTR(ctx->r4);
    //printf("[FAsync] state=%d\n", stream[0]);

    //int iterations = 0;
    //while (stream[0] != 0 && iterations < 50000) {
    //    iterations++;

    //    if (stream[0] == 48) {
    //        // Симулируем завершение SPU DMA:
    //        // stream+28 = указатель на канал, пишем 1 туда
    //        uint32_t channel_ptr = *(uint32_t*)(stream + 28);
    //        if (channel_ptr) {
    //            uint8_t* channel = (uint8_t*)GET_PTR(channel_ptr);
    //            if (channel) {
    //                channel[0] = 1;  // **(v0+28) = 1
    //                printf("[FAsync] SPU DMA complete simulated\n");
    //            }
    //        }
    //        // И вызываем NextCdTask вручную
    //        stream[0] = 0;
    //        break;
    //    }

    //    AsyncDataLoad(rdram, ctx);
    //}

    //printf("[FAsync] done, iterations=%d final_state=%d\n", iterations, stream[0]);
    //ctx->r2 = 0;
   
    printf("FAsyncLoadSomething_0005\n");
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
L_80018254:
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80018284
    if (ctx->r2 == 0) {
        // nop
        goto L_80018284;
    }
    // nop

    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_80018254
    // nop

    goto L_80018254;
    // nop

L_80018284:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_3;
    // nop

    after_3:
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
