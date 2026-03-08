#include "recomp.h"
#include "disable_warnings.h"

void sub_80055F60(uint8_t* rdram, recomp_context* ctx) {
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
    // addiu       $at, $at, -0x7590
    ctx->r1 = ADD32(ctx->r1, -0X7590);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3) << 3;
    // beq         $v0, $zero, L_80055FF4
    if (ctx->r2 == 0) {
        // addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
        goto L_80055FF4;
    }
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758E
    ctx->r1 = ADD32(ctx->r1, -0X758E);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758E
    ctx->r1 = ADD32(ctx->r1, -0X758E);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8005632C
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8005632C;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7590
    ctx->r1 = ADD32(ctx->r1, -0X7590);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758E
    ctx->r1 = ADD32(ctx->r1, -0X758E);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
L_80055FF4:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758C
    ctx->r1 = ADD32(ctx->r1, -0X758C);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7592
    ctx->r1 = ADD32(ctx->r1, -0X7592);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7592
    ctx->r1 = ADD32(ctx->r1, -0X7592);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // lh          $a0, 0x0($at)
    ctx->r4 = MEM_H(0X0, ctx->r1);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758C
    ctx->r1 = ADD32(ctx->r1, -0X758C);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
    // blez        $a0, L_8005606C
    if (SIGNED(ctx->r4) <= 0) {
        // nop
    
        goto L_8005606C;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758A
    ctx->r1 = ADD32(ctx->r1, -0X758A);
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
    // bne         $v0, $zero, L_800560BC
    if (ctx->r2 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_800560BC;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // j           L_8005609C
    // nop

    goto L_8005609C;
    // nop

L_8005606C:
    // bgez        $a0, L_800560C0
    if (SIGNED(ctx->r4) >= 0) {
        // sll         $v1, $a3, 16
        ctx->r3 = S32(ctx->r7) << 16;
        goto L_800560C0;
    }
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758A
    ctx->r1 = ADD32(ctx->r1, -0X758A);
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
    // bne         $v1, $zero, L_800560C0
    if (ctx->r3 != 0) {
        // sll         $v1, $a3, 16
        ctx->r3 = S32(ctx->r7) << 16;
        goto L_800560C0;
    }
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
L_8005609C:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x758C
    ctx->r1 = ADD32(ctx->r1, -0X758C);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7594
    ctx->r1 = ADD32(ctx->r1, -0X7594);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
L_800560BC:
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
L_800560C0:
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
    // addiu       $at, $at, -0x758C
    ctx->r1 = ADD32(ctx->r1, -0X758C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2550($v0)
    ctx->r2 = MEM_W(-0X2550, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x192C($at)
    MEM_B(-0X192C, ctx->r1) = ctx->r3;
    // lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(0X18, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $a0, 14
    ctx->r2 = S32(ctx->r4) << 14;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $a0, $zero, 0x3F01
    ctx->r4 = 0 | 0X3F01;
    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8005612C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8005612C;
    }
    // nop

    // break       7
    do_break(2147836200);
L_8005612C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_80056144
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80056144;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80056144
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80056144;
    }
    // nop

    // break       6
    do_break(2147836224);
L_80056144:
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
    // bne         $a0, $zero, L_8005618C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8005618C;
    }
    // nop

    // break       7
    do_break(2147836296);
L_8005618C:
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x1922($a0)
    ctx->r4 = MEM_BU(-0X1922, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_800561BC
    if (ctx->r2 == 0) {
        // mult        $v1, $a0
        result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_800561BC;
    }
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // j           L_800561D8
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    goto L_800561D8;
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
L_800561BC:
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
L_800561D8:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x1925($a0)
    ctx->r4 = MEM_BU(-0X1925, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80056214
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_80056214;
    }
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // bgez        $v0, L_80056240
    if (SIGNED(ctx->r2) >= 0) {
        // srl         $a2, $v0, 6
        ctx->r6 = S32(U32(ctx->r2) >> 6);
        goto L_80056240;
    }
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // j           L_80056240
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    goto L_80056240;
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
L_80056214:
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

    // bgez        $v0, L_80056240
    if (SIGNED(ctx->r2) >= 0) {
        // srl         $a1, $v0, 6
        ctx->r5 = S32(U32(ctx->r2) >> 6);
        goto L_80056240;
    }
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
L_80056240:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x192B($a0)
    ctx->r4 = MEM_BU(-0X192B, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8005627C
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
        goto L_8005627C;
    }
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // bgez        $v0, L_800562A8
    if (SIGNED(ctx->r2) >= 0) {
        // srl         $a2, $v0, 6
        ctx->r6 = S32(U32(ctx->r2) >> 6);
        goto L_800562A8;
    }
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // j           L_800562A8
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
    goto L_800562A8;
    // srl         $a2, $v0, 6
    ctx->r6 = S32(U32(ctx->r2) >> 6);
L_8005627C:
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

    // bgez        $v0, L_800562A8
    if (SIGNED(ctx->r2) >= 0) {
        // srl         $a1, $v0, 6
        ctx->r5 = S32(U32(ctx->r2) >> 6);
        goto L_800562A8;
    }
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
    // addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // srl         $a1, $v0, 6
    ctx->r5 = S32(U32(ctx->r2) >> 6);
L_800562A8:
    // lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // lh          $v1, 0xA88($v1)
    ctx->r3 = MEM_H(0XA88, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_800562DC
    if (ctx->r3 != ctx->r2) {
        // sll         $a0, $t0, 16
        ctx->r4 = S32(ctx->r8) << 16;
        goto L_800562DC;
    }
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
    // andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800562D8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800562D8;
    }
    // nop

    // j           L_800562DC
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    goto L_800562DC;
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_800562D8:
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_800562DC:
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
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
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
L_8005632C:
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
