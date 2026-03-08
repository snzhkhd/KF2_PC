#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"

void KF_RenderBegin(uint8_t* rdram, recomp_context* ctx) 
{

    PsyX_BeginScene();
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, 0x138
    ctx->r3 = ADD32(ctx->r3, 0X138);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(0X0, ctx->r3);
    // addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x158($at)
    MEM_W(0X158, ctx->r1) = ctx->r2;
    // sll         $a0, $a0, 15
    ctx->r4 = S32(ctx->r4) << 15;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $a0, 0x15C($at)
    MEM_W(0X15C, ctx->r1) = ctx->r4;
    // jal         0x8006353C
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    KF_ClearOTagR(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    after_0:
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // sw          $zero, 0x1B4($gp)
    MEM_W(0X1B4, ctx->r28) = 0;
    // sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $zero, 0x4E08($at)
    MEM_W(0X4E08, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $zero, 0x4E04($at)
    MEM_W(0X4E04, ctx->r1) = 0;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
