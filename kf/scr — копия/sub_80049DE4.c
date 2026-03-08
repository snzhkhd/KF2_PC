#include "recomp.h"
#include "disable_warnings.h"

void sub_80049DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(0X50, ctx->r29);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(0X54, ctx->r29);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(0X58, ctx->r29);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
L_80049E30:
    // jal         0x8002E73C
    // nop

    PrepareRenderPrimitives(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jal         0x80015D18
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    FixedPointLerp(rdram, ctx);
    goto after_1;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x80015D18
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    FixedPointLerp(rdram, ctx);
    goto after_2;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_2:
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x80015D18
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    FixedPointLerp(rdram, ctx);
    goto after_3;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_3:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // jal         0x80034100
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    sub_80034100(rdram, ctx);
    goto after_4;
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    after_4:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_5;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // addu        $s2, $s2, $s6
    ctx->r18 = ADD32(ctx->r18, ctx->r22);
    // slti        $v0, $s2, 0x1000
    ctx->r2 = SIGNED(ctx->r18) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80049E30
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80049E30;
    }
    // nop

    // jal         0x8002E73C
    // nop

    PrepareRenderPrimitives(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // jal         0x80034100
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    sub_80034100(rdram, ctx);
    goto after_7;
    // ori         $a3, $zero, 0x800
    ctx->r7 = 0 | 0X800;
    after_7:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
