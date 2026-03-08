#include "recomp.h"
#include "disable_warnings.h"

void sub_800166F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // lbu         $s7, 0x54($sp)
    ctx->r23 = MEM_BU(0X54, ctx->r29);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // lbu         $fp, 0x58($sp)
    ctx->r30 = MEM_BU(0X58, ctx->r29);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lbu         $s2, 0x50($sp)
    ctx->r18 = MEM_BU(0X50, ctx->r29);
    // lbu         $t5, 0x5C($sp)
    ctx->r13 = MEM_BU(0X5C, ctx->r29);
    // ori         $v0, $zero, 0xC8
    ctx->r2 = 0 | 0XC8;
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // bne         $v1, $v0, L_80016778
    if (ctx->r3 != ctx->r2) {
        // sb          $t5, 0x10($sp)
        MEM_B(0X10, ctx->r29) = ctx->r13;
        goto L_80016778;
    }
    // sb          $t5, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r13;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x59D0($v0)
    ctx->r2 = MEM_W(-0X59D0, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80016C38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80016C38;
    }
    // nop

    // jal         0x80013FC0
    // nop

    Music_PlaySEQ(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80016C38
    // nop

    goto L_80016C38;
    // nop

L_80016778:
    // andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80016848
    if (ctx->r3 != ctx->r2) {
        // addu        $t4, $s1, $zero
        ctx->r12 = ADD32(ctx->r17, 0);
        goto L_80016848;
    }
    // addu        $t4, $s1, $zero
    ctx->r12 = ADD32(ctx->r17, 0);
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // lbu         $s4, 0x79D8($s4)
    ctx->r20 = MEM_BU(0X79D8, ctx->r20);
    // lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // lbu         $t4, 0x79E4($t4)
    ctx->r12 = MEM_BU(0X79E4, ctx->r12);
    // bne         $v0, $v1, L_800167BC
    if (ctx->r2 != ctx->r3) {
        // addu        $t3, $s3, $zero
        ctx->r11 = ADD32(ctx->r19, 0);
        goto L_800167BC;
    }
    // addu        $t3, $s3, $zero
    ctx->r11 = ADD32(ctx->r19, 0);
    // lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // lbu         $t2, 0x79D9($t2)
    ctx->r10 = MEM_BU(0X79D9, ctx->r10);
    // lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // lbu         $t3, 0x79E5($t3)
    ctx->r11 = MEM_BU(0X79E5, ctx->r11);
    // j           L_800167C4
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    goto L_800167C4;
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
L_800167BC:
    // addu        $t2, $s3, $zero
    ctx->r10 = ADD32(ctx->r19, 0);
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
L_800167C4:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_800167E8
    if (ctx->r3 != ctx->r2) {
        // addu        $t1, $s5, $zero
        ctx->r9 = ADD32(ctx->r21, 0);
        goto L_800167E8;
    }
    // addu        $t1, $s5, $zero
    ctx->r9 = ADD32(ctx->r21, 0);
    // lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // lbu         $a3, 0x79DA($a3)
    ctx->r7 = MEM_BU(0X79DA, ctx->r7);
    // lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // lbu         $t1, 0x79E6($t1)
    ctx->r9 = MEM_BU(0X79E6, ctx->r9);
    // j           L_800167F4
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    goto L_800167F4;
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
L_800167E8:
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
L_800167F4:
    // bne         $v1, $v0, L_80016814
    if (ctx->r3 != ctx->r2) {
        // addu        $t0, $s6, $zero
        ctx->r8 = ADD32(ctx->r22, 0);
        goto L_80016814;
    }
    // addu        $t0, $s6, $zero
    ctx->r8 = ADD32(ctx->r22, 0);
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lbu         $a1, 0x79DB($a1)
    ctx->r5 = MEM_BU(0X79DB, ctx->r5);
    // lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // lbu         $t0, 0x79E7($t0)
    ctx->r8 = MEM_BU(0X79E7, ctx->r8);
    // j           L_8001681C
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    goto L_8001681C;
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
L_80016814:
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
L_8001681C:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80016840
    if (ctx->r3 != ctx->r2) {
        // addu        $a2, $s2, $zero
        ctx->r6 = ADD32(ctx->r18, 0);
        goto L_80016840;
    }
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79DC($a0)
    ctx->r4 = MEM_BU(0X79DC, ctx->r4);
    // lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // lbu         $a2, 0x79E8($a2)
    ctx->r6 = MEM_BU(0X79E8, ctx->r6);
    // j           L_8001687C
    // nop

    goto L_8001687C;
    // nop

L_80016840:
    // j           L_8001687C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_8001687C;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80016848:
    // addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $t0, $s1, $zero
    ctx->r8 = ADD32(ctx->r17, 0);
    // addu        $t1, $s1, $zero
    ctx->r9 = ADD32(ctx->r17, 0);
    // addu        $t3, $s1, $zero
    ctx->r11 = ADD32(ctx->r17, 0);
    // lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // lbu         $t2, 0x79D9($t2)
    ctx->r10 = MEM_BU(0X79D9, ctx->r10);
    // lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // lbu         $a3, 0x79DA($a3)
    ctx->r7 = MEM_BU(0X79DA, ctx->r7);
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lbu         $a1, 0x79DB($a1)
    ctx->r5 = MEM_BU(0X79DB, ctx->r5);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79DC($a0)
    ctx->r4 = MEM_BU(0X79DC, ctx->r4);
L_8001687C:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lh          $v1, 0x79D4($v1)
    ctx->r3 = MEM_H(0X79D4, ctx->r3);
    // nop

    // bne         $v1, $zero, L_800169C8
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800169C8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79D8($v1)
    ctx->r3 = MEM_BU(0X79D8, ctx->r3);
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // bne         $v1, $v0, L_800168F4
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t2, 0xFF
        ctx->r2 = ctx->r10 & 0XFF;
        goto L_800168F4;
    }
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79D9($v1)
    ctx->r3 = MEM_BU(0X79D9, ctx->r3);
    // nop

    // bne         $v1, $v0, L_800168F4
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_800168F4;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79DA($v1)
    ctx->r3 = MEM_BU(0X79DA, ctx->r3);
    // nop

    // bne         $v1, $v0, L_800168F4
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $a1, 0xFF
        ctx->r2 = ctx->r5 & 0XFF;
        goto L_800168F4;
    }
    // andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79DB($v1)
    ctx->r3 = MEM_BU(0X79DB, ctx->r3);
    // nop

    // bne         $v1, $v0, L_800168F4
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
        goto L_800168F4;
    }
    // andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79DC($v1)
    ctx->r3 = MEM_BU(0X79DC, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80016C38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_800168F4:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79D8($a0)
    ctx->r4 = MEM_BU(0X79D8, ctx->r4);
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // beq         $a0, $v0, L_80016918
    if (ctx->r4 == ctx->r2) {
        // andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
        goto L_80016918;
    }
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // beq         $a0, $v0, L_80016918
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80016918;
    }
    // nop

    // jal         0x8004AEC4
    // nop

    sub_8004AEC4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80016918:
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // addiu       $a0, $a0, 0x519C
    ctx->r4 = ADD32(ctx->r4, 0X519C);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80016938
    if (ctx->r2 == 0) {
        // andi        $v1, $s3, 0xFF
        ctx->r3 = ctx->r19 & 0XFF;
        goto L_80016938;
    }
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // sb          $s4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r20;
L_80016938:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lbu         $t5, 0x10($sp)
    ctx->r13 = MEM_BU(0X10, ctx->r29);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D4($at)
    MEM_H(0X79D4, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $zero, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $s1, 0x79E4($at)
    MEM_B(0X79E4, ctx->r1) = ctx->r17;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $s3, 0x79E5($at)
    MEM_B(0X79E5, ctx->r1) = ctx->r19;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $s5, 0x79E6($at)
    MEM_B(0X79E6, ctx->r1) = ctx->r21;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $s6, 0x79E7($at)
    MEM_B(0X79E7, ctx->r1) = ctx->r22;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $s2, 0x79E8($at)
    MEM_B(0X79E8, ctx->r1) = ctx->r18;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $s7, 0x79EB($at)
    MEM_B(0X79EB, ctx->r1) = ctx->r23;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $fp, 0x79EC($at)
    MEM_B(0X79EC, ctx->r1) = ctx->r30;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79E9($at)
    MEM_B(0X79E9, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $t5, 0x79ED($at)
    MEM_B(0X79ED, ctx->r1) = ctx->r13;
    // bne         $v1, $v0, L_800169B4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800169B4;
    }
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79EA($at)
    MEM_B(0X79EA, ctx->r1) = 0;
    // j           L_80016C38
    // nop

    goto L_80016C38;
    // nop

L_800169B4:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79EA($at)
    MEM_B(0X79EA, ctx->r1) = ctx->r2;
    // j           L_80016C38
    // nop

    goto L_80016C38;
    // nop

L_800169C8:
    // bne         $v1, $v0, L_800169E4
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t4, 0xFF
        ctx->r2 = ctx->r12 & 0XFF;
        goto L_800169E4;
    }
    // andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E4($v1)
    ctx->r3 = MEM_BU(0X79E4, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80016A34
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80016A34;
    }
    // nop

