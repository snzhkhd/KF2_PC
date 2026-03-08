#include "recomp.h"
#include "disable_warnings.h"

void InGameMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // jal         0x800246CC
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    SetupMenuUIBuffers(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80019734:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_1;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_1:
    // jal         0x80020ABC
    // nop

    DrawPlayerStat(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(0X1C, ctx->r29);
    // jal         0x80022774
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_3;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80019734
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80019734;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_5:
    // jal         0x80024ED4
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    WaitForButtonRelease(rdram, ctx);
    goto after_6;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    after_6:
    // addiu       $s3, $zero, -0x63
    ctx->r19 = ADD32(0, -0X63);
L_80019780:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // bne         $v0, $s4, L_800197A0
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_800197A0;
    }
    // nop

    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // beq         $v0, $s3, L_800197A8
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_800197A8;
    }
    // nop

L_800197A0:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_800197A8:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80019848
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80019848;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1194
    ctx->r1 = ADD32(ctx->r1, 0X1194);
    // addu        $at, $at, $v0
    gpr jr_addend_800197D0;
    jr_addend_800197D0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800197D0 >> 2) {
        case 0: goto L_800197D8; break;
        case 1: goto L_800197E8; break;
        case 2: goto L_800197F8; break;
        case 3: goto L_80019808; break;
        case 4: goto L_80019818; break;
        case 5: goto L_80019828; break;
        case 6: goto L_80019840; break;
        default: switch_error(__func__, 0x800197D0, 0x80011194);
    }
    // nop

L_800197D8:
    // jal         0x80019A70
    // nop

    ShowUseMenu(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_80019830
    // nop

    goto L_80019830;
    // nop

L_800197E8:
    // jal         0x8001A824
    // nop

    UseMagicMenu(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_80019830
    // nop

    goto L_80019830;
    // nop

L_800197F8:
    // jal         0x8001AAF4
    // nop

    EquipmentMenu(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // j           L_80019848
    // nop

    goto L_80019848;
    // nop

L_80019808:
    // jal         0x8001BC14
    // nop

    DrawDefAtkStats(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // j           L_80019848
    // nop

    goto L_80019848;
    // nop

L_80019818:
    // jal         0x8001BCA0
    // nop

    DropMenu(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // j           L_80019848
    // nop

    goto L_80019848;
    // nop

L_80019828:
    // jal         0x8001BEC0
    // nop

    SaveDataMenu(rdram, ctx);
    goto after_13;
    // nop

    after_13:
L_80019830:
    // bne         $v0, $s4, L_80019848
    if (ctx->r2 != ctx->r20) {
        // sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
        goto L_80019848;
    }
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // j           L_80019848
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    goto L_80019848;
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
L_80019840:
    // jal         0x8001C968
    // nop

    OptionsMenu(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_80019848:
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // bne         $v0, $s3, L_800198FC
    if (ctx->r2 != ctx->r19) {
        // addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
        goto L_800198FC;
    }
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // jal         0x80020420
    // addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    MenuInputProcess(rdram, ctx);
    goto after_15;
    // addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_15:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_16;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_16:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80019884:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E4($v0)
    ctx->r2 = MEM_W(0X62E4, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800198C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800198C4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62EC($v0)
    ctx->r2 = MEM_W(0X62EC, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800198C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800198C4;
    }
    // nop

    // jal         0x80019998
    // nop

    DrawDebugNumbers(rdram, ctx);
    goto after_18;
    // nop

    after_18:
L_800198C4:
    // jal         0x80020ABC
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    DrawPlayerStat(rdram, ctx);
    goto after_19;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_19:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(0X1C, ctx->r29);
    // jal         0x80022774
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_20;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_20:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80019884
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80019884;
    }
    // nop

    // j           L_80019780
    // nop

    goto L_80019780;
    // nop

L_800198FC:
    // lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(0X20, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80019914
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80019914;
    }
    // nop

    // jal         0x80024DA8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    PlaySfx(rdram, ctx);
    goto after_22;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
L_80019914:
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80019930
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80019930;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_80019930:
    // jal         0x80024820
    // nop

    Music_UpdateState(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // nop

    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80019970
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
        goto L_80019970;
    }
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // beq         $a0, $v0, L_80019970
    if (ctx->r4 == ctx->r2) {
        // andi        $v0, $a0, 0x1000
        ctx->r2 = ctx->r4 & 0X1000;
        goto L_80019970;
    }
    // andi        $v0, $a0, 0x1000
    ctx->r2 = ctx->r4 & 0X1000;
    // beq         $v0, $zero, L_80019970
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019970;
    }
    // nop

    // jal         0x80029C4C
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    TryCastMagic(rdram, ctx);
    goto after_24;
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    after_24:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80019970:
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
