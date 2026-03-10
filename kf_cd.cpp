#include "kf/recomp.h"
#include "kf_cd.h"
#include <string.h>
#include <unordered_map>
static uint32_t g_cdReadyCb = 0;
static uint32_t g_cdSyncCb = 0;

extern bool g_pendingType10;
extern std::unordered_map<uint32_t, uint32_t> g_stream_file_sizes;

FILE* g_cdImage = NULL;
uint32_t g_cdCurrentSector = 0;
KF_CD_Request g_cdReq = { 0 };
int g_cdReading = 0;


int KFCD_Init(const char* path)
{
    g_cdImage = fopen(path, "rb");
    return g_cdImage != NULL;
}

int KFCD_CdPosToInt(CdlLOC* p)
{
    // PS1: LBA = (M * 60 + S) * 75 + F - 150
    return (75 * (60 * btoi(p->minute) + btoi(p->second))) + btoi(p->sector) - 150;
}

void KFCD_CdControl(uint8_t* rdram, recomp_context* ctx)
{
    uint8_t com = (uint8_t)ctx->r4;
    CdlLOC* loc = (CdlLOC*)GET_PTR(ctx->r5);

    if (com == 0xA0)
    {
        printf("0xA0 from <0x % 02X>\n", ctx->r31);//
    }

    switch (com)
    {
    case 0x02: // CdlSetloc
    {
        g_cdCurrentSector = KFCD_CdPosToInt(loc);
        ctx->r2 = 1;
   //     printf("CdlSetloc\n");
        return;
    }

    case 0x1B: // CdlReadS
    {
        g_cdReq.active = 1;
        g_cdReq.sector = g_cdCurrentSector;
        g_cdReq.count = 1;
        g_cdReading = 1;
        ctx->r2 = 1;
     //   printf("CdlReadS    ctx->r2 = 1;\n");
        return;
    }

    case 0x09: // CdlPause
    {
        g_cdReading = 0;
        ctx->r2 = 1;
    //    printf("CdlPause ctx->r2 = 1;\n");
        return;
    }

    case 0x0E: // CdlSetmode
    {
        ctx->r2 = 1;
    //    printf("CdlSetmode ctx->r2 = 1;\n");
        return;
    }
    case 0x11: // CdlGetlocP (получить позицию головы)
    {
        uint8_t* res = (uint8_t*)GET_PTR(ctx->r5);
        if (res) {
            // Превращаем текущий сектор обратно в минуты:секунды:фреймы
            int s = g_cdCurrentSector + 150;
            int m = s / (75 * 60);
            s %= (75 * 60);
            int sec = s / 75;
            int f = s % 75;

            res[0] = itob(m);   // minutes
            res[1] = itob(sec); // seconds
            res[2] = itob(f);   // frames/sector
            res[3] = 1;         // track
        }
        ctx->r2 = 1; // Успех
    //    printf("CdlGetlocP\n");
        return;
    }
    case 0x15: // SeekL
    case 0x16: // SeekP
    {
        KFCD_CdlReadN(rdram,ctx);
        uint32_t* p = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
        if (p && *p) {
            uint8_t* s = (uint8_t*)GET_PTR(*p);
            if (s && s[0] == 0x10 && s[36] == 1)
                g_pendingType10 = true;
        }

        return;
    }

    default:
    {
        printf("[KF_CD] Unhandled command 0x%02X\n", com);
        ctx->r2 = 1;
        return;
    }
    }
}


void KFCD_CdlReadN(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    if (!p_active || !*p_active) {
        g_cdReading = 0;
        ctx->r2 = 1;
        return;
    }
    uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    if (!stream || stream[0] == 0) {
        ctx->r2 = 1;
        return;
    }

    uint16_t sectors = *(uint16_t*)(stream + 16);
    if (sectors == 0) { ctx->r2 = 1; return; }

    uint32_t dst = *(uint32_t*)(stream + 12);
    uint8_t* dst_ptr = (uint8_t*)GET_PTR(dst);
    CdlLOC* base_loc = (CdlLOC*)(stream + 6);
    int base_lba = KFCD_CdPosToInt(base_loc);
    uint8_t type = stream[0];

    if (type == 0x10) {
        uint16_t remain = *(uint16_t*)(stream + 34);
        uint16_t total = sectors + remain;

        // Проверяем реальный размер по LBA
        auto it = g_stream_file_sizes.find(base_lba);
        if (it != g_stream_file_sizes.end()) {
            uint16_t expected = (it->second + 2047) / 2048;
            if (expected > total) {
                printf("[CdlReadN fix] lba=%d total %d -> %d\n", base_lba, total, expected);
                total = expected;
            }
            g_stream_file_sizes.erase(it);
        }

        /*printf("[CdlReadN 0x10] sectors=%d remain=%d total=%d base_lba=%d dst=%08X\n",
            sectors, remain, total, base_lba, dst);*/

        for (int i = 0; i < total; i++) {
            fseek(g_cdImage, (uint32_t)(base_lba + i) * 2352 + 24, SEEK_SET);
            fread(dst_ptr + i * 2048, 1, 2048, g_cdImage);
        }

        uint16_t last_batch = (total > 16) ? (total % 16 ? total % 16 : 16) : total;
        *(uint16_t*)(stream + 16) = last_batch;
        *(uint16_t*)(stream + 34) = 0;

        g_cdCurrentSector = base_lba;
        g_cd_last_stream = *p_active;
        g_cd_base_lba = base_lba;
        g_cd_pass_count = total;

    }
    else {
        uint16_t to_read = (sectors > 16) ? 16 : sectors;

        if (*p_active != g_cd_last_stream || base_lba != g_cd_base_lba) {
            g_cd_last_stream = *p_active;
            g_cd_base_lba = base_lba;
            g_cd_pass_count = 0;
            if (sectors > 16 && *(uint16_t*)(stream + 34) == 0) {
                *(uint16_t*)(stream + 16) = 16;
                *(uint16_t*)(stream + 34) = sectors - 16;
                to_read = 16;
            }
        }

        int real_lba = base_lba + g_cd_pass_count;
        for (int i = 0; i < to_read; i++) {
            fseek(g_cdImage, (uint32_t)(real_lba + i) * 2352 + 24, SEEK_SET);
            fread(dst_ptr + i * 2048, 1, 2048, g_cdImage);
        }
        g_cd_pass_count += to_read;
    }

    stream[36] = 1;
    ctx->r2 = 1;
}

