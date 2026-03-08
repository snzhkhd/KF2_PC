#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"


void sub_800305F4(uint8_t* rdram, recomp_context* ctx) 
{
    //int fogNear = *(int32_t*)GET_PTR(0x80194F5C); // KFCurrentFogNearValue
    //int param_1 = (int)ctx->r4;

   // printf("[Fog] dword_80194F5C = %08X | fogNear <%d>\n", MEM_W(0, 0x80194F5C), fogNear);
    //// KFTMDVertexBufferPointer Ч PS1 адрес вершин
    //uint32_t vtx_ps1 = MEM_W(0, 0x80194F60); // найди адрес KFTMDVertexBufferPointer
    //SVECTOR* pSVar3 = (SVECTOR*)GET_PTR(vtx_ps1);

    //// KFRenderTMDTransformVector Ч PS1 адрес буфера результата
    //uint32_t sxy_ps1 = 0x80190C48 /*  KFRenderTMDTransformVector */;
    //SVECTOR* sxy = (SVECTOR*)GET_PTR(sxy_ps1);

    //ctx_to_gte(ctx); // синхронизируем матрицу камеры

    //int fogNear = *(int32_t*)GET_PTR(0x80194F5C); // KFCurrentFogNearValue

    //param_1--;
    //while (param_1 != -1) {
    //    long local_28 = 0, local_24 = 0;
    //    long result = RotTransPers(pSVar3, (int*)sxy, &local_28, &local_24);

    //    int16_t* psVar2 = &sxy->pad;
    //    psVar2[-1] = (short)result; // vz
    //    if (local_24 != 0x1000)
    //        psVar2[-1] = -1;

    //    if (fogNear < 32000) {
    //        if (local_28 > 0xaef)
    //            local_28 = local_28 * 3 - 0x15e0;
    //        *psVar2 = (short)local_28;
    //    }
    //    else {
    //        *psVar2 = 0;
    //    }

    //    sxy++;
    //    pSVar3++;
    //    param_1--;
    //}

    //gte_to_ctx(ctx);
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x4F5C($v0)
    ctx->r2 = MEM_W(0X4F5C, ctx->r2);
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // lw          $s3, 0xB54($s3)
    ctx->r19 = MEM_W(0XB54, ctx->r19);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // addiu       $s2, $s2, 0xC48
    ctx->r18 = ADD32(ctx->r18, 0XC48);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // slti        $v0, $v0, 0x7D00
    ctx->r2 = SIGNED(ctx->r2) < 0X7D00 ? 1 : 0;
    // bne         $v0, $zero, L_80030698
    if (ctx->r2 != 0) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_80030698;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_80030714
    if (ctx->r17 == ctx->r2) {
        // ori         $s5, $zero, 0x1000
        ctx->r21 = 0 | 0X1000;
        goto L_80030714;
    }
    // ori         $s5, $zero, 0x1000
    ctx->r21 = 0 | 0X1000;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s0, $s2, 0x6
    ctx->r16 = ADD32(ctx->r18, 0X6);
L_80030650:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x8005F2C8
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    sub_8005F2C8(rdram, ctx);
    goto after_0;
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    after_0:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // beq         $v1, $s5, L_80030678
    if (ctx->r3 == ctx->r21) {
        // sh          $v0, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r2;
        goto L_80030678;
    }
    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
L_80030678:
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s4, L_80030650
    if (ctx->r17 != ctx->r20) {
        // addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
        goto L_80030650;
    }
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // j           L_80030714
    // nop

    goto L_80030714;
    // nop

L_80030698:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_80030714
    if (ctx->r17 == ctx->r2) {
        // addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
        goto L_80030714;
    }
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s0, $s2, 0x6
    ctx->r16 = ADD32(ctx->r18, 0X6);
L_800306AC:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x8005F2C8
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    sub_8005F2C8(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    after_1:
    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // beq         $v1, $v0, L_800306D8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800306D8;
    }
    // nop

    // sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
L_800306D8:
    // lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v1, 0xAF0
    ctx->r2 = SIGNED(ctx->r3) < 0XAF0 ? 1 : 0;
    // bne         $v0, $zero, L_800306FC
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800306FC;
    }
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $v0, $v1, -0xAF0
    ctx->r2 = ADD32(ctx->r3, -0XAF0);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800306FC:
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // bne         $s1, $s4, L_800306AC
    if (ctx->r17 != ctx->r20) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800306AC;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80030714:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
