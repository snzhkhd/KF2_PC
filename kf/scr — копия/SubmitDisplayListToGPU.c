#include "recomp.h"
#include "disable_warnings.h"

void SubmitDisplayListToGPU(uint8_t* rdram, recomp_context* ctx) 
{
    // int a2 = (int)ctx->r5;

    /*g_PrimitiveTypeTable[a2] Ч массив int**/
    // uint32_t* table = (uint32_t*)GET_PTR(0x80190254); // или правильный адрес
    // uint32_t v8_ps1 = table[a2]; // PS1 адрес элемента
    // int* v8 = (int*)GET_PTR(v8_ps1);
    // int v9 = *v8; // = *g_PrimitiveTypeTable[a2]

    // printf("[Submit] a2=%d v8_ps1=%08X v9=%08X check=%d\n",
        // a2, v8_ps1, v9, v9 ? *(v8 + 1) : -1);
    // int* ptr = (int*)GET_PTR(v8_ps1);
    // printf("[PrimType a2=%d] [0]=%d [1]=%d [2]=%d [3]=%d [4]=%d\n",
        // a2, ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);


    //if (ptr[1] == 0) {
    //    ptr[1] = 1; // принудительно разрешаем рендер
    //    //printf("[ZERO_PRIM] a2=%d v8_ps1=%08X Ч primitives not initialized!\n", a2, v8_ps1);
    //}



    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x254
    ctx->r1 = ADD32(ctx->r1, 0X254);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $s3, 0x0($at)
    ctx->r19 = MEM_W(0X0, ctx->r1);
    // lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(0X0, ctx->r18);
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(0X58, ctx->r29);
    // bne         $v0, $zero, L_80036B90
    if (ctx->r2 != 0) {
        // addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
        goto L_80036B90;
    }
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // beq         $s1, $zero, L_80036B78
    if (ctx->r17 == 0) {
        // nop
    
        goto L_80036B78;
    }
    // nop

    // jal         0x80037138
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    Resource_UnlinkAndFree(rdram, ctx);
    goto after_0;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
L_80036B78:
    // jal         0x80036594
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_1;
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_1:
    // jal         0x80030008
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80030008(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // j           L_80036DA4
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80036DA4;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80036B90:
    // bne         $s1, $zero, L_80036BDC
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80036BDC;
    }
    // nop

    // jal         0x80037264
    // nop

    sub_80037264(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // beq         $s1, $zero, L_80036DA4
    if (ctx->r17 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80036DA4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80036BAC:
    // sh          $s0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r16;
    // sw          $s2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r18;
L_80036BB4:
    // jal         0x80017BD8
    // sll         $a0, $fp, 3
    ctx->r4 = S32(ctx->r30) << 3;
    AllocateMemor_0(rdram, ctx);
    goto after_4;
    // sll         $a0, $fp, 3
    ctx->r4 = S32(ctx->r30) << 3;
    after_4:
    // bne         $v0, $zero, L_80036BD4
    if (ctx->r2 != 0) {
        // sw          $v0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r2;
        goto L_80036BD4;
    }
    // sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // jal         0x80037184
    // nop

    CleaningUpTempResources(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_80036BB4
    // nop

    goto L_80036BB4;
    // nop

L_80036BD4:
    // j           L_80036C00
    // sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    goto L_80036C00;
    // sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80036BDC:
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // beq         $v0, $s0, L_80036C04
    if (ctx->r2 == ctx->r16) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80036C04;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80037138
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    Resource_UnlinkAndFree(rdram, ctx);
    goto after_6;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80036BAC
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    goto L_80036BAC;
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_80036C00:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80036C04:
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
    // addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // jal         0x800365CC
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_800365CC(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // nop

    // bne         $v1, $s7, L_80036C40
    if (ctx->r3 != ctx->r23) {
        // addu        $s5, $v0, $zero
        ctx->r21 = ADD32(ctx->r2, 0);
        goto L_80036C40;
    }
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(0X6, ctx->r17);
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // beq         $v1, $v0, L_80036D2C
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $fp, $zero
        ctx->r4 = ADD32(ctx->r30, 0);
        goto L_80036D2C;
    }
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
L_80036C40:
    // jal         0x80030008
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80030008(rdram, ctx);
    goto after_8;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(0XC, ctx->r19);
    // lhu         $s0, 0x6($s5)
    ctx->r16 = MEM_HU(0X6, ctx->r21);
    // nop

    // beq         $s0, $zero, L_80036CCC
    if (ctx->r16 == 0) {
        // addu        $s4, $s3, $v0
        ctx->r20 = ADD32(ctx->r19, ctx->r2);
        goto L_80036CCC;
    }
    // addu        $s4, $s3, $v0
    ctx->r20 = ADD32(ctx->r19, ctx->r2);
    // addiu       $s2, $s5, 0xA
    ctx->r18 = ADD32(ctx->r21, 0XA);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(0X8, ctx->r21);
    // lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(0XC, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(0X0, ctx->r2);
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lw          $a1, 0xB54($a1)
    ctx->r5 = MEM_W(0XB54, ctx->r5);
    // jal         0x80036690
    // addu        $a2, $s3, $a2
    ctx->r6 = ADD32(ctx->r19, ctx->r6);
    sub_80036690(rdram, ctx);
    goto after_9;
    // addu        $a2, $s3, $a2
    ctx->r6 = ADD32(ctx->r19, ctx->r6);
    after_9:
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // beq         $v0, $zero, L_80036D0C
    if (ctx->r2 == 0) {
        // ori         $s6, $zero, 0xFFFF
        ctx->r22 = 0 | 0XFFFF;
        goto L_80036D0C;
    }
    // ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
L_80036C94:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(0XC, ctx->r17);
    // jal         0x80036754
    // addu        $a1, $s3, $a1
    ctx->r5 = ADD32(ctx->r19, ctx->r5);
    sub_80036754(rdram, ctx);
    goto after_10;
    // addu        $a1, $s3, $a1
    ctx->r5 = ADD32(ctx->r19, ctx->r5);
    after_10:
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // beq         $v0, $zero, L_80036D0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80036D0C;
    }
    // nop

    // j           L_80036C94
    // nop

    goto L_80036C94;
    // nop

L_80036CCC:
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0xB54($a0)
    ctx->r4 = MEM_W(0XB54, ctx->r4);
    // lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(0XC, ctx->r17);
L_80036CE0:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // bne         $v0, $zero, L_80036CE0
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80036CE0;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80036D0C:
    // lhu         $v0, 0x4($s5)
    ctx->r2 = MEM_HU(0X4, ctx->r21);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
L_80036D2C:
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, 0x2B8C
    ctx->r5 = ADD32(ctx->r5, 0X2B8C);
    // lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(0XC, ctx->r17);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // sh          $s7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r23;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
L_80036D48:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // bne         $v0, $zero, L_80036D48
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80036D48;
    }
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // addiu       $s0, $s0, 0x2B8C
    ctx->r16 = ADD32(ctx->r16, 0X2B8C);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(0X8, ctx->r17);
    // lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(0X1C, ctx->r29);
    // jal         0x800367D0
    // addu        $a1, $s3, $a1
    ctx->r5 = ADD32(ctx->r19, ctx->r5);
    sub_800367D0(rdram, ctx);
    goto after_11;
    // addu        $a1, $s3, $a1
    ctx->r5 = ADD32(ctx->r19, ctx->r5);
    after_11:
    // jal         0x8002FFF8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8002FFF8(rdram, ctx);
    goto after_12;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_80036DA4:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
