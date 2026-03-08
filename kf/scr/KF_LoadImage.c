#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_render.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void KF_LoadImage(uint8_t* rdram, recomp_context* ctx) 
{
    RECT16* rect = (RECT16*)GET_PTR(ctx->r4);
    u_long* p = (u_long*)GET_PTR(ctx->r5);

    if (rect->w > 1024) {
        // PS1 wrap-around: данные льются линейно в VRAM
        uint16_t* src = (uint16_t*)p;
        int total = (int)rect->w * (int)rect->h;
        int cur_x = rect->x;
        int cur_y = rect->y;
        int offset = 0;

        ////debug
        //static bool once = false;
        //if (!once) 
        //{
        //    once = true;
        //    GR_SaveVRAM("vram_after_wrap.png", 0, 0, 1024, 512, 0);
        //    printf("[DUMP] saved after first wrap upload\n");
        //}

        //printf("[WRAP] src first bytes: %04X %04X %04X %04X (total=%d)\n",
        //    src[0], src[1], src[2], src[3],
        //    (int)rect->w * (int)rect->h);

        while (offset < total) {
            int chunk = 1024 - cur_x; // до конца строки VRAM
            if (chunk > total - offset)
                chunk = total - offset;
            if (chunk <= 0) break;

            GR_CopyVRAM(src + offset, 0, 0, chunk, 1, cur_x, cur_y);
            GR_UpdateVRAM();
            offset += chunk;
            cur_x += chunk;
            if (cur_x >= 1024) {
                cur_x = 0;
                cur_y++;
            }
        }
        //printf("[LoadImage WRAP] total=%d pixels uploaded, end=(%d,%d)\n",
        //    total, cur_x, cur_y);
    }
    else {
        // Обычная загрузка
        LoadImage(rect, p);
        GR_UpdateVRAM();
    }


   
    //u_long* p = (u_long*)GET_PTR(ctx->r5); // a1: Пиксели
    //printf("[KF_LoadImage] rect=(%d,%d,%d,%d) pixels_ptr=0x%08X first_bytes=%02X %02X %02X %02X\n",
    //    rect->x, rect->y, rect->w, rect->h,
    //    ctx->r5,
    //    ((uint8_t*)p)[0], ((uint8_t*)p)[1],
    //    ((uint8_t*)p)[2], ((uint8_t*)p)[3]);
    //LoadImage(rect, p); // Функция из Psy-X
   // GR_ClearVRAM(0, 0, 0, 0, 0, 0, 0);

   // GR_UpdateVRAM();
    ctx->r2 = 0;

    return;
}
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x40
//    ctx->r29 = ADD32(ctx->r29, -0X40);
//    // sw          $s1, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r17;
//    // addu        $s1, $a0, $zero
//    ctx->r17 = ADD32(ctx->r4, 0);
//    // sw          $s2, 0x28($sp)
//    MEM_W(0X28, ctx->r29) = ctx->r18;
//    // addu        $s2, $a1, $zero
//    ctx->r18 = ADD32(ctx->r5, 0);
//    // sw          $ra, 0x38($sp)
//    MEM_W(0X38, ctx->r29) = ctx->r31;
//    // sw          $s5, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r21;
//    // sw          $s4, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r20;
//    // sw          $s3, 0x2C($sp)
//    MEM_W(0X2C, ctx->r29) = ctx->r19;
//    // jal         0x800655A8
//    // sw          $s0, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r16;
//    SyncVSyncStatus(rdram, ctx);
//    goto after_0;
//    // sw          $s0, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r16;
//    after_0:
//    // lh          $a0, 0x4($s1)
//    ctx->r4 = MEM_H(0X4, ctx->r17);
//    // addu        $s5, $zero, $zero
//    ctx->r21 = ADD32(0, 0);
//    // bltz        $a0, L_80064764
//    if (SIGNED(ctx->r4) < 0) {
//        // addu        $v1, $a0, $zero
//        ctx->r3 = ADD32(ctx->r4, 0);
//        goto L_80064764;
//    }
//    // addu        $v1, $a0, $zero
//    ctx->r3 = ADD32(ctx->r4, 0);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, 0x61A4
//    ctx->r5 = ADD32(ctx->r5, 0X61A4);
//    // lhu         $v0, 0x0($a1)
//    ctx->r2 = MEM_HU(0X0, ctx->r5);
//    // nop
//
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // slt         $v0, $v0, $a0
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
//    // beq         $v0, $zero, L_80064768
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80064768;
//    }
//    // nop
//
//    // lhu         $v1, 0x0($a1)
//    ctx->r3 = MEM_HU(0X0, ctx->r5);
//    // j           L_80064768
//    // nop
//
//    goto L_80064768;
//    // nop
//
//L_80064764:
//    // addu        $v1, $zero, $zero
//    ctx->r3 = ADD32(0, 0);
//L_80064768:
//    // lh          $a1, 0x6($s1)
//    ctx->r5 = MEM_H(0X6, ctx->r17);
//    // sh          $v1, 0x4($s1)
//    MEM_H(0X4, ctx->r17) = ctx->r3;
//    // bltz        $a1, L_800647A8
//    if (SIGNED(ctx->r5) < 0) {
//        // addu        $v1, $a1, $zero
//        ctx->r3 = ADD32(ctx->r5, 0);
//        goto L_800647A8;
//    }
//    // addu        $v1, $a1, $zero
//    ctx->r3 = ADD32(ctx->r5, 0);
//    // lui         $a2, 0x8007
//    ctx->r6 = S32(0X8007 << 16);
//    // addiu       $a2, $a2, 0x61A6
//    ctx->r6 = ADD32(ctx->r6, 0X61A6);
//    // lhu         $v0, 0x0($a2)
//    ctx->r2 = MEM_HU(0X0, ctx->r6);
//    // nop
//
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // slt         $v0, $v0, $a1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
//    // beq         $v0, $zero, L_800647AC
//    if (ctx->r2 == 0) {
//        // addu        $a0, $v1, $zero
//        ctx->r4 = ADD32(ctx->r3, 0);
//        goto L_800647AC;
//    }
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//    // lhu         $a0, 0x0($a2)
//    ctx->r4 = MEM_HU(0X0, ctx->r6);
//    // j           L_800647B0
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//    goto L_800647B0;
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//L_800647A8:
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//L_800647AC:
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//L_800647B0:
//    // lh          $v1, 0x4($s1)
//    ctx->r3 = MEM_H(0X4, ctx->r17);
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // mult        $v1, $v0
//    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
//    // sh          $a0, 0x6($s1)
//    MEM_H(0X6, ctx->r17) = ctx->r4;
//    // mflo        $v0
//    ctx->r2 = lo;
//    // addiu       $v0, $v0, 0x1
//    ctx->r2 = ADD32(ctx->r2, 0X1);
//    // srl         $v1, $v0, 31
//    ctx->r3 = S32(U32(ctx->r2) >> 31);
//    // addu        $v0, $v0, $v1
//    ctx->r2 = ADD32(ctx->r2, ctx->r3);
//    // sra         $a0, $v0, 1
//    ctx->r4 = S32(ctx->r2) >> 1;
//    // bgtz        $a0, L_800647E4
//    if (SIGNED(ctx->r4) > 0) {
//        // sra         $s0, $v0, 5
//        ctx->r16 = S32(ctx->r2) >> 5;
//        goto L_800647E4;
//    }
//    // sra         $s0, $v0, 5
//    ctx->r16 = S32(ctx->r2) >> 5;
//    // j           L_80064924
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_80064924;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_800647E4:
//    // addu        $v1, $s0, $zero
//    ctx->r3 = ADD32(ctx->r16, 0);
//    // sll         $v0, $v1, 4
//    ctx->r2 = S32(ctx->r3) << 4;
//    // subu        $s0, $a0, $v0
//    ctx->r16 = SUB32(ctx->r4, ctx->r2);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // addu        $s4, $v1, $zero
//    ctx->r20 = ADD32(ctx->r3, 0);
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // lui         $v1, 0x400
//    ctx->r3 = S32(0X400 << 16);
//    // and         $v0, $v0, $v1
//    ctx->r2 = ctx->r2 & ctx->r3;
//    // bne         $v0, $zero, L_80064844
//    if (ctx->r2 != 0) {
//        // lui         $a0, 0xA000
//        ctx->r4 = S32(0XA000 << 16);
//        goto L_80064844;
//    }
//    // lui         $a0, 0xA000
//    ctx->r4 = S32(0XA000 << 16);
//    // lui         $s3, 0x400
//    ctx->r19 = S32(0X400 << 16);
//L_80064814:
//    // jal         0x800655DC
//    // nop
//
//    GPU_CheckTimeout_800655DC(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // bne         $v0, $zero, L_80064924
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_80064924;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // nop
//
//    // and         $v0, $v0, $s3
//    ctx->r2 = ctx->r2 & ctx->r19;
//    // beq         $v0, $zero, L_80064814
//    if (ctx->r2 == 0) {
//        // lui         $a0, 0xA000
//        ctx->r4 = S32(0XA000 << 16);
//        goto L_80064814;
//    }
//    // lui         $a0, 0xA000
//    ctx->r4 = S32(0XA000 << 16);
//L_80064844:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6274($v1)
//    ctx->r3 = MEM_W(0X6274, ctx->r3);
//    // lui         $v0, 0x400
//    ctx->r2 = S32(0X400 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lui         $v0, 0x100
//    ctx->r2 = S32(0X100 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6270($v0)
//    ctx->r2 = MEM_W(0X6270, ctx->r2);
//    // beq         $s5, $zero, L_80064878
//    if (ctx->r21 == 0) {
//        // nop
//    
//        goto L_80064878;
//    }
//    // nop
//
//    // lui         $a0, 0xB000
//    ctx->r4 = S32(0XB000 << 16);
//L_80064878:
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lw          $v0, 0x0($s1)
//    ctx->r2 = MEM_W(0X0, ctx->r17);
//    // nop
//
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lw          $v0, 0x4($s1)
//    ctx->r2 = MEM_W(0X4, ctx->r17);
//    // addiu       $s0, $s0, -0x1
//    ctx->r16 = ADD32(ctx->r16, -0X1);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // beq         $s0, $v0, L_800648D4
//    if (ctx->r16 == ctx->r2) {
//        // nop
//    
//        goto L_800648D4;
//    }
//    // nop
//
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//L_800648B4:
//    // lw          $v1, 0x0($s2)
//    ctx->r3 = MEM_W(0X0, ctx->r18);
//    // addiu       $s2, $s2, 0x4
//    ctx->r18 = ADD32(ctx->r18, 0X4);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6270($v0)
//    ctx->r2 = MEM_W(0X6270, ctx->r2);
//    // addiu       $s0, $s0, -0x1
//    ctx->r16 = ADD32(ctx->r16, -0X1);
//    // sw          $v1, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r3;
//    // bne         $s0, $a0, L_800648B4
//    if (ctx->r16 != ctx->r4) {
//        // nop
//    
//        goto L_800648B4;
//    }
//    // nop
//
//L_800648D4:
//    // beq         $s4, $zero, L_80064920
//    if (ctx->r20 == 0) {
//        // lui         $v1, 0x400
//        ctx->r3 = S32(0X400 << 16);
//        goto L_80064920;
//    }
//    // lui         $v1, 0x400
//    ctx->r3 = S32(0X400 << 16);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // ori         $v1, $v1, 0x2
//    ctx->r3 = ctx->r3 | 0X2;
//    // sw          $v1, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r3;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6278($v0)
//    ctx->r2 = MEM_W(0X6278, ctx->r2);
//    // lui         $a0, 0x100
//    ctx->r4 = S32(0X100 << 16);
//    // sw          $s2, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r18;
//    // sll         $v0, $s4, 16
//    ctx->r2 = S32(ctx->r20) << 16;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x627C($v1)
//    ctx->r3 = MEM_W(0X627C, ctx->r3);
//    // ori         $v0, $v0, 0x10
//    ctx->r2 = ctx->r2 | 0X10;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6280($v0)
//    ctx->r2 = MEM_W(0X6280, ctx->r2);
//    // ori         $a0, $a0, 0x201
//    ctx->r4 = ctx->r4 | 0X201;
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//L_80064920:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_80064924:
//    // lw          $ra, 0x38($sp)
//    ctx->r31 = MEM_W(0X38, ctx->r29);
//    // lw          $s5, 0x34($sp)
//    ctx->r21 = MEM_W(0X34, ctx->r29);
//    // lw          $s4, 0x30($sp)
//    ctx->r20 = MEM_W(0X30, ctx->r29);
//    // lw          $s3, 0x2C($sp)
//    ctx->r19 = MEM_W(0X2C, ctx->r29);
//    // lw          $s2, 0x28($sp)
//    ctx->r18 = MEM_W(0X28, ctx->r29);
//    // lw          $s1, 0x24($sp)
//    ctx->r17 = MEM_W(0X24, ctx->r29);
//    // lw          $s0, 0x20($sp)
//    ctx->r16 = MEM_W(0X20, ctx->r29);
//    // addiu       $sp, $sp, 0x40
//    ctx->r29 = ADD32(ctx->r29, 0X40);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

