#include "recomp.h"
#include "disable_warnings.h"

void ProcessPlayerInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lhu         $v1, 0x62CC($v1)
    ctx->r3 = MEM_HU(0X62CC, ctx->r3);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lhu         $a0, 0x62D4($a0)
    ctx->r4 = MEM_HU(0X62D4, ctx->r4);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lhu         $a1, 0x62D8($a1)
    ctx->r5 = MEM_HU(0X62D8, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lbu         $a2, -0x4A9E($a2)
    ctx->r6 = MEM_BU(-0X4A9E, ctx->r6);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sh          $v0, 0x142($gp)
    MEM_H(0X142, ctx->r28) = ctx->r2;
    // sh          $v1, 0x13C($gp)
    MEM_H(0X13C, ctx->r28) = ctx->r3;
    // sh          $a0, 0x13E($gp)
    MEM_H(0X13E, ctx->r28) = ctx->r4;
    // sh          $a1, 0x140($gp)
    MEM_H(0X140, ctx->r28) = ctx->r5;
    // bne         $a2, $zero, L_8002B460
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8002B460;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49FA($v0)
    ctx->r2 = MEM_HU(-0X49FA, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62D8($v1)
    ctx->r3 = MEM_W(0X62D8, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B460
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B460;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002B460
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B460;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA6($v0)
    ctx->r2 = MEM_BU(-0X4AA6, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002B460
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B460;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4AA5($a0)
    ctx->r4 = MEM_BU(-0X4AA5, ctx->r4);
    // jal         0x80029C4C
    // nop

    TryCastMagic(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8002B460:
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x49FA
    ctx->r17 = ADD32(ctx->r17, -0X49FA);
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62DC($v1)
    ctx->r3 = MEM_W(0X62DC, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B530
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B530;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002B530
    if (ctx->r2 != 0) {
        // ori         $s0, $zero, 0xFF
        ctx->r16 = 0 | 0XFF;
        goto L_8002B530;
    }
    // ori         $s0, $zero, 0xFF
    ctx->r16 = 0 | 0XFF;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4AA4($a0)
    ctx->r4 = MEM_BU(-0X4AA4, ctx->r4);
    // nop

    // beq         $a0, $s0, L_8002B4B8
    if (ctx->r4 == ctx->r16) {
        // nop
    
        goto L_8002B4B8;
    }
    // nop

    // jal         0x80029C4C
    // nop

    TryCastMagic(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_8002B4B8:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4AA3($a0)
    ctx->r4 = MEM_BU(-0X4AA3, ctx->r4);
    // nop

    // beq         $a0, $s0, L_8002B530
    if (ctx->r4 == ctx->r16) {
        // nop
    
        goto L_8002B530;
    }
    // nop

    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_8002B528
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B528;
    }
    // nop

    // jal         0x8002B39C
    // nop

    IsConsumable(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // beq         $v0, $zero, L_8002B510
    if (ctx->r2 == 0) {
        // addiu       $a0, $s1, -0x6A
        ctx->r4 = ADD32(ctx->r17, -0X6A);
        goto L_8002B510;
    }
    // addiu       $a0, $s1, -0x6A
    ctx->r4 = ADD32(ctx->r17, -0X6A);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4AA3($a0)
    ctx->r4 = MEM_BU(-0X4AA3, ctx->r4);
    // jal         0x8001A0BC
    // nop

    UseConsumableItem(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8002B530
    // nop

    goto L_8002B530;
    // nop

L_8002B510:
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lbu         $a2, -0x4AA3($a2)
    ctx->r6 = MEM_BU(-0X4AA3, ctx->r6);
    // jal         0x80049108
    // addiu       $a1, $s1, -0x4A
    ctx->r5 = ADD32(ctx->r17, -0X4A);
    UseItems_80049108(rdram, ctx);
    goto after_4;
    // addiu       $a1, $s1, -0x4A
    ctx->r5 = ADD32(ctx->r17, -0X4A);
    after_4:
    // j           L_8002B530
    // nop

    goto L_8002B530;
    // nop

L_8002B528:
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    MessageQueuePush(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    after_5:
L_8002B530:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A6B
    ctx->r16 = ADD32(ctx->r16, -0X4A6B);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8002B5B8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002B5B8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A68($v0)
    ctx->r2 = MEM_BU(-0X4A68, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A68($at)
    MEM_B(-0X4A68, ctx->r1) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_8002B5B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B5B8;
    }
    // nop

    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // jal         0x80028498
    // nop

    SpawnMagicProjectile(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A6A($v0)
    ctx->r2 = MEM_BU(-0X4A6A, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6A($at)
    MEM_B(-0X4A6A, ctx->r1) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_8002B5A4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8002B5A4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_8002B5B8
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    goto L_8002B5B8;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8002B5A4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A69($v0)
    ctx->r2 = MEM_BU(-0X4A69, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A68($at)
    MEM_B(-0X4A68, ctx->r1) = ctx->r2;
L_8002B5B8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49FA($v0)
    ctx->r2 = MEM_HU(-0X49FA, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62CC($v1)
    ctx->r3 = MEM_W(0X62CC, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B6CC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B6CC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B6CC
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x32
        ctx->r2 = 0 | 0X32;
        goto L_8002B6CC;
    }
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A78($v1)
    ctx->r3 = MEM_BU(-0X4A78, ctx->r3);
    // nop

    // beq         $v1, $v0, L_8002B6CC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002B6CC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4B2F($v0)
    ctx->r2 = MEM_BU(-0X4B2F, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002B624
    if (ctx->r2 == 0) {
        // ori         $v1, $zero, 0xFE0C
        ctx->r3 = 0 | 0XFE0C;
        goto L_8002B624;
    }
    // ori         $v1, $zero, 0xFE0C
    ctx->r3 = 0 | 0XFE0C;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B2F($at)
    MEM_B(-0X4B2F, ctx->r1) = ctx->r2;
L_8002B624:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B31($at)
    MEM_B(-0X4B31, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B22($v0)
    ctx->r2 = MEM_HU(-0X4B22, ctx->r2);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8002B664
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0x28
        ctx->r2 = 0 | 0X28;
        goto L_8002B664;
    }
    // ori         $v0, $zero, 0x28
    ctx->r2 = 0 | 0X28;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B31($at)
    MEM_B(-0X4B31, ctx->r1) = ctx->r2;
L_8002B664:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B1E($v0)
    ctx->r2 = MEM_HU(-0X4B1E, ctx->r2);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B1E($at)
    MEM_H(-0X4B1E, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8002B690
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8002B690;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B1E($at)
    MEM_H(-0X4B1E, ctx->r1) = 0;
L_8002B690:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2C($v0)
    ctx->r2 = MEM_HU(-0X4B2C, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2C($at)
    MEM_H(-0X4B2C, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x400
    ctx->r2 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // beq         $v0, $zero, L_8002B95C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x400
        ctx->r2 = 0 | 0X400;
        goto L_8002B95C;
    }
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2C($at)
    MEM_H(-0X4B2C, ctx->r1) = ctx->r2;
    // j           L_8002B95C
    // nop

    goto L_8002B95C;
    // nop

L_8002B6CC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4AC0($v0)
    ctx->r2 = MEM_W(-0X4AC0, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002B710
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B710;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B12($a0)
    ctx->r4 = MEM_HU(-0X4B12, ctx->r4);
    // jal         0x800262C0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_800262C0(rdram, ctx);
    goto after_7;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B1E($v1)
    ctx->r3 = MEM_HU(-0X4B1E, ctx->r3);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v1, -0x4B1E($at)
    MEM_H(-0X4B1E, ctx->r1) = ctx->r3;
    // j           L_8002B758
    // nop

    goto L_8002B758;
    // nop

L_8002B710:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B12($a0)
    ctx->r4 = MEM_HU(-0X4B12, ctx->r4);
    // lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(0X1, ctx->r2);
    // jal         0x800262C0
    // nop

    sub_800262C0(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A7C($v1)
    ctx->r3 = MEM_BU(-0X4A7C, ctx->r3);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // bne         $v1, $v0, L_8002B740
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002B740;
    }
    // nop

    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
L_8002B740:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B1E($v0)
    ctx->r2 = MEM_HU(-0X4B1E, ctx->r2);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B1E($at)
    MEM_H(-0X4B1E, ctx->r1) = ctx->r2;
L_8002B758:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B1E
    ctx->r3 = ADD32(ctx->r3, -0X4B1E);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1389
    ctx->r2 = ctx->r2 < 0X1389 ? 1 : 0;
    // bne         $v0, $zero, L_8002B778
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1388
        ctx->r2 = 0 | 0X1388;
        goto L_8002B778;
    }
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8002B778:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B2C($v0)
    ctx->r2 = MEM_HU(-0X4B2C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2C($at)
    MEM_H(-0X4B2C, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x1001
    ctx->r2 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
    // bne         $v0, $zero, L_8002B7AC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1000
        ctx->r2 = 0 | 0X1000;
        goto L_8002B7AC;
    }
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B2C($at)
    MEM_H(-0X4B2C, ctx->r1) = ctx->r2;
L_8002B7AC:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA6($v1)
    ctx->r3 = MEM_BU(-0X4AA6, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B2F($at)
    MEM_B(-0X4B2F, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_8002B7D8
    if (ctx->r3 == 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8002B7D8;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA6($at)
    MEM_B(-0X4AA6, ctx->r1) = ctx->r2;
    // j           L_8002B7E8
    // nop

    goto L_8002B7E8;
    // nop

L_8002B7D8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x63FC
    ctx->r2 = ADD32(ctx->r2, 0X63FC);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4AC4($at)
    MEM_W(-0X4AC4, ctx->r1) = ctx->r2;
L_8002B7E8:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x49FA
    ctx->r16 = ADD32(ctx->r16, -0X49FA);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62CC($v1)
    ctx->r3 = MEM_W(0X62CC, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D4($v0)
    ctx->r2 = MEM_W(0X62D4, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x62D8($a0)
    ctx->r4 = MEM_W(0X62D8, ctx->r4);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B8F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B8F4;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002B8F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B8F4;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4ABC($v0)
    ctx->r2 = MEM_W(-0X4ABC, ctx->r2);
    // nop

    // lhu         $v0, 0x24($v0)
    ctx->r2 = MEM_HU(0X24, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002B8F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B8F4;
    }
    // nop

    // jal         0x80028E8C
    // nop

    sub_80028E8C(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // beq         $v0, $zero, L_8002B8EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B8EC;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4AC4($a0)
    ctx->r4 = MEM_W(-0X4AC4, ctx->r4);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B8EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B8EC;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x63FC
    ctx->r2 = ADD32(ctx->r2, 0X63FC);
    // bne         $a0, $v0, L_8002B8BC
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $a0, 0x2
        ctx->r2 = ADD32(ctx->r4, 0X2);
        goto L_8002B8BC;
    }
    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B22($v1)
    ctx->r3 = MEM_HU(-0X4B22, ctx->r3);
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // bne         $v1, $v0, L_8002B8EC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002B8EC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B1E($v0)
    ctx->r2 = MEM_HU(-0X4B1E, ctx->r2);
    // nop

    // bne         $v0, $v1, L_8002B8EC
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $a0, 0x2
        ctx->r2 = ADD32(ctx->r4, 0X2);
        goto L_8002B8EC;
    }
    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
L_8002B8BC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4AC4($at)
    MEM_W(-0X4AC4, ctx->r1) = ctx->r2;
    // lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(0X2, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_8002B8DC
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x14
        ctx->r2 = 0 | 0X14;
        goto L_8002B8DC;
    }
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // j           L_8002B954
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    goto L_8002B954;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_8002B8DC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA6($at)
    MEM_B(-0X4AA6, ctx->r1) = ctx->r2;
    // j           L_8002B8F4
    // nop

    goto L_8002B8F4;
    // nop

L_8002B8EC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4AA6($at)
    MEM_B(-0X4AA6, ctx->r1) = 0;
L_8002B8F4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4B31($v0)
    ctx->r2 = MEM_BU(-0X4B31, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002B95C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B95C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA6($v0)
    ctx->r2 = MEM_BU(-0X4AA6, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002B95C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002B95C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49FA($v0)
    ctx->r2 = MEM_HU(-0X49FA, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62D4($v1)
    ctx->r3 = MEM_W(0X62D4, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002B95C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B95C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002B95C
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8002B95C;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8002B954:
    // jal         0x800281CC
    // nop

    MeleeAttack_800281CC(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_8002B95C:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
