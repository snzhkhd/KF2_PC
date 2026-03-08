#include "recomp.h"
#include "disable_warnings.h"

void sub_8005AEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // sw          $ra, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r31;
    // sw          $fp, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r30;
    // sw          $s7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r23;
    // sw          $s6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r22;
    // sw          $s5, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r21;
    // sw          $s4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r20;
    // sw          $s3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r19;
    // sw          $s2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r18;
    // sw          $s1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r17;
    // sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
    // sra         $s2, $v1, 16
    ctx->r18 = S32(ctx->r3) >> 16;
    // sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lbu         $s6, 0x12($s1)
    ctx->r22 = MEM_BU(0X12, ctx->r17);
    // addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // addu        $v0, $s6, $s1
    ctx->r2 = ADD32(ctx->r22, ctx->r17);
    // lbu         $a1, 0x2C($v0)
    ctx->r5 = MEM_BU(0X2C, ctx->r2);
    // addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // jal         0x8005C214
    // addu        $fp, $t0, $zero
    ctx->r30 = ADD32(ctx->r8, 0);
    sub_8005C214(rdram, ctx);
    goto after_0;
    // addu        $fp, $t0, $zero
    ctx->r30 = ADD32(ctx->r8, 0);
    after_0:
    // lbu         $v1, 0x27($s1)
    ctx->r3 = MEM_BU(0X27, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8005AFB8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005AFB8;
    }
    // nop

    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005AFB8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005AFB8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $s5, 0x28($s1)
    MEM_B(0X28, ctx->r17) = ctx->r21;
    // sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005BB50
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005BB50(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // j           L_8005B438
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    goto L_8005B438;
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
L_8005AFB8:
    // lbu         $v0, 0x29($s1)
    ctx->r2 = MEM_BU(0X29, ctx->r17);
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // bne         $v0, $v1, L_8005B1DC
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8005B1DC;
    }
    // nop

    // lbu         $v0, 0x13($s1)
    ctx->r2 = MEM_BU(0X13, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005B048
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B048;
    }
    // nop

    // lbu         $v0, 0x14($s1)
    ctx->r2 = MEM_BU(0X14, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005B048
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B048;
    }
    // nop

    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // nop

    // blez        $v0, L_8005B048
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8005B048;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s3, $s6, $s1
    ctx->r19 = ADD32(ctx->r22, ctx->r17);
    // addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
L_8005B000:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s3)
    ctx->r5 = MEM_BU(0X2C, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BCF4
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8005BCF4(rdram, ctx);
    goto after_2;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_2:
    // andi        $v0, $s5, 0x7F
    ctx->r2 = ctx->r21 & 0X7F;
    // sb          $v0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r2;
    // sb          $v0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r2;
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s3)
    ctx->r5 = MEM_BU(0X2C, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BF30
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8005BF30(rdram, ctx);
    goto after_3;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_3:
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005B000
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B000;
    }
    // nop

