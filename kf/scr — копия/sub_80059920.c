#include "recomp.h"
#include "disable_warnings.h"

void sub_80059920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $a1, -0x19C8($at)
    MEM_H(-0X19C8, ctx->r1) = ctx->r5;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $a2, -0x19C0($at)
    MEM_H(-0X19C0, ctx->r1) = ctx->r6;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // blez        $a1, L_80059990
    if (SIGNED(ctx->r5) <= 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_80059990;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2) >> 16;
    // lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // addiu       $a2, $a2, -0x2248
    ctx->r6 = ADD32(ctx->r6, -0X2248);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80059958:
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
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80059958
    if (ctx->r2 != 0) {
        // addu        $v1, $v1, $t0
        ctx->r3 = ADD32(ctx->r3, ctx->r8);
        goto L_80059958;
    }
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_80059990:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C8($v0)
    ctx->r2 = MEM_H(-0X19C8, ctx->r2);
    // nop

    // blez        $v0, L_80059AF4
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_80059AF4;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $t0, $zero, 0x7F
    ctx->r8 = 0 | 0X7F;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, -0x2248
    ctx->r9 = ADD32(ctx->r9, -0X2248);
L_800599B0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C0($v0)
    ctx->r2 = MEM_H(-0X19C0, ctx->r2);
    // nop

    // blez        $v0, L_80059ADC
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80059ADC;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800599CC:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x90($v0)
    MEM_W(0X90, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sb          $v1, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r3;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x40($v0)
    MEM_H(0X40, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x94($v0)
    MEM_W(0X94, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x98($v0)
    MEM_W(0X98, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x42($v0)
    MEM_H(0X42, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $t0, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r8;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $t0, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r8;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lh          $v1, -0x19C0($v1)
    ctx->r3 = MEM_H(-0X19C0, ctx->r3);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $t0, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r8;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v1, $a2, $v1
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $t0, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r8;
    // bne         $v1, $zero, L_800599CC
    if (ctx->r3 != 0) {
        // addiu       $a0, $a0, 0xAC
        ctx->r4 = ADD32(ctx->r4, 0XAC);
        goto L_800599CC;
    }
    // addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
L_80059ADC:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C8($v0)
    ctx->r2 = MEM_H(-0X19C8, ctx->r2);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800599B0
    if (ctx->r2 != 0) {
        // addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
        goto L_800599B0;
    }
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80059AF4:
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