L_800169E4:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E5($v1)
    ctx->r3 = MEM_BU(0X79E5, ctx->r3);
    // andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    // bne         $v1, $v0, L_80016A34
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t1, 0xFF
        ctx->r2 = ctx->r9 & 0XFF;
        goto L_80016A34;
    }
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E6($v1)
    ctx->r3 = MEM_BU(0X79E6, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80016A34
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t0, 0xFF
        ctx->r2 = ctx->r8 & 0XFF;
        goto L_80016A34;
    }
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E7($v1)
    ctx->r3 = MEM_BU(0X79E7, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80016A34
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
        goto L_80016A34;
    }
    // andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E8($v1)
    ctx->r3 = MEM_BU(0X79E8, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80016C38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_80016A34:
    // lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // lbu         $t0, 0x79E4($t0)
    ctx->r8 = MEM_BU(0X79E4, ctx->r8);
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // bne         $t0, $a0, L_80016A5C
    if (ctx->r8 != ctx->r4) {
        // andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
        goto L_80016A5C;
    }
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79D8($v1)
    ctx->r3 = MEM_BU(0X79D8, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80016C38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_80016A5C:
    // lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // lbu         $a3, 0x79E5($a3)
    ctx->r7 = MEM_BU(0X79E5, ctx->r7);
    // nop

    // bne         $a3, $a0, L_80016A84
    if (ctx->r7 != ctx->r4) {
        // andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
        goto L_80016A84;
    }
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79D9($v1)
    ctx->r3 = MEM_BU(0X79D9, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80016C38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_80016A84:
    // lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // lbu         $a2, 0x79E6($a2)
    ctx->r6 = MEM_BU(0X79E6, ctx->r6);
    // nop

    // bne         $a2, $a0, L_80016AAC
    if (ctx->r6 != ctx->r4) {
        // andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
        goto L_80016AAC;
    }
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79DA($v1)
    ctx->r3 = MEM_BU(0X79DA, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80016C38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_80016AAC:
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lbu         $a1, 0x79E7($a1)
    ctx->r5 = MEM_BU(0X79E7, ctx->r5);
    // nop

    // bne         $a1, $a0, L_80016AD4
    if (ctx->r5 != ctx->r4) {
        // andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
        goto L_80016AD4;
    }
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79DB($v1)
    ctx->r3 = MEM_BU(0X79DB, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80016C38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_80016AD4:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E8($v1)
    ctx->r3 = MEM_BU(0X79E8, ctx->r3);
    // nop

    // bne         $v1, $a0, L_80016AFC
    if (ctx->r3 != ctx->r4) {
        // nop
    
        goto L_80016AFC;
    }
    // nop

    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79DC($v0)
    ctx->r2 = MEM_BU(0X79DC, ctx->r2);
    // nop

    // beq         $v0, $s2, L_80016C38
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80016C38;
    }
    // nop

L_80016AFC:
    // beq         $t0, $a0, L_80016B0C
    if (ctx->r8 == ctx->r4) {
        // andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
        goto L_80016B0C;
    }
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // beq         $v0, $a0, L_80016B4C
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80016B4C;
    }
    // nop

L_80016B0C:
    // beq         $a3, $a0, L_80016B1C
    if (ctx->r7 == ctx->r4) {
        // andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
        goto L_80016B1C;
    }
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // beq         $v0, $a0, L_80016B4C
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80016B4C;
    }
    // nop

L_80016B1C:
    // beq         $a2, $a0, L_80016B2C
    if (ctx->r6 == ctx->r4) {
        // andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
        goto L_80016B2C;
    }
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // beq         $v0, $a0, L_80016B4C
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80016B4C;
    }
    // nop

L_80016B2C:
    // beq         $a1, $a0, L_80016B3C
    if (ctx->r5 == ctx->r4) {
        // andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
        goto L_80016B3C;
    }
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // beq         $v0, $a0, L_80016B4C
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80016B4C;
    }
    // nop

