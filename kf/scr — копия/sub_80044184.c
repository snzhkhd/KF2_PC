#include "recomp.h"
#include "disable_warnings.h"

void sub_80044184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // lw          $s1, 0x1184($s1)
    ctx->r17 = MEM_W(0X1184, ctx->r17);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // jal         0x80015694
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015694(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // lhu         $v0, 0x34($s1)
    ctx->r2 = MEM_HU(0X34, ctx->r17);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x36($s1)
    ctx->r2 = MEM_HU(0X36, ctx->r17);
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // lh          $a0, 0x34($s1)
    ctx->r4 = MEM_H(0X34, ctx->r17);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x38($s1)
    ctx->r2 = MEM_HU(0X38, ctx->r17);
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // lh          $a1, 0x36($s1)
    ctx->r5 = MEM_H(0X36, ctx->r17);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x80015990
    // sh          $v0, 0x38($s1)
    MEM_H(0X38, ctx->r17) = ctx->r2;
    sub_80015990(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x38($s1)
    MEM_H(0X38, ctx->r17) = ctx->r2;
    after_1:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // slt         $v0, $s2, $a1
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_800442E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800442E0;
    }
    // nop

    // lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(0X34, ctx->r17);
    // nop

    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_80044240
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80044240;
    }
    // nop

    // break       7
    do_break(2147762748);
L_80044240:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_80044258
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80044258;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80044258
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80044258;
    }
    // nop

    // break       6
    do_break(2147762772);
L_80044258:
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x36($s1)
    ctx->r2 = MEM_H(0X36, ctx->r17);
    // nop

    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8004427C
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8004427C;
    }
    // nop

    // break       7
    do_break(2147762808);
L_8004427C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_80044294
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80044294;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80044294
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80044294;
    }
    // nop

    // break       6
    do_break(2147762832);
L_80044294:
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x38($s1)
    ctx->r2 = MEM_H(0X38, ctx->r17);
    // nop

    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_800442B8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_800442B8;
    }
    // nop

    // break       7
    do_break(2147762868);
L_800442B8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_800442D0
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800442D0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800442D0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800442D0;
    }
    // nop

    // break       6
    do_break(2147762892);
L_800442D0:
    // mflo        $v0
    ctx->r2 = lo;
    // sh          $a0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r4;
    // sh          $v1, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r3;
    // sh          $v0, 0x38($s1)
    MEM_H(0X38, ctx->r17) = ctx->r2;
L_800442E0:
    // lh          $v0, 0x34($s1)
    ctx->r2 = MEM_H(0X34, ctx->r17);
    // lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(0X14, ctx->r17);
    // lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(0X18, ctx->r17);
    // lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(0X1C, ctx->r17);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // lh          $v0, 0x36($s1)
    ctx->r2 = MEM_H(0X36, ctx->r17);
    // lh          $v1, 0x38($s1)
    ctx->r3 = MEM_H(0X38, ctx->r17);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s3, $v0, L_80044320
    if (ctx->r19 != ctx->r2) {
        // sw          $v1, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r3;
        goto L_80044320;
    }
    // sw          $v1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r3;
    // j           L_80044338
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80044338;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80044320:
    // addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x800424C8
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_800424C8(rdram, ctx);
    goto after_2;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_2:
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80044338:
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
