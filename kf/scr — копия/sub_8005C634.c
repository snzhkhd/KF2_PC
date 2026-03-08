#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) << 1;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2248
    ctx->r2 = ADD32(ctx->r2, -0X2248);
    // sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4) << 2;
    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(0X90, ctx->r16);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // sw          $v0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r2;
    // lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(0X0, ctx->r8);
    // nop

    // addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // lw          $v0, 0x90($a2)
    ctx->r2 = MEM_W(0X90, ctx->r6);
    // addiu       $a3, $zero, -0x3
    ctx->r7 = ADD32(0, -0X3);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // sw          $v0, 0x90($a2)
    MEM_W(0X90, ctx->r6) = ctx->r2;
    // lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(0X0, ctx->r8);
    // nop

    // addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // lw          $v0, 0x90($a2)
    ctx->r2 = MEM_W(0X90, ctx->r6);
    // addiu       $a3, $zero, -0x9
    ctx->r7 = ADD32(0, -0X9);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // sw          $v0, 0x90($a2)
    MEM_W(0X90, ctx->r6) = ctx->r2;
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // or          $a0, $a1, $a0
    ctx->r4 = ctx->r5 | ctx->r4;
    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // jal         0x80057F04
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    sub_80057F04(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    after_0:
    // sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    // sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // sb          $zero, 0x27($s0)
    MEM_B(0X27, ctx->r16) = 0;
    // sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // sb          $zero, 0x29($s0)
    MEM_B(0X29, ctx->r16) = 0;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    // sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
    // sb          $zero, 0x27($s0)
    MEM_B(0X27, ctx->r16) = 0;
    // sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // ori         $t3, $zero, 0x40
    ctx->r11 = 0 | 0X40;
    // ori         $t2, $zero, 0x7F
    ctx->r10 = 0 | 0X7F;
    // lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(0X7C, ctx->r16);
    // lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(0X84, ctx->r16);
    // lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(0X72, ctx->r16);
    // lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(0X8, ctx->r16);
    // lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(0X8, ctx->r16);
    // addu        $t1, $s0, $zero
    ctx->r9 = ADD32(ctx->r16, 0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // sw          $v1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r3;
    // sh          $a0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r4;
    // sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // sw          $a2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r6;
L_8005C768:
    // sb          $t0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r8;
    // sb          $t3, 0x17($a3)
    MEM_B(0X17, ctx->r7) = ctx->r11;
    // sh          $t2, 0x4E($t1)
    MEM_H(0X4E, ctx->r9) = ctx->r10;
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8005C768
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_8005C768;
    }
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sh          $v0, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r2;
    // sh          $v0, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r2;
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
