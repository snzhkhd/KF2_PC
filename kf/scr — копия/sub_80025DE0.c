#include "recomp.h"
#include "disable_warnings.h"

void sub_80025DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lw          $a0, 0x118($gp)
    ctx->r4 = MEM_W(0X118, ctx->r28);
    // jal         0x80062AE0
    // nop

    KF_TestEvent(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $a0, 0x11C($gp)
    ctx->r4 = MEM_W(0X11C, ctx->r28);
    // jal         0x80062AE0
    // nop

    KF_TestEvent(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0x120($gp)
    ctx->r4 = MEM_W(0X120, ctx->r28);
    // jal         0x80062AE0
    // nop

    KF_TestEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $a0, 0x124($gp)
    ctx->r4 = MEM_W(0X124, ctx->r28);
    // jal         0x80062AE0
    // nop

    KF_TestEvent(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
