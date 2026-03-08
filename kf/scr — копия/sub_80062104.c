#include "recomp.h"
#include "disable_warnings.h"

void sub_80062104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, 0x5044
    ctx->r16 = ADD32(ctx->r16, 0X5044);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800621A0
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800621A0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x60D4($v0)
    ctx->r2 = MEM_W(0X60D4, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x60D8($a0)
    ctx->r4 = MEM_W(0X60D8, ctx->r4);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v1, 0x5076($at)
    MEM_H(0X5076, ctx->r1) = ctx->r3;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x60D0($a0)
    ctx->r4 = MEM_W(0X60D0, ctx->r4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, 0x5078($at)
    MEM_W(0X5078, ctx->r1) = ctx->r3;
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x60D8($a0)
    ctx->r4 = MEM_W(0X60D8, ctx->r4);
    // lui         $v1, 0x7777
    ctx->r3 = S32(0X7777 << 16);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // ori         $v1, $v1, 0x7777
    ctx->r3 = ctx->r3 | 0X7777;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // jal         0x80062A80
    // nop

    ResetEntryInt(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_800621A0:
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
