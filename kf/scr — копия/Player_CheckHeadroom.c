#include "recomp.h"
#include "disable_warnings.h"

void Player_CheckHeadroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A74($v0)
    ctx->r2 = MEM_W(-0X2A74, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A08($v1)
    ctx->r3 = MEM_H(-0X4A08, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A04($a1)
    ctx->r5 = MEM_H(-0X4A04, ctx->r5);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, 0X640);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A1C($at)
    MEM_W(-0X4A1C, ctx->r1) = ctx->r2;
    // slti        $v0, $v0, -0x3E8
    ctx->r2 = SIGNED(ctx->r2) < -0X3E8 ? 1 : 0;
    // beq         $v0, $zero, L_80025E84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80025E84;
    }
    // nop

    // jal         0x8002C06C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002C06C(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
L_80025E84:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A70($v1)
    ctx->r3 = MEM_W(-0X2A70, ctx->r3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A08($v0)
    ctx->r2 = MEM_H(-0X4A08, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A04($a1)
    ctx->r5 = MEM_H(-0X4A04, ctx->r5);
    // addiu       $v1, $v1, 0x640
    ctx->r3 = ADD32(ctx->r3, 0X640);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x4A18($at)
    MEM_W(-0X4A18, ctx->r1) = ctx->r3;
    // bgtz        $v1, L_80025ECC
    if (SIGNED(ctx->r3) > 0) {
        // nop
    
        goto L_80025ECC;
    }
    // nop

    // jal         0x8002C06C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002C06C(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
L_80025ECC:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
