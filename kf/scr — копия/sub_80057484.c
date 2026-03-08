#include "recomp.h"
#include "disable_warnings.h"

void sub_80057484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // sw          $ra, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r31;
    // sw          $fp, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r30;
    // sw          $s7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r22;
    // sw          $s5, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r21;
    // sw          $s4, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r20;
    // sw          $s3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r18;
    // sw          $s1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r17;
    // sw          $s0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r16;
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8) << 16;
    // srl         $v0, $t1, 24
    ctx->r2 = S32(U32(ctx->r9) >> 24);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $s4, $a1, 16
    ctx->r20 = S32(ctx->r5) >> 16;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $s5, $t0, $zero
    ctx->r21 = ADD32(ctx->r8, 0);
    // sh          $a2, 0x110($sp)
    MEM_H(0X110, ctx->r29) = ctx->r6;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8) << 2;
    // sra         $s3, $t1, 16
    ctx->r19 = S32(ctx->r9) >> 16;
    // lhu         $fp, 0x158($sp)
    ctx->r30 = MEM_HU(0X158, ctx->r29);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // lhu         $s7, 0x15C($sp)
    ctx->r23 = MEM_HU(0X15C, ctx->r29);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // jal         0x8005984C
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    sub_8005984C(rdram, ctx);
    goto after_0;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // bne         $v0, $zero, L_800579B4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800579B4;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s5, -0x191A($at)
    MEM_H(-0X191A, ctx->r1) = ctx->r21;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s6, -0x192E($at)
    MEM_B(-0X192E, ctx->r1) = ctx->r22;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x192D($at)
    MEM_B(-0X192D, ctx->r1) = 0;
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lh          $v0, 0x4E($v0)
    ctx->r2 = MEM_H(0X4E, ctx->r2);
    // andi        $a1, $fp, 0xFFFF
    ctx->r5 = ctx->r30 & 0XFFFF;
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80057584
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80057584;
    }
    // nop

    // break       7
    do_break(2147841408);
L_80057584:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8005759C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005759C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8005759C
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8005759C;
    }
    // nop

    // break       6
    do_break(2147841432);
