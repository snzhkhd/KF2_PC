#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void KF_DrawSync(uint8_t* rdram, recomp_context* ctx) 
{
    //static int ds_count = 0;
    //printf("[DrawSync]\n");
    //GR_UpdateVRAM();
    //GR_ReadFramebufferDataToVRAM();
    DrawSync((int)ctx->r4);
    PsyX_UpdateInput();
    ctx->r2 = 0;
}

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lbu         $v0, 0x61A2($v0)
//    ctx->r2 = MEM_BU(0X61A2, ctx->r2);
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // sltiu       $v0, $v0, 0x2
//    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_8006310C
//    if (ctx->r2 != 0) {
//        // sw          $ra, 0x14($sp)
//        MEM_W(0X14, ctx->r29) = ctx->r31;
//        goto L_8006310C;
//    }
//    // sw          $ra, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r31;
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x372C
//    ctx->r4 = ADD32(ctx->r4, 0X372C);
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
//L_8006310C:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6198($v0)
//    ctx->r2 = MEM_W(0X6198, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x3C($v0)
//    ctx->r2 = MEM_W(0X3C, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_1;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_1:
//    // lw          $ra, 0x14($sp)
//    ctx->r31 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

