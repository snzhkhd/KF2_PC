#include "recomp.h"
#include "disable_warnings.h"

void CleaningUpTempResources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // addiu       $s0, $s0, 0xB58
    ctx->r16 = ADD32(ctx->r16, 0XB58);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // ori         $s1, $zero, 0xB
    ctx->r17 = 0 | 0XB;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_800371A8:
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800371C4
    if (ctx->r2 == 0) {
        // addiu       $v0, $s1, -0x1
        ctx->r2 = ADD32(ctx->r17, -0X1);
        goto L_800371C4;
    }
    // addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // jal         0x80037138
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    Resource_UnlinkAndFree(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_800371C4:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $s2, L_800371A8
    if (ctx->r2 != ctx->r18) {
        // addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
        goto L_800371A8;
    }
    // addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
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
