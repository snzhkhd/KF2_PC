#include "recomp.h"
#include "disable_warnings.h"

void sub_80056504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7584
    ctx->r1 = ADD32(ctx->r1, -0X7584);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3) << 3;
    // beq         $v0, $zero, L_80056598
    if (ctx->r2 == 0) {
        // addu        $t0, $a0, $zero
        ctx->r8 = ADD32(ctx->r4, 0);
        goto L_80056598;
    }
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7582
    ctx->r1 = ADD32(ctx->r1, -0X7582);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7582
    ctx->r1 = ADD32(ctx->r1, -0X7582);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_800568C4
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_800568C4;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7584
    ctx->r1 = ADD32(ctx->r1, -0X7584);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7582
    ctx->r1 = ADD32(ctx->r1, -0X7582);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
L_80056598:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7580
    ctx->r1 = ADD32(ctx->r1, -0X7580);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7586
    ctx->r1 = ADD32(ctx->r1, -0X7586);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7586
    ctx->r1 = ADD32(ctx->r1, -0X7586);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $a0, 0x0($at)
    ctx->r4 = MEM_H(0X0, ctx->r1);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7580
    ctx->r1 = ADD32(ctx->r1, -0X7580);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
    // blez        $a0, L_80056610
    if (SIGNED(ctx->r4) <= 0) {
        // nop
    
        goto L_80056610;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x757E
    ctx->r1 = ADD32(ctx->r1, -0X757E);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80056660
    if (ctx->r2 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_80056660;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // j           L_80056640
    // nop

    goto L_80056640;
    // nop

L_80056610:
    // bgez        $a0, L_80056664
    if (SIGNED(ctx->r4) >= 0) {
        // sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8) << 16;
        goto L_80056664;
    }
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x757E
    ctx->r1 = ADD32(ctx->r1, -0X757E);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_80056664
    if (ctx->r3 != 0) {
        // sll         $v1, $t0, 16
        ctx->r3 = S32(ctx->r8) << 16;
        goto L_80056664;
    }
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
L_80056640:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7580
    ctx->r1 = ADD32(ctx->r1, -0X7580);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7588
    ctx->r1 = ADD32(ctx->r1, -0X7588);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
L_80056660:
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
L_80056664:
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addiu       $at, $at, -0x7580
    ctx->r1 = ADD32(ctx->r1, -0X7580);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $a3, 0x0($at)
    ctx->r7 = MEM_BU(0X0, ctx->r1);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2550($v0)
    ctx->r2 = MEM_W(-0X2550, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a3, -0x192B($at)
    MEM_B(-0X192B, ctx->r1) = ctx->r7;
    // lbu         $v1, 0x18($v0)
    ctx->r3 = MEM_BU(0X18, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x192C($a0)
    ctx->r4 = MEM_BU(-0X192C, ctx->r4);
    // sll         $v0, $v1, 14
    ctx->r2 = S32(ctx->r3) << 14;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $a0, $zero, 0x3F01
    ctx->r4 = 0 | 0X3F01;
    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_800566D0
    if (ctx->r4 != 0) {
        // nop
    
        goto L_800566D0;
    }
    // nop

    // break       7
    do_break(2147837644);
L_800566D0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_800566E8
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800566E8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800566E8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800566E8;
    }
    // nop

    // break       6
    do_break(2147837668);
L_800566E8:
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1926($v1)
    ctx->r3 = MEM_BU(-0X1926, ctx->r3);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x1923($v0)
    ctx->r2 = MEM_BU(-0X1923, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // bne         $a0, $zero, L_80056730
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80056730;
    }
    // nop

    // break       7
    do_break(2147837740);
L_80056730:
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x1922($a0)
    ctx->r4 = MEM_BU(-0X1922, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80056760
    if (ctx->r2 == 0) {
        // mult        $v1, $a0
        result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80056760;
    }
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // j           L_8005677C
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    goto L_8005677C;
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
L_80056760:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
L_8005677C:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x1925($a0)
    ctx->r4 = MEM_BU(-0X1925, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_800567B8
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_800567B8;
    }
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // bgez        $v0, L_800567B0
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $a3, $zero
        ctx->r4 = ADD32(ctx->r7, 0);
        goto L_800567B0;
    }
    // addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
L_800567B0:
    // j           L_800567E4
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    goto L_800567E4;
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
L_800567B8:
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // bgez        $v0, L_800567E0
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $a3, $zero
        ctx->r4 = ADD32(ctx->r7, 0);
        goto L_800567E0;
    }
    // addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
L_800567E0:
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
L_800567E4:
    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80056814
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_80056814;
    }
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // bgez        $v0, L_80056840
    if (SIGNED(ctx->r2) >= 0) {
        // srl         $a2, $v0, 6
        ctx->r6 = S32(U32(ctx->r2) >> 6);
        goto L_80056840;
    }
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // j           L_80056840
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    goto L_80056840;
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
L_80056814:
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // bgez        $v0, L_80056840
    if (SIGNED(ctx->r2) >= 0) {
        // srl         $a1, $v0, 6
        ctx->r5 = S32(U32(ctx->r2) >> 6);
        goto L_80056840;
    }
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
L_80056840:
    // lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // lh          $v1, 0xA88($v1)
    ctx->r3 = MEM_H(0XA88, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80056874
    if (ctx->r3 != ctx->r2) {
        // sll         $a0, $t1, 16
        ctx->r4 = S32(ctx->r9) << 16;
        goto L_80056874;
    }
    // sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9) << 16;
    // andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80056870
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80056870;
    }
    // nop

    // j           L_80056874
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    goto L_80056874;
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_80056870:
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_80056874:
    // sra         $a0, $a0, 15
    ctx->r4 = S32(ctx->r4) >> 15;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7746
    ctx->r1 = ADD32(ctx->r1, -0X7746);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sh          $a2, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r6;
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7748
    ctx->r1 = ADD32(ctx->r1, -0X7748);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sh          $a1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r5;
    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
L_800568C4:
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
