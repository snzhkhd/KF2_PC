#include "recomp.h"
#include "disable_warnings.h"

void sub_8002E4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(0X54, ctx->r29);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    // beq         $v0, $zero, L_8002E590
    if (ctx->r2 == 0) {
        // addu        $s7, $s0, $zero
        ctx->r23 = ADD32(ctx->r16, 0);
        goto L_8002E590;
    }
    // addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    // jal         0x8002E318
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    CollisionWithTilemap(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // beq         $v0, $zero, L_8002E5D4
    if (ctx->r2 == 0) {
        // lui         $v1, 0xFFF
        ctx->r3 = S32(0XFFF << 16);
        goto L_8002E5D4;
    }
    // lui         $v1, 0xFFF
    ctx->r3 = S32(0XFFF << 16);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A88($v0)
    ctx->r2 = MEM_W(-0X2A88, ctx->r2);
    // nop

    // lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(0X4, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8002E5D4
    if (ctx->r2 == 0) {
        // lui         $v0, 0xFFFE
        ctx->r2 = S32(0XFFFE << 16);
        goto L_8002E5D4;
    }
    // lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // ori         $v0, $v0, 0x7960
    ctx->r2 = ctx->r2 | 0X7960;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A7C($at)
    MEM_W(-0X2A7C, ctx->r1) = ctx->r2;
    // j           L_8002E5D4
    // ori         $s1, $s1, 0x1
    ctx->r17 = ctx->r17 | 0X1;
    goto L_8002E5D4;
    // ori         $s1, $s1, 0x1
    ctx->r17 = ctx->r17 | 0X1;
L_8002E590:
    // sra         $v0, $s4, 11
    ctx->r2 = S32(ctx->r20) >> 11;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sra         $a0, $s3, 11
    ctx->r4 = S32(ctx->r19) >> 11;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v1, -0x2A8C($at)
    MEM_W(-0X2A8C, ctx->r1) = ctx->r3;
    // lui         $v1, 0xFFF
    ctx->r3 = S32(0XFFF << 16);
L_8002E5D4:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A8C($v0)
    ctx->r2 = MEM_W(-0X2A8C, ctx->r2);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // nop

    // andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // beq         $v0, $zero, L_8002E6EC
    if (ctx->r2 == 0) {
        // and         $s2, $s2, $v1
        ctx->r18 = ctx->r18 & ctx->r3;
        goto L_8002E6EC;
    }
    // and         $s2, $s2, $v1
    ctx->r18 = ctx->r18 & ctx->r3;
    // andi        $v0, $s7, 0x10
    ctx->r2 = ctx->r23 & 0X10;
    // beq         $v0, $zero, L_8002E630
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8002E630;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // jal         0x8003D480
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    Entity_CheckWorldCollision(rdram, ctx);
    goto after_1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A68($at)
    MEM_W(-0X2A68, ctx->r1) = ctx->r2;
    // beq         $v0, $v1, L_8002E674
    if (ctx->r2 == ctx->r3) {
        // andi        $v0, $s7, 0x20
        ctx->r2 = ctx->r23 & 0X20;
        goto L_8002E674;
    }
    // andi        $v0, $s7, 0x20
    ctx->r2 = ctx->r23 & 0X20;
    // j           L_8002E674
    // ori         $s1, $s1, 0x10
    ctx->r17 = ctx->r17 | 0X10;
    goto L_8002E674;
    // ori         $s1, $s1, 0x10
    ctx->r17 = ctx->r17 | 0X10;
L_8002E630:
    // andi        $v0, $s7, 0x40
    ctx->r2 = ctx->r23 & 0X40;
    // beq         $v0, $zero, L_8002E664
    if (ctx->r2 == 0) {
        // addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
        goto L_8002E664;
    }
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // jal         0x8003D5EC
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_8003D5EC(rdram, ctx);
    goto after_2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_2:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A68($at)
    MEM_W(-0X2A68, ctx->r1) = ctx->r2;
    // beq         $v0, $v1, L_8002E668
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8002E668;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // ori         $s1, $s1, 0x10
    ctx->r17 = ctx->r17 | 0X10;
L_8002E664:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002E668:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A68($at)
    MEM_W(-0X2A68, ctx->r1) = ctx->r2;
    // andi        $v0, $s7, 0x20
    ctx->r2 = ctx->r23 & 0X20;
L_8002E674:
    // beq         $v0, $zero, L_8002E6AC
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8002E6AC;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // jal         0x80038AF0
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_80038AF0(rdram, ctx);
    goto after_3;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A64($at)
    MEM_W(-0X2A64, ctx->r1) = ctx->r2;
    // beq         $v0, $v1, L_8002E6BC
    if (ctx->r2 == ctx->r3) {
        // andi        $v0, $s7, 0x80
        ctx->r2 = ctx->r23 & 0X80;
        goto L_8002E6BC;
    }
    // andi        $v0, $s7, 0x80
    ctx->r2 = ctx->r23 & 0X80;
    // j           L_8002E6BC
    // ori         $s1, $s1, 0x20
    ctx->r17 = ctx->r17 | 0X20;
    goto L_8002E6BC;
    // ori         $s1, $s1, 0x20
    ctx->r17 = ctx->r17 | 0X20;
L_8002E6AC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A64($at)
    MEM_W(-0X2A64, ctx->r1) = ctx->r2;
    // andi        $v0, $s7, 0x80
    ctx->r2 = ctx->r23 & 0X80;
L_8002E6BC:
    // beq         $v0, $zero, L_8002E700
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8002E700;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // jal         0x80025EDC
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    sub_80025EDC(rdram, ctx);
    goto after_4;
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    after_4:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8002E700
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8002E700;
    }
    // nop

    // j           L_8002E700
    // ori         $s1, $s1, 0x80
    ctx->r17 = ctx->r17 | 0X80;
    goto L_8002E700;
    // ori         $s1, $s1, 0x80
    ctx->r17 = ctx->r17 | 0X80;
L_8002E6EC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A68($at)
    MEM_W(-0X2A68, ctx->r1) = ctx->r2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A64($at)
    MEM_W(-0X2A64, ctx->r1) = ctx->r2;
L_8002E700:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $s1, -0x2A6C($at)
    MEM_W(-0X2A6C, ctx->r1) = ctx->r17;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
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
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
