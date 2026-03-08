#include "recomp.h"
#include "disable_warnings.h"

void sub_800336D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x1050
    ctx->r29 = ADD32(ctx->r29, -0X1050);
    // sw          $s3, 0x1044($sp)
    MEM_W(0X1044, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x1038($sp)
    MEM_W(0X1038, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x103C($sp)
    MEM_W(0X103C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // addiu       $s1, $s1, 0x4ECC
    ctx->r17 = ADD32(ctx->r17, 0X4ECC);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sw          $ra, 0x104C($sp)
    MEM_W(0X104C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x1048($sp)
    MEM_W(0X1048, ctx->r29) = ctx->r20;
    // sw          $s2, 0x1040($sp)
    MEM_W(0X1040, ctx->r29) = ctx->r18;
    // lbu         $s2, 0x2($s3)
    ctx->r18 = MEM_BU(0X2, ctx->r19);
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // jal         0x8005E0F8
    // andi        $s2, $s2, 0x3
    ctx->r18 = ctx->r18 & 0X3;
    KF_SetRotMatrix(rdram, ctx);
    goto after_0;
    // andi        $s2, $s2, 0x3
    ctx->r18 = ctx->r18 & 0X3;
    after_0:
    // jal         0x8005E188
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    KF_SetTransMatrix(rdram, ctx);
    goto after_1;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // jal         0x8005F348
    // addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    sub_8005F348(rdram, ctx);
    goto after_2;
    // addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80014FFC
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    RotateMatrixCardinal(rdram, ctx);
    goto after_3;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // jal         0x8005E0F8
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    KF_SetRotMatrix(rdram, ctx);
    goto after_4;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
    // jal         0x8005E188
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    KF_SetTransMatrix(rdram, ctx);
    goto after_5;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // addiu       $s1, $s1, 0x2D8
    ctx->r17 = ADD32(ctx->r17, 0X2D8);
    // sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18) << 2;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // lbu         $v0, 0x4($s3)
    ctx->r2 = MEM_BU(0X4, ctx->r19);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // jal         0x8005E128
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    KF_SetLightMatrix(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_6:
    // jal         0x8005E158
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    KF_SetColorMatrix(rdram, ctx);
    goto after_7;
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_7:
    // lh          $a0, 0x66($s0)
    ctx->r4 = MEM_H(0X66, ctx->r16);
    // jal         0x8002FBC0
    // nop

    sub_8002FBC0(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lbu         $a0, 0x62($s0)
    ctx->r4 = MEM_BU(0X62, ctx->r16);
    // lbu         $a1, 0x63($s0)
    ctx->r5 = MEM_BU(0X63, ctx->r16);
    // lbu         $a2, 0x64($s0)
    ctx->r6 = MEM_BU(0X64, ctx->r16);
    // jal         0x8005DAD0
    // nop

    KF_SetBackColor(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // lbu         $s0, 0x0($s3)
    ctx->r16 = MEM_BU(0X0, ctx->r19);
    // bne         $v0, $v1, L_800337F8
    if (ctx->r2 != ctx->r3) {
        // andi        $s1, $s0, 0xFFFF
        ctx->r17 = ctx->r16 & 0XFFFF;
        goto L_800337F8;
    }
    // andi        $s1, $s0, 0xFFFF
    ctx->r17 = ctx->r16 & 0XFFFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79EA($v0)
    ctx->r2 = MEM_BU(0X79EA, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800337F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800337F8;
    }
    // nop

    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x250($v0)
    ctx->r2 = MEM_W(0X250, ctx->r2);
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $s0, $v0
    ctx->r2 = ctx->r16 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8003387C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003387C;
    }
    // nop

L_800337F8:
    // jal         0x80030008
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80030008(rdram, ctx);
    goto after_10;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // andi        $v0, $s4, 0x80
    ctx->r2 = ctx->r20 & 0X80;
    // beq         $v0, $zero, L_80033874
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x40
        ctx->r2 = ctx->r20 & 0X40;
        goto L_80033874;
    }
    // andi        $v0, $s4, 0x40
    ctx->r2 = ctx->r20 & 0X40;
    // beq         $v0, $zero, L_80033860
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80033860;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8002FFD4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8002FFD4(rdram, ctx);
    goto after_11;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_11:
    // lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(0X14, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8003385C
    if (ctx->r2 == 0) {
        // addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
        goto L_8003385C;
    }
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x250($a0)
    ctx->r4 = MEM_W(0X250, ctx->r4);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // jal         0x80032A1C
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80032A1C(rdram, ctx);
    goto after_12;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_12:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0xF0
    ctx->r5 = 0 | 0XF0;
    // jal         0x800322FC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    KF_RenderTMD02(rdram, ctx);
    goto after_13;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_13:
    // j           L_8003387C
    // nop

    goto L_8003387C;
    // nop

L_8003385C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80033860:
    // ori         $a1, $zero, 0xF0
    ctx->r5 = 0 | 0XF0;
    // jal         0x800322FC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_RenderTMD02(rdram, ctx);
    goto after_14;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_14:
    // j           L_8003387C
    // nop

    goto L_8003387C;
    // nop

L_80033874:
    // jal         0x80031CD0
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80031CD0(rdram, ctx);
    goto after_15;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_15:
L_8003387C:
    // lw          $ra, 0x104C($sp)
    ctx->r31 = MEM_W(0X104C, ctx->r29);
    // lw          $s4, 0x1048($sp)
    ctx->r20 = MEM_W(0X1048, ctx->r29);
    // lw          $s3, 0x1044($sp)
    ctx->r19 = MEM_W(0X1044, ctx->r29);
    // lw          $s2, 0x1040($sp)
    ctx->r18 = MEM_W(0X1040, ctx->r29);
    // lw          $s1, 0x103C($sp)
    ctx->r17 = MEM_W(0X103C, ctx->r29);
    // lw          $s0, 0x1038($sp)
    ctx->r16 = MEM_W(0X1038, ctx->r29);
    // addiu       $sp, $sp, 0x1050
    ctx->r29 = ADD32(ctx->r29, 0X1050);
    // jr          $ra
    // nop

    return;
    // nop

;}
