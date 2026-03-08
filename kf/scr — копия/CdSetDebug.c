#include "recomp.h"
#include "disable_warnings.h"

void KF_CdSetDebug(uint8_t* rdram, recomp_context* ctx) 
{
	ctx->r2 = 0;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // beq         $v0, $zero, L_8004C9F0
//    if (ctx->r2 == 0) {
//        // sll         $v0, $a0, 2
//        ctx->r2 = S32(ctx->r4) << 2;
//        goto L_8004C9F0;
//    }
//    // sll         $v0, $a0, 2
//    ctx->r2 = S32(ctx->r4) << 2;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0xB64
//    ctx->r1 = ADD32(ctx->r1, -0XB64);
//    // addu        $at, $at, $v0
//    ctx->r1 = ADD32(ctx->r1, ctx->r2);
//    // lw          $v0, 0x0($at)
//    ctx->r2 = MEM_W(0X0, ctx->r1);
//    // j           L_8004C9F8
//    // nop
//
//    goto L_8004C9F8;
//    // nop
//
//L_8004C9F0:
//    // lui         $v0, 0x8001
//    ctx->r2 = S32(0X8001 << 16);
//    // addiu       $v0, $v0, 0x2D34
//    ctx->r2 = ADD32(ctx->r2, 0X2D34);
//L_8004C9F8:
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
