#include "recomp.h"
#include "disable_warnings.h"

void sub_800262C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_800262D8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_800262D8;
    }
    // nop

    // break       7
    do_break(2147640020);
L_800262D8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_800262F0
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800262F0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_800262F0
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_800262F0;
    }
    // nop

    // break       6
    do_break(2147640044);
L_800262F0:
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v1, $a0, 0x1388
    ctx->r3 = SIGNED(ctx->r4) < 0X1388 ? 1 : 0;
    // beq         $v1, $zero, L_8002630C
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1388
        ctx->r2 = 0 | 0X1388;
        goto L_8002630C;
    }
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8002630C:
    // jr          $ra
    // nop

    return;
    // nop

;}
