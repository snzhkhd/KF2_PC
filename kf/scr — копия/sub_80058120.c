#include "recomp.h"
#include "disable_warnings.h"

void sub_80058120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4) << 16;
    // srl         $v1, $t0, 24
    ctx->r3 = S32(U32(ctx->r8) >> 24);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // sra         $s2, $t0, 16
    ctx->r18 = S32(ctx->r8) >> 16;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sra         $s1, $a2, 16
    ctx->r17 = S32(ctx->r6) >> 16;
    // sra         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5) >> 16;
    // lhu         $s5, 0x50($sp)
    ctx->r21 = MEM_HU(0X50, ctx->r29);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x8005984C
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    sub_8005984C(rdram, ctx);
    goto after_0;
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    after_0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49D8($v0)
    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s0, -0x191A($at)
    MEM_H(-0X191A, ctx->r1) = ctx->r16;
    // sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80058668
    if (ctx->r2 == 0) {
        // addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
        goto L_80058668;
    }
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // addu        $t0, $s2, $zero
    ctx->r8 = ADD32(ctx->r18, 0);
    // ori         $t4, $zero, 0x7F
    ctx->r12 = 0 | 0X7F;
    // ori         $t5, $zero, 0x3F01
    ctx->r13 = 0 | 0X3F01;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6) << 4;
    // ori         $t3, $zero, 0x3F
    ctx->r11 = 0 | 0X3F;
    // lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // addiu       $t7, $t7, -0x7748
    ctx->r15 = ADD32(ctx->r15, -0X7748);
    // addiu       $s0, $t7, 0x2
    ctx->r16 = ADD32(ctx->r15, 0X2);
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_800581FC:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A2
    ctx->r1 = ADD32(ctx->r1, -0X75A2);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // nop

    // bne         $v0, $t0, L_8005864C
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_8005864C;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // nop

    // bne         $v0, $a2, L_8005864C
    if (ctx->r2 != ctx->r6) {
        // sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23) << 16;
        goto L_8005864C;
    }
    // sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23) << 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759A
    ctx->r1 = ADD32(ctx->r1, -0X759A);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_8005864C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005864C;
    }
    // nop

    // lbu         $v0, 0x12($s3)
    ctx->r2 = MEM_BU(0X12, ctx->r19);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $a0, $v0, $s3
    ctx->r4 = ADD32(ctx->r2, ctx->r19);
    // lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(0X4E, ctx->r4);
    // andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // beq         $v1, $v0, L_80058294
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80058294;
    }
    // nop

    // bne         $v1, $zero, L_80058298
    if (ctx->r3 != 0) {
        // andi        $v0, $t2, 0xFF
        ctx->r2 = ctx->r10 & 0XFF;
        goto L_80058298;
    }
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r2;
L_80058294:
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_80058298:
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A8
    ctx->r1 = ADD32(ctx->r1, -0X75A8);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // nop

    // div         $zero, $a0, $t4
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r12)));
    // bne         $t4, $zero, L_800582E0
    if (ctx->r12 != 0) {
        // nop
    
        goto L_800582E0;
    }
    // nop

    // break       7
    do_break(2147844828);
L_800582E0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $t4, $at, L_800582F8
    if (ctx->r12 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800582F8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_800582F8
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_800582F8;
    }
    // nop

    // break       6
    do_break(2147844852);
L_800582F8:
    // mflo        $a0
    ctx->r4 = lo;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2550($v0)
    ctx->r2 = MEM_W(-0X2550, ctx->r2);
    // nop

    // lbu         $v1, 0x18($v0)
    ctx->r3 = MEM_BU(0X18, ctx->r2);
    // nop

    // sll         $v0, $v1, 14
    ctx->r2 = S32(ctx->r3) << 14;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // div         $zero, $v0, $t5
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r13)));
    // bne         $t5, $zero, L_80058338
    if (ctx->r13 != 0) {
        // nop
    
        goto L_80058338;
    }
    // nop

    // break       7
    do_break(2147844916);
L_80058338:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $t5, $at, L_80058350
    if (ctx->r13 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80058350;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80058350
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80058350;
    }
    // nop

    // break       6
    do_break(2147844940);
L_80058350:
    // mflo        $a3
    ctx->r7 = lo;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2560($v0)
    ctx->r2 = MEM_W(-0X2560, ctx->r2);
    // nop

    // addu        $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(0X1, ctx->r2);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $a0, 0x0($at)
    ctx->r4 = MEM_H(0X0, ctx->r1);
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lw          $a1, -0x1A08($a1)
    ctx->r5 = MEM_W(-0X1A08, ctx->r5);
    // addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // divu        $zero, $v1, $t5
    lo = S32(U32(ctx->r3) / U32(ctx->r13)); hi = S32(U32(ctx->r3) % U32(ctx->r13));
    // bne         $t5, $zero, L_800583C4
    if (ctx->r13 != 0) {
        // nop
    
        goto L_800583C4;
    }
    // nop

    // break       7
    do_break(2147845056);
L_800583C4:
    // mflo        $v1
    ctx->r3 = lo;
    // lhu         $v0, 0x74($s3)
    ctx->r2 = MEM_HU(0X74, ctx->r19);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t4
    lo = S32(U32(ctx->r2) / U32(ctx->r12)); hi = S32(U32(ctx->r2) % U32(ctx->r12));
    // bne         $t4, $zero, L_800583F0
    if (ctx->r12 != 0) {
        // nop
    
        goto L_800583F0;
    }
    // nop

    // break       7
    do_break(2147845100);
