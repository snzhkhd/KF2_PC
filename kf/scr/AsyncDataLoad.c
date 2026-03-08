#include "..//kf_cd.h"
#include "recomp.h"
#include "disable_warnings.h"

void KFCD_IntToCdPos(int lba, CdlLOC* loc) {
    lba += 150;
    loc->minute = itob(lba / (60 * 75));
    loc->second = itob((lba / 75) % 60);
    loc->sector = itob(lba % 75);
    loc->track = 0;
}

void AsyncDataLoad(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[DEBUG] AsyncDataLoad.\n");

     // Симулируем CD IRQ для стримов которые ждут callback
    uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    uint32_t saved_r4 = ctx->r4;
    uint32_t saved_ra = ctx->r31;
    //
    if (p_active && *p_active) 
    {
        uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
        if (stream && stream[36] == 1) 
        {
            uint8_t type = stream[0];

            recomp_func_t handler = nullptr;
            if (type == 0x10)
            {
                handler = lookup_recomp_func(0x80017DB4);
                if (handler) {
                    stream[36] = 0;

                    uint16_t chunks_now = *(uint16_t*)(stream + 16);
                    uint16_t chunks_rest = *(uint16_t*)(stream + 34);
                    uint16_t total = chunks_now + chunks_rest;

                    CdlLOC* base_loc = (CdlLOC*)(stream + 6);
                    int base_lba = KFCD_CdPosToInt(base_loc);
                    uint32_t dst = *(uint32_t*)(stream + 12);

                    // Читаем ВСЁ за один раз
                    uint8_t* dst_ptr = (uint8_t*)GET_PTR(dst);
                    for (int i = 0; i < total; i++) {
                        fseek(g_cdImage, (uint32_t)(base_lba + i) * 2352 + 24, SEEK_SET);
                        fread(dst_ptr + i * 2048, 1, 2048, g_cdImage);
                    }

                    //printf("[RTMD] BEFORE handler 1:\n");
                    //uint8_t* chk = (uint8_t*)GET_PTR(0x80130A90);
                    //printf("  bytes 12-15: %02X %02X %02X %02X  (VertexTop obj0)\n",
                    //    chk[12], chk[13], chk[14], chk[15]);
                    //printf("  bytes 16-19: %02X %02X %02X %02X  (VertexNum obj0 = %d)\n",
                    //    chk[16], chk[17], chk[18], chk[19], *(uint32_t*)(chk + 16));


                    *(uint16_t*)(stream + 16) = 0;
                    *(uint16_t*)(stream + 34) = 0;
                    stream[36] = 1;

                    // КЛЮЧЕВОЙ ФИКС: сброс CD state чтобы повторное чтение
                    // из handler шло с правильного LBA
                    g_cdCurrentSector = base_lba;
                    KFCD_ResetReadState();

                    ctx->r4 = *p_active;
                    handler(rdram, ctx);

                    //printf("[RTMD] AFTER handler 1:\n");
                    //printf("  bytes 12-15: %02X %02X %02X %02X\n", chk[12], chk[13], chk[14], chk[15]);
                    //printf("  bytes 16-19: %02X %02X %02X %02X  (VertexNum = %d)\n",
                    //    chk[16], chk[17], chk[18], chk[19], *(uint32_t*)(chk + 16));


                    // Снова сброс — handler мог сдвинуть pass_count
                    g_cdCurrentSector = base_lba;
                    KFCD_ResetReadState();

                    stream[36] = 1;
                    ctx->r4 = *p_active;
                    handler(rdram, ctx);

                    //printf("[RTMD] AFTER handler 2:\n");
                    //printf("  bytes 12-15: %02X %02X %02X %02X\n", chk[12], chk[13], chk[14], chk[15]);
                    //printf("  bytes 16-19: %02X %02X %02X %02X  (VertexNum = %d)\n",
                    //    chk[16], chk[17], chk[18], chk[19], *(uint32_t*)(chk + 16));

                    ctx->r4 = saved_r4;
                    ctx->r31 = saved_ra;
                    handler = nullptr;
                    
                }
            }
            else if (type == 0x30) 
            {
                uint32_t cb = *(uint32_t*)(stream + 20);
                if (cb) handler = lookup_recomp_func(cb);
            }

            if (handler) 
            {
                stream[36] = 0;
                //printf("[AsyncDataLoad] IRQ sim type=0x%02X\n", type);
                
                uint32_t saved_r4 = ctx->r4;
                uint32_t saved_ra = ctx->r31;
                ctx->r4 = *p_active;
                handler(rdram, ctx);
                ctx->r4 = saved_r4;
                ctx->r31 = saved_ra;
            }
            /*printf("[IRQ sim 0x10] stream[16]=%d stream[34]=%d\n",
                *(uint16_t*)(stream + 16),
                *(uint16_t*)(stream + 34));*/
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
