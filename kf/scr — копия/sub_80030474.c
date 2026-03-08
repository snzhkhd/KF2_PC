#include "recomp.h"
#include "disable_warnings.h"

void sub_80030474(uint8_t* rdram, recomp_context* ctx) 
{
    //int a1 = (int)ctx->r4;
    //printf("[sub_80030474] a1=%d dword_80194F5C=%d\n",
    //    a1, *(int*)GET_PTR(0x80194F5C));

    /*if (a1 <= 0 || a1 > 10000) {
        printf("[sub_80030474] suspicious a1, skip\n");
        ctx->r2 = 0;
        return;
    }*/
    //*(int32_t*)GET_PTR(0x80194F5C) = 100000;
    * (int32_t*)GET_PTR(0x80194F5C) = 0x9000;

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4F5C($v1)
    ctx->r3 = MEM_W(0X4F5C, ctx->r3);
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // lw          $s3, 0xB54($s3)
    ctx->r19 = MEM_W(0XB54, ctx->r19);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // addiu       $s2, $s2, 0xC48
    ctx->r18 = ADD32(ctx->r18, 0XC48);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // slti        $v0, $v1, 0x7D00
    ctx->r2 = SIGNED(ctx->r3) < 0X7D00 ? 1 : 0;
    // bne         $v0, $zero, L_80030500
    if (ctx->r2 != 0) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_80030500;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_800305D0
    if (ctx->r17 == ctx->r2) {
        // addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
        goto L_800305D0;
    }
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s0, $s2, 0x6
    ctx->r16 = ADD32(ctx->r18, 0X6);
L_800304C8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x8005F2C8
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    sub_8005F2C8(rdram, ctx);
    goto after_0;
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    after_0:
    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s4, L_800304C8
    if (ctx->r17 != ctx->r20) {
        // addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
        goto L_800304C8;
    }
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // j           L_800305D0
    // nop

    goto L_800305D0;
    // nop

L_80030500:
    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // beq         $v0, $zero, L_80030570
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80030570;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // beq         $s1, $v0, L_800305D0
    if (ctx->r17 == ctx->r2) {
        // addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
        goto L_800305D0;
    }
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s0, $s2, 0x6
    ctx->r16 = ADD32(ctx->r18, 0X6);
L_8003051C:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x8005F2C8
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    sub_8005F2C8(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    after_1:
    // lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(0X10, ctx->r29);
    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // addiu       $v1, $v1, -0x320
    ctx->r3 = ADD32(ctx->r3, -0X320);
    // bgez        $v1, L_80030548
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $v1, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r3;
        goto L_80030548;
    }
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80030548:
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // bne         $s1, $s4, L_8003051C
    if (ctx->r17 != ctx->r20) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8003051C;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // j           L_800305D0
    // nop

    goto L_800305D0;
    // nop

L_80030570:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // beq         $s1, $v0, L_800305D0
    if (ctx->r17 == ctx->r2) {
        // addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
        goto L_800305D0;
    }
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s0, $s2, 0x6
    ctx->r16 = ADD32(ctx->r18, 0X6);
L_80030580:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x8005F2C8
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    sub_8005F2C8(rdram, ctx);
    goto after_2;
    // addiu       $a3, $sp, 0x14
    ctx->r7 = ADD32(ctx->r29, 0X14);
    after_2:
    // lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(0X10, ctx->r29);
    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // slti        $v0, $v1, 0xAF0
    ctx->r2 = SIGNED(ctx->r3) < 0XAF0 ? 1 : 0;
    // bne         $v0, $zero, L_800305B8
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_800305B8;
    }
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $v0, $v1, -0xAF0
    ctx->r2 = ADD32(ctx->r3, -0XAF0);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800305B8:
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // bne         $s1, $s4, L_80030580
    if (ctx->r17 != ctx->r20) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80030580;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800305D0:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