int KFCD_CdRead(int sectors, uint32_t* buf)
{
    if (!g_cdImage) return 0;

    g_cdReq.active = 1;
    g_cdReq.sector = g_cdCurrentSector;
    g_cdReq.count = sectors;
    g_cdReq.dst = (uint8_t*)buf;

    g_cdReading = 1;
    return 1;
}

int KFCD_CdReadSync(int mode)
{
    if (!g_cdReq.active)
        return -1;

    while (g_cdReq.count > 0)
    {
        uint32_t fileOffset = g_cdReq.sector * RAW_SECTOR_SIZE;

        fseek(g_cdImage, fileOffset + 24, SEEK_SET);
        // +24 пропускаем sync/header чтобы получить 2048 data

        fread(g_cdReq.dst, 1, SECTOR_SIZE, g_cdImage);

        g_cdReq.dst += SECTOR_SIZE;
        g_cdReq.sector++;
        g_cdReq.count--;
    }

    g_cdReq.active = 0;
    g_cdReading = 0;

    if (g_cdSyncCb) {
        KFCD_InvokeCallback(rdram, g_ctx, g_cdSyncCb, 2);
    }
    return 0;
}

int KFCD_CdSync(int mode)
{
    if (g_cdReading)
        return 0;   // busy

    return 2;       // CdlComplete
}

void KFCD_CdReadyCallback(uint8_t* rdram, recomp_context* ctx)
{
    g_cdReadyCb = ctx->r4;
    printf("KFCD_CdReadyCallback r4 : <0x%08X>\n", g_cdReadyCb);
    ctx->r2 = 0;
}

void KFCD_CdSyncCallback(uint8_t* rdram, recomp_context* ctx)
{
    g_cdSyncCb = ctx->r4;
    printf("KFCD_CdSyncCallback r4 : <0x%08X>\n", g_cdSyncCb);
    ctx->r2 = 0;
}

void KFCD_InvokeCallback(uint8_t* rdram, recomp_context* ctx, uint32_t cbAddr, uint8_t status)
{
    if (cbAddr == 0)
        return;

    recomp_func_t func = lookup_recomp_func(cbAddr);
    if (!func)
        return;

    // Сохраняем volatile регистры
    uint32_t saved_r4 = ctx->r4;
    uint32_t saved_r5 = ctx->r5;
    uint32_t saved_r2 = ctx->r2;
    uint32_t saved_ra = ctx->r31;

    uint8_t result[8] = { 0 };
    result[0] = status;

    // Копируем result в rdram (любая свободная область)
    uint32_t result_addr = 0x80010000; 
    memcpy(rdram + result_addr, result, sizeof(result));

    ctx->r4 = status;
    ctx->r5 = result_addr;

    func(rdram, ctx);

    // Восстановление
    ctx->r4 = saved_r4;
    ctx->r5 = saved_r5;
    ctx->r2 = saved_r2;
    ctx->r31 = saved_ra;
}

void KDCD_SetupDmaTransfer(uint8_t* rdram, recomp_context* ctx)
{
   // printf("SetupDmaTransfer\n");

    uint32_t dest_vram = ctx->r4;
    uint32_t count = ctx->r6;

    uint8_t* dest_ptr = (uint8_t*)GET_PTR(dest_vram);


    printf("KDCD_SetupDmaTransfer dest_vram : <0x%08X>", dest_vram);
    if (g_cdImage && dest_ptr) {
        // Убираем +150! Твой .bin начинается сразу с LBA 0
        uint32_t physSector = g_cdCurrentSector;

        // 2352 - размер RAW-сектора
        uint32_t fileOffset = physSector * RAW_SECTOR_SIZE;

        // +24 для пропуска заголовка сектора Mode 2 (Form 1)
        fseek(g_cdImage, fileOffset + 24, SEEK_SET);

        fread(dest_ptr, 1, 2048, g_cdImage);

        // В ISO9660 строка "CD001" лежит начиная с 1-го байта сектора 
        // (нулевой байт - это тип дескриптора)
        printf("[HLE CD] SetupDmaTransfer: Read LBA %d to 0x%08X. Data: %c%c%c%c%c\n",
            g_cdCurrentSector, dest_vram,
            dest_ptr[1], dest_ptr[2], dest_ptr[3], dest_ptr[4], dest_ptr[5]);

        g_cdCurrentSector++;
    }

    ctx->r2 = 0; // Сообщаем об успехе
}

void KFCD_ResetReadState()
{
    g_cd_pass_count = 0;
    g_cd_last_stream = 0;
}