L_800583F0:
    // mflo        $a3
    ctx->r7 = lo;
    // lhu         $v0, 0x76($s3)
    ctx->r2 = MEM_HU(0X76, ctx->r19);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t4
    lo = S32(U32(ctx->r2) / U32(ctx->r12)); hi = S32(U32(ctx->r2) % U32(ctx->r12));
    // bne         $t4, $zero, L_8005841C
    if (ctx->r12 != 0) {
        // nop
    
        goto L_8005841C;
    }
    // nop

    // break       7
    do_break(2147845144);
L_8005841C:
    // mflo        $t1
    ctx->r9 = lo;
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(0X3, ctx->r4);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80058464
    if (ctx->r2 == 0) {
        // mult        $t1, $v1
        result = S64(S32(ctx->r9)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80058464;
    }
    // mult        $t1, $v1
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t3
    lo = S32(U32(ctx->r2) / U32(ctx->r11)); hi = S32(U32(ctx->r2) % U32(ctx->r11));
    // bne         $t3, $zero, L_80058458
    if (ctx->r11 != 0) {
        // nop
    
        goto L_80058458;
    }
    // nop

    // break       7
    do_break(2147845204);
L_80058458:
    // mflo        $t1
    ctx->r9 = lo;
    // j           L_8005848C
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    goto L_8005848C;
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
L_80058464:
    // subu        $v0, $t4, $v1
    ctx->r2 = SUB32(ctx->r12, ctx->r3);
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t3
    lo = S32(U32(ctx->r2) / U32(ctx->r11)); hi = S32(U32(ctx->r2) % U32(ctx->r11));
    // bne         $t3, $zero, L_80058488
    if (ctx->r11 != 0) {
        // nop
    
        goto L_80058488;
    }
    // nop

    // break       7
    do_break(2147845252);
L_80058488:
    // mflo        $a1
    ctx->r5 = lo;
L_8005848C:
    // andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A0
    ctx->r1 = ADD32(ctx->r1, -0X75A0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, -0x2560($v1)
    ctx->r3 = MEM_W(-0X2560, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80058500
    if (ctx->r2 == 0) {
        // mult        $t1, $v1
        result = S64(S32(ctx->r9)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80058500;
    }
    // mult        $t1, $v1
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t3
    lo = S32(U32(ctx->r2) / U32(ctx->r11)); hi = S32(U32(ctx->r2) % U32(ctx->r11));
    // bne         $t3, $zero, L_800584F4
    if (ctx->r11 != 0) {
        // nop
    
        goto L_800584F4;
    }
    // nop

    // break       7
    do_break(2147845360);
L_800584F4:
    // mflo        $t1
    ctx->r9 = lo;
    // j           L_8005852C
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    goto L_8005852C;
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_80058500:
    // subu        $v0, $t4, $v1
    ctx->r2 = SUB32(ctx->r12, ctx->r3);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t3
    lo = S32(U32(ctx->r2) / U32(ctx->r11)); hi = S32(U32(ctx->r2) % U32(ctx->r11));
    // bne         $t3, $zero, L_80058524
    if (ctx->r11 != 0) {
        // nop
    
        goto L_80058524;
    }
    // nop

    // break       7
    do_break(2147845408);
L_80058524:
    // mflo        $a1
    ctx->r5 = lo;
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_8005852C:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80058570
    if (ctx->r2 == 0) {
        // mult        $t1, $v1
        result = S64(S32(ctx->r9)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80058570;
    }
    // mult        $t1, $v1
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t3
    lo = S32(U32(ctx->r2) / U32(ctx->r11)); hi = S32(U32(ctx->r2) % U32(ctx->r11));
    // bne         $t3, $zero, L_80058564
    if (ctx->r11 != 0) {
        // nop
    
        goto L_80058564;
    }
    // nop

    // break       7
    do_break(2147845472);
L_80058564:
    // mflo        $t1
    ctx->r9 = lo;
    // j           L_80058598
    // nop

    goto L_80058598;
    // nop

L_80058570:
    // subu        $v0, $t4, $v1
    ctx->r2 = SUB32(ctx->r12, ctx->r3);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $t3
    lo = S32(U32(ctx->r2) / U32(ctx->r11)); hi = S32(U32(ctx->r2) % U32(ctx->r11));
    // bne         $t3, $zero, L_80058594
    if (ctx->r11 != 0) {
        // nop
    
        goto L_80058594;
    }
    // nop

    // break       7
    do_break(2147845520);
L_80058594:
    // mflo        $a1
    ctx->r5 = lo;
L_80058598:
    // lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // lh          $v1, 0xA88($v1)
    ctx->r3 = MEM_H(0XA88, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_800585C8
    if (ctx->r3 != ctx->r2) {
        // mult        $a1, $a1
        result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_800585C8;
    }
    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sltu        $v0, $a1, $t1
    ctx->r2 = ctx->r5 < ctx->r9 ? 1 : 0;
    // beq         $v0, $zero, L_800585C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800585C0;
    }
    // nop

    // j           L_800585C4
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    goto L_800585C4;
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
L_800585C0:
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
L_800585C4:
    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800585C8:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3FFF
    ctx->r3 = 0 | 0X3FFF;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_800585E4
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800585E4;
    }
    // nop

    // break       7
    do_break(2147845600);
L_800585E4:
    // mflo        $a1
    ctx->r5 = lo;
    // mult        $t1, $t1
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80058608
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80058608;
    }
    // nop

    // break       7
    do_break(2147845636);
L_80058608:
    // mflo        $t1
    ctx->r9 = lo;
    // andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
L_8005864C:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800581FC
    if (ctx->r2 != 0) {
        // andi        $v0, $t2, 0xFF
        ctx->r2 = ctx->r10 & 0XFF;
        goto L_800581FC;
    }
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
L_80058668:
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
