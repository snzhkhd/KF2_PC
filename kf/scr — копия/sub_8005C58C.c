#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C58C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x770($v0)
    ctx->r2 = MEM_W(-0X770, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x1
    ctx->r16 = 0 | 0X1;
    // beq         $v0, $s0, L_8005C5C4
    if (ctx->r2 == ctx->r16) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_8005C5C4;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x79C($v0)
    ctx->r2 = MEM_W(-0X79C, ctx->r2);
    // nop

    // bne         $v0, $s0, L_8005C5CC
    if (ctx->r2 != ctx->r16) {
        // nop
    
        goto L_8005C5CC;
    }
    // nop

L_8005C5C4:
    // j           L_8005C61C
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8005C61C;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8005C5CC:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x718($a0)
    ctx->r4 = MEM_W(-0X718, ctx->r4);
    // jal         0x80062AE0
    // nop

    KF_TestEvent(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // bne         $s1, $s0, L_8005C60C
    if (ctx->r17 != ctx->r16) {
        // nop
    
        goto L_8005C60C;
    }
    // nop

    // bne         $v0, $zero, L_8005C614
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005C614;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8005C5EC:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x718($a0)
    ctx->r4 = MEM_W(-0X718, ctx->r4);
    // jal         0x80062AE0
    // nop

    KF_TestEvent(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // beq         $v0, $zero, L_8005C5EC
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005C5EC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_8005C614
    // nop

    goto L_8005C614;
    // nop

L_8005C60C:
    // bne         $v0, $s0, L_8005C61C
    if (ctx->r2 != ctx->r16) {
        // nop
    
        goto L_8005C61C;
    }
    // nop

L_8005C614:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x79C($at)
    MEM_W(-0X79C, ctx->r1) = ctx->r2;
L_8005C61C:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
