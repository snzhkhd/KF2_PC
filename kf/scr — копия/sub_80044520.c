#include "recomp.h"
#include "disable_warnings.h"

void sub_80044520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // lw          $s2, 0x1184($s2)
    ctx->r18 = MEM_W(0X1184, ctx->r18);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(0X4, ctx->r3);
    // lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(0X18, ctx->r18);
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // jal         0x80015990
    // sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    sub_80015990(rdram, ctx);
    goto after_0;
    // sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // slt         $s0, $s0, $s1
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // bne         $s0, $zero, L_800445A8
    if (ctx->r16 != 0) {
        // slt         $v0, $s3, $s1
        ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
        goto L_800445A8;
    }
    // slt         $v0, $s3, $s1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // j           L_800446B8
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    goto L_800446B8;
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800445A8:
    // bne         $v0, $zero, L_800445E8
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800445E8;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lh          $a1, 0x34($s2)
    ctx->r5 = MEM_H(0X34, ctx->r18);
    // jal         0x80015D18
    // ori         $a2, $zero, 0xC00
    ctx->r6 = 0 | 0XC00;
    FixedPointLerp(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0xC00
    ctx->r6 = 0 | 0XC00;
    after_1:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lh          $a1, 0x36($s2)
    ctx->r5 = MEM_H(0X36, ctx->r18);
    // ori         $a2, $zero, 0xC00
    ctx->r6 = 0 | 0XC00;
    // jal         0x80015D18
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    FixedPointLerp(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    after_2:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lh          $a1, 0x38($s2)
    ctx->r5 = MEM_H(0X38, ctx->r18);
    // ori         $a2, $zero, 0xC00
    ctx->r6 = 0 | 0XC00;
    // jal         0x80015D18
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    FixedPointLerp(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r2;
    after_3:
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
L_800445E8:
    // lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(0X18, ctx->r29);
    // nop

    // sll         $a3, $a3, 12
    ctx->r7 = S32(ctx->r7) << 12;
    // div         $zero, $a3, $s1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_80044604
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80044604;
    }
    // nop

    // break       7
    do_break(2147763712);
L_80044604:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_8004461C
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004461C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a3, $at, L_8004461C
    if (ctx->r7 != ctx->r1) {
        // nop
    
        goto L_8004461C;
    }
    // nop

    // break       6
    do_break(2147763736);
L_8004461C:
    // mflo        $a3
    ctx->r7 = lo;
    // lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(0X1C, ctx->r29);
    // nop

    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $s1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_8004463C
    if (ctx->r17 != 0) {
        // nop
    
        goto L_8004463C;
    }
    // nop

    // break       7
    do_break(2147763768);
L_8004463C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_80044654
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80044654;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80044654
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80044654;
    }
    // nop

    // break       6
    do_break(2147763792);
L_80044654:
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // div         $zero, $v0, $s1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_80044674
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80044674;
    }
    // nop

    // break       7
    do_break(2147763824);
L_80044674:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_8004468C
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004468C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8004468C
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8004468C;
    }
    // nop

    // break       6
    do_break(2147763848);
L_8004468C:
    // mflo        $v0
    ctx->r2 = lo;
    // lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(0X64, ctx->r29);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // sh          $a3, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r7;
    // lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(0X68, ctx->r29);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // jal         0x80044184
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80044184(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
L_800446B8:
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
