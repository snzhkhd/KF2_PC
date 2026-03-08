#include "recomp.h"
#include "disable_warnings.h"

void sub_8004892C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(0X40, ctx->r29);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(0X44, ctx->r29);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // beq         $s0, $zero, L_800489A4
    if (ctx->r16 == 0) {
        // sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
        goto L_800489A4;
    }
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    FixedPointLerp(rdram, ctx);
    goto after_0;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_0:
    // sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(0X4, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    FixedPointLerp(rdram, ctx);
    goto after_1;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_1:
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(0X8, ctx->r17);
    // jal         0x80015D18
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    FixedPointLerp(rdram, ctx);
    goto after_2;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_2:
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
L_800489A4:
    // beq         $s3, $zero, L_800489D4
    if (ctx->r19 == 0) {
        // nop
    
        goto L_800489D4;
    }
    // nop

    // lh          $a0, 0x0($s3)
    ctx->r4 = MEM_H(0X0, ctx->r19);
    // lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(0X0, ctx->r21);
    // jal         0x80015D30
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    sub_80015D30(rdram, ctx);
    goto after_3;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_3:
    // sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    // lh          $a0, 0x4($s3)
    ctx->r4 = MEM_H(0X4, ctx->r19);
    // lh          $a1, 0x4($s5)
    ctx->r5 = MEM_H(0X4, ctx->r21);
    // jal         0x80015D30
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    sub_80015D30(rdram, ctx);
    goto after_4;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_4:
    // sh          $v0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r2;
L_800489D4:
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
