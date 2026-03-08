#include "recomp.h"
#include "disable_warnings.h"

void sub_80036690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(0X0, ctx->r6);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $v0, L_8003674C
    if (ctx->r9 == ctx->r2) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8003674C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800366AC:
    // lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(0X0, ctx->r6);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $t4, L_8003671C
    if (ctx->r2 != ctx->r12) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8003671C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(0X0, ctx->r6);
    // nop

    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $t3, L_80036740
    if (ctx->r3 == ctx->r11) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_80036740;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // addiu       $t0, $a1, 0x4
    ctx->r8 = ADD32(ctx->r5, 0X4);
    // addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
L_800366E4:
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lhu         $v0, -0x2($t0)
    ctx->r2 = MEM_HU(-0X2, ctx->r8);
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // sh          $v0, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // bne         $v1, $t2, L_800366E4
    if (ctx->r3 != ctx->r10) {
        // addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
        goto L_800366E4;
    }
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // j           L_80036744
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    goto L_80036744;
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_8003671C:
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80036740:
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80036744:
    // bne         $t1, $t3, L_800366AC
    if (ctx->r9 != ctx->r11) {
        // nop
    
        goto L_800366AC;
    }
    // nop

L_8003674C:
    // jr          $ra
    // nop

    return;
    // nop

;}
