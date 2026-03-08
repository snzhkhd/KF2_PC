#include "recomp.h"
#include "disable_warnings.h"

void SEQ_Open(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x1938($a3)
    ctx->r7 = MEM_W(-0X1938, ctx->r7);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a3, $v0, L_80059E70
    if (ctx->r7 != ctx->r2) {
        // addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
        goto L_80059E70;
    }
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x32D8
    ctx->r4 = ADD32(ctx->r4, 0X32D8);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80059EEC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80059EEC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80059E70:
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $t1, $zero, 0x1
    ctx->r9 = 0 | 0X1;
L_80059E7C:
    // sllv        $v0, $t1, $v1
    ctx->r2 = S32(ctx->r9) << (ctx->r3 & 31);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // bne         $v0, $zero, L_80059E98
    if (ctx->r2 != 0) {
        // andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
        goto L_80059E98;
    }
    // andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_80059E98:
    // beq         $v0, $zero, L_80059E7C
    if (ctx->r2 == 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80059E7C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2) << (ctx->r16 & 31);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x1938($v1)
    ctx->r3 = MEM_W(-0X1938, ctx->r3);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x1938($at)
    MEM_W(-0X1938, ctx->r1) = ctx->r2;
    // jal         0x80059AFC
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    SEQ_InitData(rdram, ctx);
    goto after_1;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_1:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80059EEC
    if (ctx->r2 != ctx->r3) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80059EEC;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80059EEC:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
