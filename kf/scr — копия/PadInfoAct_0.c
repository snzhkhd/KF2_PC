#include "recomp.h"
#include "disable_warnings.h"

void PadInfoAct_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
L_8004CC5C:
    // nop

    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // beq         $v0, $zero, L_8004CCD4
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_8004CCD4;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_0;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // bne         $v0, $zero, L_8004CCF8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004CCF8;
    }
    // nop

L_8004CCD4:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s4, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r20;
    // andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8004DBE0
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    CD_cw_8004DBE0(rdram, ctx);
    goto after_1;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_1:
    // beq         $v0, $zero, L_8004CD18
    if (ctx->r2 == 0) {
        // addiu       $v0, $s6, 0x1
        ctx->r2 = ADD32(ctx->r22, 0X1);
        goto L_8004CD18;
    }
    // addiu       $v0, $s6, 0x1
    ctx->r2 = ADD32(ctx->r22, 0X1);
L_8004CCF8:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_8004CC5C
    if (ctx->r16 != ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8004CC5C;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s4, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r20;
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // addiu       $v0, $s6, 0x1
    ctx->r2 = ADD32(ctx->r22, 0X1);
L_8004CD18:
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
