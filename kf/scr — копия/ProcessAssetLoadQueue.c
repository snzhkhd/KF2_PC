#include "recomp.h"
#include "disable_warnings.h"


void ProcessAssetLoadQueue(uint8_t* rdram, recomp_context* ctx) 
{

    //// Лог ВСЕГДА, без условий
    //uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    //if (p_active)
    //{
    //    uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    //    if (stream)
    //    {
    //        printf("[ProcessAssetLoadQueue] stream=%d | (24) = <%d>, (12) = <%d>\n", stream[0], stream[24], stream[12]);
    //    }
    //}
    

    //// if (p_active && *p_active) {
    //    // uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    //    // if (stream) {
    //        // uint16_t total = *(uint16_t*)(stream + 32);
    //        // printf("[PAQ_ENTRY] stream=0x%08X state=%d ready=%d total=%d\n",
    //            // *p_active, stream[0], stream[36], total);
    //    // }
    //// }


    //if (p_active && *p_active) 
    //{
    //    uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    //    if (stream && stream[0] == 64 && stream[36] == 1) {
    //        uint32_t dst = *(uint32_t*)(stream + 12);
    //        uint16_t* v2 = (uint16_t*)GET_PTR(dst);
    //        if (v2) 
    //        {
    //            // Проверяем условие break из ProcessAssetLoadQueue
    //            bool will_break = (v2[0] != v2[4] || v2[1] != v2[5] ||
    //                v2[2] != v2[6] || v2[3] != v2[7] ||
    //                !v2[2] || !v2[3]);
    //            bool is_end = (v2[0] == 0xFFFF);
    //            uint16_t total = *(uint16_t*)(stream + 32);

    //            printf("[PAQ SKIP] v2[0-7]: %04X %04X %04X %04X | %04X %04X %04X %04X\n",
    //                v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
    //            printf("[PAQ SKIP] stream+24(rect): x=%d y=%d w=%d h=%d remaining=%d\n",
    //                *(int16_t*)(stream + 24), *(int16_t*)(stream + 26),
    //                *(int16_t*)(stream + 28), *(int16_t*)(stream + 30),
    //                total);
    //            printf("[PAQ SKIP] will force NextCdTask!\n");

    //            // Если сразу break и total маленький — это не текстурный стрим
    //            //if (will_break && total <= 16 && !is_end) 
    //            //{
    //            //    //printf("[PAQ] Non-texture small stream, forcing NextCdTask\n");
    //            //    stream[36] = 0;  // сбрасываем флаг
    //            //    recomp_func_t next_task = lookup_recomp_func(0x80017D2C); //0x80017D2C - NextCdTask
    //            //    if (next_task) {
    //            //        uint32_t saved_ra = ctx->r31;
    //            //        ctx->r4 = *p_active;
    //            //        next_task(rdram, ctx);
    //            //        ctx->r31 = saved_ra;
    //            //    }
    //            //    ctx->r2 = 0;
    //            //    return;
    //            //}
    //        }
    //    }
    //}
    //uint32_t stream_ptr = MEM_W(0, ADDR_G_ACTIVECDSTREAM);
 //   printf("ProcessAssetLoadQueue\n");

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80062840
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // lw          $s1, -0x57B8($s1)
    ctx->r17 = MEM_W(-0X57B8, ctx->r17);
    // nop

    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // bne         $v1, $v0, L_80017658
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80017658;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lbu         $v1, 0x24($s1)
    ctx->r3 = MEM_BU(0X24, ctx->r17);
    // nop

    // bne         $v1, $v0, L_80017658
    if (ctx->r3 != ctx->r2) {
        // addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
        goto L_80017658;
    }
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(0XC, ctx->r17);
    // jal         0x80062AF0
    // sb          $zero, 0x24($s1)
    MEM_B(0X24, ctx->r17) = 0;
    KF_ExitCriticalSection(rdram, ctx);
    goto after_1;
    // sb          $zero, 0x24($s1)
    MEM_B(0X24, ctx->r17) = 0;
    after_1:
L_80017444:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // lh          $a1, 0x1E($s1)
    ctx->r5 = MEM_H(0X1E, ctx->r17);
    // subu        $v1, $v0, $s4
    ctx->r3 = SUB32(ctx->r2, ctx->r20);
    // beq         $a1, $zero, L_80017500
    if (ctx->r5 == 0) {
        // addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
        goto L_80017500;
    }
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // lh          $a0, 0x1C($s1)
    ctx->r4 = MEM_H(0X1C, ctx->r17);
    // nop

    // mult        $a1, $a0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sll         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2) << 1;
    // slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // beq         $v0, $zero, L_800174E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800174E0;
    }
    // nop

    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_80017488
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80017488;
    }
    // nop

    // break       7
    do_break(2147579012);
