#include "recomp.h"
#include "disable_warnings.h"

void sub_800320BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x4ACC($v0)
    ctx->r2 = MEM_W(0X4ACC, ctx->r2);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4AD0($v1)
    ctx->r3 = MEM_W(0X4AD0, ctx->r3);
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(0X58, ctx->r29);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(0X18, ctx->r2);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x4AD4($v0)
    ctx->r2 = MEM_W(0X4AD4, ctx->r2);
    // lw          $a1, 0x18($v1)
    ctx->r5 = MEM_W(0X18, ctx->r3);
    // lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(0X18, ctx->r2);
    // lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(0X5C, ctx->r29);
    // jal         0x8005F524
    // addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    AverageSZ3(rdram, ctx);
    goto after_0;
    // addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    after_0:
    // blez        $v0, L_800322C8
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800322C8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x636C
    ctx->r5 = ADD32(ctx->r5, 0X636C);
    // jal         0x8005F474
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    KF_NormalColorCol(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
    // lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // addiu       $s2, $s2, 0x4ACC
    ctx->r18 = ADD32(ctx->r18, 0X4ACC);
    // lw          $s4, 0x0($s2)
    ctx->r20 = MEM_W(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // ori         $s5, $s1, 0x34
    ctx->r21 = ctx->r17 | 0X34;
    // lw          $a1, 0x14($s4)
    ctx->r5 = MEM_W(0X14, ctx->r20);
    // addiu       $s3, $s3, -0x2
    ctx->r19 = ADD32(ctx->r19, -0X2);
    // jal         0x8005F394
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    KF_DpqColor(rdram, ctx);
    goto after_2;
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    after_2:
    // lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(0X14, ctx->r17);
    // addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    // jal         0x8005F394
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    KF_DpqColor(rdram, ctx);
    goto after_3;
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    after_3:
    // j           L_800322C0
    // addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    goto L_800322C0;
    // addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
L_80032190:
    // lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(0X14, ctx->r16);
    // addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    // jal         0x8005F394
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    KF_DpqColor(rdram, ctx);
    goto after_4;
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    after_4:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $a2, 0x28
    ctx->r2 = ADD32(ctx->r6, 0X28);
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
    // bne         $v0, $zero, L_800322C8
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
        goto L_800322C8;
    }
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // sh          $fp, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r30;
    // sh          $s7, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r23;
    // lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(0X18, ctx->r20);
    // nop

    // sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(0X18, ctx->r17);
    // nop

    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // nop

    // sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x20($s4)
    ctx->r2 = MEM_HU(0X20, ctx->r20);
    // nop

    // sh          $v0, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(0X20, ctx->r17);
    // nop

    // sh          $v0, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // nop

    // sh          $v0, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r2;
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // lui         $a1, 0x2AAA
    ctx->r5 = S32(0X2AAA << 16);
    // sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(0X1C, ctx->r17);
    // ori         $a1, $a1, 0xAAAB
    ctx->r5 = ctx->r5 | 0XAAAB;
    // sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(0X1C, ctx->r16);
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r2;
    // sb          $s5, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r21;
    // sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
    // lw          $v1, 0x10($s4)
    ctx->r3 = MEM_W(0X10, ctx->r20);
    // lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(0X10, ctx->r17);
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
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
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $a0, $v0, $s6
    ctx->r4 = ADD32(ctx->r2, ctx->r22);
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_800322A0
    if (ctx->r2 == 0) {
        // addu        $a1, $a2, $zero
        ctx->r5 = ADD32(ctx->r6, 0);
        goto L_800322A0;
    }
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
L_800322A0:
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x15C($v0)
    ctx->r2 = MEM_W(0X15C, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x80067238
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_5;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_5:
    // addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
L_800322C0:
    // bgtz        $v0, L_80032190
    if (SIGNED(ctx->r2) > 0) {
        // addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
        goto L_80032190;
    }
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_800322C8:
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
