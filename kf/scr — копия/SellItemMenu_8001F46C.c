#include "recomp.h"
#include "disable_warnings.h"

void SellItemMenu_8001F46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xE90
    ctx->r29 = ADD32(ctx->r29, -0XE90);
    // sw          $s4, 0xE78($sp)
    MEM_W(0XE78, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s7, 0xE84($sp)
    MEM_W(0XE84, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x2190
    ctx->r4 = ADD32(ctx->r4, -0X2190);
    // sw          $s3, 0xE74($sp)
    MEM_W(0XE74, ctx->r29) = ctx->r19;
    // addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sw          $s2, 0xE70($sp)
    MEM_W(0XE70, ctx->r29) = ctx->r18;
    // addiu       $s2, $sp, 0xB90
    ctx->r18 = ADD32(ctx->r29, 0XB90);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $s5, 0xE7C($sp)
    MEM_W(0XE7C, ctx->r29) = ctx->r21;
    // addiu       $s5, $sp, 0xDE8
    ctx->r21 = ADD32(ctx->r29, 0XDE8);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0xE64($sp)
    MEM_W(0XE64, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x77
    ctx->r2 = 0 | 0X77;
    // sw          $ra, 0xE88($sp)
    MEM_W(0XE88, ctx->r29) = ctx->r31;
    // sw          $s6, 0xE80($sp)
    MEM_W(0XE80, ctx->r29) = ctx->r22;
    // sw          $s1, 0xE6C($sp)
    MEM_W(0XE6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0xE68($sp)
    MEM_W(0XE68, ctx->r29) = ctx->r16;
    // sw          $zero, 0xE60($sp)
    MEM_W(0XE60, ctx->r29) = 0;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80019DD4
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    CollectEquippableItems(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $s1, $sp, 0xC08
    ctx->r17 = ADD32(ctx->r29, 0XC08);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x8001F728
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    CalculateSellPrices(rdram, ctx);
    goto after_1;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_1:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // jal         0x800249BC
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    InitListWidget(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_2:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // andi        $a1, $s7, 0xFF
    ctx->r5 = ctx->r23 & 0XFF;
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // jal         0x80024A8C
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    ListNavigating(rdram, ctx);
    goto after_3;
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    after_3:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001F55C
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x63
        ctx->r18 = ADD32(0, -0X63);
        goto L_8001F55C;
    }
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // bne         $v0, $zero, L_8001F6F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F6F8;
    }
    // nop

L_8001F55C:
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
L_8001F564:
    // lw          $v0, 0xE60($sp)
    ctx->r2 = MEM_W(0XE60, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001F584
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F584;
    }
    // nop

    // lw          $v0, 0xE64($sp)
    ctx->r2 = MEM_W(0XE64, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001F58C
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001F58C;
    }
    // nop

L_8001F584:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_8001F58C:
    // lw          $v0, 0xE60($sp)
    ctx->r2 = MEM_W(0XE60, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001F5C8
    if (ctx->r2 != ctx->r19) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F5C8;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // ori         $a2, $zero, 0xB
    ctx->r6 = 0 | 0XB;
    // andi        $s0, $s6, 0xFF
    ctx->r16 = ctx->r22 & 0XFF;
    // jal         0x80022468
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    ShowEquipmentMenu(rdram, ctx);
    goto after_6;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_6:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001F5C4
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0xE64($sp)
        MEM_W(0XE64, ctx->r29) = ctx->r2;
        goto L_8001F5C4;
    }
    // sw          $v0, 0xE64($sp)
    MEM_W(0XE64, ctx->r29) = ctx->r2;
    // j           L_8001F5C8
    // sw          $s2, 0xE64($sp)
    MEM_W(0XE64, ctx->r29) = ctx->r18;
    goto L_8001F5C8;
    // sw          $s2, 0xE64($sp)
    MEM_W(0XE64, ctx->r29) = ctx->r18;
L_8001F5C4:
    // sw          $s0, 0xE64($sp)
    MEM_W(0XE64, ctx->r29) = ctx->r16;
L_8001F5C8:
    // lw          $v0, 0xE64($sp)
    ctx->r2 = MEM_W(0XE64, ctx->r29);
    // nop

    // bne         $v0, $s2, L_8001F684
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F684;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0xE60
    ctx->r6 = ADD32(ctx->r29, 0XE60);
    // jal         0x80020578
    // addiu       $a3, $sp, 0xE64
    ctx->r7 = ADD32(ctx->r29, 0XE64);
    ProcessListNavigation(rdram, ctx);
    goto after_7;
    // addiu       $a3, $sp, 0xE64
    ctx->r7 = ADD32(ctx->r29, 0XE64);
    after_7:
    // lbu         $a0, 0x39($sp)
    ctx->r4 = MEM_BU(0X39, ctx->r29);
    // lbu         $s7, 0x39($sp)
    ctx->r23 = MEM_BU(0X39, ctx->r29);
    // lw          $v1, 0xE60($sp)
    ctx->r3 = MEM_W(0XE60, ctx->r29);
    // addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // lbu         $s6, 0x0($v0)
    ctx->r22 = MEM_BU(0X0, ctx->r2);
    // bne         $v1, $s3, L_8001F63C
    if (ctx->r3 != ctx->r19) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001F63C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $v0, $sp, $a0
    ctx->r2 = ADD32(ctx->r29, ctx->r4);
    // lbu         $v0, 0xB90($v0)
    ctx->r2 = MEM_BU(0XB90, ctx->r2);
    // lw          $v1, 0x6C($gp)
    ctx->r3 = MEM_W(0X6C, ctx->r28);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001F630
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001F630;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_8;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_8:
    // j           L_8001F638
    // sw          $zero, 0xE60($sp)
    MEM_W(0XE60, ctx->r29) = 0;
    goto L_8001F638;
    // sw          $zero, 0xE60($sp)
    MEM_W(0XE60, ctx->r29) = 0;
L_8001F630:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_9;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_9:
L_8001F638:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001F63C:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001F660
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F660;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_11;
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    after_11:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8001F660:
    // jal         0x800228B4
    // ori         $a1, $zero, 0xB
    ctx->r5 = 0 | 0XB;
    RenderItemList(rdram, ctx);
    goto after_12;
    // ori         $a1, $zero, 0xB
    ctx->r5 = 0 | 0XB;
    after_12:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_13;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_13:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001F63C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F63C;
    }
    // nop

    // j           L_8001F564
    // nop

    goto L_8001F564;
    // nop

L_8001F684:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // lw          $a1, 0xE64($sp)
    ctx->r5 = MEM_W(0XE64, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a1, $v0, L_8001F6F8
    if (ctx->r5 == ctx->r2) {
        // andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
        goto L_8001F6F8;
    }
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B10
    ctx->r4 = ADD32(ctx->r4, -0X4B10);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // addiu       $v1, $v1, -0x2190
    ctx->r3 = ADD32(ctx->r3, -0X2190);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // lbu         $a0, 0x6C($gp)
    ctx->r4 = MEM_BU(0X6C, ctx->r28);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
L_8001F6F8:
    // lw          $ra, 0xE88($sp)
    ctx->r31 = MEM_W(0XE88, ctx->r29);
    // lw          $s7, 0xE84($sp)
    ctx->r23 = MEM_W(0XE84, ctx->r29);
    // lw          $s6, 0xE80($sp)
    ctx->r22 = MEM_W(0XE80, ctx->r29);
    // lw          $s5, 0xE7C($sp)
    ctx->r21 = MEM_W(0XE7C, ctx->r29);
    // lw          $s4, 0xE78($sp)
    ctx->r20 = MEM_W(0XE78, ctx->r29);
    // lw          $s3, 0xE74($sp)
    ctx->r19 = MEM_W(0XE74, ctx->r29);
    // lw          $s2, 0xE70($sp)
    ctx->r18 = MEM_W(0XE70, ctx->r29);
    // lw          $s1, 0xE6C($sp)
    ctx->r17 = MEM_W(0XE6C, ctx->r29);
    // lw          $s0, 0xE68($sp)
    ctx->r16 = MEM_W(0XE68, ctx->r29);
    // addiu       $sp, $sp, 0xE90
    ctx->r29 = ADD32(ctx->r29, 0XE90);
    // jr          $ra
    // nop

    return;
    // nop

;}
