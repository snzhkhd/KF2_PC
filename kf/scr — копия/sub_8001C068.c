#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x428
    ctx->r29 = ADD32(ctx->r29, -0X428);
    // sw          $s0, 0x408($sp)
    MEM_W(0X408, ctx->r29) = ctx->r16;
    // addiu       $s0, $sp, 0x3A0
    ctx->r16 = ADD32(ctx->r29, 0X3A0);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $ra, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r31;
    // sw          $s5, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r20;
    // sw          $s3, 0x414($sp)
    MEM_W(0X414, ctx->r29) = ctx->r19;
    // sw          $s2, 0x410($sp)
    MEM_W(0X410, ctx->r29) = ctx->r18;
    // sw          $s1, 0x40C($sp)
    MEM_W(0X40C, ctx->r29) = ctx->r17;
    // sw          $zero, 0x3FC($sp)
    MEM_W(0X3FC, ctx->r29) = 0;
    // jal         0x8001E184
    // sw          $v0, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r2;
    InitMenuTextCoords(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r2;
    after_0:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    // ori         $a3, $zero, 0x38
    ctx->r7 = 0 | 0X38;
    // ori         $v0, $zero, 0x57
    ctx->r2 = 0 | 0X57;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xCE
    ctx->r2 = 0 | 0XCE;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x8001C58C
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    RenderStaticMenuBox(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // jal         0x80018190
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8001C118
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001C118;
    }
    // nop

L_8001C0F4:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8001C0F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C0F4;
    }
    // nop

L_8001C118:
    // jal         0x80025008
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    MemCard_InitSystem(rdram, ctx);
    goto after_5;
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    after_5:
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8001C124:
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // jal         0x80025198
    // addiu       $a1, $sp, 0x3F8
    ctx->r5 = ADD32(ctx->r29, 0X3F8);
    MemCard_ScanForSaves(rdram, ctx);
    goto after_6;
    // addiu       $a1, $sp, 0x3F8
    ctx->r5 = ADD32(ctx->r29, 0X3F8);
    after_6:
    // lw          $v0, 0x3F8($sp)
    ctx->r2 = MEM_W(0X3F8, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001C14C
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
        goto L_8001C14C;
    }
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_8001C124
    if (ctx->r16 != ctx->r17) {
        // nop
    
        goto L_8001C124;
    }
    // nop

L_8001C14C:
    // addiu       $s2, $sp, 0x2B8
    ctx->r18 = ADD32(ctx->r29, 0X2B8);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $s3, $sp, 0x358
    ctx->r19 = ADD32(ctx->r29, 0X358);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // addiu       $s1, $sp, 0x378
    ctx->r17 = ADD32(ctx->r29, 0X378);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // addiu       $v0, $sp, 0x380
    ctx->r2 = ADD32(ctx->r29, 0X380);
    // jal         0x8001C3A0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8001C3A0(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // addiu       $a0, $sp, 0x280
    ctx->r4 = ADD32(ctx->r29, 0X280);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x800249BC
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    InitListWidget(rdram, ctx);
    goto after_8;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_8:
    // addiu       $s4, $zero, -0x63
    ctx->r20 = ADD32(0, -0X63);
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sb          $v0, 0x29F($sp)
    MEM_B(0X29F, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x83
    ctx->r2 = 0 | 0X83;
    // sb          $v0, 0x29D($sp)
    MEM_B(0X29D, ctx->r29) = ctx->r2;
    // sb          $s0, 0x29E($sp)
    MEM_B(0X29E, ctx->r29) = ctx->r16;
    // sw          $s2, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r17;
    // sw          $s3, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r19;
L_8001C1AC:
    // lw          $v0, 0x3FC($sp)
    ctx->r2 = MEM_W(0X3FC, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001C1CC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C1CC;
    }
    // nop

    // lw          $v0, 0x400($sp)
    ctx->r2 = MEM_W(0X400, ctx->r29);
    // nop

    // beq         $v0, $s4, L_8001C1D4
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_8001C1D4;
    }
    // nop

L_8001C1CC:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_9;
    // nop

    after_9:
L_8001C1D4:
    // lw          $v0, 0x3FC($sp)
    ctx->r2 = MEM_W(0X3FC, ctx->r29);
    // nop

    // bne         $v0, $s5, L_8001C224
    if (ctx->r2 != ctx->r21) {
        // addiu       $a0, $sp, 0x280
        ctx->r4 = ADD32(ctx->r29, 0X280);
        goto L_8001C224;
    }
    // addiu       $a0, $sp, 0x280
    ctx->r4 = ADD32(ctx->r29, 0X280);
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // jal         0x80022468
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    ShowEquipmentMenu(rdram, ctx);
    goto after_10;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    after_10:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001C208
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x400($sp)
        MEM_W(0X400, ctx->r29) = ctx->r2;
        goto L_8001C208;
    }
    // sw          $v0, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r2;
    // j           L_8001C224
    // sw          $s4, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r20;
    goto L_8001C224;
    // sw          $s4, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r20;
