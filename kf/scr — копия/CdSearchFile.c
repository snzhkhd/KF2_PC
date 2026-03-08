#include "recomp.h"
#include "disable_warnings.h"

void KF_CdSearchFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x848($v1)
    ctx->r3 = MEM_W(-0X848, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB70($v0)
    ctx->r2 = MEM_W(-0XB70, ctx->r2);
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // beq         $v1, $v0, L_8004F50C
    if (ctx->r3 == ctx->r2) {
        // sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
        goto L_8004F50C;
    }
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // jal         0x8004F7B8
    // nop

    CdCheckISO9660(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_8004F76C
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004F76C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB70($v0)
    ctx->r2 = MEM_W(-0XB70, ctx->r2);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x848($at)
    MEM_W(-0X848, ctx->r1) = ctx->r2;
L_8004F50C:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // ori         $v0, $zero, 0x5C
    ctx->r2 = 0 | 0X5C;
    // beq         $v1, $v0, L_8004F52C
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_8004F52C;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // j           L_8004F76C
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004F76C;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004F524:
    // j           L_8004F5BC
    // sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    goto L_8004F5BC;
    // sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
L_8004F52C:
    // sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    // addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // ori         $s4, $zero, 0x5C
    ctx->r20 = 0 | 0X5C;
L_8004F53C:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $s4, L_8004F580
    if (ctx->r2 == ctx->r20) {
        // addiu       $s1, $sp, 0x10
        ctx->r17 = ADD32(ctx->r29, 0X10);
        goto L_8004F580;
    }
    // addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // ori         $v1, $zero, 0x5C
    ctx->r3 = 0 | 0X5C;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
L_8004F554:
    // nop

    // beq         $v0, $zero, L_8004F5C0
    if (ctx->r2 == 0) {
        // slti        $v0, $s2, 0x8
        ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
        goto L_8004F5C0;
    }
    // slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $v1, L_8004F554
    if (ctx->r2 != ctx->r3) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8004F554;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
L_8004F580:
    // nop

    // beq         $v0, $zero, L_8004F5C0
    if (ctx->r2 == 0) {
        // slti        $v0, $s2, 0x8
        ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
        goto L_8004F5C0;
    }
    // slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // jal         0x8004FAAC
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_8004FAAC(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_8004F524
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8004F524;
    }
    // nop

    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8004F53C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004F53C;
    }
    // nop

L_8004F5BC:
    // slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
L_8004F5C0:
    // bne         $v0, $zero, L_8004F5F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004F5F4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // blez        $v0, L_8004F768
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
        goto L_8004F768;
    }
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2FF8
    ctx->r4 = ADD32(ctx->r4, 0X2FF8);
    // jal         0x80062BA0
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    psx_printf(rdram, ctx);
    goto after_2;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_2:
    // j           L_8004F76C
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004F76C;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004F5F4:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8004F628
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004F628;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // blez        $v0, L_8004F768
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
        goto L_8004F768;
    }
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3014
    ctx->r4 = ADD32(ctx->r4, 0X3014);
    // j           L_8004F760
    // nop

    goto L_8004F760;
    // nop

L_8004F628:
    // jal         0x8004FB58
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    sub_8004FB58(rdram, ctx);
    goto after_3;
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    after_3:
    // bne         $v0, $zero, L_8004F664
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004F664;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // blez        $v0, L_8004F76C
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004F76C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x302C
    ctx->r4 = ADD32(ctx->r4, 0X302C);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8004F76C
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004F76C;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004F664:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004F68C
    if (ctx->r2 != 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8004F68C;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3048
    ctx->r4 = ADD32(ctx->r4, 0X3048);
    // jal         0x80062BA0
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    psx_printf(rdram, ctx);
    goto after_5;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
L_8004F68C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x64BC
    ctx->r2 = ADD32(ctx->r2, 0X64BC);
    // addiu       $s0, $v0, -0x8
    ctx->r16 = ADD32(ctx->r2, -0X8);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8004F6A0:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x64BC
    ctx->r1 = ADD32(ctx->r1, 0X64BC);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8004F744
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8004F744;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8004F794
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_8004F794(rdram, ctx);
    goto after_6;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_6:
    // beq         $v0, $zero, L_8004F72C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004F72C;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004F6F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004F6F4;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3068
    ctx->r4 = ADD32(ctx->r4, 0X3068);
    // jal         0x80062BA0
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    psx_printf(rdram, ctx);
    goto after_7;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_7:
L_8004F6F4:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(0XC, ctx->r16);
    // sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // sw          $v1, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r3;
    // sw          $a0, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r4;
    // sw          $a1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r5;
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(0X14, ctx->r16);
    // sw          $v0, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r2;
    // sw          $v1, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r3;
    // j           L_8004F76C
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_8004F76C;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8004F72C:
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slti        $v0, $s2, 0x40
    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_8004F6A0
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
        goto L_8004F6A0;
    }
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_8004F744:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB7C($v0)
    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
    // nop

    // blez        $v0, L_8004F768
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
        goto L_8004F768;
    }
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3074
    ctx->r4 = ADD32(ctx->r4, 0X3074);
L_8004F760:
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_8004F768:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004F76C:
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
