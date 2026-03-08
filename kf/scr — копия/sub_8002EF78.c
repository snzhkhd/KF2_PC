#include "recomp.h"
#include "disable_warnings.h"

void sub_8002EF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t5, $a1, $zero
    ctx->r13 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x753C
    ctx->r3 = ADD32(ctx->r3, -0X753C);
    // lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(0X34, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(0X0, ctx->r3);
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // lw          $a1, -0x7538($a1)
    ctx->r5 = MEM_W(-0X7538, ctx->r5);
    // lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // lw          $t7, -0x7544($t7)
    ctx->r15 = MEM_W(-0X7544, ctx->r15);
    // lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // lw          $t1, -0x7540($t1)
    ctx->r9 = MEM_W(-0X7540, ctx->r9);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // lw          $t0, -0x7534($t0)
    ctx->r8 = MEM_W(-0X7534, ctx->r8);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // beq         $t8, $v0, L_8002F178
    if (ctx->r24 == ctx->r2) {
        // sll         $v0, $a3, 24
        ctx->r2 = S32(ctx->r7) << 24;
        goto L_8002F178;
    }
    // sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7) << 24;
    // addiu       $s6, $v1, -0xC
    ctx->r22 = ADD32(ctx->r3, -0XC);
    // lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // addiu       $s5, $s5, -0x428C
    ctx->r21 = ADD32(ctx->r21, -0X428C);
    // ori         $s4, $zero, 0xFF
    ctx->r20 = 0 | 0XFF;
    // addiu       $s3, $v1, -0xB
    ctx->r19 = ADD32(ctx->r3, -0XB);
    // sra         $t4, $v0, 24
    ctx->r12 = S32(ctx->r2) >> 24;
    // sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9) << 1;
    // addu        $t3, $v0, $t1
    ctx->r11 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $t7, 2
    ctx->r2 = S32(ctx->r15) << 2;
    // addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // addu        $s1, $t0, $t5
    ctx->r17 = ADD32(ctx->r8, ctx->r13);
    // addu        $s0, $t0, $a0
    ctx->r16 = ADD32(ctx->r8, ctx->r4);
L_8002F010:
    // sltiu       $v0, $t9, 0x18
    ctx->r2 = ctx->r25 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002F138
    if (ctx->r2 == 0) {
        // sltiu       $v0, $a1, 0x18
        ctx->r2 = ctx->r5 < 0X18 ? 1 : 0;
        goto L_8002F138;
    }
    // sltiu       $v0, $a1, 0x18
    ctx->r2 = ctx->r5 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002F138
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002F138;
    }
    // nop

    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // nop

    // beq         $v0, $zero, L_8002F138
    if (ctx->r2 == 0) {
        // sltiu       $v0, $t7, 0x50
        ctx->r2 = ctx->r15 < 0X50 ? 1 : 0;
        goto L_8002F138;
    }
    // sltiu       $v0, $t7, 0x50
    ctx->r2 = ctx->r15 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8002F134
    if (ctx->r2 == 0) {
        // sltiu       $v0, $t1, 0x50
        ctx->r2 = ctx->r9 < 0X50 ? 1 : 0;
        goto L_8002F134;
    }
    // sltiu       $v0, $t1, 0x50
    ctx->r2 = ctx->r9 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8002F134
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002F134;
    }
    // nop

    // lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(0X0, ctx->r16);
    // lbu         $v1, 0x0($s6)
    ctx->r3 = MEM_BU(0X0, ctx->r22);
    // lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(0X0, ctx->r17);
    // and         $v0, $t6, $v1
    ctx->r2 = ctx->r14 & ctx->r3;
    // bne         $v0, $zero, L_8002F090
    if (ctx->r2 != 0) {
        // and         $v0, $t5, $v1
        ctx->r2 = ctx->r13 & ctx->r3;
        goto L_8002F090;
    }
    // and         $v0, $t5, $v1
    ctx->r2 = ctx->r13 & ctx->r3;
    // bne         $v0, $zero, L_8002F094
    if (ctx->r2 != 0) {
        // sll         $v1, $t3, 3
        ctx->r3 = S32(ctx->r11) << 3;
        goto L_8002F094;
    }
    // sll         $v1, $t3, 3
    ctx->r3 = S32(ctx->r11) << 3;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10) << 1;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_8002F078:
    // lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(0X0, ctx->r22);
    // lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(0X0, ctx->r8);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // j           L_8002F0F0
    // sb          $v1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r3;
    goto L_8002F0F0;
    // sb          $v1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r3;
L_8002F090:
    // sll         $v1, $t3, 3
    ctx->r3 = S32(ctx->r11) << 3;
L_8002F094:
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10) << 1;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x7550($a0)
    ctx->r4 = MEM_W(-0X7550, ctx->r4);
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $s4, L_8002F078
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_8002F078;
    }
    // nop

    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8002F0F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002F0F0;
    }
    // nop

L_8002F0D8:
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // nop

    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // j           L_8002F138
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    goto L_8002F138;
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
L_8002F0F0:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x754C($v0)
    ctx->r2 = MEM_W(-0X754C, ctx->r2);
    // nop

    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // beq         $v0, $s4, L_8002F138
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_8002F138;
    }
    // nop

    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // nop

    // and         $v0, $t6, $v1
    ctx->r2 = ctx->r14 & ctx->r3;
    // bne         $v0, $zero, L_8002F0D8
    if (ctx->r2 != 0) {
        // and         $v0, $t5, $v1
        ctx->r2 = ctx->r13 & ctx->r3;
        goto L_8002F0D8;
    }
    // and         $v0, $t5, $v1
    ctx->r2 = ctx->r13 & ctx->r3;
    // bne         $v0, $zero, L_8002F0D8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002F0D8;
    }
    // nop

    // j           L_8002F13C
    // addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    goto L_8002F13C;
    // addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
L_8002F134:
    // sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8002F138:
    // addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
L_8002F13C:
    // addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // addu        $t0, $t0, $s2
    ctx->r8 = ADD32(ctx->r8, ctx->r18);
    // addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12) << 1;
    // addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $t8, $v0, L_8002F010
    if (ctx->r24 != ctx->r2) {
        // addu        $t1, $t1, $t4
        ctx->r9 = ADD32(ctx->r9, ctx->r12);
        goto L_8002F010;
    }
    // addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
L_8002F178:
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $t9, -0x753C($at)
    MEM_W(-0X753C, ctx->r1) = ctx->r25;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $a1, -0x7538($at)
    MEM_W(-0X7538, ctx->r1) = ctx->r5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $t7, -0x7544($at)
    MEM_W(-0X7544, ctx->r1) = ctx->r15;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $t1, -0x7540($at)
    MEM_W(-0X7540, ctx->r1) = ctx->r9;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $t0, -0x7534($at)
    MEM_W(-0X7534, ctx->r1) = ctx->r8;
    // lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(0X18, ctx->r29);
    // lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(0X14, ctx->r29);
    // lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(0X10, ctx->r29);
    // lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(0XC, ctx->r29);
    // lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(0X8, ctx->r29);
    // lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(0X4, ctx->r29);
    // lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(0X0, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
