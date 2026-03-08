#include "recomp.h"
#include "disable_warnings.h"

void sub_80032A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x4E0
    ctx->r29 = ADD32(ctx->r29, -0X4E0);
    // sw          $s7, 0x4D4($sp)
    MEM_W(0X4D4, ctx->r29) = ctx->r23;
    // addiu       $s7, $a2, 0xC
    ctx->r23 = ADD32(ctx->r6, 0XC);
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // sw          $ra, 0x4DC($sp)
    MEM_W(0X4DC, ctx->r29) = ctx->r31;
    // sw          $fp, 0x4D8($sp)
    MEM_W(0X4D8, ctx->r29) = ctx->r30;
    // sw          $s6, 0x4D0($sp)
    MEM_W(0X4D0, ctx->r29) = ctx->r22;
    // sw          $s5, 0x4CC($sp)
    MEM_W(0X4CC, ctx->r29) = ctx->r21;
    // sw          $s4, 0x4C8($sp)
    MEM_W(0X4C8, ctx->r29) = ctx->r20;
    // sw          $s3, 0x4C4($sp)
    MEM_W(0X4C4, ctx->r29) = ctx->r19;
    // sw          $s2, 0x4C0($sp)
    MEM_W(0X4C0, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4BC($sp)
    MEM_W(0X4BC, ctx->r29) = ctx->r17;
    // sw          $s0, 0x4B8($sp)
    MEM_W(0X4B8, ctx->r29) = ctx->r16;
    // sw          $zero, 0x450($sp)
    MEM_W(0X450, ctx->r29) = 0;
    // sw          $zero, 0x468($sp)
    MEM_W(0X468, ctx->r29) = 0;
    // sw          $s7, 0x460($sp)
    MEM_W(0X460, ctx->r29) = ctx->r23;
    // sw          $v0, 0x10($s7)
    MEM_W(0X10, ctx->r23) = ctx->r2;
    // sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5) << 3;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $a0, 0x448($sp)
    MEM_W(0X448, ctx->r29) = ctx->r4;
    // sw          $v0, 0x458($sp)
    MEM_W(0X458, ctx->r29) = ctx->r2;
    // lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(0X14, ctx->r2);
    // lw          $t3, 0x460($sp)
    ctx->r11 = MEM_W(0X460, ctx->r29);
    // addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r2;
    // lw          $t2, 0x458($sp)
    ctx->r10 = MEM_W(0X458, ctx->r29);
    // addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    // lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(0X10, ctx->r10);
    // lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(0X14, ctx->r10);
    // addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $t3, $v0, L_800335E0
    if (ctx->r11 == ctx->r2) {
        // sw          $t3, 0x470($sp)
        MEM_W(0X470, ctx->r29) = ctx->r11;
        goto L_800335E0;
    }
    // sw          $t3, 0x470($sp)
    MEM_W(0X470, ctx->r29) = ctx->r11;
    // lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // sw          $t2, 0x488($sp)
    MEM_W(0X488, ctx->r29) = ctx->r10;
    // addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
L_80032AC0:
    // lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(0X0, ctx->r15);
    // nop

    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(0X0, ctx->r15);
    // nop

    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x443($sp)
    ctx->r3 = MEM_BU(0X443, ctx->r29);
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // beq         $v1, $v0, L_80032AF4
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80032AF4;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // ori         $v0, $zero, 0x2E
    ctx->r2 = 0 | 0X2E;
    // bne         $v1, $v0, L_80033104
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x24
        ctx->r2 = 0 | 0X24;
        goto L_80033104;
    }
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
L_80032AF4:
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // sw          $t4, 0x490($sp)
    MEM_W(0X490, ctx->r29) = ctx->r12;
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t6, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r14;
    // sw          $t7, 0x49C($sp)
    MEM_W(0X49C, ctx->r29) = ctx->r15;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // jal         0x80017684
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    MemcpyDword(rdram, ctx);
    goto after_0;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    after_0:
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // lw          $t3, 0x458($sp)
    ctx->r11 = MEM_W(0X458, ctx->r29);
    // lw          $t2, 0x448($sp)
    ctx->r10 = MEM_W(0X448, ctx->r29);
    // lw          $t6, 0x498($sp)
    ctx->r14 = MEM_W(0X498, ctx->r29);
    // lw          $v0, 0x14($t7)
    ctx->r2 = MEM_W(0X14, ctx->r15);
    // nop

    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(0X0, ctx->r11);
    // lh          $v1, 0x442($sp)
    ctx->r3 = MEM_H(0X442, ctx->r29);
    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // nop

    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x18($t7)
    ctx->r2 = MEM_W(0X18, ctx->r15);
    // nop

    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(0X0, ctx->r11);
    // lh          $v1, 0x440($sp)
    ctx->r3 = MEM_H(0X440, ctx->r29);
    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(0X0, ctx->r11);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addu        $v1, $t2, $v1
    ctx->r3 = ADD32(ctx->r10, ctx->r3);
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // lh          $a0, 0x442($sp)
    ctx->r4 = MEM_H(0X442, ctx->r29);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // lh          $a2, 0x18($sp)
    ctx->r6 = MEM_H(0X18, ctx->r29);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($t7)
    ctx->r2 = MEM_W(0X1C, ctx->r15);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(0X0, ctx->r11);
    // lh          $v1, 0x440($sp)
    ctx->r3 = MEM_H(0X440, ctx->r29);
    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x10($sp)
    ctx->r3 = MEM_H(0X10, ctx->r29);
    // lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(0X0, ctx->r2);
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(0X4, ctx->r2);
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
    // sh          $v1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r3;
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(0X12, ctx->r29);
    // lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(0X1A, ctx->r29);
    // lw          $t4, 0x490($sp)
    ctx->r12 = MEM_W(0X490, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x14($sp)
    ctx->r2 = MEM_H(0X14, ctx->r29);
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // lw          $t3, 0x488($sp)
    ctx->r11 = MEM_W(0X488, ctx->r29);
    // lh          $v1, 0x1C($sp)
    ctx->r3 = MEM_H(0X1C, ctx->r29);
    // and         $t8, $t8, $t3
    ctx->r24 = ctx->r24 & ctx->r11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // lh          $v0, 0x10($sp)
    ctx->r2 = MEM_H(0X10, ctx->r29);
    // lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(0X20, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(0X12, ctx->r29);
    // lh          $v1, 0x22($sp)
    ctx->r3 = MEM_H(0X22, ctx->r29);
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x14($sp)
    ctx->r2 = MEM_H(0X14, ctx->r29);
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // lh          $v1, 0x24($sp)
    ctx->r3 = MEM_H(0X24, ctx->r29);
    // and         $t9, $t9, $t3
    ctx->r25 = ctx->r25 & ctx->r11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // lh          $v0, 0x10($sp)
    ctx->r2 = MEM_H(0X10, ctx->r29);
    // lh          $v1, 0x28($sp)
    ctx->r3 = MEM_H(0X28, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(0X12, ctx->r29);
    // lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_H(0X2A, ctx->r29);
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x14($sp)
    ctx->r2 = MEM_H(0X14, ctx->r29);
    // lh          $v1, 0x2C($sp)
    ctx->r3 = MEM_H(0X2C, ctx->r29);
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // lh          $v0, 0x20($sp)
    ctx->r2 = MEM_H(0X20, ctx->r29);
    // lh          $v1, 0x28($sp)
    ctx->r3 = MEM_H(0X28, ctx->r29);
    // and         $t5, $t5, $t3
    ctx->r13 = ctx->r13 & ctx->r11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // lh          $v0, 0x22($sp)
    ctx->r2 = MEM_H(0X22, ctx->r29);
    // lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_H(0X2A, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x24($sp)
    ctx->r2 = MEM_H(0X24, ctx->r29);
    // lw          $t2, 0x478($sp)
    ctx->r10 = MEM_W(0X478, ctx->r29);
    // lh          $v1, 0x2C($sp)
    ctx->r3 = MEM_H(0X2C, ctx->r29);
    // and         $t2, $t2, $t3
    ctx->r10 = ctx->r10 & ctx->r11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $t2, 0x478($sp)
    MEM_W(0X478, ctx->r29) = ctx->r10;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // lh          $v0, 0x18($sp)
    ctx->r2 = MEM_H(0X18, ctx->r29);
    // lh          $v1, 0x28($sp)
    ctx->r3 = MEM_H(0X28, ctx->r29);
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(0X1A, ctx->r29);
    // lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_H(0X2A, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x1C($sp)
    ctx->r2 = MEM_H(0X1C, ctx->r29);
    // lw          $t2, 0x480($sp)
    ctx->r10 = MEM_W(0X480, ctx->r29);
    // lh          $v1, 0x2C($sp)
    ctx->r3 = MEM_H(0X2C, ctx->r29);
    // and         $t2, $t2, $t3
    ctx->r10 = ctx->r10 & ctx->r11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $t2, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r10;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // sw          $t4, 0x490($sp)
    MEM_W(0X490, ctx->r29) = ctx->r12;
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t6, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r14;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // jal         0x80017684
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    MemcpyDword(rdram, ctx);
    goto after_1;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    after_1:
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // addiu       $t2, $zero, -0x100
    ctx->r10 = ADD32(0, -0X100);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // lbu         $a0, 0x31($sp)
    ctx->r4 = MEM_BU(0X31, ctx->r29);
    // lbu         $t1, 0x35($sp)
    ctx->r9 = MEM_BU(0X35, ctx->r29);
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // lbu         $a3, 0x30($sp)
    ctx->r7 = MEM_BU(0X30, ctx->r29);
    // lbu         $t3, 0x34($sp)
    ctx->r11 = MEM_BU(0X34, ctx->r29);
    // lbu         $v1, 0x39($sp)
    ctx->r3 = MEM_BU(0X39, ctx->r29);
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // lbu         $t0, 0x38($sp)
    ctx->r8 = MEM_BU(0X38, ctx->r29);
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // or          $t8, $t8, $v0
    ctx->r24 = ctx->r24 | ctx->r2;
    // and         $t8, $t8, $t2
    ctx->r24 = ctx->r24 & ctx->r10;
    // addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // or          $t8, $t8, $v0
    ctx->r24 = ctx->r24 | ctx->r2;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // and         $t9, $t9, $t2
    ctx->r25 = ctx->r25 & ctx->r10;
    // addu        $v0, $a3, $t0
    ctx->r2 = ADD32(ctx->r7, ctx->r8);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // srl         $s0, $t8, 8
    ctx->r16 = S32(U32(ctx->r24) >> 8);
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // srl         $s1, $t9, 8
    ctx->r17 = S32(U32(ctx->r25) >> 8);
    // sw          $t3, 0x4B0($sp)
    MEM_W(0X4B0, ctx->r29) = ctx->r11;
    // lbu         $t3, 0x3D($sp)
    ctx->r11 = MEM_BU(0X3D, ctx->r29);
    // andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // or          $t5, $t5, $a0
    ctx->r13 = ctx->r13 | ctx->r4;
    // and         $t5, $t5, $t2
    ctx->r13 = ctx->r13 & ctx->r10;
    // addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // sw          $t3, 0x4A8($sp)
    MEM_W(0X4A8, ctx->r29) = ctx->r11;
    // addiu       $t3, $zero, -0x100
    ctx->r11 = ADD32(0, -0X100);
    // lbu         $a0, 0x3C($sp)
    ctx->r4 = MEM_BU(0X3C, ctx->r29);
    // lw          $t2, 0x478($sp)
    ctx->r10 = MEM_W(0X478, ctx->r29);
    // addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // or          $t5, $t5, $a3
    ctx->r13 = ctx->r13 | ctx->r7;
    // or          $t2, $t2, $v1
    ctx->r10 = ctx->r10 | ctx->r3;
    // and         $t2, $t2, $t3
    ctx->r10 = ctx->r10 & ctx->r11;
    // addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // srl         $t0, $t0, 1
    ctx->r8 = S32(U32(ctx->r8) >> 1);
    // or          $t2, $t2, $t0
    ctx->r10 = ctx->r10 | ctx->r8;
    // srl         $s6, $t5, 8
    ctx->r22 = S32(U32(ctx->r13) >> 8);
    // andi        $s6, $s6, 0xFF
    ctx->r22 = ctx->r22 & 0XFF;
    // sw          $t2, 0x478($sp)
    MEM_W(0X478, ctx->r29) = ctx->r10;
    // lw          $t2, 0x4A8($sp)
    ctx->r10 = MEM_W(0X4A8, ctx->r29);
    // lw          $t3, 0x458($sp)
    ctx->r11 = MEM_W(0X458, ctx->r29);
    // addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // srl         $t1, $t1, 1
    ctx->r9 = S32(U32(ctx->r9) >> 1);
    // lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(0X4, ctx->r11);
    // lw          $t2, 0x480($sp)
    ctx->r10 = MEM_W(0X480, ctx->r29);
    // lw          $t3, 0x450($sp)
    ctx->r11 = MEM_W(0X450, ctx->r29);
    // sll         $t1, $t1, 8
    ctx->r9 = S32(ctx->r9) << 8;
    // sb          $t8, 0x8($s7)
    MEM_B(0X8, ctx->r23) = ctx->r24;
    // sb          $s0, 0x9($s7)
    MEM_B(0X9, ctx->r23) = ctx->r16;
    // sb          $t9, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r25;
    // sb          $s1, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r17;
    // sb          $t5, 0x10($s7)
    MEM_B(0X10, ctx->r23) = ctx->r13;
    // sb          $s6, 0x11($s7)
    MEM_B(0X11, ctx->r23) = ctx->r22;
    // or          $t2, $t2, $t1
    ctx->r10 = ctx->r10 | ctx->r9;
    // addu        $fp, $t3, $v0
    ctx->r30 = ADD32(ctx->r11, ctx->r2);
    // sll         $s2, $fp, 3
    ctx->r18 = S32(ctx->r30) << 3;
    // addiu       $s3, $fp, 0x1
    ctx->r19 = ADD32(ctx->r30, 0X1);
    // sll         $s3, $s3, 3
    ctx->r19 = S32(ctx->r19) << 3;
    // addiu       $t3, $zero, -0x100
    ctx->r11 = ADD32(0, -0X100);
    // and         $t2, $t2, $t3
    ctx->r10 = ctx->r10 & ctx->r11;
    // addiu       $s4, $fp, 0x2
    ctx->r20 = ADD32(ctx->r30, 0X2);
    // sh          $s2, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r18;
    // sh          $s3, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r19;
    // lw          $v0, 0x440($sp)
    ctx->r2 = MEM_W(0X440, ctx->r29);
    // sll         $s4, $s4, 3
    ctx->r20 = S32(ctx->r20) << 3;
    // sw          $t2, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r10;
    // sw          $v0, 0x18($s7)
    MEM_W(0X18, ctx->r23) = ctx->r2;
    // sh          $s4, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r20;
    // lw          $t2, 0x4B0($sp)
    ctx->r10 = MEM_W(0X4B0, ctx->r29);
    // lw          $v0, 0x440($sp)
    ctx->r2 = MEM_W(0X440, ctx->r29);
    // addu        $a0, $t2, $a0
    ctx->r4 = ADD32(ctx->r10, ctx->r4);
    // lw          $t2, 0x480($sp)
    ctx->r10 = MEM_W(0X480, ctx->r29);
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // sw          $a0, 0x4B0($sp)
    MEM_W(0X4B0, ctx->r29) = ctx->r4;
    // srl         $t3, $a0, 1
    ctx->r11 = S32(U32(ctx->r4) >> 1);
    // or          $t2, $t2, $t3
    ctx->r10 = ctx->r10 | ctx->r11;
    // sw          $t2, 0x480($sp)
    MEM_W(0X480, ctx->r29) = ctx->r10;
    // sw          $v0, 0x1C($s7)
    MEM_W(0X1C, ctx->r23) = ctx->r2;
    // addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // jal         0x80017684
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    MemcpyDword(rdram, ctx);
    goto after_2;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    after_2:
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // sb          $s0, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r16;
    // sb          $t8, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r24;
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // sb          $s6, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r22;
    // sb          $t5, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r13;
    // lbu         $t3, 0x480($sp)
    ctx->r11 = MEM_BU(0X480, ctx->r29);
    // nop

    // sb          $t3, 0x10($s7)
    MEM_B(0X10, ctx->r23) = ctx->r11;
    // lw          $t2, 0x480($sp)
    ctx->r10 = MEM_W(0X480, ctx->r29);
    // nop

    // srl         $s5, $t2, 8
    ctx->r21 = S32(U32(ctx->r10) >> 8);
    // andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // sb          $s5, 0x11($s7)
    MEM_B(0X11, ctx->r23) = ctx->r21;
    // sh          $s2, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r18;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // nop

    // sb          $v0, 0x16($s7)
    MEM_B(0X16, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // nop

    // sb          $v0, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r2;
    // sh          $s4, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r20;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // addiu       $s2, $fp, 0x4
    ctx->r18 = ADD32(ctx->r30, 0X4);
    // sb          $v0, 0x1A($s7)
    MEM_B(0X1A, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // sll         $s2, $s2, 3
    ctx->r18 = S32(ctx->r18) << 3;
    // sb          $v0, 0x1B($s7)
    MEM_B(0X1B, ctx->r23) = ctx->r2;
    // sh          $s2, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r18;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // sb          $v0, 0x1C($s7)
    MEM_B(0X1C, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // sb          $v0, 0x1D($s7)
    MEM_B(0X1D, ctx->r23) = ctx->r2;
    // addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    // jal         0x80017684
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    MemcpyDword(rdram, ctx);
    goto after_3;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_3:
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // sb          $s1, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r17;
    // sb          $t9, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r25;
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // sb          $s6, 0x9($s7)
    MEM_B(0X9, ctx->r23) = ctx->r22;
    // sb          $t5, 0x8($s7)
    MEM_B(0X8, ctx->r23) = ctx->r13;
    // lbu         $t3, 0x478($sp)
    ctx->r11 = MEM_BU(0X478, ctx->r29);
    // nop

    // sb          $t3, 0x10($s7)
    MEM_B(0X10, ctx->r23) = ctx->r11;
    // lw          $t2, 0x478($sp)
    ctx->r10 = MEM_W(0X478, ctx->r29);
    // nop

    // srl         $s1, $t2, 8
    ctx->r17 = S32(U32(ctx->r10) >> 8);
    // andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // sb          $s1, 0x11($s7)
    MEM_B(0X11, ctx->r23) = ctx->r17;
    // sh          $s3, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r19;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // nop

    // sb          $v0, 0x16($s7)
    MEM_B(0X16, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // nop

    // sb          $v0, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r2;
    // sh          $s4, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r20;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // addiu       $s0, $fp, 0x3
    ctx->r16 = ADD32(ctx->r30, 0X3);
    // sb          $v0, 0x18($s7)
    MEM_B(0X18, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // sb          $v0, 0x19($s7)
    MEM_B(0X19, ctx->r23) = ctx->r2;
    // sh          $s0, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // sb          $v0, 0x1C($s7)
    MEM_B(0X1C, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // sb          $v0, 0x1D($s7)
    MEM_B(0X1D, ctx->r23) = ctx->r2;
    // addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    // jal         0x80017684
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    MemcpyDword(rdram, ctx);
    goto after_4;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_4:
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // sb          $s6, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r22;
    // sb          $t5, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r13;
    // lbu         $t3, 0x480($sp)
    ctx->r11 = MEM_BU(0X480, ctx->r29);
    // sb          $s5, 0x9($s7)
    MEM_B(0X9, ctx->r23) = ctx->r21;
    // sb          $t3, 0x8($s7)
    MEM_B(0X8, ctx->r23) = ctx->r11;
    // lbu         $t2, 0x478($sp)
    ctx->r10 = MEM_BU(0X478, ctx->r29);
    // sb          $s1, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r17;
    // sb          $t2, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r10;
    // sh          $s4, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r20;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // nop

    // sb          $v0, 0x16($s7)
    MEM_B(0X16, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // nop

    // sb          $v0, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r2;
    // sh          $s2, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r18;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // lw          $t3, 0x468($sp)
    ctx->r11 = MEM_W(0X468, ctx->r29);
    // sh          $s0, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r16;
    // addiu       $t3, $t3, 0x80
    ctx->r11 = ADD32(ctx->r11, 0X80);
    // sw          $t3, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r11;
    // sb          $v0, 0x18($s7)
    MEM_B(0X18, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // lw          $t6, 0x498($sp)
    ctx->r14 = MEM_W(0X498, ctx->r29);
    // sb          $v0, 0x19($s7)
    MEM_B(0X19, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // lw          $t4, 0x490($sp)
    ctx->r12 = MEM_W(0X490, ctx->r29);
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // sb          $v0, 0x1A($s7)
    MEM_B(0X1A, ctx->r23) = ctx->r2;
    // lw          $t2, 0x450($sp)
    ctx->r10 = MEM_W(0X450, ctx->r29);
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // sw          $t2, 0x450($sp)
    MEM_W(0X450, ctx->r29) = ctx->r10;
    // sb          $v0, 0x1B($s7)
    MEM_B(0X1B, ctx->r23) = ctx->r2;
    // lw          $t3, 0x460($sp)
    ctx->r11 = MEM_W(0X460, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // lw          $v0, 0x14($t3)
    ctx->r2 = MEM_W(0X14, ctx->r11);
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // sw          $v0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r2;
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // j           L_800335B4
    // addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    goto L_800335B4;
    // addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
L_80033104:
    // beq         $v1, $v0, L_80033118
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80033118;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // ori         $v0, $zero, 0x26
    ctx->r2 = 0 | 0X26;
    // bne         $v1, $v0, L_80033560
    if (ctx->r3 != ctx->r2) {
        // addu        $a1, $t7, $zero
        ctx->r5 = ADD32(ctx->r15, 0);
        goto L_80033560;
    }
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
L_80033118:
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // ori         $a2, $zero, 0x6
    ctx->r6 = 0 | 0X6;
    // sw          $t4, 0x490($sp)
    MEM_W(0X490, ctx->r29) = ctx->r12;
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t6, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r14;
    // sw          $t7, 0x49C($sp)
    MEM_W(0X49C, ctx->r29) = ctx->r15;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // jal         0x80017684
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    MemcpyDword(rdram, ctx);
    goto after_5;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    after_5:
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // lw          $t2, 0x458($sp)
    ctx->r10 = MEM_W(0X458, ctx->r29);
    // lw          $t3, 0x448($sp)
    ctx->r11 = MEM_W(0X448, ctx->r29);
    // lw          $t6, 0x498($sp)
    ctx->r14 = MEM_W(0X498, ctx->r29);
    // lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(0X10, ctx->r15);
    // nop

    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(0X0, ctx->r10);
    // lh          $v1, 0x442($sp)
    ctx->r3 = MEM_H(0X442, ctx->r29);
    // addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // nop

    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x14($t7)
    ctx->r2 = MEM_W(0X14, ctx->r15);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(0X0, ctx->r10);
    // lh          $v1, 0x440($sp)
    ctx->r3 = MEM_H(0X440, ctx->r29);
    // addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(0X0, ctx->r10);
    // lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(0X0, ctx->r2);
    // addu        $v1, $t3, $v1
    ctx->r3 = ADD32(ctx->r11, ctx->r3);
    // sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // lh          $a1, 0x442($sp)
    ctx->r5 = MEM_H(0X442, ctx->r29);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // lh          $a2, 0x18($sp)
    ctx->r6 = MEM_H(0X18, ctx->r29);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x10($sp)
    ctx->r2 = MEM_H(0X10, ctx->r29);
    // lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(0X0, ctx->r3);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(0X4, ctx->r3);
    // ori         $a2, $zero, 0x3
    ctx->r6 = 0 | 0X3;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(0X12, ctx->r29);
    // lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(0X1A, ctx->r29);
    // lw          $t4, 0x490($sp)
    ctx->r12 = MEM_W(0X490, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x14($sp)
    ctx->r2 = MEM_H(0X14, ctx->r29);
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // lw          $t2, 0x488($sp)
    ctx->r10 = MEM_W(0X488, ctx->r29);
    // lh          $v1, 0x1C($sp)
    ctx->r3 = MEM_H(0X1C, ctx->r29);
    // and         $t8, $t8, $t2
    ctx->r24 = ctx->r24 & ctx->r10;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // lh          $v0, 0x10($sp)
    ctx->r2 = MEM_H(0X10, ctx->r29);
    // lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(0X20, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(0X12, ctx->r29);
    // lh          $v1, 0x22($sp)
    ctx->r3 = MEM_H(0X22, ctx->r29);
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x14($sp)
    ctx->r2 = MEM_H(0X14, ctx->r29);
    // lh          $v1, 0x24($sp)
    ctx->r3 = MEM_H(0X24, ctx->r29);
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // lh          $v0, 0x18($sp)
    ctx->r2 = MEM_H(0X18, ctx->r29);
    // lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(0X20, ctx->r29);
    // and         $t9, $t9, $t2
    ctx->r25 = ctx->r25 & ctx->r10;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(0X1A, ctx->r29);
    // lh          $v1, 0x22($sp)
    ctx->r3 = MEM_H(0X22, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r2;
    // lh          $v0, 0x1C($sp)
    ctx->r2 = MEM_H(0X1C, ctx->r29);
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // lh          $v1, 0x24($sp)
    ctx->r3 = MEM_H(0X24, ctx->r29);
    // and         $t5, $t5, $t2
    ctx->r13 = ctx->r13 & ctx->r10;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // sw          $t4, 0x490($sp)
    MEM_W(0X490, ctx->r29) = ctx->r12;
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t6, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r14;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // jal         0x80017684
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    MemcpyDword(rdram, ctx);
    goto after_6;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    after_6:
    // ori         $a2, $zero, 0x6
    ctx->r6 = 0 | 0X6;
    // addiu       $t3, $zero, -0x100
    ctx->r11 = ADD32(0, -0X100);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // lbu         $v1, 0x31($sp)
    ctx->r3 = MEM_BU(0X31, ctx->r29);
    // lbu         $a3, 0x35($sp)
    ctx->r7 = MEM_BU(0X35, ctx->r29);
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // lbu         $a0, 0x30($sp)
    ctx->r4 = MEM_BU(0X30, ctx->r29);
    // lbu         $t0, 0x34($sp)
    ctx->r8 = MEM_BU(0X34, ctx->r29);
    // lbu         $t1, 0x39($sp)
    ctx->r9 = MEM_BU(0X39, ctx->r29);
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // lw          $t2, 0x458($sp)
    ctx->r10 = MEM_W(0X458, ctx->r29);
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // or          $t8, $t8, $v0
    ctx->r24 = ctx->r24 | ctx->r2;
    // and         $t8, $t8, $t3
    ctx->r24 = ctx->r24 & ctx->r11;
    // addu        $v0, $a0, $t0
    ctx->r2 = ADD32(ctx->r4, ctx->r8);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // or          $t8, $t8, $v0
    ctx->r24 = ctx->r24 | ctx->r2;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $t9, $t9, $v1
    ctx->r25 = ctx->r25 | ctx->r3;
    // and         $t9, $t9, $t3
    ctx->r25 = ctx->r25 & ctx->r11;
    // srl         $s2, $t8, 8
    ctx->r18 = S32(U32(ctx->r24) >> 8);
    // andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) << 8;
    // lbu         $v1, 0x38($sp)
    ctx->r3 = MEM_BU(0X38, ctx->r29);
    // lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(0X4, ctx->r10);
    // lw          $t3, 0x450($sp)
    ctx->r11 = MEM_W(0X450, ctx->r29);
    // addiu       $t2, $zero, -0x100
    ctx->r10 = ADD32(0, -0X100);
    // sb          $t8, 0x8($s7)
    MEM_B(0X8, ctx->r23) = ctx->r24;
    // sb          $s2, 0x9($s7)
    MEM_B(0X9, ctx->r23) = ctx->r18;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // or          $t9, $t9, $a0
    ctx->r25 = ctx->r25 | ctx->r4;
    // addu        $fp, $t3, $v0
    ctx->r30 = ADD32(ctx->r11, ctx->r2);
    // srl         $s3, $t9, 8
    ctx->r19 = S32(U32(ctx->r25) >> 8);
    // andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
    // sll         $s5, $fp, 3
    ctx->r21 = S32(ctx->r30) << 3;
    // addiu       $s4, $fp, 0x1
    ctx->r20 = ADD32(ctx->r30, 0X1);
    // sll         $s4, $s4, 3
    ctx->r20 = S32(ctx->r20) << 3;
    // addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // sb          $t9, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r25;
    // sb          $s3, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r19;
    // sh          $s5, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r21;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // srl         $t0, $t0, 1
    ctx->r8 = S32(U32(ctx->r8) >> 1);
    // sh          $s4, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r20;
    // sb          $v0, 0x14($s7)
    MEM_B(0X14, ctx->r23) = ctx->r2;
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // or          $t5, $t5, $a3
    ctx->r13 = ctx->r13 | ctx->r7;
    // sb          $v0, 0x15($s7)
    MEM_B(0X15, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // and         $t5, $t5, $t2
    ctx->r13 = ctx->r13 & ctx->r10;
    // sb          $v0, 0x16($s7)
    MEM_B(0X16, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // or          $t5, $t5, $t0
    ctx->r13 = ctx->r13 | ctx->r8;
    // sb          $v0, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r2;
    // addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // jal         0x80017684
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    MemcpyDword(rdram, ctx);
    goto after_7;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    after_7:
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // sb          $s2, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r18;
    // sb          $t8, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r24;
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // nop

    // srl         $s0, $t5, 8
    ctx->r16 = S32(U32(ctx->r13) >> 8);
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // sb          $t5, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r13;
    // sb          $s0, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r16;
    // sh          $s5, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r21;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // addiu       $s1, $fp, 0x2
    ctx->r17 = ADD32(ctx->r30, 0X2);
    // sb          $v0, 0x12($s7)
    MEM_B(0X12, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17) << 3;
    // sb          $v0, 0x13($s7)
    MEM_B(0X13, ctx->r23) = ctx->r2;
    // sh          $s1, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // ori         $a2, $zero, 0x6
    ctx->r6 = 0 | 0X6;
    // sb          $v0, 0x16($s7)
    MEM_B(0X16, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // sb          $v0, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r2;
    // addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    // jal         0x80017684
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    MemcpyDword(rdram, ctx);
    goto after_8;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_8:
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // sb          $s3, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r19;
    // sb          $t9, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r25;
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // sb          $s0, 0x9($s7)
    MEM_B(0X9, ctx->r23) = ctx->r16;
    // sb          $t5, 0x8($s7)
    MEM_B(0X8, ctx->r23) = ctx->r13;
    // sh          $s4, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r20;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // nop

    // sb          $v0, 0x12($s7)
    MEM_B(0X12, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // nop

    // sb          $v0, 0x13($s7)
    MEM_B(0X13, ctx->r23) = ctx->r2;
    // sh          $s1, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // ori         $a2, $zero, 0x6
    ctx->r6 = 0 | 0X6;
    // sb          $v0, 0x14($s7)
    MEM_B(0X14, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // addu        $a1, $t7, $zero
    ctx->r5 = ADD32(ctx->r15, 0);
    // sb          $v0, 0x15($s7)
    MEM_B(0X15, ctx->r23) = ctx->r2;
    // addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    // jal         0x80017684
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    MemcpyDword(rdram, ctx);
    goto after_9;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_9:
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // sb          $s2, 0x5($s7)
    MEM_B(0X5, ctx->r23) = ctx->r18;
    // sb          $t8, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r24;
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // sb          $s0, 0x9($s7)
    MEM_B(0X9, ctx->r23) = ctx->r16;
    // sb          $t5, 0x8($s7)
    MEM_B(0X8, ctx->r23) = ctx->r13;
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // sb          $s3, 0xD($s7)
    MEM_B(0XD, ctx->r23) = ctx->r19;
    // sb          $t9, 0xC($s7)
    MEM_B(0XC, ctx->r23) = ctx->r25;
    // sh          $s5, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r21;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // nop

    // sb          $v0, 0x12($s7)
    MEM_B(0X12, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // nop

    // sb          $v0, 0x13($s7)
    MEM_B(0X13, ctx->r23) = ctx->r2;
    // sh          $s1, 0x440($sp)
    MEM_H(0X440, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x440($sp)
    ctx->r2 = MEM_BU(0X440, ctx->r29);
    // lw          $t3, 0x468($sp)
    ctx->r11 = MEM_W(0X468, ctx->r29);
    // sh          $s4, 0x442($sp)
    MEM_H(0X442, ctx->r29) = ctx->r20;
    // addiu       $t3, $t3, 0x60
    ctx->r11 = ADD32(ctx->r11, 0X60);
    // sw          $t3, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r11;
    // sb          $v0, 0x14($s7)
    MEM_B(0X14, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // lw          $t6, 0x498($sp)
    ctx->r14 = MEM_W(0X498, ctx->r29);
    // sb          $v0, 0x15($s7)
    MEM_B(0X15, ctx->r23) = ctx->r2;
    // lbu         $v0, 0x442($sp)
    ctx->r2 = MEM_BU(0X442, ctx->r29);
    // lw          $t4, 0x490($sp)
    ctx->r12 = MEM_W(0X490, ctx->r29);
    // addiu       $t6, $t6, 0x8
    ctx->r14 = ADD32(ctx->r14, 0X8);
    // sb          $v0, 0x16($s7)
    MEM_B(0X16, ctx->r23) = ctx->r2;
    // lw          $t2, 0x450($sp)
    ctx->r10 = MEM_W(0X450, ctx->r29);
    // lbu         $v0, 0x443($sp)
    ctx->r2 = MEM_BU(0X443, ctx->r29);
    // addiu       $t2, $t2, 0x3
    ctx->r10 = ADD32(ctx->r10, 0X3);
    // sw          $t2, 0x450($sp)
    MEM_W(0X450, ctx->r29) = ctx->r10;
    // sb          $v0, 0x17($s7)
    MEM_B(0X17, ctx->r23) = ctx->r2;
    // lw          $t3, 0x460($sp)
    ctx->r11 = MEM_W(0X460, ctx->r29);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // lw          $v0, 0x14($t3)
    ctx->r2 = MEM_W(0X14, ctx->r11);
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // sw          $v0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r2;
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // j           L_800335B4
    // addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
    goto L_800335B4;
    // addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
L_80033560:
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // sw          $t4, 0x490($sp)
    MEM_W(0X490, ctx->r29) = ctx->r12;
    // sw          $t5, 0x494($sp)
    MEM_W(0X494, ctx->r29) = ctx->r13;
    // sw          $t6, 0x498($sp)
    MEM_W(0X498, ctx->r29) = ctx->r14;
    // sw          $t7, 0x49C($sp)
    MEM_W(0X49C, ctx->r29) = ctx->r15;
    // sw          $t8, 0x4A0($sp)
    MEM_W(0X4A0, ctx->r29) = ctx->r24;
    // sw          $t9, 0x4A4($sp)
    MEM_W(0X4A4, ctx->r29) = ctx->r25;
    // addiu       $fp, $v0, 0x1
    ctx->r30 = ADD32(ctx->r2, 0X1);
    // jal         0x80017684
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    MemcpyDword(rdram, ctx);
    goto after_10;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_10:
    // sll         $fp, $fp, 2
    ctx->r30 = S32(ctx->r30) << 2;
    // lw          $t2, 0x468($sp)
    ctx->r10 = MEM_W(0X468, ctx->r29);
    // addu        $s7, $s7, $fp
    ctx->r23 = ADD32(ctx->r23, ctx->r30);
    // addu        $t2, $t2, $fp
    ctx->r10 = ADD32(ctx->r10, ctx->r30);
    // sw          $t2, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r10;
    // lw          $t9, 0x4A4($sp)
    ctx->r25 = MEM_W(0X4A4, ctx->r29);
    // lw          $t8, 0x4A0($sp)
    ctx->r24 = MEM_W(0X4A0, ctx->r29);
    // lw          $t7, 0x49C($sp)
    ctx->r15 = MEM_W(0X49C, ctx->r29);
    // lw          $t6, 0x498($sp)
    ctx->r14 = MEM_W(0X498, ctx->r29);
    // lw          $t5, 0x494($sp)
    ctx->r13 = MEM_W(0X494, ctx->r29);
    // lw          $t4, 0x490($sp)
    ctx->r12 = MEM_W(0X490, ctx->r29);
L_800335B4:
    // lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(0X0, ctx->r15);
    // lw          $t3, 0x470($sp)
    ctx->r11 = MEM_W(0X470, ctx->r29);
    // sw          $v0, 0x440($sp)
    MEM_W(0X440, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x441($sp)
    ctx->r2 = MEM_BU(0X441, ctx->r29);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $t3, $v0, L_80032AC0
    if (ctx->r11 != ctx->r2) {
        // sw          $t3, 0x470($sp)
        MEM_W(0X470, ctx->r29) = ctx->r11;
        goto L_80032AC0;
    }
    // sw          $t3, 0x470($sp)
    MEM_W(0X470, ctx->r29) = ctx->r11;
L_800335E0:
    // lw          $t2, 0x460($sp)
    ctx->r10 = MEM_W(0X460, ctx->r29);
    // lw          $t3, 0x468($sp)
    ctx->r11 = MEM_W(0X468, ctx->r29);
    // lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(0X10, ctx->r10);
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // lw          $t2, 0x458($sp)
    ctx->r10 = MEM_W(0X458, ctx->r29);
    // lw          $t3, 0x450($sp)
    ctx->r11 = MEM_W(0X450, ctx->r29);
    // lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(0X4, ctx->r10);
    // lw          $t2, 0x460($sp)
    ctx->r10 = MEM_W(0X460, ctx->r29);
    // addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // lw          $t3, 0x458($sp)
    ctx->r11 = MEM_W(0X458, ctx->r29);
    // lw          $t2, 0x448($sp)
    ctx->r10 = MEM_W(0X448, ctx->r29);
    // lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(0X0, ctx->r11);
    // lw          $s0, 0x4($t3)
    ctx->r16 = MEM_W(0X4, ctx->r11);
    // addu        $a1, $t2, $a1
    ctx->r5 = ADD32(ctx->r10, ctx->r5);
    // jal         0x80017684
    // sll         $a2, $s0, 1
    ctx->r6 = S32(ctx->r16) << 1;
    MemcpyDword(rdram, ctx);
    goto after_11;
    // sll         $a2, $s0, 1
    ctx->r6 = S32(ctx->r16) << 1;
    after_11:
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // addu        $s7, $s7, $s0
    ctx->r23 = ADD32(ctx->r23, ctx->r16);
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lw          $t3, 0x450($sp)
    ctx->r11 = MEM_W(0X450, ctx->r29);
    // addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // sw          $s0, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r16;
    // jal         0x80017684
    // sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11) << 1;
    MemcpyDword(rdram, ctx);
    goto after_12;
    // sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11) << 1;
    after_12:
    // lw          $t2, 0x450($sp)
    ctx->r10 = MEM_W(0X450, ctx->r29);
    // lw          $t3, 0x460($sp)
    ctx->r11 = MEM_W(0X460, ctx->r29);
    // sll         $a0, $t2, 3
    ctx->r4 = S32(ctx->r10) << 3;
    // addu        $t2, $s0, $zero
    ctx->r10 = ADD32(ctx->r16, 0);
    // lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(0X0, ctx->r11);
    // addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // sw          $t2, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r10;
    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // lw          $t3, 0x458($sp)
    ctx->r11 = MEM_W(0X458, ctx->r29);
    // lw          $t2, 0x460($sp)
    ctx->r10 = MEM_W(0X460, ctx->r29);
    // lw          $v0, 0xC($t3)
    ctx->r2 = MEM_W(0XC, ctx->r11);
    // nop

    // sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // lw          $a1, 0x8($t3)
    ctx->r5 = MEM_W(0X8, ctx->r11);
    // lw          $a2, 0xC($t3)
    ctx->r6 = MEM_W(0XC, ctx->r11);
    // lw          $t3, 0x448($sp)
    ctx->r11 = MEM_W(0X448, ctx->r29);
    // addu        $a0, $s7, $a0
    ctx->r4 = ADD32(ctx->r23, ctx->r4);
    // addu        $a1, $t3, $a1
    ctx->r5 = ADD32(ctx->r11, ctx->r5);
    // jal         0x80017684
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    MemcpyDword(rdram, ctx);
    goto after_13;
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    after_13:
    // lw          $ra, 0x4DC($sp)
    ctx->r31 = MEM_W(0X4DC, ctx->r29);
    // lw          $fp, 0x4D8($sp)
    ctx->r30 = MEM_W(0X4D8, ctx->r29);
    // lw          $s7, 0x4D4($sp)
    ctx->r23 = MEM_W(0X4D4, ctx->r29);
    // lw          $s6, 0x4D0($sp)
    ctx->r22 = MEM_W(0X4D0, ctx->r29);
    // lw          $s5, 0x4CC($sp)
    ctx->r21 = MEM_W(0X4CC, ctx->r29);
    // lw          $s4, 0x4C8($sp)
    ctx->r20 = MEM_W(0X4C8, ctx->r29);
    // lw          $s3, 0x4C4($sp)
    ctx->r19 = MEM_W(0X4C4, ctx->r29);
    // lw          $s2, 0x4C0($sp)
    ctx->r18 = MEM_W(0X4C0, ctx->r29);
    // lw          $s1, 0x4BC($sp)
    ctx->r17 = MEM_W(0X4BC, ctx->r29);
    // lw          $s0, 0x4B8($sp)
    ctx->r16 = MEM_W(0X4B8, ctx->r29);
    // addiu       $sp, $sp, 0x4E0
    ctx->r29 = ADD32(ctx->r29, 0X4E0);
    // jr          $ra
    // nop

    return;
    // nop

;}
