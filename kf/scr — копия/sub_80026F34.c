#include "recomp.h"
#include "disable_warnings.h"

void sub_80026F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A6F($v1)
    ctx->r3 = MEM_BU(-0X4A6F, ctx->r3);
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // beq         $v1, $v0, L_80027258
    if (ctx->r3 == ctx->r2) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_80027258;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // beq         $a1, $zero, L_80027258
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80027258;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B28($v0)
    ctx->r2 = MEM_HU(-0X4B28, ctx->r2);
    // nop

    // subu        $s4, $v0, $a1
    ctx->r20 = SUB32(ctx->r2, ctx->r5);
    // bgtz        $s4, L_80026F90
    if (SIGNED(ctx->r20) > 0) {
        // sll         $v1, $a1, 11
        ctx->r3 = S32(ctx->r5) << 11;
        goto L_80026F90;
    }
    // sll         $v1, $a1, 11
    ctx->r3 = S32(ctx->r5) << 11;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_80026F90:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2A($v0)
    ctx->r2 = MEM_HU(-0X4B2A, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s4, -0x4B28($at)
    MEM_H(-0X4B28, ctx->r1) = ctx->r20;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80026FB0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026FB0;
    }
    // nop

    // break       7
    do_break(2147643308);
L_80026FB0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80026FC8
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80026FC8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80026FC8
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80026FC8;
    }
    // nop

    // break       6
    do_break(2147643332);
L_80026FC8:
    // mflo        $s2
    ctx->r18 = lo;
    // beq         $s3, $zero, L_8002709C
    if (ctx->r19 == 0) {
        // sra         $s1, $s2, 2
        ctx->r17 = S32(ctx->r18) >> 2;
        goto L_8002709C;
    }
    // sra         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18) >> 2;
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(0X0, ctx->r19);
    // lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(0X4, ctx->r19);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(0X8, ctx->r19);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // addiu       $a1, $a1, 0x352
    ctx->r5 = ADD32(ctx->r5, 0X352);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
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
    // slti        $v0, $s1, 0x50
    ctx->r2 = SIGNED(ctx->r17) < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_80027020
    if (ctx->r2 == 0) {
        // andi        $v0, $s5, 0x40
        ctx->r2 = ctx->r21 & 0X40;
        goto L_80027020;
    }
    // andi        $v0, $s5, 0x40
    ctx->r2 = ctx->r21 & 0X40;
    // ori         $s1, $zero, 0x50
    ctx->r17 = 0 | 0X50;
L_80027020:
    // beq         $v0, $zero, L_80027040
    if (ctx->r2 == 0) {
        // sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17) << 2;
        goto L_80027040;
    }
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // slti        $v0, $s1, 0x259
    ctx->r2 = SIGNED(ctx->r17) < 0X259 ? 1 : 0;
    // bne         $v0, $zero, L_80027050
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80027050;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // j           L_80027050
    // ori         $s1, $zero, 0x258
    ctx->r17 = 0 | 0X258;
    goto L_80027050;
    // ori         $s1, $zero, 0x258
    ctx->r17 = 0 | 0X258;
L_80027040:
    // slti        $v0, $s1, 0x12D
    ctx->r2 = SIGNED(ctx->r17) < 0X12D ? 1 : 0;
    // bne         $v0, $zero, L_80027050
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80027050;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // ori         $s1, $zero, 0x12C
    ctx->r17 = 0 | 0X12C;
L_80027050:
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // jal         0x80015538
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80015694
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80015694(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(0X1A, ctx->r29);
    // nop

    // slti        $v0, $v1, 0xC9
    ctx->r2 = SIGNED(ctx->r3) < 0XC9 ? 1 : 0;
    // bne         $v0, $zero, L_8002708C
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, -0xC8
        ctx->r2 = SIGNED(ctx->r3) < -0XC8 ? 1 : 0;
        goto L_8002708C;
    }
    // slti        $v0, $v1, -0xC8
    ctx->r2 = SIGNED(ctx->r3) < -0XC8 ? 1 : 0;
    // ori         $v0, $zero, 0xC8
    ctx->r2 = 0 | 0XC8;
    // j           L_800270A8
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    goto L_800270A8;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
L_8002708C:
    // beq         $v0, $zero, L_800270A8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0xC8
        ctx->r2 = ADD32(0, -0XC8);
        goto L_800270A8;
    }
    // addiu       $v0, $zero, -0xC8
    ctx->r2 = ADD32(0, -0XC8);
    // j           L_800270A8
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    goto L_800270A8;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
L_8002709C:
    // sh          $zero, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = 0;
    // sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
L_800270A8:
    // sra         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18) >> 1;
    // ori         $v0, $zero, 0x514
    ctx->r2 = 0 | 0X514;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x47
    ctx->r2 = SIGNED(ctx->r2) < 0X47 ? 1 : 0;
    // beq         $v0, $zero, L_800270D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800270D4;
    }
    // nop

    // ori         $s0, $zero, 0x46
    ctx->r16 = 0 | 0X46;
