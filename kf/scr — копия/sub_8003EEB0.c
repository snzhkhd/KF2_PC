#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(0X74, ctx->r29);
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(0X6C, ctx->r29);
    // lhu         $t0, 0x70($sp)
    ctx->r8 = MEM_HU(0X70, ctx->r29);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // ori         $s5, $zero, 0x1000
    ctx->r21 = 0 | 0X1000;
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(0X0, ctx->r20);
    // lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(0X4, ctx->r20);
    // lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(0X8, ctx->r20);
    // lw          $a2, 0xC($s4)
    ctx->r6 = MEM_W(0XC, ctx->r20);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s7, $v0, 16
    ctx->r23 = S32(ctx->r2) >> 16;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
L_8003EF34:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(0X4, ctx->r16);
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(0X8, ctx->r16);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // addiu       $a1, $a1, 0x640
    ctx->r5 = ADD32(ctx->r5, 0X640);
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // subu        $a2, $v1, $a2
    ctx->r6 = SUB32(ctx->r3, ctx->r6);
    // jal         0x800159DC
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_VectorToAngles(rdram, ctx);
    goto after_0;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_0:
    // lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(0X22, ctx->r29);
    // lh          $a1, 0x42($s3)
    ctx->r5 = MEM_H(0X42, ctx->r19);
    // nop

    // subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // andi        $a2, $v0, 0xFFF
    ctx->r6 = ctx->r2 & 0XFFF;
    // slti        $v0, $a2, 0x800
    ctx->r2 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003EF84
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003EF84;
    }
    // nop

    // subu        $a2, $s5, $a2
    ctx->r6 = SUB32(ctx->r21, ctx->r6);
L_8003EF84:
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // sll         $v1, $a2, 12
    ctx->r3 = S32(ctx->r6) << 12;
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8003EFA4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003EFA4;
    }
    // nop

    // break       7
    do_break(2147741600);
L_8003EFA4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003EFBC
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003EFBC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8003EFBC
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8003EFBC;
    }
    // nop

    // break       6
    do_break(2147741624);
L_8003EFBC:
    // mflo        $a2
    ctx->r6 = lo;
    // nop

    // slti        $v0, $a2, 0x1001
    ctx->r2 = SIGNED(ctx->r6) < 0X1001 ? 1 : 0;
    // bne         $v0, $zero, L_8003EFD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003EFD4;
    }
    // nop

    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
L_8003EFD4:
    // jal         0x80015D30
    // nop

    sub_80015D30(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s7, $v0, L_8003F020
    if (ctx->r23 != ctx->r2) {
        // nop
    
        goto L_8003F020;
    }
    // nop

    // lh          $a0, 0x20($sp)
    ctx->r4 = MEM_H(0X20, ctx->r29);
    // lh          $a1, 0x40($s3)
    ctx->r5 = MEM_H(0X40, ctx->r19);
    // nop

    // subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // andi        $a2, $v0, 0xFFF
    ctx->r6 = ctx->r2 & 0XFFF;
    // slti        $v0, $a2, 0x800
    ctx->r2 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003F010
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003F010;
    }
    // nop

    // subu        $a2, $s5, $a2
    ctx->r6 = SUB32(ctx->r21, ctx->r6);
L_8003F010:
    // jal         0x80015D30
    // nop

    sub_80015D30(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8003F024
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    goto L_8003F024;
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
L_8003F020:
    // sh          $fp, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r30;
L_8003F024:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // jal         0x80015538
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_3;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_3:
    // sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80015694
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    sub_80015694(rdram, ctx);
    goto after_4;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_4:
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // beq         $s2, $zero, L_8003F0BC
    if (ctx->r18 == 0) {
        // nop
    
        goto L_8003F0BC;
    }
    // nop

    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(0X14, ctx->r29);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x80015990
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_80015990(rdram, ctx);
    goto after_5;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_5:
    // div         $zero, $v0, $s1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_8003F084
    if (ctx->r17 != 0) {
        // nop
    
        goto L_8003F084;
    }
    // nop

    // break       7
    do_break(2147741824);
L_8003F084:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_8003F09C
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003F09C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003F09C
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003F09C;
    }
    // nop

    // break       6
    do_break(2147741848);
L_8003F09C:
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A54
    ctx->r5 = ADD32(ctx->r5, -0X4A54);
    // jal         0x80016168
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    sub_80016168(rdram, ctx);
    goto after_6;
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_6:
    // j           L_8003EF34
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    goto L_8003EF34;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
L_8003F0BC:
    // lh          $v0, 0x22($sp)
    ctx->r2 = MEM_H(0X22, ctx->r29);
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(0X50, ctx->r29);
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
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
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
