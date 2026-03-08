#include "recomp.h"
#include "disable_warnings.h"

void sub_8001AEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x370
    ctx->r29 = ADD32(ctx->r29, -0X370);
    // sw          $s6, 0x360($sp)
    MEM_W(0X360, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sw          $fp, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->r30;
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x334($sp)
    MEM_W(0X334, ctx->r29) = ctx->r2;
    // sltiu       $v0, $s6, 0x9
    ctx->r2 = ctx->r22 < 0X9 ? 1 : 0;
    // sw          $ra, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r31;
    // sw          $s7, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->r23;
    // sw          $s5, 0x35C($sp)
    MEM_W(0X35C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r19;
    // sw          $s2, 0x350($sp)
    MEM_W(0X350, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x348($sp)
    MEM_W(0X348, ctx->r29) = ctx->r16;
    // beq         $v0, $zero, L_8001B060
    if (ctx->r2 == 0) {
        // sw          $zero, 0x330($sp)
        MEM_W(0X330, ctx->r29) = 0;
        goto L_8001B060;
    }
    // sw          $zero, 0x330($sp)
    MEM_W(0X330, ctx->r29) = 0;
    // sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x11B4
    ctx->r1 = ADD32(ctx->r1, 0X11B4);
    // addu        $at, $at, $v0
    gpr jr_addend_8001AF58;
    jr_addend_8001AF58 = ctx->r2;
    jr_addend_8001AF58;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8001AF58 >> 2) {
        case 0: goto L_8001AF60; break;
        case 1: goto L_8001B060; break;
        case 2: goto L_8001AF74; break;
        case 3: goto L_8001AF88; break;
        case 4: goto L_8001AF9C; break;
        case 5: goto L_8001AFB0; break;
        case 6: goto L_8001AFC4; break;
        case 7: goto L_8001AFD8; break;
        case 8: goto L_8001AFD8; break;
        default: switch_error(__func__, 0x8001AF58, 0x800111B4);
    }
    // nop

L_8001AF60:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4AA1($s4)
    ctx->r20 = MEM_BU(-0X4AA1, ctx->r20);
    // j           L_8001B060
    // ori         $v1, $zero, 0x14
    ctx->r3 = 0 | 0X14;
    goto L_8001B060;
    // ori         $v1, $zero, 0x14
    ctx->r3 = 0 | 0X14;
L_8001AF74:
    // ori         $t0, $zero, 0x22
    ctx->r8 = 0 | 0X22;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A7A($s4)
    ctx->r20 = MEM_BU(-0X4A7A, ctx->r20);
    // j           L_8001B060
    // ori         $v1, $zero, 0x28
    ctx->r3 = 0 | 0X28;
    goto L_8001B060;
    // ori         $v1, $zero, 0x28
    ctx->r3 = 0 | 0X28;
L_8001AF88:
    // ori         $t0, $zero, 0x15
    ctx->r8 = 0 | 0X15;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A7C($s4)
    ctx->r20 = MEM_BU(-0X4A7C, ctx->r20);
    // j           L_8001B060
    // ori         $v1, $zero, 0x1B
    ctx->r3 = 0 | 0X1B;
    goto L_8001B060;
    // ori         $v1, $zero, 0x1B
    ctx->r3 = 0 | 0X1B;
L_8001AF9C:
    // ori         $t0, $zero, 0x1C
    ctx->r8 = 0 | 0X1C;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A7B($s4)
    ctx->r20 = MEM_BU(-0X4A7B, ctx->r20);
    // j           L_8001B060
    // ori         $v1, $zero, 0x21
    ctx->r3 = 0 | 0X21;
    goto L_8001B060;
    // ori         $v1, $zero, 0x21
    ctx->r3 = 0 | 0X21;
L_8001AFB0:
    // ori         $t0, $zero, 0x29
    ctx->r8 = 0 | 0X29;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A79($s4)
    ctx->r20 = MEM_BU(-0X4A79, ctx->r20);
    // j           L_8001B060
    // ori         $v1, $zero, 0x2E
    ctx->r3 = 0 | 0X2E;
    goto L_8001B060;
    // ori         $v1, $zero, 0x2E
    ctx->r3 = 0 | 0X2E;
L_8001AFC4:
    // ori         $t0, $zero, 0x2F
    ctx->r8 = 0 | 0X2F;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A78($s4)
    ctx->r20 = MEM_BU(-0X4A78, ctx->r20);
    // j           L_8001B060
    // ori         $v1, $zero, 0x34
    ctx->r3 = 0 | 0X34;
    goto L_8001B060;
    // ori         $v1, $zero, 0x34
    ctx->r3 = 0 | 0X34;
L_8001AFD8:
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // bne         $s6, $v0, L_8001AFF4
    if (ctx->r22 != ctx->r2) {
        // nop
    
        goto L_8001AFF4;
    }
    // nop

    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A77($s4)
    ctx->r20 = MEM_BU(-0X4A77, ctx->r20);
    // j           L_8001AFFC
    // nop

    goto L_8001AFFC;
    // nop

L_8001AFF4:
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // lbu         $s4, -0x4A76($s4)
    ctx->r20 = MEM_BU(-0X4A76, ctx->r20);
L_8001AFFC:
    // bne         $s6, $v0, L_8001B014
    if (ctx->r22 != ctx->r2) {
        // nop
    
        goto L_8001B014;
    }
    // nop

    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // lbu         $t2, -0x4A76($t2)
    ctx->r10 = MEM_BU(-0X4A76, ctx->r10);
    // j           L_8001B024
    // sb          $t2, 0x338($sp)
    MEM_B(0X338, ctx->r29) = ctx->r10;
    goto L_8001B024;
    // sb          $t2, 0x338($sp)
    MEM_B(0X338, ctx->r29) = ctx->r10;
L_8001B014:
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // lbu         $t2, -0x4A77($t2)
    ctx->r10 = MEM_BU(-0X4A77, ctx->r10);
    // nop

    // sb          $t2, 0x338($sp)
    MEM_B(0X338, ctx->r29) = ctx->r10;
L_8001B024:
    // lbu         $v1, 0x338($sp)
    ctx->r3 = MEM_BU(0X338, ctx->r29);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8001B05C
    if (ctx->r3 == ctx->r2) {
        // ori         $t0, $zero, 0x35
        ctx->r8 = 0 | 0X35;
        goto L_8001B05C;
    }
    // ori         $t0, $zero, 0x35
    ctx->r8 = 0 | 0X35;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
L_8001B05C:
    // ori         $v1, $zero, 0x3B
    ctx->r3 = 0 | 0X3B;
L_8001B060:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x2190
    ctx->r4 = ADD32(ctx->r4, -0X2190);
    // addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $s1, $sp, 0x2F0
    ctx->r17 = ADD32(ctx->r29, 0X2F0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addiu       $s5, $sp, 0x310
    ctx->r21 = ADD32(ctx->r29, 0X310);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // jal         0x80019CD0
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    GetInventoryItems(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16) << 1;
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // addu        $t0, $s1, $s0
    ctx->r8 = ADD32(ctx->r17, ctx->r16);
    // addu        $t1, $s5, $s0
    ctx->r9 = ADD32(ctx->r21, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7) << 3;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x667D
    ctx->r1 = ADD32(ctx->r1, -0X667D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6680
    ctx->r1 = ADD32(ctx->r1, -0X6680);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6679
    ctx->r1 = ADD32(ctx->r1, -0X6679);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t2, 0x0($at)
    ctx->r10 = do_lwl(rdram, ctx->r10, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x667C
    ctx->r1 = ADD32(ctx->r1, -0X667C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t2, 0x0($at)
    ctx->r10 = do_lwr(rdram, ctx->r10, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6675
    ctx->r1 = ADD32(ctx->r1, -0X6675);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t3, 0x0($at)
    ctx->r11 = do_lwl(rdram, ctx->r11, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6678
    ctx->r1 = ADD32(ctx->r1, -0X6678);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t3, 0x0($at)
    ctx->r11 = do_lwr(rdram, ctx->r11, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6671
    ctx->r1 = ADD32(ctx->r1, -0X6671);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t4, 0x0($at)
    ctx->r12 = do_lwl(rdram, ctx->r12, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6674
    ctx->r1 = ADD32(ctx->r1, -0X6674);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t4, 0x0($at)
    ctx->r12 = do_lwr(rdram, ctx->r12, 0X0, ctx->r1);
    // swl         $v1, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r3);
    // swr         $v1, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r3);
    // swl         $t2, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r10);
    // swr         $t2, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r10);
    // swl         $t3, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r11);
    // swr         $t3, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r11);
    // swl         $t4, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r12);
    // swr         $t4, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r12);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x666D
    ctx->r1 = ADD32(ctx->r1, -0X666D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6670
    ctx->r1 = ADD32(ctx->r1, -0X6670);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6669
    ctx->r1 = ADD32(ctx->r1, -0X6669);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t2, 0x0($at)
    ctx->r10 = do_lwl(rdram, ctx->r10, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x666C
    ctx->r1 = ADD32(ctx->r1, -0X666C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t2, 0x0($at)
    ctx->r10 = do_lwr(rdram, ctx->r10, 0X0, ctx->r1);
    // swl         $v1, 0x13($a3)
    do_swl(rdram, 0X13, ctx->r7, ctx->r3);
    // swr         $v1, 0x10($a3)
    do_swr(rdram, 0X10, ctx->r7, ctx->r3);
    // swl         $t2, 0x17($a3)
    do_swl(rdram, 0X17, ctx->r7, ctx->r10);
    // swr         $t2, 0x14($a3)
    do_swr(rdram, 0X14, ctx->r7, ctx->r10);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // jal         0x800249BC
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    InitListWidget(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    after_1:
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // blez        $s0, L_8001B22C
    if (SIGNED(ctx->r16) <= 0) {
        // sb          $v0, 0x3B($sp)
        MEM_B(0X3B, ctx->r29) = ctx->r2;
        goto L_8001B22C;
    }
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_8001B200:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $a0, L_8001B21C
    if (ctx->r2 != ctx->r4) {
        // nop
    
        goto L_8001B21C;
    }
    // nop

    // addu        $fp, $s3, $zero
    ctx->r30 = ADD32(ctx->r19, 0);
    // addiu       $v1, $a3, 0x28
    ctx->r3 = ADD32(ctx->r7, 0X28);
    // ori         $s3, $zero, 0x28
    ctx->r19 = 0 | 0X28;
L_8001B21C:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slt         $v0, $s3, $s0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8001B200
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8001B200;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001B22C:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80024A8C
    // andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    ListNavigating(rdram, ctx);
    goto after_2;
    // andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    after_2:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001B268
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x63
        ctx->r18 = ADD32(0, -0X63);
        goto L_8001B268;
    }
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $a0, 0x310($v0)
    ctx->r4 = MEM_BU(0X310, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // bne         $v0, $zero, L_8001B44C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001B44C;
    }
    // nop

L_8001B268:
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // addiu       $s1, $sp, 0x310
    ctx->r17 = ADD32(ctx->r29, 0X310);
L_8001B270:
    // lw          $v0, 0x330($sp)
    ctx->r2 = MEM_W(0X330, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001B290
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001B290;
    }
    // nop

    // lw          $v0, 0x334($sp)
    ctx->r2 = MEM_W(0X334, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001B298
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001B298;
    }
    // nop

L_8001B290:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8001B298:
    // lw          $v0, 0x330($sp)
    ctx->r2 = MEM_W(0X330, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001B2D4
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001B2D4;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // ori         $a2, $zero, 0x5
    ctx->r6 = 0 | 0X5;
    // andi        $s0, $s7, 0xFF
    ctx->r16 = ctx->r23 & 0XFF;
    // jal         0x80022468
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    ShowEquipmentMenu(rdram, ctx);
    goto after_5;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_5:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001B2D0
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x334($sp)
        MEM_W(0X334, ctx->r29) = ctx->r2;
        goto L_8001B2D0;
    }
    // sw          $v0, 0x334($sp)
    MEM_W(0X334, ctx->r29) = ctx->r2;
    // j           L_8001B2D4
    // sw          $s2, 0x334($sp)
    MEM_W(0X334, ctx->r29) = ctx->r18;
    goto L_8001B2D4;
    // sw          $s2, 0x334($sp)
    MEM_W(0X334, ctx->r29) = ctx->r18;
L_8001B2D0:
    // sw          $s0, 0x334($sp)
    MEM_W(0X334, ctx->r29) = ctx->r16;
L_8001B2D4:
    // lw          $v0, 0x334($sp)
    ctx->r2 = MEM_W(0X334, ctx->r29);
    // nop

    // bne         $v0, $s2, L_8001B35C
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001B35C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0x330
    ctx->r6 = ADD32(ctx->r29, 0X330);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x334
    ctx->r7 = ADD32(ctx->r29, 0X334);
    ProcessListNavigation(rdram, ctx);
    goto after_6;
    // addiu       $a3, $sp, 0x334
    ctx->r7 = ADD32(ctx->r29, 0X334);
    after_6:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // lw          $v1, 0x330($sp)
    ctx->r3 = MEM_W(0X330, ctx->r29);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lbu         $s7, 0x0($v0)
    ctx->r23 = MEM_BU(0X0, ctx->r2);
    // bne         $v1, $s4, L_8001B314
    if (ctx->r3 != ctx->r20) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_8001B314;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_7:
L_8001B314:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001B338
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001B338;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_9;
    // andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    after_9:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8001B338:
    // jal         0x800228B4
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    RenderItemList(rdram, ctx);
    goto after_10;
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    after_10:
    // jal         0x80024620
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_11;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_11:
    // slti        $v0, $s3, 0x2
    ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001B314
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001B314;
    }
    // nop

    // j           L_8001B270
    // nop

    goto L_8001B270;
    // nop

L_8001B35C:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lw          $v1, 0x334($sp)
    ctx->r3 = MEM_W(0X334, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001B404
    if (ctx->r3 == ctx->r2) {
        // sltiu       $v0, $s6, 0x9
        ctx->r2 = ctx->r22 < 0X9 ? 1 : 0;
        goto L_8001B404;
    }
    // sltiu       $v0, $s6, 0x9
    ctx->r2 = ctx->r22 < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8001B404
    if (ctx->r2 == 0) {
        // sll         $v0, $s6, 2
        ctx->r2 = S32(ctx->r22) << 2;
        goto L_8001B404;
    }
    // sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x11DC
    ctx->r1 = ADD32(ctx->r1, 0X11DC);
    // addu        $at, $at, $v0
    gpr jr_addend_8001B390;
    jr_addend_8001B390 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8001B390 >> 2) {
        case 0: goto L_8001B398; break;
        case 1: goto L_8001B404; break;
        case 2: goto L_8001B3AC; break;
        case 3: goto L_8001B3B8; break;
        case 4: goto L_8001B3C4; break;
        case 5: goto L_8001B3D0; break;
        case 6: goto L_8001B3DC; break;
        case 7: goto L_8001B3E8; break;
        case 8: goto L_8001B3F4; break;
        default: switch_error(__func__, 0x8001B390, 0x800111DC);
    }
    // nop

L_8001B398:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // jal         0x8002810C
    // nop

    sub_8002810C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // j           L_8001B408
    // addiu       $v0, $s6, -0x7
    ctx->r2 = ADD32(ctx->r22, -0X7);
    goto L_8001B408;
    // addiu       $v0, $s6, -0x7
    ctx->r2 = ADD32(ctx->r22, -0X7);
L_8001B3AC:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // j           L_8001B3FC
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    goto L_8001B3FC;
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
L_8001B3B8:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // j           L_8001B3FC
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_8001B3FC;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8001B3C4:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // j           L_8001B3FC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    goto L_8001B3FC;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
L_8001B3D0:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // j           L_8001B3FC
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    goto L_8001B3FC;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
L_8001B3DC:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // j           L_8001B3FC
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    goto L_8001B3FC;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
L_8001B3E8:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // j           L_8001B3FC
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    goto L_8001B3FC;
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
L_8001B3F4:
    // lbu         $a0, 0x334($sp)
    ctx->r4 = MEM_BU(0X334, ctx->r29);
    // ori         $a1, $zero, 0x6
    ctx->r5 = 0 | 0X6;
L_8001B3FC:
    // jal         0x80027ED0
    // nop

    sub_80027ED0(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_8001B404:
    // addiu       $v0, $s6, -0x7
    ctx->r2 = ADD32(ctx->r22, -0X7);
L_8001B408:
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8001B44C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_8001B44C;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lbu         $v1, 0x338($sp)
    ctx->r3 = MEM_BU(0X338, ctx->r29);
    // nop

    // beq         $v1, $v0, L_8001B44C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001B44C;
    }
    // nop

    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
L_8001B44C:
    // lw          $ra, 0x36C($sp)
    ctx->r31 = MEM_W(0X36C, ctx->r29);
    // lw          $fp, 0x368($sp)
    ctx->r30 = MEM_W(0X368, ctx->r29);
    // lw          $s7, 0x364($sp)
    ctx->r23 = MEM_W(0X364, ctx->r29);
    // lw          $s6, 0x360($sp)
    ctx->r22 = MEM_W(0X360, ctx->r29);
    // lw          $s5, 0x35C($sp)
    ctx->r21 = MEM_W(0X35C, ctx->r29);
    // lw          $s4, 0x358($sp)
    ctx->r20 = MEM_W(0X358, ctx->r29);
    // lw          $s3, 0x354($sp)
    ctx->r19 = MEM_W(0X354, ctx->r29);
    // lw          $s2, 0x350($sp)
    ctx->r18 = MEM_W(0X350, ctx->r29);
    // lw          $s1, 0x34C($sp)
    ctx->r17 = MEM_W(0X34C, ctx->r29);
    // lw          $s0, 0x348($sp)
    ctx->r16 = MEM_W(0X348, ctx->r29);
    // addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
    // jr          $ra
    // nop

    return;
    // nop

;}
