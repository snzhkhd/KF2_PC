#include "recomp.h"
#include "disable_warnings.h"

void sub_8002A3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s2, $s2, -0x4A64
    ctx->r18 = ADD32(ctx->r18, -0X4A64);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(0X4, ctx->r18);
    // lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(0X8, ctx->r18);
    // ori         $s3, $zero, 0x6A4
    ctx->r19 = 0 | 0X6A4;
    // jal         0x8002E120
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    MAP_CollisionWithTile(rdram, ctx);
    goto after_0;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A6C($v1)
    ctx->r3 = MEM_BU(-0X4A6C, ctx->r3);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_8002A4CC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
        goto L_8002A4CC;
    }
    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_8002A454
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002A454;
    }
    // nop

    // beq         $v1, $zero, L_8002A778
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8002A778;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_8002A470
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002A470;
    }
    // nop

    // j           L_8002A8B4
    // nop

    goto L_8002A8B4;
    // nop

L_8002A454:
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // beq         $v1, $v0, L_8002A544
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x50
        ctx->r2 = 0 | 0X50;
        goto L_8002A544;
    }
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // beq         $v1, $v0, L_8002A6C0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002A6C0;
    }
    // nop

    // j           L_8002A8B4
    // nop

    goto L_8002A8B4;
    // nop

L_8002A470:
    // jal         0x8002A338
    // nop

    sub_8002A338(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A02($v0)
    ctx->r2 = MEM_H(-0X4A02, ctx->r2);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A7C($a0)
    ctx->r4 = MEM_W(-0X2A7C, ctx->r4);
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = ctx->r2;
    // addiu       $v0, $a0, 0x64
    ctx->r2 = ADD32(ctx->r4, 0X64);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002A8B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002A8B4;
    }
    // nop

    // sw          $a0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = 0;
    // j           L_8002A8B4
    // nop

    goto L_8002A8B4;
    // nop

L_8002A4CC:
    // jal         0x8002A338
    // nop

    sub_8002A338(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A02($a0)
    ctx->r4 = MEM_H(-0X4A02, ctx->r4);
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, -0x2A7C($a1)
    ctx->r5 = MEM_W(-0X2A7C, ctx->r5);
    // addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002A500
    if (ctx->r2 == 0) {
        // sw          $v1, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r3;
        goto L_8002A500;
    }
    // sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // bltz        $a0, L_8002A51C
    if (SIGNED(ctx->r4) < 0) {
        // nop
    
        goto L_8002A51C;
    }
    // nop

L_8002A500:
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002A514
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002A514;
    }
    // nop

    // sw          $a1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r5;