L_800270D4:
    // bne         $s4, $zero, L_800270EC
    if (ctx->r20 != 0) {
        // nop
    
        goto L_800270EC;
    }
    // nop

    // jal         0x8002C06C
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    sub_8002C06C(rdram, ctx);
    goto after_3;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_3:
    // j           L_800270F4
    // ori         $v0, $zero, 0xDAC
    ctx->r2 = 0 | 0XDAC;
    goto L_800270F4;
    // ori         $v0, $zero, 0xDAC
    ctx->r2 = 0 | 0XDAC;
L_800270EC:
    // bne         $s3, $zero, L_8002710C
    if (ctx->r19 != 0) {
        // ori         $v0, $zero, 0xDAC
        ctx->r2 = 0 | 0XDAC;
        goto L_8002710C;
    }
    // ori         $v0, $zero, 0xDAC
    ctx->r2 = 0 | 0XDAC;
L_800270F4:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A00($at)
    MEM_H(-0X4A00, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s0, -0x49FE($at)
    MEM_H(-0X49FE, ctx->r1) = ctx->r16;
    // j           L_80027258
    // nop

    goto L_80027258;
    // nop

L_8002710C:
    // jal         0x8005DBCC
    // sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18) << 2;
    KF_SquareRoot0(rdram, ctx);
    goto after_4;
    // sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18) << 2;
    after_4:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // slti        $v0, $s2, 0x10
    ctx->r2 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8002712C
    if (ctx->r2 == 0) {
        // slti        $v0, $s2, 0x2B
        ctx->r2 = SIGNED(ctx->r18) < 0X2B ? 1 : 0;
        goto L_8002712C;
    }
    // slti        $v0, $s2, 0x2B
    ctx->r2 = SIGNED(ctx->r18) < 0X2B ? 1 : 0;
    // j           L_80027138
    // ori         $s2, $zero, 0x10
    ctx->r18 = 0 | 0X10;
    goto L_80027138;
    // ori         $s2, $zero, 0x10
    ctx->r18 = 0 | 0X10;
L_8002712C:
    // bne         $v0, $zero, L_8002713C
    if (ctx->r2 != 0) {
        // andi        $v0, $s5, 0x40
        ctx->r2 = ctx->r21 & 0X40;
        goto L_8002713C;
    }
    // andi        $v0, $s5, 0x40
    ctx->r2 = ctx->r21 & 0X40;
    // ori         $s2, $zero, 0x2A
    ctx->r18 = 0 | 0X2A;
L_80027138:
    // andi        $v0, $s5, 0x40
    ctx->r2 = ctx->r21 & 0X40;
L_8002713C:
    // beq         $v0, $zero, L_80027148
    if (ctx->r2 == 0) {
        // andi        $v0, $s5, 0x80
        ctx->r2 = ctx->r21 & 0X80;
        goto L_80027148;
    }
    // andi        $v0, $s5, 0x80
    ctx->r2 = ctx->r21 & 0X80;
    // sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18) << 1;
L_80027148:
    // beq         $v0, $zero, L_80027190
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80027190;
    }
    // nop

    // jal         0x80062BF0
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    rand_recomp(rdram, ctx);
    goto after_5;
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    after_5:
    // slti        $v0, $v0, 0x4001
    ctx->r2 = SIGNED(ctx->r2) < 0X4001 ? 1 : 0;
    // bne         $v0, $zero, L_8002716C
    if (ctx->r2 != 0) {
        // negu        $v0, $s2
        ctx->r2 = SUB32(0, ctx->r18);
        goto L_8002716C;
    }
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // j           L_80027170
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_80027170;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_8002716C:
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_80027170:
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16) << 16;
    // jal         0x8002BFF4
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    sub_8002BFF4(rdram, ctx);
    goto after_6;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_6:
    // j           L_80027258
    // nop

    goto L_80027258;
    // nop

L_80027190:
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(0X12, ctx->r29);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A4A($v1)
    ctx->r3 = MEM_H(-0X4A4A, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_80027240
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80027240;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1224
    ctx->r1 = ADD32(ctx->r1, 0X1224);
    // addu        $at, $at, $v0
    gpr jr_addend_800271D0;
    jr_addend_800271D0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800271D0 >> 2) {
        case 0: goto L_800271D8; break;
        case 1: goto L_800271E8; break;
        case 2: goto L_800271F8; break;
        case 3: goto L_80027204; break;
        case 4: goto L_80027210; break;
        case 5: goto L_8002721C; break;
        case 6: goto L_80027228; break;
        case 7: goto L_80027234; break;
        default: switch_error(__func__, 0x800271D0, 0x80011224);
    }
    // nop

L_800271D8:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // j           L_80027240
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    goto L_80027240;
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
L_800271E8:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // j           L_80027240
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_80027240;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_800271F8:
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // j           L_80027240
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_80027240;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_80027204:
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    // j           L_80027240
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_80027240;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_80027210:
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    // j           L_80027240
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    goto L_80027240;
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
L_8002721C:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // j           L_8002723C
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    goto L_8002723C;
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
L_80027228:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // j           L_8002723C
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    goto L_8002723C;
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
L_80027234:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
L_8002723C:
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_80027240:
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16) << 16;
    // jal         0x8002BF60
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    sub_8002BF60(rdram, ctx);
    goto after_7;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_7:
L_80027258:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
