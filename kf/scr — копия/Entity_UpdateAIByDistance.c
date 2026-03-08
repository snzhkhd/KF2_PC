#include "recomp.h"
#include "disable_warnings.h"

void Entity_UpdateAIByDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79B4($v0)
    ctx->r2 = MEM_W(0X79B4, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(0X2C, ctx->r2);
    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015954
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    CalculateDistance(rdram, ctx);
    goto after_0;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_0:
    // jal         0x8003C038
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    Entity_SelectAction(rdram, ctx);
    goto after_1;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
