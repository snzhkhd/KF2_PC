#include "recomp.h"
#include "disable_warnings.h"

void sub_8003CD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // lhu         $t1, 0xDC($sp)
    ctx->r9 = MEM_HU(0XDC, ctx->r29);
    // lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(0X100, ctx->r29);
    // lhu         $a0, 0xD8($sp)
    ctx->r4 = MEM_HU(0XD8, ctx->r29);
    // sh          $t1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xE0($sp)
    ctx->r9 = MEM_HU(0XE0, ctx->r29);
    // nop

    // sh          $t1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xE4($sp)
    ctx->r9 = MEM_HU(0XE4, ctx->r29);
    // nop

    // sh          $t1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xE8($sp)
    ctx->r9 = MEM_HU(0XE8, ctx->r29);
    // nop

    // sh          $t1, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xEC($sp)
    ctx->r9 = MEM_HU(0XEC, ctx->r29);
    // nop

    // sh          $t1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xF0($sp)
    ctx->r9 = MEM_HU(0XF0, ctx->r29);
    // nop

    // sh          $t1, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xF4($sp)
    ctx->r9 = MEM_HU(0XF4, ctx->r29);
    // sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // sh          $t1, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xF8($sp)
    ctx->r9 = MEM_HU(0XF8, ctx->r29);
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r22;
    // sh          $t1, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xFC($sp)
    ctx->r9 = MEM_HU(0XFC, ctx->r29);
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $ra, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r31;
    // sw          $fp, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r30;
    // sw          $s7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r23;
    // sw          $s5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r21;
    // sw          $s4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r20;
    // sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // sh          $t1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x104($sp)
    ctx->r9 = MEM_HU(0X104, ctx->r29);
    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // beq         $v0, $zero, L_8003CE54
    if (ctx->r2 == 0) {
        // sh          $t1, 0x88($sp)
        MEM_H(0X88, ctx->r29) = ctx->r9;
        goto L_8003CE54;
    }
    // sh          $t1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r9;
    // sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
L_8003CE54:
    // andi        $s7, $v1, 0x7FFF
    ctx->r23 = ctx->r3 & 0X7FFF;
    // lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // addiu       $s4, $s4, -0x19F8
    ctx->r20 = ADD32(ctx->r20, -0X19F8);
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // andi        $fp, $a0, 0xFFFF
    ctx->r30 = ctx->r4 & 0XFFFF;
    // ori         $t1, $zero, 0x1000
    ctx->r9 = 0 | 0X1000;
    // subu        $t1, $t1, $fp
    ctx->r9 = SUB32(ctx->r9, ctx->r30);
    // sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
    // addiu       $s0, $s4, 0x1E
    ctx->r16 = ADD32(ctx->r20, 0X1E);
    // addiu       $s2, $s4, 0x2C
    ctx->r18 = ADD32(ctx->r20, 0X2C);
L_8003CE7C:
    // lbu         $v1, -0x15($s0)
    ctx->r3 = MEM_BU(-0X15, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8003D03C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $s5, 0x1
        ctx->r2 = ADD32(ctx->r21, 0X1);
        goto L_8003D03C;
    }
    // addiu       $v0, $s5, 0x1
    ctx->r2 = ADD32(ctx->r21, 0X1);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79B4($v0)
    ctx->r2 = MEM_W(0X79B4, ctx->r2);
    // nop

    // beq         $s4, $v0, L_8003D03C
    if (ctx->r20 == ctx->r2) {
        // addiu       $v0, $s5, 0x1
        ctx->r2 = ADD32(ctx->r21, 0X1);
        goto L_8003D03C;
    }
    // addiu       $v0, $s5, 0x1
    ctx->r2 = ADD32(ctx->r21, 0X1);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // bne         $s6, $v0, L_8003CEC8
    if (ctx->r22 != ctx->r2) {
        // ori         $v0, $zero, 0x8001
        ctx->r2 = 0 | 0X8001;
        goto L_8003CEC8;
    }
    // ori         $v0, $zero, 0x8001
    ctx->r2 = 0 | 0X8001;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // lhu         $a3, -0x2($s0)
    ctx->r7 = MEM_HU(-0X2, ctx->r16);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // j           L_8003CF00
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    goto L_8003CF00;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8003CEC8:
    // bne         $s6, $v0, L_8003CF10
    if (ctx->r22 != ctx->r2) {
        // nop
    
        goto L_8003CF10;
    }
    // nop

    // lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(0X0, ctx->r16);
    // lw          $v0, 0x12($s0)
    ctx->r2 = MEM_W(0X12, ctx->r16);
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8003CF48
    if (ctx->r3 != 0) {
        // lui         $v1, 0xFF67
        ctx->r3 = S32(0XFF67 << 16);
        goto L_8003CF48;
    }
    // lui         $v1, 0xFF67
    ctx->r3 = S32(0XFF67 << 16);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // lhu         $a3, -0x2($s0)
    ctx->r7 = MEM_HU(-0X2, ctx->r16);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_8003CF00:
    // jal         0x80015B74
    // nop

    sub_80015B74(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8003CF4C
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    goto L_8003CF4C;
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8003CF10:
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(0X4, ctx->r17);
    // lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(0X8, ctx->r17);
    // jal         0x80015A88
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    GetDistanceIfInRange(rdram, ctx);
    goto after_1;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8003CF4C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003CF4C;
    }
    // nop

    // lui         $v1, 0xFF67
    ctx->r3 = S32(0XFF67 << 16);
