#include "recomp.h"
#include "disable_warnings.h"

void Entity_SelectAction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // lw          $s5, 0x79B4($s5)
    ctx->r21 = MEM_W(0X79B4, ctx->r21);
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v1, 0xF($s5)
    ctx->r3 = MEM_BU(0XF, ctx->r21);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, 0x79B0($a0)
    ctx->r4 = MEM_W(0X79B0, ctx->r4);
    // beq         $v1, $v0, L_8003C108
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003C108;
    }
    // nop

    // beq         $v1, $zero, L_8003C108
    if (ctx->r3 == 0) {
        // addiu       $s2, $a0, 0x38
        ctx->r18 = ADD32(ctx->r4, 0X38);
        goto L_8003C108;
    }
    // addiu       $s2, $a0, 0x38
    ctx->r18 = ADD32(ctx->r4, 0X38);
    // addiu       $s3, $zero, -0x2
    ctx->r19 = ADD32(0, -0X2);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // ori         $s1, $zero, 0xF
    ctx->r17 = 0 | 0XF;
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_8003C09C:
    // lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(0X0, ctx->r18);
    // nop

    // beq         $s0, $zero, L_8003C0D8
    if (ctx->r16 == 0) {
        // addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
        goto L_8003C0D8;
    }
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8003BB98
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    sub_8003BB98(rdram, ctx);
    goto after_0;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slt         $v0, $s3, $v1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003C0D0
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_8003C0D0;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
L_8003C0D0:
    // bne         $s1, $s7, L_8003C09C
    if (ctx->r17 != ctx->r23) {
        // nop
    
        goto L_8003C09C;
    }
    // nop

L_8003C0D8:
    // beq         $s4, $zero, L_8003C108
    if (ctx->r20 == 0) {
        // nop
    
        goto L_8003C108;
    }
    // nop

    // lw          $v0, 0x60($s5)
    ctx->r2 = MEM_W(0X60, ctx->r21);
    // nop

    // bne         $s4, $v0, L_8003C100
    if (ctx->r20 != ctx->r2) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8003C100;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lbu         $v1, 0xF($s5)
    ctx->r3 = MEM_BU(0XF, ctx->r21);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_8003C108
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003C108;
    }
    // nop

L_8003C100:
    // jal         0x8003BB60
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    Entity_ApplySequence(rdram, ctx);
    goto after_1;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_1:
L_8003C108:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
