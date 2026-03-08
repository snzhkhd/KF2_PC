#include "recomp.h"
#include "disable_warnings.h"

void sub_8005CD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3) >> 16;
    // lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // addiu       $a2, $a2, -0x2248
    ctx->r6 = ADD32(ctx->r6, -0X2248);
    // sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10) << 2;
    // addu        $t1, $v1, $a2
    ctx->r9 = ADD32(ctx->r3, ctx->r6);
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2) << 2;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // addu        $s0, $t0, $v1
    ctx->r16 = ADD32(ctx->r8, ctx->r3);
    // lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(0X98, ctx->r16);
    // lh          $a2, 0x42($s0)
    ctx->r6 = MEM_H(0X42, ctx->r16);
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // blez        $a2, L_8005CE24
    if (SIGNED(ctx->r6) <= 0) {
        // addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
        goto L_8005CE24;
    }
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // divu        $zero, $v0, $a2
    lo = S32(U32(ctx->r2) / U32(ctx->r6)); hi = S32(U32(ctx->r2) % U32(ctx->r6));
    // bne         $a2, $zero, L_8005CDA4
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8005CDA4;
    }
    // nop

    // break       7
    do_break(2147863968);
L_8005CDA4:
    // mfhi        $v0
    ctx->r2 = hi;
    // nop

    // bne         $v0, $zero, L_8005CF70
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_8005CF70;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(0X40, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8005CEE4
    if (SIGNED(ctx->r2) <= 0) {
        // sll         $v0, $a3, 8
        ctx->r2 = S32(ctx->r7) << 8;
        goto L_8005CEE4;
    }
    // sll         $v0, $a3, 8
    ctx->r2 = S32(ctx->r7) << 8;
    // or          $s1, $v0, $t2
    ctx->r17 = ctx->r2 | ctx->r10;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80057DEC
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    sub_80057DEC(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    after_0:
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // lh          $v1, 0x40($s0)
    ctx->r3 = MEM_H(0X40, ctx->r16);
    // nop

    // subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // blez        $v0, L_8005CEBC
    if (SIGNED(ctx->r2) <= 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_8005CEBC;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // lhu         $a2, 0x12($sp)
    ctx->r6 = MEM_HU(0X12, ctx->r29);
    // nop

    // subu        $v0, $a2, $v1
    ctx->r2 = SUB32(ctx->r6, ctx->r3);
    // blez        $v0, L_8005CEB8
    if (SIGNED(ctx->r2) <= 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005CEB8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a1, $v0, L_8005CEB8
    if (ctx->r5 == ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8005CEB8;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // j           L_8005CED4
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    goto L_8005CED4;
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8005CE24:
    // lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(0X40, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8005CEE4
    if (SIGNED(ctx->r2) <= 0) {
        // sll         $v0, $a3, 8
        ctx->r2 = S32(ctx->r7) << 8;
        goto L_8005CEE4;
    }
    // sll         $v0, $a3, 8
    ctx->r2 = S32(ctx->r7) << 8;
    // or          $s1, $v0, $t2
    ctx->r17 = ctx->r2 | ctx->r10;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80057DEC
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    sub_80057DEC(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    after_1:
    // lw          $v0, 0x94($s0)
    ctx->r2 = MEM_W(0X94, ctx->r16);
    // lw          $v1, 0x98($s0)
    ctx->r3 = MEM_W(0X98, ctx->r16);
    // lh          $t0, 0x42($s0)
    ctx->r8 = MEM_H(0X42, ctx->r16);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // negu        $a0, $t0
    ctx->r4 = SUB32(0, ctx->r8);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v0, 0x3E($s0)
    ctx->r2 = MEM_H(0X3E, ctx->r16);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8005CEBC
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_8005CEBC;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // nop

    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8005CEB8
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8005CEB8;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lhu         $a2, 0x12($sp)
    ctx->r6 = MEM_HU(0X12, ctx->r29);
    // addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x80057C6C
    // addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    sub_80057C6C(rdram, ctx);
    goto after_2;
    // addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    after_2:
    // j           L_8005CF00
    // nop

    goto L_8005CF00;
    // nop

L_8005CEB8:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_8005CEBC:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
L_8005CED4:
    // jal         0x80057C6C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80057C6C(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // j           L_8005CF00
    // nop

    goto L_8005CF00;
    // nop

L_8005CEE4:
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(0X90, ctx->r2);
    // addiu       $a0, $zero, -0x21
    ctx->r4 = ADD32(0, -0X21);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r3;
L_8005CF00:
    // lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(0X98, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8005CF20
    if (ctx->r2 == 0) {
        // sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18) << 16;
        goto L_8005CF20;
    }
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // lh          $v0, 0x40($s0)
    ctx->r2 = MEM_H(0X40, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8005CF70
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_8005CF70;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_8005CF20:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19) << 16;
    // sra         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) >> 14;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(0X90, ctx->r2);
    // addiu       $a0, $zero, -0x21
    ctx->r4 = ADD32(0, -0X21);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r3;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_8005CF70:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    // addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // jal         0x80057DEC
    // addiu       $a2, $s0, 0x7A
    ctx->r6 = ADD32(ctx->r16, 0X7A);
    sub_80057DEC(rdram, ctx);
    goto after_4;
    // addiu       $a2, $s0, 0x7A
    ctx->r6 = ADD32(ctx->r16, 0X7A);
    after_4:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
