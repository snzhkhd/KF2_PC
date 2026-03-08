#include "recomp.h"
#include "disable_warnings.h"

void sub_80036DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // lw          $s7, 0x78($sp)
    ctx->r23 = MEM_W(0X78, ctx->r29);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // jal         0x80034A2C
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    sub_80034A2C(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // bne         $s1, $zero, L_80036E34
    if (ctx->r17 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80036E34;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $zero, 0x4($s7)
    MEM_H(0X4, ctx->r23) = 0;
    // sh          $zero, 0x2($s7)
    MEM_H(0X2, ctx->r23) = 0;
    // j           L_8003703C
    // sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    goto L_8003703C;
    // sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
L_80036E34:
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // nop

    // addu        $a2, $s1, $v0
    ctx->r6 = ADD32(ctx->r17, ctx->r2);
    // slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80036E9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80036E9C;
    }
    // nop

L_80036E4C:
    // andi        $v1, $s0, 0x7F
    ctx->r3 = ctx->r16 & 0X7F;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(0XC, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $a2, $v0
    ctx->r16 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $s5, 3
    ctx->r2 = S32(ctx->r21) << 3;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x3($s7)
    do_swl(rdram, 0X3, ctx->r23, ctx->r3);
    // swr         $v1, 0x0($s7)
    do_swr(rdram, 0X0, ctx->r23, ctx->r3);
    // swl         $a0, 0x7($s7)
    do_swl(rdram, 0X7, ctx->r23, ctx->r4);
    // j           L_80037038
    // swr         $a0, 0x4($s7)
    do_swr(rdram, 0X4, ctx->r23, ctx->r4);
    goto L_80037038;
    // swr         $a0, 0x4($s7)
    do_swr(rdram, 0X4, ctx->r23, ctx->r4);
L_80036E9C:
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80036EB4
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80036EB4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // j           L_80036E4C
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_80036E4C;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80036EB4:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
    // lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(0XC, ctx->r6);
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $a2, $v0
    ctx->r16 = ADD32(ctx->r6, ctx->r2);
    // jal         0x800365CC
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sub_800365CC(rdram, ctx);
    goto after_1;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // sll         $v1, $s5, 3
    ctx->r3 = S32(ctx->r21) << 3;
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lwl         $a0, 0x3($v1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X3, ctx->r3);
    // lwr         $a0, 0x0($v1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r3);
    // lwl         $a1, 0x7($v1)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r3);
    // lwr         $a1, 0x4($v1)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r3);
    // swl         $a0, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r4);
    // swr         $a0, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r4);
    // swl         $a1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r5);
    // swr         $a1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r5);
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // lhu         $s0, 0x6($s4)
    ctx->r16 = MEM_HU(0X6, ctx->r20);
    // lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(0XC, ctx->r17);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addu        $s3, $s1, $v0
    ctx->r19 = ADD32(ctx->r17, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80036F7C
    if (ctx->r16 == ctx->r2) {
        // addiu       $s2, $s4, 0x8
        ctx->r18 = ADD32(ctx->r20, 0X8);
        goto L_80036F7C;
    }
    // addiu       $s2, $s4, 0x8
    ctx->r18 = ADD32(ctx->r20, 0X8);
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80036F24:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // jal         0x80036A8C
    // addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    sub_80036A8C(rdram, ctx);
    goto after_2;
    // addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_2:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // beq         $a1, $zero, L_80036F74
    if (ctx->r5 == 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_80036F74;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // nop

    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // nop

    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
L_80036F74:
    // bne         $s0, $s6, L_80036F24
    if (ctx->r16 != ctx->r22) {
        // nop
    
        goto L_80036F24;
    }
    // nop

L_80036F7C:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // jal         0x80036A8C
    // addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    sub_80036A8C(rdram, ctx);
    goto after_3;
    // addu        $a0, $s1, $a0
    ctx->r4 = ADD32(ctx->r17, ctx->r4);
    after_3:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // beq         $a1, $zero, L_80037018
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80037018;
    }
    // nop

    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(0X0, ctx->r5);
    // lh          $a0, 0x18($sp)
    ctx->r4 = MEM_H(0X18, ctx->r29);
    // lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(0X24, ctx->r29);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(0X0, ctx->r5);
    // lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(0X1A, ctx->r29);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(0X2, ctx->r5);
    // lh          $a0, 0x1C($sp)
    ctx->r4 = MEM_H(0X1C, ctx->r29);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
L_80037018:
    // lwl         $v0, 0x1B($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1B, ctx->r29);
    // lwr         $v0, 0x18($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X18, ctx->r29);
    // lwl         $v1, 0x1F($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X1F, ctx->r29);
    // lwr         $v1, 0x1C($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X1C, ctx->r29);
    // swl         $v0, 0x3($s7)
    do_swl(rdram, 0X3, ctx->r23, ctx->r2);
    // swr         $v0, 0x0($s7)
    do_swr(rdram, 0X0, ctx->r23, ctx->r2);
    // swl         $v1, 0x7($s7)
    do_swl(rdram, 0X7, ctx->r23, ctx->r3);
    // swr         $v1, 0x4($s7)
    do_swr(rdram, 0X4, ctx->r23, ctx->r3);
L_80037038:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003703C:
    // lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(0X60, ctx->r29);
    // lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
