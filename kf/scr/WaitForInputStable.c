#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"

void WaitForInputStable(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("WaitForInputStable\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lw          $v1, 0x68($gp)
    ctx->r3 = MEM_W(0X68, ctx->r28);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80024EC0
    if (ctx->r3 != ctx->r2) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_80024EC0;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
L_80024E90:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_0:
    // beq         $v0, $zero, L_80024EC0
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80024EC0;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80024EBC
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80024EBC;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // j           L_80024E90
    // nop

    goto L_80024E90;
    // nop

L_80024EBC:
    // sw          $zero, 0x70($gp)
    MEM_W(0X70, ctx->r28) = 0;
L_80024EC0:
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
