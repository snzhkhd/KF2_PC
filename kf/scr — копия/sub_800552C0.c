#include "recomp.h"
#include "disable_warnings.h"

void sub_800552C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x191A($v0)
    ctx->r2 = MEM_HU(-0X191A, ctx->r2);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // srl         $a0, $v0, 8
    ctx->r4 = S32(U32(ctx->r2) >> 8);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $a0, 0x74($v1)
    ctx->r4 = MEM_HU(0X74, ctx->r3);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x1926($a1)
    ctx->r5 = MEM_BU(-0X1926, ctx->r5);
    // sll         $v0, $a0, 7
    ctx->r2 = S32(ctx->r4) << 7;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
    // divu        $zero, $a0, $a2
    lo = S32(U32(ctx->r4) / U32(ctx->r6)); hi = S32(U32(ctx->r4) % U32(ctx->r6));
    // bne         $a2, $zero, L_8005533C
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8005533C;
    }
    // nop

    // break       7
    do_break(2147832632);
L_8005533C:
    // mflo        $a0
    ctx->r4 = lo;
    // lhu         $v1, 0x76($v1)
    ctx->r3 = MEM_HU(0X76, ctx->r3);
    // nop

    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // divu        $zero, $v1, $a2
    lo = S32(U32(ctx->r3) / U32(ctx->r6)); hi = S32(U32(ctx->r3) % U32(ctx->r6));
    // bne         $a2, $zero, L_80055370
    if (ctx->r6 != 0) {
        // nop
    
        goto L_80055370;
    }
    // nop

    // break       7
    do_break(2147832684);
L_80055370:
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x1923($a1)
    ctx->r5 = MEM_BU(-0X1923, ctx->r5);
    // nop

    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $a2
    lo = S32(U32(ctx->r2) / U32(ctx->r6)); hi = S32(U32(ctx->r2) % U32(ctx->r6));
    // bne         $a2, $zero, L_800553A0
    if (ctx->r6 != 0) {
        // nop
    
        goto L_800553A0;
    }
    // nop

    // break       7
    do_break(2147832732);
L_800553A0:
    // mflo        $a3
    ctx->r7 = lo;
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $a2
    lo = S32(U32(ctx->r2) / U32(ctx->r6)); hi = S32(U32(ctx->r2) % U32(ctx->r6));
    // bne         $a2, $zero, L_800553C4
    if (ctx->r6 != 0) {
        // nop
    
        goto L_800553C4;
    }
    // nop

    // break       7
    do_break(2147832768);
L_800553C4:
    // mflo        $a1
    ctx->r5 = lo;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1922($v1)
    ctx->r3 = MEM_BU(-0X1922, ctx->r3);
    // lhu         $a0, 0x1AA($v0)
    ctx->r4 = MEM_HU(0X1AA, ctx->r2);
    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80055414
    if (ctx->r2 == 0) {
        // addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
        goto L_80055414;
    }
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80055408
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80055408;
    }
    // nop

    // break       7
    do_break(2147832836);
L_80055408:
    // mflo        $a2
    ctx->r6 = lo;
    // j           L_80055440
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    goto L_80055440;
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
L_80055414:
    // subu        $v0, $a2, $v1
    ctx->r2 = SUB32(ctx->r6, ctx->r3);
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // ori         $v0, $zero, 0x3F
    ctx->r2 = 0 | 0X3F;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_8005543C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005543C;
    }
    // nop

    // break       7
    do_break(2147832888);
L_8005543C:
    // mflo        $a1
    ctx->r5 = lo;
L_80055440:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1925($v1)
    ctx->r3 = MEM_BU(-0X1925, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80055480
    if (ctx->r2 == 0) {
        // mult        $a2, $v1
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80055480;
    }
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80055474
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80055474;
    }
    // nop

    // break       7
    do_break(2147832944);
L_80055474:
    // mflo        $a2
    ctx->r6 = lo;
    // j           L_800554AC
    // nop

    goto L_800554AC;
    // nop

L_80055480:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // ori         $v0, $zero, 0x3F
    ctx->r2 = 0 | 0X3F;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_800554A8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800554A8;
    }
    // nop

    // break       7
    do_break(2147832996);
L_800554A8:
    // mflo        $a1
    ctx->r5 = lo;
L_800554AC:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x192B($v1)
    ctx->r3 = MEM_BU(-0X192B, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_800554EC
    if (ctx->r2 == 0) {
        // mult        $v1, $a2
        result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_800554EC;
    }
    // mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_800554E0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800554E0;
    }
    // nop

    // break       7
    do_break(2147833052);
L_800554E0:
    // mflo        $a2
    ctx->r6 = lo;
    // j           L_80055518
    // nop

    goto L_80055518;
    // nop

L_800554EC:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // ori         $v0, $zero, 0x3F
    ctx->r2 = 0 | 0X3F;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_80055514
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055514;
    }
    // nop

    // break       7
    do_break(2147833104);
L_80055514:
    // mflo        $a1
    ctx->r5 = lo;
