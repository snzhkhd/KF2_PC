#include "recomp.h"
#include "disable_warnings.h"

void Flush3dRender(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lw          $v1, 0x64($gp)
    ctx->r3 = MEM_W(0X64, ctx->r28);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80024D98
    if (ctx->r3 != ctx->r2) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80024D98;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x24C($a0)
    ctx->r4 = MEM_W(0X24C, ctx->r4);
    // jal         0x80017C40
    // nop

    KF_PadChkVsync(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sw          $zero, 0x64($gp)
    MEM_W(0X64, ctx->r28) = 0;
L_80024D98:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
