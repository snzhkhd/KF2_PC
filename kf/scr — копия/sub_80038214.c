#include "recomp.h"
#include "disable_warnings.h"

void sub_80038214(uint8_t* rdram, recomp_context* ctx) {
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
    // lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // addiu       $s1, $s1, -0x6810
    ctx->r17 = ADD32(ctx->r17, -0X6810);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // ori         $s2, $zero, 0x18C
    ctx->r18 = 0 | 0X18C;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $s1, -0x1E00
    ctx->r20 = ADD32(ctx->r17, -0X1E00);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, 0x6
    ctx->r16 = ADD32(ctx->r17, 0X6);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80038248:
    // lbu         $v1, -0x2($s0)
    ctx->r3 = MEM_BU(-0X2, ctx->r16);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // beq         $v1, $v0, L_80038294
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x51
        ctx->r2 = 0 | 0X51;
        goto L_80038294;
    }
    // ori         $v0, $zero, 0x51
    ctx->r2 = 0 | 0X51;
    // bne         $v1, $v0, L_800382D8
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800382D8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v1, 0x35($s0)
    ctx->r3 = MEM_BU(0X35, ctx->r16);
    // nop

    // beq         $v1, $v0, L_800382D8
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800382D8;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lbu         $a2, 0x17($v0)
    ctx->r6 = MEM_BU(0X17, ctx->r2);
    // j           L_800382D0
    // nop

    goto L_800382D0;
    // nop

L_80038294:
    // lbu         $v1, 0x32($s0)
    ctx->r3 = MEM_BU(0X32, ctx->r16);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // beq         $v1, $v0, L_800382D8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800382D8;
    }
    // nop

    // lhu         $a0, 0x34($s0)
    ctx->r4 = MEM_HU(0X34, ctx->r16);
    // lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(0X0, ctx->r17);
    // jal         0x8003804C
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_8003804C(rdram, ctx);
    goto after_0;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lbu         $a2, 0xC($v0)
    ctx->r6 = MEM_BU(0XC, ctx->r2);
L_800382D0:
    // jal         0x80038120
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_80038120(rdram, ctx);
    goto after_1;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
L_800382D8:
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // bne         $s2, $zero, L_80038248
    if (ctx->r18 != 0) {
        // addiu       $s1, $s1, 0x44
        ctx->r17 = ADD32(ctx->r17, 0X44);
        goto L_80038248;
    }
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
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
