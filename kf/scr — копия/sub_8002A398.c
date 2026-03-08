#include "recomp.h"
#include "disable_warnings.h"

void sub_8002A398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // slti        $v0, $a0, 0x140
    ctx->r2 = SIGNED(ctx->r4) < 0X140 ? 1 : 0;
    // bne         $v0, $zero, L_8002A3CC
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8002A3CC;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $a0, $a0, -0x140
    ctx->r4 = ADD32(ctx->r4, -0X140);
    // slti        $v0, $a0, 0x381
    ctx->r2 = SIGNED(ctx->r4) < 0X381 ? 1 : 0;
    // bne         $v0, $zero, L_8002A3BC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002A3BC;
    }
    // nop

    // ori         $a0, $zero, 0x380
    ctx->r4 = 0 | 0X380;
L_8002A3BC:
    // sra         $a1, $a0, 3
    ctx->r5 = S32(ctx->r4) >> 3;
    // ori         $a0, $zero, 0xC
    ctx->r4 = 0 | 0XC;
    // jal         0x80014570
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    PlaySoundEffect(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_0:
L_8002A3CC:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
