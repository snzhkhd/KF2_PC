#include "recomp.h"
#include "disable_warnings.h"

void Map_CopyTileBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(0X38, ctx->r29);
    // lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(0X44, ctx->r29);
    // sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(0X3C, ctx->r29);
    // lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(0X40, ctx->r29);
    // lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(0X48, ctx->r29);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // beq         $s4, $v0, L_80037F50
    if (ctx->r20 == ctx->r2) {
        // sw          $s0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r16;
        goto L_80037F50;
    }
    // sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // sra         $v0, $t7, 10
    ctx->r2 = S32(ctx->r15) >> 10;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $t7, $v0, L_80037CA4
    if (ctx->r15 == ctx->r2) {
        // slti        $v0, $t7, 0x2
        ctx->r2 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
        goto L_80037CA4;
    }
    // slti        $v0, $t7, 0x2
    ctx->r2 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80037C7C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80037C7C;
    }
    // nop

    // beq         $t7, $zero, L_80037C98
    if (ctx->r15 == 0) {
        // sll         $v1, $a2, 1
        ctx->r3 = S32(ctx->r6) << 1;
        goto L_80037C98;
    }
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // j           L_80037CE4
    // nop

    goto L_80037CE4;
    // nop

L_80037C7C:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $t7, $v0, L_80037CB8
    if (ctx->r15 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80037CB8;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $t7, $v0, L_80037CD4
    if (ctx->r15 == ctx->r2) {
        // addiu       $v0, $a3, -0x1
        ctx->r2 = ADD32(ctx->r7, -0X1);
        goto L_80037CD4;
    }
    // addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // j           L_80037CE4
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    goto L_80037CE4;
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
L_80037C98:
    // ori         $t8, $zero, 0x1
    ctx->r24 = 0 | 0X1;
    // j           L_80037CE0
    // ori         $t2, $zero, 0x50
    ctx->r10 = 0 | 0X50;
    goto L_80037CE0;
    // ori         $t2, $zero, 0x50
    ctx->r10 = 0 | 0X50;
L_80037CA4:
    // addiu       $t8, $zero, -0x50
    ctx->r24 = ADD32(0, -0X50);
    // ori         $t2, $zero, 0x1
    ctx->r10 = 0 | 0X1;
    // addiu       $v0, $t1, -0x1
    ctx->r2 = ADD32(ctx->r9, -0X1);
    // j           L_80037CE0
    // addu        $t1, $v0, $s4
    ctx->r9 = ADD32(ctx->r2, ctx->r20);
    goto L_80037CE0;
    // addu        $t1, $v0, $s4
    ctx->r9 = ADD32(ctx->r2, ctx->r20);
L_80037CB8:
    // addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // addiu       $t2, $zero, -0x50
    ctx->r10 = ADD32(0, -0X50);
    // addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v0, $s4
    ctx->r7 = ADD32(ctx->r2, ctx->r20);
    // addiu       $v0, $t1, -0x1
    ctx->r2 = ADD32(ctx->r9, -0X1);
    // j           L_80037CE0
    // addu        $t1, $v0, $t3
    ctx->r9 = ADD32(ctx->r2, ctx->r11);
    goto L_80037CE0;
    // addu        $t1, $v0, $t3
    ctx->r9 = ADD32(ctx->r2, ctx->r11);
L_80037CD4:
    // ori         $t8, $zero, 0x50
    ctx->r24 = 0 | 0X50;
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // addu        $a3, $v0, $t3
    ctx->r7 = ADD32(ctx->r2, ctx->r11);
L_80037CE0:
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
L_80037CE4:
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) << 1;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // beq         $t3, $zero, L_80037F50
    if (ctx->r11 == 0) {
        // addiu       $t1, $t3, -0x1
        ctx->r9 = ADD32(ctx->r11, -0X1);
        goto L_80037F50;
    }
    // addiu       $t1, $t3, -0x1
    ctx->r9 = ADD32(ctx->r11, -0X1);
    // sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10) << 2;
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sll         $s6, $v0, 1
    ctx->r22 = S32(ctx->r2) << 1;
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // andi        $s3, $s5, 0x1
    ctx->r19 = ctx->r21 & 0X1;
    // andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_80037D5C:
    // addiu       $s2, $a3, 0x320
    ctx->r18 = ADD32(ctx->r7, 0X320);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a2, $s4, -0x1
    ctx->r6 = ADD32(ctx->r20, -0X1);
    // beq         $a2, $s0, L_80037F44
    if (ctx->r6 == ctx->r16) {
        // addu        $s1, $a0, $s6
        ctx->r17 = ADD32(ctx->r4, ctx->r22);
        goto L_80037F44;
    }
    // addu        $s1, $a0, $s6
    ctx->r17 = ADD32(ctx->r4, ctx->r22);
    // andi        $t6, $t0, 0x2
    ctx->r14 = ctx->r8 & 0X2;
    // andi        $t5, $t0, 0x4
    ctx->r13 = ctx->r8 & 0X4;
    // andi        $t4, $t0, 0x8
    ctx->r12 = ctx->r8 & 0X8;
    // andi        $t3, $t0, 0x10
    ctx->r11 = ctx->r8 & 0X10;
    // andi        $t2, $t0, 0x20
    ctx->r10 = ctx->r8 & 0X20;
    // addiu       $a1, $a3, 0x9
    ctx->r5 = ADD32(ctx->r7, 0X9);