L_8005759C:
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, -0x2560($a0)
    ctx->r4 = MEM_W(-0X2560, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s7, -0x192B($at)
    MEM_B(-0X192B, ctx->r1) = ctx->r23;
    // sll         $v0, $s1, 4
    ctx->r2 = S32(ctx->r17) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x192C($at)
    MEM_B(-0X192C, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1926($at)
    MEM_B(-0X1926, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1925($at)
    MEM_B(-0X1925, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, -0x2550($v1)
    ctx->r3 = MEM_W(-0X2550, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x1930($at)
    MEM_B(-0X1930, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x1929($v0)
    ctx->r2 = MEM_BU(-0X1929, ctx->r2);
    // lhu         $v1, 0x12($v1)
    ctx->r3 = MEM_HU(0X12, ctx->r3);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800579B4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800579B4;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a1, $zero, L_80057634
    if (ctx->r5 != 0) {
        // addiu       $a0, $sp, 0x90
        ctx->r4 = ADD32(ctx->r29, 0X90);
        goto L_80057634;
    }
    // addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x800579E4
    // andi        $a3, $s6, 0xFFFF
    ctx->r7 = ctx->r22 & 0XFFFF;
    sub_800579E4(rdram, ctx);
    goto after_1;
    // andi        $a3, $s6, 0xFFFF
    ctx->r7 = ctx->r22 & 0XFFFF;
    after_1:
    // j           L_800579B0
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    goto L_800579B0;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_80057634:
    // jal         0x80054FD8
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_80054FD8(rdram, ctx);
    goto after_2;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_800579B0
    if (ctx->r2 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_800579B0;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // addiu       $t2, $t2, -0x191A
    ctx->r10 = ADD32(ctx->r10, -0X191A);
    // addiu       $s0, $t2, 0x2
    ctx->r16 = ADD32(ctx->r10, 0X2);
    // andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
L_80057660:
    // addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(0X10, ctx->r2);
    // nop

    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // lbu         $v1, 0x90($v0)
    ctx->r3 = MEM_BU(0X90, ctx->r2);
    // lbu         $v0, -0x11($s0)
    ctx->r2 = MEM_BU(-0X11, ctx->r16);
    // sb          $v1, -0xC($s0)
    MEM_B(-0XC, ctx->r16) = ctx->r3;
    // lbu         $v1, -0xC($s0)
    ctx->r3 = MEM_BU(-0XC, ctx->r16);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, -0x1A08($a0)
    ctx->r4 = MEM_W(-0X1A08, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // sb          $v0, -0x9($s0)
    MEM_B(-0X9, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // nop

    // sb          $v0, -0xB($s0)
    MEM_B(-0XB, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // sb          $v0, -0xA($s0)
    MEM_B(-0XA, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // nop

    // sb          $v0, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(0X5, ctx->r3);
    // nop

    // sb          $v0, -0x7($s0)
    MEM_B(-0X7, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x6($v1)
    ctx->r2 = MEM_BU(0X6, ctx->r3);
    // nop

    // sb          $v0, -0x6($s0)
    MEM_B(-0X6, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x7($v1)
    ctx->r2 = MEM_BU(0X7, ctx->r3);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8005476C
    // sb          $v0, -0x5($s0)
    MEM_B(-0X5, ctx->r16) = ctx->r2;
    sub_8005476C(rdram, ctx);
    goto after_3;
    // sb          $v0, -0x5($s0)
    MEM_B(-0X5, ctx->r16) = ctx->r2;
    after_3:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v1, $zero, L_80057994
    if (ctx->r3 == 0) {
        // sh          $v0, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r2;
        goto L_80057994;
    }
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A2
    ctx->r1 = ADD32(ctx->r1, -0X75A2);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s5, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r21;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lbu         $a0, -0x17($s0)
    ctx->r4 = MEM_BU(-0X17, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759A
    ctx->r1 = ADD32(ctx->r1, -0X759A);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lbu         $a0, -0x11($s0)
    ctx->r4 = MEM_BU(-0X11, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A0
    ctx->r1 = ADD32(ctx->r1, -0X75A0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lhu         $t2, 0x110($sp)
    ctx->r10 = MEM_HU(0X110, ctx->r29);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $t2, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r10;
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // ori         $v1, $zero, 0x21
    ctx->r3 = 0 | 0X21;
    // beq         $v0, $v1, L_80057860
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80057860;
    }
    // nop

    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A8
    ctx->r1 = ADD32(ctx->r1, -0X75A8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $fp, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r30;
L_80057860:
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A6
    ctx->r1 = ADD32(ctx->r1, -0X75A6);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $s7, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r23;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lbu         $a0, -0xC($s0)
    ctx->r4 = MEM_BU(-0XC, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A4
    ctx->r1 = ADD32(ctx->r1, -0X75A4);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s6, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r22;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lbu         $a0, -0x9($s0)
    ctx->r4 = MEM_BU(-0X9, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7598
    ctx->r1 = ADD32(ctx->r1, -0X7598);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75B0
    ctx->r1 = ADD32(ctx->r1, -0X75B0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // jal         0x80055088
    // nop

    sub_80055088(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80057968
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80057968;
    }
    // nop

    // lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(0X2, ctx->r16);
    // jal         0x800552C0
    // nop

    sub_800552C0(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_8005797C
    // nop

    goto L_8005797C;
    // nop

L_80057968:
    // jal         0x8005599C
    // nop

    sub_8005599C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // jal         0x80054A10
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    sub_80054A10(rdram, ctx);
    goto after_7;
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_7:
L_8005797C:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x1916($v1)
    ctx->r3 = MEM_H(-0X1916, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2) << (ctx->r3 & 31);
    // j           L_80057998
    // or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    goto L_80057998;
    // or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_80057994:
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80057998:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80057660
    if (ctx->r2 != 0) {
        // andi        $v1, $s1, 0xFF
        ctx->r3 = ctx->r17 & 0XFF;
        goto L_80057660;
    }
    // andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
L_800579B0:
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_800579B4:
    // lw          $ra, 0x144($sp)
    ctx->r31 = MEM_W(0X144, ctx->r29);
    // lw          $fp, 0x140($sp)
    ctx->r30 = MEM_W(0X140, ctx->r29);
    // lw          $s7, 0x13C($sp)
    ctx->r23 = MEM_W(0X13C, ctx->r29);
    // lw          $s6, 0x138($sp)
    ctx->r22 = MEM_W(0X138, ctx->r29);
    // lw          $s5, 0x134($sp)
    ctx->r21 = MEM_W(0X134, ctx->r29);
    // lw          $s4, 0x130($sp)
    ctx->r20 = MEM_W(0X130, ctx->r29);
    // lw          $s3, 0x12C($sp)
    ctx->r19 = MEM_W(0X12C, ctx->r29);
    // lw          $s2, 0x128($sp)
    ctx->r18 = MEM_W(0X128, ctx->r29);
    // lw          $s1, 0x124($sp)
    ctx->r17 = MEM_W(0X124, ctx->r29);
    // lw          $s0, 0x120($sp)
    ctx->r16 = MEM_W(0X120, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
