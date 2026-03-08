#include "recomp.h"
#include "disable_warnings.h"

void sub_80014DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(0X0, ctx->r5);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lw          $s1, 0x4($a1)
    ctx->r17 = MEM_W(0X4, ctx->r5);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // lw          $s2, 0x8($a1)
    ctx->r18 = MEM_W(0X8, ctx->r5);
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // jal         0x80015990
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sub_80015990(rdram, ctx);
    goto after_0;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_0:
    // mult        $s0, $s3
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80014E20
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80014E20;
    }
    // nop

    // break       7
    do_break(2147569180);
L_80014E20:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80014E38
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80014E38;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_80014E38
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_80014E38;
    }
    // nop

    // break       6
    do_break(2147569204);
L_80014E38:
    // mflo        $a1
    ctx->r5 = lo;
    // mult        $s1, $s3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80014E54
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80014E54;
    }
    // nop

    // break       7
    do_break(2147569232);
L_80014E54:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80014E6C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80014E6C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80014E6C
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80014E6C;
    }
    // nop

    // break       6
    do_break(2147569256);
L_80014E6C:
    // mflo        $a0
    ctx->r4 = lo;
    // mult        $s2, $s3
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80014E88
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80014E88;
    }
    // nop

    // break       7
    do_break(2147569284);
L_80014E88:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80014EA0
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80014EA0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80014EA0
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80014EA0;
    }
    // nop

    // break       6
    do_break(2147569308);
L_80014EA0:
    // mflo        $v1
    ctx->r3 = lo;
    // sh          $a1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r5;
    // sh          $a0, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r4;
    // sh          $v1, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r3;
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
