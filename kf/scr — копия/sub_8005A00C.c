#include "recomp.h"
#include "disable_warnings.h"

void sub_8005A00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5) >> 16;
    // sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $s3, $a0, 16
    ctx->r19 = S32(ctx->r4) >> 16;
    // sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(0X4, ctx->r17);
    // nop

    // addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lbu         $s0, 0x0($a3)
    ctx->r16 = MEM_BU(0X0, ctx->r7);
    // nop

    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8005A1B4
    if (ctx->r2 == 0) {
        // andi        $a0, $s0, 0xF
        ctx->r4 = ctx->r16 & 0XF;
        goto L_8005A1B4;
    }
    // andi        $a0, $s0, 0xF
    ctx->r4 = ctx->r16 & 0XF;
    // andi        $a2, $s0, 0xF0
    ctx->r6 = ctx->r16 & 0XF0;
    // ori         $v0, $zero, 0xC0
    ctx->r2 = 0 | 0XC0;
    // beq         $a2, $v0, L_8005A134
    if (ctx->r6 == ctx->r2) {
        // sb          $a0, 0x12($s1)
        MEM_B(0X12, ctx->r17) = ctx->r4;
        goto L_8005A134;
    }
    // sb          $a0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r4;
    // slti        $v0, $a2, 0xC1
    ctx->r2 = SIGNED(ctx->r6) < 0XC1 ? 1 : 0;
    // beq         $v0, $zero, L_8005A0C4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x90
        ctx->r2 = 0 | 0X90;
        goto L_8005A0C4;
    }
    // ori         $v0, $zero, 0x90
    ctx->r2 = 0 | 0X90;
    // beq         $a2, $v0, L_8005A0E0
    if (ctx->r6 == ctx->r2) {
        // ori         $v0, $zero, 0xB0
        ctx->r2 = 0 | 0XB0;
        goto L_8005A0E0;
    }
    // ori         $v0, $zero, 0xB0
    ctx->r2 = 0 | 0XB0;
    // beq         $a2, $v0, L_8005A10C
    if (ctx->r6 == ctx->r2) {
        // ori         $v1, $zero, 0xB0
        ctx->r3 = 0 | 0XB0;
        goto L_8005A10C;
    }
    // ori         $v1, $zero, 0xB0
    ctx->r3 = 0 | 0XB0;
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A0C4:
    // ori         $v0, $zero, 0xE0
    ctx->r2 = 0 | 0XE0;
    // beq         $a2, $v0, L_8005A160
    if (ctx->r6 == ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_8005A160;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // beq         $a2, $v0, L_8005A188
    if (ctx->r6 == ctx->r2) {
        // ori         $v1, $zero, 0xFF
        ctx->r3 = 0 | 0XFF;
        goto L_8005A188;
    }
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A0E0:
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // ori         $v0, $zero, 0x90
    ctx->r2 = 0 | 0X90;
    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lbu         $s0, 0x0($v1)
    ctx->r16 = MEM_BU(0X0, ctx->r3);
    // addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lbu         $s4, 0x1($v1)
    ctx->r20 = MEM_BU(0X1, ctx->r3);
    // j           L_8005A210
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    goto L_8005A210;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8005A10C:
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // sb          $v1, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r3;
    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(0X0, ctx->r2);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8005A400
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_8005A400(rdram, ctx);
    goto after_0;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A134:
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // ori         $v1, $zero, 0xC0
    ctx->r3 = 0 | 0XC0;
    // sb          $v1, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r3;
    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(0X0, ctx->r2);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8005A388
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_8005A388(rdram, ctx);
    goto after_1;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A160:
    // ori         $v0, $zero, 0xE0
    ctx->r2 = 0 | 0XE0;
    // sb          $v0, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8005B73C
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    sub_8005B73C(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    after_2:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A188:
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // sb          $v1, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r3;
    // sb          $a0, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r4;
    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(0X0, ctx->r2);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8005B7E8
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_8005B7E8(rdram, ctx);
    goto after_3;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A1B4:
    // lbu         $v1, 0x11($s1)
    ctx->r3 = MEM_BU(0X11, ctx->r17);
    // ori         $v0, $zero, 0xC0
    ctx->r2 = 0 | 0XC0;
    // beq         $v1, $v0, L_8005A24C
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0xC1
        ctx->r2 = SIGNED(ctx->r3) < 0XC1 ? 1 : 0;
        goto L_8005A24C;
    }
    // slti        $v0, $v1, 0xC1
    ctx->r2 = SIGNED(ctx->r3) < 0XC1 ? 1 : 0;
    // beq         $v0, $zero, L_8005A1E4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x90
        ctx->r2 = 0 | 0X90;
        goto L_8005A1E4;
    }
    // ori         $v0, $zero, 0x90
    ctx->r2 = 0 | 0X90;
    // beq         $v1, $v0, L_8005A200
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xB0
        ctx->r2 = 0 | 0XB0;
        goto L_8005A200;
    }
    // ori         $v0, $zero, 0xB0
    ctx->r2 = 0 | 0XB0;
    // beq         $v1, $v0, L_8005A238
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8005A238;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A1E4:
    // ori         $v0, $zero, 0xE0
    ctx->r2 = 0 | 0XE0;
    // beq         $v1, $v0, L_8005A264
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8005A264;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8005A278
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8005A278;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A200:
    // addiu       $v0, $a3, 0x2
    ctx->r2 = ADD32(ctx->r7, 0X2);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lbu         $s4, 0x1($a3)
    ctx->r20 = MEM_BU(0X1, ctx->r7);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8005A210:
    // jal         0x8005BB50
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_8005BB50(rdram, ctx);
    goto after_4;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005A2A4
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    sub_8005A2A4(rdram, ctx);
    goto after_5;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_5:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A238:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8005A400
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8005A400(rdram, ctx);
    goto after_6;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A24C:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8005A388
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8005A388(rdram, ctx);
    goto after_7;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_7:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A264:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8005B73C
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_8005B73C(rdram, ctx);
    goto after_8;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_8:
    // j           L_8005A284
    // nop

    goto L_8005A284;
    // nop

L_8005A278:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8005B7E8
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8005B7E8(rdram, ctx);
    goto after_9;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_9:
L_8005A284:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
