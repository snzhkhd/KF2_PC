#include "recomp.h"
#include "disable_warnings.h"

void sub_80051E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x314($v0)
    ctx->r2 = MEM_W(-0X314, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // bne         $v0, $zero, L_80051E7C
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80051E7C;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x314($at)
    MEM_W(-0X314, ctx->r1) = ctx->r2;
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // addiu       $a0, $a0, 0x1508
    ctx->r4 = ADD32(ctx->r4, 0X1508);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x774($at)
    MEM_W(-0X774, ctx->r1) = 0;
    // jal         0x80051E8C
    // nop

    sub_80051E8C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x9
    ctx->r4 = ctx->r4 | 0X9;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // jal         0x80062AB0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    KF_OpenEvent(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, -0x718($at)
    MEM_W(-0X718, ctx->r1) = ctx->r4;
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80051E7C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
