#include "recomp.h"
#include "disable_warnings.h"

void sub_80019128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A58($a0)
    ctx->r4 = MEM_W(-0X5A58, ctx->r4);
    // jal         0x80062820
    // nop

    KF_CloseEvent(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A4C($a0)
    ctx->r4 = MEM_W(-0X5A4C, ctx->r4);
    // jal         0x80062820
    // nop

    KF_CloseEvent(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A48($a0)
    ctx->r4 = MEM_W(-0X5A48, ctx->r4);
    // jal         0x80062820
    // nop

    KF_CloseEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A40($a0)
    ctx->r4 = MEM_W(-0X5A40, ctx->r4);
    // jal         0x80062820
    // nop

    KF_CloseEvent(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
