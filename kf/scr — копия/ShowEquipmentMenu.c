#include "recomp.h"
#include "disable_warnings.h"

void ShowEquipmentMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A66
    ctx->r5 = ADD32(ctx->r5, -0X4A66);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(0X0, ctx->r5);
    // addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7CE8
    ctx->r1 = ADD32(ctx->r1, 0X7CE8);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7CEA
    ctx->r1 = ADD32(ctx->r1, 0X7CEA);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7D04
    ctx->r1 = ADD32(ctx->r1, 0X7D04);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // addiu       $at, $at, 0x7D06
    ctx->r1 = ADD32(ctx->r1, 0X7D06);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x6290
    ctx->r4 = ADD32(ctx->r4, -0X6290);
    // sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(0X0, ctx->r5);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // lwl         $a3, 0xB($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XB, ctx->r2);
    // lwr         $a3, 0x8($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X8, ctx->r2);
    // lwl         $t0, 0xF($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XF, ctx->r2);
    // lwr         $t0, 0xC($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0XC, ctx->r2);
    // swl         $v1, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r3);
    // swr         $v1, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r3);
    // swl         $a2, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r6);
    // swr         $a2, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r6);
    // swl         $a3, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r7);
    // swr         $a3, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r7);
    // swl         $t0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r8);
    // swr         $t0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r8);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a2, 0x17($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X17, ctx->r2);
    // lwr         $a2, 0x14($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X14, ctx->r2);
    // swl         $v1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r3);
    // swr         $v1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r3);
    // swl         $a2, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r6);
    // swr         $a2, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r6);
    // addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5) << 3;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // lwl         $a1, 0xB($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r2);
    // lwr         $a1, 0x8($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r2);
    // lwl         $a2, 0xF($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XF, ctx->r2);
    // lwr         $a2, 0xC($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0XC, ctx->r2);
    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // swl         $a0, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r4);
    // swr         $a0, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r4);
    // swl         $a1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r5);
    // swr         $a1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r5);
    // swl         $a2, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r6);
    // swr         $a2, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r6);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
L_8002261C:
    // beq         $s2, $v0, L_80022634
    if (ctx->r18 == ctx->r2) {
        // nop
    
        goto L_80022634;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80022748
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    goto L_80022748;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80022634:
    // jal         0x80024E70
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    WaitForInputStable(rdram, ctx);
    goto after_1;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_1:
    // jal         0x80024E3C
    // nop

    ReadPadWithFlag(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62F4($v1)
    ctx->r3 = MEM_W(0X62F4, ctx->r3);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // bne         $v1, $zero, L_80022674
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80022674;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80022690
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80022690;
    }
    // nop

L_80022674:
    // sw          $zero, 0x74($gp)
    MEM_W(0X74, ctx->r28) = 0;
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_3:
    // bne         $s1, $zero, L_800226F8
    if (ctx->r17 != 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_800226F8;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // j           L_800226F8
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    goto L_800226F8;
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
L_80022690:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_800226BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800226BC;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_4:
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // j           L_800226F8
    // negu        $s2, $s1
    ctx->r18 = SUB32(0, ctx->r17);
    goto L_800226F8;
    // negu        $s2, $s1
    ctx->r18 = SUB32(0, ctx->r17);
L_800226BC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D0($v0)
    ctx->r2 = MEM_W(0X62D0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_800226EC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800226EC;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E0($v0)
    ctx->r2 = MEM_W(0X62E0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_800226FC
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_800226FC;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800226EC:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_5:
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800226F8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800226FC:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_6;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_6:
    // jal         0x80023388
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_7;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    after_7:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x800228B4
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    RenderItemList(rdram, ctx);
    goto after_8;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_8:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80023294
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    ApplyViewTransforms(rdram, ctx);
    goto after_9;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_9:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_800226FC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x63
        ctx->r2 = ADD32(0, -0X63);
        goto L_800226FC;
    }
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // j           L_8002261C
    // nop

    goto L_8002261C;
    // nop

L_80022748:
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(0X60, ctx->r29);
    // lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(0X5C, ctx->r29);
    // lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(0X58, ctx->r29);
    // lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(0X54, ctx->r29);
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
