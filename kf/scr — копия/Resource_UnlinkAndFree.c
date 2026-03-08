#include "recomp.h"
#include "disable_warnings.h"

void Resource_UnlinkAndFree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80037170
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80037170;
    }
    // nop

    // jal         0x8004C774
    // nop

    Mem_FreeBlock(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_80037170:
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
