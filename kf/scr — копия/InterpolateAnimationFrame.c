#include "recomp.h"
#include "disable_warnings.h"

void InterpolateAnimationFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // andi        $v0, $s3, 0x2
    ctx->r2 = ctx->r19 & 0X2;
    // beq         $v0, $zero, L_8002E940
    if (ctx->r2 == 0) {
        // sw          $ra, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r31;
        goto L_8002E940;
    }
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sll         $a3, $s2, 16
    ctx->r7 = S32(ctx->r18) << 16;
    // jal         0x80015D70
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    LerpRotationMatrix(rdram, ctx);
    goto after_0;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_0:
L_8002E940:
    // andi        $v0, $s3, 0x1
    ctx->r2 = ctx->r19 & 0X1;
    // beq         $v0, $zero, L_8002E960
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8002E960;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sll         $a3, $s2, 16
    ctx->r7 = S32(ctx->r18) << 16;
    // jal         0x80015D70
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    LerpRotationMatrix(rdram, ctx);
    goto after_1;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_1:
L_8002E960:
    // andi        $v0, $s3, 0x4
    ctx->r2 = ctx->r19 & 0X4;
    // beq         $v0, $zero, L_8002E9AC
    if (ctx->r2 == 0) {
        // andi        $v0, $s3, 0x8
        ctx->r2 = ctx->r19 & 0X8;
        goto L_8002E9AC;
    }
    // andi        $v0, $s3, 0x8
    ctx->r2 = ctx->r19 & 0X8;
    // lbu         $a0, 0x62($s0)
    ctx->r4 = MEM_BU(0X62, ctx->r16);
    // lbu         $a1, 0x26($s1)
    ctx->r5 = MEM_BU(0X26, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    FixedPointLerp(rdram, ctx);
    goto after_2;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_2:
    // lbu         $a0, 0x63($s0)
    ctx->r4 = MEM_BU(0X63, ctx->r16);
    // sb          $v0, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r2;
    // lbu         $a1, 0x27($s1)
    ctx->r5 = MEM_BU(0X27, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    FixedPointLerp(rdram, ctx);
    goto after_3;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(0X64, ctx->r16);
    // sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
    // lbu         $a1, 0x28($s1)
    ctx->r5 = MEM_BU(0X28, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    FixedPointLerp(rdram, ctx);
    goto after_4;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_4:
    // sb          $v0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r2;
    // andi        $v0, $s3, 0x8
    ctx->r2 = ctx->r19 & 0X8;
L_8002E9AC:
    // beq         $v0, $zero, L_8002E9C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002E9C8;
    }
    // nop

    // lh          $a0, 0x66($s0)
    ctx->r4 = MEM_H(0X66, ctx->r16);
    // lh          $a1, 0x2A($s1)
    ctx->r5 = MEM_H(0X2A, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    FixedPointLerp(rdram, ctx);
    goto after_5;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // sh          $v0, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r2;
L_8002E9C8:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
