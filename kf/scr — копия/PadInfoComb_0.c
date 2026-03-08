#include "recomp.h"
#include "disable_warnings.h"

void PadInfoComb_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // lw          $s5, -0xB88($s5)
    ctx->r21 = MEM_W(-0XB88, ctx->r21);
    // sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18) << 2;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
L_8004CD94:
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // bne         $s2, $v0, L_8004CDC8
    if (ctx->r18 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004CDC8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB78($v0)
    ctx->r2 = MEM_BU(-0XB78, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // bne         $v0, $zero, L_8004CDC8
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004CDC8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x8004E0D0
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    sub_8004E0D0(rdram, ctx);
    goto after_0;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // j           L_8004CE3C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004CE3C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004CDC8:
    // beq         $s2, $v0, L_8004CE1C
    if (ctx->r18 == ctx->r2) {
        // andi        $a0, $s4, 0xFF
        ctx->r4 = ctx->r20 & 0XFF;
        goto L_8004CE1C;
    }
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // jal         0x8004E0D0
    // nop

    sub_8004E0D0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // beq         $s1, $zero, L_8004CE10
    if (ctx->r17 == 0) {
        // nop
    
        goto L_8004CE10;
    }
    // nop

    // lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(0X0, ctx->r22);
    // nop

    // beq         $v0, $zero, L_8004CE10
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_8004CE10;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // bne         $v0, $zero, L_8004CE34
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004CE34;
    }
    // nop

L_8004CE10:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s5, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r21;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
L_8004CE1C:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_8004CE4C
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004CE4C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004CE34:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004CE3C:
    // bne         $s0, $v0, L_8004CD94
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8004CD94;
    }
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s5, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r21;
L_8004CE4C:
    // bne         $v0, $zero, L_8004CE68
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8004CE68;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8004D68C
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    InitDmaChannel(rdram, ctx);
    goto after_4;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // j           L_8004CE6C
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    goto L_8004CE6C;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8004CE68:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004CE6C:
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
