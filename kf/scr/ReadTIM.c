#include "recomp.h"
#include "disable_warnings.h"

void KF_ReadTIM(uint8_t* rdram, recomp_context* ctx) 
{
    printf("ReadTIM\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x6EB4($a0)
    ctx->r4 = MEM_W(-0X6EB4, ctx->r4);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80065BD8
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    ParseTIMHeader(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_800658D4
    if (ctx->r3 == ctx->r2) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_800658D4;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x6EB4($a0)
    ctx->r4 = MEM_W(-0X6EB4, ctx->r4);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r3;
    // j           L_800658D8
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800658D8;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800658D4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800658D8:
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
