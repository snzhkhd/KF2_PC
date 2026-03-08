#include "recomp.h"
#include "disable_warnings.h"

void BuildUnifiedActionMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x988
    ctx->r29 = ADD32(ctx->r29, -0X988);
    // sw          $s0, 0x960($sp)
    MEM_W(0X960, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // addiu       $a2, $sp, 0x908
    ctx->r6 = ADD32(ctx->r29, 0X908);
    // addiu       $a1, $sp, 0x8B8
    ctx->r5 = ADD32(ctx->r29, 0X8B8);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $v1, $sp, 0x740
    ctx->r3 = ADD32(ctx->r29, 0X740);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $ra, 0x980($sp)
    MEM_W(0X980, ctx->r29) = ctx->r31;
    // sw          $s7, 0x97C($sp)
    MEM_W(0X97C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x978($sp)
    MEM_W(0X978, ctx->r29) = ctx->r22;
    // sw          $s5, 0x974($sp)
    MEM_W(0X974, ctx->r29) = ctx->r21;
    // sw          $s4, 0x970($sp)
    MEM_W(0X970, ctx->r29) = ctx->r20;
    // sw          $s3, 0x96C($sp)
    MEM_W(0X96C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x968($sp)
    MEM_W(0X968, ctx->r29) = ctx->r18;
    // sw          $s1, 0x964($sp)
    MEM_W(0X964, ctx->r29) = ctx->r17;
    // sw          $zero, 0x958($sp)
    MEM_W(0X958, ctx->r29) = 0;
    // sw          $v0, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r2;
L_8001B810:
    // sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // sw          $t0, 0x778($a0)
    MEM_W(0X778, ctx->r4) = ctx->r8;
    // sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
    // sb          $a3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r7;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4A
    ctx->r2 = SIGNED(ctx->r16) < 0X4A ? 1 : 0;
    // bne         $v0, $zero, L_8001B810
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8001B810;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // addiu       $s1, $s1, -0x2130
    ctx->r17 = ADD32(ctx->r17, -0X2130);
    // addiu       $a0, $s1, -0x60
    ctx->r4 = ADD32(ctx->r17, -0X60);
    // addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $s6, $sp, 0x740
    ctx->r22 = ADD32(ctx->r29, 0X740);
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // addiu       $a3, $sp, 0x8B8
    ctx->r7 = ADD32(ctx->r29, 0X8B8);
    // lbu         $s4, 0x0($s1)
    ctx->r20 = MEM_BU(0X0, ctx->r17);
    // lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // lbu         $s5, -0x212F($s5)
    ctx->r21 = MEM_BU(-0X212F, ctx->r21);
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x74
    ctx->r2 = 0 | 0X74;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sb          $zero, -0x212F($at)
    MEM_B(-0X212F, ctx->r1) = 0;
    // jal         0x80019CD0
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    GetInventoryItems(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1900
    ctx->r4 = ADD32(ctx->r4, -0X1900);
    // sll         $a1, $s0, 1
    ctx->r5 = S32(ctx->r16) << 1;
    // addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) << 3;
    // addu        $a1, $s2, $a1
    ctx->r5 = ADD32(ctx->r18, ctx->r5);
    // addiu       $s3, $sp, 0x790
    ctx->r19 = ADD32(ctx->r29, 0X790);
    // sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16) << 2;
    // addu        $a2, $s3, $a2
    ctx->r6 = ADD32(ctx->r19, ctx->r6);
    // addiu       $a3, $sp, 0x908
    ctx->r7 = ADD32(ctx->r29, 0X908);
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sb          $s5, -0x212F($at)
    MEM_B(-0X212F, ctx->r1) = ctx->r21;
    // jal         0x8001A9E4
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    CollectAvailableSpells(rdram, ctx);
    goto after_1;
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    after_1:
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16) << 1;
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7) << 3;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x4A66
    ctx->r17 = ADD32(ctx->r17, -0X4A66);
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(0X0, ctx->r17);
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
    // lwl         $t0, 0x0($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x667C
    ctx->r1 = ADD32(ctx->r1, -0X667C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t0, 0x0($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6675
    ctx->r1 = ADD32(ctx->r1, -0X6675);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t1, 0x0($at)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6678
    ctx->r1 = ADD32(ctx->r1, -0X6678);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t1, 0x0($at)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6671
    ctx->r1 = ADD32(ctx->r1, -0X6671);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $t2, 0x0($at)
    ctx->r10 = do_lwl(rdram, ctx->r10, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x6674
    ctx->r1 = ADD32(ctx->r1, -0X6674);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t2, 0x0($at)
    ctx->r10 = do_lwr(rdram, ctx->r10, 0X0, ctx->r1);
    // swl         $v1, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r3);
    // swr         $v1, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r3);
    // swl         $t0, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r8);
    // swr         $t0, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r8);
    // swl         $t1, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r9);
    // swr         $t1, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r9);
    // swl         $t2, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r10);
    // swr         $t2, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r10);
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
    // lwl         $t0, 0x0($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x666C
    ctx->r1 = ADD32(ctx->r1, -0X666C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $t0, 0x0($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X0, ctx->r1);
    // swl         $v1, 0x13($a3)
    do_swl(rdram, 0X13, ctx->r7, ctx->r3);
    // swr         $v1, 0x10($a3)
    do_swr(rdram, 0X10, ctx->r7, ctx->r3);
    // swl         $t0, 0x17($a3)
    do_swl(rdram, 0X17, ctx->r7, ctx->r8);
    // swr         $t0, 0x14($a3)
    do_swr(rdram, 0X14, ctx->r7, ctx->r8);
    // jal         0x800249BC
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    InitListWidget(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    after_2:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4AA4($v1)
    ctx->r3 = MEM_HU(-0X4AA4, ctx->r3);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // beq         $v1, $v0, L_8001BA88
    if (ctx->r3 == ctx->r2) {
        // sw          $s3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r19;
        goto L_8001BA88;
    }
    // sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $s1, -0x3E
    ctx->r17 = ADD32(ctx->r17, -0X3E);
L_8001BA3C:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_8001BA5C
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $sp, $s0
        ctx->r2 = ADD32(ctx->r29, ctx->r16);
        goto L_8001BA5C;
    }
    // addu        $v0, $sp, $s0
    ctx->r2 = ADD32(ctx->r29, ctx->r16);
    // lbu         $v1, 0x8B8($v0)
    ctx->r3 = MEM_BU(0X8B8, ctx->r2);
    // lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(0X1, ctx->r17);
    // j           L_8001BA60
    // nop

    goto L_8001BA60;
    // nop

L_8001BA5C:
    // lbu         $v0, 0x908($v0)
    ctx->r2 = MEM_BU(0X908, ctx->r2);
L_8001BA60:
    // nop

    // bne         $v0, $v1, L_8001BA78
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BA78;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80024A8C
    // andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    ListNavigating(rdram, ctx);
    goto after_3;
    // andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_3:
    // ori         $s0, $zero, 0x4A
    ctx->r16 = 0 | 0X4A;
L_8001BA78:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4A
    ctx->r2 = SIGNED(ctx->r16) < 0X4A ? 1 : 0;
    // bne         $v0, $zero, L_8001BA3C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BA3C;
    }
    // nop

L_8001BA88:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001BAB8
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x63
        ctx->r18 = ADD32(0, -0X63);
        goto L_8001BAB8;
    }
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $a0, 0x8B8($v0)
    ctx->r4 = MEM_BU(0X8B8, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // bne         $v0, $zero, L_8001BBE4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BBE4;
    }
    // nop

L_8001BAB8:
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // addiu       $s1, $sp, 0x8B8
    ctx->r17 = ADD32(ctx->r29, 0X8B8);
L_8001BAC0:
    // lw          $v0, 0x958($sp)
    ctx->r2 = MEM_W(0X958, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001BAE0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BAE0;
    }
    // nop

    // lw          $v0, 0x95C($sp)
    ctx->r2 = MEM_W(0X95C, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001BAE8
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001BAE8;
    }
    // nop

L_8001BAE0:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_8001BAE8:
    // lw          $v0, 0x958($sp)
    ctx->r2 = MEM_W(0X958, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001BB28
    if (ctx->r2 != ctx->r19) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BB28;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // ori         $a2, $zero, 0x10
    ctx->r6 = 0 | 0X10;
    // jal         0x80022468
    // andi        $a3, $s7, 0xFF
    ctx->r7 = ctx->r23 & 0XFF;
    ShowEquipmentMenu(rdram, ctx);
    goto after_6;
    // andi        $a3, $s7, 0xFF
    ctx->r7 = ctx->r23 & 0XFF;
    after_6:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001BB1C
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x95C($sp)
        MEM_W(0X95C, ctx->r29) = ctx->r2;
        goto L_8001BB1C;
    }
    // sw          $v0, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r2;
    // j           L_8001BB28
    // sw          $s2, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r18;
    goto L_8001BB28;
    // sw          $s2, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r18;
L_8001BB1C:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // sw          $v0, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r2;
L_8001BB28:
    // lw          $v0, 0x95C($sp)
    ctx->r2 = MEM_W(0X95C, ctx->r29);
    // nop

    // bne         $v0, $s2, L_8001BBB0
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BBB0;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0x958
    ctx->r6 = ADD32(ctx->r29, 0X958);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x95C
    ctx->r7 = ADD32(ctx->r29, 0X95C);
    ProcessListNavigation(rdram, ctx);
    goto after_7;
    // addiu       $a3, $sp, 0x95C
    ctx->r7 = ADD32(ctx->r29, 0X95C);
    after_7:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // lw          $v1, 0x958($sp)
    ctx->r3 = MEM_W(0X958, ctx->r29);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lbu         $s7, 0x0($v0)
    ctx->r23 = MEM_BU(0X0, ctx->r2);
    // bne         $v1, $s3, L_8001BB68
    if (ctx->r3 != ctx->r19) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001BB68;
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
L_8001BB68:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001BB8C
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BB8C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_10;
    // andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    after_10:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8001BB8C:
    // jal         0x800228B4
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    RenderItemList(rdram, ctx);
    goto after_11;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    after_11:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_12;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_12:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001BB68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BB68;
    }
    // nop

    // j           L_8001BAC0
    // nop

    goto L_8001BAC0;
    // nop

L_8001BBB0:
    // lw          $v1, 0x95C($sp)
    ctx->r3 = MEM_W(0X95C, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001BBE4
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $sp, $v1
        ctx->r2 = ADD32(ctx->r29, ctx->r3);
        goto L_8001BBE4;
    }
    // addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // lbu         $a0, 0x908($v0)
    ctx->r4 = MEM_BU(0X908, ctx->r2);
    // jal         0x80027E80
    // nop

    sub_80027E80(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lw          $v0, 0x95C($sp)
    ctx->r2 = MEM_W(0X95C, ctx->r29);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $a0, 0x8B8($v0)
    ctx->r4 = MEM_BU(0X8B8, ctx->r2);
    // jal         0x80027EA8
    // nop

    sub_80027EA8(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_8001BBE4:
    // lw          $ra, 0x980($sp)
    ctx->r31 = MEM_W(0X980, ctx->r29);
    // lw          $s7, 0x97C($sp)
    ctx->r23 = MEM_W(0X97C, ctx->r29);
    // lw          $s6, 0x978($sp)
    ctx->r22 = MEM_W(0X978, ctx->r29);
    // lw          $s5, 0x974($sp)
    ctx->r21 = MEM_W(0X974, ctx->r29);
    // lw          $s4, 0x970($sp)
    ctx->r20 = MEM_W(0X970, ctx->r29);
    // lw          $s3, 0x96C($sp)
    ctx->r19 = MEM_W(0X96C, ctx->r29);
    // lw          $s2, 0x968($sp)
    ctx->r18 = MEM_W(0X968, ctx->r29);
    // lw          $s1, 0x964($sp)
    ctx->r17 = MEM_W(0X964, ctx->r29);
    // lw          $s0, 0x960($sp)
    ctx->r16 = MEM_W(0X960, ctx->r29);
    // addiu       $sp, $sp, 0x988
    ctx->r29 = ADD32(ctx->r29, 0X988);
    // jr          $ra
    // nop

    return;
    // nop

;}
