#include "recomp.h"
#include "disable_warnings.h"

void sub_800260BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // jal         0x80018190
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    after_0:
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D8($at)
    MEM_B(0X79D8, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D9($at)
    MEM_B(0X79D9, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DA($at)
    MEM_B(0X79DA, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DB($at)
    MEM_B(0X79DB, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DC($at)
    MEM_B(0X79DC, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x800166F8
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_800166F8(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
L_80026148:
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

    // bne         $v0, $zero, L_80026148
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026148;
    }
    // nop

    // jal         0x80018190
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_5;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_6;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_7;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_8;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $s3, $v0, L_80026210
    if (ctx->r19 == ctx->r2) {
        // ori         $a0, $zero, 0xFF
        ctx->r4 = 0 | 0XFF;
        goto L_80026210;
    }
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x800166F8
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_800166F8(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_9:
L_800261C4:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800261C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800261C4;
    }
    // nop

    // jal         0x80018190
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_13;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_14;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_14:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_15;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_16;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
L_80026210:
    // jal         0x80027CA8
    // nop

    Player_Spawn(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // jal         0x8002E73C
    // nop

    PrepareRenderPrimitives(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // ori         $a0, $zero, 0x82
    ctx->r4 = 0 | 0X82;
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // jal         0x80039898
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    FadeScreenIn(rdram, ctx);
    goto after_19;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_19:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x858($v0)
    ctx->r2 = MEM_W(0X858, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80026254
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80026254;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x101
    ctx->r5 = 0 | 0X101;
    // jal         0x80034C68
    // ori         $a2, $zero, 0x181
    ctx->r6 = 0 | 0X181;
    sub_80034C68(rdram, ctx);
    goto after_20;
    // ori         $a2, $zero, 0x181
    ctx->r6 = 0 | 0X181;
    after_20:
L_80026254:
    // jal         0x80018190
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // ori         $a0, $zero, 0x82
    ctx->r4 = 0 | 0X82;
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80039898
    // addiu       $a3, $zero, -0x80
    ctx->r7 = ADD32(0, -0X80);
    FadeScreenIn(rdram, ctx);
    goto after_22;
    // addiu       $a3, $zero, -0x80
    ctx->r7 = ADD32(0, -0X80);
    after_22:
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // lbu         $v0, 0x48($sp)
    ctx->r2 = MEM_BU(0X48, ctx->r29);
    // andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x800166F8
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_800166F8(rdram, ctx);
    goto after_23;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_23:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
