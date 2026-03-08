#include "recomp.h"
#include "disable_warnings.h"

void FindFreeAudioChannel(uint8_t* rdram, recomp_context* ctx) 
{
    printf("FindFreeAudioChannel\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4B74
    ctx->r17 = ADD32(ctx->r17, -0X4B74);
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80014AF4:
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80014B0C
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_80014B0C;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // j           L_80014B94
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_80014B94;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80014B0C:
    // bne         $a1, $v1, L_80014AF4
    if (ctx->r5 != ctx->r3) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_80014AF4;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4B74
    ctx->r17 = ADD32(ctx->r17, -0X4B74);
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80014B24:
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(0X0, ctx->r17);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $v0, L_80014B88
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_80014B88;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x59AC
    ctx->r16 = ADD32(ctx->r16, -0X59AC);
    // ori         $a1, $zero, 0x81
    ctx->r5 = 0 | 0X81;
L_80014B40:
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(0X0, ctx->r16);
    // nop

    // beq         $a0, $s2, L_80014B60
    if (ctx->r4 == ctx->r18) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_80014B60;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // beq         $v0, $s1, L_80014B74
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_80014B74;
    }
    // nop

L_80014B60:
    // bne         $a1, $s2, L_80014B40
    if (ctx->r5 != ctx->r18) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80014B40;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80014B68:
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // j           L_80014B94
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_80014B94;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80014B74:
    // jal         0x8005D010
    // nop

    FreeSPUVoice(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    // j           L_80014B68
    // sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    goto L_80014B68;
    // sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80014B88:
    // bne         $a1, $s2, L_80014B24
    if (ctx->r5 != ctx->r18) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_80014B24;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80014B94:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
