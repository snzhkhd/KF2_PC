#include "recomp.h"
#include "disable_warnings.h"

void Menu_SelectLanguage(uint8_t* rdram, recomp_context* ctx) 
{
    printf("Menu_SelectLanguage\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addiu       $s5, $zero, -0x63
    ctx->r21 = ADD32(0, -0X63);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8001D08C:
    // bne         $s3, $s6, L_8001D09C
    if (ctx->r19 != ctx->r22) {
        // nop
    
        goto L_8001D09C;
    }
    // nop

    // beq         $s2, $s5, L_8001D0A4
    if (ctx->r18 == ctx->r21) {
        // nop
    
        goto L_8001D0A4;
    }
    // nop

L_8001D09C:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8001D0A4:
    // beq         $s3, $s6, L_8001D0BC
    if (ctx->r19 == ctx->r22) {
        // nop
    
        goto L_8001D0BC;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s3, -0x4A66($at)
    MEM_H(-0X4A66, ctx->r1) = ctx->r19;
    // j           L_8001D1E8
    // nop

    goto L_8001D1E8;
    // nop

L_8001D0BC:
    // beq         $s2, $s5, L_8001D0C8
    if (ctx->r18 == ctx->r21) {
        // nop
    
        goto L_8001D0C8;
    }
    // nop

    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
L_8001D0C8:
    // jal         0x80024E70
    // nop

    WaitForInputStable(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80024E3C
    // nop

    ReadPadWithFlag(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62F4($v1)
    ctx->r3 = MEM_W(0X62F4, ctx->r3);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // beq         $v1, $zero, L_8001D10C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8001D10C;
    }
    // nop

    // sw          $zero, 0x74($gp)
    MEM_W(0X74, ctx->r28) = 0;
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_3:
    // bne         $s1, $zero, L_8001D1AC
    if (ctx->r17 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_8001D1AC;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // j           L_8001D1AC
    // ori         $s1, $zero, 0x2
    ctx->r17 = 0 | 0X2;
    goto L_8001D1AC;
    // ori         $s1, $zero, 0x2
    ctx->r17 = 0 | 0X2;
L_8001D10C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001D144
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001D144;
    }
    // nop

    // sw          $zero, 0x74($gp)
    MEM_W(0X74, ctx->r28) = 0;
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_4:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $s1, $v0, L_8001D1AC
    if (ctx->r17 != ctx->r2) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8001D1AC;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // j           L_8001D1AC
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_8001D1AC;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8001D144:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001D170
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001D170;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_5:
    // addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // j           L_8001D1AC
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    goto L_8001D1AC;
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
L_8001D170:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D0($v0)
    ctx->r2 = MEM_W(0X62D0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_8001D1A0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001D1A0;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E0($v0)
    ctx->r2 = MEM_W(0X62E0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001D1B0
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001D1B0;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001D1A0:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_6:
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_8001D1AC:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001D1B0:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_7;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_7:
    // ori         $a0, $zero, 0x7
    ctx->r4 = 0 | 0X7;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80022774
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_8;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_8:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001D1B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001D1B0;
    }
    // nop

    // j           L_8001D08C
    // nop

    goto L_8001D08C;
    // nop

L_8001D1E8:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
