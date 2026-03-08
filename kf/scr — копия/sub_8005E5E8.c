#include "recomp.h"
#include "disable_warnings.h"

void sub_8005E5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // addiu       $fp, $s7, 0x28
    ctx->r30 = ADD32(ctx->r23, 0X28);
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // blez        $s6, L_8005E734
    if (SIGNED(ctx->r22) <= 0) {
        // sw          $s0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r16;
        goto L_8005E734;
    }
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // addu        $s5, $s7, $zero
    ctx->r21 = ADD32(ctx->r23, 0);
    // sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22) << 1;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s6
    ctx->r2 = SUB32(ctx->r2, ctx->r22);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s0, $fp, $zero
    ctx->r16 = ADD32(ctx->r30, 0);
L_8005E64C:
    // lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(0X0, ctx->r21);
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // bne         $v0, $s6, L_8005E668
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8005E668;
    }
    // nop

    // lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(0X0, ctx->r23);
    // j           L_8005E66C
    // nop

    goto L_8005E66C;
    // nop

L_8005E668:
    // lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(0X4, ctx->r21);
L_8005E66C:
    // lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(0X10, ctx->r8);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // lw          $a3, 0x6458($a3)
    ctx->r7 = MEM_W(0X6458, ctx->r7);
    // nop

    // slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // beq         $v0, $zero, L_8005E6D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E6D0;
    }
    // nop

    // sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // nop

    // slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005E724
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8005E724;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // j           L_8005E700
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    goto L_8005E700;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8005E6D0:
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // nop

    // slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // beq         $v0, $zero, L_8005E724
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $a2
        ctx->r2 = SUB32(ctx->r3, ctx->r6);
        goto L_8005E724;
    }
    // subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
L_8005E700:
    // jal         0x8005EE1C
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    sub_8005EE1C(rdram, ctx);
    goto after_0;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005E724:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8005E64C
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_8005E64C;
    }
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8005E734:
    // addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s6, L_8005E848
    if (SIGNED(ctx->r22) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8005E848;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
L_8005E760:
    // lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(0X0, ctx->r21);
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // bne         $v0, $s6, L_8005E77C
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8005E77C;
    }
    // nop

    // lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(0X0, ctx->r30);
    // j           L_8005E780
    // nop

    goto L_8005E780;
    // nop

L_8005E77C:
    // lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(0X4, ctx->r21);
L_8005E780:
    // lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(0X10, ctx->r8);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // lw          $a3, 0x645C($a3)
    ctx->r7 = MEM_W(0X645C, ctx->r7);
    // nop

    // slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005E7E4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005E7E4;
    }
    // nop

    // sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // nop

    // slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // beq         $v0, $zero, L_8005E838
    if (ctx->r2 == 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8005E838;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // j           L_8005E814
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    goto L_8005E814;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8005E7E4:
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // nop

    // slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005E838
    if (ctx->r2 != 0) {
        // subu        $v0, $v1, $a2
        ctx->r2 = SUB32(ctx->r3, ctx->r6);
        goto L_8005E838;
    }
    // subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
L_8005E814:
    // jal         0x8005EE1C
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    sub_8005EE1C(rdram, ctx);
    goto after_1;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_1:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005E838:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8005E760
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_8005E760;
    }
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8005E848:
    // addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s6, L_8005E9B0
    if (SIGNED(ctx->r22) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8005E9B0;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s5, $s7, $zero
    ctx->r21 = ADD32(ctx->r23, 0);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s0, $fp, $zero
    ctx->r16 = ADD32(ctx->r30, 0);
L_8005E874:
    // lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(0X0, ctx->r21);
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // bne         $v0, $s6, L_8005E890
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8005E890;
    }
    // nop

    // lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(0X0, ctx->r23);
    // j           L_8005E894
    // nop

    goto L_8005E894;
    // nop

L_8005E890:
    // lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(0X4, ctx->r21);
L_8005E894:
    // lw          $v0, 0x28($t0)
    ctx->r2 = MEM_W(0X28, ctx->r8);
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005E918
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005E918;
    }
    // nop

    // sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(0X28, ctx->r5);
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005E9A0
    if (ctx->r2 == 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8005E9A0;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6454($v1)
    ctx->r3 = MEM_W(0X6454, ctx->r3);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(0XC, ctx->r8);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // sra         $a3, $a3, 12
    ctx->r7 = S32(ctx->r7) >> 12;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // j           L_8005E96C
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    goto L_8005E96C;
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
L_8005E918:
    // lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(0X28, ctx->r5);
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005E9A0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005E9A0;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6454($v0)
    ctx->r2 = MEM_W(0X6454, ctx->r2);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(0X10, ctx->r8);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
L_8005E96C:
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // jal         0x8005EE1C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8005EE1C(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005E9A0:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8005E874
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_8005E874;
    }
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8005E9B0:
    // addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s6, L_8005EB18
    if (SIGNED(ctx->r22) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8005EB18;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
L_8005E9DC:
    // lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(0X0, ctx->r21);
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // bne         $v0, $s6, L_8005E9F8
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8005E9F8;
    }
    // nop

    // lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(0X0, ctx->r30);
    // j           L_8005E9FC
    // nop

    goto L_8005E9FC;
    // nop

