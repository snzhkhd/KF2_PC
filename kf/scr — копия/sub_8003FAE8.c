#include "recomp.h"
#include "disable_warnings.h"

void sub_8003FAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x4A($a0)
    ctx->r2 = MEM_HU(0X4A, ctx->r4);
    // ori         $v1, $zero, 0x10
    ctx->r3 = 0 | 0X10;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // slti        $v0, $s0, 0xD
    ctx->r2 = SIGNED(ctx->r16) < 0XD ? 1 : 0;
    // bne         $v0, $zero, L_8003FB1C
    if (ctx->r2 != 0) {
        // slti        $v0, $s0, -0xC
        ctx->r2 = SIGNED(ctx->r16) < -0XC ? 1 : 0;
        goto L_8003FB1C;
    }
    // slti        $v0, $s0, -0xC
    ctx->r2 = SIGNED(ctx->r16) < -0XC ? 1 : 0;
    // j           L_8003FB28
    // ori         $s0, $zero, 0xC
    ctx->r16 = 0 | 0XC;
    goto L_8003FB28;
    // ori         $s0, $zero, 0xC
    ctx->r16 = 0 | 0XC;
L_8003FB1C:
    // beq         $v0, $zero, L_8003FB28
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003FB28;
    }
    // nop

    // addiu       $s0, $zero, -0xC
    ctx->r16 = ADD32(0, -0XC);
L_8003FB28:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $a0, $s0, -0x2
    ctx->r4 = ADD32(ctx->r16, -0X2);
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 15
    ctx->r3 = S32(ctx->r3) >> 15;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
