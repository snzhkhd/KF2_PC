#include "recomp.h"
#include "disable_warnings.h"

void MenuInputProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(0X40, ctx->r29);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // jal         0x80024E70
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    WaitForInputStable(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    after_0:
    // jal         0x80024E3C
    // nop

    ReadPadWithFlag(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62F4($v1)
    ctx->r3 = MEM_W(0X62F4, ctx->r3);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // beq         $v1, $zero, L_800204A0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800204A0;
    }
    // nop

    // sw          $zero, 0x74($gp)
    MEM_W(0X74, ctx->r28) = 0;
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_2:
    // bne         $s0, $zero, L_8002054C
    if (ctx->r16 != 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8002054C;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // j           L_8002054C
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    goto L_8002054C;
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_800204A0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_800204D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800204D4;
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
    // bne         $s0, $s1, L_8002054C
    if (ctx->r16 != ctx->r17) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8002054C;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_8002054C
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_8002054C;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800204D4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80020510
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020510;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_4:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // beq         $v0, $zero, L_80020548
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020548;
    }
    // nop

    // j           L_8002054C
    // sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    goto L_8002054C;
    // sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
L_80020510:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D0($v0)
    ctx->r2 = MEM_W(0X62D0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_80020540
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80020540;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E0($v0)
    ctx->r2 = MEM_W(0X62E0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80020550
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80020550;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80020540:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_5:
L_80020548:
    // sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
L_8002054C:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80020550:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
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
