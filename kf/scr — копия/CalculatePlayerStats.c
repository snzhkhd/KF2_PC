#include "recomp.h"
#include "disable_warnings.h"

void CalculatePlayerStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B18($v0)
    ctx->r2 = MEM_HU(-0X4B18, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B16($v1)
    ctx->r3 = MEM_HU(-0X4B16, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4AE6($a0)
    ctx->r4 = MEM_H(-0X4AE6, ctx->r4);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B0C($at)
    MEM_H(-0X4B0C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B0A($at)
    MEM_H(-0X4B0A, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B08($at)
    MEM_H(-0X4B08, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B06($at)
    MEM_H(-0X4B06, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B04($at)
    MEM_H(-0X4B04, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B02($at)
    MEM_H(-0X4B02, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B00($at)
    MEM_H(-0X4B00, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AFE($at)
    MEM_H(-0X4AFE, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AFA($at)
    MEM_H(-0X4AFA, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AF8($at)
    MEM_H(-0X4AF8, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AF6($at)
    MEM_H(-0X4AF6, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AF4($at)
    MEM_H(-0X4AF4, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AF2($at)
    MEM_H(-0X4AF2, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AF0($at)
    MEM_H(-0X4AF0, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AEE($at)
    MEM_H(-0X4AEE, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AEC($at)
    MEM_H(-0X4AEC, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AEA($at)
    MEM_H(-0X4AEA, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B14($at)
    MEM_H(-0X4B14, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B12($at)
    MEM_H(-0X4B12, ctx->r1) = ctx->r3;
    // beq         $a0, $zero, L_80026518
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80026518;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B14($v0)
    ctx->r2 = MEM_HU(-0X4B14, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // bgez        $v0, L_80026510
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80026510;
    }
    // nop

    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80026510:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B14($at)
    MEM_H(-0X4B14, ctx->r1) = ctx->r2;
L_80026518:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4AA1
    ctx->r16 = ADD32(ctx->r16, -0X4AA1);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80026624
    if (ctx->r3 == ctx->r2) {
        // sll         $a0, $v1, 4
        ctx->r4 = S32(ctx->r3) << 4;
        goto L_80026624;
    }
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x4754
    ctx->r2 = ADD32(ctx->r2, -0X4754);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B0C($v0)
    ctx->r2 = MEM_HU(-0X4B0C, ctx->r2);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B0C($at)
    MEM_H(-0X4B0C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B0A($v0)
    ctx->r2 = MEM_HU(-0X4B0A, ctx->r2);
    // lhu         $v1, 0x8($a0)
    ctx->r3 = MEM_HU(0X8, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B0A($at)
    MEM_H(-0X4B0A, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B08($v0)
    ctx->r2 = MEM_HU(-0X4B08, ctx->r2);
    // lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(0XA, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B08($at)
    MEM_H(-0X4B08, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B06($v0)
    ctx->r2 = MEM_HU(-0X4B06, ctx->r2);
    // lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(0XC, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B06($at)
    MEM_H(-0X4B06, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B04($v0)
    ctx->r2 = MEM_HU(-0X4B04, ctx->r2);
    // lhu         $v1, 0xE($a0)
    ctx->r3 = MEM_HU(0XE, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B04($at)
    MEM_H(-0X4B04, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B02($v0)
    ctx->r2 = MEM_HU(-0X4B02, ctx->r2);
    // lhu         $v1, 0x10($a0)
    ctx->r3 = MEM_HU(0X10, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B02($at)
    MEM_H(-0X4B02, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B00($v0)
    ctx->r2 = MEM_HU(-0X4B00, ctx->r2);
    // lhu         $v1, 0x12($a0)
    ctx->r3 = MEM_HU(0X12, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B00($at)
    MEM_H(-0X4B00, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AFE($v0)
    ctx->r2 = MEM_HU(-0X4AFE, ctx->r2);
    // lhu         $v1, 0x14($a0)
    ctx->r3 = MEM_HU(0X14, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AFE($at)
    MEM_H(-0X4AFE, ctx->r1) = ctx->r2;
L_80026624:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A7C($a0)
    ctx->r4 = MEM_BU(-0X4A7C, ctx->r4);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A7B($a0)
    ctx->r4 = MEM_BU(-0X4A7B, ctx->r4);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A7A($a0)
    ctx->r4 = MEM_BU(-0X4A7A, ctx->r4);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A79($a0)
    ctx->r4 = MEM_BU(-0X4A79, ctx->r4);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A78($a0)
    ctx->r4 = MEM_BU(-0X4A78, ctx->r4);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lbu         $a0, 0x2A($s0)
    ctx->r4 = MEM_BU(0X2A, ctx->r16);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lbu         $a0, 0x2B($s0)
    ctx->r4 = MEM_BU(0X2B, ctx->r16);
    // jal         0x80026314
    // nop

    sub_80026314(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADA($v0)
    ctx->r2 = MEM_H(-0X4ADA, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800266B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800266B8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF0($v0)
    ctx->r2 = MEM_HU(-0X4AF0, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x32
    ctx->r2 = ADD32(ctx->r2, 0X32);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF0($at)
    MEM_H(-0X4AF0, ctx->r1) = ctx->r2;
L_800266B8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AD8($v0)
    ctx->r2 = MEM_H(-0X4AD8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80026708
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026708;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF8($v0)
    ctx->r2 = MEM_HU(-0X4AF8, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AF6($v1)
    ctx->r3 = MEM_HU(-0X4AF6, ctx->r3);
    // addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF8($at)
    MEM_H(-0X4AF8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AFA($v0)
    ctx->r2 = MEM_HU(-0X4AFA, ctx->r2);
    // addiu       $v1, $v1, 0x1E
    ctx->r3 = ADD32(ctx->r3, 0X1E);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AF6($at)
    MEM_H(-0X4AF6, ctx->r1) = ctx->r3;
    // addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AFA($at)
    MEM_H(-0X4AFA, ctx->r1) = ctx->r2;
L_80026708:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ACE($v0)
    ctx->r2 = MEM_H(-0X4ACE, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80026734
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026734;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B12($v0)
    ctx->r2 = MEM_HU(-0X4B12, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B12($at)
    MEM_H(-0X4B12, ctx->r1) = ctx->r2;
L_80026734:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // bne         $v1, $v0, L_80026778
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xB
        ctx->r2 = 0 | 0XB;
        goto L_80026778;
    }
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
    // ori         $v0, $zero, 0xFFF6
    ctx->r2 = 0 | 0XFFF6;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AF8($v1)
    ctx->r3 = MEM_HU(-0X4AF8, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4AF6($a0)
    ctx->r4 = MEM_HU(-0X4AF6, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AF8($at)
    MEM_H(-0X4AF8, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4AF6($at)
    MEM_H(-0X4AF6, ctx->r1) = ctx->r4;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
L_80026778:
    // bne         $v1, $v0, L_800267D0
    if (ctx->r3 != ctx->r2) {
        // ori         $a0, $zero, 0xFFF6
        ctx->r4 = 0 | 0XFFF6;
        goto L_800267D0;
    }
    // ori         $a0, $zero, 0xFFF6
    ctx->r4 = 0 | 0XFFF6;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF2($v0)
    ctx->r2 = MEM_HU(-0X4AF2, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AF0($v1)
    ctx->r3 = MEM_HU(-0X4AF0, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AF2($at)
    MEM_H(-0X4AF2, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AEC($v0)
    ctx->r2 = MEM_HU(-0X4AEC, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AF0($at)
    MEM_H(-0X4AF0, ctx->r1) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AEA($v1)
    ctx->r3 = MEM_HU(-0X4AEA, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AEC($at)
    MEM_H(-0X4AEC, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AEA($at)
    MEM_H(-0X4AEA, ctx->r1) = ctx->r3;
L_800267D0:
    // lbu         $v0, 0x2A($s0)
    ctx->r2 = MEM_BU(0X2A, ctx->r16);
    // ori         $v1, $zero, 0x37
    ctx->r3 = 0 | 0X37;
    // beq         $v0, $v1, L_800267F0
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800267F0;
    }
    // nop

    // lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(0X2B, ctx->r16);
    // nop

    // bne         $v0, $v1, L_80026840
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80026840;
    }
    // nop

L_800267F0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B0A($v0)
    ctx->r2 = MEM_HU(-0X4B0A, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B08($v1)
    ctx->r3 = MEM_HU(-0X4B08, ctx->r3);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B0A($at)
    MEM_H(-0X4B0A, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B06($v0)
    ctx->r2 = MEM_HU(-0X4B06, ctx->r2);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B08($at)
    MEM_H(-0X4B08, ctx->r1) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AFE($v1)
    ctx->r3 = MEM_HU(-0X4AFE, ctx->r3);
    // addiu       $v0, $v0, 0x16
    ctx->r2 = ADD32(ctx->r2, 0X16);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B06($at)
    MEM_H(-0X4B06, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4AFE($at)
    MEM_H(-0X4AFE, ctx->r1) = ctx->r3;
L_80026840:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x38
    ctx->r3 = 0 | 0X38;
    // beq         $v0, $v1, L_80026868
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80026868;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_80026880
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80026880;
    }
    // nop

L_80026868:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B12($v0)
    ctx->r2 = MEM_HU(-0X4B12, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B12($at)
    MEM_H(-0X4B12, ctx->r1) = ctx->r2;
L_80026880:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x39
    ctx->r3 = 0 | 0X39;
    // beq         $v0, $v1, L_800268A8
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800268A8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_800268C0
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800268C0;
    }
    // nop

L_800268A8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B14($v0)
    ctx->r2 = MEM_HU(-0X4B14, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B14($at)
    MEM_H(-0X4B14, ctx->r1) = ctx->r2;
L_800268C0:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B14
    ctx->r4 = ADD32(ctx->r4, -0X4B14);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // ori         $v0, $zero, 0x7FFF
    ctx->r2 = 0 | 0X7FFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800268E4
    if (ctx->r2 == 0) {
        // sltiu       $v0, $v1, 0x3E8
        ctx->r2 = ctx->r3 < 0X3E8 ? 1 : 0;
        goto L_800268E4;
    }
    // sltiu       $v0, $v1, 0x3E8
    ctx->r2 = ctx->r3 < 0X3E8 ? 1 : 0;
    // j           L_800268F0
    // sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    goto L_800268F0;
    // sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_800268E4:
    // bne         $v0, $zero, L_800268F0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x3E7
        ctx->r2 = 0 | 0X3E7;
        goto L_800268F0;
    }
    // ori         $v0, $zero, 0x3E7
    ctx->r2 = 0 | 0X3E7;
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_800268F0:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B12
    ctx->r4 = ADD32(ctx->r4, -0X4B12);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // ori         $v0, $zero, 0x7FFF
    ctx->r2 = 0 | 0X7FFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80026914
    if (ctx->r2 == 0) {
        // sltiu       $v0, $v1, 0x3E8
        ctx->r2 = ctx->r3 < 0X3E8 ? 1 : 0;
        goto L_80026914;
    }
    // sltiu       $v0, $v1, 0x3E8
    ctx->r2 = ctx->r3 < 0X3E8 ? 1 : 0;
    // j           L_80026920
    // sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    goto L_80026920;
    // sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_80026914:
    // bne         $v0, $zero, L_80026920
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x3E7
        ctx->r2 = 0 | 0X3E7;
        goto L_80026920;
    }
    // ori         $v0, $zero, 0x3E7
    ctx->r2 = 0 | 0X3E7;
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80026920:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B0C
    ctx->r3 = ADD32(ctx->r3, -0X4B0C);
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_80026940
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026940;
    }
    // nop

    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_80026940:
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_80026958
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026958;
    }
    // nop

    // sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
L_80026958:
    // lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(0X5, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_80026970
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026970;
    }
    // nop

    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_80026970:
    // lbu         $v0, 0x7($v1)
    ctx->r2 = MEM_BU(0X7, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_80026988
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026988;
    }
    // nop

    // sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
L_80026988:
    // lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(0X9, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_800269A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800269A0;
    }
    // nop

    // sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_800269A0:
    // lbu         $v0, 0xB($v1)
    ctx->r2 = MEM_BU(0XB, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_800269B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800269B8;
    }
    // nop

    // sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
L_800269B8:
    // lbu         $v0, 0xD($v1)
    ctx->r2 = MEM_BU(0XD, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // beq         $v0, $zero, L_800269D0
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x7FFF
        ctx->r4 = 0 | 0X7FFF;
        goto L_800269D0;
    }
    // ori         $a0, $zero, 0x7FFF
    ctx->r4 = 0 | 0X7FFF;
    // sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
L_800269D0:
    // lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(0XE, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_800269E8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800269E8;
    }
    // nop

    // sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
L_800269E8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AFA($v0)
    ctx->r2 = MEM_HU(-0X4AFA, ctx->r2);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026A08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026A08;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AFA($at)
    MEM_H(-0X4AFA, ctx->r1) = 0;
L_80026A08:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AF8($v0)
    ctx->r2 = MEM_HU(-0X4AF8, ctx->r2);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026A28
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026A28;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AF8($at)
    MEM_H(-0X4AF8, ctx->r1) = 0;
L_80026A28:
    // lhu         $v0, 0x16($v1)
    ctx->r2 = MEM_HU(0X16, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026A40
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026A40;
    }
    // nop

    // sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
L_80026A40:
    // lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(0X18, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026A58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026A58;
    }
    // nop

    // sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_80026A58:
    // lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(0X1A, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026A70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026A70;
    }
    // nop

    // sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
L_80026A70:
    // lhu         $v0, 0x1C($v1)
    ctx->r2 = MEM_HU(0X1C, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026A88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026A88;
    }
    // nop

    // sh          $zero, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = 0;
L_80026A88:
    // lhu         $v0, 0x1E($v1)
    ctx->r2 = MEM_HU(0X1E, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026AA0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026AA0;
    }
    // nop

    // sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
L_80026AA0:
    // lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(0X20, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026AB8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026AB8;
    }
    // nop

    // sh          $zero, 0x20($v1)
    MEM_H(0X20, ctx->r3) = 0;
L_80026AB8:
    // lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(0X22, ctx->r3);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80026AD0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026AD0;
    }
    // nop

    // sh          $zero, 0x22($v1)
    MEM_H(0X22, ctx->r3) = 0;
L_80026AD0:
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
