#include "recomp.h"
#include "disable_warnings.h"

void sub_80019198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // sltiu       $v0, $v0, 0x16
    ctx->r2 = ctx->r2 < 0X16 ? 1 : 0;
    // bne         $v0, $zero, L_80019440
    if (ctx->r2 != 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_80019440;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lw          $v1, 0x48($gp)
    ctx->r3 = MEM_W(0X48, ctx->r28);
    // nop

    // bgez        $v1, L_800191C4
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800191C4;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x1F
    ctx->r2 = ADD32(ctx->r3, 0X1F);
L_800191C4:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // beq         $v1, $v0, L_80019290
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x9
        ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
        goto L_80019290;
    }
    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_800191F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800191F4;
    }
    // nop

    // beq         $v1, $zero, L_80019210
    if (ctx->r3 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80019210;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // j           L_80019440
    // nop

    goto L_80019440;
    // nop

L_800191F4:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_80019314
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x18
        ctx->r2 = 0 | 0X18;
        goto L_80019314;
    }
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // beq         $v1, $v0, L_800193A8
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800193A8;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // j           L_80019440
    // nop

    goto L_80019440;
    // nop

L_80019210:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v1, 0x50($gp)
    ctx->r3 = MEM_HU(0X50, ctx->r28);
    // lhu         $t0, 0x54($gp)
    ctx->r8 = MEM_HU(0X54, ctx->r28);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // jal         0x80063264
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    ClearImageWithCallback(rdram, ctx);
    goto after_0;
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    after_0:
    // lw          $v1, 0x50($gp)
    ctx->r3 = MEM_W(0X50, ctx->r28);
    // nop

    // slti        $v0, $v1, 0x120
    ctx->r2 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
    // beq         $v0, $zero, L_80019278
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80019278;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8001926C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001926C;
    }
    // nop

    // j           L_80019270
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    goto L_80019270;
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_8001926C:
    // addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
L_80019270:
    // sw          $v0, 0x50($gp)
    MEM_W(0X50, ctx->r28) = ctx->r2;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80019278:
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3C0
    ctx->r2 = 0 | 0X3C0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // j           L_8001938C
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    goto L_8001938C;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
L_80019290:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v1, 0x50($gp)
    ctx->r3 = MEM_HU(0X50, ctx->r28);
    // lhu         $t0, 0x54($gp)
    ctx->r8 = MEM_HU(0X54, ctx->r28);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // jal         0x80063264
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    ClearImageWithCallback(rdram, ctx);
    goto after_1;
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    after_1:
    // lw          $v1, 0x50($gp)
    ctx->r3 = MEM_W(0X50, ctx->r28);
    // nop

    // slti        $v0, $v1, 0x120
    ctx->r2 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
    // beq         $v0, $zero, L_800192FC
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800192FC;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_800192F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800192F0;
    }
    // nop

    // j           L_800192F4
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    goto L_800192F4;
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_800192F0:
    // addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
L_800192F4:
    // sw          $v0, 0x50($gp)
    MEM_W(0X50, ctx->r28) = ctx->r2;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800192FC:
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3E0
    ctx->r2 = 0 | 0X3E0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // j           L_8001938C
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    goto L_8001938C;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
L_80019314:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v1, 0x50($gp)
    ctx->r3 = MEM_HU(0X50, ctx->r28);
    // lhu         $t0, 0x54($gp)
    ctx->r8 = MEM_HU(0X54, ctx->r28);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // jal         0x80063264
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    ClearImageWithCallback(rdram, ctx);
    goto after_2;
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    after_2:
    // lw          $v1, 0x50($gp)
    ctx->r3 = MEM_W(0X50, ctx->r28);
    // nop

    // slti        $v0, $v1, 0x120
    ctx->r2 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
    // beq         $v0, $zero, L_80019378
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80019378;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80019370
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
        goto L_80019370;
    }
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
L_80019370:
    // sw          $v0, 0x50($gp)
    MEM_W(0X50, ctx->r28) = ctx->r2;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80019378:
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3C0
    ctx->r2 = 0 | 0X3C0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x120
    ctx->r2 = 0 | 0X120;
