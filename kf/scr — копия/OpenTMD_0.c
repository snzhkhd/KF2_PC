#include "recomp.h"
#include "disable_warnings.h"

void OpenTMD_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x6EAC
    ctx->r2 = ADD32(ctx->r2, -0X6EAC);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // addiu       $a2, $a2, -0x6EA8
    ctx->r6 = ADD32(ctx->r6, -0X6EA8);
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // addiu       $a3, $a3, -0x6EB0
    ctx->r7 = ADD32(ctx->r7, -0X6EB0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80065CF8
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    AnalizingTMD(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6EA4($at)
    MEM_W(-0X6EA4, ctx->r1) = ctx->r2;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    return;
;}