L_8002A514:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = 0;
L_8002A51C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A02($v0)
    ctx->r2 = MEM_HU(-0X4A02, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A52($at)
    MEM_H(-0X4A52, ctx->r1) = ctx->r2;
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = ctx->r2;
    // j           L_8002A8B4
    // nop

    goto L_8002A8B4;
    // nop

L_8002A544:
    // jal         0x8002A338
    // ori         $s4, $zero, 0x31
    ctx->r20 = 0 | 0X31;
    sub_8002A338(rdram, ctx);
    goto after_3;
    // ori         $s4, $zero, 0x31
    ctx->r20 = 0 | 0X31;
    after_3:
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(0X8, ctx->r18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A02($v1)
    ctx->r3 = MEM_H(-0X4A02, ctx->r3);
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // jal         0x8002E4F4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8002E4F4(rdram, ctx);
    goto after_4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // bne         $s1, $zero, L_8002A5B8
    if (ctx->r17 != 0) {
        // nop
    
        goto L_8002A5B8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A02($v0)
    ctx->r2 = MEM_HU(-0X4A02, ctx->r2);
    // sw          $s0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r16;
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A2C($at)
    MEM_H(-0X4A2C, ctx->r1) = ctx->r2;
    // j           L_8002A8B4
    // nop

    goto L_8002A8B4;
    // nop

L_8002A5B8:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A02($a0)
    ctx->r4 = MEM_H(-0X4A02, ctx->r4);
    // nop

    // bgez        $a0, L_8002A5DC
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_8002A5DC;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = 0;
    // j           L_8002A8B4
    // nop

    goto L_8002A8B4;
    // nop

L_8002A5DC:
    // jal         0x8002A398
    // nop

    sub_8002A398(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A02($v1)
    ctx->r3 = MEM_H(-0X4A02, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x1E0
    ctx->r2 = SIGNED(ctx->r3) < 0X1E0 ? 1 : 0;
    // bne         $v0, $zero, L_8002A648
    if (ctx->r2 != 0) {
        // andi        $v0, $s1, 0x4
        ctx->r2 = ctx->r17 & 0X4;
        goto L_8002A648;
    }
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x8E2E
    ctx->r3 = S32(0X8E2E << 16);
    // ori         $v1, $v1, 0x727
    ctx->r3 = ctx->r3 | 0X727;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // mfhi        $a1
    ctx->r5 = hi;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // jal         0x80026F34
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    sub_80026F34(rdram, ctx);
    goto after_6;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    after_6:
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
L_8002A648:
    // beq         $v0, $zero, L_8002A660
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002A660;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // j           L_8002A6A8
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    goto L_8002A6A8;
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_8002A660:
    // jal         0x8002E394
    // nop

    sub_8002E394(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(0X8, ctx->r18);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A4A($v1)
    ctx->r3 = MEM_HU(-0X2A4A, ctx->r3);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A58($v0)
    ctx->r2 = MEM_W(-0X2A58, ctx->r2);
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // jal         0x8002E4F4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8002E4F4(rdram, ctx);
    goto after_8;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // bne         $v0, $zero, L_8002A6AC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8002A6AC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $s0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r16;
L_8002A6A8:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8002A6AC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A04($at)
    MEM_H(-0X4A04, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = ctx->r2;
L_8002A6C0:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4A04
    ctx->r4 = ADD32(ctx->r4, -0X4A04);
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // nop

    // blez        $v0, L_8002A6F4
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002A6F4;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A02($v0)
    ctx->r2 = MEM_HU(-0X4A02, ctx->r2);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2) >> 18;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_8002A6F4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A02($v0)
    ctx->r2 = MEM_HU(-0X4A02, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A2C($v1)
    ctx->r3 = MEM_H(-0X4A2C, ctx->r3);
    // addiu       $v0, $v0, -0x64
    ctx->r2 = ADD32(ctx->r2, -0X64);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = ctx->r2;
    // blez        $v1, L_8002A730
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8002A730;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8002A728
    if (SIGNED(ctx->r2) > 0) {
        // addiu       $v0, $a0, 0xA
        ctx->r2 = ADD32(ctx->r4, 0XA);
        goto L_8002A728;
    }
    // addiu       $v0, $a0, 0xA
    ctx->r2 = ADD32(ctx->r4, 0XA);
    // addiu       $v0, $a0, -0x1E
    ctx->r2 = ADD32(ctx->r4, -0X1E);
L_8002A728:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A2C($at)
    MEM_H(-0X4A2C, ctx->r1) = ctx->r2;
L_8002A730:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4A04
    ctx->r3 = ADD32(ctx->r3, -0X4A04);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // bgtz        $v0, L_8002A778
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8002A778;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A2C($v0)
    ctx->r2 = MEM_H(-0X4A2C, ctx->r2);
    // nop

    // bgtz        $v0, L_8002A778
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8002A778;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = 0;
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A2C($at)
    MEM_H(-0X4A2C, ctx->r1) = 0;
L_8002A778:
    // lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // addiu       $s2, $s2, -0x2A7C
    ctx->r18 = ADD32(ctx->r18, -0X2A7C);
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4A60
    ctx->r17 = ADD32(ctx->r17, -0X4A60);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // nop

    // subu        $s0, $v1, $a1
    ctx->r16 = SUB32(ctx->r3, ctx->r5);
    // bgez        $s0, L_8002A7FC
    if (SIGNED(ctx->r16) >= 0) {
        // slti        $v0, $s0, -0x100
        ctx->r2 = SIGNED(ctx->r16) < -0X100 ? 1 : 0;
        goto L_8002A7FC;
    }
    // slti        $v0, $s0, -0x100
    ctx->r2 = SIGNED(ctx->r16) < -0X100 ? 1 : 0;
    // bne         $v0, $zero, L_8002A7C4
    if (ctx->r2 != 0) {
        // slti        $v0, $s0, -0x200
        ctx->r2 = SIGNED(ctx->r16) < -0X200 ? 1 : 0;
        goto L_8002A7C4;
    }
    // slti        $v0, $s0, -0x200
    ctx->r2 = SIGNED(ctx->r16) < -0X200 ? 1 : 0;
    // slti        $v0, $s0, -0x80
    ctx->r2 = SIGNED(ctx->r16) < -0X80 ? 1 : 0;
    // beq         $v0, $zero, L_8002A7BC
    if (ctx->r2 == 0) {
        // addiu       $v0, $a1, -0x80
        ctx->r2 = ADD32(ctx->r5, -0X80);
        goto L_8002A7BC;
    }
    // addiu       $v0, $a1, -0x80
    ctx->r2 = ADD32(ctx->r5, -0X80);
    // j           L_8002A8B4
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    goto L_8002A8B4;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8002A7BC:
    // j           L_8002A8B4
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    goto L_8002A8B4;
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
L_8002A7C4:
    // bne         $v0, $zero, L_8002A7D8
    if (ctx->r2 != 0) {
        // ori         $v1, $zero, 0x20
        ctx->r3 = 0 | 0X20;
        goto L_8002A7D8;
    }
    // ori         $v1, $zero, 0x20
    ctx->r3 = 0 | 0X20;
    // addiu       $v0, $a1, -0x100
    ctx->r2 = ADD32(ctx->r5, -0X100);
    // j           L_8002A8B4
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    goto L_8002A8B4;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8002A7D8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A0E($v0)
    ctx->r2 = MEM_H(-0X4A0E, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = ctx->r3;
    // slti        $v0, $v0, 0xC9
    ctx->r2 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // bne         $v0, $zero, L_8002A89C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x96
        ctx->r2 = ADD32(0, -0X96);
        goto L_8002A89C;
    }
    // addiu       $v0, $zero, -0x96
    ctx->r2 = ADD32(0, -0X96);
    // j           L_8002A89C
    // addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
    goto L_8002A89C;
    // addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
L_8002A7FC:
    // blez        $s0, L_8002A8B4
    if (SIGNED(ctx->r16) <= 0) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8002A8B4;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x4A5C($a2)
    ctx->r6 = MEM_W(-0X4A5C, ctx->r6);
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x31
    ctx->r2 = 0 | 0X31;
    // jal         0x8002E4F4
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8002E4F4(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_9:
    // bne         $v0, $zero, L_8002A8B4
    if (ctx->r2 != 0) {
        // slti        $v0, $s0, 0x101
        ctx->r2 = SIGNED(ctx->r16) < 0X101 ? 1 : 0;
        goto L_8002A8B4;
    }
    // slti        $v0, $s0, 0x101
    ctx->r2 = SIGNED(ctx->r16) < 0X101 ? 1 : 0;
    // beq         $v0, $zero, L_8002A864
    if (ctx->r2 == 0) {
        // slti        $v0, $s0, 0x81
        ctx->r2 = SIGNED(ctx->r16) < 0X81 ? 1 : 0;
        goto L_8002A864;
    }
    // slti        $v0, $s0, 0x81
    ctx->r2 = SIGNED(ctx->r16) < 0X81 ? 1 : 0;
    // bne         $v0, $zero, L_8002A858
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002A858;
    }
    // nop

    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // j           L_8002A8B4
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    goto L_8002A8B4;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8002A858:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // j           L_8002A8B4
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    goto L_8002A8B4;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8002A864:
    // slti        $v0, $s0, 0x201
    ctx->r2 = SIGNED(ctx->r16) < 0X201 ? 1 : 0;
    // beq         $v0, $zero, L_8002A884
    if (ctx->r2 == 0) {
        // slti        $v0, $s0, 0x401
        ctx->r2 = SIGNED(ctx->r16) < 0X401 ? 1 : 0;
        goto L_8002A884;
    }
    // slti        $v0, $s0, 0x401
    ctx->r2 = SIGNED(ctx->r16) < 0X401 ? 1 : 0;
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // j           L_8002A8B4
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    goto L_8002A8B4;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8002A884:
    // bne         $v0, $zero, L_8002A890
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_8002A890;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
L_8002A890:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A6C($at)
    MEM_B(-0X4A6C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x28
    ctx->r2 = 0 | 0X28;
L_8002A89C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A02($at)
    MEM_H(-0X4A02, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A04($at)
    MEM_H(-0X4A04, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A2C($at)
    MEM_H(-0X4A2C, ctx->r1) = 0;
L_8002A8B4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A6C($v0)
    ctx->r2 = MEM_BU(-0X4A6C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002A938
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002A938;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A70($v0)
    ctx->r2 = MEM_BU(-0X4A70, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002A930
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002A930;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4A06($a0)
    ctx->r4 = MEM_HU(-0X4A06, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A0E($v0)
    ctx->r2 = MEM_HU(-0X4A0E, ctx->r2);
    // nop

    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4A06($at)
    MEM_H(-0X4A06, ctx->r1) = ctx->r4;
    // jal         0x800601F4
    // nop

    FixedSin(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // sra         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) >> 5;
    // bgez        $v1, L_8002A91C
    if (SIGNED(ctx->r3) >= 0) {
        // sra         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) >> 2;
        goto L_8002A91C;
    }
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
L_8002A91C:
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A08($at)
    MEM_H(-0X4A08, ctx->r1) = ctx->r2;
    // j           L_8002A938
    // nop

    goto L_8002A938;
    // nop

L_8002A930:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A08($at)
    MEM_H(-0X4A08, ctx->r1) = 0;
L_8002A938:
    // jal         0x80025E30
    // nop

    Player_CheckHeadroom(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
