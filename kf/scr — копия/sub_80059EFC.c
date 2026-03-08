#include "recomp.h"
#include "disable_warnings.h"

void sub_80059EFC(uint8_t* rdram, recomp_context* ctx) {
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
    // sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5) << 16;
    // sra         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7) >> 16;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $v1, $a0, 14
    ctx->r3 = S32(ctx->r4) >> 14;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x70($s1)
    ctx->r2 = MEM_H(0X70, ctx->r17);
    // lw          $v1, 0x88($s1)
    ctx->r3 = MEM_W(0X88, ctx->r17);
    // nop

    // subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // blez        $a1, L_80059FA8
    if (SIGNED(ctx->r5) <= 0) {
        // addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
        goto L_80059FA8;
    }
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // lh          $v1, 0x6E($s1)
    ctx->r3 = MEM_H(0X6E, ctx->r17);
    // nop

    // blez        $v1, L_80059F88
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80059F88;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80059FF0
    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
    goto L_80059FF0;
    // sh          $v0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r2;
L_80059F88:
    // bne         $v1, $zero, L_80059FA0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80059FA0;
    }
    // nop

    // lw          $v0, 0x88($s1)
    ctx->r2 = MEM_W(0X88, ctx->r17);
    // sh          $a2, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r6;
    // j           L_80059FEC
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    goto L_80059FEC;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80059FA0:
    // j           L_80059FF0
    // sw          $a1, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r5;
    goto L_80059FF0;
    // sw          $a1, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r5;
L_80059FA8:
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80059FF0
    if (ctx->r2 != 0) {
        // addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
        goto L_80059FF0;
    }
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sra         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) >> 16;
L_80059FC0:
    // jal         0x8005A00C
    // sra         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18) >> 16;
    sub_8005A00C(rdram, ctx);
    goto after_0;
    // sra         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18) >> 16;
    after_0:
    // lw          $v0, 0x88($s1)
    ctx->r2 = MEM_W(0X88, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80059FC0
    if (ctx->r2 == 0) {
        // sra         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19) >> 16;
        goto L_80059FC0;
    }
    // sra         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) >> 16;
    // lh          $v1, 0x70($s1)
    ctx->r3 = MEM_H(0X70, ctx->r17);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80059FC0
    if (ctx->r2 != 0) {
        // subu        $v0, $s0, $v1
        ctx->r2 = SUB32(ctx->r16, ctx->r3);
        goto L_80059FC0;
    }
    // subu        $v0, $s0, $v1
    ctx->r2 = SUB32(ctx->r16, ctx->r3);
L_80059FEC:
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
L_80059FF0:
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
