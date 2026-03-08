#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4B28
    ctx->r5 = ADD32(ctx->r5, -0X4B28);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // bgtz        $v1, L_8002C218
    if (SIGNED(ctx->r3) > 0) {
        // nop
    
        goto L_8002C218;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // jal         0x8002C06C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002C06C(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // j           L_8002C23C
    // nop

    goto L_8002C23C;
    // nop

L_8002C218:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B2A($a0)
    ctx->r4 = MEM_HU(-0X4B2A, ctx->r4);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002C238
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C238;
    }
    // nop

    // j           L_8002C23C
    // sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    goto L_8002C23C;
    // sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
L_8002C238:
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8002C23C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
