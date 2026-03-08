#include "recomp.h"
#include "disable_warnings.h"

void SEQ_InitData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // ori         $t1, $zero, 0x40
    ctx->r9 = 0 | 0X40;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $s0, 0x0($at)
    ctx->r16 = MEM_W(0X0, ctx->r1);
    // ori         $t0, $zero, 0x7F
    ctx->r8 = 0 | 0X7F;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sh          $a1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r5;
    // sh          $zero, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = 0;
    // sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // sb          $zero, 0x29($s0)
    MEM_B(0X29, ctx->r16) = 0;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    // sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // sh          $zero, 0x72($s0)
    MEM_H(0X72, ctx->r16) = 0;
    // sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
    // sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // sb          $zero, 0x27($s0)
    MEM_B(0X27, ctx->r16) = 0;
    // sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // sh          $v0, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r2;
    // sh          $zero, 0xAA($s0)
    MEM_H(0XAA, ctx->r16) = 0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_80059B94:
    // sb          $a3, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r7;
    // sb          $t1, 0x17($v1)
    MEM_B(0X17, ctx->r3) = ctx->r9;
    // sh          $t0, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r8;
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slti        $v0, $a3, 0x10
    ctx->r2 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80059B94
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80059B94;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r2;
    // sw          $a2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r6;
    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // ori         $v0, $zero, 0x53
    ctx->r2 = 0 | 0X53;
    // beq         $v1, $v0, L_80059BD8
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x70
        ctx->r2 = 0 | 0X70;
        goto L_80059BD8;
    }
    // ori         $v0, $zero, 0x70
    ctx->r2 = 0 | 0X70;
    // bne         $v1, $v0, L_80059C08
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80059C08;
    }
    // nop

L_80059BD8:
    // addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x7($a2)
    ctx->r3 = MEM_BU(0X7, ctx->r6);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80059C20
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $a2, 0x9
        ctx->r2 = ADD32(ctx->r6, 0X9);
        goto L_80059C20;
    }
    // addiu       $v0, $a2, 0x9
    ctx->r2 = ADD32(ctx->r6, 0X9);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x329C
    ctx->r4 = ADD32(ctx->r4, 0X329C);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80059E28
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80059E28;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80059C08:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x32B4
    ctx->r4 = ADD32(ctx->r4, 0X32B4);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_80059E28
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80059E28;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80059C20:
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x8($a2)
    ctx->r3 = MEM_BU(0X8, ctx->r6);
    // addiu       $v0, $a2, 0xA
    ctx->r2 = ADD32(ctx->r6, 0XA);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x9($a2)
    ctx->r2 = MEM_BU(0X9, ctx->r6);
    // lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(0X4, ctx->r16);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lui         $a2, 0x393
    ctx->r6 = S32(0X393 << 16);
    // addiu       $v1, $a1, 0x2
    ctx->r3 = ADD32(ctx->r5, 0X2);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lbu         $a0, 0x1($a1)
    ctx->r4 = MEM_BU(0X1, ctx->r5);
    // ori         $a2, $a2, 0x8700
    ctx->r6 = ctx->r6 | 0X8700;
    // addiu       $v1, $a1, 0x3
    ctx->r3 = ADD32(ctx->r5, 0X3);
    // sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80059C90
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80059C90;
    }
    // nop

    // break       7
    do_break(2147851404);
L_80059C90:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80059CA8
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80059CA8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a2, $at, L_80059CA8
    if (ctx->r6 != ctx->r1) {
        // nop
    
        goto L_80059CA8;
    }
    // nop

    // break       6
    do_break(2147851428);
L_80059CA8:
    // mflo        $a2
    ctx->r6 = lo;
    // mfhi        $v1
    ctx->r3 = hi;
    // sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80059CCC
    if (ctx->r2 == 0) {
        // addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
        goto L_80059CCC;
    }
    // addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // j           L_80059CD0
    // sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    goto L_80059CD0;
    // sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
L_80059CCC:
    // sw          $a2, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r6;
L_80059CD0:
    // sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10) << 16;
    // lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(0X84, ctx->r16);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $v1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // jal         0x8005BB50
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    sub_8005BB50(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    after_2:
    // lh          $a0, 0x4A($s0)
    ctx->r4 = MEM_H(0X4A, ctx->r16);
    // lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(0X84, ctx->r16);
    // nop

    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // lw          $a2, -0x5D30($a2)
    ctx->r6 = MEM_W(-0X5D30, ctx->r6);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // sw          $v0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r2;
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // sll         $a3, $a2, 4
    ctx->r7 = S32(ctx->r6) << 4;
    // sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7) << 2;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_80059D84
    if (ctx->r2 == 0) {
        // sw          $v1, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r3;
        goto L_80059D84;
    }
    // sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // divu        $zero, $v1, $a0
    lo = S32(U32(ctx->r3) / U32(ctx->r4)); hi = S32(U32(ctx->r3) % U32(ctx->r4));
    // bne         $a0, $zero, L_80059D70
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80059D70;
    }
    // nop

    // break       7
    do_break(2147851628);
L_80059D70:
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // sh          $v1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r3;
    // j           L_80059E1C
    // sh          $v1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r3;
    goto L_80059E1C;
    // sh          $v1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r3;
L_80059D84:
    // lh          $v1, 0x4A($s0)
    ctx->r3 = MEM_H(0X4A, ctx->r16);
    // lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(0X84, ctx->r16);
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
    // divu        $zero, $v0, $a1
    lo = S32(U32(ctx->r2) / U32(ctx->r5)); hi = S32(U32(ctx->r2) % U32(ctx->r5));
    // bne         $a1, $zero, L_80059DBC
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80059DBC;
    }
    // nop

    // break       7
    do_break(2147851704);
L_80059DBC:
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v1, 0x4A($s0)
    ctx->r3 = MEM_H(0X4A, ctx->r16);
    // lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(0X84, ctx->r16);
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
    // divu        $zero, $v0, $a1
    lo = S32(U32(ctx->r2) / U32(ctx->r5)); hi = S32(U32(ctx->r2) % U32(ctx->r5));
    // bne         $a1, $zero, L_80059DF8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80059DF8;
    }
    // nop

    // break       7
    do_break(2147851764);
L_80059DF8:
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
    // beq         $v0, $zero, L_80059E1C
    if (ctx->r2 == 0) {
        // sh          $a0, 0x70($s0)
        MEM_H(0X70, ctx->r16) = ctx->r4;
        goto L_80059E1C;
    }
    // sh          $a0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r4;
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r2;
L_80059E1C:
    // lhu         $v1, 0x70($s0)
    ctx->r3 = MEM_HU(0X70, ctx->r16);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sh          $v1, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r3;
L_80059E28:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
