#include "recomp.h"
#include "disable_warnings.h"

void ProcessMeleeAttack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4AA1($a0)
    ctx->r4 = MEM_BU(-0X4AA1, ctx->r4);
    // addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // sw          $s2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // lw          $s2, -0x4ABC($s2)
    ctx->r18 = MEM_W(-0X4ABC, ctx->r18);
    // sw          $ra, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r31;
    // sw          $fp, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r30;
    // sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // sw          $s6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r22;
    // sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // sw          $s4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r20;
    // sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    // sw          $s1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r17;
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80029594
    if (ctx->r2 != 0) {
        // sw          $s0, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->r16;
        goto L_80029594;
    }
    // sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // slti        $v0, $a0, 0x12
    ctx->r2 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // bne         $v0, $zero, L_800290EC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800290EC;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_80029C18
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80029C18;
    }
    // nop

    // j           L_80029594
    // nop

    goto L_80029594;
    // nop

L_800290EC:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4AAC($a1)
    ctx->r5 = MEM_H(-0X4AAC, ctx->r5);
    // nop

    // beq         $a1, $v0, L_8002957C
    if (ctx->r5 == ctx->r2) {
        // addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
        goto L_8002957C;
    }
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA2($v1)
    ctx->r3 = MEM_BU(-0X4AA2, ctx->r3);
    // nop

    // beq         $v1, $zero, L_80029124
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80029124;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80029548
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $a3, 0x190
        ctx->r2 = ADD32(ctx->r7, 0X190);
        goto L_80029548;
    }
    // addiu       $v0, $a3, 0x190
    ctx->r2 = ADD32(ctx->r7, 0X190);
    // j           L_80029C18
    // nop

    goto L_80029C18;
    // nop

L_80029124:
    // bne         $a1, $zero, L_800291F8
    if (ctx->r5 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_800291F8;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $a0, $v0, L_80029144
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x11
        ctx->r2 = 0 | 0X11;
        goto L_80029144;
    }
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // beq         $a0, $v0, L_80029150
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80029150;
    }
    // nop

    // j           L_80029158
    // nop

    goto L_80029158;
    // nop

L_80029144:
    // ori         $a2, $zero, 0x1F
    ctx->r6 = 0 | 0X1F;
    // j           L_80029158
    // ori         $t0, $zero, 0x75
    ctx->r8 = 0 | 0X75;
    goto L_80029158;
    // ori         $t0, $zero, 0x75
    ctx->r8 = 0 | 0X75;
L_80029150:
    // ori         $a2, $zero, 0x1E
    ctx->r6 = 0 | 0X1E;
    // ori         $t0, $zero, 0x76
    ctx->r8 = 0 | 0X76;
L_80029158:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x3B
    ctx->r3 = 0 | 0X3B;
    // beq         $v0, $v1, L_80029180
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80029180;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_80029184
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80029184;
    }
    // nop

L_80029180:
    // addiu       $a2, $a2, 0x11
    ctx->r6 = ADD32(ctx->r6, 0X11);
