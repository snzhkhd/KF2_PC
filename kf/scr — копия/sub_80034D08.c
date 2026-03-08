#include "recomp.h"
#include "disable_warnings.h"

void sub_80034D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $s0
    ctx->r19 = ADD32(ctx->r7, ctx->r16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // beq         $v0, $zero, L_80034DD0
    if (ctx->r2 == 0) {
        // sw          $s4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r20;
        goto L_80034DD0;
    }
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // ori         $s5, $zero, 0x2
    ctx->r21 = 0 | 0X2;
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
L_80034D50:
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17) << 3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x59A8
    ctx->r1 = ADD32(ctx->r1, -0X59A8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a0, 0x0($at)
    ctx->r4 = MEM_W(0X0, ctx->r1);
    // beq         $v1, $zero, L_80034DA4
    if (ctx->r3 == 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80034DA4;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // bne         $a0, $zero, L_80034D8C
    if (ctx->r4 != 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80034D8C;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // jal         0x80014BB0
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    StartAudioStream(rdram, ctx);
    goto after_0;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_0:
    // j           L_80034DC4
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_80034DC4;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80034D8C:
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // bne         $v0, $s5, L_80034DC0
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80034DC0;
    }
    // nop

    // j           L_80034DC0
    // sh          $s4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r20;
    goto L_80034DC0;
    // sh          $s4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r20;
L_80034DA4:
    // beq         $a0, $zero, L_80034DC0
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80034DC0;
    }
    // nop

    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // bne         $v0, $s4, L_80034DC0
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80034DC0;
    }
    // nop

    // sh          $s5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r21;
L_80034DC0:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80034DC4:
    // slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_80034D50
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80034D50;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80034DD0:
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
