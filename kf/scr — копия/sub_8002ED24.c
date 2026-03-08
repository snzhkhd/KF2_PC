#include "recomp.h"
#include "disable_warnings.h"

void sub_8002ED24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // addiu       $s1, $s1, 0x4F60
    ctx->r17 = ADD32(ctx->r17, 0X4F60);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // ori         $s2, $zero, 0x17
    ctx->r18 = 0 | 0X17;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // andi        $s3, $s4, 0xFF
    ctx->r19 = ctx->r20 & 0XFF;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8002ED5C:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // jal         0x8002ECC0
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_8002ECC0(rdram, ctx);
    goto after_0;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x8002ECC0
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    sub_8002ECC0(rdram, ctx);
    goto after_1;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // slt         $v0, $a0, $s0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8002EDB0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002EDB0;
    }
    // nop

    // addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // subu        $v0, $a0, $s0
    ctx->r2 = SUB32(ctx->r4, ctx->r16);
L_8002EDA0:
    // sb          $s4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r20;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $s5, L_8002EDA0
    if (ctx->r2 != ctx->r21) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8002EDA0;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8002EDB0:
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // bne         $s2, $s5, L_8002ED5C
    if (ctx->r18 != ctx->r21) {
        // addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
        goto L_8002ED5C;
    }
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
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
