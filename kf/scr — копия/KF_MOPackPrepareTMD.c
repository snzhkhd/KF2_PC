#include "recomp.h"
#include "disable_warnings.h"

void KF_MOPackPrepareTMD(uint8_t* rdram, recomp_context* ctx)
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lhu         $s1, 0x0($s0)
    ctx->r17 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // beq         $v0, $zero, L_80036524
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80036524;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // addiu       $s4, $s4, 0x254
    ctx->r20 = ADD32(ctx->r20, 0X254);
    // ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
L_800364DC:
    // lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(0X0, ctx->r16);
    // nop

    // sltiu       $v0, $s2, 0x5
    ctx->r2 = ctx->r18 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003650C
    if (ctx->r2 != 0) {
        // andi        $a0, $s3, 0xFFFF
        ctx->r4 = ctx->r19 & 0XFFFF;
        goto L_8003650C;
    }
    // andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // jal         0x80036594
    // sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    KF_RenderSetTMDFromLoadedMO(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    after_0:
    // lw          $a0, -0x4($s4)
    ctx->r4 = MEM_W(-0X4, ctx->r20);
    // jal         0x80030130
    // nop

    KF_TMDIndicesToOffsets(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_8003650C:
    // addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_800364DC
    if (ctx->r2 != 0) {
        // addu        $s1, $s1, $s5
        ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_800364DC;
    }
    // addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80036524:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
