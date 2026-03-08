#include "recomp.h"
#include "disable_warnings.h"

void sub_80053F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(0X40, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // bne         $v0, $zero, L_80053F28
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80053F28;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x40($at)
    MEM_W(0X40, ctx->r1) = ctx->r2;
    // j           L_80053F40
    // nop

    goto L_80053F40;
    // nop

L_80053F28:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x40($at)
    MEM_W(0X40, ctx->r1) = 0;
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80053F40:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // nop

    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
