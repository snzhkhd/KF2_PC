#include "recomp.h"
#include "disable_warnings.h"

void TriggerLightFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // lhu         $t2, 0x58($sp)
    ctx->r10 = MEM_HU(0X58, ctx->r29);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $t0, $v0, L_8002EAB8
    if (ctx->r8 != ctx->r2) {
        // sw          $ra, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r31;
        goto L_8002EAB8;
    }
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // bne         $v1, $t0, L_8002EAB8
    if (ctx->r3 != ctx->r8) {
        // andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
        goto L_8002EAB8;
    }
    // andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // beq         $v0, $v1, L_8002EACC
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8002EACC;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002EAB8:
    // ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
    // sb          $a0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r4;
    // sb          $a1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r5;
    // sb          $a2, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r6;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002EACC:
    // beq         $a3, $v0, L_8002EADC
    if (ctx->r7 == ctx->r2) {
        // sll         $a2, $t2, 16
        ctx->r6 = S32(ctx->r10) << 16;
        goto L_8002EADC;
    }
    // sll         $a2, $t2, 16
    ctx->r6 = S32(ctx->r10) << 16;
    // sh          $a3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r7;
    // ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
L_8002EADC:
    // addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x8002E9E8
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    UpdateEnvironmentTint(rdram, ctx);
    goto after_0;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_0:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
