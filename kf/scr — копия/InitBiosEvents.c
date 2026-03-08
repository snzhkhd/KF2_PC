#include "recomp.h"
#include "disable_warnings.h"

void InitBiosEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80062AB0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    KF_OpenEvent(rdram, ctx);
    goto after_0;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // ori         $a1, $zero, 0x100
    ctx->r5 = 0 | 0X100;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // sw          $v0, 0x118($gp)
    MEM_W(0X118, ctx->r28) = ctx->r2;
    // jal         0x80062AB0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    KF_OpenEvent(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // sw          $v0, 0x11C($gp)
    MEM_W(0X11C, ctx->r28) = ctx->r2;
    // jal         0x80062AB0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    KF_OpenEvent(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    // sw          $v0, 0x120($gp)
    MEM_W(0X120, ctx->r28) = ctx->r2;
    // jal         0x80062AB0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    KF_OpenEvent(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // lw          $a0, 0x118($gp)
    ctx->r4 = MEM_W(0X118, ctx->r28);
    // sw          $v0, 0x124($gp)
    MEM_W(0X124, ctx->r28) = ctx->r2;
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $a0, 0x11C($gp)
    ctx->r4 = MEM_W(0X11C, ctx->r28);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $a0, 0x120($gp)
    ctx->r4 = MEM_W(0X120, ctx->r28);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lw          $a0, 0x124($gp)
    ctx->r4 = MEM_W(0X124, ctx->r28);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
