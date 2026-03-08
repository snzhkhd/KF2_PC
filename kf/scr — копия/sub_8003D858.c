#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // bgez        $v0, L_8003D870
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
        goto L_8003D870;
    }
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // j           L_8003D874
    // sh          $v0, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r2;
    goto L_8003D874;
    // sh          $v0, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r2;
L_8003D870:
    // sh          $v1, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r3;
L_8003D874:
    // lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(0X18, ctx->r4);
    // nop

    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003D8A0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8003D8A0;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // j           L_8003D8AC
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    goto L_8003D8AC;
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
L_8003D8A0:
    // bgez        $v1, L_8003D8AC
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003D8AC;
    }
    // nop

    // sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
L_8003D8AC:
    // jr          $ra
    // nop

    return;
    // nop

;}
