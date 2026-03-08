#include "recomp.h"
#include "disable_warnings.h"

void sub_80033DB4(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("sub_80033DB4\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A1C($a1)
    ctx->r5 = MEM_W(-0X4A1C, ctx->r5);
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // slti        $v0, $a1, 0xF0
    ctx->r2 = SIGNED(ctx->r5) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_80033E34
    if (ctx->r2 == 0) {
        // sw          $ra, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r31;
        goto L_80033E34;
    }
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    // bgez        $a1, L_80033DDC
    if (SIGNED(ctx->r5) >= 0) {
        // ori         $v0, $zero, 0x80
        ctx->r2 = 0 | 0X80;
        goto L_80033DDC;
    }
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80033DDC:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC0
    ctx->r2 = 0 | 0XC0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x37
    ctx->r2 = 0 | 0X37;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7BDC
    ctx->r2 = 0 | 0X7BDC;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    // ori         $a3, $zero, 0xF0
    ctx->r7 = 0 | 0XF0;
    // jal         0x80033C78
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    RenderFadeOverlay(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_0:
L_80033E34:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
