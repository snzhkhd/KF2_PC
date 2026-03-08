#include "recomp.h"
#include "disable_warnings.h"

void sub_80050A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D24($v0)
    ctx->r2 = MEM_W(-0X5D24, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x10A8($v1)
    ctx->r3 = MEM_W(-0X10A8, ctx->r3);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D28($v0)
    ctx->r2 = MEM_W(-0X5D28, ctx->r2);
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // lw          $v1, -0x2118($v1)
    ctx->r3 = MEM_W(-0X2118, ctx->r3);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D24($at)
    MEM_W(-0X5D24, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_80050A7C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80050A7C;
    }
    // nop

    // jalr        $v1
    // nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80050A7C:
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $zero, 0x134($at)
    MEM_W(0X134, ctx->r1) = 0;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