L_80016B3C:
    // beq         $v1, $a0, L_80016B8C
    if (ctx->r3 == ctx->r4) {
        // ori         $s0, $zero, 0xF0
        ctx->r16 = 0 | 0XF0;
        goto L_80016B8C;
    }
    // ori         $s0, $zero, 0xF0
    ctx->r16 = 0 | 0XF0;
    // bne         $s2, $a0, L_80016B8C
    if (ctx->r18 != ctx->r4) {
        // nop
    
        goto L_80016B8C;
    }
    // nop

L_80016B4C:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80016BC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80016BC0;
    }
    // nop

L_80016B60:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80016BC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80016BC0;
    }
    // nop

    // j           L_80016B60
    // nop

    goto L_80016B60;
    // nop

L_80016B8C:
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D6($v0)
    ctx->r2 = MEM_H(0X79D6, ctx->r2);
    // nop

    // bne         $v0, $s0, L_80016BC0
    if (ctx->r2 != ctx->r16) {
        // nop
    
        goto L_80016BC0;
    }
    // nop

    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_80016B8C
    // nop

    goto L_80016B8C;
    // nop

L_80016BC0:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E9($v0)
    ctx->r2 = MEM_BU(0X79E9, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800168F4
    if (ctx->r2 == 0) {
        // andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
        goto L_800168F4;
    }
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_800168F4
    if (ctx->r4 == ctx->r2) {
        // sll         $v0, $s7, 24
        ctx->r2 = S32(ctx->r23) << 24;
        goto L_800168F4;
    }
    // sll         $v0, $s7, 24
    ctx->r2 = S32(ctx->r23) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // ori         $v1, $zero, 0x7F
    ctx->r3 = 0 | 0X7F;
    // bne         $v0, $v1, L_800168F4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800168F4;
    }
    // nop

    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E4($v0)
    ctx->r2 = MEM_BU(0X79E4, ctx->r2);
    // nop

    // beq         $v0, $a0, L_800168F4
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_800168F4;
    }
    // nop

    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79EB($v0)
    ctx->r2 = MEM_BU(0X79EB, ctx->r2);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79EC($v1)
    ctx->r3 = MEM_BU(0X79EC, ctx->r3);
    // negu        $s7, $v0
    ctx->r23 = SUB32(0, ctx->r2);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79ED($v0)
    ctx->r2 = MEM_BU(0X79ED, ctx->r2);
    // negu        $fp, $v1
    ctx->r30 = SUB32(0, ctx->r3);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_800168F4
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    goto L_800168F4;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
L_80016C38:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
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