L_80055518:
    // lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // lh          $v1, 0xA88($v1)
    ctx->r3 = MEM_H(0XA88, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80055540
    if (ctx->r3 != ctx->r2) {
        // sltu        $v0, $a1, $a2
        ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
        goto L_80055540;
    }
    // sltu        $v0, $a1, $a2
    ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
    // beq         $v0, $zero, L_8005553C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005553C;
    }
    // nop

    // j           L_80055540
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    goto L_80055540;
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8005553C:
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_80055540:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x192E($v0)
    ctx->r2 = MEM_BU(-0X192E, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1920($v1)
    ctx->r3 = MEM_BU(-0X1920, ctx->r3);
    // andi        $a0, $a0, 0xC0FF
    ctx->r4 = ctx->r4 & 0XC0FF;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(0X44, ctx->r3);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // sh          $a0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r4;
    // andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7746
    ctx->r1 = ADD32(ctx->r1, -0X7746);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $a2, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r6;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7748
    ctx->r1 = ADD32(ctx->r1, -0X7748);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $a1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r5;
    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // sltiu       $v0, $a0, 0x10
    ctx->r2 = ctx->r4 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_800555D4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_800555D4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $a3, $v0, $a0
    ctx->r7 = S32(ctx->r2) << (ctx->r4 & 31);
    // j           L_800555E0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_800555E0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800555D4:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v1, $a0, -0x10
    ctx->r3 = ADD32(ctx->r4, -0X10);
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
L_800555E0:
    // andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x49D8($a0)
    ctx->r4 = MEM_BU(-0X49D8, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // ori         $v1, $zero, 0xA
    ctx->r3 = 0 | 0XA;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AC
    ctx->r1 = ADD32(ctx->r1, -0X75AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // beq         $a0, $zero, L_80055680
    if (ctx->r4 == 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80055680;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
L_80055620:
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
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $a0, 0x0($at)
    ctx->r4 = MEM_BU(0X0, ctx->r1);
    // addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $a0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r4;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49D8($v0)
    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_80055620
    if (ctx->r3 != 0) {
        // sll         $v1, $a1, 16
        ctx->r3 = S32(ctx->r5) << 16;
        goto L_80055620;
    }
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
L_80055680:
    // andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
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
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, -0x6EA0($v0)
    ctx->r2 = MEM_HU(-0X6EA0, ctx->r2);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x6E98($a0)
    ctx->r4 = MEM_HU(-0X6E98, ctx->r4);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0xFD8($v1)
    ctx->r3 = MEM_HU(-0XFD8, ctx->r3);
    // or          $v0, $a3, $v0
    ctx->r2 = ctx->r7 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, -0x6EA0($at)
    MEM_H(-0X6EA0, ctx->r1) = ctx->r2;
    // or          $a0, $a2, $a0
    ctx->r4 = ctx->r6 | ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $a0, -0x6E98($at)
    MEM_H(-0X6E98, ctx->r1) = ctx->r4;
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v1, -0xFD8($at)
    MEM_H(-0XFD8, ctx->r1) = ctx->r3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0xFD0($v0)
    ctx->r2 = MEM_HU(-0XFD0, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x191C($v1)
    ctx->r3 = MEM_BU(-0X191C, ctx->r3);
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0xFD0($at)
    MEM_H(-0XFD0, ctx->r1) = ctx->r2;
    // andi        $v1, $v1, 0x4
    ctx->r3 = ctx->r3 & 0X4;
    // beq         $v1, $zero, L_80055748
    if (ctx->r3 == 0) {
        // nor         $v1, $zero, $a3
        ctx->r3 = ~(0 | ctx->r7);
        goto L_80055748;
    }
    // nor         $v1, $zero, $a3
    ctx->r3 = ~(0 | ctx->r7);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, -0x6E90($v0)
    ctx->r2 = MEM_HU(-0X6E90, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x6E88($v1)
    ctx->r3 = MEM_HU(-0X6E88, ctx->r3);
    // or          $v0, $a3, $v0
    ctx->r2 = ctx->r7 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, -0x6E90($at)
    MEM_H(-0X6E90, ctx->r1) = ctx->r2;
    // or          $v1, $a2, $v1
    ctx->r3 = ctx->r6 | ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, -0x6E88($at)
    MEM_H(-0X6E88, ctx->r1) = ctx->r3;
    // j           L_80055774
    // nop

    goto L_80055774;
    // nop

L_80055748:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, -0x6E90($v0)
    ctx->r2 = MEM_HU(-0X6E90, ctx->r2);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x6E88($a0)
    ctx->r4 = MEM_HU(-0X6E88, ctx->r4);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, -0x6E90($at)
    MEM_H(-0X6E90, ctx->r1) = ctx->r2;
    // nor         $v0, $zero, $a2
    ctx->r2 = ~(0 | ctx->r6);
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $a0, -0x6E88($at)
    MEM_H(-0X6E88, ctx->r1) = ctx->r4;
L_80055774:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // nop

    // sh          $a3, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r7;
    // sh          $a2, 0x196($v0)
    MEM_H(0X196, ctx->r2) = ctx->r6;
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
