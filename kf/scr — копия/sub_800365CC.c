#include "recomp.h"
#include "disable_warnings.h"

void sub_800365CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(0X10, ctx->r29);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $v0, L_80036678
    if (ctx->r3 == ctx->r2) {
        // addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
        goto L_80036678;
    }
    // addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // ori         $t6, $zero, 0x1000
    ctx->r14 = 0 | 0X1000;
    // addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80036614:
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // lhu         $a1, 0x2($t4)
    ctx->r5 = MEM_HU(0X2, ctx->r12);
    // nop

    // addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // slt         $v0, $a2, $t0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // beq         $v0, $zero, L_80036668
    if (ctx->r2 == 0) {
        // addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
        goto L_80036668;
    }
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // subu        $v0, $a2, $t3
    ctx->r2 = SUB32(ctx->r6, ctx->r11);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // lhu         $v1, 0x0($t4)
    ctx->r3 = MEM_HU(0X0, ctx->r12);
    // divu        $zero, $v0, $a1
    lo = S32(U32(ctx->r2) / U32(ctx->r5)); hi = S32(U32(ctx->r2) % U32(ctx->r5));
    // bne         $a1, $zero, L_80036654
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80036654;
    }
    // nop

    // break       7
    do_break(2147706448);
L_80036654:
    // mflo        $a0
    ctx->r4 = lo;
    // beq         $v1, $zero, L_80036684
    if (ctx->r3 == 0) {
        // addu        $v0, $t4, $zero
        ctx->r2 = ADD32(ctx->r12, 0);
        goto L_80036684;
    }
    // addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
    // j           L_80036684
    // subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
    goto L_80036684;
    // subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
L_80036668:
    // addu        $t3, $t0, $zero
    ctx->r11 = ADD32(ctx->r8, 0);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $t5, L_80036614
    if (ctx->r3 != ctx->r13) {
        // addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_80036614;
    }
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80036678:
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // ori         $a0, $zero, 0x1000
    ctx->r4 = 0 | 0X1000;
    // addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
L_80036684:
    // sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // jr          $ra
    // sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    return;
    // sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
;}
