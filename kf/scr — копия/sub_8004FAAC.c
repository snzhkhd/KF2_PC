#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // addiu       $s2, $s2, 0x6AC0
    ctx->r18 = ADD32(ctx->r18, 0X6AC0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_8004FAE0:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x6AB8
    ctx->r1 = ADD32(ctx->r1, 0X6AB8);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8004FB30
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FB30;
    }
    // nop

    // bne         $v0, $s3, L_8004FB1C
    if (ctx->r2 != ctx->r19) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8004FB1C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80062BC0
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    strcmp_recomp(rdram, ctx);
    goto after_0;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // bne         $v0, $zero, L_8004FB20
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x2C
        ctx->r18 = ADD32(ctx->r18, 0X2C);
        goto L_8004FB20;
    }
    // addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // j           L_8004FB34
    // addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    goto L_8004FB34;
    // addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_8004FB1C:
    // addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
L_8004FB20:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8004FAE0
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
        goto L_8004FAE0;
    }
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
L_8004FB30:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004FB34:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
