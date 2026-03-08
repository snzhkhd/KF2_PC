#include "recomp.h"
#include "disable_warnings.h"

void sub_80051C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7AC($v0)
    ctx->r2 = MEM_W(-0X7AC, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80051CD8
    if (ctx->r2 == 0) {
        // addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
        goto L_80051CD8;
    }
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7A4($a0)
    ctx->r4 = MEM_W(-0X7A4, ctx->r4);
    // nop

    // divu        $zero, $a1, $a0
    lo = S32(U32(ctx->r5) / U32(ctx->r4)); hi = S32(U32(ctx->r5) % U32(ctx->r4));
    // bne         $a0, $zero, L_80051CB4
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80051CB4;
    }
    // nop

    // break       7
    do_break(2147818672);
L_80051CB4:
    // mfhi        $v0
    ctx->r2 = hi;
    // nop

    // beq         $v0, $zero, L_80051CD8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051CD8;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7A0($v0)
    ctx->r2 = MEM_W(-0X7A0, ctx->r2);
    // addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
L_80051CD8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7A8($v0)
    ctx->r2 = MEM_W(-0X7A8, ctx->r2);
    // nop

    // srlv        $a3, $a1, $v0
    ctx->r7 = S32(U32(ctx->r5) >> (ctx->r2 & 31));
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // beq         $a2, $v0, L_80051D04
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80051D04;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a2, $v0, L_80051D0C
    if (ctx->r6 != ctx->r2) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80051D0C;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // j           L_80051D20
    // andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    goto L_80051D20;
    // andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
L_80051D04:
    // j           L_80051D20
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    goto L_80051D20;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80051D0C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7CC($a0)
    ctx->r4 = MEM_W(-0X7CC, ctx->r4);
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $a3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r7;
L_80051D20:
    // jr          $ra
    // nop

    return;
    // nop

;}
