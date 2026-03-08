#include "recomp.h"
#include "disable_warnings.h"

void EquipmentMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x240
    ctx->r29 = ADD32(ctx->r29, -0X240);
    // addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4A66($v1)
    ctx->r3 = MEM_H(-0X4A66, ctx->r3);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $ra, 0x23C($sp)
    MEM_W(0X23C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r18;
    // sw          $s1, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r17;
    // sw          $s0, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r16;
    // sw          $zero, 0x228($sp)
    MEM_W(0X228, ctx->r29) = 0;
    // sw          $v0, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x6788
    ctx->r2 = ADD32(ctx->r2, -0X6788);
    // addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // or          $v0, $a2, $a3
    ctx->r2 = ctx->r6 | ctx->r7;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_8001ABA4
    if (ctx->r2 == 0) {
        // addiu       $t0, $a2, 0xF0
        ctx->r8 = ADD32(ctx->r6, 0XF0);
        goto L_8001ABA4;
    }
    // addiu       $t0, $a2, 0xF0
    ctx->r8 = ADD32(ctx->r6, 0XF0);
L_8001AB50:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8001AB50
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8001AB50;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8001ABD4
    // addiu       $s0, $sp, 0x138
    ctx->r16 = ADD32(ctx->r29, 0X138);
    goto L_8001ABD4;
    // addiu       $s0, $sp, 0x138
    ctx->r16 = ADD32(ctx->r29, 0X138);
L_8001ABA4:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8001ABA4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8001ABA4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $s0, $sp, 0x138
    ctx->r16 = ADD32(ctx->r29, 0X138);
L_8001ABD4:
    // jal         0x8001AD20
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    CollectEquippedItemsData(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800249BC
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    InitListWidget(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    after_1:
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sb          $v0, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r2;
    // sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x27
    ctx->r2 = 0 | 0X27;
    // sb          $v0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
L_8001AC1C:
    // lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(0X228, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001AC3C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001AC3C;
    }
    // nop

    // lw          $v0, 0x22C($sp)
    ctx->r2 = MEM_W(0X22C, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001AC44
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001AC44;
    }
    // nop

L_8001AC3C:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8001AC44:
    // lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(0X228, ctx->r29);
    // nop

    // bne         $v0, $s1, L_8001AC9C
    if (ctx->r2 != ctx->r17) {
        // nop
    
        goto L_8001AC9C;
    }
    // nop

    // lbu         $a0, 0x31($sp)
    ctx->r4 = MEM_BU(0X31, ctx->r29);
    // nop

    // bne         $a0, $s1, L_8001AC74
    if (ctx->r4 != ctx->r17) {
        // ori         $v0, $zero, 0x9
        ctx->r2 = 0 | 0X9;
        goto L_8001AC74;
    }
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // jal         0x8001B480
    // nop

    sub_8001B480(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8001AC94
    // nop

    goto L_8001AC94;
    // nop

L_8001AC74:
    // bne         $a0, $v0, L_8001AC8C
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8001AC8C;
    }
    // nop

    // jal         0x8001B7C0
    // nop

    BuildUnifiedActionMenu(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8001AC94
    // nop

    goto L_8001AC94;
    // nop

L_8001AC8C:
    // jal         0x8001AEF4
    // nop

    sub_8001AEF4(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_8001AC94:
    // jal         0x8001AD20
    // addiu       $a0, $sp, 0x138
    ctx->r4 = ADD32(ctx->r29, 0X138);
    CollectEquippedItemsData(rdram, ctx);
    goto after_6;
    // addiu       $a0, $sp, 0x138
    ctx->r4 = ADD32(ctx->r29, 0X138);
    after_6:
L_8001AC9C:
    // lw          $v0, 0x22C($sp)
    ctx->r2 = MEM_W(0X22C, ctx->r29);
    // nop

    // bne         $v0, $s2, L_8001AD04
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8001AD04;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x228
    ctx->r6 = ADD32(ctx->r29, 0X228);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x22C
    ctx->r7 = ADD32(ctx->r29, 0X22C);
    ProcessListNavigation(rdram, ctx);
    goto after_7;
    // addiu       $a3, $sp, 0x22C
    ctx->r7 = ADD32(ctx->r29, 0X22C);
    after_7:
    // lw          $v0, 0x228($sp)
    ctx->r2 = MEM_W(0X228, ctx->r29);
    // nop

    // bne         $v0, $s1, L_8001ACD4
    if (ctx->r2 != ctx->r17) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001ACD4;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_8;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_8:
L_8001ACD4:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_9;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_9:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x800228B4
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    RenderItemList(rdram, ctx);
    goto after_10;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    after_10:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001ACD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001ACD4;
    }
    // nop

    // j           L_8001AC1C
    // nop

    goto L_8001AC1C;
    // nop

L_8001AD04:
    // lw          $ra, 0x23C($sp)
    ctx->r31 = MEM_W(0X23C, ctx->r29);
    // lw          $s2, 0x238($sp)
    ctx->r18 = MEM_W(0X238, ctx->r29);
    // lw          $s1, 0x234($sp)
    ctx->r17 = MEM_W(0X234, ctx->r29);
    // lw          $s0, 0x230($sp)
    ctx->r16 = MEM_W(0X230, ctx->r29);
    // addiu       $sp, $sp, 0x240
    ctx->r29 = ADD32(ctx->r29, 0X240);
    // jr          $ra
    // nop

    return;
    // nop

;}
