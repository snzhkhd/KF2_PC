#include "recomp.h"
#include "disable_warnings.h"

void sub_8005D29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x30($v0)
    ctx->r2 = MEM_W(0X30, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // bne         $v0, $zero, L_8005D33C
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8005D33C;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, 0x3D($at)
    MEM_B(0X3D, ctx->r1) = 0;
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x3C($v0)
    ctx->r2 = MEM_BU(0X3C, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8005D2EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005D2EC;
    }
    // nop

    // jal         0x80061BE4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSyncCallback(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, 0x3C($at)
    MEM_B(0X3C, ctx->r1) = 0;
    // j           L_8005D328
    // nop

    goto L_8005D328;
    // nop

L_8005D2EC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x3E($v0)
    ctx->r2 = MEM_BU(0X3E, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8005D320
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x6
        ctx->r4 = 0 | 0X6;
        goto L_8005D320;
    }
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x38($a1)
    ctx->r5 = MEM_W(0X38, ctx->r5);
    // jal         0x80061B84
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x38($at)
    MEM_W(0X38, ctx->r1) = 0;
    // j           L_8005D328
    // nop

    goto L_8005D328;
    // nop

L_8005D320:
    // jal         0x80061B84
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_3;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
L_8005D328:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, 0x3E($at)
    MEM_B(0X3E, ctx->r1) = ctx->r2;
L_8005D33C:
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