L_80029184:
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_800291F0
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800291F0;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a1, $zero, 0x12
    ctx->r5 = 0 | 0X12;
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x4A64
    ctx->r7 = ADD32(ctx->r7, -0X4A64);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // addiu       $v0, $a3, 0x18
    ctx->r2 = ADD32(ctx->r7, 0X18);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80042D2C
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    SpawnParticleEntity(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $s3, -0x4AB0($at)
    MEM_W(-0X4AB0, ctx->r1) = ctx->r19;
    // beq         $s3, $zero, L_800291F8
    if (ctx->r19 == 0) {
        // ori         $v0, $zero, 0x63
        ctx->r2 = 0 | 0X63;
        goto L_800291F8;
    }
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // j           L_800291F8
    // sb          $v0, 0x7($s3)
    MEM_B(0X7, ctx->r19) = ctx->r2;
    goto L_800291F8;
    // sb          $v0, 0x7($s3)
    MEM_B(0X7, ctx->r19) = ctx->r2;
L_800291F0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4AB0($at)
    MEM_W(-0X4AB0, ctx->r1) = 0;
L_800291F8:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4AAC
    ctx->r4 = ADD32(ctx->r4, -0X4AAC);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // lhu         $v1, 0x1C($s2)
    ctx->r3 = MEM_HU(0X1C, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8002922C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFF
        ctx->r2 = 0 | 0XFFF;
        goto L_8002922C;
    }
    // ori         $v0, $zero, 0xFFF
    ctx->r2 = 0 | 0XFFF;
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_8002922C:
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
    // lhu         $v1, 0x1E($s2)
    ctx->r3 = MEM_HU(0X1E, ctx->r18);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800292EC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800292EC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B22($v0)
    ctx->r2 = MEM_HU(-0X4B22, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80029274
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80029274;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA1($v1)
    ctx->r3 = MEM_BU(-0X4AA1, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80029274
    if (ctx->r3 != ctx->r2) {
        // ori         $a0, $zero, 0x3
        ctx->r4 = 0 | 0X3;
        goto L_80029274;
    }
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // jal         0x80014570
    // ori         $a1, $zero, 0x6E
    ctx->r5 = 0 | 0X6E;
    PlaySoundEffect(rdram, ctx);
    goto after_1;
    // ori         $a1, $zero, 0x6E
    ctx->r5 = 0 | 0X6E;
    after_1:
L_80029274:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AAC($v1)
    ctx->r3 = MEM_H(-0X4AAC, ctx->r3);
    // lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(0X1E, ctx->r18);
    // nop

    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
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
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // ori         $v1, $zero, 0xFFF
    ctx->r3 = 0 | 0XFFF;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // div         $zero, $v0, $v1
	if (ctx->r3 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
	}
	else
	{
		lo = 0; 
		hi = 0;
	}
    
    // bne         $v1, $zero, L_800292BC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800292BC;
    }
    // nop

    // break       7
    do_break(2147652280);
L_800292BC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_800292D4
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800292D4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800292D4
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800292D4;
    }
    // nop

    // break       6
    do_break(2147652304);
L_800292D4:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = ctx->r2;
    // j           L_800292F4
    // nop

    goto L_800292F4;
    // nop

L_800292EC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
L_800292F4:
    // lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // lw          $s3, -0x4AB0($s3)
    ctx->r19 = MEM_W(-0X4AB0, ctx->r19);
    // nop

    // beq         $s3, $zero, L_8002949C
    if (ctx->r19 == 0) {
        // ori         $a0, $zero, 0x20
        ctx->r4 = 0 | 0X20;
        goto L_8002949C;
    }
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4C($v0)
    ctx->r2 = MEM_HU(-0X4A4C, ctx->r2);
    // lhu         $v1, 0x3C($s2)
    ctx->r3 = MEM_HU(0X3C, ctx->r18);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A4A($v0)
    ctx->r2 = MEM_HU(-0X4A4A, ctx->r2);
    // lhu         $v1, 0x3E($s2)
    ctx->r3 = MEM_HU(0X3E, ctx->r18);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x4AA2($a1)
    ctx->r5 = MEM_BU(-0X4AA2, ctx->r5);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A48($v0)
    ctx->r2 = MEM_HU(-0X4A48, ctx->r2);
    // lhu         $v1, 0x40($s2)
    ctx->r3 = MEM_HU(0X40, ctx->r18);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4AAC($a2)
    ctx->r6 = MEM_H(-0X4AAC, ctx->r6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r2;
    // lh          $a3, 0x3A($s2)
    ctx->r7 = MEM_H(0X3A, ctx->r18);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // jal         0x80036DD8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80036DD8(rdram, ctx);
    goto after_2;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // lhu         $v1, 0x34($s2)
    ctx->r3 = MEM_HU(0X34, ctx->r18);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(0X3A, ctx->r29);
    // lhu         $v1, 0x36($s2)
    ctx->r3 = MEM_HU(0X36, ctx->r18);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x3C($sp)
    ctx->r2 = MEM_HU(0X3C, ctx->r29);
    // lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(0X38, ctx->r18);
    // addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80015614
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    sub_80015614(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A5C($v0)
    ctx->r2 = MEM_W(-0X4A5C, ctx->r2);
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(0X4C, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A08($v1)
    ctx->r3 = MEM_H(-0X4A08, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A04($a0)
    ctx->r4 = MEM_H(-0X4A04, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // lh          $a3, 0x42($s2)
    ctx->r7 = MEM_H(0X42, ctx->r18);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x4AA2($a1)
    ctx->r5 = MEM_BU(-0X4AA2, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lh          $a2, -0x4AAC($a2)
    ctx->r6 = MEM_H(-0X4AAC, ctx->r6);
    // ori         $a0, $zero, 0x20
    ctx->r4 = 0 | 0X20;
    // jal         0x80036DD8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80036DD8(rdram, ctx);
    goto after_4;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // lhu         $v1, 0x34($s2)
    ctx->r3 = MEM_HU(0X34, ctx->r18);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(0X3A, ctx->r29);
    // lhu         $v1, 0x36($s2)
    ctx->r3 = MEM_HU(0X36, ctx->r18);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x3C($sp)
    ctx->r2 = MEM_HU(0X3C, ctx->r29);
    // lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(0X38, ctx->r18);
    // addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80015614
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    sub_80015614(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    after_5:
    // addiu       $a3, $s3, 0x24
    ctx->r7 = ADD32(ctx->r19, 0X24);
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(0X78, ctx->r29);
    // lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(0X4C, ctx->r29);
    // lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(0X7C, ctx->r29);
    // lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(0X80, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x800159DC
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    Math_VectorToAngles(rdram, ctx);
    goto after_6;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_6:
L_8002949C:
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
    // bne         $v0, $zero, L_80029C18
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029C18;
    }
    // nop

    // beq         $s3, $zero, L_8002952C
    if (ctx->r19 == 0) {
        // addiu       $a0, $s3, 0x24
        ctx->r4 = ADD32(ctx->r19, 0X24);
        goto L_8002952C;
    }
    // addiu       $a0, $s3, 0x24
    ctx->r4 = ADD32(ctx->r19, 0X24);
    // addiu       $s0, $s3, 0x34
    ctx->r16 = ADD32(ctx->r19, 0X34);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80015538
    // sb          $zero, 0x7($s3)
    MEM_B(0X7, ctx->r19) = 0;
    Math_AnglesToDirVector(rdram, ctx);
    goto after_7;
    // sb          $zero, 0x7($s3)
    MEM_B(0X7, ctx->r19) = 0;
    after_7:
    // lui         $a0, 0x68DB
    ctx->r4 = S32(0X68DB << 16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B22($v1)
    ctx->r3 = MEM_HU(-0X4B22, ctx->r3);
    // ori         $a0, $a0, 0x8BAD
    ctx->r4 = ctx->r4 | 0X8BAD;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $a0
    ctx->r4 = hi;
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80015694
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80015694(rdram, ctx);
    goto after_8;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_8:
    // lhu         $v1, 0x18($s3)
    ctx->r3 = MEM_HU(0X18, ctx->r19);
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sh          $v0, 0xE($s3)
    MEM_H(0XE, ctx->r19) = ctx->r2;
    // sh          $v1, 0x40($s3)
    MEM_H(0X40, ctx->r19) = ctx->r3;
L_8002952C:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA2($at)
    MEM_B(-0X4AA2, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4AAC($at)
    MEM_H(-0X4AAC, ctx->r1) = 0;
    // j           L_80029C18
    // nop

    goto L_80029C18;
    // nop

L_80029548:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AAC($at)
    MEM_H(-0X4AAC, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80029C18
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80029C18;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AAC($at)
    MEM_H(-0X4AAC, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
    // j           L_80029C18
    // nop

    goto L_80029C18;
    // nop

L_8002957C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4B31($at)
    MEM_B(-0X4B31, ctx->r1) = 0;
    // j           L_80029C18
    // nop

    goto L_80029C18;
    // nop

L_80029594:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AAC($v1)
    ctx->r3 = MEM_H(-0X4AAC, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80029B38
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80029B38;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA2($v0)
    ctx->r2 = MEM_BU(-0X4AA2, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800295D0
    if (ctx->r2 != 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_800295D0;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lhu         $s1, 0x1C($s2)
    ctx->r17 = MEM_HU(0X1C, ctx->r18);
    // lhu         $s4, 0x1E($s2)
    ctx->r20 = MEM_HU(0X1E, ctx->r18);
    // lhu         $s5, 0x2C($s2)
    ctx->r21 = MEM_HU(0X2C, ctx->r18);
    // j           L_800295E4
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    goto L_800295E4;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
L_800295D0:
    // lhu         $s1, 0x24($s2)
    ctx->r17 = MEM_HU(0X24, ctx->r18);
    // lhu         $s4, 0x28($s2)
    ctx->r20 = MEM_HU(0X28, ctx->r18);
    // lhu         $s3, 0x2A($s2)
    ctx->r19 = MEM_HU(0X2A, ctx->r18);
    // lhu         $s5, 0x30($s2)
    ctx->r21 = MEM_HU(0X30, ctx->r18);
    // lhu         $s6, 0x32($s2)
    ctx->r22 = MEM_HU(0X32, ctx->r18);
L_800295E4:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4AAC
    ctx->r16 = ADD32(ctx->r16, -0X4AAC);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA2($v1)
    ctx->r3 = MEM_BU(-0X4AA2, ctx->r3);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // bne         $v1, $zero, L_800296D4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800296D4;
    }
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x3($s2)
    ctx->r3 = MEM_BU(0X3, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_800296D4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800296D4;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A9D($v0)
    ctx->r2 = MEM_BU(-0X4A9D, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800296D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800296D4;
    }
    // nop

    // jal         0x80028E8C
    // nop

    sub_80028E8C(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // beq         $v0, $zero, L_800296D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800296D4;
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
    // beq         $v0, $zero, L_800296D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800296D4;
    }
    // nop

    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(0X0, ctx->r16);
    // lhu         $v0, 0x20($s2)
    ctx->r2 = MEM_HU(0X20, ctx->r18);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800296CC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800296CC;
    }
    // nop

    // lhu         $v0, 0x22($s2)
    ctx->r2 = MEM_HU(0X22, ctx->r18);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800296CC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800296CC;
    }
    // nop

    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lbu         $a2, -0x4A9E($a2)
    ctx->r6 = MEM_BU(-0X4A9E, ctx->r6);
    // nop

    // beq         $a2, $zero, L_800296D4
    if (ctx->r6 == 0) {
        // nop
    
        goto L_800296D4;
    }
    // nop

    // lbu         $v0, 0x5($s2)
    ctx->r2 = MEM_BU(0X5, ctx->r18);
    // lbu         $a0, 0x3($s2)
    ctx->r4 = MEM_BU(0X3, ctx->r18);
    // xor         $a1, $a2, $v0
    ctx->r5 = ctx->r6 ^ ctx->r2;
    // jal         0x80028EC0
    // sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    CheckHasWeaponMagic(rdram, ctx);
    goto after_10;
    // sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_10:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A9E($v0)
    ctx->r2 = MEM_BU(-0X4A9E, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A9E($at)
    MEM_B(-0X4A9E, ctx->r1) = ctx->r2;
    // j           L_800296D4
    // nop

    goto L_800296D4;
    // nop

L_800296CC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A9E($at)
    MEM_B(-0X4A9E, ctx->r1) = 0;
L_800296D4:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4AAC($a0)
    ctx->r4 = MEM_H(-0X4AAC, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AA8($v1)
    ctx->r3 = MEM_H(-0X4AA8, ctx->r3);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80029734
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s1
        ctx->r2 = ADD32(ctx->r3, ctx->r17);
        goto L_80029734;
    }
    // addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80029734
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80029734;
    }
    // nop

    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // jal         0x80014570
    // ori         $a1, $zero, 0x50
    ctx->r5 = 0 | 0X50;
    PlaySoundEffect(rdram, ctx);
    goto after_11;
    // ori         $a1, $zero, 0x50
    ctx->r5 = 0 | 0X50;
    after_11:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AA8($v0)
    ctx->r2 = MEM_H(-0X4AA8, ctx->r2);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slt         $v0, $v0, $s5
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // bne         $v0, $zero, L_8002972C
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s6
        ctx->r2 = ADD32(ctx->r3, ctx->r22);
        goto L_8002972C;
    }
    // addu        $v0, $v1, $s6
    ctx->r2 = ADD32(ctx->r3, ctx->r22);
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
L_8002972C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AA8($at)
    MEM_H(-0X4AA8, ctx->r1) = ctx->r2;
L_80029734:
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x4AAC
    ctx->r6 = ADD32(ctx->r6, -0X4AAC);
    // lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(0X0, ctx->r6);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AAA($v1)
    ctx->r3 = MEM_H(-0X4AAA, ctx->r3);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80029B08
    if (ctx->r2 != 0) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_80029B08;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80029B08
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80029B08;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA2($v1)
    ctx->r3 = MEM_BU(-0X4AA2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A9C($at)
    MEM_B(-0X4A9C, ctx->r1) = 0;
    // bne         $v1, $v0, L_80029828
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80029828;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA1($v1)
    ctx->r3 = MEM_BU(-0X4AA1, ctx->r3);
    // nop

    // bne         $v1, $v0, L_800297CC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800297CC;
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
    // beq         $v0, $zero, L_800297CC
    if (ctx->r2 == 0) {
        // subu        $v0, $a1, $s1
        ctx->r2 = SUB32(ctx->r5, ctx->r17);
        goto L_800297CC;
    }
    // subu        $v0, $a1, $s1
    ctx->r2 = SUB32(ctx->r5, ctx->r17);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A9C($at)
    MEM_B(-0X4A9C, ctx->r1) = ctx->r2;
    // j           L_80029C18
    // nop

    goto L_80029C18;
    // nop

L_800297CC:
    // lbu         $a0, 0x4($s2)
    ctx->r4 = MEM_BU(0X4, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_80029828
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80029828;
    }
    // nop

    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4AAC($a1)
    ctx->r5 = MEM_H(-0X4AAC, ctx->r5);
    // lhu         $a2, 0x26($s2)
    ctx->r6 = MEM_HU(0X26, ctx->r18);
    // nop

    // subu        $a2, $a1, $a2
    ctx->r6 = SUB32(ctx->r5, ctx->r6);
    // div         $zero, $a2, $s3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r19)));
    // bne         $s3, $zero, L_80029800
    if (ctx->r19 != 0) {
        // nop
    
        goto L_80029800;
    }
    // nop

    // break       7
    do_break(2147653628);
L_80029800:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s3, $at, L_80029818
    if (ctx->r19 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80029818;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_80029818
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_80029818;
    }
    // nop

    // break       6
    do_break(2147653652);
L_80029818:
    // mflo        $a2
    ctx->r6 = lo;
    // slt         $a1, $a1, $s4
    ctx->r5 = SIGNED(ctx->r5) < SIGNED(ctx->r20) ? 1 : 0;
    // jal         0x80028EC0
    // xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    CheckHasWeaponMagic(rdram, ctx);
    goto after_12;
    // xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    after_12:
L_80029828:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AAC($v0)
    ctx->r2 = MEM_H(-0X4AAC, ctx->r2);
    // nop

    // slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // bne         $v0, $zero, L_80029900
    if (ctx->r2 != 0) {
        // addiu       $t4, $sp, 0x68
        ctx->r12 = ADD32(ctx->r29, 0X68);
        goto L_80029900;
    }
    // addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // sw          $t4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r12;
    // lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // lhu         $t4, -0x4B20($t4)
    ctx->r12 = MEM_HU(-0X4B20, ctx->r12);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AAA($at)
    MEM_H(-0X4AAA, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B31($at)
    MEM_B(-0X4B31, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B22($at)
    MEM_H(-0X4B22, ctx->r1) = 0;
    // sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // addiu       $v0, $v0, -0x3E8
    ctx->r2 = ADD32(ctx->r2, -0X3E8);
    // sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // j           L_80029928
    // sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    goto L_80029928;
    // sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
L_8002989C:
    // lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(0X98, ctx->r29);
    // nop

    // sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(0X88, ctx->r29);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // lhu         $a1, -0xB0($s4)
    ctx->r5 = MEM_HU(-0XB0, ctx->r20);
    // lhu         $a2, -0xA8($s4)
    ctx->r6 = MEM_HU(-0XA8, ctx->r20);
    // lhu         $a3, -0xA6($s4)
    ctx->r7 = MEM_HU(-0XA6, ctx->r20);
    // lhu         $v0, -0xA4($s4)
    ctx->r2 = MEM_HU(-0XA4, ctx->r20);
    // lhu         $v1, -0xA2($s4)
    ctx->r3 = MEM_HU(-0XA2, ctx->r20);
    // lhu         $t0, -0xA0($s4)
    ctx->r8 = MEM_HU(-0XA0, ctx->r20);
    // lhu         $t1, -0x9E($s4)
    ctx->r9 = MEM_HU(-0X9E, ctx->r20);
    // lhu         $t2, -0x9C($s4)
    ctx->r10 = MEM_HU(-0X9C, ctx->r20);
    // lhu         $t3, -0x9A($s4)
    ctx->r11 = MEM_HU(-0X9A, ctx->r20);
    // andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // jal         0x8003C718
    // sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    ApplyDamage(rdram, ctx);
    goto after_13;
    // sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_13:
    // j           L_80029B08
    // nop

    goto L_80029B08;
    // nop

L_80029900:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4B20($v1)
    ctx->r3 = MEM_HU(-0X4B20, ctx->r3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4AAA($v0)
    ctx->r2 = MEM_HU(-0X4AAA, ctx->r2);
    // sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sw          $v1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AAA($at)
    MEM_H(-0X4AAA, ctx->r1) = ctx->r2;
L_80029928:
    // addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    // sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(0X1A, ctx->r18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A42($v1)
    ctx->r3 = MEM_HU(-0X4A42, ctx->r3);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A44
    ctx->r16 = ADD32(ctx->r16, -0X4A44);
    // sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x80015614
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    sub_80015614(rdram, ctx);
    goto after_14;
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    after_14:
    // ori         $v0, $zero, 0xE10
    ctx->r2 = 0 | 0XE10;
    // lhu         $v1, 0x1A($s2)
    ctx->r3 = MEM_HU(0X1A, ctx->r18);
    // lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(0X5C, ctx->r29);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x91A2
    ctx->r2 = S32(0X91A2 << 16);
    // ori         $v0, $v0, 0xB3C5
    ctx->r2 = ctx->r2 | 0XB3C5;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(0X58, ctx->r29);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // bgez        $a0, L_800299B4
    if (SIGNED(ctx->r4) >= 0) {
        // sw          $v1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r3;
        goto L_800299B4;
    }
    // sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_800299B4:
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // bgez        $v0, L_800299CC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800299CC;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_800299CC:
    // lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(0X60, ctx->r29);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // bgez        $a0, L_800299E0
    if (SIGNED(ctx->r4) >= 0) {
        // sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
        goto L_800299E0;
    }
    // sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_800299E0:
    // ori         $s5, $zero, 0x3
    ctx->r21 = 0 | 0X3;
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // addiu       $s7, $s7, -0x19F8
    ctx->r23 = ADD32(ctx->r23, -0X19F8);
    // addiu       $fp, $s7, 0x60E0
    ctx->r30 = ADD32(ctx->r23, 0X60E0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // addiu       $s4, $s0, -0x20
    ctx->r20 = ADD32(ctx->r16, -0X20);
    // sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // addiu       $v0, $v0, -0x320
    ctx->r2 = ADD32(ctx->r2, -0X320);
    // sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
L_80029A28:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(0X58, ctx->r29);
    // lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(0X5C, ctx->r29);
    // lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(0X60, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(0X4C, ctx->r29);
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x258
    ctx->r2 = 0 | 0X258;
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(0X48, ctx->r29);
    // lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(0X4C, ctx->r29);
    // lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(0X50, ctx->r29);
    // jal         0x8003D480
    // ori         $a3, $zero, 0x190
    ctx->r7 = 0 | 0X190;
    Entity_CheckWorldCollision(rdram, ctx);
    goto after_15;
    // ori         $a3, $zero, 0x190
    ctx->r7 = 0 | 0X190;
    after_15:
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // beq         $s3, $s6, L_80029B00
    if (ctx->r19 == ctx->r22) {
        // addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80029B00;
    }
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // sll         $v0, $s3, 5
    ctx->r2 = S32(ctx->r19) << 5;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $v0, $s7
    ctx->r17 = ADD32(ctx->r2, ctx->r23);
    // lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(0X2C, ctx->r17);
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(0X8, ctx->r20);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(0X34, ctx->r17);
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // jal         0x80015804
    // addu        $s2, $v0, $fp
    ctx->r18 = ADD32(ctx->r2, ctx->r30);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_16;
    // addu        $s2, $v0, $fp
    ctx->r18 = ADD32(ctx->r2, ctx->r30);
    after_16:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16) << 16;
    // lh          $a0, 0x1A($s4)
    ctx->r4 = MEM_H(0X1A, ctx->r20);
    // lh          $a2, 0x16($s2)
    ctx->r6 = MEM_H(0X16, ctx->r18);
    // jal         0x80015798
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_17;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_17:
    // beq         $v0, $zero, L_80029B00
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80029B00;
    }
    // nop

    // addiu       $a1, $s0, 0x800
    ctx->r5 = ADD32(ctx->r16, 0X800);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // lh          $a0, 0x42($s1)
    ctx->r4 = MEM_H(0X42, ctx->r17);
    // lh          $a2, 0x18($s2)
    ctx->r6 = MEM_H(0X18, ctx->r18);
    // jal         0x80015798
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_18;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_18:
    // bne         $v0, $zero, L_8002989C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x11
        ctx->r2 = 0 | 0X11;
        goto L_8002989C;
    }
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
L_80029B00:
    // bne         $s5, $s6, L_80029A28
    if (ctx->r21 != ctx->r22) {
        // nop
    
        goto L_80029A28;
    }
    // nop

L_80029B08:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4AAC
    ctx->r3 = ADD32(ctx->r3, -0X4AAC);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(0X0, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80029C18
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80029C18;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A9E($at)
    MEM_B(-0X4A9E, ctx->r1) = 0;
    // j           L_80029C18
    // nop

    goto L_80029C18;
    // nop

L_80029B38:
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
    // bne         $v0, $zero, L_80029C18
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029C18;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4B31($v0)
    ctx->r2 = MEM_BU(-0X4B31, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80029C10
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80029C10;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x4B14($a0)
    ctx->r4 = MEM_HU(-0X4B14, ctx->r4);
    // lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(0X1, ctx->r18);
    // jal         0x800262C0
    // nop

    sub_800262C0(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A79($v1)
    ctx->r3 = MEM_BU(-0X4A79, ctx->r3);
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // bne         $v1, $v0, L_80029B9C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80029B9C;
    }
    // nop

    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
L_80029B9C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A77($v0)
    ctx->r2 = MEM_BU(-0X4A77, ctx->r2);
    // ori         $v1, $zero, 0x39
    ctx->r3 = 0 | 0X39;
    // beq         $v0, $v1, L_80029BC4
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80029BC4;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A76($v0)
    ctx->r2 = MEM_BU(-0X4A76, ctx->r2);
    // nop

    // bne         $v0, $v1, L_80029BDC
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80029BDC;
    }
    // nop

L_80029BC4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4AA1($v1)
    ctx->r3 = MEM_BU(-0X4AA1, ctx->r3);
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // bne         $v1, $v0, L_80029BDC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80029BDC;
    }
    // nop

    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
L_80029BDC:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B22
    ctx->r3 = ADD32(ctx->r3, -0X4B22);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1389
    ctx->r2 = ctx->r2 < 0X1389 ? 1 : 0;
    // bne         $v0, $zero, L_80029C18
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1388
        ctx->r2 = 0 | 0X1388;
        goto L_80029C18;
    }
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // j           L_80029C18
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    goto L_80029C18;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80029C10:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B31($at)
    MEM_B(-0X4B31, ctx->r1) = ctx->r2;
L_80029C18:
    // lw          $ra, 0xD4($sp)
    ctx->r31 = MEM_W(0XD4, ctx->r29);
    // lw          $fp, 0xD0($sp)
    ctx->r30 = MEM_W(0XD0, ctx->r29);
    // lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(0XCC, ctx->r29);
    // lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(0XC8, ctx->r29);
    // lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(0XC4, ctx->r29);
    // lw          $s4, 0xC0($sp)
    ctx->r20 = MEM_W(0XC0, ctx->r29);
    // lw          $s3, 0xBC($sp)
    ctx->r19 = MEM_W(0XBC, ctx->r29);
    // lw          $s2, 0xB8($sp)
    ctx->r18 = MEM_W(0XB8, ctx->r29);
    // lw          $s1, 0xB4($sp)
    ctx->r17 = MEM_W(0XB4, ctx->r29);
    // lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(0XB0, ctx->r29);
    // addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // jr          $ra
    // nop

    return;
    // nop

;}
