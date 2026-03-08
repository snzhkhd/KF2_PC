#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "gpu/PsyX_GPU.h"
#include "psx/libetc.h"
#include <string>
#include <unordered_set>

static int SaveCount = 0;
static int SaveTimer = 0;

void TriggerGpuDma(uint8_t* rdram, recomp_context* ctx) 
{
    //PsyX_BeginScene(); <- вызывается в BeginDraw2D и RenderScene
    uint32_t madr = ctx->r4;
    calls_per_frame++;
    if (madr < 0x80000000 || madr >= 0x80200000) return;
    uint32_t cur_addr = madr;

    // Считаем непустые записи OTag
    int non_empty = 0;
    
    //for (int i = 0; i < 0x2000; i++) 
    //{
    //    uint32_t* cur = (uint32_t*)GET_PTR(cur_addr);
    //    uint32_t tag = cur[0];
    //    uint8_t len = (tag >> 24) & 0xFF;
    //    uint32_t next = tag & 0x00FFFFFF;
    //    if (len > 0)
    //    {
    //        non_empty++;

    //        uint8_t code = (cur[1] >> 24) & 0xFF;
    //        // Для GT3 (0x34) и GT4 (0x3E) — вершины начинаются с cur[2]
    //        if ((code == 0x34 || code == 0x3E) && non_empty < 3) {
    //            int16_t x0 = (int16_t)(cur[2] & 0xFFFF);
    //            int16_t y0 = (int16_t)(cur[2] >> 16);
    //            int16_t x1 = (int16_t)(cur[4] & 0xFFFF);
    //            int16_t y1 = (int16_t)(cur[4] >> 16);
    //            int16_t x2 = (int16_t)(cur[6] & 0xFFFF);
    //            int16_t y2 = (int16_t)(cur[6] >> 16);
    //            printf("[Vert] code=%02X (%d,%d) (%d,%d) (%d,%d)\n",
    //                code, x0, y0, x1, y1, x2, y2);
    //        }
    //    }
    //    if (next == 0x00FFFFFF || next < 0x00010000) break;
    //    cur_addr = next | 0x80000000;
    //}
  //  printf("[TriggerGpuDma] madr=%08X non_empty=%d\n", madr, non_empty);


    uint32_t* p_data = (uint32_t*)GET_PTR(madr);
    

    uint32_t first_word = p_data[0];
    uint32_t next_ptr = first_word & 0x00FFFFFF;
    uint8_t  top_byte = (first_word >> 24) & 0xFF;

    if (next_ptr >= 0x00010000 && next_ptr < 0x00200000 && top_byte < 0x20)
    {
       
        int max_iter = 1024;

        while (true)
        {
            uint32_t* cur = (uint32_t*)GET_PTR(cur_addr);
            uint32_t tag = cur[0];
            uint8_t  len = (tag >> 24) & 0xFF;
            uint32_t next = tag & 0x00FFFFFF;

            if (len > 0) 
            {
                uint8_t code = (cur[1] >> 24) & 0xFF;

                ////non_empty++;
                //if (code == 0x3E) 
                //{
                //    bool semiTrans = (code & 0x02) != 0;
                //    if (semiTrans)
                //        break;
                //}

                
                if (code == 0x2E) 
                {

                    uint16_t clut = (cur[3] >> 16) & 0xFFFF;
                    uint16_t tpage = (cur[5] >> 16) & 0xFFFF;
                    uint8_t u0 = cur[3] & 0xFF;
                    uint8_t v0 = (cur[3] >> 8) & 0xFF;
                    uint8_t u1 = cur[5] & 0xFF;
                    uint8_t v1 = (cur[5] >> 8) & 0xFF;
                    int16_t x0 = cur[2] & 0xFFFF;
                    int16_t y0 = cur[2] >> 16;
                }


                static uint8_t psyx_prim[256];
                memset(psyx_prim, 0, 256);

                // P_TAG (USE_EXTENDED_PRIM_POINTERS=0):
                *(uint32_t*)psyx_prim = ((uint32_t)len << 24) | 0x00FFFFFF;
                psyx_prim[4] = (cur[1] >> 0) & 0xFF; // r0
                psyx_prim[5] = (cur[1] >> 8) & 0xFF; // g0
                psyx_prim[6] = (cur[1] >> 16) & 0xFF; // b0
                psyx_prim[7] = (cur[1] >> 24) & 0xFF; // code 
                memcpy(psyx_prim + 8, &cur[2], (len - 1) * 4);

                //работает и без фикса
                //if (psyx_prim[15] == 0x2E || psyx_prim[15] == 0x3E ||   
                //    psyx_prim[15] == 0x26 || psyx_prim[15] == 0x36) {
                //    // Semi-transparent textured poly — убираем semi-transparency флаг
                //    // Правильное решение: настроить GR_SetBlendMode перед рендером
                //    // Временный фикс:
                //    psyx_prim[15] &= ~0x02; // убираем бит semi-transparency
                //}

                ParsePrimitivesLinkedList((u_long*)psyx_prim, 0);

            }
            if (next == 0x00FFFFFF || next < 0x00010000) break;
            cur_addr = next | 0x80000000;
        }

        GR_UpdateVRAM();

        DrawAllSplits();

        //PsyX_EndScene(); <- вызывается в RenderEnd и EndDraw2D
        if (g_vsync_pending) 
        {
            VSync(0);
            g_vsync_pending = false;

            SaveTimer++;
            if (SaveTimer > 20 && SaveCount < 5)
            {
                SaveTimer = 0;
                std::string str = "vram_debug_" + std::to_string(SaveCount) + ".tga";
                GR_SaveVRAM(str.c_str(), 0, 0, 1024, 512, 0);
                SaveCount++;
                printf("[DEBUG] VRAM saved to %s\n", str.c_str());
            }
        }
        
    }
    else if (top_byte == 0x00 && (first_word & 0xFF) <= 0x20)
    {
        uint32_t* packet_start = p_data + 1;
        
        ParsePrimitivesLinkedList((unsigned long*)packet_start, 1);
    }
    else
    {
       
        ParsePrimitivesLinkedList((unsigned long*)p_data, 1);
    }

    WRITE_W(0x1F8010A8, MEM_W(0, 0x1F8010A8) & ~0x01000000);
    WRITE_W(0x1F801814, 0x1C000000);
    ctx->r2 = 0;
}
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v1, 0x400
    //ctx->r3 = S32(0X400 << 16);
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x6274($v0)
    //ctx->r2 = MEM_W(0X6274, ctx->r2);
    //// ori         $v1, $v1, 0x2
    //ctx->r3 = ctx->r3 | 0X2;
    //// sw          $v1, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r3;
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x6278($v0)
    //ctx->r2 = MEM_W(0X6278, ctx->r2);
    //// nop

    //// sw          $a0, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r4;
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x627C($v0)
    //ctx->r2 = MEM_W(0X627C, ctx->r2);
    //// lui         $v1, 0x100
    //ctx->r3 = S32(0X100 << 16);
    //// sw          $zero, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = 0;
    //// lui         $v0, 0x8007
    //ctx->r2 = S32(0X8007 << 16);
    //// lw          $v0, 0x6280($v0)
    //ctx->r2 = MEM_W(0X6280, ctx->r2);
    //// ori         $v1, $v1, 0x401
    //ctx->r3 = ctx->r3 | 0X401;
    //// sw          $v1, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r3;
    //// jr          $ra
    //// nop

    //return;
    //// nop