L_80037D88:
    // beq         $s3, $zero, L_80037E58
    if (ctx->r19 == 0) {
        // andi        $v0, $s5, 0x2
        ctx->r2 = ctx->r21 & 0X2;
        goto L_80037E58;
    }
    // andi        $v0, $s5, 0x2
    ctx->r2 = ctx->r21 & 0X2;
    // beq         $t9, $zero, L_80037DA4
    if (ctx->r25 == 0) {
        // nop
    
        goto L_80037DA4;
    }
    // nop

    // lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(0X0, ctx->r7);
    // nop

    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80037DA4:
    // beq         $t6, $zero, L_80037DB8
    if (ctx->r14 == 0) {
        // nop
    
        goto L_80037DB8;
    }
    // nop

    // lbu         $v0, -0x8($a1)
    ctx->r2 = MEM_BU(-0X8, ctx->r5);
    // nop

    // sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
L_80037DB8:
    // beq         $t5, $zero, L_80037DDC
    if (ctx->r13 == 0) {
        // nop
    
        goto L_80037DDC;
    }
    // nop

    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // lbu         $v0, -0x7($a1)
    ctx->r2 = MEM_BU(-0X7, ctx->r5);
    // andi        $v1, $v1, 0xFC
    ctx->r3 = ctx->r3 & 0XFC;
    // addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
L_80037DDC:
    // beq         $t4, $zero, L_80037DF0
    if (ctx->r12 == 0) {
        // nop
    
        goto L_80037DF0;
    }
    // nop

    // lbu         $v0, -0x6($a1)
    ctx->r2 = MEM_BU(-0X6, ctx->r5);
    // nop

    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_80037DF0:
    // beq         $t3, $zero, L_80037E10
    if (ctx->r11 == 0) {
        // nop
    
        goto L_80037E10;
    }
    // nop

    // lbu         $v0, -0x5($a1)
    ctx->r2 = MEM_BU(-0X5, ctx->r5);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // andi        $v1, $v1, 0xC0
    ctx->r3 = ctx->r3 & 0XC0;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
L_80037E10:
    // beq         $t2, $zero, L_80037E34
    if (ctx->r10 == 0) {
        // andi        $v0, $t0, 0x40
        ctx->r2 = ctx->r8 & 0X40;
        goto L_80037E34;
    }
    // andi        $v0, $t0, 0x40
    ctx->r2 = ctx->r8 & 0X40;
    // lbu         $v0, -0x5($a1)
    ctx->r2 = MEM_BU(-0X5, ctx->r5);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // andi        $v1, $v1, 0xBF
    ctx->r3 = ctx->r3 & 0XBF;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // andi        $v0, $t0, 0x40
    ctx->r2 = ctx->r8 & 0X40;
