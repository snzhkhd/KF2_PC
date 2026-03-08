#include "recomp.h"
#include "disable_warnings.h"

void sub_8005D538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
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
    // sra         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3) >> 16;
    // lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // addiu       $a2, $a2, -0x2248
    ctx->r6 = ADD32(ctx->r6, -0X2248);
    // sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8) << 2;
    // addu        $s2, $v1, $a2
    ctx->r18 = ADD32(ctx->r3, ctx->r6);
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2) << 2;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // addu        $s0, $s1, $v1
    ctx->r16 = ADD32(ctx->r17, ctx->r3);
    // lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(0X98, ctx->r16);
    // lh          $a2, 0x42($s0)
    ctx->r6 = MEM_H(0X42, ctx->r16);
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // blez        $a2, L_8005D694
    if (SIGNED(ctx->r6) <= 0) {
        // addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
        goto L_8005D694;
    }
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // divu        $zero, $v0, $a2
    lo = S32(U32(ctx->r2) / U32(ctx->r6)); hi = S32(U32(ctx->r2) % U32(ctx->r6));
    // bne         $a2, $zero, L_8005D5C8
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8005D5C8;
    }
    // nop

    // break       7
    do_break(2147866052);
L_8005D5C8:
    // mfhi        $v0
    ctx->r2 = hi;
    // nop

    // bne         $v0, $zero, L_8005D818
    if (ctx->r2 != 0) {
        // sll         $v0, $s3, 16
        ctx->r2 = S32(ctx->r19) << 16;
        goto L_8005D818;
    }
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(0X40, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8005D774
    if (SIGNED(ctx->r2) < 0) {
        // sll         $v0, $a3, 8
        ctx->r2 = S32(ctx->r7) << 8;
        goto L_8005D774;
    }
    // sll         $v0, $a3, 8
    ctx->r2 = S32(ctx->r7) << 8;
    // or          $s1, $v0, $t0
    ctx->r17 = ctx->r2 | ctx->r8;
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
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // lh          $v1, 0x40($s0)
    ctx->r3 = MEM_H(0X40, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x7F
    ctx->r2 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_8005D64C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005D64C;
    }
    // nop

    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x7F
    ctx->r2 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_8005D64C
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8005D64C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
    // jal         0x80057C6C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80057C6C(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_8005D64C:
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // lh          $v0, 0x40($s0)
    ctx->r2 = MEM_H(0X40, ctx->r16);
    // lh          $v1, 0x3E($s0)
    ctx->r3 = MEM_H(0X3E, ctx->r16);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005D7A8
    if (ctx->r2 == 0) {
        // sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19) << 16;
        goto L_8005D7A8;
    }
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // sra         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) >> 8;
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // lhu         $a2, 0x12($sp)
    ctx->r6 = MEM_HU(0X12, ctx->r29);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x80057C6C
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sub_80057C6C(rdram, ctx);
    goto after_2;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_2:
    // j           L_8005D7A8
    // nop

    goto L_8005D7A8;
    // nop

L_8005D694:
    // bgez        $a2, L_8005D818
    if (SIGNED(ctx->r6) >= 0) {
        // sll         $v0, $s3, 16
        ctx->r2 = S32(ctx->r19) << 16;
        goto L_8005D818;
    }
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(0X40, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8005D774
    if (SIGNED(ctx->r2) < 0) {
        // sll         $v0, $a3, 8
        ctx->r2 = S32(ctx->r7) << 8;
        goto L_8005D774;
    }
    // sll         $v0, $a3, 8
    ctx->r2 = S32(ctx->r7) << 8;
    // or          $s1, $v0, $t0
    ctx->r17 = ctx->r2 | ctx->r8;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80057DEC
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    sub_80057DEC(rdram, ctx);
    goto after_3;
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    after_3:
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // lh          $v1, 0x42($s0)
    ctx->r3 = MEM_H(0X42, ctx->r16);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x7F
    ctx->r2 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_8005D710
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005D710;
    }
    // nop

    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x7F
    ctx->r2 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_8005D710
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8005D710;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
    // jal         0x80057C6C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80057C6C(rdram, ctx);
    goto after_4;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
L_8005D710:
    // lw          $v1, 0x94($s0)
    ctx->r3 = MEM_W(0X94, ctx->r16);
    // lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(0X98, ctx->r16);
    // lh          $t0, 0x42($s0)
    ctx->r8 = MEM_H(0X42, ctx->r16);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // negu        $v0, $t0
    ctx->r2 = SUB32(0, ctx->r8);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v1, 0x3E($s0)
    ctx->r3 = MEM_H(0X3E, ctx->r16);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8005D7A8
    if (ctx->r2 == 0) {
        // sll         $v0, $s3, 16
        ctx->r2 = S32(ctx->r19) << 16;
        goto L_8005D7A8;
    }
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // lhu         $a2, 0x12($sp)
    ctx->r6 = MEM_HU(0X12, ctx->r29);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // jal         0x80057C6C
    // subu        $a2, $a2, $t0
    ctx->r6 = SUB32(ctx->r6, ctx->r8);
    sub_80057C6C(rdram, ctx);
    goto after_5;
    // subu        $a2, $a2, $t0
    ctx->r6 = SUB32(ctx->r6, ctx->r8);
    after_5:
    // j           L_8005D7A8
    // nop

    goto L_8005D7A8;
    // nop

L_8005D774:
    // sll         $a0, $a3, 8
    ctx->r4 = S32(ctx->r7) << 8;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
    // jal         0x80057C6C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80057C6C(rdram, ctx);
    goto after_6;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // addiu       $a0, $zero, -0x11
    ctx->r4 = ADD32(0, -0X11);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
L_8005D7A8:
    // lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(0X98, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8005D7C8
    if (ctx->r2 == 0) {
        // sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19) << 16;
        goto L_8005D7C8;
    }
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // lh          $v0, 0x40($s0)
    ctx->r2 = MEM_H(0X40, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8005D818
    if (ctx->r2 != 0) {
        // sll         $v0, $s3, 16
        ctx->r2 = S32(ctx->r19) << 16;
        goto L_8005D818;
    }
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
L_8005D7C8:
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
    // sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20) << 16;
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
    // addiu       $a0, $zero, -0x11
    ctx->r4 = ADD32(0, -0X11);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r3;
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
L_8005D818:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
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
    goto after_7;
    // addiu       $a2, $s0, 0x7A
    ctx->r6 = ADD32(ctx->r16, 0X7A);
    after_7:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
