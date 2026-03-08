#include "recomp.h"
#include "disable_warnings.h"

void sub_80055D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // addu        $t1, $a2, $zero
    ctx->r9 = ADD32(ctx->r6, 0);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // beq         $a1, $a2, L_80055F58
    if (ctx->r5 == ctx->r6) {
        // addu        $t2, $a3, $zero
        ctx->r10 = ADD32(ctx->r7, 0);
        goto L_80055F58;
    }
    // addu        $t2, $a3, $zero
    ctx->r10 = ADD32(ctx->r7, 0);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7594
    ctx->r1 = ADD32(ctx->r1, -0X7594);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758C
    ctx->r1 = ADD32(ctx->r1, -0X758C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $t0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r8;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758A
    ctx->r1 = ADD32(ctx->r1, -0X758A);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $t1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r9;
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // subu        $v0, $a1, $a2
    ctx->r2 = SUB32(ctx->r5, ctx->r6);
    // bltz        $v0, L_80055E28
    if (SIGNED(ctx->r2) < 0) {
        // slt         $v0, $v0, $v1
        ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_80055E28;
    }
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80055E38
    if (ctx->r2 != 0) {
        // sll         $a0, $t2, 16
        ctx->r4 = S32(ctx->r10) << 16;
        goto L_80055E38;
    }
    // sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10) << 16;
    // j           L_80055ED8
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
    goto L_80055ED8;
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
L_80055E28:
    // subu        $v0, $a2, $a1
    ctx->r2 = SUB32(ctx->r6, ctx->r5);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80055ED4
    if (ctx->r2 == 0) {
        // sll         $a0, $t2, 16
        ctx->r4 = S32(ctx->r10) << 16;
        goto L_80055ED4;
    }
    // sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10) << 16;
L_80055E38:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // div         $zero, $a0, $v1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80055E60
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80055E60;
    }
    // nop

    // break       7
    do_break(2147835484);
L_80055E60:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80055E78
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80055E78;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80055E78
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80055E78;
    }
    // nop

    // break       6
    do_break(2147835508);
L_80055E78:
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7592
    ctx->r1 = ADD32(ctx->r1, -0X7592);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7590
    ctx->r1 = ADD32(ctx->r1, -0X7590);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758E
    ctx->r1 = ADD32(ctx->r1, -0X758E);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // j           L_80055F58
    // nop

    goto L_80055F58;
    // nop

L_80055ED4:
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
L_80055ED8:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80055F00
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055F00;
    }
    // nop

    // break       7
    do_break(2147835644);
L_80055F00:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80055F18
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80055F18;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80055F18
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80055F18;
    }
    // nop

    // break       6
    do_break(2147835668);
L_80055F18:
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addiu       $at, $at, -0x7590
    ctx->r1 = ADD32(ctx->r1, -0X7590);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7592
    ctx->r1 = ADD32(ctx->r1, -0X7592);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
L_80055F58:
    // jr          $ra
    // nop

    return;
    // nop

;}
