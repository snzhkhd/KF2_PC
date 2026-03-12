#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"
#include <string>
#include <chrono>
#include "audio/PsyX_SPUAL.h"
#define SPU_MEMSIZE				(2048*1024)
void KF_SpuUpdateTick(uint8_t* rdram, recomp_context* ctx) 
{

    //static auto last_time = std::chrono::steady_clock::now();
    //static int tick_frames = 0;
    //tick_frames++;
    //auto now = std::chrono::steady_clock::now();
    //auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_time).count();
    //if (elapsed >= 1000) {
    //    printf("[SEQ] ticks per second: %d\n", tick_frames);
    //    tick_frames = 0;
    //    last_time = now;
    //}

    uint8_t max_voices = MEM_BU(0, 0x8019B628);

    for (int i = 0; i < 24 && i < max_voices; i++) {
        uint8_t flags = MEM_BU(0, 0x80078A38 + i);
        if (flags == 0) continue;

        // Внутренняя таблица: 16 байт на голос (8 halfwords)
        // Layout: volL, volR, pitch, startAddr, ADSR1, ADSR2, ...
        uint32_t base = 0x800788B8 + i * 16;

        SpuVoiceAttr attr;
        memset(&attr, 0, sizeof(attr));
        attr.voice = (1 << i);
        attr.mask = 0;

        //if (flags != 0) {
        //    static int upd_log = 0;
        //    if (upd_log++ < 30) {
        //        printf("[SpuTick] voice=%d flags=%02X vol=%d/%d pitch=%04X addr=%04X adsr=%04X/%04X\n",
        //            i, flags,
        //            (int16_t)MEM_HS(0, base), (int16_t)MEM_HS(2, base),
        //            MEM_HU(4, base),
        //            MEM_HU(6, base),
        //            MEM_HU(8, base), MEM_HU(10, base));
        //    }
        //}

        if (flags & 1) {
            attr.volume.left = (int16_t)MEM_HS(0, base);
            attr.volume.right = (int16_t)MEM_HS(2, base);
            attr.mask |= SPU_VOICE_VOLL | SPU_VOICE_VOLR;
        }
        if (flags & 4) {
            attr.pitch = MEM_HU(4, base);
            attr.mask |= SPU_VOICE_PITCH;
        }
        if (flags & 8) {
            uint32_t raw_addr = MEM_HU(6, base);
            uint32_t real_addr = raw_addr << 3;
            if (real_addr < 0x80000) {
                attr.addr = real_addr;
                attr.mask |= SPU_VOICE_WDSA;
                /*printf("[SPU Play] voice=%d addr=%08X pitch=%04X\n",
                    i, real_addr, MEM_HU(4, base));*/
            }
        }
        if (flags & 0x10) {
            attr.adsr1 = MEM_HU(8, base);
            attr.adsr2 = MEM_HU(10, base);
            attr.mask |= SPU_VOICE_ADSR_ADSR1 | SPU_VOICE_ADSR_ADSR2;
        }

        if (attr.mask) {
            SpuSetVoiceAttr(&attr);
        }

        MEM_B(0, 0x80078A38 + i) = 0;
    }

    // KeyOn
    uint16_t kon_lo = MEM_HU(0, 0x80079160);
    uint16_t kon_hi = MEM_HU(0, 0x80079168);
    uint32_t kon = kon_lo | (kon_hi << 16);
    if (kon) 
    {
       /* for (int i = 0; i < 24; i++) {
            if (kon & (1 << i)) {
                uint8_t f = MEM_BU(0, 0x80078A38 + i);
                uint32_t vbase = 0x800788B8 + i * 16;
                printf("[KeyOn] v=%d flags=%02X addr=%04X pitch=%04X adsr=%04X/%04X\n",
                    i, f, MEM_HU(6, vbase), MEM_HU(4, vbase),
                    MEM_HU(8, vbase), MEM_HU(10, vbase));
            }
        }*/

        for (int i = 0; i < 24; i++) {
            if (kon & (1 << i)) {
                uint32_t vbase = 0x800788B8 + i * 16;

                // Читаем все параметры из теневых регистров игры
                uint16_t vol_l = MEM_HU(0, vbase);
                uint16_t vol_r = MEM_HU(2, vbase);
                uint16_t pitch = MEM_HU(4, vbase);
                uint16_t addr = MEM_HU(6, vbase);
                uint16_t adsr1 = MEM_HU(8, vbase);
                uint16_t adsr2 = MEM_HU(10, vbase);

                // uint16_t addr_raw = MEM_HU(6, vbase);
                // printf("[KeyOn] voice=%d addr_raw=%04X (byte=%08X) pitch=%04X\n",
                    // i, addr_raw, addr_raw * 8, pitch);

                // Оставляем твой лог для отладки
                uint8_t f = MEM_BU(0, 0x80078A38 + i);
                /* printf("[KeyOn] v=%d flags=%02X addr=%04X pitch=%04X adsr=%04X/%04X\n",
                    i, f, addr, pitch, adsr1, adsr2); */

                    // 1. Создаем и обнуляем структуру
                SpuVoiceAttr attr;
                memset(&attr, 0, sizeof(attr));

                // 2. Указываем, какой голос настраиваем (битовая маска голоса)
                attr.voice = (1 << i);

                // 3. Указываем PsyX, какие именно поля мы хотим обновить
                attr.mask = SPU_VOICE_VOLL | SPU_VOICE_VOLR | SPU_VOICE_PITCH |
                    SPU_VOICE_WDSA | SPU_VOICE_ADSR_AMODE | SPU_VOICE_ADSR_SMODE |
                    SPU_VOICE_ADSR_RMODE | SPU_VOICE_ADSR_AR | SPU_VOICE_ADSR_DR |
                    SPU_VOICE_ADSR_SR | SPU_VOICE_ADSR_RR | SPU_VOICE_ADSR_SL;

                // 4. Громкость, Питч и Адрес
                attr.volume.left = vol_l;
                attr.volume.right = vol_r;
                attr.pitch = pitch;
                attr.addr = addr * 8; // ВАЖНО: PsyQ ожидает реальный байтовый адрес, поэтому умножаем на 8!

                // 5. РАСПАКОВКА ADSR1 (Attack, Decay, Sustain Level)
                attr.a_mode = (adsr1 >> 15) & 1;     // Бит 15: Attack Mode
                attr.ar = (adsr1 >> 8) & 0x7F;  // Биты 14-8: Attack Rate (7 бит)
                attr.dr = (adsr1 >> 4) & 0x0F;  // Биты 7-4: Decay Rate (4 бита)
                attr.sl = adsr1 & 0x0F;  // Биты 3-0: Sustain Level (4 бита)

                // 6. РАСПАКОВКА ADSR2 (Sustain Rate, Release Rate)
                attr.s_mode = (adsr2 >> 13) & 7;     // Биты 15-13: Sustain Mode (3 бита)
                attr.sr = (adsr2 >> 6) & 0x7F;  // Биты 12-6: Sustain Rate (7 бит)
                attr.r_mode = (adsr2 >> 5) & 1;     // Бит 5: Release Mode
                attr.rr = adsr2 & 0x1F;  // Биты 4-0: Release Rate (5 бит)

                // 7. Дублируем сырые значения (на случай, если PsyX имеет хак и читает их напрямую)
                attr.adsr1 = adsr1;
                attr.adsr2 = adsr2;

                // 8. Передаем в эмулятор!
                SpuSetVoiceAttr(&attr);
            }
        }


        SpuSetKey(SPU_ON, kon);



        //uint8_t* spuMem = PsyX_SPUAL_GetMemory();

        //for (int i = 0; i < 24; i++) {
        //    if (kon & (1 << i)) {
        //        uint32_t vbase = 0x800788B8 + i * 16;
        //        uint16_t addr_raw = MEM_HU(6, vbase);
        //        uint32_t byte_addr = addr_raw * 8;
        //        if (byte_addr + 16 < SPU_MEMSIZE) {
        //            uint8_t* spu = spuMem + byte_addr;
        //            printf("[SPU VERIFY] voice=%d addr=%08X "
        //                "bytes: %02X %02X %02X %02X %02X %02X %02X %02X\n",
        //                i, byte_addr,
        //                spu[0], spu[1], spu[2], spu[3],
        //                spu[4], spu[5], spu[6], spu[7]);
        //        }
        //    }
        //}


        MEM_H(0, 0x80079160) = 0;
        MEM_H(0, 0x80079168) = 0;
    }

    // KeyOff
    uint16_t koff_lo = MEM_HU(0, 0x801DF028);
    uint16_t koff_hi = MEM_HU(0, 0x801DF030);
    uint32_t koff = koff_lo | (koff_hi << 16);
    if (koff) 
    {
        SpuSetKey(SPU_OFF, koff);
        MEM_H(0, 0x801DF028) = 0;
        MEM_H(0, 0x801DF030) = 0;
    }

    ctx->r2 = 0;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x38
//    ctx->r29 = ADD32(ctx->r29, -0X38);
//    // sw          $ra, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r31;
//    // sw          $s4, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r20;
//    // sw          $s3, 0x2C($sp)
//    MEM_W(0X2C, ctx->r29) = ctx->r19;
//    // sw          $s2, 0x28($sp)
//    MEM_W(0X28, ctx->r29) = ctx->r18;
//    // sw          $s1, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r17;
//    // sw          $s0, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r16;
//    // addu        $s0, $zero, $zero
//    ctx->r16 = ADD32(0, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, -0x70D0($v0)
//    ctx->r2 = MEM_W(-0X70D0, ctx->r2);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // addiu       $v1, $v1, -0x70C8
//    ctx->r3 = ADD32(ctx->r3, -0X70C8);
//    // lui         $a0, 0x801A
//    ctx->r4 = S32(0X801A << 16);
//    // lbu         $a0, -0x49D8($a0)
//    ctx->r4 = MEM_BU(-0X49D8, ctx->r4);
//    // addiu       $v0, $v0, 0x1
//    ctx->r2 = ADD32(ctx->r2, 0X1);
//    // andi        $v0, $v0, 0xF
//    ctx->r2 = ctx->r2 & 0XF;
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sw          $v0, -0x70D0($at)
//    MEM_W(-0X70D0, ctx->r1) = ctx->r2;
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // addu        $v0, $v0, $v1
//    ctx->r2 = ADD32(ctx->r2, ctx->r3);
//    // blez        $a0, L_80057184
//    if (SIGNED(ctx->r4) <= 0) {
//        // sw          $zero, 0x0($v0)
//        MEM_W(0X0, ctx->r2) = 0;
//        goto L_80057184;
//    }
//    // sw          $zero, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = 0;
//    // addu        $a2, $v0, $zero
//    ctx->r6 = ADD32(ctx->r2, 0);
//    // ori         $t0, $zero, 0x1
//    ctx->r8 = 0 | 0X1;
//    // addu        $a3, $a0, $zero
//    ctx->r7 = ADD32(ctx->r4, 0);
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // addiu       $a0, $a0, -0x75AA
//    ctx->r4 = ADD32(ctx->r4, -0X75AA);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // lw          $a1, 0x44($a1)
//    ctx->r5 = MEM_W(0X44, ctx->r5);
//L_80057144:
//    // nop
//
//    // lhu         $v0, 0xC($a1)
//    ctx->r2 = MEM_HU(0XC, ctx->r5);
//    // nop
//
//    // sh          $v0, 0x0($a0)
//    MEM_H(0X0, ctx->r4) = ctx->r2;
//    // lhu         $v0, 0x0($a0)
//    ctx->r2 = MEM_HU(0X0, ctx->r4);
//    // nop
//
//    // bne         $v0, $zero, L_80057174
//    if (ctx->r2 != 0) {
//        // addiu       $a0, $a0, 0x34
//        ctx->r4 = ADD32(ctx->r4, 0X34);
//        goto L_80057174;
//    }
//    // addiu       $a0, $a0, 0x34
//    ctx->r4 = ADD32(ctx->r4, 0X34);
//    // lw          $v1, 0x0($a2)
//    ctx->r3 = MEM_W(0X0, ctx->r6);
//    // sllv        $v0, $t0, $s0
//    ctx->r2 = S32(ctx->r8) << (ctx->r16 & 31);
//    // or          $v0, $v0, $v1
//    ctx->r2 = ctx->r2 | ctx->r3;
//    // sw          $v0, 0x0($a2)
//    MEM_W(0X0, ctx->r6) = ctx->r2;
//L_80057174:
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // slt         $v0, $s0, $a3
//    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
//    // bne         $v0, $zero, L_80057144
//    if (ctx->r2 != 0) {
//        // addiu       $a1, $a1, 0x10
//        ctx->r5 = ADD32(ctx->r5, 0X10);
//        goto L_80057144;
//    }
//    // addiu       $a1, $a1, 0x10
//    ctx->r5 = ADD32(ctx->r5, 0X10);
//L_80057184:
//    // lui         $v0, 0x801B
//    ctx->r2 = S32(0X801B << 16);
//    // lbu         $v0, 0x5190($v0)
//    ctx->r2 = MEM_BU(0X5190, ctx->r2);
//    // nop
//
//    // bne         $v0, $zero, L_80057240
//    if (ctx->r2 != 0) {
//        // addu        $s0, $zero, $zero
//        ctx->r16 = ADD32(0, 0);
//        goto L_80057240;
//    }
//    // addu        $s0, $zero, $zero
//    ctx->r16 = ADD32(0, 0);
//    // addiu       $s2, $zero, -0x1
//    ctx->r18 = ADD32(0, -0X1);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // addiu       $v1, $v1, -0x70C8
//    ctx->r3 = ADD32(ctx->r3, -0X70C8);
//L_800571A4:
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // and         $s2, $s2, $v0
//    ctx->r18 = ctx->r18 & ctx->r2;
//    // slti        $v0, $s0, 0xF
//    ctx->r2 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
//    // bne         $v0, $zero, L_800571A4
//    if (ctx->r2 != 0) {
//        // addiu       $v1, $v1, 0x4
//        ctx->r3 = ADD32(ctx->r3, 0X4);
//        goto L_800571A4;
//    }
//    // addiu       $v1, $v1, 0x4
//    ctx->r3 = ADD32(ctx->r3, 0X4);
//    // lui         $v0, 0x801A
//    ctx->r2 = S32(0X801A << 16);
//    // lbu         $v0, -0x49D8($v0)
//    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8005723C
//    if (SIGNED(ctx->r2) <= 0) {
//        // addu        $s0, $zero, $zero
//        ctx->r16 = ADD32(0, 0);
//        goto L_8005723C;
//    }
//    // addu        $s0, $zero, $zero
//    ctx->r16 = ADD32(0, 0);
//    // ori         $s4, $zero, 0x1
//    ctx->r20 = 0 | 0X1;
//    // ori         $s3, $zero, 0x2
//    ctx->r19 = 0 | 0X2;
//    // addu        $s1, $zero, $zero
//    ctx->r17 = ADD32(0, 0);
//L_800571DC:
//    // sllv        $v0, $s4, $s0
//    ctx->r2 = S32(ctx->r20) << (ctx->r16 & 31);
//    // and         $v0, $s2, $v0
//    ctx->r2 = ctx->r18 & ctx->r2;
//    // beq         $v0, $zero, L_80057224
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80057224;
//    }
//    // nop
//
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addiu       $at, $at, -0x7595
//    ctx->r1 = ADD32(ctx->r1, -0X7595);
//    // addu        $at, $at, $s1
//    ctx->r1 = ADD32(ctx->r1, ctx->r17);
//    // lbu         $v0, 0x0($at)
//    ctx->r2 = MEM_BU(0X0, ctx->r1);
//    // nop
//
//    // bne         $v0, $s3, L_80057214
//    if (ctx->r2 != ctx->r19) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_80057214;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // lui         $a1, 0xFF
//    ctx->r5 = S32(0XFF << 16);
//    // jal         0x80059720
//    // ori         $a1, $a1, 0xFFFF
//    ctx->r5 = ctx->r5 | 0XFFFF;
//    KF_SpuSetNoiseVoice(rdram, ctx);
//    goto after_0;
//    // ori         $a1, $a1, 0xFFFF
//    ctx->r5 = ctx->r5 | 0XFFFF;
//    after_0:
//L_80057214:
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addiu       $at, $at, -0x7595
//    ctx->r1 = ADD32(ctx->r1, -0X7595);
//    // addu        $at, $at, $s1
//    ctx->r1 = ADD32(ctx->r1, ctx->r17);
//    // sb          $zero, 0x0($at)
//    MEM_B(0X0, ctx->r1) = 0;
//L_80057224:
//    // lui         $v0, 0x801A
//    ctx->r2 = S32(0X801A << 16);
//    // lbu         $v0, -0x49D8($v0)
//    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // slt         $v0, $s0, $v0
//    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
//    // bne         $v0, $zero, L_800571DC
//    if (ctx->r2 != 0) {
//        // addiu       $s1, $s1, 0x34
//        ctx->r17 = ADD32(ctx->r17, 0X34);
//        goto L_800571DC;
//    }
//    // addiu       $s1, $s1, 0x34
//    ctx->r17 = ADD32(ctx->r17, 0X34);
//L_8005723C:
//    // addu        $s0, $zero, $zero
//    ctx->r16 = ADD32(0, 0);
//L_80057240:
//    // addu        $s1, $zero, $zero
//    ctx->r17 = ADD32(0, 0);
//    // lui         $v0, 0x801E
//    ctx->r2 = S32(0X801E << 16);
//    // lhu         $v0, -0xFD8($v0)
//    ctx->r2 = MEM_HU(-0XFD8, ctx->r2);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lhu         $v1, -0x6EA0($v1)
//    ctx->r3 = MEM_HU(-0X6EA0, ctx->r3);
//    // lui         $a0, 0x801E
//    ctx->r4 = S32(0X801E << 16);
//    // lhu         $a0, -0xFD0($a0)
//    ctx->r4 = MEM_HU(-0XFD0, ctx->r4);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // lhu         $a1, -0x6E98($a1)
//    ctx->r5 = MEM_HU(-0X6E98, ctx->r5);
//    // nor         $v0, $zero, $v0
//    ctx->r2 = ~(0 | ctx->r2);
//    // and         $v1, $v1, $v0
//    ctx->r3 = ctx->r3 & ctx->r2;
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sh          $v1, -0x6EA0($at)
//    MEM_H(-0X6EA0, ctx->r1) = ctx->r3;
//    // nor         $a0, $zero, $a0
//    ctx->r4 = ~(0 | ctx->r4);
//    // and         $a1, $a1, $a0
//    ctx->r5 = ctx->r5 & ctx->r4;
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sh          $a1, -0x6E98($at)
//    MEM_H(-0X6E98, ctx->r1) = ctx->r5;
//L_80057284:
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addiu       $at, $at, -0x7594
//    ctx->r1 = ADD32(ctx->r1, -0X7594);
//    // addu        $at, $at, $s1
//    ctx->r1 = ADD32(ctx->r1, ctx->r17);
//    // lh          $v0, 0x0($at)
//    ctx->r2 = MEM_HS(0X0, ctx->r1);
//    // nop
//
//    // beq         $v0, $zero, L_800572A8
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_800572A8;
//    }
//    // nop
//
//    // jal         0x80055F60
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    sub_80055F60(rdram, ctx);
//    goto after_1;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_1:
//L_800572A8:
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addiu       $at, $at, -0x7588
//    ctx->r1 = ADD32(ctx->r1, -0X7588);
//    // addu        $at, $at, $s1
//    ctx->r1 = ADD32(ctx->r1, ctx->r17);
//    // lh          $v0, 0x0($at)
//    ctx->r2 = MEM_HS(0X0, ctx->r1);
//    // nop
//
//    // beq         $v0, $zero, L_800572CC
//    if (ctx->r2 == 0) {
//        // addiu       $s1, $s1, 0x34
//        ctx->r17 = ADD32(ctx->r17, 0X34);
//        goto L_800572CC;
//    }
//    // addiu       $s1, $s1, 0x34
//    ctx->r17 = ADD32(ctx->r17, 0X34);
//    // jal         0x80056504
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    sub_80056504(rdram, ctx);
//    goto after_2;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_2:
//L_800572CC:
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // slti        $v0, $s0, 0x18
//    ctx->r2 = SIGNED(ctx->r16) < 0X18 ? 1 : 0;
//    // bne         $v0, $zero, L_80057284
//    if (ctx->r2 != 0) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_80057284;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // addiu       $a1, $a1, -0x75C8
//    ctx->r5 = ADD32(ctx->r5, -0X75C8);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addiu       $v0, $v0, -0x7748
//    ctx->r2 = ADD32(ctx->r2, -0X7748);
//    // addiu       $t1, $v0, 0xA
//    ctx->r9 = ADD32(ctx->r2, 0XA);
//    // addiu       $t0, $v0, 0x8
//    ctx->r8 = ADD32(ctx->r2, 0X8);
//    // addiu       $a3, $v0, 0x2
//    ctx->r7 = ADD32(ctx->r2, 0X2);
//    // addu        $a2, $v0, $zero
//    ctx->r6 = ADD32(ctx->r2, 0);
//L_800572FC:
//    // lbu         $v0, 0x0($a1)
//    ctx->r2 = MEM_BU(0X0, ctx->r5);
//    // nop
//
//    // andi        $v0, $v0, 0x1
//    ctx->r2 = ctx->r2 & 0X1;
//    // beq         $v0, $zero, L_80057330
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80057330;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x44($v0)
//    ctx->r2 = MEM_W(0X44, ctx->r2);
//    // lhu         $v1, 0x0($a2)
//    ctx->r3 = MEM_HU(0X0, ctx->r6);
//    // addu        $v0, $a0, $v0
//    ctx->r2 = ADD32(ctx->r4, ctx->r2);
//    // sh          $v1, 0x0($v0)
//    MEM_H(0X0, ctx->r2) = ctx->r3;
//    // lhu         $v1, 0x0($a3)
//    ctx->r3 = MEM_HU(0X0, ctx->r7);
//    // nop
//
//    // sh          $v1, 0x2($v0)
//    MEM_H(0X2, ctx->r2) = ctx->r3;
//L_80057330:
//    // lbu         $v0, 0x0($a1)
//    ctx->r2 = MEM_BU(0X0, ctx->r5);
//    // nop
//
//    // andi        $v0, $v0, 0x4
//    ctx->r2 = ctx->r2 & 0X4;
//    // beq         $v0, $zero, L_80057364
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80057364;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x44($v0)
//    ctx->r2 = MEM_W(0X44, ctx->r2);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addiu       $at, $at, -0x7744
//    ctx->r1 = ADD32(ctx->r1, -0X7744);
//    // addu        $at, $at, $a0
//    ctx->r1 = ADD32(ctx->r1, ctx->r4);
//    // lhu         $v1, 0x0($at)
//    ctx->r3 = MEM_HU(0X0, ctx->r1);
//    // addu        $v0, $a0, $v0
//    ctx->r2 = ADD32(ctx->r4, ctx->r2);
//    // sh          $v1, 0x4($v0)
//    MEM_H(0X4, ctx->r2) = ctx->r3;
//L_80057364:
//    // lbu         $v0, 0x0($a1)
//    ctx->r2 = MEM_BU(0X0, ctx->r5);
//    // nop
//
//    // andi        $v0, $v0, 0x8
//    ctx->r2 = ctx->r2 & 0X8;
//    // beq         $v0, $zero, L_80057398
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80057398;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x44($v0)
//    ctx->r2 = MEM_W(0X44, ctx->r2);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addiu       $at, $at, -0x7742
//    ctx->r1 = ADD32(ctx->r1, -0X7742);
//    // addu        $at, $at, $a0
//    ctx->r1 = ADD32(ctx->r1, ctx->r4);
//    // lhu         $v1, 0x0($at)
//    ctx->r3 = MEM_HU(0X0, ctx->r1);
//    // addu        $v0, $a0, $v0
//    ctx->r2 = ADD32(ctx->r4, ctx->r2);
//    // sh          $v1, 0x6($v0)
//    MEM_H(0X6, ctx->r2) = ctx->r3;
//L_80057398:
//    // lbu         $v0, 0x0($a1)
//    ctx->r2 = MEM_BU(0X0, ctx->r5);
//    // nop
//
//    // andi        $v0, $v0, 0x10
//    ctx->r2 = ctx->r2 & 0X10;
//    // beq         $v0, $zero, L_800573CC
//    if (ctx->r2 == 0) {
//        // addiu       $a3, $a3, 0x10
//        ctx->r7 = ADD32(ctx->r7, 0X10);
//        goto L_800573CC;
//    }
//    // addiu       $a3, $a3, 0x10
//    ctx->r7 = ADD32(ctx->r7, 0X10);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x44($v0)
//    ctx->r2 = MEM_W(0X44, ctx->r2);
//    // lhu         $v1, 0x0($t0)
//    ctx->r3 = MEM_HU(0X0, ctx->r8);
//    // addu        $v0, $a0, $v0
//    ctx->r2 = ADD32(ctx->r4, ctx->r2);
//    // sh          $v1, 0x8($v0)
//    MEM_H(0X8, ctx->r2) = ctx->r3;
//    // lhu         $v1, 0x0($t1)
//    ctx->r3 = MEM_HU(0X0, ctx->r9);
//    // nop
//
//    // sh          $v1, 0xA($v0)
//    MEM_H(0XA, ctx->r2) = ctx->r3;
//L_800573CC:
//    // sb          $zero, 0x0($a1)
//    MEM_B(0X0, ctx->r5) = 0;
//    // addiu       $a1, $a1, 0x1
//    ctx->r5 = ADD32(ctx->r5, 0X1);
//    // addiu       $t1, $t1, 0x10
//    ctx->r9 = ADD32(ctx->r9, 0X10);
//    // addiu       $t0, $t0, 0x10
//    ctx->r8 = ADD32(ctx->r8, 0X10);
//    // addiu       $a0, $a0, 0x10
//    ctx->r4 = ADD32(ctx->r4, 0X10);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addiu       $v0, $v0, -0x75B0
//    ctx->r2 = ADD32(ctx->r2, -0X75B0);
//    // slt         $v0, $a1, $v0
//    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
//    // bne         $v0, $zero, L_800572FC
//    if (ctx->r2 != 0) {
//        // addiu       $a2, $a2, 0x10
//        ctx->r6 = ADD32(ctx->r6, 0X10);
//        goto L_800572FC;
//    }
//    // addiu       $a2, $a2, 0x10
//    ctx->r6 = ADD32(ctx->r6, 0X10);
//    // lui         $t0, 0x801E
//    ctx->r8 = S32(0X801E << 16);
//    // lhu         $t0, -0xFD8($t0)
//    ctx->r8 = MEM_HU(-0XFD8, ctx->r8);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x44($v0)
//    ctx->r2 = MEM_W(0X44, ctx->r2);
//    // lui         $v1, 0x801E
//    ctx->r3 = S32(0X801E << 16);
//    // lhu         $v1, -0xFD0($v1)
//    ctx->r3 = MEM_HU(-0XFD0, ctx->r3);
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // lhu         $a0, -0x6EA0($a0)
//    ctx->r4 = MEM_HU(-0X6EA0, ctx->r4);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // lhu         $a1, -0x6E98($a1)
//    ctx->r5 = MEM_HU(-0X6E98, ctx->r5);
//    // lui         $a2, 0x8008
//    ctx->r6 = S32(0X8008 << 16);
//    // lhu         $a2, -0x6E90($a2)
//    ctx->r6 = MEM_HU(-0X6E90, ctx->r6);
//    // lui         $a3, 0x8008
//    ctx->r7 = S32(0X8008 << 16);
//    // lhu         $a3, -0x6E88($a3)
//    ctx->r7 = MEM_HU(-0X6E88, ctx->r7);
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // sh          $zero, -0xFD8($at)
//    MEM_H(-0XFD8, ctx->r1) = 0;
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // sh          $zero, -0xFD0($at)
//    MEM_H(-0XFD0, ctx->r1) = 0;
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sh          $zero, -0x6EA0($at)
//    MEM_H(-0X6EA0, ctx->r1) = 0;
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sh          $zero, -0x6E98($at)
//    MEM_H(-0X6E98, ctx->r1) = 0;
//    // sh          $t0, 0x18C($v0)
//    MEM_H(0X18C, ctx->r2) = ctx->r8;
//    // sh          $v1, 0x18E($v0)
//    MEM_H(0X18E, ctx->r2) = ctx->r3;
//    // sh          $a0, 0x188($v0)
//    MEM_H(0X188, ctx->r2) = ctx->r4;
//    // sh          $a1, 0x18A($v0)
//    MEM_H(0X18A, ctx->r2) = ctx->r5;
//    // sh          $a2, 0x198($v0)
//    MEM_H(0X198, ctx->r2) = ctx->r6;
//    // sh          $a3, 0x19A($v0)
//    MEM_H(0X19A, ctx->r2) = ctx->r7;
//    // lw          $ra, 0x34($sp)
//    ctx->r31 = MEM_W(0X34, ctx->r29);
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
//    // jr          $ra
//    // addiu       $sp, $sp, 0x38
//    ctx->r29 = ADD32(ctx->r29, 0X38);
//    return;
//    // addiu       $sp, $sp, 0x38
//    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
