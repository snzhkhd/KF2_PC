#include "recomp.h"
#include "disable_warnings.h"

void Math_Atan2_Fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // bgez        $a2, L_80015818
    if (SIGNED(ctx->r6) >= 0) {
        // addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
        goto L_80015818;
    }
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80015818:
    // bgez        $a1, L_80015824
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80015824;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80015824:
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800158C8
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_800158C8;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // blez        $a1, L_80015878
    if (SIGNED(ctx->r5) <= 0) {
        // sll         $a0, $a2, 12
        ctx->r4 = S32(ctx->r6) << 12;
        goto L_80015878;
    }
    // sll         $a0, $a2, 12
    ctx->r4 = S32(ctx->r6) << 12;
    // div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_80015848
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80015848;
    }
    // nop

    // break       7
    do_break(2147571780);
L_80015848:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_80015860
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015860;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80015860
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80015860;
    }
    // nop

    // break       6
    do_break(2147571804);
L_80015860:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005D978
    // nop

    Math_CORDIC_Atan(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80015944
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    goto L_80015944;
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
L_80015878:
    // bgez        $a1, L_800158C0
    if (SIGNED(ctx->r5) >= 0) {
        // nop
    
        goto L_800158C0;
    }
    // nop

    // div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_80015890
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80015890;
    }
    // nop

    // break       7
    do_break(2147571852);
L_80015890:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_800158A8
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800158A8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_800158A8
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_800158A8;
    }
    // nop

    // break       6
    do_break(2147571876);
L_800158A8:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005D978
    // nop

    Math_CORDIC_Atan(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // ori         $v1, $zero, 0x800
    ctx->r3 = 0 | 0X800;
    // j           L_80015944
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    goto L_80015944;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_800158C0:
    // j           L_80015944
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80015944;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800158C8:
    // bgez        $a2, L_8001590C
    if (SIGNED(ctx->r6) >= 0) {
        // sll         $a0, $a1, 12
        ctx->r4 = S32(ctx->r5) << 12;
        goto L_8001590C;
    }
    // sll         $a0, $a1, 12
    ctx->r4 = S32(ctx->r5) << 12;
    // div         $zero, $a0, $a2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_800158E0
    if (ctx->r6 != 0) {
        // nop
    
        goto L_800158E0;
    }
    // nop

    // break       7
    do_break(2147571932);
L_800158E0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_800158F8
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800158F8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_800158F8
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_800158F8;
    }
    // nop

    // break       6
    do_break(2147571956);
L_800158F8:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005D978
    // nop

    Math_CORDIC_Atan(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_80015944
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    goto L_80015944;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
L_8001590C:
    // div         $zero, $a0, $a2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8001591C
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8001591C;
    }
    // nop

    // break       7
    do_break(2147571992);
L_8001591C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_80015934
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80015934;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80015934
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80015934;
    }
    // nop

    // break       6
    do_break(2147572016);
L_80015934:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005D978
    // nop

    Math_CORDIC_Atan(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, 0XC00);
L_80015944:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
