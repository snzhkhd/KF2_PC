#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_render.h"

void KF_SetDispMask(uint8_t* rdram, recomp_context* ctx) 
{
	SetDispMask((int)ctx->r4);
//	// Ёмул€ци€ сброса GPU не нужна в HLE
//	//ctx->r2 = 0;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // lui         $s1, 0x8007
//    ctx->r17 = S32(0X8007 << 16);
//    // addiu       $s1, $s1, 0x61A2
//    ctx->r17 = ADD32(ctx->r17, 0X61A2);
//    // sw          $ra, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r31;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // lbu         $v0, 0x0($s1)
//    ctx->r2 = MEM_BU(0X0, ctx->r17);
//    // nop
//
//    // sltiu       $v0, $v0, 0x2
//    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_8006307C
//    if (ctx->r2 != 0) {
//        // addu        $s0, $a0, $zero
//        ctx->r16 = ADD32(ctx->r4, 0);
//        goto L_8006307C;
//    }
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x3718
//    ctx->r4 = ADD32(ctx->r4, 0X3718);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x619C($v0)
//    ctx->r2 = MEM_W(0X619C, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_0;
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    after_0:
//L_8006307C:
//    // bne         $s0, $zero, L_80063090
//    if (ctx->r16 != 0) {
//        // addiu       $a0, $s1, 0x6A
//        ctx->r4 = ADD32(ctx->r17, 0X6A);
//        goto L_80063090;
//    }
//    // addiu       $a0, $s1, 0x6A
//    ctx->r4 = ADD32(ctx->r17, 0X6A);
//    // addiu       $a1, $zero, -0x1
//    ctx->r5 = ADD32(0, -0X1);
//    // jal         0x80065828
//    // ori         $a2, $zero, 0x14
//    ctx->r6 = 0 | 0X14;
//    memset_1(rdram, ctx);
//    goto after_1;
//    // ori         $a2, $zero, 0x14
//    ctx->r6 = 0 | 0X14;
//    after_1:
//L_80063090:
//    // lui         $a0, 0x300
//    ctx->r4 = S32(0X300 << 16);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6198($v0)
//    ctx->r2 = MEM_W(0X6198, ctx->r2);
//    // beq         $s0, $zero, L_800630A8
//    if (ctx->r16 == 0) {
//        // ori         $a0, $a0, 0x1
//        ctx->r4 = ctx->r4 | 0X1;
//        goto L_800630A8;
//    }
//    // ori         $a0, $a0, 0x1
//    ctx->r4 = ctx->r4 | 0X1;
//    // lui         $a0, 0x300
//    ctx->r4 = S32(0X300 << 16);
//L_800630A8:
//    // lw          $v0, 0x10($v0)
//    ctx->r2 = MEM_W(0X10, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // nop
//
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // lw          $ra, 0x18($sp)
//    ctx->r31 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
