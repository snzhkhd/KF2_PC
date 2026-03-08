#include "recomp.h"
#include "disable_warnings.h"

void sub_80014594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // jal         0x80050B64
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_80050B64(rdram, ctx);
    goto after_0;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x559C
    ctx->r3 = ADD32(ctx->r3, -0X559C);
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
L_800145B8:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_800145E0
    if (ctx->r2 == ctx->r5) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_800145E0;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800145E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800145E0;
    }
    // nop

    // sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_800145E0:
    // bne         $a0, $a1, L_800145B8
    if (ctx->r4 != ctx->r5) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_800145B8;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