L_8003CF48:
    // ori         $v1, $v1, 0x6981
    ctx->r3 = ctx->r3 | 0X6981;
L_8003CF4C:
    // lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(0X38, ctx->r29);
    // nop

    // slt         $v0, $v1, $t1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // bne         $v0, $zero, L_8003D038
    if (ctx->r2 != 0) {
        // ori         $t1, $zero, 0x1000
        ctx->r9 = 0 | 0X1000;
        goto L_8003D038;
    }
    // ori         $t1, $zero, 0x1000
    ctx->r9 = 0 | 0X1000;
    // beq         $fp, $t1, L_8003CFC4
    if (ctx->r30 == ctx->r9) {
        // sll         $v0, $v1, 12
        ctx->r2 = S32(ctx->r3) << 12;
        goto L_8003CFC4;
    }
    // sll         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) << 12;
    // div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // bne         $s3, $zero, L_8003CF78
    if (ctx->r19 != 0) {
        // nop
    
        goto L_8003CF78;
    }
    // nop

    // break       7
    do_break(2147733364);
L_8003CF78:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s3, $at, L_8003CF90
    if (ctx->r19 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003CF90;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003CF90
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003CF90;
    }
    // nop

    // break       6
    do_break(2147733388);
L_8003CF90:
    // mflo        $v0
    ctx->r2 = lo;
    // lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(0X98, ctx->r29);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // mult        $v0, $t1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $t1, $zero, 0x1000
    ctx->r9 = 0 | 0X1000;
    // mflo        $v0
    ctx->r2 = lo;
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // mult        $s7, $v0
    result = S64(S32(ctx->r23)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8003CFC8
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    goto L_8003CFC8;
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
L_8003CFC4:
    // addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
L_8003CFC8:
    // lhu         $t1, 0x58($sp)
    ctx->r9 = MEM_HU(0X58, ctx->r29);
    // lhu         $a1, 0x40($sp)
    ctx->r5 = MEM_HU(0X40, ctx->r29);
    // lhu         $a2, 0x48($sp)
    ctx->r6 = MEM_HU(0X48, ctx->r29);
    // lhu         $a3, 0x50($sp)
    ctx->r7 = MEM_HU(0X50, ctx->r29);
    // sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x60($sp)
    ctx->r9 = MEM_HU(0X60, ctx->r29);
    // nop

    // sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x68($sp)
    ctx->r9 = MEM_HU(0X68, ctx->r29);
    // nop

    // sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x70($sp)
    ctx->r9 = MEM_HU(0X70, ctx->r29);
    // nop

    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x78($sp)
    ctx->r9 = MEM_HU(0X78, ctx->r29);
    // nop

    // sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x80($sp)
    ctx->r9 = MEM_HU(0X80, ctx->r29);
    // nop

    // sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x88($sp)
    ctx->r9 = MEM_HU(0X88, ctx->r29);
    // andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    // sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(0X90, ctx->r29);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // jal         0x8003C718
    // sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    ApplyDamage(rdram, ctx);
    goto after_2;
    // sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_2:
L_8003D038:
    // addiu       $v0, $s5, 0x1
    ctx->r2 = ADD32(ctx->r21, 0X1);
L_8003D03C:
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // addiu       $s2, $s2, 0x7C
    ctx->r18 = ADD32(ctx->r18, 0X7C);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xC8
    ctx->r2 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // bne         $v0, $zero, L_8003CE7C
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x7C
        ctx->r20 = ADD32(ctx->r20, 0X7C);
        goto L_8003CE7C;
    }
    // addiu       $s4, $s4, 0x7C
    ctx->r20 = ADD32(ctx->r20, 0X7C);
    // lw          $ra, 0xC4($sp)
    ctx->r31 = MEM_W(0XC4, ctx->r29);
    // lw          $fp, 0xC0($sp)
    ctx->r30 = MEM_W(0XC0, ctx->r29);
    // lw          $s7, 0xBC($sp)
    ctx->r23 = MEM_W(0XBC, ctx->r29);
    // lw          $s6, 0xB8($sp)
    ctx->r22 = MEM_W(0XB8, ctx->r29);
    // lw          $s5, 0xB4($sp)
    ctx->r21 = MEM_W(0XB4, ctx->r29);
    // lw          $s4, 0xB0($sp)
    ctx->r20 = MEM_W(0XB0, ctx->r29);
    // lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(0XAC, ctx->r29);
    // lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(0XA8, ctx->r29);
    // lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(0XA4, ctx->r29);
    // lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(0XA0, ctx->r29);
    // addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // jr          $ra
    // nop

    return;
    // nop

;}
