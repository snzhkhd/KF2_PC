#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libetc.h"
#include "psx/libpad.h"

void KF_PadInit(uint8_t* rdram, recomp_context* ctx) 
{
 //   PadInit((int)ctx->r4);



    

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $a0, -0x19FC($at)
    MEM_W(-0X19FC, ctx->r1) = ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FF8($at)
    MEM_W(-0X6FF8, ctx->r1) = ctx->r2;
    // jal         0x80061B54
    // nop

    KF_ResetCallback(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x2000
    ctx->r4 = S32(0X2000 << 16);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, -0x6FF8
    ctx->r5 = ADD32(ctx->r5, -0X6FF8);
    // jal         0x80062A60
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    PAD_init2(rdram, ctx);
    goto after_1;
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    after_1:
    // jal         0x80062A70
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_ChangeClearPAD(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
