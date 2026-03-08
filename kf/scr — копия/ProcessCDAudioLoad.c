#include "recomp.h"
#include "disable_warnings.h"

void ProcessCDAudioLoad(uint8_t* rdram, recomp_context* ctx) 
{
    //uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    //uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    //if (stream) 
    //{
    //    printf("[ProcessCDAudioLoad] stream[0]=%d stream[24]=%d stream[26]=%d stream[28]=%d\n",
    //        *(int16_t*)(stream + 0),
    //        *(int16_t*)(stream + 24),
    //        *(int16_t*)(stream + 26),
    //        *(int16_t*)(stream + 28));
    //}
   
    //uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    //if (!p_active || !*p_active) 
    //{
    //    printf("[ProcessCDAudioLoad] active stream not found!\n");
    //    ctx->r2 = 0; 
    //    return;
    //}

    //uint8_t* stream = (uint8_t*)GET_PTR(*p_active);
    //if (!stream) 
    //{
    //    printf("[ProcessCDAudioLoad] stream not valid!\n");

    //    ctx->r2 = 0; return;
    //}

    //if (stream[0] == 48 )//&& *(uint16_t*)(stream + 24) == 2) 
    //{
    //    printf("[ProcessCDAudioLoad] VAB stream detected, forcing complete\n");

    //    // Симулируем **(v0+28) = 1
    //    uint32_t channel_ptr = *(uint32_t*)(stream + 28);
    //    if (channel_ptr) {
    //        uint32_t* channel = (uint32_t*)GET_PTR(channel_ptr);
    //        if (channel) *channel = 1;
    //    }

    //    // NextCdTask
    //    recomp_func_t next_task = lookup_recomp_func(0x80017D2C);
    //    if (next_task) {
    //        uint32_t saved_ra = ctx->r31;
    //        ctx->r4 = *p_active;
    //        next_task(rdram, ctx);
    //        ctx->r31 = saved_ra;
    //    }

    //    // stream+16 = 0 (оригинал делает это)
    //    *(uint16_t*)(stream + 16) = 0;

    //    printf("[ProcessCDAudioLoad] VAB stream complete, NextCdTask called\n");
    //}
    //else
    //{
    //    printf("another stream 0 <%d>, +24 <%d>\n\n", stream[0], *(uint16_t*)(stream + 24));
    //}
    //ctx->r2 = 0;

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80062840
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // lw          $s0, -0x57B8($s0)
    ctx->r16 = MEM_W(-0X57B8, ctx->r16);
    // nop

    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // bne         $v1, $v0, L_80014AA8
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80014AA8;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(0X18, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80014AA8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80014AA8;
    }
    // nop

    // jal         0x80062AF0
    // addiu       $s3, $s0, 0x2
    ctx->r19 = ADD32(ctx->r16, 0X2);
    KF_ExitCriticalSection(rdram, ctx);
    goto after_1;
    // addiu       $s3, $s0, 0x2
    ctx->r19 = ADD32(ctx->r16, 0X2);
    after_1:
    // lh          $v0, 0x1A($s0)
    ctx->r2 = MEM_H(0X1A, ctx->r16);
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x59AC
    ctx->r3 = ADD32(ctx->r3, -0X59AC);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
L_800149F0:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(0X0, ctx->r17);
    // jal         0x80051EB0
    // ori         $a1, $zero, 0x9000
    ctx->r5 = 0 | 0X9000;
    sub_80051EB0(rdram, ctx);
    goto after_2;
    // ori         $a1, $zero, 0x9000
    ctx->r5 = 0 | 0X9000;
    after_2:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80014A30
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_80014A30;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(0X0, ctx->r17);
    // jal         0x8005D010
    // nop

    FreeSPUVoice(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80017D2C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    NextCdTask(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // j           L_800149F0
    // nop

    goto L_800149F0;
    // nop

L_80014A30:
    // bne         $v1, $v0, L_80014A74
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80014A74;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(0X10, ctx->r16);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // jal         0x80018150
    // sb          $s2, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r18;
    ConvertCdAddress(rdram, ctx);
    goto after_5;
    // sb          $s2, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r18;
    after_5:
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_80014A50:
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // beq         $v0, $zero, L_80014A50
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_80014A50;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // jal         0x8005C564
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    SsVabTransCompleted(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_7:
    // j           L_80014AB0
    // nop

    goto L_80014AB0;
    // nop

L_80014A74:
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(0X0, ctx->r17);
    // nop

    // bne         $v1, $v0, L_80014AB0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80014AB0;
    }
    // nop

    // jal         0x80017D2C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    NextCdTask(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // jal         0x8005C564
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    SsVabTransCompleted(rdram, ctx);
    goto after_9;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_9:
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // nop

    // sh          $s2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r18;
    // j           L_80014AB0
    // sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    goto L_80014AB0;
    // sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_80014AA8:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_80014AB0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
