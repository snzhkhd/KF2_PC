#include "recomp.h"
#include "disable_warnings.h"

void sub_8001A35C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4ADC
    ctx->r3 = ADD32(ctx->r3, -0X4ADC);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // blez        $v0, L_8001A380
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8001A380;
    }
    // nop

    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8001A380:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADE($v0)
    ctx->r2 = MEM_H(-0X4ADE, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x41
    ctx->r2 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // bne         $v0, $zero, L_8001A3A0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_8001A3A0;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ADE($at)
    MEM_H(-0X4ADE, ctx->r1) = ctx->r2;
L_8001A3A0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AE8($at)
    MEM_H(-0X4AE8, ctx->r1) = 0;
    // jal         0x8001A3F8
    // nop

    sub_8001A3F8(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x8001A3C8
    // nop

    sub_8001A3C8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
