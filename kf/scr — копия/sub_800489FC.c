#include "recomp.h"
#include "disable_warnings.h"

void sub_800489FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // beq         $v0, $zero, L_80048A90
    if (ctx->r2 == 0) {
        // sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
        goto L_80048A90;
    }
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // andi        $s1, $v1, 0xFFFE
    ctx->r17 = ctx->r3 & 0XFFFE;
    // srl         $v1, $s1, 1
    ctx->r3 = S32(U32(ctx->r17) >> 1);
    // subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2) << 16;
    // sll         $s2, $v1, 16
    ctx->r18 = S32(ctx->r3) << 16;
    // sb          $a1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r5;
    // sh          $a2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r6;
L_80048A48:
    // lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(0X18, ctx->r16);
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    // jal         0x80015798
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_0;
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    after_0:
    // bne         $v0, $zero, L_80048A80
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80048A80;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // jal         0x800360A0
    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    KF_GpuUpdate(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    after_1:
    // j           L_80048A48
    // nop

    goto L_80048A48;
    // nop

L_80048A80:
    // andi        $v0, $s4, 0xFFF
    ctx->r2 = ctx->r20 & 0XFFF;
    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_2;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
L_80048A90:
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
