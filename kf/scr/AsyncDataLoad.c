#include "recomp.h"
#include "disable_warnings.h"

void AsyncDataLoad(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[DEBUG] AsyncDataLoad.\n");
    uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    if (p_active && *p_active) {
        uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
        if (stream) {
            uint16_t chunks = *(uint16_t*)(stream + 16);
            // Если есть данные для чтения но никто не запустил CdlReadN
            if (chunks > 0 && stream[36] == 0 && stream[1] == 0) {
                printf("[Async] forcing CdlReadN for stream[0]=%d chunks=%d\n",
                    stream[0], chunks);
                uint32_t saved_r4 = ctx->r4;
                uint32_t saved_r5 = ctx->r5;
                ctx->r4 = 0x16;
                ctx->r5 = (uint32_t)((*p_active + 2) | 0x80000000);
                KF_CdControl(rdram, ctx);
                ctx->r4 = saved_r4;
                ctx->r5 = saved_r5;
            }

            // Обработчик если данные готовы
            if (stream[36]) 
            {
                //stream[36] = 0;
                recomp_func_t handler = nullptr;
                switch (stream[0]) {
                case 0x10: handler = lookup_recomp_func(0x80017DB4); break;
                case 0x20:
                case 0x40: handler = lookup_recomp_func(0x80017F2C); break;
                }
                if (handler) {
                    uint32_t saved_ra = ctx->r31;
                    uint32_t saved_r4 = ctx->r4;
                    ctx->r4 = *p_active;
                    handler(rdram, ctx);
                    ctx->r4 = saved_r4;
                    ctx->r31 = saved_ra;
                }
            }
        }
    }


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80014988
    // nop

    ProcessCDAudioLoad(rdram, ctx);

    goto after_0;
    // nop

    after_0:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