L_8005E9F8:
    // lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(0X4, ctx->r21);
L_8005E9FC:
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // lw          $v0, 0x28($t0)
    ctx->r2 = MEM_W(0X28, ctx->r8);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8005EA80
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EA80;
    }
    // nop

    // sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(0X28, ctx->r5);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8005EB08
    if (ctx->r2 == 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8005EB08;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6454($v1)
    ctx->r3 = MEM_W(0X6454, ctx->r3);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(0XC, ctx->r8);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // sra         $a3, $a3, 12
    ctx->r7 = S32(ctx->r7) >> 12;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // j           L_8005EAD4
    // subu        $a3, $v0, $a3
    ctx->r7 = SUB32(ctx->r2, ctx->r7);
    goto L_8005EAD4;
    // subu        $a3, $v0, $a3
    ctx->r7 = SUB32(ctx->r2, ctx->r7);
L_8005EA80:
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(0X28, ctx->r5);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8005EB08
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EB08;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6454($v0)
    ctx->r2 = MEM_W(0X6454, ctx->r2);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(0X10, ctx->r8);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
L_8005EAD4:
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // jal         0x8005EE1C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8005EE1C(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005EB08:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8005E9DC
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_8005E9DC;
    }
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8005EB18:
    // addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s6, L_8005EC80
    if (SIGNED(ctx->r22) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8005EC80;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s5, $s7, $zero
    ctx->r21 = ADD32(ctx->r23, 0);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s0, $fp, $zero
    ctx->r16 = ADD32(ctx->r30, 0);
L_8005EB44:
    // lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(0X0, ctx->r21);
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // bne         $v0, $s6, L_8005EB60
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8005EB60;
    }
    // nop

    // lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(0X0, ctx->r23);
    // j           L_8005EB64
    // nop

    goto L_8005EB64;
    // nop

L_8005EB60:
    // lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(0X4, ctx->r21);
L_8005EB64:
    // lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(0X24, ctx->r8);
    // lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(0X8, ctx->r8);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005EBE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EBE8;
    }
    // nop

    // sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(0X24, ctx->r5);
    // lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(0X8, ctx->r5);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005EC70
    if (ctx->r2 == 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8005EC70;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x644C($v1)
    ctx->r3 = MEM_W(0X644C, ctx->r3);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(0X8, ctx->r8);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // sra         $a3, $a3, 12
    ctx->r7 = S32(ctx->r7) >> 12;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // j           L_8005EC3C
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    goto L_8005EC3C;
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
L_8005EBE8:
    // lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(0X24, ctx->r5);
    // lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(0X8, ctx->r5);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005EC70
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EC70;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x644C($v0)
    ctx->r2 = MEM_W(0X644C, ctx->r2);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(0X10, ctx->r8);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
L_8005EC3C:
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // jal         0x8005EE1C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8005EE1C(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005EC70:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8005EB44
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_8005EB44;
    }
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8005EC80:
    // addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s6, L_8005EDE4
    if (SIGNED(ctx->r22) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8005EDE4;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
L_8005ECAC:
    // lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(0X0, ctx->r21);
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // bne         $v0, $s6, L_8005ECC8
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8005ECC8;
    }
    // nop

    // lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(0X0, ctx->r30);
    // j           L_8005ECCC
    // nop

    goto L_8005ECCC;
    // nop

L_8005ECC8:
    // lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(0X4, ctx->r21);
L_8005ECCC:
    // lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(0X8, ctx->r8);
    // lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(0X24, ctx->r8);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8005ED4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005ED4C;
    }
    // nop

    // sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(0X8, ctx->r5);
    // lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(0X24, ctx->r5);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8005EDD4
    if (ctx->r2 == 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8005EDD4;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x644C($v1)
    ctx->r3 = MEM_W(0X644C, ctx->r3);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(0X8, ctx->r8);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // sra         $a3, $a3, 12
    ctx->r7 = S32(ctx->r7) >> 12;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // j           L_8005EDA0
    // subu        $a3, $v0, $a3
    ctx->r7 = SUB32(ctx->r2, ctx->r7);
    goto L_8005EDA0;
    // subu        $a3, $v0, $a3
    ctx->r7 = SUB32(ctx->r2, ctx->r7);
L_8005ED4C:
    // lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(0X8, ctx->r5);
    // lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(0X24, ctx->r5);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8005EDD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EDD4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x644C($v0)
    ctx->r2 = MEM_W(0X644C, ctx->r2);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x63AC($a2)
    ctx->r6 = MEM_W(0X63AC, ctx->r6);
    // nop

    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(0X10, ctx->r8);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
L_8005EDA0:
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // jal         0x8005EE1C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8005EE1C(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8005EDD4:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8005ECAC
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_8005ECAC;
    }
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8005EDE4:
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(0X68, ctx->r29);
    // lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(0X64, ctx->r29);
    // lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(0X60, ctx->r29);
    // lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(0X5C, ctx->r29);
    // lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(0X58, ctx->r29);
    // lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(0X54, ctx->r29);
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
