#include "recomp.h"
#include "disable_warnings.h"

void sub_80029F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // jal         0x800601F4
    // sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    FixedSin(rdram, ctx);
    goto after_0;
    // sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_0:
    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // mflo        $v0
    ctx->r2 = lo;
    // jal         0x800602D0
    // sra         $s3, $v0, 12
    ctx->r19 = S32(ctx->r2) >> 12;
    FixedCos(rdram, ctx);
    goto after_1;
    // sra         $s3, $v0, 12
    ctx->r19 = S32(ctx->r2) >> 12;
    after_1:
    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // addu        $fp, $s3, $zero
    ctx->r30 = ADD32(ctx->r19, 0);
    // sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $s2, $v0, 12
    ctx->r18 = S32(ctx->r2) >> 12;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
L_80029F88:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A60($a1)
    ctx->r5 = MEM_W(-0X4A60, ctx->r5);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A64($v0)
    ctx->r2 = MEM_W(-0X4A64, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A5C($v1)
    ctx->r3 = MEM_W(-0X4A5C, ctx->r3);
    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x31
    ctx->r2 = 0 | 0X31;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    sub_8002E4F4(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_2:
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // bne         $s4, $zero, L_8002A014
    if (ctx->r20 != 0) {
        // addiu       $v0, $zero, -0x6
        ctx->r2 = ADD32(0, -0X6);
        goto L_8002A014;
    }
    // addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
L_80029FDC:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(0X20, ctx->r29);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $a0, -0x2A82($a0)
    ctx->r4 = MEM_HU(-0X2A82, ctx->r4);
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4A14($at)
    MEM_H(-0X4A14, ctx->r1) = ctx->r4;
    // j           L_8002A2F0
    // nop

    goto L_8002A2F0;
    // nop

L_8002A014:
    // and         $v0, $s4, $v0
    ctx->r2 = ctx->r20 & ctx->r2;
    // bne         $v0, $zero, L_8002A070
    if (ctx->r2 != 0) {
        // addu        $s6, $zero, $zero
        ctx->r22 = ADD32(0, 0);
        goto L_8002A070;
    }
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A7C($a0)
    ctx->r4 = MEM_W(-0X2A7C, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // addiu       $v0, $a0, 0x500
    ctx->r2 = ADD32(ctx->r4, 0X500);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002A070
    if (ctx->r2 != 0) {
        // ori         $s6, $zero, 0x1
        ctx->r22 = 0 | 0X1;
        goto L_8002A070;
    }
    // ori         $s6, $zero, 0x1
    ctx->r22 = 0 | 0X1;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A6F($v0)
    ctx->r2 = MEM_BU(-0X4A6F, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002A074
    if (ctx->r2 != 0) {
        // andi        $v0, $s4, 0x30
        ctx->r2 = ctx->r20 & 0X30;
        goto L_8002A074;
    }
    // andi        $v0, $s4, 0x30
    ctx->r2 = ctx->r20 & 0X30;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A78($v0)
    ctx->r2 = MEM_W(-0X2A78, ctx->r2);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // slti        $v0, $v0, -0x6A4
    ctx->r2 = SIGNED(ctx->r2) < -0X6A4 ? 1 : 0;
    // bne         $v0, $zero, L_80029FDC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029FDC;
    }
    // nop

L_8002A070:
    // andi        $v0, $s4, 0x30
    ctx->r2 = ctx->r20 & 0X30;
L_8002A074:
    // beq         $v0, $zero, L_8002A1A0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8002A1A0;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(0X48, ctx->r29);
    // nop

    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // beq         $t0, $v0, L_8002A2F0
    if (ctx->r8 == ctx->r2) {
        // sw          $t0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r8;
        goto L_8002A2F0;
    }
    // sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // jal         0x8002E394
    // nop

    sub_8002E394(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A5C($v1)
    ctx->r3 = MEM_HU(-0X2A5C, ctx->r3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A64($v0)
    ctx->r2 = MEM_HU(-0X4A64, ctx->r2);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lhu         $a1, -0x4A5C($a1)
    ctx->r5 = MEM_HU(-0X4A5C, ctx->r5);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) << 16;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x2A54($v0)
    ctx->r2 = MEM_HU(-0X2A54, ctx->r2);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sh          $v1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r3;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x80015804
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    Math_Atan2_Fixed(rdram, ctx);
    goto after_4;
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // jal         0x800157D4
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_800157D4(rdram, ctx);
    goto after_5;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_5:
    // bne         $v0, $zero, L_8002A100
    if (ctx->r2 != 0) {
        // addiu       $v0, $s1, 0x7E0
        ctx->r2 = ADD32(ctx->r17, 0X7E0);
        goto L_8002A100;
    }
    // addiu       $v0, $s1, 0x7E0
    ctx->r2 = ADD32(ctx->r17, 0X7E0);
    // addiu       $v0, $s1, 0x820
    ctx->r2 = ADD32(ctx->r17, 0X820);
L_8002A100:
    // andi        $s1, $v0, 0xFFF
    ctx->r17 = ctx->r2 & 0XFFF;
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // lhu         $s0, -0x2A4C($s0)
    ctx->r16 = MEM_HU(-0X2A4C, ctx->r16);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800601F4
    // addiu       $s0, $s0, 0x370
    ctx->r16 = ADD32(ctx->r16, 0X370);
    FixedSin(rdram, ctx);
    goto after_6;
    // addiu       $s0, $s0, 0x370
    ctx->r16 = ADD32(ctx->r16, 0X370);
    after_6:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // jal         0x800602D0
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    FixedCos(rdram, ctx);
    goto after_7;
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    after_7:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v0, 0x28($sp)
    ctx->r2 = MEM_H(0X28, ctx->r29);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A5C($v1)
    ctx->r3 = MEM_W(-0X2A5C, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $s3, $v0, $a0
    ctx->r19 = SUB32(ctx->r2, ctx->r4);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A54($a0)
    ctx->r4 = MEM_W(-0X2A54, ctx->r4);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // mflo        $v1
    ctx->r3 = lo;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // subu        $s2, $v0, $a1
    ctx->r18 = SUB32(ctx->r2, ctx->r5);
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    // j           L_80029F88
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    goto L_80029F88;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_8002A18C:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(0X20, ctx->r29);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // j           L_8002A244
    // sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    goto L_8002A244;
    // sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_8002A1A0:
    // lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(0X40, ctx->r29);
    // nop

    // bne         $t0, $zero, L_8002A24C
    if (ctx->r8 != 0) {
        // nop
    
        goto L_8002A24C;
    }
    // nop

    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // nop

    // addiu       $s0, $t0, -0x16
    ctx->r16 = ADD32(ctx->r8, -0X16);
    // bltz        $s0, L_8002A248
    if (SIGNED(ctx->r16) < 0) {
        // ori         $t0, $zero, 0x1
        ctx->r8 = 0 | 0X1;
        goto L_8002A248;
    }
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4A64
    ctx->r17 = ADD32(ctx->r17, -0X4A64);
L_8002A1CC:
    // jal         0x800601F4
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    FixedSin(rdram, ctx);
    goto after_8;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_8:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800602D0
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    FixedCos(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_9:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(0X4, ctx->r17);
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x31
    ctx->r2 = 0 | 0X31;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    sub_8002E4F4(rdram, ctx);
    goto after_10;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_10:
    // beq         $v0, $zero, L_8002A18C
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, -0x16
        ctx->r16 = ADD32(ctx->r16, -0X16);
        goto L_8002A18C;
    }
    // addiu       $s0, $s0, -0x16
    ctx->r16 = ADD32(ctx->r16, -0X16);
    // bgez        $s0, L_8002A1CC
    if (SIGNED(ctx->r16) >= 0) {
        // nop
    
        goto L_8002A1CC;
    }
    // nop

L_8002A244:
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
L_8002A248:
    // sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_8002A24C:
    // bne         $s6, $zero, L_8002A25C
    if (ctx->r22 != 0) {
        // andi        $v0, $s4, 0x1
        ctx->r2 = ctx->r20 & 0X1;
        goto L_8002A25C;
    }
    // andi        $v0, $s4, 0x1
    ctx->r2 = ctx->r20 & 0X1;
    // beq         $v0, $zero, L_8002A280
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x2
        ctx->r2 = ctx->r20 & 0X2;
        goto L_8002A280;
    }
    // andi        $v0, $s4, 0x2
    ctx->r2 = ctx->r20 & 0X2;
L_8002A25C:
    // beq         $s3, $zero, L_8002A26C
    if (ctx->r19 == 0) {
        // nop
    
        goto L_8002A26C;
    }
    // nop

    // j           L_80029F88
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    goto L_80029F88;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_8002A26C:
    // beq         $s2, $zero, L_8002A280
    if (ctx->r18 == 0) {
        // andi        $v0, $s4, 0x2
        ctx->r2 = ctx->r20 & 0X2;
        goto L_8002A280;
    }
    // andi        $v0, $s4, 0x2
    ctx->r2 = ctx->r20 & 0X2;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // j           L_80029F88
    // addu        $s3, $fp, $zero
    ctx->r19 = ADD32(ctx->r30, 0);
    goto L_80029F88;
    // addu        $s3, $fp, $zero
    ctx->r19 = ADD32(ctx->r30, 0);
L_8002A280:
    // beq         $v0, $zero, L_8002A2EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002A2EC;
    }
    // nop

    // bne         $s7, $zero, L_8002A25C
    if (ctx->r23 != 0) {
        // nop
    
        goto L_8002A25C;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A88($v0)
    ctx->r2 = MEM_W(-0X2A88, ctx->r2);
    // nop

    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // nop

    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $zero, L_8002A2BC
    if (ctx->r3 == 0) {
        // ori         $s7, $zero, 0x1
        ctx->r23 = 0 | 0X1;
        goto L_8002A2BC;
    }
    // ori         $s7, $zero, 0x1
    ctx->r23 = 0 | 0X1;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $v0, L_8002A2D4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002A2D4;
    }
    // nop

L_8002A2BC:
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // nop

    // addu        $v0, $fp, $t0
    ctx->r2 = ADD32(ctx->r30, ctx->r8);
    // sra         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2) >> 1;
    // j           L_80029F88
    // addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    goto L_80029F88;
    // addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
L_8002A2D4:
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // nop

    // subu        $v0, $fp, $t0
    ctx->r2 = SUB32(ctx->r30, ctx->r8);
    // sra         $s3, $v0, 1
    ctx->r19 = S32(ctx->r2) >> 1;
    // j           L_80029F88
    // negu        $s2, $s3
    ctx->r18 = SUB32(0, ctx->r19);
    goto L_80029F88;
    // negu        $s2, $s3
    ctx->r18 = SUB32(0, ctx->r19);
L_8002A2EC:
    // sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8002A2F0:
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s3, -0x4A54($at)
    MEM_H(-0X4A54, ctx->r1) = ctx->r19;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s2, -0x4A50($at)
    MEM_H(-0X4A50, ctx->r1) = ctx->r18;
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
