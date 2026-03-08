#include "recomp.h"
#include "disable_warnings.h"

void sub_8003B9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // addiu       $s1, $s1, -0x19F8
    ctx->r17 = ADD32(ctx->r17, -0X19F8);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // ori         $s2, $zero, 0xC7
    ctx->r18 = 0 | 0XC7;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_8003B9CC:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8003BA4C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003BA4C;
    }
    // nop

    // lbu         $v0, -0xF($s0)
    ctx->r2 = MEM_BU(-0XF, ctx->r16);
    // nop

    // bne         $v0, $v1, L_8003BA4C
    if (ctx->r2 != ctx->r3) {
        // lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
        goto L_8003BA4C;
    }
    // lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // lw          $v0, -0xC($s0)
    ctx->r2 = MEM_W(-0XC, ctx->r16);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $v1, 0xF003
    ctx->r3 = S32(0XF003 << 16);
    // bne         $v0, $v1, L_8003BA4C
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8003BA4C;
    }
    // nop

    // lh          $v0, 0x58($s0)
    ctx->r2 = MEM_H(0X58, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8003BA28
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BA28;
    }
    // nop

    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8003BA4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BA4C;
    }
    // nop

L_8003BA28:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x4C($v0)
    ctx->r2 = MEM_W(0X4C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // jal         0x8003B984
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8003B984(rdram, ctx);
    goto after_1;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
L_8003BA4C:
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s2, $v0, L_8003B9CC
    if (ctx->r18 != ctx->r2) {
        // addiu       $s1, $s1, 0x7C
        ctx->r17 = ADD32(ctx->r17, 0X7C);
        goto L_8003B9CC;
    }
    // addiu       $s1, $s1, 0x7C
    ctx->r17 = ADD32(ctx->r17, 0X7C);
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
