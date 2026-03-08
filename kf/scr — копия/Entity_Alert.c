#include "recomp.h"
#include "disable_warnings.h"

void Entity_Alert(uint8_t* rdram, recomp_context* ctx) {
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
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(0X20, ctx->r16);
    // sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    // sh          $zero, 0x40($s0)
    MEM_H(0X40, ctx->r16) = 0;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // jal         0x8003B784
    // sh          $v1, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r3;
    Entity_UpdatePhysics(rdram, ctx);
    goto after_0;
    // sh          $v1, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r3;
    after_0:
    // jal         0x8003B8BC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    Entity_EnterCombatState(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // bne         $v1, $v0, L_8003BAC4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003BAC4;
    }
    // nop

    // sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
L_8003BAC4:
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
