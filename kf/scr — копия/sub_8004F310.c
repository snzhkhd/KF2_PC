#include "recomp.h"
#include "disable_warnings.h"

void sub_8004F310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x4
    ctx->r16 = 0 | 0X4;
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_8004F320:
    // jal         0x8004C924
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_CdLastCom(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_0:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // bne         $v0, $v1, L_8004F36C
    if (ctx->r2 != ctx->r3) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8004F36C;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // addiu       $a0, $a0, -0xC60
    ctx->r4 = ADD32(ctx->r4, -0XC60);
    // jal         0x8004CA78
    // nop

    PadStopCom_0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // addiu       $a0, $a0, -0xC38
    ctx->r4 = ADD32(ctx->r4, -0XC38);
    // jal         0x8004CA90
    // nop

    KF_CdSyncCallback(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    // jal         0x8004CAA8
    // nop

    KF_CdReadyCallback(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8004F38C
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8004F38C;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004F36C:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_8004F320
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8004F320;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2FE0
    ctx->r4 = ADD32(ctx->r4, 0X2FE0);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004F38C:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
