#include "recomp.h"
#include "disable_warnings.h"

void AnalizingTMD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // jal         0x80062FC8
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    sub_80062FC8(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    after_0:
    // ori         $s3, $zero, 0x2
    ctx->r19 = 0 | 0X2;
    // bne         $v0, $s3, L_80065D50
    if (ctx->r2 != ctx->r19) {
        // addiu       $s2, $s0, 0xC
        ctx->r18 = ADD32(ctx->r16, 0XC);
        goto L_80065D50;
    }
    // addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x387C
    ctx->r4 = ADD32(ctx->r4, 0X387C);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80065D50:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $s3, L_80065D80
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80065D80;
    }
    // nop

    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(0X0, ctx->r16);
    // lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(0X4, ctx->r16);
    // lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(0X8, ctx->r16);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3890
    ctx->r4 = ADD32(ctx->r4, 0X3890);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80065D80:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // bne         $v0, $s3, L_80065DB4
    if (ctx->r2 != ctx->r19) {
        // sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17) << 3;
        goto L_80065DB4;
    }
    // sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17) << 3;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(0X0, ctx->r2);
    // lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(0X4, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x38B8
    ctx->r4 = ADD32(ctx->r4, 0X38B8);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_80065DB4:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // bne         $v0, $s3, L_80065DE8
    if (ctx->r2 != ctx->r19) {
        // sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17) << 3;
        goto L_80065DE8;
    }
    // sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17) << 3;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(0X8, ctx->r2);
    // lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(0XC, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x38D0
    ctx->r4 = ADD32(ctx->r4, 0X38D0);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_80065DE8:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // bne         $v0, $s3, L_80065E24
    if (ctx->r2 != ctx->r19) {
        // sll         $v1, $s1, 3
        ctx->r3 = S32(ctx->r17) << 3;
        goto L_80065E24;
    }
    // sll         $v1, $s1, 3
    ctx->r3 = S32(ctx->r17) << 3;
    // sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17) << 3;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(0X10, ctx->r2);
    // lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(0X14, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x38E8
    ctx->r4 = ADD32(ctx->r4, 0X38E8);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // sll         $v1, $s1, 3
    ctx->r3 = S32(ctx->r17) << 3;
L_80065E24:
    // subu        $v1, $v1, $s1
    ctx->r3 = SUB32(ctx->r3, ctx->r17);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(0X10, ctx->r3);
    // nop

    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(0X14, ctx->r3);
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
