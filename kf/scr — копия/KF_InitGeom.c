#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"

void KF_InitGeom(uint8_t* rdram, recomp_context* ctx) 
{
    printf("KF_InitGeom\n");
    //ctx_to_gte(ctx);
    //InitGeom();
    //gte_to_ctx(ctx);

    ctx->cp2c[29] = 0x155;
    ctx->cp2c[30] = 0x100;
    ctx->cp2c[26] = 0x3E8;      // H = focal length
    ctx->cp2c[27] = 0xFFFFEF9E;
    ctx->cp2c[28] = 0x00140000;
    ctx->cp2c[24] = 0x00A00000; // OFX = 160 << 16
    ctx->cp2c[25] = 0x00780000; // OFY = 120 << 16
    ctx_to_gte(ctx);
    ctx->r2 = 0;

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $at, 0x8007
    //ctx->r1 = S32(0X8007 << 16);
    //// sw          $ra, 0x37C($at)
    //MEM_W(0X37C, ctx->r1) = ctx->r31;
    //// jal         0x8005F5F8
    //// nop

    //_patch_gte(rdram, ctx);
    //goto after_0;
    //// nop

    //after_0:
    //// lui         $ra, 0x8007
    //ctx->r31 = S32(0X8007 << 16);
    //// lw          $ra, 0x37C($ra)
    //ctx->r31 = MEM_W(0X37C, ctx->r31);
    //// nop

    //// mfc0        $v0, Status
    //ctx->r2 = cop0_status_read(ctx);
    //// lui         $v1, 0x4000
    //ctx->r3 = S32(0X4000 << 16);
    //// or          $v0, $v0, $v1
    //ctx->r2 = ctx->r2 | ctx->r3;
    //// mtc0        $v0, Status
    //cop0_status_write(ctx, ctx->r2);
    //// nop

    //// addiu       $t0, $zero, 0x155
    //ctx->r8 = ADD32(0, 0X155);
    //// ctc2        $t0, $29
    //gte_ctc2(ctx, 8, 29);
    //// nop

    //// addiu       $t0, $zero, 0x100
    //ctx->r8 = ADD32(0, 0X100);
    //// ctc2        $t0, $30
    //gte_ctc2(ctx, 8, 30);
    //// nop

    //// addiu       $t0, $zero, 0x3E8
    //ctx->r8 = ADD32(0, 0X3E8);
    //// ctc2        $t0, $26
    //gte_ctc2(ctx, 8, 26);
    //// nop

    //// addiu       $t0, $zero, -0x1062
    //ctx->r8 = ADD32(0, -0X1062);
    //// ctc2        $t0, $27
    //gte_ctc2(ctx, 8, 27);
    //// nop

    //// lui         $t0, 0x140
    //ctx->r8 = S32(0X140 << 16);
    //// ctc2        $t0, $28
    //gte_ctc2(ctx, 8, 28);
    //// nop

    //// ctc2        $zero, $24
    //gte_ctc2(ctx, 0, 24);
    //// ctc2        $zero, $25
    //gte_ctc2(ctx, 0, 25);
    //// nop

    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
