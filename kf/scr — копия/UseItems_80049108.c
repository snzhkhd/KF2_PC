#include "recomp.h"
#include "disable_warnings.h"

void UseItems_80049108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // addiu       $v1, $s5, -0x52
    ctx->r3 = ADD32(ctx->r21, -0X52);
    // sltiu       $v0, $v1, 0x23
    ctx->r2 = ctx->r3 < 0X23 ? 1 : 0;
    // sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $zero, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = 0;
    // beq         $v0, $zero, L_80049CB8
    if (ctx->r2 == 0) {
        // addu        $s6, $a1, $zero
        ctx->r22 = ADD32(ctx->r5, 0);
        goto L_80049CB8;
    }
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x29CC
    ctx->r1 = ADD32(ctx->r1, 0X29CC);
    // addu        $at, $at, $v0
    gpr jr_addend_80049168;
    jr_addend_80049168 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80049168 >> 2) {
        case 0: goto L_80049AB8; break;
        case 1: goto L_80049CB8; break;
        case 2: goto L_800496C4; break;
        case 3: goto L_80049B48; break;
        case 4: goto L_80049C48; break;
        case 5: goto L_80049C90; break;
        case 6: goto L_800496E0; break;
        case 7: goto L_80049760; break;
        case 8: goto L_8004984C; break;
        case 9: goto L_8004985C; break;
        case 10: goto L_8004986C; break;
        case 11: goto L_8004987C; break;
        case 12: goto L_8004988C; break;
        case 13: goto L_80049CB8; break;
        case 14: goto L_80049CB8; break;
        case 15: goto L_80049CB8; break;
        case 16: goto L_80049CB8; break;
        case 17: goto L_80049170; break;
        case 18: goto L_80049170; break;
        case 19: goto L_80049170; break;
        case 20: goto L_80049170; break;
        case 21: goto L_80049604; break;
        case 22: goto L_80049170; break;
        case 23: goto L_80049CB8; break;
        case 24: goto L_80049170; break;
        case 25: goto L_80049170; break;
        case 26: goto L_80049170; break;
        case 27: goto L_80049170; break;
        case 28: goto L_80049CB8; break;
        case 29: goto L_8004935C; break;
        case 30: goto L_80049364; break;
        case 31: goto L_8004936C; break;
        case 32: goto L_80049234; break;
        case 33: goto L_8004923C; break;
        case 34: goto L_80049244; break;
        default: switch_error(__func__, 0x80049168, 0x800129CC);
    }
    // nop

