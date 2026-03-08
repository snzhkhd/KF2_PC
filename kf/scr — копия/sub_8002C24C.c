#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4B24
    ctx->r5 = ADD32(ctx->r5, -0X4B24);
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // bgtz        $v1, L_8002C270
    if (SIGNED(ctx->r3) > 0) {
        // nop
    
        goto L_8002C270;
    }
    // nop

    // j           L_8002C294
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    goto L_8002C294;
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8002C270:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B26($a0)
    ctx->r4 = MEM_HU(-0X4B26, ctx->r4);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002C290
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C290;
    }
    // nop

    // j           L_8002C294
    // sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    goto L_8002C294;
    // sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
L_8002C290:
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8002C294:
    // jr          $ra
    // nop

    return;
    // nop

;}
