#include "recomp.h"
#include "disable_warnings.h"

void sub_8005B7E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $s2, $a0, 16
    ctx->r18 = S32(ctx->r4) >> 16;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x2248
    ctx->r4 = ADD32(ctx->r4, -0X2248);
    // sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18) << 2;
    // addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // ori         $v0, $zero, 0x2F
    ctx->r2 = 0 | 0X2F;
    // beq         $a2, $v0, L_8005B9FC
    if (ctx->r6 == ctx->r2) {
        // addu        $s0, $a1, $v1
        ctx->r16 = ADD32(ctx->r5, ctx->r3);
        goto L_8005B9FC;
    }
    // addu        $s0, $a1, $v1
    ctx->r16 = ADD32(ctx->r5, ctx->r3);
    // ori         $v0, $zero, 0x51
    ctx->r2 = 0 | 0X51;
    // bne         $a2, $v0, L_8005BB38
    if (ctx->r6 != ctx->r2) {
        // lui         $a2, 0x393
        ctx->r6 = S32(0X393 << 16);
        goto L_8005BB38;
    }
    // lui         $a2, 0x393
    ctx->r6 = S32(0X393 << 16);
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // nop

    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lbu         $a1, 0x1($a0)
    ctx->r5 = MEM_BU(0X1, ctx->r4);
    // ori         $a2, $a2, 0x8700
    ctx->r6 = ctx->r6 | 0X8700;
    // addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8005B8B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B8B0;
    }
    // nop

    // break       7
    do_break(2147858604);
L_8005B8B0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8005B8C8
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005B8C8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_8005B8C8
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_8005B8C8;
    }
    // nop

    // break       6
    do_break(2147858628);
L_8005B8C8:
    // mflo        $a2
    ctx->r6 = lo;
    // lh          $v0, 0x4A($s0)
    ctx->r2 = MEM_H(0X4A, ctx->r16);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x5D30($v1)
    ctx->r3 = MEM_W(-0X5D30, ctx->r3);
    // nop

    // sll         $a3, $v1, 4
    ctx->r7 = S32(ctx->r3) << 4;
    // mflo        $a1
    ctx->r5 = lo;
    // nop

    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7) << 2;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8005B948
    if (ctx->r2 == 0) {
        // sw          $a2, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->r6;
        goto L_8005B948;
    }
    // sw          $a2, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r6;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // divu        $zero, $v1, $a1
    lo = S32(U32(ctx->r3) / U32(ctx->r5)); hi = S32(U32(ctx->r3) % U32(ctx->r5));
    // bne         $a1, $zero, L_8005B934
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8005B934;
    }
    // nop

    // break       7
    do_break(2147858736);
L_8005B934:
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // sh          $v1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r3;
    // j           L_8005B9E0
    // sh          $v1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r3;
    goto L_8005B9E0;
    // sh          $v1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r3;
L_8005B948:
    // lh          $v1, 0x4A($s0)
    ctx->r3 = MEM_H(0X4A, ctx->r16);
    // lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(0X8C, ctx->r16);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // bne         $a0, $zero, L_8005B980
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8005B980;
    }
    // nop

    // break       7
    do_break(2147858812);
L_8005B980:
    // mflo        $a1
    ctx->r5 = lo;
    // lh          $v1, 0x4A($s0)
    ctx->r3 = MEM_H(0X4A, ctx->r16);
    // lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(0X8C, ctx->r16);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // bne         $a0, $zero, L_8005B9BC
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8005B9BC;
    }
    // nop

    // break       7
    do_break(2147858872);
L_8005B9BC:
    // mfhi        $v1
    ctx->r3 = hi;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r2;
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8005B9E0
    if (ctx->r2 == 0) {
        // sh          $a1, 0x70($s0)
        MEM_H(0X70, ctx->r16) = ctx->r5;
        goto L_8005B9E0;
    }
    // sh          $a1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r5;
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // sh          $v0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r2;
L_8005B9E0:
    // sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $t0, 16
    ctx->r5 = S32(ctx->r8) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // j           L_8005BB38
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    goto L_8005BB38;
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
L_8005B9FC:
    // lhu         $v0, 0x48($s0)
    ctx->r2 = MEM_HU(0X48, ctx->r16);
    // lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(0X46, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // bne         $v1, $zero, L_8005BA28
    if (ctx->r3 != 0) {
        // sh          $v0, 0x48($s0)
        MEM_H(0X48, ctx->r16) = ctx->r2;
        goto L_8005BA28;
    }
    // sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // sb          $zero, 0x27($s0)
    MEM_B(0X27, ctx->r16) = 0;
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // j           L_8005BB38
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    goto L_8005BB38;
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8005BA28:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005BA5C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, -0x2
        ctx->r4 = ADD32(0, -0X2);
        goto L_8005BA5C;
    }
    // addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // sb          $zero, 0x27($s0)
    MEM_B(0X27, ctx->r16) = 0;
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // j           L_8005BB38
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    goto L_8005BB38;
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
L_8005BA5C:
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lbu         $v1, 0x3C($s0)
    ctx->r3 = MEM_BU(0X3C, ctx->r16);
    // sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8005BB20
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005BB20;
    }
    // nop

    // lbu         $a0, 0x3C($s0)
    ctx->r4 = MEM_BU(0X3C, ctx->r16);
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // jal         0x8005C10C
    // sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    sub_8005C10C(rdram, ctx);
    goto after_1;
    // sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    after_1:
    // sll         $a0, $s1, 8
    ctx->r4 = S32(ctx->r17) << 8;
    // jal         0x80057F04
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80057F04(rdram, ctx);
    goto after_2;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_2:
L_8005BB20:
    // sll         $a0, $s1, 8
    ctx->r4 = S32(ctx->r17) << 8;
    // jal         0x80057F04
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80057F04(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_3:
    // lh          $v0, 0x70($s0)
    ctx->r2 = MEM_H(0X70, ctx->r16);
    // nop

    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
L_8005BB38:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