L_80049170:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
L_80049178:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // ori         $a3, $zero, 0x6A4
    ctx->r7 = 0 | 0X6A4;
    // lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(0X2, ctx->r22);
    // ori         $v1, $zero, 0x200
    ctx->r3 = 0 | 0X200;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80038C0C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FindInteractableInCone(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80049CB8
    if (ctx->r16 == ctx->r2) {
        // sll         $v0, $s0, 4
        ctx->r2 = S32(ctx->r16) << 4;
        goto L_80049CB8;
    }
    // sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16) << 4;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80039348
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_80039348(rdram, ctx);
    goto after_1;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_1:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $s2, L_800491F8
    if (ctx->r3 == ctx->r18) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_800491F8;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004922C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8004922C;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_80049210
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_80049210;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // beq         $v1, $v0, L_80049214
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $zero, 0x4
        ctx->r4 = 0 | 0X4;
        goto L_80049214;
    }
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // j           L_80049178
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_80049178;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800491F8:
    // jal         0x80048768
    // nop

    sub_80048768(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $s2, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r18;
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049210:
    // lbu         $a0, 0x3E($s1)
    ctx->r4 = MEM_BU(0X3E, ctx->r17);
L_80049214:
    // jal         0x80035CC4
    // nop

    MessageQueuePush(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $s2, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r18;
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_8004922C:
    // j           L_80049178
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_80049178;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80049234:
    // j           L_80049248
    // ori         $s1, $zero, 0x28
    ctx->r17 = 0 | 0X28;
    goto L_80049248;
    // ori         $s1, $zero, 0x28
    ctx->r17 = 0 | 0X28;
L_8004923C:
    // j           L_80049248
    // ori         $s1, $zero, 0x2C
    ctx->r17 = 0 | 0X2C;
    goto L_80049248;
    // ori         $s1, $zero, 0x2C
    ctx->r17 = 0 | 0X2C;
L_80049244:
    // ori         $s1, $zero, 0x30
    ctx->r17 = 0 | 0X30;
L_80049248:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // ori         $a3, $zero, 0x6A4
    ctx->r7 = 0 | 0X6A4;
    // lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(0X2, ctx->r22);
    // ori         $v1, $zero, 0x200
    ctx->r3 = 0 | 0X200;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80038C0C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FindInteractableInCone(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80049CB8
    if (ctx->r16 == ctx->r2) {
        // sll         $v0, $s0, 4
        ctx->r2 = S32(ctx->r16) << 4;
        goto L_80049CB8;
    }
    // sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16) << 4;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // addiu       $a0, $a0, -0x6810
    ctx->r4 = ADD32(ctx->r4, -0X6810);
    // addu        $s0, $v0, $a0
    ctx->r16 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // ori         $v0, $zero, 0xBD
    ctx->r2 = 0 | 0XBD;
    // bne         $v1, $v0, L_80049330
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80049330;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v1, 0x38($s0)
    ctx->r3 = MEM_BU(0X38, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80049CB8
    if (ctx->r3 != ctx->r2) {
        // subu        $v1, $s0, $a0
        ctx->r3 = SUB32(ctx->r16, ctx->r4);
        goto L_80049CB8;
    }
    // subu        $v1, $s0, $a0
    ctx->r3 = SUB32(ctx->r16, ctx->r4);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2) << 8;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) << 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sb          $s5, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r21;
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79D8($v0)
    ctx->r2 = MEM_BU(0X79D8, ctx->r2);
    // nop

    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519E
    ctx->r1 = ADD32(ctx->r1, 0X519E);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v0, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r2;
    // jal         0x80049D2C
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    InventoryRemoveItem(rdram, ctx);
    goto after_5;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_5:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // jal         0x8004908C
    // sb          $zero, 0x40($a0)
    MEM_B(0X40, ctx->r4) = 0;
    sub_8004908C(rdram, ctx);
    goto after_6;
    // sb          $zero, 0x40($a0)
    MEM_B(0X40, ctx->r4) = 0;
    after_6:
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049330:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80039348
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_80039348(rdram, ctx);
    goto after_7;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_7:
    // ori         $v1, $zero, 0x3
    ctx->r3 = 0 | 0X3;
    // bne         $v0, $v1, L_80049CBC
    if (ctx->r2 != ctx->r3) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80049CBC;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lbu         $a0, 0x3E($s0)
    ctx->r4 = MEM_BU(0X3E, ctx->r16);
    // jal         0x80035CC4
    // nop

    MessageQueuePush(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004935C:
    // j           L_80049370
    // ori         $s1, $zero, 0x28
    ctx->r17 = 0 | 0X28;
    goto L_80049370;
    // ori         $s1, $zero, 0x28
    ctx->r17 = 0 | 0X28;
L_80049364:
    // j           L_80049370
    // ori         $s1, $zero, 0x2C
    ctx->r17 = 0 | 0X2C;
    goto L_80049370;
    // ori         $s1, $zero, 0x2C
    ctx->r17 = 0 | 0X2C;
L_8004936C:
    // ori         $s1, $zero, 0x30
    ctx->r17 = 0 | 0X30;
L_80049370:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79D8($v1)
    ctx->r3 = MEM_BU(0X79D8, ctx->r3);
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // beq         $v1, $v0, L_80049CB8
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80049CB8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // nop

    // beq         $v1, $v0, L_80049CBC
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80049CBC;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4B24
    ctx->r3 = ADD32(ctx->r3, -0X4B24);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_80049CBC
    if (ctx->r2 != 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80049CBC;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    // addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // jal         0x80039898
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    FadeScreenIn(rdram, ctx);
    goto after_9;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    after_9:
    // jal         0x8003B9A8
    // nop

    sub_8003B9A8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519E
    ctx->r1 = ADD32(ctx->r1, 0X519E);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lbu         $s2, 0x0($at)
    ctx->r18 = MEM_BU(0X0, ctx->r1);
L_800493F0:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800493F0
    if (ctx->r2 != 0) {
        // andi        $a2, $s2, 0xFF
        ctx->r6 = ctx->r18 & 0XFF;
        goto L_800493F0;
    }
    // andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79D8($v0)
    ctx->r2 = MEM_BU(0X79D8, ctx->r2);
    // nop

    // beq         $a2, $v0, L_80049430
    if (ctx->r6 == ctx->r2) {
        // addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
        goto L_80049430;
    }
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // j           L_80049438
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    goto L_80049438;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80049430:
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
L_80049438:
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x800166F8
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_800166F8(rdram, ctx);
    goto after_13;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_13:
L_80049458:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80049458
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80049458;
    }
    // nop

    // jal         0x80018190
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // addiu       $at, $at, 0x519C
    ctx->r1 = ADD32(ctx->r1, 0X519C);
    // addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // sll         $s0, $v0, 4
    ctx->r16 = S32(ctx->r2) << 4;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lh          $a0, 0x26($s0)
    ctx->r4 = MEM_H(0X26, ctx->r16);
    // jal         0x80014FAC
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    sub_80014FAC(rdram, ctx);
    goto after_17;
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_17:
    // ori         $a0, $zero, 0x400
    ctx->r4 = 0 | 0X400;
    // jal         0x8001565C
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    sub_8001565C(rdram, ctx);
    goto after_18;
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_18:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $zero, -0x4A6F($at)
    MEM_B(-0X4A6F, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A30($at)
    MEM_H(-0X4A30, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A32($at)
    MEM_H(-0X4A32, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A34($at)
    MEM_H(-0X4A34, ctx->r1) = 0;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A44
    ctx->r5 = ADD32(ctx->r5, -0X4A44);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4A4C
    ctx->r4 = ADD32(ctx->r4, -0X4A4C);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lwl         $v1, 0x7($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r5);
    // lwr         $v1, 0x4($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r5);
    // swl         $v0, 0x3($a0)
    do_swl(rdram, 0X3, ctx->r4, ctx->r2);
    // swr         $v0, 0x0($a0)
    do_swr(rdram, 0X0, ctx->r4, ctx->r2);
    // swl         $v1, 0x7($a0)
    do_swl(rdram, 0X7, ctx->r4, ctx->r3);
    // swr         $v1, 0x4($a0)
    do_swr(rdram, 0X4, ctx->r4, ctx->r3);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(0X20, ctx->r29);
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r2;
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(0X24, ctx->r29);
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r2;
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x26($s0)
    ctx->r2 = MEM_HU(0X26, ctx->r16);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v1, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r3;
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A42($at)
    MEM_H(-0X4A42, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A4A($at)
    MEM_H(-0X4A4A, ctx->r1) = ctx->r2;
    // jal         0x80039898
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    FadeScreenIn(rdram, ctx);
    goto after_19;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_19:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $v0, 0x858($v0)
    ctx->r2 = MEM_W(0X858, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800495B0
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_800495B0;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x101
    ctx->r5 = 0 | 0X101;
    // jal         0x80034C68
    // ori         $a2, $zero, 0x181
    ctx->r6 = 0 | 0X181;
    sub_80034C68(rdram, ctx);
    goto after_20;
    // ori         $a2, $zero, 0x181
    ctx->r6 = 0 | 0X181;
    after_20:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_800495B0:
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80039898
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    FadeScreenIn(rdram, ctx);
    goto after_21;
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    after_21:
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80033F94
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    SetFadeColor(rdram, ctx);
    goto after_22;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_22:
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // andi        $a3, $s2, 0xFF
    ctx->r7 = ctx->r18 & 0XFF;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x800166F8
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_800166F8(rdram, ctx);
    goto after_23;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_23:
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049604:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // ori         $a3, $zero, 0x6A4
    ctx->r7 = 0 | 0X6A4;
    // lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(0X2, ctx->r22);
    // ori         $v1, $zero, 0x200
    ctx->r3 = 0 | 0X200;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80038C0C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FindInteractableInCone(rdram, ctx);
    goto after_24;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_24:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80049CB8
    if (ctx->r16 == ctx->r2) {
        // sll         $v0, $s0, 4
        ctx->r2 = S32(ctx->r16) << 4;
        goto L_80049CB8;
    }
    // sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16) << 4;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // ori         $v0, $zero, 0xB8
    ctx->r2 = 0 | 0XB8;
    // bne         $v1, $v0, L_8004969C
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8004969C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lbu         $v1, 0x38($s0)
    ctx->r3 = MEM_BU(0X38, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80049CBC
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80049CBC;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $s5, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r21;
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v0, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r2;
    // jal         0x80049D2C
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    InventoryRemoveItem(rdram, ctx);
    goto after_25;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_25:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8004908C
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_8004908C(rdram, ctx);
    goto after_26;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_26:
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_8004969C:
    // jal         0x80039348
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_80039348(rdram, ctx);
    goto after_27;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_27:
    // ori         $v1, $zero, 0x3
    ctx->r3 = 0 | 0X3;
    // bne         $v0, $v1, L_80049CBC
    if (ctx->r2 != ctx->r3) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80049CBC;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lbu         $a0, 0x3E($s0)
    ctx->r4 = MEM_BU(0X3E, ctx->r16);
    // jal         0x80035CC4
    // nop

    MessageQueuePush(rdram, ctx);
    goto after_28;
    // nop

    after_28:
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800496C4:
    // ori         $v0, $zero, 0x4B0
    ctx->r2 = 0 | 0X4B0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD2($at)
    MEM_H(-0X4AD2, ctx->r1) = ctx->r2;
    // jal         0x80049D2C
    // ori         $a0, $zero, 0x54
    ctx->r4 = 0 | 0X54;
    InventoryRemoveItem(rdram, ctx);
    goto after_29;
    // ori         $a0, $zero, 0x54
    ctx->r4 = 0 | 0X54;
    after_29:
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800496E0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // ori         $a3, $zero, 0x6A4
    ctx->r7 = 0 | 0X6A4;
    // lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(0X2, ctx->r22);
    // ori         $v1, $zero, 0x200
    ctx->r3 = 0 | 0X200;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80038C0C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FindInteractableInCone(rdram, ctx);
    goto after_30;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_30:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80049750
    if (ctx->r16 == ctx->r2) {
        // sll         $v0, $s0, 4
        ctx->r2 = S32(ctx->r16) << 4;
        goto L_80049750;
    }
    // sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16) << 4;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // ori         $v0, $zero, 0x9D
    ctx->r2 = 0 | 0X9D;
    // bne         $v1, $v0, L_80049748
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80049748;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lbu         $a0, 0x38($a0)
    ctx->r4 = MEM_BU(0X38, ctx->r4);
    // jal         0x80039190
    // nop

    sub_80039190(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049748:
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v0, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r2;
L_80049750:
    // jal         0x8004878C
    // ori         $a0, $zero, 0x8
    ctx->r4 = 0 | 0X8;
    sub_8004878C(rdram, ctx);
    goto after_32;
    // ori         $a0, $zero, 0x8
    ctx->r4 = 0 | 0X8;
    after_32:
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049760:
    // lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // addiu       $s1, $s1, -0x6810
    ctx->r17 = ADD32(ctx->r17, -0X6810);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $s4, 0xF
    ctx->r20 = S32(0XF << 16);
    // ori         $s4, $s4, 0x423F
    ctx->r20 = ctx->r20 | 0X423F;
    // ori         $s3, $zero, 0x18B
    ctx->r19 = 0 | 0X18B;
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8004977C:
    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // nop

    // slti        $v0, $v1, 0x52
    ctx->r2 = SIGNED(ctx->r3) < 0X52 ? 1 : 0;
    // bne         $v0, $zero, L_800497E0
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x54
        ctx->r2 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
        goto L_800497E0;
    }
    // slti        $v0, $v1, 0x54
    ctx->r2 = SIGNED(ctx->r3) < 0X54 ? 1 : 0;
    // bne         $v0, $zero, L_800497AC
    if (ctx->r2 != 0) {
        // addiu       $a0, $s1, 0x14
        ctx->r4 = ADD32(ctx->r17, 0X14);
        goto L_800497AC;
    }
    // addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // slti        $v0, $v1, 0x61
    ctx->r2 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    // beq         $v0, $zero, L_800497E0
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x5A
        ctx->r2 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
        goto L_800497E0;
    }
    // slti        $v0, $v1, 0x5A
    ctx->r2 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
    // bne         $v0, $zero, L_800497E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800497E0;
    }
    // nop

L_800497AC:
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // ori         $a1, $zero, 0x61A8
    ctx->r5 = 0 | 0X61A8;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x4A64
    ctx->r6 = ADD32(ctx->r6, -0X4A64);
    // jal         0x80015B74
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80015B74(rdram, ctx);
    goto after_33;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_33:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bltz        $v1, L_800497E0
    if (SIGNED(ctx->r3) < 0) {
        // slt         $v0, $v1, $s4
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
        goto L_800497E0;
    }
    // slt         $v0, $v1, $s4
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // beq         $v0, $zero, L_800497E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800497E0;
    }
    // nop

    // addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_800497E0:
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s3, $v0, L_8004977C
    if (ctx->r19 != ctx->r2) {
        // addiu       $s1, $s1, 0x44
        ctx->r17 = ADD32(ctx->r17, 0X44);
        goto L_8004977C;
    }
    // addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    // beq         $s2, $zero, L_80049CB8
    if (ctx->r18 == 0) {
        // ori         $a0, $zero, 0x8009
        ctx->r4 = 0 | 0X8009;
        goto L_80049CB8;
    }
    // ori         $a0, $zero, 0x8009
    ctx->r4 = 0 | 0X8009;
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // addiu       $a1, $s2, 0x14
    ctx->r5 = ADD32(ctx->r18, 0X14);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(0X1C, ctx->r18);
    // ori         $a2, $zero, 0x6E
    ctx->r6 = 0 | 0X6E;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(0X18, ctx->r18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x59C4($v0)
    ctx->r2 = MEM_W(-0X59C4, ctx->r2);
    // ori         $a3, $zero, 0x61A8
    ctx->r7 = 0 | 0X61A8;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7148
    ctx->r2 = 0 | 0X7148;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80014414
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    PlayPositionalSound3D_Wrap(rdram, ctx);
    goto after_34;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_34:
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004984C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0xC30
    ctx->r4 = ADD32(ctx->r4, -0XC30);
    // j           L_80049898
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    goto L_80049898;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
L_8004985C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0xC28
    ctx->r4 = ADD32(ctx->r4, -0XC28);
    // j           L_80049898
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    goto L_80049898;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
L_8004986C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0xC20
    ctx->r4 = ADD32(ctx->r4, -0XC20);
    // j           L_80049898
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    goto L_80049898;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
L_8004987C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0xC18
    ctx->r4 = ADD32(ctx->r4, -0XC18);
    // j           L_80049898
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    goto L_80049898;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
L_8004988C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0xC10
    ctx->r4 = ADD32(ctx->r4, -0XC10);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
L_80049898:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x1900
    ctx->r5 = ADD32(ctx->r5, -0X1900);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
L_800498A4:
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // beq         $v1, $a3, L_80049CB8
    if (ctx->r3 == ctx->r7) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80049CB8;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $zero, L_800498A4
    if (ctx->r2 != 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_800498A4;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
    // ori         $a0, $zero, 0x15E
    ctx->r4 = 0 | 0X15E;
    // ori         $a1, $zero, 0xA
    ctx->r5 = 0 | 0XA;
    // lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // lhu         $a2, 0x12E($a2)
    ctx->r6 = MEM_HU(0X12E, ctx->r6);
    // jal         0x80038E6C
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    FindFreeOrOldestProjectileSlot(rdram, ctx);
    goto after_35;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_35:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // jal         0x80038004
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80038004(rdram, ctx);
    goto after_36;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_36:
    // jal         0x80049D2C
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    InventoryRemoveItem(rdram, ctx);
    goto after_37;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_37:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4A4C
    ctx->r16 = ADD32(ctx->r16, -0X4A4C);
    // sh          $s5, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r21;
    // sh          $zero, 0x28($s1)
    MEM_H(0X28, ctx->r17) = 0;
    // sh          $zero, 0x26($s1)
    MEM_H(0X26, ctx->r17) = 0;
    // sh          $zero, 0x24($s1)
    MEM_H(0X24, ctx->r17) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(0X0, ctx->r16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A4A($v0)
    ctx->r2 = MEM_H(-0X4A4A, ctx->r2);
    // ori         $a2, $zero, 0x5DC
    ctx->r6 = 0 | 0X5DC;
    // jal         0x80048874
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80048874(rdram, ctx);
    goto after_38;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_38:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0xC8
    ctx->r5 = 0 | 0XC8;
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(0X0, ctx->r16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A4A($v0)
    ctx->r2 = MEM_H(-0X4A4A, ctx->r2);
    // ori         $a2, $zero, 0x3E8
    ctx->r6 = 0 | 0X3E8;
    // jal         0x80048874
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80048874(rdram, ctx);
    goto after_39;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_39:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800499A8:
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8004892C
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    sub_8004892C(rdram, ctx);
    goto after_40;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_40:
    // sll         $a0, $s3, 6
    ctx->r4 = S32(ctx->r19) << 6;
    // lhu         $v0, 0x26($s1)
    ctx->r2 = MEM_HU(0X26, ctx->r17);
    // addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // jal         0x800601F4
    // sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    FixedSin(rdram, ctx);
    goto after_41;
    // sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    after_41:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // jal         0x80014988
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    ProcessCDAudioLoad(rdram, ctx);
    goto after_42;
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    after_42:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_43;
    // nop

    after_43:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_44;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_44:
    // slti        $v0, $s3, 0x1000
    ctx->r2 = SIGNED(ctx->r19) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_800499A8
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800499A8;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // j           L_80049A30
    // nop

    goto L_80049A30;
    // nop

L_80049A14:
    // jal         0x80014988
    // nop

    ProcessCDAudioLoad(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_47;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_47:
L_80049A30:
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // lhu         $v1, 0x26($s1)
    ctx->r3 = MEM_HU(0X26, ctx->r17);
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    // lh          $v0, 0x10($s1)
    ctx->r2 = MEM_H(0X10, ctx->r17);
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // bgtz        $v0, L_80049A14
    if (SIGNED(ctx->r2) > 0) {
        // sh          $v1, 0x26($s1)
        MEM_H(0X26, ctx->r17) = ctx->r3;
        goto L_80049A14;
    }
    // sh          $v1, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r3;
    // j           L_80049A78
    // sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
    goto L_80049A78;
    // sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
L_80049A5C:
    // jal         0x80014988
    // nop

    ProcessCDAudioLoad(rdram, ctx);
    goto after_48;
    // nop

    after_48:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_49;
    // nop

    after_49:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_50;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_50:
L_80049A78:
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // lhu         $v1, 0x26($s1)
    ctx->r3 = MEM_HU(0X26, ctx->r17);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80049A5C
    if (ctx->r2 != 0) {
        // sh          $v1, 0x26($s1)
        MEM_H(0X26, ctx->r17) = ctx->r3;
        goto L_80049A5C;
    }
    // sh          $v1, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r3;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // jal         0x80035CC4
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    MessageQueuePush(rdram, ctx);
    goto after_51;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    after_51:
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049AB8:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // jal         0x800487AC
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    IsFacingFountainTile(rdram, ctx);
    goto after_52;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_52:
    // bne         $v0, $zero, L_80049B20
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80049B20;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // ori         $a3, $zero, 0x6A4
    ctx->r7 = 0 | 0X6A4;
    // lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(0X2, ctx->r22);
    // ori         $v1, $zero, 0x200
    ctx->r3 = 0 | 0X200;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80038C0C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    FindInteractableInCone(rdram, ctx);
    goto after_53;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_53:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80049CB8
    if (ctx->r16 == ctx->r2) {
        // sll         $v0, $s0, 4
        ctx->r2 = S32(ctx->r16) << 4;
        goto L_80049CB8;
    }
    // sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16) << 4;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // addiu       $at, $at, -0x680A
    ctx->r1 = ADD32(ctx->r1, -0X680A);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // ori         $v0, $zero, 0xC3
    ctx->r2 = 0 | 0XC3;
    // bne         $v1, $v0, L_80049CBC
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80049CBC;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049B20:
    // jal         0x80049D6C
    // ori         $a0, $zero, 0x4D
    ctx->r4 = 0 | 0X4D;
    InventoryAddItem(rdram, ctx);
    goto after_54;
    // ori         $a0, $zero, 0x4D
    ctx->r4 = 0 | 0X4D;
    after_54:
    // bne         $v0, $zero, L_80049C80
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80049C80;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    MessageQueuePush(rdram, ctx);
    goto after_55;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    after_55:
    // jal         0x80049D2C
    // ori         $a0, $zero, 0x52
    ctx->r4 = 0 | 0X52;
    InventoryRemoveItem(rdram, ctx);
    goto after_56;
    // ori         $a0, $zero, 0x52
    ctx->r4 = 0 | 0X52;
    after_56:
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049B48:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A14($v0)
    ctx->r2 = MEM_HU(-0X4A14, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80049B60
    if (ctx->r2 != 0) {
        // ori         $s3, $zero, 0x2
        ctx->r19 = 0 | 0X2;
        goto L_80049B60;
    }
    // ori         $s3, $zero, 0x2
    ctx->r19 = 0 | 0X2;
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
L_80049B60:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // ori         $a3, $zero, 0x1F40
    ctx->r7 = 0 | 0X1F40;
    // lh          $a1, 0x2($s6)
    ctx->r5 = MEM_H(0X2, ctx->r22);
    // lh          $a2, 0x0($s6)
    ctx->r6 = MEM_H(0X0, ctx->r22);
    // ori         $v0, $zero, 0x1F4
    ctx->r2 = 0 | 0X1F4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x8003D200
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_8003D200(rdram, ctx);
    goto after_57;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_57:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_80049BB8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80049BB8;
    }
    // nop

    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // bne         $v0, $s3, L_80049BB8
    if (ctx->r2 != ctx->r19) {
        // ori         $a0, $zero, 0x6
        ctx->r4 = 0 | 0X6;
        goto L_80049BB8;
    }
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(0X1, ctx->r3);
    // j           L_80049C74
    // addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
    goto L_80049C74;
    // addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
L_80049BB8:
    // lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // addiu       $s2, $s2, -0x6810
    ctx->r18 = ADD32(ctx->r18, -0X6810);
    // ori         $s1, $zero, 0x18B
    ctx->r17 = 0 | 0X18B;
    // addiu       $s0, $s2, 0x39
    ctx->r16 = ADD32(ctx->r18, 0X39);
L_80049BC8:
    // lhu         $v1, -0x33($s0)
    ctx->r3 = MEM_HU(-0X33, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // addiu       $at, $at, 0x79F0
    ctx->r1 = ADD32(ctx->r1, 0X79F0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // ori         $v0, $zero, 0xE2
    ctx->r2 = 0 | 0XE2;
    // bne         $v1, $v0, L_80049C30
    if (ctx->r3 != ctx->r2) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80049C30;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(0X7, ctx->r16);
    // nop

    // bne         $v0, $s3, L_80049C30
    if (ctx->r2 != ctx->r19) {
        // ori         $v0, $zero, 0x8000
        ctx->r2 = 0 | 0X8000;
        goto L_80049C30;
    }
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // lw          $a0, -0x25($s0)
    ctx->r4 = MEM_W(-0X25, ctx->r16);
    // lw          $a1, -0x1D($s0)
    ctx->r5 = MEM_W(-0X1D, ctx->r16);
    // lbu         $a2, -0x1($s0)
    ctx->r6 = MEM_BU(-0X1, ctx->r16);
    // lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(0X0, ctx->r16);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // jal         0x8003955C
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    sub_8003955C(rdram, ctx);
    goto after_58;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    after_58:
    // bne         $v0, $zero, L_80049C64
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x6
        ctx->r4 = 0 | 0X6;
        goto L_80049C64;
    }
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
L_80049C30:
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_80049BC8
    if (ctx->r17 != ctx->r2) {
        // addiu       $s2, $s2, 0x44
        ctx->r18 = ADD32(ctx->r18, 0X44);
        goto L_80049BC8;
    }
    // addiu       $s2, $s2, 0x44
    ctx->r18 = ADD32(ctx->r18, 0X44);
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049C48:
    // jal         0x80049D2C
    // ori         $a0, $zero, 0x56
    ctx->r4 = 0 | 0X56;
    InventoryRemoveItem(rdram, ctx);
    goto after_59;
    // ori         $a0, $zero, 0x56
    ctx->r4 = 0 | 0X56;
    after_59:
    // ori         $v0, $zero, 0x384
    ctx->r2 = 0 | 0X384;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4AD0($at)
    MEM_H(-0X4AD0, ctx->r1) = ctx->r2;
    // j           L_80049C80
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049C80;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049C64:
    // lhu         $a1, 0x3A($s2)
    ctx->r5 = MEM_HU(0X3A, ctx->r18);
    // nop

    // addiu       $a1, $a1, 0x1FE
    ctx->r5 = ADD32(ctx->r5, 0X1FE);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_80049C74:
    // jal         0x800378A0
    // nop

    LoadPopupsTexturOrTalk(rdram, ctx);
    goto after_60;
    // nop

    after_60:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049C80:
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v0, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r2;
    // j           L_80049CBC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    goto L_80049CBC;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049C90:
    // jal         0x80049D2C
    // ori         $a0, $zero, 0x57
    ctx->r4 = 0 | 0X57;
    InventoryRemoveItem(rdram, ctx);
    goto after_61;
    // ori         $a0, $zero, 0x57
    ctx->r4 = 0 | 0X57;
    after_61:
    // ori         $v0, $zero, 0x384
    ctx->r2 = 0 | 0X384;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4ACE($at)
    MEM_H(-0X4ACE, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sw          $v0, 0x5198($at)
    MEM_W(0X5198, ctx->r1) = ctx->r2;
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_62;
    // nop

    after_62:
L_80049CB8:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_80049CBC:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_63;
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_63:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x5198($v0)
    ctx->r2 = MEM_W(0X5198, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80049CF4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80049CF4;
    }
    // nop

    // jal         0x80035CC4
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    MessageQueuePush(rdram, ctx);
    goto after_64;
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    after_64:
L_80049CF4:
    // jal         0x80027C38
    // nop

    Player_ResetMovement(rdram, ctx);
    goto after_65;
    // nop

    after_65:
    // lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
