#include "recomp.h"
#include "disable_warnings.h"

void sub_8001EF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
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
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
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
L_8001EF8C:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_1;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_1:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(0X1C, ctx->r29);
    // jal         0x80022774
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_2;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001EF8C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001EF8C;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_4:
    // jal         0x80024ED4
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    WaitForButtonRelease(rdram, ctx);
    goto after_5;
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    after_5:
    // addiu       $s5, $zero, -0x63
    ctx->r21 = ADD32(0, -0X63);
L_8001EFD0:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // bne         $v0, $s6, L_8001EFF0
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8001EFF0;
    }
    // nop

    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // beq         $v0, $s5, L_8001EFF8
    if (ctx->r2 == ctx->r21) {
        // nop
    
        goto L_8001EFF8;
    }
    // nop

L_8001EFF0:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_8001EFF8:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // beq         $v1, $zero, L_8001F018
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001F018;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8001F02C
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8001F02C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // j           L_8001F038
    // nop

    goto L_8001F038;
    // nop

L_8001F018:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x8001F0D4
    // andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    BuyItemMenu(rdram, ctx);
    goto after_7;
    // andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    after_7:
    // j           L_8001F038
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    goto L_8001F038;
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_8001F02C:
    // jal         0x8001F46C
    // andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    SellItemMenu_8001F46C(rdram, ctx);
    goto after_8;
    // andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_8:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_8001F038:
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // bne         $v0, $s5, L_8001F0A0
    if (ctx->r2 != ctx->r21) {
        // addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
        goto L_8001F0A0;
    }
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // jal         0x80020420
    // addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    MenuInputProcess(rdram, ctx);
    goto after_9;
    // addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_9:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001F068:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_10;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_10:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(0X1C, ctx->r29);
    // jal         0x80022774
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_11;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_11:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001F068
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F068;
    }
    // nop

    // j           L_8001EFD0
    // nop

    goto L_8001EFD0;
    // nop

L_8001F0A0:
    // jal         0x80024820
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    Music_UpdateState(rdram, ctx);
    goto after_13;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
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
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
