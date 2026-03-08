#include "recomp.h"
#include "disable_warnings.h"

void CalculateDamagePart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5) << 4;
    // sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6) << 4;
    // bne         $a1, $zero, L_8003C6B4
    if (ctx->r5 != 0) {
        // sll         $a0, $a0, 4
        ctx->r4 = S32(ctx->r4) << 4;
        goto L_8003C6B4;
    }
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // j           L_8003C710
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8003C710;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003C6B4:
    // addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // subu        $a0, $a1, $v1
    ctx->r4 = SUB32(ctx->r5, ctx->r3);
    // bgez        $a0, L_8003C6C8
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_8003C6C8;
    }
    // nop

    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8003C6C8:
    // bne         $v1, $zero, L_8003C6D4
    if (ctx->r3 != 0) {
        // mult        $a1, $a1
        result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8003C6D4;
    }
    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $v1, $zero, 0x10
    ctx->r3 = 0 | 0X10;
L_8003C6D4:
    // mflo        $v0
    ctx->r2 = lo;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // div         $zero, $v0, $v1
	if (ctx->r3 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
	}
	else
	{
		lo = 0;
		hi = 0;
	}
    
    // bne         $v1, $zero, L_8003C6EC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003C6EC;
    }
    // nop

    // break       7
    do_break(2147731176);
L_8003C6EC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003C704
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003C704;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003C704
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003C704;
    }
    // nop

    // break       6
    do_break(2147731200);
L_8003C704:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
L_8003C710:
    // jr          $ra
    // nop

    return;
    // nop

;}
