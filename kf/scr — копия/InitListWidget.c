#include "recomp.h"
#include "disable_warnings.h"

void InitListWidget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addiu       $t1, $a3, 0x4
    ctx->r9 = ADD32(ctx->r7, 0X4);
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7B98
    ctx->r4 = ADD32(ctx->r4, 0X7B98);
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
L_80024A3C:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // slti        $v0, $t0, 0x18
    ctx->r2 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80024A3C
    if (ctx->r2 != 0) {
        // addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_80024A3C;
    }
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // ori         $v0, $zero, 0x2A
    ctx->r2 = 0 | 0X2A;
    // sb          $v0, 0x1C($a3)
    MEM_B(0X1C, ctx->r7) = ctx->r2;
    // ori         $v0, $zero, 0x9F
    ctx->r2 = 0 | 0X9F;
    // sb          $v0, 0x1D($a3)
    MEM_B(0X1D, ctx->r7) = ctx->r2;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sb          $v0, 0x1F($a3)
    MEM_B(0X1F, ctx->r7) = ctx->r2;
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // sb          $zero, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = 0;
    // sb          $zero, 0x20($a3)
    MEM_B(0X20, ctx->r7) = 0;
    // sb          $zero, 0x21($a3)
    MEM_B(0X21, ctx->r7) = 0;
    // sb          $zero, 0x22($a3)
    MEM_B(0X22, ctx->r7) = 0;
    // jr          $ra
    // sb          $v0, 0x23($a3)
    MEM_B(0X23, ctx->r7) = ctx->r2;
    return;
    // sb          $v0, 0x23($a3)
    MEM_B(0X23, ctx->r7) = ctx->r2;
;}
