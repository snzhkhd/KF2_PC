#include "recomp.h"
#include "disable_warnings.h"

void Entity_SetContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // beq         $a1, $zero, L_8003D7F4
    if (ctx->r5 == 0) {
        // nop
    
        goto L_8003D7F4;
    }
    // nop

    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x79B4
    ctx->r4 = ADD32(ctx->r4, 0X79B4);
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // addiu       $a0, $a0, -0x32CC
    ctx->r4 = ADD32(ctx->r4, -0X32CC);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, 0x79B0($at)
    MEM_W(0X79B0, ctx->r1) = ctx->r2;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v1, 0x79C4($at)
    MEM_W(0X79C4, ctx->r1) = ctx->r3;
    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8003D81C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003D81C;
    }
    // nop

    // lh          $v1, 0x22($a1)
    ctx->r3 = MEM_H(0X22, ctx->r5);
    // nop

    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, 0x79BC($at)
    MEM_W(0X79BC, ctx->r1) = ctx->r2;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->r2;
    // j           L_8003D81C
    // nop

    goto L_8003D81C;
    // nop

L_8003D7F4:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79B4($at)
    MEM_W(0X79B4, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79B0($at)
    MEM_W(0X79B0, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79C4($at)
    MEM_W(0X79C4, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79BC($at)
    MEM_W(0X79BC, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = 0;
L_8003D81C:
    // jr          $ra
    // nop

    return;
    // nop

;}