L_80037E34:
    // beq         $v0, $zero, L_80037E58
    if (ctx->r2 == 0) {
        // andi        $v0, $s5, 0x2
        ctx->r2 = ctx->r21 & 0X2;
        goto L_80037E58;
    }
    // andi        $v0, $s5, 0x2
    ctx->r2 = ctx->r21 & 0X2;
    // lbu         $v0, -0x5($a1)
    ctx->r2 = MEM_BU(-0X5, ctx->r5);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // andi        $v0, $s5, 0x2
    ctx->r2 = ctx->r21 & 0X2;
L_80037E58:
    // beq         $v0, $zero, L_80037F24
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80037F24;
    }
    // nop

    // beq         $t9, $zero, L_80037E74
    if (ctx->r25 == 0) {
        // nop
    
        goto L_80037E74;
    }
    // nop

    // lbu         $v0, -0x4($a1)
    ctx->r2 = MEM_BU(-0X4, ctx->r5);
    // nop

    // sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
L_80037E74:
    // beq         $t6, $zero, L_80037E88
    if (ctx->r14 == 0) {
        // nop
    
        goto L_80037E88;
    }
    // nop

    // lbu         $v0, -0x3($a1)
    ctx->r2 = MEM_BU(-0X3, ctx->r5);
    // nop

    // sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
L_80037E88:
    // beq         $t5, $zero, L_80037EAC
    if (ctx->r13 == 0) {
        // nop
    
        goto L_80037EAC;
    }
    // nop

    // lbu         $v1, 0x7($a0)
    ctx->r3 = MEM_BU(0X7, ctx->r4);
    // lbu         $v0, -0x2($a1)
    ctx->r2 = MEM_BU(-0X2, ctx->r5);
    // andi        $v1, $v1, 0xFC
    ctx->r3 = ctx->r3 & 0XFC;
    // addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r3;
L_80037EAC:
    // beq         $t4, $zero, L_80037EC0
    if (ctx->r12 == 0) {
        // nop
    
        goto L_80037EC0;
    }
    // nop

    // lbu         $v0, -0x1($a1)
    ctx->r2 = MEM_BU(-0X1, ctx->r5);
    // nop

    // sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
L_80037EC0:
    // beq         $t3, $zero, L_80037EE0
    if (ctx->r11 == 0) {
        // nop
    
        goto L_80037EE0;
    }
    // nop

    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(0X9, ctx->r4);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // andi        $v1, $v1, 0xC0
    ctx->r3 = ctx->r3 & 0XC0;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
L_80037EE0:
    // beq         $t2, $zero, L_80037F04
    if (ctx->r10 == 0) {
        // andi        $v0, $t0, 0x40
        ctx->r2 = ctx->r8 & 0X40;
        goto L_80037F04;
    }
    // andi        $v0, $t0, 0x40
    ctx->r2 = ctx->r8 & 0X40;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(0X9, ctx->r4);
    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // andi        $v1, $v1, 0xBF
    ctx->r3 = ctx->r3 & 0XBF;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
    // andi        $v0, $t0, 0x40
    ctx->r2 = ctx->r8 & 0X40;
L_80037F04:
    // beq         $v0, $zero, L_80037F24
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80037F24;
    }
    // nop

    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(0X9, ctx->r4);
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
L_80037F24:
    // addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // sll         $v0, $t8, 2
    ctx->r2 = S32(ctx->r24) << 2;
    // addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $s0, L_80037D88
    if (ctx->r6 != ctx->r16) {
        // addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_80037D88;
    }
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80037F44:
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // bne         $t1, $s0, L_80037D5C
    if (ctx->r9 != ctx->r16) {
        // addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
        goto L_80037D5C;
    }
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_80037F50:
    // lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(0X20, ctx->r29);
    // lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(0X1C, ctx->r29);
    // lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(0X18, ctx->r29);
    // lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(0X14, ctx->r29);
    // lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(0X10, ctx->r29);
    // lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(0XC, ctx->r29);
    // lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(0X8, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
