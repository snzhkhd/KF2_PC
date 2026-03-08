#include "recomp.h"
#include "disable_warnings.h"

void sub_80044784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // jal         0x80042BD4
    // addiu       $a3, $s0, 0x2C
    ctx->r7 = ADD32(ctx->r16, 0X2C);
    sub_80042BD4(rdram, ctx);
    goto after_0;
    // addiu       $a3, $s0, 0x2C
    ctx->r7 = ADD32(ctx->r16, 0X2C);
    after_0:
    // lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(0X24, ctx->r16);
    // jal         0x80062BF0
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    after_1:
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x64
    ctx->r6 = 0 | 0X64;
    // lhu         $v1, 0x26($s0)
    ctx->r3 = MEM_HU(0X26, ctx->r16);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, -0x80
    ctx->r3 = ADD32(ctx->r3, -0X80);
    // sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(0X28, ctx->r16);
    // addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x63A4
    ctx->r2 = ADD32(ctx->r2, 0X63A4);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // jal         0x80042D2C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_80044800
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80044800;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
L_80044800:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
