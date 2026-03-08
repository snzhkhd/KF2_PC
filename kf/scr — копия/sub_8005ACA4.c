#include "recomp.h"
#include "disable_warnings.h"

void sub_8005ACA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
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
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // beq         $v1, $v0, L_8005AD18
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x1E
        ctx->r2 = 0 | 0X1E;
        goto L_8005AD18;
    }
    // ori         $v0, $zero, 0x1E
    ctx->r2 = 0 | 0X1E;
    // beq         $v1, $v0, L_8005AD3C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005AD3C;
    }
    // nop

    // j           L_8005ADBC
    // sb          $a2, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r6;
    goto L_8005ADBC;
    // sb          $a2, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r6;
L_8005AD18:
    // sb          $a2, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r6;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x27($s0)
    MEM_B(0X27, ctx->r16) = ctx->r2;
    // jal         0x8005BB50
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    sub_8005BB50(rdram, ctx);
    goto after_0;
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    after_0:
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // j           L_8005ADE0
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    goto L_8005ADE0;
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
L_8005AD3C:
    // lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(0X28, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8005AD60
    if (ctx->r2 != 0) {
        // sb          $a2, 0x16($s0)
        MEM_B(0X16, ctx->r16) = ctx->r6;
        goto L_8005AD60;
    }
    // sb          $a2, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r6;
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // jal         0x8005BB50
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    sub_8005BB50(rdram, ctx);
    goto after_1;
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    after_1:
    // j           L_8005ADE0
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    goto L_8005ADE0;
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
L_8005AD60:
    // sltiu       $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 < 0X7F ? 1 : 0;
    // beq         $v0, $zero, L_8005ADA4
    if (ctx->r2 == 0) {
        // addu        $a1, $a3, $zero
        ctx->r5 = ADD32(ctx->r7, 0);
        goto L_8005ADA4;
    }
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(0X28, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // jal         0x8005BB50
    // sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    sub_8005BB50(rdram, ctx);
    goto after_2;
    // sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    after_2:
    // lbu         $v1, 0x28($s0)
    ctx->r3 = MEM_BU(0X28, ctx->r16);
    // nop

    // beq         $v1, $zero, L_8005AD9C
    if (ctx->r3 == 0) {
        // sw          $v0, 0x88($s0)
        MEM_W(0X88, ctx->r16) = ctx->r2;
        goto L_8005AD9C;
    }
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // j           L_8005ADE0
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    goto L_8005ADE0;
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8005AD9C:
    // j           L_8005ADE0
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    goto L_8005ADE0;
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_8005ADA4:
    // jal         0x8005BB50
    // nop

    sub_8005BB50(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // j           L_8005ADE0
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    goto L_8005ADE0;
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8005ADBC:
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lbu         $v0, 0x2A($s0)
    ctx->r2 = MEM_BU(0X2A, ctx->r16);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8005BB50
    // sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    sub_8005BB50(rdram, ctx);
    goto after_4;
    // sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    after_4:
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
L_8005ADE0:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
