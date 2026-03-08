#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "gpu/PsyX_GPU.h"

void ShowLoadOrNewGameMenu(uint8_t* rdram, recomp_context* ctx) 
{
    printf("ShowLoadOrNewGameMenu\n");
    static bool dump = false;
    if (!dump)
    {
        dump = true;
        GR_SaveVRAM("vram_before_menu.png", 0, 0, 1024, 512, 0);
        printf("[DUMP] VRAM saved before menu render\n");
    }


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x318
    ctx->r29 = ADD32(ctx->r29, -0X318);
    // sw          $s1, 0x2FC($sp)
    MEM_W(0X2FC, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $s5, 0x30C($sp)
    MEM_W(0X30C, ctx->r29) = ctx->r21;
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // sw          $s2, 0x300($sp)
    MEM_W(0X300, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // sw          $s3, 0x304($sp)
    MEM_W(0X304, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x310($sp)
    MEM_W(0X310, ctx->r29) = ctx->r31;
    // sw          $s4, 0x308($sp)
    MEM_W(0X308, ctx->r29) = ctx->r20;
    // jal         0x800246CC
    // sw          $s0, 0x2F8($sp)
    MEM_W(0X2F8, ctx->r29) = ctx->r16;
    SetupMenuUIBuffers(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x2F8($sp)
    MEM_W(0X2F8, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $s0, $sp, 0x280
    ctx->r16 = ADD32(ctx->r29, 0X280);
    // jal         0x8001E184
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    InitMenuTextCoords(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
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
    goto after_2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // jal         0x80025008
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    MemCard_InitSystem(rdram, ctx);
    goto after_3;
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    after_3:
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_8001CDB0:
    // jal         0x800250A8
    // nop

    MemCard_CheckSlot(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_8001CE34
    if (ctx->r4 == 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8001CE34;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s4, L_8001CDB0
    if (ctx->r16 != ctx->r20) {
        // nop
    
        goto L_8001CDB0;
    }
    // nop

    // ori         $s4, $zero, 0x2
    ctx->r20 = 0 | 0X2;
    // beq         $a0, $s4, L_8001CE34
    if (ctx->r4 == ctx->r20) {
        // addiu       $s0, $sp, 0x280
        ctx->r16 = ADD32(ctx->r29, 0X280);
        goto L_8001CE34;
    }
    // addiu       $s0, $sp, 0x280
    ctx->r16 = ADD32(ctx->r29, 0X280);
    // jal         0x8001D474
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LoadMemCardErrorLabels(rdram, ctx);
    goto after_5;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
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
    // sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // jal         0x8001C58C
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    RenderStaticMenuBox(rdram, ctx);
    goto after_6;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_8001CE1C:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_8;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_8:
    // beq         $v0, $zero, L_8001CE1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CE1C;
    }
    // nop

    // j           L_8001CEC0
    // nop

    goto L_8001CEC0;
    // nop

L_8001CE34:
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_8001CE3C:
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // jal         0x80025198
    // addiu       $a1, $sp, 0x2F0
    ctx->r5 = ADD32(ctx->r29, 0X2F0);
    MemCard_ScanForSaves(rdram, ctx);
    goto after_9;
    // addiu       $a1, $sp, 0x2F0
    ctx->r5 = ADD32(ctx->r29, 0X2F0);
    after_9:
    // lw          $v1, 0x2F0($sp)
    ctx->r3 = MEM_W(0X2F0, ctx->r29);
    // nop

    // bne         $v1, $zero, L_8001CEE8
    if (ctx->r3 != 0) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8001CEE8;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s4, L_8001CE3C
    if (ctx->r16 != ctx->r20) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001CE3C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a0, $v0, L_8001CEC8
    if (ctx->r4 != ctx->r2) {
        // addiu       $s0, $sp, 0x280
        ctx->r16 = ADD32(ctx->r29, 0X280);
        goto L_8001CEC8;
    }
    // addiu       $s0, $sp, 0x280
    ctx->r16 = ADD32(ctx->r29, 0X280);
    // jal         0x8001D5A8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    InitNoSaveFoundLabels(rdram, ctx);
    goto after_10;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a2, $zero, 0x3
    ctx->r6 = 0 | 0X3;
    // ori         $a3, $zero, 0x38
    ctx->r7 = 0 | 0X38;
    // ori         $v1, $zero, 0x50
    ctx->r3 = 0 | 0X50;
    // ori         $v0, $zero, 0xCE
    ctx->r2 = 0 | 0XCE;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // jal         0x8001C58C
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    RenderStaticMenuBox(rdram, ctx);
    goto after_11;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_11:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_8001CEB0:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_13;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_13:
    // beq         $v0, $zero, L_8001CEB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CEB0;
    }
    // nop

L_8001CEC0:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_8001CEC8:
    // jal         0x80025064
    // nop

    sub_80025064(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // jal         0x8001D050
    // nop

    Menu_SelectLanguage(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80024820
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    Music_UpdateState(rdram, ctx);
    goto after_17;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // j           L_8001D028
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8001D028;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001CEE8:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_18;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_18:
    // jal         0x80024ED4
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    WaitForButtonRelease(rdram, ctx);
    goto after_19;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    after_19:
L_8001CEF8:
    // beq         $s3, $s4, L_8001CF08
    if (ctx->r19 == ctx->r20) {
        // nop
    
        goto L_8001CF08;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_20;
    // nop

    after_20:
L_8001CF08:
    // beq         $s3, $zero, L_8001CF20
    if (ctx->r19 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001CF20;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s3, $v0, L_8001CF30
    if (ctx->r19 == ctx->r2) {
        // addiu       $v0, $zero, -0x63
        ctx->r2 = ADD32(0, -0X63);
        goto L_8001CF30;
    }
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // j           L_8001CF4C
    // nop

    goto L_8001CF4C;
    // nop

L_8001CF20:
    // jal         0x8001D050
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    Menu_SelectLanguage(rdram, ctx);
    goto after_21;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    after_21:
    // j           L_8001CF4C
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    goto L_8001CF4C;
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
L_8001CF30:
    // jal         0x8001D214
    // nop

    sub_8001D214(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // bne         $s2, $s4, L_8001CF4C
    if (ctx->r18 != ctx->r20) {
        // addiu       $v0, $zero, -0x63
        ctx->r2 = ADD32(0, -0X63);
        goto L_8001CF4C;
    }
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_8001CF4C:
    // bne         $s2, $v0, L_8001D014
    if (ctx->r18 != ctx->r2) {
        // nop
    
        goto L_8001D014;
    }
    // nop

    // jal         0x80024E70
    // nop

    WaitForInputStable(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // jal         0x80024E3C
    // nop

    ReadPadWithFlag(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62F4($v1)
    ctx->r3 = MEM_W(0X62F4, ctx->r3);
    // nop

    // and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // bne         $v1, $zero, L_8001CF94
    if (ctx->r3 != 0) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8001CF94;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001CFB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CFB0;
    }
    // nop

L_8001CF94:
    // sw          $zero, 0x74($gp)
    MEM_W(0X74, ctx->r28) = 0;
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_25;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_25:
    // bne         $s1, $zero, L_8001CFD8
    if (ctx->r17 != 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8001CFD8;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // j           L_8001CFD8
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    goto L_8001CFD8;
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
L_8001CFB0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001CFDC
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001CFDC;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_26;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_26:
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    // addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
L_8001CFD8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001CFDC:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_27;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_27:
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80022774
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_28;
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_28:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001CFDC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001CFDC;
    }
    // nop

    // j           L_8001CEF8
    // nop

    goto L_8001CEF8;
    // nop

L_8001D014:
    // jal         0x80025064
    // nop

    sub_80025064(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // jal         0x80024820
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    Music_UpdateState(rdram, ctx);
    goto after_31;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_31:
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_8001D028:
    // lw          $ra, 0x310($sp)
    ctx->r31 = MEM_W(0X310, ctx->r29);
    // lw          $s5, 0x30C($sp)
    ctx->r21 = MEM_W(0X30C, ctx->r29);
    // lw          $s4, 0x308($sp)
    ctx->r20 = MEM_W(0X308, ctx->r29);
    // lw          $s3, 0x304($sp)
    ctx->r19 = MEM_W(0X304, ctx->r29);
    // lw          $s2, 0x300($sp)
    ctx->r18 = MEM_W(0X300, ctx->r29);
    // lw          $s1, 0x2FC($sp)
    ctx->r17 = MEM_W(0X2FC, ctx->r29);
    // lw          $s0, 0x2F8($sp)
    ctx->r16 = MEM_W(0X2F8, ctx->r29);
    // addiu       $sp, $sp, 0x318
    ctx->r29 = ADD32(ctx->r29, 0X318);
    // jr          $ra
    // nop

    return;
    // nop

;}
