#include "recomp.h"
#include "disable_warnings.h"

void KF_CdIntstr(uint8_t* rdram, recomp_context* ctx) 
{
    printf("KF_CdIntstr\n");

    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lw          $v0, 0x0($at)
//    ctx->r2 = MEM_W(0X0, ctx->r1);
//    // j           L_8004CA30
//    // nop
//
//    goto L_8004CA30;
//    // nop
//
//    // lui         $v0, 0x8001
//    ctx->r2 = S32(0X8001 << 16);
//    // addiu       $v0, $v0, 0x2D34
//    ctx->r2 = ADD32(ctx->r2, 0X2D34);
//L_8004CA30:
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
