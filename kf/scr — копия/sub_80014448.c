#include "recomp.h"
#include "disable_warnings.h"

void sub_80014448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x5574
    ctx->r3 = ADD32(ctx->r3, -0X5574);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(0X0, ctx->r7);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lh          $a1, -0x438($v1)
    ctx->r5 = MEM_H(-0X438, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a1, $v0, L_800144B0
    if (ctx->r5 == ctx->r2) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_800144B0;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // beq         $a1, $v0, L_800144B0
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_800144B0;
    }
    // nop

    // lh          $v0, 0x6($a3)
    ctx->r2 = MEM_H(0X6, ctx->r7);
    // lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(0X0, ctx->r4);
    // lh          $a2, 0x2($a3)
    ctx->r6 = MEM_H(0X2, ctx->r7);
    // lh          $a3, 0x4($a3)
    ctx->r7 = MEM_H(0X4, ctx->r7);
    // jal         0x80058A90
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80058A90(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
L_800144B0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