L_8001938C:
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x800633C0
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImageWithCallback(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_3:
    // j           L_80019440
    // nop

    goto L_80019440;
    // nop

L_800193A8:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v1, 0x50($gp)
    ctx->r3 = MEM_HU(0X50, ctx->r28);
    // lhu         $t0, 0x54($gp)
    ctx->r8 = MEM_HU(0X54, ctx->r28);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // jal         0x80063264
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    ClearImageWithCallback(rdram, ctx);
    goto after_4;
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    after_4:
    // lw          $v1, 0x50($gp)
    ctx->r3 = MEM_W(0X50, ctx->r28);
    // nop

    // slti        $v0, $v1, 0x120
    ctx->r2 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
    // beq         $v0, $zero, L_80019408
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80019408;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80019400
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
        goto L_80019400;
    }
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
L_80019400:
    // sw          $v0, 0x50($gp)
    MEM_W(0X50, ctx->r28) = ctx->r2;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80019408:
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3E0
    ctx->r2 = 0 | 0X3E0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x120
    ctx->r2 = 0 | 0X120;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x800633C0
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImageWithCallback(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_5:
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x4C($gp)
    MEM_W(0X4C, ctx->r28) = ctx->r2;
L_80019440:
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // addiu       $a3, $v0, -0x5
    ctx->r7 = ADD32(ctx->r2, -0X5);
    // sltiu       $v0, $a3, 0xA
    ctx->r2 = ctx->r7 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_800194C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800194C0;
    }
    // nop

    // lw          $v0, 0x48($gp)
    ctx->r2 = MEM_W(0X48, ctx->r28);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $zero, L_800194C0
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800194C0;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // srl         $v1, $a3, 31
    ctx->r3 = S32(U32(ctx->r7) >> 31);
    // addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addiu       $v0, $v0, 0x3C0
    ctx->r2 = ADD32(ctx->r2, 0X3C0);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // addiu       $v1, $v1, 0x140
    ctx->r3 = ADD32(ctx->r3, 0X140);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x800633C0
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImageWithCallback(rdram, ctx);
    goto after_6;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_6:
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x4C($gp)
    MEM_W(0X4C, ctx->r28) = ctx->r2;
