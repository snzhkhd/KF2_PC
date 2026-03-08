#include "recomp.h"
#include "disable_warnings.h"

void sub_8002F1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lh          $a0, 0x4F3C($a0)
    ctx->r4 = MEM_H(0X4F3C, ctx->r4);
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // jal         0x800602D0
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    FixedCos(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    after_0:
    // ori         $v1, $zero, 0x1000
    ctx->r3 = 0 | 0X1000;
    // subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0xD5C
    ctx->r4 = ADD32(ctx->r4, -0XD5C);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8002F21C:
    // lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(0X2, ctx->r4);
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(0X0, ctx->r4);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // bne         $a1, $t0, L_8002F21C
    if (ctx->r5 != ctx->r8) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8002F21C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // addiu       $s0, $s0, 0x4F3E
    ctx->r16 = ADD32(ctx->r16, 0X4F3E);
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(0X0, ctx->r16);
    // jal         0x800601F4
    // nop

    FixedSin(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(0X0, ctx->r16);
    // jal         0x800602D0
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    FixedCos(rdram, ctx);
    goto after_2;
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    after_2:
    // jal         0x8002EAFC
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    sub_8002EAFC(rdram, ctx);
    goto after_3;
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    after_3:
    // lh          $v1, 0x18($sp)
    ctx->r3 = MEM_H(0X18, ctx->r29);
    // nop

    // mult        $s5, $v1
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // addiu       $s1, $s1, -0x7544
    ctx->r17 = ADD32(ctx->r17, -0X7544);
    // addiu       $s0, $s0, 0x22
    ctx->r16 = ADD32(ctx->r16, 0X22);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x4F2C($a0)
    ctx->r4 = MEM_W(0X4F2C, ctx->r4);
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lw          $a1, 0x4F30($a1)
    ctx->r5 = MEM_W(0X4F30, ctx->r5);
    // lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // lw          $a2, 0x4F34($a2)
    ctx->r6 = MEM_W(0X4F34, ctx->r6);
    // sll         $s6, $a0, 1
    ctx->r22 = S32(ctx->r4) << 1;
    // mflo        $a3
    ctx->r7 = lo;
    // sra         $a3, $a3, 20
    ctx->r7 = S32(ctx->r7) >> 20;
    // addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x4F44($v0)
    ctx->r2 = MEM_W(0X4F44, ctx->r2);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4F48($v1)
    ctx->r3 = MEM_W(0X4F48, ctx->r3);
    // andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v0, 0x4F4C($at)
    MEM_W(0X4F4C, ctx->r1) = ctx->r2;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $a3, -0x753C($at)
    MEM_W(-0X753C, ctx->r1) = ctx->r7;
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v1, -0x7540($at)
    MEM_W(-0X7540, ctx->r1) = ctx->r3;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v0, 0x4F54($at)
    MEM_W(0X4F54, ctx->r1) = ctx->r2;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v1, 0x4F50($at)
    MEM_W(0X4F50, ctx->r1) = ctx->r3;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $v1, 0x4F58($at)
    MEM_W(0X4F58, ctx->r1) = ctx->r3;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $s4, $v1, $a3
    ctx->r20 = ADD32(ctx->r3, ctx->r7);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x7538($at)
    MEM_W(-0X7538, ctx->r1) = ctx->r2;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $s4, -0x7534($at)
    MEM_W(-0X7534, ctx->r1) = ctx->r20;
    // jal         0x8002D4A4
    // sll         $s7, $a2, 1
    ctx->r23 = S32(ctx->r6) << 1;
    ResolveCurrentMetaTile(rdram, ctx);
    goto after_4;
    // sll         $s7, $a2, 1
    ctx->r23 = S32(ctx->r6) << 1;
    after_4:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A82($v1)
    ctx->r3 = MEM_HU(-0X2A82, ctx->r3);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v1, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = ctx->r3;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x754C($at)
    MEM_W(-0X754C, ctx->r1) = ctx->r2;
    // bne         $v1, $zero, L_8002F384
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8002F384;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, -0x4($s1)
    MEM_B(-0X4, ctx->r17) = ctx->r2;
    // j           L_8002F390
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    goto L_8002F390;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8002F384:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, -0x4($s1)
    MEM_B(-0X4, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8002F390:
    // sb          $v0, -0x3($s1)
    MEM_B(-0X3, ctx->r17) = ctx->r2;
    // lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(0X1A, ctx->r29);
    // nop

    // mult        $v1, $s3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(0X1E, ctx->r29);
    // nop

    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t6
    ctx->r14 = lo;
    // mult        $v1, $s5
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // lh          $v0, 0x1C($sp)
    ctx->r2 = MEM_H(0X1C, ctx->r29);
    // nop

    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $a0, 0x20($sp)
    ctx->r4 = MEM_H(0X20, ctx->r29);
    // nop

    // mult        $a0, $s3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // lh          $v0, 0x24($sp)
    ctx->r2 = MEM_H(0X24, ctx->r29);
    // nop

    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $s0
    ctx->r16 = lo;
    // mult        $a0, $s5
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // addiu       $fp, $fp, -0x7548
    ctx->r30 = ADD32(ctx->r30, -0X7548);
    // lbu         $a2, 0x0($fp)
    ctx->r6 = MEM_BU(0X0, ctx->r30);
    // lh          $t4, 0x22($sp)
    ctx->r12 = MEM_H(0X22, ctx->r29);
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    // subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // sra         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8) >> 8;
    // addu        $t0, $t0, $s6
    ctx->r8 = ADD32(ctx->r8, ctx->r22);
    // mflo        $t5
    ctx->r13 = lo;
    // sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // mult        $t4, $s3
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) >> 8;
    // addu        $a3, $a3, $s7
    ctx->r7 = ADD32(ctx->r7, ctx->r23);
    // sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // subu        $v1, $v1, $t6
    ctx->r3 = SUB32(ctx->r3, ctx->r14);
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // sra         $t1, $t1, 8
    ctx->r9 = S32(ctx->r9) >> 8;
    // addu        $t1, $t1, $s7
    ctx->r9 = ADD32(ctx->r9, ctx->r23);
    // sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // mult        $t4, $s5
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t3, $t3, 8
    ctx->r11 = S32(ctx->r11) >> 8;
    // addu        $t3, $t3, $s6
    ctx->r11 = ADD32(ctx->r11, ctx->r22);
    // sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // sra         $t2, $t2, 8
    ctx->r10 = S32(ctx->r10) >> 8;
    // addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // jal         0x8002EB24
    // sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    sub_8002EB24(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_5:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // lbu         $a2, 0x0($fp)
    ctx->r6 = MEM_BU(0X0, ctx->r30);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x8002EB24
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    sub_8002EB24(rdram, ctx);
    goto after_6;
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    after_6:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // lbu         $a2, 0x0($fp)
    ctx->r6 = MEM_BU(0X0, ctx->r30);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x8002EB24
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    sub_8002EB24(rdram, ctx);
    goto after_7;
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    after_7:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lbu         $a2, 0x0($fp)
    ctx->r6 = MEM_BU(0X0, ctx->r30);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8002EB24
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    sub_8002EB24(rdram, ctx);
    goto after_8;
    // ori         $a2, $a2, 0x20
    ctx->r6 = ctx->r6 | 0X20;
    after_8:
    // lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(0X0, ctx->r30);
    // jal         0x8002ED24
    // ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    sub_8002ED24(rdram, ctx);
    goto after_9;
    // ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    after_9:
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x7540($v1)
    ctx->r3 = MEM_W(-0X7540, ctx->r3);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x7544($a0)
    ctx->r4 = MEM_W(-0X7544, ctx->r4);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x7550($a0)
    ctx->r4 = MEM_W(-0X7550, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // addiu       $at, $at, -0x4288
    ctx->r1 = ADD32(ctx->r1, -0X4288);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8002F584
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8002F584;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x7534($v1)
    ctx->r3 = MEM_W(-0X7534, ctx->r3);
    // j           L_8002F598
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    goto L_8002F598;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8002F584:
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x7534($v1)
    ctx->r3 = MEM_W(-0X7534, ctx->r3);
    // lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(0X0, ctx->r30);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8002F598:
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, -0x7540
    ctx->r16 = ADD32(ctx->r16, -0X7540);
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // addiu       $s5, $zero, -0x18
    ctx->r21 = ADD32(0, -0X18);
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // ori         $s2, $zero, 0x18
    ctx->r18 = 0 | 0X18;
    // addiu       $a0, $zero, -0x18
    ctx->r4 = ADD32(0, -0X18);
L_8002F5B8:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8002EDE4
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    sub_8002EDE4(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_10:
    // addiu       $a0, $zero, -0x18
    ctx->r4 = ADD32(0, -0X18);
    // addiu       $a1, $zero, -0x17
    ctx->r5 = ADD32(0, -0X17);
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(0X8, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // jal         0x8002EF78
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    sub_8002EF78(rdram, ctx);
    goto after_11;
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    after_11:
    // jal         0x8002EDE4
    // addiu       $a0, $zero, -0x17
    ctx->r4 = ADD32(0, -0X17);
    sub_8002EDE4(rdram, ctx);
    goto after_12;
    // addiu       $a0, $zero, -0x17
    ctx->r4 = ADD32(0, -0X17);
    after_12:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // addiu       $a1, $zero, -0x17
    ctx->r5 = ADD32(0, -0X17);
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $v1, $v1, -0x18
    ctx->r3 = ADD32(ctx->r3, -0X18);
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // jal         0x8002EF78
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    sub_8002EF78(rdram, ctx);
    goto after_13;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_13:
    // jal         0x8002EDE4
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_8002EDE4(rdram, ctx);
    goto after_14;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_14:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // ori         $a1, $zero, 0x19
    ctx->r5 = 0 | 0X19;
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $v1, $v1, -0x18
    ctx->r3 = ADD32(ctx->r3, -0X18);
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // jal         0x8002EF78
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    sub_8002EF78(rdram, ctx);
    goto after_15;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_15:
    // jal         0x8002EDE4
    // ori         $a0, $zero, 0x19
    ctx->r4 = 0 | 0X19;
    sub_8002EDE4(rdram, ctx);
    goto after_16;
    // ori         $a0, $zero, 0x19
    ctx->r4 = 0 | 0X19;
    after_16:
    // ori         $a0, $zero, 0x18
    ctx->r4 = 0 | 0X18;
    // ori         $a1, $zero, 0x19
    ctx->r5 = 0 | 0X19;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(0X8, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // jal         0x8002EF78
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    sub_8002EF78(rdram, ctx);
    goto after_17;
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    after_17:
    // jal         0x8002EDE4
    // ori         $a0, $zero, 0x18
    ctx->r4 = 0 | 0X18;
    sub_8002EDE4(rdram, ctx);
    goto after_18;
    // ori         $a0, $zero, 0x18
    ctx->r4 = 0 | 0X18;
    after_18:
    // ori         $a0, $zero, 0x18
    ctx->r4 = 0 | 0X18;
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(0X8, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // jal         0x8002EF78
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    sub_8002EF78(rdram, ctx);
    goto after_19;
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    after_19:
    // jal         0x8002EDE4
    // ori         $a0, $zero, 0x17
    ctx->r4 = 0 | 0X17;
    sub_8002EDE4(rdram, ctx);
    goto after_20;
    // ori         $a0, $zero, 0x17
    ctx->r4 = 0 | 0X17;
    after_20:
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8002EF78
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    sub_8002EF78(rdram, ctx);
    goto after_21;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_21:
    // jal         0x8002EDE4
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    sub_8002EDE4(rdram, ctx);
    goto after_22;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_22:
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // addiu       $a1, $zero, -0x19
    ctx->r5 = ADD32(0, -0X19);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8002EF78
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    sub_8002EF78(rdram, ctx);
    goto after_23;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_23:
    // jal         0x8002EDE4
    // addiu       $a0, $zero, -0x19
    ctx->r4 = ADD32(0, -0X19);
    sub_8002EDE4(rdram, ctx);
    goto after_24;
    // addiu       $a0, $zero, -0x19
    ctx->r4 = ADD32(0, -0X19);
    after_24:
    // addiu       $a0, $zero, -0x18
    ctx->r4 = ADD32(0, -0X18);
    // addiu       $a1, $zero, -0x19
    ctx->r5 = ADD32(0, -0X19);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(0X8, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // jal         0x8002EF78
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    sub_8002EF78(rdram, ctx);
    goto after_25;
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    after_25:
    // slti        $v0, $s1, 0xE
    ctx->r2 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8002F5B8
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, -0x18
        ctx->r4 = ADD32(0, -0X18);
        goto L_8002F5B8;
    }
    // addiu       $a0, $zero, -0x18
    ctx->r4 = ADD32(0, -0X18);
    // lbu         $v0, -0x19($s4)
    ctx->r2 = MEM_BU(-0X19, ctx->r20);
    // lbu         $v1, -0x17($s4)
    ctx->r3 = MEM_BU(-0X17, ctx->r20);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, -0x19($s4)
    MEM_B(-0X19, ctx->r20) = ctx->r2;
    // lbu         $v0, -0x18($s4)
    ctx->r2 = MEM_BU(-0X18, ctx->r20);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sb          $v1, -0x17($s4)
    MEM_B(-0X17, ctx->r20) = ctx->r3;
    // lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(0X0, ctx->r20);
    // ori         $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 | 0XC0;
    // sb          $v0, -0x18($s4)
    MEM_B(-0X18, ctx->r20) = ctx->r2;
    // lbu         $v0, -0x1($s4)
    ctx->r2 = MEM_BU(-0X1, ctx->r20);
    // ori         $v1, $v1, 0xC0
    ctx->r3 = ctx->r3 | 0XC0;
    // sb          $v1, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r3;
    // lbu         $v1, 0x17($s4)
    ctx->r3 = MEM_BU(0X17, ctx->r20);
    // ori         $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 | 0XC0;
    // sb          $v0, -0x1($s4)
    MEM_B(-0X1, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x1($s4)
    ctx->r2 = MEM_BU(0X1, ctx->r20);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sb          $v1, 0x17($s4)
    MEM_B(0X17, ctx->r20) = ctx->r3;
    // lbu         $v1, 0x19($s4)
    ctx->r3 = MEM_BU(0X19, ctx->r20);
    // ori         $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 | 0XC0;
    // sb          $v0, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x18($s4)
    ctx->r2 = MEM_BU(0X18, ctx->r20);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sb          $v1, 0x19($s4)
    MEM_B(0X19, ctx->r20) = ctx->r3;
    // ori         $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 | 0XC0;
    // sb          $v0, 0x18($s4)
    MEM_B(0X18, ctx->r20) = ctx->r2;
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
