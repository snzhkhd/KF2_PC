#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79B4($s0)
    ctx->r16 = MEM_W(0X79B4, ctx->r16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8003E514
    if (ctx->r2 != 0) {
        // addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
        goto L_8003E514;
    }
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // lh          $v0, 0x50($s0)
    ctx->r2 = MEM_H(0X50, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x54($s0)
    ctx->r2 = MEM_H(0X54, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    KF_SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // beq         $s1, $zero, L_8003E520
    if (ctx->r17 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8003E520;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lh          $a0, 0x50($s0)
    ctx->r4 = MEM_H(0X50, ctx->r16);
    // nop

    // mult        $a0, $s2
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    // div         $zero, $a2, $s1
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_8003E4A0
    if (ctx->r17 != 0) {
        // nop
    
        goto L_8003E4A0;
    }
    // nop

    // break       7
    do_break(2147738780);
L_8003E4A0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_8003E4B8
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003E4B8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_8003E4B8
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_8003E4B8;
    }
    // nop

    // break       6
    do_break(2147738804);
L_8003E4B8:
    // mflo        $a2
    ctx->r6 = lo;
    // jal         0x80014D48
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80014D48(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // lh          $a0, 0x54($s0)
    ctx->r4 = MEM_H(0X54, ctx->r16);
    // nop

    // mult        $a0, $s2
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    // div         $zero, $a2, $s1
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_8003E4E8
    if (ctx->r17 != 0) {
        // nop
    
        goto L_8003E4E8;
    }
    // nop

    // break       7
    do_break(2147738852);
L_8003E4E8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_8003E500
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003E500;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_8003E500
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_8003E500;
    }
    // nop

    // break       6
    do_break(2147738876);
L_8003E500:
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D48
    // sh          $v0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r2;
    sub_80014D48(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r2;
    after_2:
    // sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
L_8003E514:
    // addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // jal         0x8003D8E4
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_8003D8E4(rdram, ctx);
    goto after_3;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
L_8003E520:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
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