L_80017488:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_800174A0
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800174A0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_800174A0
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_800174A0;
    }
    // nop

    // break       6
    do_break(2147579036);
L_800174A0:
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // sra         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3) >> 1;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // beq         $v0, $zero, L_800175F8
    if (ctx->r2 == 0) {
        // addu        $v1, $s2, $zero
        ctx->r3 = ADD32(ctx->r18, 0);
        goto L_800175F8;
    }
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x800632F8
    // sh          $v1, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r3;
    LoadImageWithCallback(rdram, ctx);
    goto after_2;
    // sh          $v1, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r3;
    after_2:
    // lhu         $v1, 0x1A($s1)
    ctx->r3 = MEM_HU(0X1A, ctx->r17);
    // subu        $v0, $s3, $s2
    ctx->r2 = SUB32(ctx->r19, ctx->r18);
    // sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    // addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // j           L_800175F8
    // sh          $v1, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r3;
    goto L_800175F8;
    // sh          $v1, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r3;
L_800174E0:
    // addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x800632F8
    // sh          $s3, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r19;
    //printf("ProcessAssetLoadQueue call LoadImageWithCallback!\n");
    LoadImageWithCallback(rdram, ctx);
    goto after_3;
    // sh          $s3, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r19;
    after_3:
    // addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // j           L_80017444
    // sh          $zero, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = 0;
    goto L_80017444;
    // sh          $zero, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = 0;
L_80017500:
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_800175FC
    if (ctx->r2 != 0) {
        // addiu       $a0, $s1, 0x2
        ctx->r4 = ADD32(ctx->r17, 0X2);
        goto L_800175FC;
    }
    // addiu       $a0, $s1, 0x2
    ctx->r4 = ADD32(ctx->r17, 0X2);
    // lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(0X0, ctx->r16);
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // bne         $a1, $v0, L_8001756C
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_8001756C;
    }
    // nop

    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // nop

    // bne         $v1, $v0, L_8001756C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001756C;
    }
    // nop

    // lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(0X4, ctx->r16);
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // bne         $a0, $v0, L_8001756C
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8001756C;
    }
    // nop

    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // bne         $v1, $v0, L_8001756C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001756C;
    }
    // nop

    // beq         $a0, $zero, L_8001756C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8001756C;
    }
    // nop

    // bne         $v1, $zero, L_800175BC
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_800175BC;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8001756C:
    // lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(0X20, ctx->r17);
    // sh          $zero, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = 0;
    // sb          $zero, 0x24($s1)
    MEM_B(0X24, ctx->r17) = 0;
    // sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    // lwl         $v0, 0x9($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X9, ctx->r17);
    // lwr         $v0, 0x6($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X6, ctx->r17);
    // nop

    // swl         $v0, 0x5($s1)
    do_swl(rdram, 0X5, ctx->r17, ctx->r2);
    // swr         $v0, 0x2($s1)
    do_swr(rdram, 0X2, ctx->r17, ctx->r2);
    // jal         0x800173B0
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    CalculateNextCdChunk(rdram, ctx);
    goto after_4;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_800175A0:
    // addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // beq         $v0, $zero, L_800175A0
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_800175A0;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_80017660
    // nop

    goto L_80017660;
    // nop

L_800175BC:
    // beq         $a1, $v0, L_8001763C
    if (ctx->r5 == ctx->r2) {
        // addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
        goto L_8001763C;
    }
    // addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // j           L_80017444
    // sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    goto L_80017444;
    // sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
L_800175F8:
    // addiu       $a0, $s1, 0x2
    ctx->r4 = ADD32(ctx->r17, 0X2);
L_800175FC:
    // lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(0X10, ctx->r17);
    // jal         0x80018150
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    ConvertCdAddress(rdram, ctx);
    goto after_6;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_6:
    // jal         0x800173B0
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    CalculateNextCdChunk(rdram, ctx);
    goto after_7;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800630D0
    // sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    KF_DrawSync(rdram, ctx);
    goto after_8;
    // sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    after_8:
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_80017620:
    // addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_9;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // beq         $v0, $zero, L_80017620
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_80017620;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_80017660
    // nop

    goto L_80017660;
    // nop

L_8001763C:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_10;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // jal         0x80017D2C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    NextCdTask(rdram, ctx);
    goto after_11;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
    // j           L_80017660
    // nop

    goto L_80017660;
    // nop

L_80017658:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_80017660:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
