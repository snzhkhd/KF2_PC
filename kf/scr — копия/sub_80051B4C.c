#include "recomp.h"
#include "disable_warnings.h"

void sub_80051B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7B4($v0)
    ctx->r2 = MEM_W(-0X7B4, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // bne         $v0, $zero, L_80051BAC
    if (ctx->r2 != 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_80051BAC;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lhu         $v0, -0x7D0($v0)
    ctx->r2 = MEM_HU(-0X7D0, ctx->r2);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x7A8($a1)
    ctx->r5 = MEM_W(-0X7A8, ctx->r5);
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // jal         0x800518A4
    // sllv        $a1, $v0, $a1
    ctx->r5 = S32(ctx->r2) << (ctx->r5 & 31);
    sub_800518A4(rdram, ctx);
    goto after_0;
    // sllv        $a1, $v0, $a1
    ctx->r5 = S32(ctx->r2) << (ctx->r5 & 31);
    after_0:
    // jal         0x800518A4
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_800518A4(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_1:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x800518A4
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_800518A4(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // j           L_80051BBC
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_80051BBC;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80051BAC:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800511C4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_800511C4(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80051BBC:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
