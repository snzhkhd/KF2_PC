#include "recomp.h"
#include "disable_warnings.h"

void sub_8005A2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5) >> 16;
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4) >> 16;
    // sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x12($s0)
    ctx->r3 = MEM_BU(0X12, ctx->r16);
    // lh          $v0, 0xAA($s0)
    ctx->r2 = MEM_H(0XAA, ctx->r16);
    // addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // lbu         $t2, 0x17($a0)
    ctx->r10 = MEM_BU(0X17, ctx->r4);
    // srav        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2) >> (ctx->r3 & 31);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_8005A374
    if (ctx->r2 != 0) {
        // andi        $s1, $a3, 0xFF
        ctx->r17 = ctx->r7 & 0XFF;
        goto L_8005A374;
    }
    // andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // lhu         $v0, 0x74($s0)
    ctx->r2 = MEM_HU(0X74, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8005A374
    if (ctx->r2 == 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_8005A374;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // beq         $v0, $zero, L_8005A35C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005A35C;
    }
    // nop

    // lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(0X4C, ctx->r16);
    // lbu         $a2, 0x2C($a0)
    ctx->r6 = MEM_BU(0X2C, ctx->r4);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // sll         $a0, $t0, 8
    ctx->r4 = S32(ctx->r8) << 8;
    // or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    // jal         0x80057484
    // andi        $a3, $t3, 0xFF
    ctx->r7 = ctx->r11 & 0XFF;
    sub_80057484(rdram, ctx);
    goto after_0;
    // andi        $a3, $t3, 0xFF
    ctx->r7 = ctx->r11 & 0XFF;
    after_0:
    // j           L_8005A374
    // sh          $s1, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r17;
    goto L_8005A374;
    // sh          $s1, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r17;
L_8005A35C:
    // lbu         $a2, 0x2C($a0)
    ctx->r6 = MEM_BU(0X2C, ctx->r4);
    // sll         $a0, $t0, 8
    ctx->r4 = S32(ctx->r8) << 8;
    // lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(0X4C, ctx->r16);
    // or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    // jal         0x800579E4
    // andi        $a3, $t3, 0xFF
    ctx->r7 = ctx->r11 & 0XFF;
    sub_800579E4(rdram, ctx);
    goto after_1;
    // andi        $a3, $t3, 0xFF
    ctx->r7 = ctx->r11 & 0XFF;
    after_1:
L_8005A374:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
