#include "recomp.h"
#include "disable_warnings.h"

void sub_80016580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x1280
    ctx->r8 = ADD32(ctx->r8, -0X1280);
    // ori         $t1, $zero, 0x7F
    ctx->r9 = 0 | 0X7F;
    // ori         $t4, $zero, 0xFF
    ctx->r12 = 0 | 0XFF;
    // ori         $t3, $zero, 0xC
    ctx->r11 = 0 | 0XC;
    // ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4A64
    ctx->r3 = ADD32(ctx->r3, -0X4A64);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $a3, $t0, 0x18
    ctx->r7 = ADD32(ctx->r8, 0X18);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r3;
L_800165D8:
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // nop

    // beq         $v0, $t4, L_80016620
    if (ctx->r2 == ctx->r12) {
        // addiu       $t0, $t0, 0x48
        ctx->r8 = ADD32(ctx->r8, 0X48);
        goto L_80016620;
    }
    // addiu       $t0, $t0, 0x48
    ctx->r8 = ADD32(ctx->r8, 0X48);
    // lbu         $v0, -0x10($a3)
    ctx->r2 = MEM_BU(-0X10, ctx->r7);
    // nop

    // andi        $v0, $v0, 0xC
    ctx->r2 = ctx->r2 & 0XC;
    // beq         $v0, $t3, L_80016620
    if (ctx->r2 == ctx->r11) {
        // nop
    
        goto L_80016620;
    }
    // nop

    // lw          $v0, -0x4($a3)
    ctx->r2 = MEM_W(-0X4, ctx->r7);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r2;
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_80016620:
    // addiu       $a3, $a3, 0x48
    ctx->r7 = ADD32(ctx->r7, 0X48);
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_800165D8
    if (ctx->r2 != 0) {
        // addu        $t1, $t1, $t2
        ctx->r9 = ADD32(ctx->r9, ctx->r10);
        goto L_800165D8;
    }
    // addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // ori         $t0, $zero, 0x18B
    ctx->r8 = 0 | 0X18B;
    // ori         $t2, $zero, 0xFF
    ctx->r10 = 0 | 0XFF;
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // addiu       $a3, $a3, -0x67F8
    ctx->r7 = ADD32(ctx->r7, -0X67F8);
L_80016648:
    // lhu         $v0, -0x12($a3)
    ctx->r2 = MEM_HU(-0X12, ctx->r7);
    // nop

    // beq         $v0, $t2, L_8001667C
    if (ctx->r2 == ctx->r10) {
        // nop
    
        goto L_8001667C;
    }
    // nop

    // lw          $v0, -0x4($a3)
    ctx->r2 = MEM_W(-0X4, ctx->r7);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r2;
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_8001667C:
    // addiu       $a3, $a3, 0x44
    ctx->r7 = ADD32(ctx->r7, 0X44);
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_80016648
    if (ctx->r2 != 0) {
        // addu        $t0, $t0, $t1
        ctx->r8 = ADD32(ctx->r8, ctx->r9);
        goto L_80016648;
    }
    // addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // addiu       $t0, $t0, -0x19F8
    ctx->r8 = ADD32(ctx->r8, -0X19F8);
    // ori         $t1, $zero, 0xC7
    ctx->r9 = 0 | 0XC7;
    // ori         $t3, $zero, 0xFF
    ctx->r11 = 0 | 0XFF;
    // ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // addiu       $a3, $t0, 0x30
    ctx->r7 = ADD32(ctx->r8, 0X30);
L_800166A8:
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // nop

    // beq         $v0, $t3, L_800166DC
    if (ctx->r2 == ctx->r11) {
        // addiu       $t0, $t0, 0x7C
        ctx->r8 = ADD32(ctx->r8, 0X7C);
        goto L_800166DC;
    }
    // addiu       $t0, $t0, 0x7C
    ctx->r8 = ADD32(ctx->r8, 0X7C);
    // lw          $v0, -0x4($a3)
    ctx->r2 = MEM_W(-0X4, ctx->r7);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r2;
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_800166DC:
    // addiu       $a3, $a3, 0x7C
    ctx->r7 = ADD32(ctx->r7, 0X7C);
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_800166A8
    if (ctx->r2 != 0) {
        // addu        $t1, $t1, $t2
        ctx->r9 = ADD32(ctx->r9, ctx->r10);
        goto L_800166A8;
    }
    // addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // jr          $ra
    // nop

    return;
    // nop

;}
