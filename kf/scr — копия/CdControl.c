#include "..//kf_cd.h"
#include "recomp.h"
#include "disable_warnings.h"
//#include "psx/libcd.h"
#include <string>
#include <unordered_set>

static std::unordered_set<uint32_t> g_cd_done_streams;


//void KF_CdControl(uint8_t* rdram, recomp_context* ctx)
//{
//    //g_Option_Music    8019B58C off music
//    WRITE_W(0x8019B58C, 0);
//
//
//    uint8_t cmd = (uint8_t)ctx->r4;
//    uint32_t param_addr = ctx->r5;
//
//    printf("[KF_CdControl] cmd=0x%02X\n", cmd);
//
//    if (cmd == 0x16) // CdlReadN — запуск стримингового чтения
//    {
//        uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
//        if (p_active && *p_active) {
//            uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
//            if (stream)
//            {
//                CdlLOC* base_loc = (CdlLOC*)(stream + 6);
//                CdlLOC* cur_loc = (CdlLOC*)(stream + 2);
//                int base_lba = KFCD_CdPosToInt(base_loc);
//                int cur_lba = KFCD_CdPosToInt(cur_loc);
//                uint16_t chunks_rem = *(uint16_t*)(stream + 16);
//
//                // Новый стрим или новый файл — сброс счётчика
//                if (*p_active != g_cd_last_stream || base_lba != g_cd_base_lba) {
//                    //    printf("[CdlReadN] NEW STREAM: old_base=%d new_base=%d\n", g_cd_base_lba, base_lba);
//                    g_cd_last_stream = *p_active;
//                    g_cd_base_lba = base_lba;
//                    g_cd_pass_count = 0;
//                }
//
//                // Файл полностью прочитан
//                if (chunks_rem == 0)
//                {
//                    //    printf("[CdlReadN] chunks=0, file done, calling NextCdTask\n");
//                    recomp_func_t next_task = lookup_recomp_func(0x80017D2C);
//                    if (next_task) {
//                        uint32_t saved_r4 = ctx->r4;
//                        uint32_t saved_ra = ctx->r31;
//                        ctx->r4 = *p_active;
//                        next_task(rdram, ctx);
//                        ctx->r4 = saved_r4;
//                        ctx->r31 = saved_ra;
//                    }
//                    ctx->r2 = 1;
//                    return;
//                }
//
//                int real_lba;
//                if (cur_lba == base_lba) {
//                    real_lba = base_lba + g_cd_pass_count * 16;
//                    //    printf("[CdlReadN] path=2 base=%d pass=%d real=%d chunks=%d\n",
//                     //       base_lba, g_cd_pass_count, real_lba, chunks_rem);
//                    g_cd_pass_count++;
//                }
//                else {
//                    real_lba = cur_lba;
//                    //    printf("[CdlReadN] path=1 base=%d cur=%d real=%d chunks=%d\n",
//                     //       base_lba, cur_lba, real_lba, chunks_rem);
//                }
//
//                uint32_t dst = *(uint32_t*)(stream + 12);
//                uint8_t* dst_ptr = (uint8_t*)GET_PTR(dst);
//
//                // Читаем ТОЛЬКО 16 секторов за раз (одна порция = 0x8000 байт)
//                uint16_t sectors_to_read = (chunks_rem > 16) ? 16 : chunks_rem;
//                uint32_t bytes_to_read = sectors_to_read * 2048;
//
//                uint32_t fileOffset = (uint32_t)real_lba * 2352 + 24;
//                fseek(g_cdImage, fileOffset, SEEK_SET);
//
//                // Читаем секторами по 2048 байт, пропуская 304 байта заголовка каждого сектора
//                uint8_t* write_ptr = dst_ptr;
//                for (int i = 0; i < sectors_to_read; i++) {
//                    fseek(g_cdImage, (uint32_t)(real_lba + i) * 2352 + 24, SEEK_SET);
//                    fread(write_ptr, 1, 2048, g_cdImage);
//                    write_ptr += 2048;
//                }
//                stream[36] = 1; // сигналим что порция готова
//            }
//        }
//        ctx->r2 = 1;
//        return;
//    }
//    //dword_8006F478 = 0;
//    uint32_t dword_8006F478 = MEM_W(0, 0x8006F478);
//    WRITE_W(dword_8006F478, 0);
//    KFCD_CdControl(rdram, ctx);
//    ctx->r2 = 1;
//    return;
//}

void KF_CdControl(uint8_t* rdram, recomp_context* ctx) 
{
    uint8_t cmd = (uint8_t)ctx->r4;

    uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    printf("[KF_CdControl] cmd=0x%02X active_stream=%08X stream[0]=%02X\n",
        cmd,
        *p_active,
        ((uint8_t*)GET_PTR(*(uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM)))[0]);

    if (cmd == 0x16) 
    {
        
        if (p_active)
        {
            
            if (stream)
            {
                printf("[KF_CdControl] cmd=0x16 p_active=%08X stream[0]=%02X stream[36]=%d\n",
                    *p_active, stream[0], stream[36]);
            }
        }
        
    }

    //CD_cw_8004DBE0 (rdram, ctx)   <- можно вызвать напрямую!
   KFCD_CdControl(rdram, ctx);
    return;
    ////не выполняем оригинальный код!
    //printf("\n[KF_CdControl]  wtf??\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // andi        $s2, $s4, 0xFF
    ctx->r18 = ctx->r20 & 0XFF;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0xC08
    ctx->r3 = ADD32(ctx->r3, -0XC08);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // lw          $s5, -0xB88($s5)
    ctx->r21 = MEM_W(-0XB88, ctx->r21);
    // sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18) << 2;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
L_8004CB1C:
    // bne         $s2, $v0, L_8004CB4C
    if (ctx->r18 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004CB4C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB78($v0)
    ctx->r2 = MEM_BU(-0XB78, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // bne         $v0, $zero, L_8004CB4C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004CB4C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x8004E0D0
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    sub_8004E0D0(rdram, ctx);
    goto after_0;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // j           L_8004CBC0
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004CBC0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004CB4C:
    // beq         $s2, $v0, L_8004CBA0
    if (ctx->r18 == ctx->r2) {
        // andi        $a0, $s4, 0xFF
        ctx->r4 = ctx->r20 & 0XFF;
        goto L_8004CBA0;
    }
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // jal         0x8004E0D0
    // nop

    sub_8004E0D0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // beq         $s1, $zero, L_8004CB94
    if (ctx->r17 == 0) {
        // nop
    
        goto L_8004CB94;
    }
    // nop

    // lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(0X0, ctx->r22);
    // nop

    // beq         $v0, $zero, L_8004CB94
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_8004CB94;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // bne         $v0, $zero, L_8004CBB8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004CBB8;
    }
    // nop

L_8004CB94:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s5, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r21;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
L_8004CBA0:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_8004CBD8
    if (ctx->r2 == 0) {
        // addiu       $v0, $s7, 0x1
        ctx->r2 = ADD32(ctx->r23, 0X1);
        goto L_8004CBD8;
    }
    // addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
L_8004CBB8:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004CBC0:
    // bne         $s0, $v0, L_8004CB1C
    if (ctx->r16 != ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8004CB1C;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s5, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r21;
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
L_8004CBD8:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
