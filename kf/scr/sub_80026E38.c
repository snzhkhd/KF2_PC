#include "recomp.h"
#include "disable_warnings.h"

void sub_80026E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4B2C($v0)
    ctx->r2 = MEM_HS(-0X4B2C, ctx->r2);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    // sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5) << 4;
    // mflo        $v0
    ctx->r2 = lo;
    // bne         $a2, $zero, L_80026E64
    if (ctx->r6 != 0) {
        // sra         $v1, $v0, 8
        ctx->r3 = S32(ctx->r2) >> 8;
        goto L_80026E64;
    }
    // sra         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2) >> 8;
    // j           L_80026ED8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80026ED8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80026E64:
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // subu        $a0, $a2, $v1
    ctx->r4 = SUB32(ctx->r6, ctx->r3);
    // bgez        $a0, L_80026E78
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_80026E78;
    }
    // nop

    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80026E78:
    // bne         $v1, $zero, L_80026E84
    if (ctx->r3 != 0) {
        // mult        $a2, $a2
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80026E84;
    }
    // mult        $a2, $a2
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $v1, $zero, 0x10
    ctx->r3 = 0 | 0X10;
L_80026E84:
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
		hi = 0;
		lo = 0;
	}
    
    // bne         $v1, $zero, L_80026E9C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80026E9C;
    }
    // nop

    // break       7
    do_break(2147643032);
L_80026E9C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80026EB4
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80026EB4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80026EB4
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80026EB4;
    }
    // nop

    // break       6
    do_break(2147643056);
L_80026EB4:
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_80026ED8:
    // jr          $ra
    // nop

    return;
    // nop

;}
