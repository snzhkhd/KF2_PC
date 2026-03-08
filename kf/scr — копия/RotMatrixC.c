#include "recomp.h"
#include "disable_warnings.h"

void RotMatrixC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(0X0, ctx->r16);
    // jal         0x800602D0
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    FixedCos(rdram, ctx);
    goto after_0;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    after_0:
    // lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(0X2, ctx->r16);
    // jal         0x800602D0
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    FixedCos(rdram, ctx);
    goto after_1;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_1:
    // lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(0X4, ctx->r16);
    // jal         0x800602D0
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    FixedCos(rdram, ctx);
    goto after_2;
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    after_2:
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(0X0, ctx->r16);
    // jal         0x800601F4
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    FixedSin(rdram, ctx);
    goto after_3;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_3:
    // lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(0X2, ctx->r16);
    // jal         0x800601F4
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    FixedSin(rdram, ctx);
    goto after_4;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_4:
    // lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(0X4, ctx->r16);
    // jal         0x800601F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    FixedSin(rdram, ctx);
    goto after_5;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_5:
    // mult        $s3, $s1
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // mult        $s0, $s2
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // mult        $s0, $s1
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t5
    ctx->r13 = lo;
    // mult        $s3, $s2
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // mult        $s3, $v0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t4
    ctx->r12 = lo;
    // mult        $a0, $s1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // mult        $s1, $s4
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $a3, $a3, 12
    ctx->r7 = S32(ctx->r7) >> 12;
    // mult        $s0, $s4
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9) >> 12;
    // addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // sra         $t3, $t3, 12
    ctx->r11 = S32(ctx->r11) >> 12;
    // negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // sra         $t5, $t5, 12
    ctx->r13 = S32(ctx->r13) >> 12;
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    // subu        $a1, $a1, $t5
    ctx->r5 = SUB32(ctx->r5, ctx->r13);
    // sra         $t4, $t4, 12
    ctx->r12 = S32(ctx->r12) >> 12;
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // subu        $a0, $a0, $t4
    ctx->r4 = SUB32(ctx->r4, ctx->r12);
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // mflo        $v1
    ctx->r3 = lo;
    // sra         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10) >> 12;
    // sh          $s2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r18;
    // mult        $s3, $s4
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
    // sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // sh          $a1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r5;
    // sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // sra         $a2, $a2, 12
    ctx->r6 = S32(ctx->r6) >> 12;
    // sra         $t0, $t0, 12
    ctx->r8 = S32(ctx->r8) >> 12;
    // addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // sh          $a2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r6;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // mflo        $v1
    ctx->r3 = lo;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
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
