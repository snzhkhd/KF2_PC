#include "recomp.h"
#include "disable_warnings.h"

void sub_8002E394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A6C($v0)
    ctx->r2 = MEM_W(-0X2A6C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8002E3F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002E3F0;
    }
    // nop

    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A64
    ctx->r5 = ADD32(ctx->r5, -0X4A64);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x2A5C
    ctx->r4 = ADD32(ctx->r4, -0X2A5C);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(0XC, ctx->r5);
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // ori         $v0, $zero, 0x320
    ctx->r2 = 0 | 0X320;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0x2A4C($at)
    MEM_H(-0X2A4C, ctx->r1) = ctx->r2;
    // j           L_8002E4E0
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    goto L_8002E4E0;
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
L_8002E3F0:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A68($a0)
    ctx->r4 = MEM_W(-0X2A68, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_8002E460
    if (ctx->r4 == ctx->r2) {
        // sll         $v0, $a0, 5
        ctx->r2 = S32(ctx->r4) << 5;
        goto L_8002E460;
    }
    // sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4) << 5;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, -0x19F8
    ctx->r3 = ADD32(ctx->r3, -0X19F8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // addiu       $a2, $a2, -0x2A5C
    ctx->r6 = ADD32(ctx->r6, -0X2A5C);
    // lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(0X2C, ctx->r2);
    // lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(0X30, ctx->r2);
    // lw          $a1, 0x34($v0)
    ctx->r5 = MEM_W(0X34, ctx->r2);
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // sw          $a1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r5;
    // lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(0X38, ctx->r2);
    // nop

    // sw          $v1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r3;
    // lhu         $v1, 0x1C($v0)
    ctx->r3 = MEM_HU(0X1C, ctx->r2);
    // nop

    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v1, -0x2A4C($at)
    MEM_H(-0X2A4C, ctx->r1) = ctx->r3;
    // lhu         $v0, 0x1E($v0)
    ctx->r2 = MEM_HU(0X1E, ctx->r2);
    // j           L_8002E4E0
    // nop

    goto L_8002E4E0;
    // nop

L_8002E460:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A64($v1)
    ctx->r3 = MEM_W(-0X2A64, ctx->r3);
    // nop

    // beq         $v1, $a0, L_8002E4EC
    if (ctx->r3 == ctx->r4) {
        // sll         $v0, $v1, 4
        ctx->r2 = S32(ctx->r3) << 4;
        goto L_8002E4EC;
    }
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(0X6, ctx->r2);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, -0x2A5C
    ctx->r8 = ADD32(ctx->r8, -0X2A5C);
    // lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(0X14, ctx->r2);
    // lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(0X18, ctx->r2);
    // lw          $a3, 0x1C($v0)
    ctx->r7 = MEM_W(0X1C, ctx->r2);
    // sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(0X20, ctx->r2);
    // nop

    // sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // addiu       $v1, $v1, -0x1E00
    ctx->r3 = ADD32(ctx->r3, -0X1E00);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // nop

    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v1, -0x2A4C($at)
    MEM_H(-0X2A4C, ctx->r1) = ctx->r3;
    // lhu         $v0, 0x8($v0)
    ctx->r2 = MEM_HU(0X8, ctx->r2);
L_8002E4E0:
    // nop

    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0x2A4A($at)
    MEM_H(-0X2A4A, ctx->r1) = ctx->r2;
L_8002E4EC:
    // jr          $ra
    // nop

    return;
    // nop

;}
