#include "recomp.h"
#include "disable_warnings.h"

void sub_800446E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // lw          $s1, 0x1184($s1)
    ctx->r17 = MEM_W(0X1184, ctx->r17);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // lhu         $v1, 0x2C($s1)
    ctx->r3 = MEM_HU(0X2C, ctx->r17);
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sh          $v1, 0x2C($s1)
    MEM_H(0X2C, ctx->r17) = ctx->r3;
    // lh          $v0, 0x2C($s1)
    ctx->r2 = MEM_H(0X2C, ctx->r17);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v1, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r3;
    // sh          $v1, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r3;
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(0X38, ctx->r29);
    // sra         $a2, $a2, 12
    ctx->r6 = S32(ctx->r6) >> 12;
    // addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // mflo        $a1
    ctx->r5 = lo;
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    // subu        $a1, $a2, $a1
    ctx->r5 = SUB32(ctx->r6, ctx->r5);
    // jal         0x80042938
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    sub_80042938(rdram, ctx);
    goto after_0;
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // lh          $v0, 0x2C($s1)
    ctx->r2 = MEM_H(0X2C, ctx->r17);
    // nop

    // slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8004476C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8004476C;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_8004476C:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
