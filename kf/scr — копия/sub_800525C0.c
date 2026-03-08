#include "recomp.h"
#include "disable_warnings.h"

void sub_800525C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a2, $a0, 15
    ctx->r6 = S32(ctx->r4) << 15;
    // subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_800525E4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800525E4;
    }
    // nop

    // break       7
    do_break(2147821024);
L_800525E4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_800525FC
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800525FC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_800525FC
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_800525FC;
    }
    // nop

    // break       6
    do_break(2147821048);
L_800525FC:
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v1, $a1, 15
    ctx->r3 = S32(ctx->r5) << 15;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80052620
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80052620;
    }
    // nop

    // break       7
    do_break(2147821084);
L_80052620:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80052638
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80052638;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80052638
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80052638;
    }
    // nop

    // break       6
    do_break(2147821108);
L_80052638:
    // mflo        $v1
    ctx->r3 = lo;
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x21BC
    ctx->r4 = ADD32(ctx->r4, -0X21BC);
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $a2, -0x21B4($at)
    MEM_H(-0X21B4, ctx->r1) = ctx->r6;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $v1, -0x21B2($at)
    MEM_H(-0X21B2, ctx->r1) = ctx->r3;
    // jal         0x800526FC
    // nop

    sub_800526FC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // nop

    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
