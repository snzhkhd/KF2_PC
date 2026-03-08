#include "recomp.h"
#include "disable_warnings.h"

void sub_80026314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_80026428
    if (ctx->r4 == ctx->r2) {
        // sll         $a0, $a0, 5
        ctx->r4 = S32(ctx->r4) << 5;
        goto L_80026428;
    }
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2CE8
    ctx->r2 = ADD32(ctx->r2, -0X2CE8);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4AFA
    ctx->r5 = ADD32(ctx->r5, -0X4AFA);
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(0X2, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF8($v0)
    ctx->r2 = MEM_HU(-0X4AF8, ctx->r2);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF8($at)
    MEM_H(-0X4AF8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF6($v0)
    ctx->r2 = MEM_HU(-0X4AF6, ctx->r2);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF6($at)
    MEM_H(-0X4AF6, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF4($v0)
    ctx->r2 = MEM_HU(-0X4AF4, ctx->r2);
    // lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(0X8, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF4($at)
    MEM_H(-0X4AF4, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF2($v0)
    ctx->r2 = MEM_HU(-0X4AF2, ctx->r2);
    // lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(0XA, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF2($at)
    MEM_H(-0X4AF2, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF0($v0)
    ctx->r2 = MEM_HU(-0X4AF0, ctx->r2);
    // lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(0XC, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF0($at)
    MEM_H(-0X4AF0, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AEE($v0)
    ctx->r2 = MEM_HU(-0X4AEE, ctx->r2);
    // lhu         $v1, 0xE($a0)
    ctx->r3 = MEM_HU(0XE, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AEE($at)
    MEM_H(-0X4AEE, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AEC($v0)
    ctx->r2 = MEM_HU(-0X4AEC, ctx->r2);
    // lhu         $v1, 0x10($a0)
    ctx->r3 = MEM_HU(0X10, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AEC($at)
    MEM_H(-0X4AEC, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AEA($v0)
    ctx->r2 = MEM_HU(-0X4AEA, ctx->r2);
    // lhu         $v1, 0x12($a0)
    ctx->r3 = MEM_HU(0X12, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AEA($at)
    MEM_H(-0X4AEA, ctx->r1) = ctx->r2;
L_80026428:
    // jr          $ra
    // nop

    return;
    // nop

;}
