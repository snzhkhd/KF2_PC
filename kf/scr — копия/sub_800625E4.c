#include "recomp.h"
#include "disable_warnings.h"

void sub_800625E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x6108
    ctx->r2 = ADD32(ctx->r2, 0X6108);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // beq         $a1, $v0, L_80062608
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_80062608;
    }
    // nop

    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_80062608:
    // jr          $ra
    // nop

    return;
    // nop

;}
