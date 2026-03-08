#include "recomp.h"
#include "disable_warnings.h"

void KF_DrawOTag(uint8_t* rdram, recomp_context* ctx) 
{
  //  printf("DrawOTag\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x61A2($v0)
    ctx->r2 = MEM_BU(0X61A2, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80063670
    if (ctx->r2 != 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_80063670;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x37C4
    ctx->r4 = ADD32(ctx->r4, 0X37C4);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x619C($v0)
    ctx->r2 = MEM_W(0X619C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
L_80063670:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6198($v0)
    ctx->r2 = MEM_W(0X6198, ctx->r2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(0X18, ctx->r2);
    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
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
