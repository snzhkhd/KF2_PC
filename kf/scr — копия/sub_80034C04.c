#include "recomp.h"
#include "disable_warnings.h"

void sub_80034C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // lw          $t0, 0x4F48($t0)
    ctx->r8 = MEM_W(0X4F48, ctx->r8);
    // sra         $a3, $v1, 11
    ctx->r7 = S32(ctx->r3) >> 11;
    // subu        $v1, $a3, $a2
    ctx->r3 = SUB32(ctx->r7, ctx->r6);
    // slt         $v1, $t0, $v1
    ctx->r3 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v1, $zero, L_80034C60
    if (ctx->r3 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80034C60;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
    // slt         $v1, $v1, $t0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v1, $zero, L_80034C60
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80034C60;
    }
    // nop

    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // lw          $a2, 0x4F44($a2)
    ctx->r6 = MEM_W(0X4F44, ctx->r6);
    // sra         $a0, $v1, 11
    ctx->r4 = S32(ctx->r3) >> 11;
    // subu        $v1, $a0, $a1
    ctx->r3 = SUB32(ctx->r4, ctx->r5);
    // slt         $v1, $a2, $v1
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v1, $zero, L_80034C60
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80034C60;
    }
    // nop

    // addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80034C60:
    // jr          $ra
    // nop

    return;
    // nop

;}
