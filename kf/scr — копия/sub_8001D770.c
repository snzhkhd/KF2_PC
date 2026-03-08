#include "recomp.h"
#include "disable_warnings.h"

void sub_8001D770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x400
    ctx->r29 = ADD32(ctx->r29, -0X400);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $ra, 0x3F8($sp)
    MEM_W(0X3F8, ctx->r29) = ctx->r31;
    // sw          $s5, 0x3F4($sp)
    MEM_W(0X3F4, ctx->r29) = ctx->r21;
    // sw          $s4, 0x3F0($sp)
    MEM_W(0X3F0, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3EC($sp)
    MEM_W(0X3EC, ctx->r29) = ctx->r19;
    // sw          $s2, 0x3E8($sp)
    MEM_W(0X3E8, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3E4($sp)
    MEM_W(0X3E4, ctx->r29) = ctx->r17;
    // sw          $s0, 0x3E0($sp)
    MEM_W(0X3E0, ctx->r29) = ctx->r16;
    // sw          $zero, 0x3D4($sp)
    MEM_W(0X3D4, ctx->r29) = 0;
    // jal         0x800246CC
    // sw          $v0, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r2;
    SetupMenuUIBuffers(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $s0, $sp, 0x398
    ctx->r16 = ADD32(ctx->r29, 0X398);
    // jal         0x8001E184
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    InitMenuTextCoords(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // ori         $a2, $zero, 0x38
    ctx->r6 = 0 | 0X38;
    // ori         $a3, $zero, 0x57
    ctx->r7 = 0 | 0X57;
    // ori         $v0, $zero, 0xCE
    ctx->r2 = 0 | 0XCE;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x8001EDE0
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8001EDE0(rdram, ctx);
    goto after_2;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_2:
    // jal         0x80018190
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_3;
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    after_3:
    // jal         0x80025008
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    MemCard_InitSystem(rdram, ctx);
    goto after_4;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    after_4:
L_8001D7F0:
    // jal         0x800250A8
    // nop

    MemCard_CheckSlot(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_8001D808
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8001D808;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_8001D7F0
    if (ctx->r16 != ctx->r17) {
        // nop
    
        goto L_8001D7F0;
    }
    // nop

L_8001D808:
    // ori         $s0, $zero, 0x4
    ctx->r16 = 0 | 0X4;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8001D810:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // jal         0x80025198
    // addiu       $a1, $sp, 0x3D0
    ctx->r5 = ADD32(ctx->r29, 0X3D0);
    MemCard_ScanForSaves(rdram, ctx);
    goto after_6;
    // addiu       $a1, $sp, 0x3D0
    ctx->r5 = ADD32(ctx->r29, 0X3D0);
    after_6:
    // beq         $v0, $zero, L_8001D83C
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8001D83C;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // lw          $v0, 0x3D0($sp)
    ctx->r2 = MEM_W(0X3D0, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001D83C
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8001D83C;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_8001D810
    if (ctx->r16 != ctx->r17) {
        // nop
    
        goto L_8001D810;
    }
    // nop

L_8001D83C:
    // addiu       $s2, $sp, 0x2B0
    ctx->r18 = ADD32(ctx->r29, 0X2B0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $s3, $sp, 0x350
    ctx->r19 = ADD32(ctx->r29, 0X350);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // addiu       $s1, $sp, 0x370
    ctx->r17 = ADD32(ctx->r29, 0X370);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // addiu       $v0, $sp, 0x378
    ctx->r2 = ADD32(ctx->r29, 0X378);
    // jal         0x8001C3A0
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8001C3A0(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16) << 2;
    // addu        $a3, $t0, $s0
    ctx->r7 = ADD32(ctx->r8, ctx->r16);
    // addu        $t1, $s1, $s0
    ctx->r9 = ADD32(ctx->r17, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $a0, $sp, 0x278
    ctx->r4 = ADD32(ctx->r29, 0X278);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // ori         $a2, $zero, 0x3
    ctx->r6 = 0 | 0X3;
    // addiu       $s4, $zero, -0x63
    ctx->r20 = ADD32(0, -0X63);
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    // sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7) << 2;
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
    // addiu       $at, $at, -0x625D
    ctx->r1 = ADD32(ctx->r1, -0X625D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6260
    ctx->r1 = ADD32(ctx->r1, -0X6260);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6259
    ctx->r1 = ADD32(ctx->r1, -0X6259);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t2, 0x0($at)
    ctx->r10 = do_lwl(rdram, ctx->r10, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x625C
    ctx->r1 = ADD32(ctx->r1, -0X625C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t2, 0x0($at)
    ctx->r10 = do_lwr(rdram, ctx->r10, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6255
    ctx->r1 = ADD32(ctx->r1, -0X6255);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t3, 0x0($at)
    ctx->r11 = do_lwl(rdram, ctx->r11, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6258
    ctx->r1 = ADD32(ctx->r1, -0X6258);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t3, 0x0($at)
    ctx->r11 = do_lwr(rdram, ctx->r11, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6251
    ctx->r1 = ADD32(ctx->r1, -0X6251);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t4, 0x0($at)
    ctx->r12 = do_lwl(rdram, ctx->r12, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6254
    ctx->r1 = ADD32(ctx->r1, -0X6254);
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
    // addiu       $at, $at, -0x6250
    ctx->r1 = ADD32(ctx->r1, -0X6250);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lb          $v1, 0x0($at)
    ctx->r3 = MEM_B(0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x624F
    ctx->r1 = ADD32(ctx->r1, -0X624F);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lb          $t2, 0x0($at)
    ctx->r10 = MEM_B(0X0, ctx->r1);
    // sb          $v1, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r3;
    // sb          $t2, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r10;
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x330($t0)
    MEM_W(0X330, ctx->r8) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // jal         0x800249BC
    // sw          $v0, 0x358($t0)
    MEM_W(0X358, ctx->r8) = ctx->r2;
    InitListWidget(rdram, ctx);
    goto after_8;
    // sw          $v0, 0x358($t0)
    MEM_W(0X358, ctx->r8) = ctx->r2;
    after_8:
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sb          $v0, 0x297($sp)
    MEM_B(0X297, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x83
    ctx->r2 = 0 | 0X83;
    // sb          $v0, 0x295($sp)
    MEM_B(0X295, ctx->r29) = ctx->r2;
    // sb          $s0, 0x296($sp)
    MEM_B(0X296, ctx->r29) = ctx->r16;
    // sw          $s2, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = ctx->r17;
    // jal         0x80024DA8
    // sw          $s3, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->r19;
    PlaySfx(rdram, ctx);
    goto after_9;
    // sw          $s3, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->r19;
    after_9:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_8001D9C8:
    // lw          $v0, 0x3D4($sp)
    ctx->r2 = MEM_W(0X3D4, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001D9E8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001D9E8;
    }
    // nop

    // lw          $v0, 0x3D8($sp)
    ctx->r2 = MEM_W(0X3D8, ctx->r29);
    // nop

    // beq         $v0, $s4, L_8001D9F0
    if (ctx->r2 == ctx->r20) {
        // nop
    
        goto L_8001D9F0;
    }
    // nop

L_8001D9E8:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_11;
    // nop

    after_11:
L_8001D9F0:
    // lw          $v0, 0x3D4($sp)
    ctx->r2 = MEM_W(0X3D4, ctx->r29);
    // nop

    // bne         $v0, $s5, L_8001DA30
    if (ctx->r2 != ctx->r21) {
        // addiu       $a0, $sp, 0x278
        ctx->r4 = ADD32(ctx->r29, 0X278);
        goto L_8001DA30;
    }
    // addiu       $a0, $sp, 0x278
    ctx->r4 = ADD32(ctx->r29, 0X278);
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // ori         $a2, $zero, 0x9
    ctx->r6 = 0 | 0X9;
    // jal         0x80022468
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    ShowEquipmentMenu(rdram, ctx);
    goto after_12;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    after_12:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001DA24
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x3D8($sp)
        MEM_W(0X3D8, ctx->r29) = ctx->r2;
        goto L_8001DA24;
    }
    // sw          $v0, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r2;
    // j           L_8001DA30
    // sw          $s4, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r20;
    goto L_8001DA30;
    // sw          $s4, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r20;
L_8001DA24:
    // lbu         $v0, 0x299($sp)
    ctx->r2 = MEM_BU(0X299, ctx->r29);
    // nop

    // sw          $v0, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->r2;
L_8001DA30:
    // lw          $v0, 0x3D8($sp)
    ctx->r2 = MEM_W(0X3D8, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001DA98
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x278
        ctx->r4 = ADD32(ctx->r29, 0X278);
        goto L_8001DA98;
    }
    // addiu       $a0, $sp, 0x278
    ctx->r4 = ADD32(ctx->r29, 0X278);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x3D4
    ctx->r6 = ADD32(ctx->r29, 0X3D4);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x3D8
    ctx->r7 = ADD32(ctx->r29, 0X3D8);
    ProcessListNavigation(rdram, ctx);
    goto after_13;
    // addiu       $a3, $sp, 0x3D8
    ctx->r7 = ADD32(ctx->r29, 0X3D8);
    after_13:
    // lw          $v0, 0x3D4($sp)
    ctx->r2 = MEM_W(0X3D4, ctx->r29);
    // nop

    // bne         $v0, $s5, L_8001DA68
    if (ctx->r2 != ctx->r21) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001DA68;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_14;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_14:
L_8001DA68:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_15;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_15:
    // addiu       $a0, $sp, 0x278
    ctx->r4 = ADD32(ctx->r29, 0X278);
    // jal         0x800228B4
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    RenderItemList(rdram, ctx);
    goto after_16;
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    after_16:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001DA68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001DA68;
    }
    // nop

    // j           L_8001D9C8
    // nop

    goto L_8001D9C8;
    // nop

L_8001DA98:
    // lw          $v1, 0x3D8($sp)
    ctx->r3 = MEM_W(0X3D8, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001DAB8
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8001DAB8;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lw          $a0, 0x378($v0)
    ctx->r4 = MEM_W(0X378, ctx->r2);
    // jal         0x8001DAF0
    // nop

    sub_8001DAF0(rdram, ctx);
    goto after_18;
    // nop

    after_18:
L_8001DAB8:
    // jal         0x80025064
    // nop

    sub_80025064(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // jal         0x80024820
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    Music_UpdateState(rdram, ctx);
    goto after_20;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // lw          $ra, 0x3F8($sp)
    ctx->r31 = MEM_W(0X3F8, ctx->r29);
    // lw          $s5, 0x3F4($sp)
    ctx->r21 = MEM_W(0X3F4, ctx->r29);
    // lw          $s4, 0x3F0($sp)
    ctx->r20 = MEM_W(0X3F0, ctx->r29);
    // lw          $s3, 0x3EC($sp)
    ctx->r19 = MEM_W(0X3EC, ctx->r29);
    // lw          $s2, 0x3E8($sp)
    ctx->r18 = MEM_W(0X3E8, ctx->r29);
    // lw          $s1, 0x3E4($sp)
    ctx->r17 = MEM_W(0X3E4, ctx->r29);
    // lw          $s0, 0x3E0($sp)
    ctx->r16 = MEM_W(0X3E0, ctx->r29);
    // addiu       $sp, $sp, 0x400
    ctx->r29 = ADD32(ctx->r29, 0X400);
    // jr          $ra
    // nop

    return;
    // nop

;}
