#include "recomp.h"
#include "disable_warnings.h"

void sub_80015DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(0X48, ctx->r29);
    // nop

    // mult        $s5, $s5
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // mflo        $s4
    ctx->r20 = lo;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // mflo        $s0
    ctx->r16 = lo;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sra         $a0, $s4, 6
    ctx->r4 = S32(ctx->r20) >> 6;
    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // mflo        $a1
    ctx->r5 = lo;
    // mult        $s0, $s2
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18) >> 2;
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // mflo        $a2
    ctx->r6 = lo;
    // mult        $s1, $a0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19) >> 2;
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(0X50, ctx->r29);
    // subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // mflo        $v0
    ctx->r2 = lo;
    // subu        $a0, $a1, $v0
    ctx->r4 = SUB32(ctx->r5, ctx->r2);
    // bltz        $a0, L_80015F0C
    if (SIGNED(ctx->r4) < 0) {
        // sw          $ra, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r31;
        goto L_80015F0C;
    }
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // jal         0x8005DBCC
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    KF_SquareRoot0(rdram, ctx);
    goto after_0;
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    after_0:
    // mult        $s3, $s1
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // sra         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20) >> 2;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // bne         $s0, $zero, L_80015EAC
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80015EAC;
    }
    // nop

    // break       7
    do_break(2147573416);
L_80015EAC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_80015EC4
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015EC4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80015EC4
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80015EC4;
    }
    // nop

    // break       6
    do_break(2147573440);
L_80015EC4:
    // mflo        $a2
    ctx->r6 = lo;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // div         $zero, $v1, $s0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r16)));
    // bne         $s0, $zero, L_80015EE0
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80015EE0;
    }
    // nop

    // break       7
    do_break(2147573468);
L_80015EE0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_80015EF8
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015EF8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80015EF8
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80015EF8;
    }
    // nop

    // break       6
    do_break(2147573492);
L_80015EF8:
    // mflo        $v1
    ctx->r3 = lo;
    // bgtz        $a2, L_80015F14
    if (SIGNED(ctx->r6) > 0) {
        // nop
    
        goto L_80015F14;
    }
    // nop

    // bgtz        $v1, L_80015F14
    if (SIGNED(ctx->r3) > 0) {
        // nop
    
        goto L_80015F14;
    }
    // nop

L_80015F0C:
    // j           L_80016028
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80016028;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015F14:
    // bne         $s6, $zero, L_80015F2C
    if (ctx->r22 != 0) {
        // slt         $v0, $a2, $v1
        ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_80015F2C;
    }
    // slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // blez        $a2, L_80015F3C
    if (SIGNED(ctx->r6) <= 0) {
        // addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
        goto L_80015F3C;
    }
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // j           L_80015F30
    // slt         $v0, $s0, $a2
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    goto L_80015F30;
    // slt         $v0, $s0, $a2
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
L_80015F2C:
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80015F30:
    // bne         $v0, $zero, L_80015F3C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80015F3C;
    }
    // nop

    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
L_80015F3C:
    // jal         0x8005DBCC
    // sll         $a0, $s0, 14
    ctx->r4 = S32(ctx->r16) << 14;
    KF_SquareRoot0(rdram, ctx);
    goto after_1;
    // sll         $a0, $s0, 14
    ctx->r4 = S32(ctx->r16) << 14;
    after_1:
    // sll         $a1, $s2, 14
    ctx->r5 = S32(ctx->r18) << 14;
    // div         $zero, $a1, $s5
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r21)));
    // bne         $s5, $zero, L_80015F58
    if (ctx->r21 != 0) {
        // nop
    
        goto L_80015F58;
    }
    // nop

    // break       7
    do_break(2147573588);
L_80015F58:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s5, $at, L_80015F70
    if (ctx->r21 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015F70;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_80015F70
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_80015F70;
    }
    // nop

    // break       6
    do_break(2147573612);
L_80015F70:
    // mflo        $a1
    ctx->r5 = lo;
    // nop

    // div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80015F88
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80015F88;
    }
    // nop

    // break       7
    do_break(2147573636);
L_80015F88:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80015FA0
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015FA0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_80015FA0
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_80015FA0;
    }
    // nop

    // break       6
    do_break(2147573660);
L_80015FA0:
    // mflo        $a1
    ctx->r5 = lo;
    // mult        $s1, $s0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $s5, 1
    ctx->r3 = S32(ctx->r21) >> 1;
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $s3, $a0
    ctx->r4 = ADD32(ctx->r19, ctx->r4);
    // sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) << 12;
    // div         $zero, $a0, $v1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80015FCC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80015FCC;
    }
    // nop

    // break       7
    do_break(2147573704);
L_80015FCC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80015FE4
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015FE4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80015FE4
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80015FE4;
    }
    // nop

    // break       6
    do_break(2147573728);
L_80015FE4:
    // mflo        $a0
    ctx->r4 = lo;
    // sra         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) >> 1;
    // div         $zero, $a0, $v1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80015FFC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80015FFC;
    }
    // nop

    // break       7
    do_break(2147573752);
L_80015FFC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80016014
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80016014;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80016014
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80016014;
    }
    // nop

    // break       6
    do_break(2147573776);
L_80016014:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80015804
    // sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    Math_Atan2_Fixed(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    after_2:
    // sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80016028:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
