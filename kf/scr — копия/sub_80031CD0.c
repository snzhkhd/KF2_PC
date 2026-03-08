#include "recomp.h"
#include "disable_warnings.h"

void sub_80031CD0(uint8_t* rdram, recomp_context* ctx) 
{
    // uint32_t base = *(uint32_t*)GET_PTR(0x80190250); // g_CurrentPrimitiveBuffer
    // printf("[BASE=%08X]\n", base);
    // for (int i = 0; i < 4; i++) {
        // uint32_t entry = base + 12 + 28 * i;
        // printf("[entry %d @ %08X] ", i, entry);
        // for (int j = 0; j < 7; j++)
            // printf("%08X ", *(uint32_t*)GET_PTR(entry + j * 4));
        // printf("\n");
    // }

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // jal         0x8002FFD4
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    sub_8002FFD4(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // addiu       $s2, $s2, 0x250
    ctx->r18 = ADD32(ctx->r18, 0X250);
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80030474
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_80030474(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // lw          $fp, 0x14($s0)
    ctx->r30 = MEM_W(0X14, ctx->r16);
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $fp, $zero
    ctx->r2 = ADD32(ctx->r30, 0);
    // beq         $v0, $zero, L_80032088
    if (ctx->r2 == 0) {
        // addiu       $fp, $fp, -0x1
        ctx->r30 = ADD32(ctx->r30, -0X1);
        goto L_80032088;
    }
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // addiu       $s6, $s2, 0x9F8
    ctx->r22 = ADD32(ctx->r18, 0X9F8);
L_80031D50:
    // lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(0X0, ctx->r17);
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // srl         $s7, $a3, 24
    ctx->r23 = S32(U32(ctx->r7) >> 24);
    // andi        $v1, $s7, 0xFD
    ctx->r3 = ctx->r23 & 0XFD;
    // beq         $v1, $v0, L_80031EF4
    if (ctx->r3 == ctx->r2) {
        // sw          $a3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r7;
        goto L_80031EF4;
    }
    // sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // bne         $v1, $v0, L_80032068
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80032068;
    }
    // nop

    // lhu         $v0, 0x12($s1)
    ctx->r2 = MEM_HU(0X12, ctx->r17);
    // lhu         $v1, 0x16($s1)
    ctx->r3 = MEM_HU(0X16, ctx->r17);
    // addu        $s4, $v0, $s6
    ctx->r20 = ADD32(ctx->r2, ctx->r22);
    // addu        $s3, $v1, $s6
    ctx->r19 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(0X0, ctx->r19);
    // addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
    // lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(0X0, ctx->r18);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // blez        $v0, L_80032068
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80032068;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lhu         $a0, 0x18($s1)
    ctx->r4 = MEM_HU(0X18, ctx->r17);
    // addiu       $v0, $s0, 0x34
    ctx->r2 = ADD32(ctx->r16, 0X34);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80032088
    if (ctx->r2 != 0) {
        // addu        $s5, $a0, $s6
        ctx->r21 = ADD32(ctx->r4, ctx->r22);
        goto L_80032088;
    }
    // addu        $s5, $a0, $s6
    ctx->r21 = ADD32(ctx->r4, ctx->r22);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // lhu         $a0, 0x10($s1)
    ctx->r4 = MEM_HU(0X10, ctx->r17);
    // lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(0X20, ctx->r29);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x8005F474
    // addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    KF_NormalColorCol(rdram, ctx);
    goto after_3;
    // addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    after_3:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s4)
    ctx->r5 = MEM_H(0X6, ctx->r20);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    KF_DpqColor(rdram, ctx);
    goto after_4;
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_4:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s2)
    ctx->r5 = MEM_H(0X6, ctx->r18);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    KF_DpqColor(rdram, ctx);
    goto after_5;
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_5:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(0X6, ctx->r19);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    KF_DpqColor(rdram, ctx);
    goto after_6;
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_6:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s5)
    ctx->r5 = MEM_H(0X6, ctx->r21);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    KF_DpqColor(rdram, ctx);
    goto after_7;
    // addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_7:
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $s7, 0x3C
    ctx->r2 = ctx->r23 | 0X3C;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_H(0X4, ctx->r20);
    // lh          $v1, 0x4($s2)
    ctx->r3 = MEM_H(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_H(0X4, ctx->r19);
    // lh          $a0, 0x4($s5)
    ctx->r4 = MEM_H(0X4, ctx->r21);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_80032048
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    goto L_80032048;
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
L_80031EF4:
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(0X12, ctx->r17);
    // addu        $s4, $v0, $s6
    ctx->r20 = ADD32(ctx->r2, ctx->r22);
    // addu        $s3, $v1, $s6
    ctx->r19 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(0X0, ctx->r19);
    // addu        $s2, $v0, $s6
    ctx->r18 = ADD32(ctx->r2, ctx->r22);
    // lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(0X0, ctx->r18);
    // jal         0x8005F524
    // nop

    AverageSZ3(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // blez        $v0, L_80032068
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80032068;
    }
    // nop

    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80032088
    if (ctx->r2 != 0) {
        // addiu       $a2, $sp, 0x10
        ctx->r6 = ADD32(ctx->r29, 0X10);
        goto L_80032088;
    }
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(0XC, ctx->r17);
    // lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(0X20, ctx->r29);
    // jal         0x8005F474
    // addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    KF_NormalColorCol(rdram, ctx);
    goto after_9;
    // addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    after_9:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s4)
    ctx->r5 = MEM_H(0X6, ctx->r20);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    KF_DpqColor(rdram, ctx);
    goto after_10;
    // addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_10:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s2)
    ctx->r5 = MEM_H(0X6, ctx->r18);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    KF_DpqColor(rdram, ctx);
    goto after_11;
    // addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_11:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(0X6, ctx->r19);
    // jal         0x8005F394
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    KF_DpqColor(rdram, ctx);
    goto after_12;
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_12:
    // lui         $a1, 0x5555
    ctx->r5 = S32(0X5555 << 16);
    // ori         $a1, $a1, 0x5556
    ctx->r5 = ctx->r5 | 0X5556;
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $s7, 0x34
    ctx->r2 = ctx->r23 | 0X34;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lh          $v1, 0x4($s4)
    ctx->r3 = MEM_H(0X4, ctx->r20);
    // lh          $v0, 0x4($s2)
    ctx->r2 = MEM_H(0X4, ctx->r18);
    // lh          $a0, 0x4($s3)
    ctx->r4 = MEM_H(0X4, ctx->r19);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80032048:
    // addiu       $a0, $v0, 0xF0
    ctx->r4 = ADD32(ctx->r2, 0XF0);
    // sltiu       $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 < 0X2000 ? 1 : 0;
    // beq         $v0, $zero, L_80032068
    if (ctx->r2 == 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80032068;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lw          $v0, -0xAEC($s6)
    ctx->r2 = MEM_W(-0XAEC, ctx->r22);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x80067238
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_13;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_13:
L_80032068:
    // lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(0X18, ctx->r29);
    // nop

    // srl         $v0, $a3, 6
    ctx->r2 = S32(U32(ctx->r7) >> 6);
    // andi        $v0, $v0, 0x3FC
    ctx->r2 = ctx->r2 & 0X3FC;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // addu        $v0, $fp, $zero
    ctx->r2 = ADD32(ctx->r30, 0);
    // bne         $v0, $zero, L_80031D50
    if (ctx->r2 != 0) {
        // addiu       $fp, $fp, -0x1
        ctx->r30 = ADD32(ctx->r30, -0X1);
        goto L_80031D50;
    }
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
L_80032088:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
