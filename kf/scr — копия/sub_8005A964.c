#include "recomp.h"
#include "disable_warnings.h"

void sub_8005A964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x12($s1)
    ctx->r2 = MEM_BU(0X12, ctx->r17);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // addu        $s2, $s1, $v0
    ctx->r18 = ADD32(ctx->r17, ctx->r2);
    // lbu         $a1, 0x2C($s2)
    ctx->r5 = MEM_BU(0X2C, ctx->r18);
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // jal         0x8005C214
    // addu        $s6, $t0, $zero
    ctx->r22 = ADD32(ctx->r8, 0);
    sub_8005C214(rdram, ctx);
    goto after_0;
    // addu        $s6, $t0, $zero
    ctx->r22 = ADD32(ctx->r8, 0);
    after_0:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // blez        $v0, L_8005AA70
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8005AA70;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // sltiu       $s4, $v0, 0x40
    ctx->r20 = ctx->r2 < 0X40 ? 1 : 0;
L_8005AA0C:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s2)
    ctx->r5 = MEM_BU(0X2C, ctx->r18);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BCF4
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    sub_8005BCF4(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_1:
    // beq         $s4, $zero, L_8005AA30
    if (ctx->r20 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8005AA30;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_8005AA48
    // sb          $v0, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r2;
    goto L_8005AA48;
    // sb          $v0, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r2;
L_8005AA30:
    // addiu       $v0, $s3, 0xC0
    ctx->r2 = ADD32(ctx->r19, 0XC0);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8005AA48
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005AA48;
    }
    // nop

    // sb          $zero, 0x21($sp)
    MEM_B(0X21, ctx->r29) = 0;
L_8005AA48:
    // lh          $a0, 0x4C($s1)
    ctx->r4 = MEM_H(0X4C, ctx->r17);
    // lbu         $a1, 0x2C($s2)
    ctx->r5 = MEM_BU(0X2C, ctx->r18);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x8005BF30
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    sub_8005BF30(rdram, ctx);
    goto after_2;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_2:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005AA0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005AA0C;
    }
    // nop

L_8005AA70:
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_3;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_3:
    // sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