L_800194C0:
    // lw          $v1, 0x4C($gp)
    ctx->r3 = MEM_W(0X4C, ctx->r28);
    // nop

    // addiu       $t0, $v1, -0xE
    ctx->r8 = ADD32(ctx->r3, -0XE);
    // sltiu       $v0, $t0, 0xA
    ctx->r2 = ctx->r8 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_8001959C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x18
        ctx->r2 = 0 | 0X18;
        goto L_8001959C;
    }
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // lw          $v0, 0x48($gp)
    ctx->r2 = MEM_W(0X48, ctx->r28);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // bne         $v0, $zero, L_8001959C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x18
        ctx->r2 = 0 | 0X18;
        goto L_8001959C;
    }
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // beq         $v1, $v0, L_8001953C
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8001953C;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x34
    ctx->r2 = 0 | 0X34;
    // sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8) << 2;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x50($gp)
    ctx->r2 = MEM_HU(0X50, ctx->r28);
    // lhu         $t0, 0x54($gp)
    ctx->r8 = MEM_HU(0X54, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $t0, $t0, -0xA
    ctx->r8 = ADD32(ctx->r8, -0XA);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // jal         0x80063264
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    ClearImageWithCallback(rdram, ctx);
    goto after_7;
    // sh          $t0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r8;
    after_7:
L_8001953C:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3E0
    ctx->r2 = 0 | 0X3E0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1E0
    ctx->r2 = 0 | 0X1E0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // ori         $v1, $zero, 0x20
    ctx->r3 = 0 | 0X20;
    // sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
    // sh          $v1, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, -0xE
    ctx->r2 = ADD32(ctx->r2, -0XE);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // lw          $v0, 0x50($gp)
    ctx->r2 = MEM_W(0X50, ctx->r28);
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // jal         0x800633C0
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    MoveImageWithCallback(rdram, ctx);
    goto after_8;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_8:
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x4C($gp)
    MEM_W(0X4C, ctx->r28) = ctx->r2;
    // lw          $v1, 0x4C($gp)
    ctx->r3 = MEM_W(0X4C, ctx->r28);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
L_8001959C:
    // bne         $v1, $v0, L_800195F8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800195F8;
    }
    // nop

    // lw          $v0, 0x48($gp)
    ctx->r2 = MEM_W(0X48, ctx->r28);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // bne         $v0, $zero, L_800195F8
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800195F8;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v1, 0x54($gp)
    ctx->r3 = MEM_HU(0X54, ctx->r28);
    // ori         $v0, $zero, 0x19
    ctx->r2 = 0 | 0X19;
    // sw          $v0, 0x4C($gp)
    MEM_W(0X4C, ctx->r28) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x48($gp)
    MEM_W(0X48, ctx->r28) = ctx->r2;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // jal         0x80063264
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    ClearImageWithCallback(rdram, ctx);
    goto after_9;
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    after_9:
L_800195F8:
    // lw          $v1, 0x4C($gp)
    ctx->r3 = MEM_W(0X4C, ctx->r28);
    // ori         $v0, $zero, 0x19
    ctx->r2 = 0 | 0X19;
    // bne         $v1, $v0, L_80019668
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1A
        ctx->r2 = 0 | 0X1A;
        goto L_80019668;
    }
    // ori         $v0, $zero, 0x1A
    ctx->r2 = 0 | 0X1A;
    // lw          $v0, 0x48($gp)
    ctx->r2 = MEM_W(0X48, ctx->r28);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $zero, L_80019668
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1A
        ctx->r2 = 0 | 0X1A;
        goto L_80019668;
    }
    // ori         $v0, $zero, 0x1A
    ctx->r2 = 0 | 0X1A;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3E0
    ctx->r2 = 0 | 0X3E0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1C0
    ctx->r2 = 0 | 0X1C0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x800633C0
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImageWithCallback(rdram, ctx);
    goto after_10;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_10:
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // lw          $v1, 0x48($gp)
    ctx->r3 = MEM_W(0X48, ctx->r28);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4C($gp)
    MEM_W(0X4C, ctx->r28) = ctx->r2;
    // sw          $v1, 0x48($gp)
    MEM_W(0X48, ctx->r28) = ctx->r3;
    // lw          $v1, 0x4C($gp)
    ctx->r3 = MEM_W(0X4C, ctx->r28);
    // ori         $v0, $zero, 0x1A
    ctx->r2 = 0 | 0X1A;
L_80019668:
    // bne         $v1, $v0, L_800196C4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800196C4;
    }
    // nop

    // lw          $v0, 0x48($gp)
    ctx->r2 = MEM_W(0X48, ctx->r28);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $zero, L_800196C4
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800196C4;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lw          $a1, 0x50($gp)
    ctx->r5 = MEM_W(0X50, ctx->r28);
    // lw          $a2, 0x54($gp)
    ctx->r6 = MEM_W(0X54, ctx->r28);
    // ori         $v0, $zero, 0x3C0
    ctx->r2 = 0 | 0X3C0;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1E0
    ctx->r2 = 0 | 0X1E0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x800633C0
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImageWithCallback(rdram, ctx);
    goto after_11;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_11:
    // lw          $v0, 0x4C($gp)
    ctx->r2 = MEM_W(0X4C, ctx->r28);
    // lw          $v1, 0x48($gp)
    ctx->r3 = MEM_W(0X48, ctx->r28);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4C($gp)
    MEM_W(0X4C, ctx->r28) = ctx->r2;
    // sw          $v1, 0x48($gp)
    MEM_W(0X48, ctx->r28) = ctx->r3;
L_800196C4:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_12;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_13;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // lw          $v0, 0x48($gp)
    ctx->r2 = MEM_W(0X48, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x48($gp)
    MEM_W(0X48, ctx->r28) = ctx->r2;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