L_8005B048:
    // lbu         $v1, 0x13($s1)
    ctx->r3 = MEM_BU(0X13, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8005B114
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8005B114;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lbu         $v0, 0x14($s1)
    ctx->r2 = MEM_BU(0X14, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005B114
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8005B114;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // addiu       $v0, $s5, -0x41
    ctx->r2 = ADD32(ctx->r21, -0X41);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 < 0X3F ? 1 : 0;
    // beq         $v0, $zero, L_8005B0A8
    if (ctx->r2 == 0) {
        // andi        $v1, $s5, 0xFF
        ctx->r3 = ctx->r21 & 0XFF;
        goto L_8005B0A8;
    }
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // bgez        $v0, L_8005B0AC
    if (SIGNED(ctx->r2) >= 0) {
        // andi        $s4, $v0, 0xE000
        ctx->r20 = ctx->r2 & 0XE000;
        goto L_8005B0AC;
    }
    // andi        $s4, $v0, 0xE000
    ctx->r20 = ctx->r2 & 0XE000;
    // addiu       $v0, $v0, 0x1FFF
    ctx->r2 = ADD32(ctx->r2, 0X1FFF);
    // j           L_8005B0AC
    // andi        $s4, $v0, 0xE000
    ctx->r20 = ctx->r2 & 0XE000;
    goto L_8005B0AC;
    // andi        $s4, $v0, 0xE000
    ctx->r20 = ctx->r2 & 0XE000;
L_8005B0A8:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8005B0AC:
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // nop

    // blez        $v0, L_8005B10C
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8005B10C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s3, $s6, $s1
    ctx->r19 = ADD32(ctx->r22, ctx->r17);
    // addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
L_8005B0C4:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s3)
    ctx->r5 = MEM_BU(0X2C, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BCF4
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8005BCF4(rdram, ctx);
    goto after_4;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_4:
    // lbu         $v0, 0x5D($sp)
    ctx->r2 = MEM_BU(0X5D, ctx->r29);
    // nop

    // sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s3)
    ctx->r5 = MEM_BU(0X2C, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BF30
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8005BF30(rdram, ctx);
    goto after_5;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_5:
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005B0C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B0C4;
    }
    // nop

L_8005B10C:
    // lbu         $v1, 0x13($s1)
    ctx->r3 = MEM_BU(0X13, ctx->r17);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8005B114:
    // bne         $v1, $v0, L_8005B1C0
    if (ctx->r3 != ctx->r2) {
        // sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23) << 16;
        goto L_8005B1C0;
    }
    // sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23) << 16;
    // lbu         $v0, 0x14($s1)
    ctx->r2 = MEM_BU(0X14, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005B1C4
    if (ctx->r2 != 0) {
        // sra         $a0, $a0, 16
        ctx->r4 = S32(ctx->r4) >> 16;
        goto L_8005B1C4;
    }
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $v0, $s5, -0x40
    ctx->r2 = ADD32(ctx->r21, -0X40);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8005B158
    if (ctx->r2 == 0) {
        // andi        $v1, $s5, 0xFF
        ctx->r3 = ctx->r21 & 0XFF;
        goto L_8005B158;
    }
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8005B15C
    // sll         $s4, $v0, 8
    ctx->r20 = S32(ctx->r2) << 8;
    goto L_8005B15C;
    // sll         $s4, $v0, 8
    ctx->r20 = S32(ctx->r2) << 8;
L_8005B158:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8005B15C:
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // nop

    // blez        $v0, L_8005B1BC
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8005B1BC;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s3, $s6, $s1
    ctx->r19 = ADD32(ctx->r22, ctx->r17);
    // addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
L_8005B174:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s3)
    ctx->r5 = MEM_BU(0X2C, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BCF4
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8005BCF4(rdram, ctx);
    goto after_6;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_6:
    // lbu         $v0, 0x5C($sp)
    ctx->r2 = MEM_BU(0X5C, ctx->r29);
    // nop

    // sb          $v0, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r2;
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s3)
    ctx->r5 = MEM_BU(0X2C, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BF30
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8005BF30(rdram, ctx);
    goto after_7;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_7:
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005B174
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B174;
    }
    // nop

L_8005B1BC:
    // sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23) << 16;
L_8005B1C0:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
L_8005B1C4:
    // sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_8;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_8:
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    // j           L_8005B438
    // sb          $zero, 0x29($s1)
    MEM_B(0X29, ctx->r17) = 0;
    goto L_8005B438;
    // sb          $zero, 0x29($s1)
    MEM_B(0X29, ctx->r17) = 0;
L_8005B1DC:
    // lbu         $v0, 0x2A($s1)
    ctx->r2 = MEM_BU(0X2A, ctx->r17);
    // nop

    // bne         $v0, $v1, L_8005B424
    if (ctx->r2 != ctx->r3) {
        // sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23) << 16;
        goto L_8005B424;
    }
    // sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23) << 16;
    // lbu         $t0, 0x16($s1)
    ctx->r8 = MEM_BU(0X16, ctx->r17);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // bne         $t0, $v0, L_8005B318
    if (ctx->r8 != ctx->r2) {
        // addu        $v0, $s6, $s1
        ctx->r2 = ADD32(ctx->r22, ctx->r17);
        goto L_8005B318;
    }
    // addu        $v0, $s6, $s1
    ctx->r2 = ADD32(ctx->r22, ctx->r17);
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // nop

    // blez        $v0, L_8005B408
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8005B408;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s2, $s6, $s1
    ctx->r18 = ADD32(ctx->r22, ctx->r17);
L_8005B210:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s2)
    ctx->r5 = MEM_BU(0X2C, ctx->r18);
    // lwl         $v0, 0x7B($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X7B, ctx->r29);
    // lwr         $v0, 0x78($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X78, ctx->r29);
    // lwl         $v1, 0x7F($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7F, ctx->r29);
    // lwr         $v1, 0x7C($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X7C, ctx->r29);
    // lwl         $a2, 0x83($sp)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X83, ctx->r29);
    // lwr         $a2, 0x80($sp)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X80, ctx->r29);
    // lwl         $a3, 0x87($sp)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X87, ctx->r29);
    // lwr         $a3, 0x84($sp)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X84, ctx->r29);
    // swl         $v0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r2);
    // swr         $v0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r2);
    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // swl         $a2, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r6);
    // swr         $a2, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r6);
    // swl         $a3, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r7);
    // swr         $a3, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r7);
    // lh          $v0, 0x88($sp)
    ctx->r2 = MEM_H(0X88, ctx->r29);
    // nop

    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x15($s1)
    ctx->r3 = MEM_BU(0X15, ctx->r17);
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // lhu         $t2, 0x58($sp)
    ctx->r10 = MEM_HU(0X58, ctx->r29);
    // lhu         $a3, 0x5A($sp)
    ctx->r7 = MEM_HU(0X5A, ctx->r29);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lwl         $v0, 0x5F($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X5F, ctx->r29);
    // lwr         $v0, 0x5C($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X5C, ctx->r29);
    // lwl         $v1, 0x63($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X63, ctx->r29);
    // lwr         $v1, 0x60($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X60, ctx->r29);
    // lwl         $t0, 0x67($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X67, ctx->r29);
    // lwr         $t0, 0x64($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X64, ctx->r29);
    // lwl         $t1, 0x6B($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0X6B, ctx->r29);
    // lwr         $t1, 0x68($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0X68, ctx->r29);
    // swl         $v0, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
    // swr         $v0, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
    // swl         $v1, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r3);
    // swr         $v1, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r3);
    // swl         $t0, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r8);
    // swr         $t0, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r8);
    // swl         $t1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r9);
    // swr         $t1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r9);
    // lwl         $v0, 0x6F($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X6F, ctx->r29);
    // lwr         $v0, 0x6C($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X6C, ctx->r29);
    // lwl         $v1, 0x73($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X73, ctx->r29);
    // lwr         $v1, 0x70($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X70, ctx->r29);
    // lwl         $t0, 0x77($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X77, ctx->r29);
    // lwr         $t0, 0x74($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X74, ctx->r29);
    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // swl         $v1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r3);
    // swr         $v1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r3);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // jal         0x8005B468
    // or          $a3, $t2, $a3
    ctx->r7 = ctx->r10 | ctx->r7;
    sub_8005B468(rdram, ctx);
    goto after_9;
    // or          $a3, $t2, $a3
    ctx->r7 = ctx->r10 | ctx->r7;
    after_9:
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005B210
    if (ctx->r2 != 0) {
        // sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23) << 16;
        goto L_8005B210;
    }
    // sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23) << 16;
    // j           L_8005B408
    // nop

    goto L_8005B408;
    // nop

L_8005B318:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($v0)
    ctx->r5 = MEM_BU(0X2C, ctx->r2);
    // lwl         $v0, 0x7B($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X7B, ctx->r29);
    // lwr         $v0, 0x78($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X78, ctx->r29);
    // lwl         $v1, 0x7F($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7F, ctx->r29);
    // lwr         $v1, 0x7C($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X7C, ctx->r29);
    // lwl         $a2, 0x83($sp)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X83, ctx->r29);
    // lwr         $a2, 0x80($sp)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X80, ctx->r29);
    // lwl         $a3, 0x87($sp)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X87, ctx->r29);
    // lwr         $a3, 0x84($sp)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X84, ctx->r29);
    // swl         $v0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r2);
    // swr         $v0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r2);
    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // swl         $a2, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r6);
    // swr         $a2, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r6);
    // swl         $a3, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r7);
    // swr         $a3, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r7);
    // lh          $v0, 0x88($sp)
    ctx->r2 = MEM_H(0X88, ctx->r29);
    // nop

    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x15($s1)
    ctx->r3 = MEM_BU(0X15, ctx->r17);
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // lhu         $t2, 0x58($sp)
    ctx->r10 = MEM_HU(0X58, ctx->r29);
    // lhu         $a3, 0x5A($sp)
    ctx->r7 = MEM_HU(0X5A, ctx->r29);
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // lwl         $v0, 0x5F($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X5F, ctx->r29);
    // lwr         $v0, 0x5C($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X5C, ctx->r29);
    // lwl         $v1, 0x63($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X63, ctx->r29);
    // lwr         $v1, 0x60($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X60, ctx->r29);
    // lwl         $t0, 0x67($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X67, ctx->r29);
    // lwr         $t0, 0x64($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X64, ctx->r29);
    // lwl         $t1, 0x6B($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0X6B, ctx->r29);
    // lwr         $t1, 0x68($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0X68, ctx->r29);
    // swl         $v0, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
    // swr         $v0, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
    // swl         $v1, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r3);
    // swr         $v1, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r3);
    // swl         $t0, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r8);
    // swr         $t0, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r8);
    // swl         $t1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r9);
    // swr         $t1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r9);
    // lwl         $v0, 0x6F($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X6F, ctx->r29);
    // lwr         $v0, 0x6C($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X6C, ctx->r29);
    // lwl         $v1, 0x73($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X73, ctx->r29);
    // lwr         $v1, 0x70($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X70, ctx->r29);
    // lwl         $t0, 0x77($sp)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X77, ctx->r29);
    // lwr         $t0, 0x74($sp)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X74, ctx->r29);
    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // swl         $v1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r3);
    // swr         $v1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r3);
    // swl         $t0, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r8);
    // swr         $t0, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r8);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // jal         0x8005B468
    // or          $a3, $t2, $a3
    ctx->r7 = ctx->r10 | ctx->r7;
    sub_8005B468(rdram, ctx);
    goto after_10;
    // or          $a3, $t2, $a3
    ctx->r7 = ctx->r10 | ctx->r7;
    after_10:
    // sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23) << 16;
L_8005B408:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_11;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_11:
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    // j           L_8005B438
    // sb          $zero, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = 0;
    goto L_8005B438;
    // sb          $zero, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = 0;
L_8005B424:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_12;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_12:
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
L_8005B438:
    // lw          $ra, 0xF4($sp)
    ctx->r31 = MEM_W(0XF4, ctx->r29);
    // lw          $fp, 0xF0($sp)
    ctx->r30 = MEM_W(0XF0, ctx->r29);
    // lw          $s7, 0xEC($sp)
    ctx->r23 = MEM_W(0XEC, ctx->r29);
    // lw          $s6, 0xE8($sp)
    ctx->r22 = MEM_W(0XE8, ctx->r29);
    // lw          $s5, 0xE4($sp)
    ctx->r21 = MEM_W(0XE4, ctx->r29);
    // lw          $s4, 0xE0($sp)
    ctx->r20 = MEM_W(0XE0, ctx->r29);
    // lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(0XDC, ctx->r29);
    // lw          $s2, 0xD8($sp)
    ctx->r18 = MEM_W(0XD8, ctx->r29);
    // lw          $s1, 0xD4($sp)
    ctx->r17 = MEM_W(0XD4, ctx->r29);
    // lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(0XD0, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
