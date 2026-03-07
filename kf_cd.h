#pragma once
#include "_context.h"
#include <stdint.h>
#include <stdio.h>
#include "psx/libcd.h" 
//#define SECTOR_SIZE 2048
#define RAW_SECTOR_SIZE 2352

//typedef struct {
//    uint8_t minute;
//    uint8_t second;
//    uint8_t sector;
//} CdlLOC;

typedef struct {
    int active;
    uint32_t sector;
    uint32_t count;
    uint8_t* dst;
} KF_CD_Request;

extern FILE* g_cdImage;
extern uint32_t g_cdCurrentSector;
extern KF_CD_Request g_cdReq;
extern int g_cdReading;

static uint32_t g_cd_pass_count = 0;
static uint32_t g_cd_last_stream = 0;
static uint32_t g_cd_initial_dst = 0;
static int      g_cd_base_lba = -1;


#ifdef __cplusplus
extern "C"
{
#endif


int KFCD_CdPosToInt(CdlLOC* p);

int KFCD_Init(const char* path);


void KFCD_CdControl(uint8_t* rdram, recomp_context* ctx);
void KFCD_CdlReadN(uint8_t* rdram, recomp_context* ctx);
int KFCD_CdRead(int sectors, uint32_t* buf);
int KFCD_CdReadSync(int mode);
int KFCD_CdSync(int mode);

void KFCD_CdReadyCallback(uint8_t* rdram, recomp_context* ctx);
void KFCD_CdSyncCallback(uint8_t* rdram, recomp_context* ctx);

void KFCD_InvokeCallback(uint8_t* rdram,recomp_context* ctx,uint32_t cbAddr,uint8_t status);

void KDCD_SetupDmaTransfer(uint8_t* rdram, recomp_context* ctx);
#ifdef __cplusplus
}
#endif