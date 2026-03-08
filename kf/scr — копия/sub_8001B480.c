#include "recomp.h"
#include "disable_warnings.h"

void sub_8001B480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x2C0
    ctx->r29 = ADD32(ctx->r29, -0X2C0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1900
    ctx->r4 = ADD32(ctx->r4, -0X1900);
    // sw          $s1, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // sw          $s2, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r18;
    // addiu       $s2, $sp, 0x230
    ctx->r18 = ADD32(ctx->r29, 0X230);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $s4, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r20;
    // addiu       $s4, $sp, 0x280
    ctx->r20 = ADD32(ctx->r29, 0X280);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $ra, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r19;
    // sw          $s0, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->r16;
    // sw          $zero, 0x298($sp)
    MEM_W(0X298, ctx->r29) = 0;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8001A9E4
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    CollectAvailableSpells(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16) << 1;
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16) << 2;
    // addu        $t1, $s4, $s0
    ctx->r9 = ADD32(ctx->r20, ctx->r16);
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
    // addu        $a3, $s1, $a3
    ctx->r7 = ADD32(ctx->r17, ctx->r7);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
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
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x218($t0)
    MEM_W(0X218, ctx->r8) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // jal         0x800249BC
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    InitListWidget(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    after_1:
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x83
    ctx->r2 = 0 | 0X83;
    // sb          $v0, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // blez        $s0, L_8001B69C
    if (SIGNED(ctx->r16) <= 0) {
        // sb          $v0, 0x3B($sp)
        MEM_B(0X3B, ctx->r29) = ctx->r2;
        goto L_8001B69C;
    }
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8001B660:
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4AA5($v0)
    ctx->r2 = MEM_BU(-0X4AA5, ctx->r2);
    // nop

    // bne         $v1, $v0, L_8001B68C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001B68C;
    }
    // nop

    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80024A8C
    // andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    ListNavigating(rdram, ctx);
    goto after_2;
    // andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    after_2:
    // addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // ori         $s3, $zero, 0x14
    ctx->r19 = 0 | 0X14;
L_8001B68C:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slt         $v0, $s3, $s0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8001B660
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8001B660;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8001B69C:
    // addiu       $s0, $zero, -0x63
    ctx->r16 = ADD32(0, -0X63);
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
L_8001B6A4:
    // lw          $v0, 0x298($sp)
    ctx->r2 = MEM_W(0X298, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001B6C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001B6C4;
    }
    // nop

    // lw          $v0, 0x29C($sp)
    ctx->r2 = MEM_W(0X29C, ctx->r29);
    // nop

    // beq         $v0, $s0, L_8001B6CC
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_8001B6CC;
    }
    // nop

L_8001B6C4:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8001B6CC:
    // lw          $v0, 0x298($sp)
    ctx->r2 = MEM_W(0X298, ctx->r29);
    // nop

    // bne         $v0, $s1, L_8001B718
    if (ctx->r2 != ctx->r17) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001B718;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
    // jal         0x80022468
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    ShowEquipmentMenu(rdram, ctx);
    goto after_4;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    after_4:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001B700
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x29C($sp)
        MEM_W(0X29C, ctx->r29) = ctx->r2;
        goto L_8001B700;
    }
    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
    // j           L_8001B718
    // sw          $s0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r16;
    goto L_8001B718;
    // sw          $s0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r16;
L_8001B700:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $v0, 0x280($v0)
    ctx->r2 = MEM_BU(0X280, ctx->r2);
    // nop

    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
L_8001B718:
    // lw          $v0, 0x29C($sp)
    ctx->r2 = MEM_W(0X29C, ctx->r29);
    // nop

    // bne         $v0, $s0, L_8001B780
    if (ctx->r2 != ctx->r16) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001B780;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x298
    ctx->r6 = ADD32(ctx->r29, 0X298);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x29C
    ctx->r7 = ADD32(ctx->r29, 0X29C);
    ProcessListNavigation(rdram, ctx);
    goto after_5;
    // addiu       $a3, $sp, 0x29C
    ctx->r7 = ADD32(ctx->r29, 0X29C);
    after_5:
    // lw          $v0, 0x298($sp)
    ctx->r2 = MEM_W(0X298, ctx->r29);
    // nop

    // bne         $v0, $s1, L_8001B750
    if (ctx->r2 != ctx->r17) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_8001B750;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_6:
L_8001B750:
    // jal         0x800244E0
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_7;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_7:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x800228B4
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    RenderItemList(rdram, ctx);
    goto after_8;
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    after_8:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // slti        $v0, $s3, 0x2
    ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001B750
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001B750;
    }
    // nop

    // j           L_8001B6A4
    // nop

    goto L_8001B6A4;
    // nop

L_8001B780:
    // lw          $v1, 0x29C($sp)
    ctx->r3 = MEM_W(0X29C, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001B79C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001B79C;
    }
    // nop

    // lbu         $a0, 0x29C($sp)
    ctx->r4 = MEM_BU(0X29C, ctx->r29);
    // jal         0x80027E70
    // nop

    SsSetAutoKeyOffMode(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_8001B79C:
    // lw          $ra, 0x2BC($sp)
    ctx->r31 = MEM_W(0X2BC, ctx->r29);
    // lw          $s4, 0x2B8($sp)
    ctx->r20 = MEM_W(0X2B8, ctx->r29);
    // lw          $s3, 0x2B4($sp)
    ctx->r19 = MEM_W(0X2B4, ctx->r29);
    // lw          $s2, 0x2B0($sp)
    ctx->r18 = MEM_W(0X2B0, ctx->r29);
    // lw          $s1, 0x2AC($sp)
    ctx->r17 = MEM_W(0X2AC, ctx->r29);
    // lw          $s0, 0x2A8($sp)
    ctx->r16 = MEM_W(0X2A8, ctx->r29);
    // addiu       $sp, $sp, 0x2C0
    ctx->r29 = ADD32(ctx->r29, 0X2C0);
    // jr          $ra
    // nop

    return;
    // nop

;}
