#include "recomp.h"
#include "disable_warnings.h"

void CalculateNextCdChunk(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("CalculateNextCdChunk\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $v1, 0x22($a0)
    ctx->r3 = MEM_HS(0X22, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x11
    ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // bne         $v0, $zero, L_800173DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800173DC;
    }
    // nop

    // lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(0X22, ctx->r4);
    // ori         $v1, $zero, 0x10
    ctx->r3 = 0 | 0X10;
    // sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // j           L_800173E4
    // sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    goto L_800173E4;
    // sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
L_800173DC:
    // sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
    // sh          $zero, 0x22($a0)
    MEM_H(0X22, ctx->r4) = 0;
L_800173E4:
    // jr          $ra
    // nop

    return;
    // nop

;}
