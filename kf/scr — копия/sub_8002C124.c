#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(0X0, ctx->r4);
    // beq         $a1, $zero, L_8002C134
    if (ctx->r5 == 0) {
        // addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
        goto L_8002C134;
    }
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lhu         $t1, 0x0($a1)
    ctx->r9 = MEM_HU(0X0, ctx->r5);
L_8002C134:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bne         $v1, $zero, L_8002C14C
    if (ctx->r3 != 0) {
        // sll         $v0, $t1, 16
        ctx->r2 = S32(ctx->r9) << 16;
        goto L_8002C14C;
    }
    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // beq         $t1, $zero, L_8002C1D4
    if (ctx->r9 == 0) {
        // nop
    
        goto L_8002C1D4;
    }
    // nop

L_8002C14C:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002C164
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C164;
    }
    // nop

    // j           L_8002C16C
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    goto L_8002C16C;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8002C164:
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_8002C16C:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_8002C1B8
    if (ctx->r2 == 0) {
        // mult        $v1, $a3
        result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8002C1B8;
    }
    // mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8002C194
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8002C194;
    }
    // nop

    // break       7
    do_break(2147664272);
L_8002C194:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8002C1AC
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002C1AC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8002C1AC
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8002C1AC;
    }
    // nop

    // break       6
    do_break(2147664296);
L_8002C1AC:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8002C1BC
    // nop

    goto L_8002C1BC;
    // nop

L_8002C1B8:
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_8002C1BC:
    // beq         $a1, $zero, L_8002C1C8
    if (ctx->r5 == 0) {
        // sh          $t0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r8;
        goto L_8002C1C8;
    }
    // sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
L_8002C1C8:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // j           L_8002C1D8
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    goto L_8002C1D8;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_8002C1D4:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002C1D8:
    // jr          $ra
    // nop

    return;
    // nop

;}
