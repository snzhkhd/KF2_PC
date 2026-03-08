#include "recomp.h"
#include "disable_warnings.h"

void sub_80025064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $a0, 0x138($gp)
    ctx->r4 = MEM_W(0X138, ctx->r28);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80017C40
    // nop

    KF_PadChkVsync(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x8004C8D4
    // nop

    StopCARD2(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80061A8C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_PadInit(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
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
