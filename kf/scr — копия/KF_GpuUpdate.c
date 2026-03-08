#include "recomp.h"
#include "disable_warnings.h"

void KF_GpuUpdate(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("UpdatePlayerSystem\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jal         0x80030044
    // nop

    KF_RenderUpdateCamera(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x8002FA5C
    // nop

    sub_8002FA5C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80035D74
    // nop

    sub_80035D74(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x8002F1C8
    // nop

    sub_8002F1C8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8002FE74
    // nop

    KF_RenderBegin(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x800370FC
    // nop

    sub_800370FC(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x8003417C
    // nop

    UpdateTileLighting(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A72($v0)
    ctx->r2 = MEM_BU(-0X4A72, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lh          $a0, -0x1D2E($a0)
    ctx->r4 = MEM_H(-0X1D2E, ctx->r4);
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lh          $a1, 0x4F3E($a1)
    ctx->r5 = MEM_H(0X4F3E, ctx->r5);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A73($v1)
    ctx->r3 = MEM_BU(-0X4A73, ctx->r3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x1D48($at)
    MEM_B(-0X1D48, ctx->r1) = ctx->r2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1B74($at)
    MEM_B(-0X1B74, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1B98($at)
    MEM_B(-0X1B98, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1BBC($at)
    MEM_B(-0X1BBC, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1BE0($at)
    MEM_B(-0X1BE0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1C04($at)
    MEM_B(-0X1C04, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1C28($at)
    MEM_B(-0X1C28, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1C4C($at)
    MEM_B(-0X1C4C, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1C70($at)
    MEM_B(-0X1C70, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1C94($at)
    MEM_B(-0X1C94, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1CB8($at)
    MEM_B(-0X1CB8, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1CDC($at)
    MEM_B(-0X1CDC, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1D00($at)
    MEM_B(-0X1D00, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, -0x1D24($at)
    MEM_B(-0X1D24, ctx->r1) = ctx->r3;
    // jal         0x800157E4
    // nop

    sub_800157E4(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $v1, 0xB0($gp)
    ctx->r3 = MEM_W(0XB0, ctx->r28);
    // nop

    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // sw          $v1, 0xB0($gp)
    MEM_W(0XB0, ctx->r28) = ctx->r3;
    // bgtz        $v1, L_8003619C
    if (SIGNED(ctx->r3) > 0) {
        // addiu       $v0, $v1, 0x7
        ctx->r2 = ADD32(ctx->r3, 0X7);
        goto L_8003619C;
    }
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
    // bgez        $v1, L_800361AC
    if (SIGNED(ctx->r3) >= 0) {
        // lui         $t1, 0x1062
        ctx->r9 = S32(0X1062 << 16);
        goto L_800361AC;
    }
    // lui         $t1, 0x1062
    ctx->r9 = S32(0X1062 << 16);
    // addiu       $v0, $v1, -0x7
    ctx->r2 = ADD32(ctx->r3, -0X7);
L_8003619C:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sw          $v0, 0xB0($gp)
    MEM_W(0XB0, ctx->r28) = ctx->r2;
    // lui         $t1, 0x1062
    ctx->r9 = S32(0X1062 << 16);
L_800361AC:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B28($a0)
    ctx->r4 = MEM_HU(-0X4B28, ctx->r4);
    // ori         $t1, $t1, 0x4DD3
    ctx->r9 = ctx->r9 | 0X4DD3;
    // multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $t3, 0x51EB
    ctx->r11 = S32(0X51EB << 16);
    // ori         $t3, $t3, 0x851F
    ctx->r11 = ctx->r11 | 0X851F;
    // mfhi        $v1
    ctx->r3 = hi;
    // srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // mult        $t7, $t3
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $t0, 0x6666
    ctx->r8 = S32(0X6666 << 16);
    // ori         $t0, $t0, 0x6667
    ctx->r8 = ctx->r8 | 0X6667;
    // sra         $a3, $t7, 31
    ctx->r7 = S32(ctx->r15) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10) >> 5;
    // subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // sll         $a2, $t2, 1
    ctx->r6 = S32(ctx->r10) << 1;
    // addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6) << 3;
    // addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) << 2;
    // subu        $a2, $t7, $a2
    ctx->r6 = SUB32(ctx->r15, ctx->r6);
    // mult        $a2, $t0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t4
    ctx->r12 = hi;
    // mult        $t7, $t0
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a0
    ctx->r4 = hi;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4B24($a1)
    ctx->r5 = MEM_HU(-0X4B24, ctx->r5);
    // nop

    // multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) >> 2;
    // subu        $a0, $a0, $a3
    ctx->r4 = SUB32(ctx->r4, ctx->r7);
    // sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4) << 2;
    // addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7) << 1;
    // subu        $a3, $t7, $a3
    ctx->r7 = SUB32(ctx->r15, ctx->r7);
    // mfhi        $v1
    ctx->r3 = hi;
    // srl         $v1, $v1, 6
    ctx->r3 = S32(U32(ctx->r3) >> 6);
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // mult        $t7, $t3
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t6, $t7, 31
    ctx->r14 = S32(ctx->r15) >> 31;
    // mfhi        $a1
    ctx->r5 = hi;
    // sra         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) >> 5;
    // subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5) << 1;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // subu        $a0, $t7, $a0
    ctx->r4 = SUB32(ctx->r15, ctx->r4);
    // mult        $a0, $t0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $t5, 0x68DB
    ctx->r13 = S32(0X68DB << 16);
    // ori         $t5, $t5, 0x8BAD
    ctx->r13 = ctx->r13 | 0X8BAD;
    // addiu       $t2, $t2, 0x3
    ctx->r10 = ADD32(ctx->r10, 0X3);
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // sra         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12) >> 2;
    // subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // addiu       $t4, $t4, 0x3
    ctx->r12 = ADD32(ctx->r12, 0X3);
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, -0x1D2E
    ctx->r9 = ADD32(ctx->r9, -0X1D2E);
    // addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // mfhi        $t3
    ctx->r11 = hi;
    // lw          $v1, 0xB0($gp)
    ctx->r3 = MEM_W(0XB0, ctx->r28);
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // mult        $t7, $t0
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) >> 6;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // lhu         $t0, 0x4F3C($t0)
    ctx->r8 = MEM_HU(0X4F3C, ctx->r8);
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B22($v1)
    ctx->r3 = MEM_HU(-0X4B22, ctx->r3);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $t0, -0x1D30($at)
    MEM_H(-0X1D30, ctx->r1) = ctx->r8;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $t5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11) >> 2;
    // subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B1E($v1)
    ctx->r3 = MEM_HU(-0X4B1E, ctx->r3);
    // addiu       $t3, $t3, 0x3
    ctx->r11 = ADD32(ctx->r11, 0X3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $t2, -0x1CD8($at)
    MEM_H(-0X1CD8, ctx->r1) = ctx->r10;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $t4, -0x1CB4($at)
    MEM_H(-0X1CB4, ctx->r1) = ctx->r12;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $a3, -0x1C90($at)
    MEM_H(-0X1C90, ctx->r1) = ctx->r7;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $a1, -0x1C6C($at)
    MEM_H(-0X1C6C, ctx->r1) = ctx->r5;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // mfhi        $a1
    ctx->r5 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $t5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $t3, -0x1C48($at)
    MEM_H(-0X1C48, ctx->r1) = ctx->r11;
    // sra         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8) >> 2;
    // subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, -0x1C24($at)
    MEM_H(-0X1C24, ctx->r1) = ctx->r2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $a1, -0x1BFC($at)
    MEM_H(-0X1BFC, ctx->r1) = ctx->r5;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, -0x1BD8($at)
    MEM_H(-0X1BD8, ctx->r1) = ctx->r2;
    // jal         0x80033AE8
    // nop

    UpdateCamera(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x80035C30
    // nop

    UpdateStatusEffects(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x80033A1C
    // nop

    KF_RenderTilemap(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x80034F14
    // nop

    sub_80034F14(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x80033DB4
    // nop

    sub_80033DB4(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x80033E44
    // nop

    sub_80033E44(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // jal         0x80033ED4
    // nop

    sub_80033ED4(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x80033FBC
    // nop

    sub_80033FBC(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // jal         0x8002FF0C
    // nop

    KF_RenderEnd(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80017CC8
    // nop

    sub_80017CC8(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // jal         0x800371F4
    // nop

    sub_800371F4(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop
 //   printf("UpdatePlayerSystem  end\n");
    return;
    // nop

;}
