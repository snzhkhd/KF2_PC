#include "recomp.h"
#include "disable_warnings.h"

void sub_800140B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80054388
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    SetMasterVolume(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x59D0
    ctx->r16 = ADD32(ctx->r16, -0X59D0);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80014120
    if (ctx->r3 != ctx->r2) {
        // addiu       $s1, $s0, 0x24
        ctx->r17 = ADD32(ctx->r16, 0X24);
        goto L_80014120;
    }
    // addiu       $s1, $s0, 0x24
    ctx->r17 = ADD32(ctx->r16, 0X24);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x80052198
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CDAudio_SetVolume(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005C7A4
    // nop

    CDAudio_Stop(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005D4F0
    // nop

    SpuVoice_StopAll(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80014120:
    // ori         $s0, $zero, 0x81
    ctx->r16 = 0 | 0X81;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80014128:
    // lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(0X0, ctx->r17);
    // nop

    // beq         $a0, $s2, L_80014140
    if (ctx->r4 == ctx->r18) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_80014140;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // jal         0x8005D010
    // nop

    FreeSPUVoice(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80014140:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s2, L_80014128
    if (ctx->r16 != ctx->r18) {
        // nop
    
        goto L_80014128;
    }
    // nop

    // jal         0x8005D29C
    // nop

    sub_8005D29C(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