L_8001C208:
    // lbu         $v0, 0x2A1($sp)
    ctx->r2 = MEM_BU(0X2A1, ctx->r29);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lw          $v0, 0x380($v0)
    ctx->r2 = MEM_W(0X380, ctx->r2);
    // nop

    // sw          $v0, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r2;
L_8001C224:
    // lw          $v0, 0x400($sp)
    ctx->r2 = MEM_W(0X400, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001C28C
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x280
        ctx->r4 = ADD32(ctx->r29, 0X280);
        goto L_8001C28C;
    }
    // addiu       $a0, $sp, 0x280
    ctx->r4 = ADD32(ctx->r29, 0X280);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x3FC
    ctx->r6 = ADD32(ctx->r29, 0X3FC);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x400
    ctx->r7 = ADD32(ctx->r29, 0X400);
    ProcessListNavigation(rdram, ctx);
    goto after_11;
    // addiu       $a3, $sp, 0x400
    ctx->r7 = ADD32(ctx->r29, 0X400);
    after_11:
    // lw          $v0, 0x3FC($sp)
    ctx->r2 = MEM_W(0X3FC, ctx->r29);
    // nop

    // bne         $v0, $s5, L_8001C25C
    if (ctx->r2 != ctx->r21) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001C25C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_12;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_12:
L_8001C25C:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_13;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_13:
    // addiu       $a0, $sp, 0x280
    ctx->r4 = ADD32(ctx->r29, 0X280);
    // jal         0x800228B4
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    RenderItemList(rdram, ctx);
    goto after_14;
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    after_14:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001C25C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C25C;
    }
    // nop

    // j           L_8001C1AC
    // nop

    goto L_8001C1AC;
    // nop

L_8001C28C:
    // lw          $v1, 0x400($sp)
    ctx->r3 = MEM_W(0X400, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001C354
    if (ctx->r3 == ctx->r2) {
        // addiu       $s0, $sp, 0x3A0
        ctx->r16 = ADD32(ctx->r29, 0X3A0);
        goto L_8001C354;
    }
    // addiu       $s0, $sp, 0x3A0
    ctx->r16 = ADD32(ctx->r29, 0X3A0);
    // jal         0x8001E938
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8001E938(rdram, ctx);
    goto after_16;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_16:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // ori         $a3, $zero, 0x38
    ctx->r7 = 0 | 0X38;
    // ori         $v0, $zero, 0x57
    ctx->r2 = 0 | 0X57;
    // ori         $s2, $zero, 0xCE
    ctx->r18 = 0 | 0XCE;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // ori         $s1, $zero, 0x2
    ctx->r17 = 0 | 0X2;
    // sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x8001C58C
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    RenderStaticMenuBox(rdram, ctx);
    goto after_17;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_17:
    // lw          $a0, 0x400($sp)
    ctx->r4 = MEM_W(0X400, ctx->r29);
    // jal         0x800255E0
    // nop

    sub_800255E0(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // beq         $v0, $zero, L_8001C350
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8001C350;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8001EA60
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    sub_8001EA60(rdram, ctx);
    goto after_19;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_19:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a2, $zero, 0x3
    ctx->r6 = 0 | 0X3;
    // ori         $a3, $zero, 0x38
    ctx->r7 = 0 | 0X38;
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x8001C58C
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    RenderStaticMenuBox(rdram, ctx);
    goto after_20;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_20:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_21;
    // nop

    after_21:
L_8001C32C:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_22;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_22:
    // beq         $v0, $zero, L_8001C32C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001C32C;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8001C354
    // sw          $v0, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r2;
    goto L_8001C354;
    // sw          $v0, 0x400($sp)
    MEM_W(0X400, ctx->r29) = ctx->r2;
L_8001C350:
    // sw          $zero, 0x400($sp)
    MEM_W(0X400, ctx->r29) = 0;
L_8001C354:
    // jal         0x80025064
    // nop

    sub_80025064(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // lw          $v0, 0x400($sp)
    ctx->r2 = MEM_W(0X400, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001C378
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C378;
    }
    // nop

    // jal         0x80018D74
    // nop

    _loadTIM(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // lw          $v0, 0x400($sp)
    ctx->r2 = MEM_W(0X400, ctx->r29);
L_8001C378:
    // lw          $ra, 0x420($sp)
    ctx->r31 = MEM_W(0X420, ctx->r29);
    // lw          $s5, 0x41C($sp)
    ctx->r21 = MEM_W(0X41C, ctx->r29);
    // lw          $s4, 0x418($sp)
    ctx->r20 = MEM_W(0X418, ctx->r29);
    // lw          $s3, 0x414($sp)
    ctx->r19 = MEM_W(0X414, ctx->r29);
    // lw          $s2, 0x410($sp)
    ctx->r18 = MEM_W(0X410, ctx->r29);
    // lw          $s1, 0x40C($sp)
    ctx->r17 = MEM_W(0X40C, ctx->r29);
    // lw          $s0, 0x408($sp)
    ctx->r16 = MEM_W(0X408, ctx->r29);
    // addiu       $sp, $sp, 0x428
    ctx->r29 = ADD32(ctx->r29, 0X428);
    // jr          $ra
    // nop

    return;
    // nop

;}
