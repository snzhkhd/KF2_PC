#include "recomp.h"
#include "disable_warnings.h"

void DrawDebugNumbers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A64($a2)
    ctx->r6 = MEM_W(-0X4A64, ctx->r6);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4A5C($a3)
    ctx->r7 = MEM_W(-0X4A5C, ctx->r7);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79DD($v1)
    ctx->r3 = MEM_BU(0X79DD, ctx->r3);
    // ori         $v0, $zero, 0xFC
    ctx->r2 = 0 | 0XFC;
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xCD
    ctx->r2 = 0 | 0XCD;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sra         $a2, $a2, 11
    ctx->r6 = S32(ctx->r6) >> 11;
    // sra         $a3, $a3, 11
    ctx->r7 = S32(ctx->r7) >> 11;
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) << 6;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A14($v1)
    ctx->r3 = MEM_HU(-0X4A14, ctx->r3);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // jal         0x80024B24
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    FormatHUDNumber(rdram, ctx);
    goto after_0;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AA8
    ctx->r4 = ADD32(ctx->r4, 0X7AA8);
    // jal         0x80023FD4
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    DrawHUDNumberString(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
