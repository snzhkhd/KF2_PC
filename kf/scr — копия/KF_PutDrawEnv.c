#include "_context.h"
#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "gpu/PsyX_GPU.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"
#include <string>



void KF_PutDrawEnv(uint8_t* rdram, recomp_context* ctx)
{
   /* printf("[DrawEnv] clip x0=%d y0=%d x1=%d y1=%d dfe=%d\n",
        activeDrawEnv.clip.x, activeDrawEnv.clip.y,
        activeDrawEnv.clip.x + activeDrawEnv.clip.w,
        activeDrawEnv.clip.y + activeDrawEnv.clip.h,
        activeDrawEnv.dfe);*/

    DRAWENV* env = (DRAWENV*)GET_PTR(ctx->r4);
    memcpy(&activeDrawEnv, env, sizeof(DRAWENV));
    PutDrawEnv(env); 
    ctx->r2 = ctx->r4;
}
    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // addiu       $s2, $s2, 0x61A2
    ctx->r18 = ADD32(ctx->r18, 0X61A2);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_800636F4
    if (ctx->r2 != 0) {
        // addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
        goto L_800636F4;
    }
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x37D8
    ctx->r4 = ADD32(ctx->r4, 0X37D8);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x619C($v0)
    ctx->r2 = MEM_W(0X619C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
L_800636F4:
    // addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80063DB8
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    BuildRenderCommand(rdram, ctx);
    goto after_1;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(0X1C, ctx->r17);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6198($v1)
    ctx->r3 = MEM_W(0X6198, ctx->r3);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(0X18, ctx->r3);
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // jalr        $v0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // addiu       $a0, $s2, 0xE
    ctx->r4 = ADD32(ctx->r18, 0XE);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80065864
    // ori         $a2, $zero, 0x5C
    ctx->r6 = 0 | 0X5C;
    memcpy_recomp(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x5C
    ctx->r6 = 0 | 0X5C;
    after_3:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
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
    */
