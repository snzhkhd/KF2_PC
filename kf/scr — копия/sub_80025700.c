#include "recomp.h"
#include "disable_warnings.h"

void sub_80025700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x598
    ctx->r29 = ADD32(ctx->r29, -0X598);
    // sw          $s3, 0x57C($sp)
    MEM_W(0X57C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x590($sp)
    MEM_W(0X590, ctx->r29) = ctx->r31;
    // sw          $s7, 0x58C($sp)
    MEM_W(0X58C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r22;
    // sw          $s5, 0x584($sp)
    MEM_W(0X584, ctx->r29) = ctx->r21;
    // sw          $s4, 0x580($sp)
    MEM_W(0X580, ctx->r29) = ctx->r20;
    // sw          $s2, 0x578($sp)
    MEM_W(0X578, ctx->r29) = ctx->r18;
    // sw          $s1, 0x574($sp)
    MEM_W(0X574, ctx->r29) = ctx->r17;
    // sw          $s0, 0x570($sp)
    MEM_W(0X570, ctx->r29) = ctx->r16;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x121C
    ctx->r5 = ADD32(ctx->r5, 0X121C);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lb          $v1, 0x4($a1)
    ctx->r3 = MEM_B(0X4, ctx->r5);
    // lb          $a0, 0x5($a1)
    ctx->r4 = MEM_B(0X5, ctx->r5);
    // swl         $v0, 0x4EB($sp)
    do_swl(rdram, 0X4EB, ctx->r29, ctx->r2);
    // swr         $v0, 0x4E8($sp)
    do_swr(rdram, 0X4E8, ctx->r29, ctx->r2);
    // sb          $v1, 0x4EC($sp)
    MEM_B(0X4EC, ctx->r29) = ctx->r3;
    // sb          $a0, 0x4ED($sp)
    MEM_B(0X4ED, ctx->r29) = ctx->r4;
    // addiu       $a0, $sp, 0x4EE
    ctx->r4 = ADD32(ctx->r29, 0X4EE);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x22
    ctx->r6 = 0 | 0X22;
    memset_recomp(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x22
    ctx->r6 = 0 | 0X22;
    after_0:
    // lb          $v0, 0x80($gp)
    ctx->r2 = MEM_B(0X80, ctx->r28);
    // lb          $v1, 0x81($gp)
    ctx->r3 = MEM_B(0X81, ctx->r28);
    // sb          $v0, 0x558($sp)
    MEM_B(0X558, ctx->r29) = ctx->r2;
    // sb          $v1, 0x559($sp)
    MEM_B(0X559, ctx->r29) = ctx->r3;
    // addiu       $a0, $sp, 0x55A
    ctx->r4 = ADD32(ctx->r29, 0X55A);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    memset_recomp(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    after_1:
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // addiu       $a0, $sp, 0x510
    ctx->r4 = ADD32(ctx->r29, 0X510);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    memset_recomp(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    after_2:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x258
    ctx->r6 = 0 | 0X258;
    memset_recomp(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x258
    ctx->r6 = 0 | 0X258;
    after_3:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x80025198
    // addiu       $a1, $sp, 0x568
    ctx->r5 = ADD32(ctx->r29, 0X568);
    MemCard_ScanForSaves(rdram, ctx);
    goto after_4;
    // addiu       $a1, $sp, 0x568
    ctx->r5 = ADD32(ctx->r29, 0X568);
    after_4:
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s4, $sp, 0x50C
    ctx->r20 = ADD32(ctx->r29, 0X50C);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_800257C8:
    // addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // addu        $s1, $v0, $s2
    ctx->r17 = ADD32(ctx->r2, ctx->r18);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x1F58
    ctx->r5 = ADD32(ctx->r5, -0X1F58);
    // jal         0x80062BE0
    // ori         $a2, $zero, 0xC
    ctx->r6 = 0 | 0XC;
    KF_strncmp(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0xC
    ctx->r6 = 0 | 0XC;
    after_5:
    // bne         $v0, $zero, L_80025814
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x28
        ctx->r18 = ADD32(ctx->r18, 0X28);
        goto L_80025814;
    }
    // addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // lbu         $v0, 0xC($s1)
    ctx->r2 = MEM_BU(0XC, ctx->r17);
    // addiu       $a0, $sp, 0x558
    ctx->r4 = ADD32(ctx->r29, 0X558);
    // jal         0x80062C00
    // sb          $v0, 0x558($sp)
    MEM_B(0X558, ctx->r29) = ctx->r2;
    KF_atoi(rdram, ctx);
    goto after_6;
    // sb          $v0, 0x558($sp)
    MEM_B(0X558, ctx->r29) = ctx->r2;
    after_6:
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // bne         $v0, $s3, L_80025814
    if (ctx->r2 != ctx->r19) {
        // sw          $a0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80025814;
    }
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
L_80025814:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0xF
    ctx->r2 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // bne         $v0, $zero, L_800257C8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800257C8;
    }
    // nop

    // bne         $s5, $zero, L_80025870
    if (ctx->r21 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80025870;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s6, $v0, L_8002583C
    if (ctx->r22 != ctx->r2) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8002583C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // j           L_80025C0C
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    goto L_80025C0C;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_8002583C:
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
L_80025844:
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x500($v0)
    ctx->r2 = MEM_W(0X500, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80025860
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80025860;
    }
    // nop

    // addiu       $s3, $s0, 0x1
    ctx->r19 = ADD32(ctx->r16, 0X1);
    // ori         $s0, $zero, 0xF
    ctx->r16 = 0 | 0XF;
L_80025860:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0xF
    ctx->r2 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // bne         $v0, $zero, L_80025844
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16) << 2;
        goto L_80025844;
    }
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
L_80025870:
    // addiu       $s2, $sp, 0x4E8
    ctx->r18 = ADD32(ctx->r29, 0X4E8);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x1F58
    ctx->r5 = ADD32(ctx->r5, -0X1F58);
    // jal         0x80062B90
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    strcat_recomp(rdram, ctx);
    goto after_7;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_7:
    // addiu       $a0, $sp, 0x26C
    ctx->r4 = ADD32(ctx->r29, 0X26C);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x1F48
    ctx->r5 = ADD32(ctx->r5, -0X1F48);
    // addiu       $v0, $s3, 0x30
    ctx->r2 = ADD32(ctx->r19, 0X30);
    // sb          $v0, 0x4F9($sp)
    MEM_B(0X4F9, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x53
    ctx->r2 = 0 | 0X53;
    // sb          $v0, 0x268($sp)
    MEM_B(0X268, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x43
    ctx->r2 = 0 | 0X43;
    // sb          $v0, 0x269($sp)
    MEM_B(0X269, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sb          $v0, 0x26A($sp)
    MEM_B(0X26A, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $zero, 0x4FA($sp)
    MEM_B(0X4FA, ctx->r29) = 0;
    // jal         0x80062BD0
    // sb          $v0, 0x26B($sp)
    MEM_B(0X26B, ctx->r29) = ctx->r2;
    strcpy_recomp(rdram, ctx);
    goto after_8;
    // sb          $v0, 0x26B($sp)
    MEM_B(0X26B, ctx->r29) = ctx->r2;
    after_8:
    // addiu       $s1, $sp, 0x268
    ctx->r17 = ADD32(ctx->r29, 0X268);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80025C3C
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_80025C3C(rdram, ctx);
    goto after_9;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_9:
    // sll         $v0, $s3, 5
    ctx->r2 = S32(ctx->r19) << 5;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F25
    ctx->r1 = ADD32(ctx->r1, -0X1F25);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F28
    ctx->r1 = ADD32(ctx->r1, -0X1F28);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F21
    ctx->r1 = ADD32(ctx->r1, -0X1F21);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F24
    ctx->r1 = ADD32(ctx->r1, -0X1F24);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F1D
    ctx->r1 = ADD32(ctx->r1, -0X1F1D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F20
    ctx->r1 = ADD32(ctx->r1, -0X1F20);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F19
    ctx->r1 = ADD32(ctx->r1, -0X1F19);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F1C
    ctx->r1 = ADD32(ctx->r1, -0X1F1C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // swl         $v1, 0x2CB($sp)
    do_swl(rdram, 0X2CB, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C8($sp)
    do_swr(rdram, 0X2C8, ctx->r29, ctx->r3);
    // swl         $a0, 0x2CF($sp)
    do_swl(rdram, 0X2CF, ctx->r29, ctx->r4);
    // swr         $a0, 0x2CC($sp)
    do_swr(rdram, 0X2CC, ctx->r29, ctx->r4);
    // swl         $a1, 0x2D3($sp)
    do_swl(rdram, 0X2D3, ctx->r29, ctx->r5);
    // swr         $a1, 0x2D0($sp)
    do_swr(rdram, 0X2D0, ctx->r29, ctx->r5);
    // swl         $a2, 0x2D7($sp)
    do_swl(rdram, 0X2D7, ctx->r29, ctx->r6);
    // swr         $a2, 0x2D4($sp)
    do_swr(rdram, 0X2D4, ctx->r29, ctx->r6);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F15
    ctx->r1 = ADD32(ctx->r1, -0X1F15);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $v1, 0x0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F18
    ctx->r1 = ADD32(ctx->r1, -0X1F18);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $v1, 0x0($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F11
    ctx->r1 = ADD32(ctx->r1, -0X1F11);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a0, 0x0($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F14
    ctx->r1 = ADD32(ctx->r1, -0X1F14);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a0, 0x0($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F0D
    ctx->r1 = ADD32(ctx->r1, -0X1F0D);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a1, 0x0($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F10
    ctx->r1 = ADD32(ctx->r1, -0X1F10);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a1, 0x0($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F09
    ctx->r1 = ADD32(ctx->r1, -0X1F09);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwl         $a2, 0x0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X0, ctx->r1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1F0C
    ctx->r1 = ADD32(ctx->r1, -0X1F0C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lwr         $a2, 0x0($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r1);
    // swl         $v1, 0x2DB($sp)
    do_swl(rdram, 0X2DB, ctx->r29, ctx->r3);
    // swr         $v1, 0x2D8($sp)
    do_swr(rdram, 0X2D8, ctx->r29, ctx->r3);
    // swl         $a0, 0x2DF($sp)
    do_swl(rdram, 0X2DF, ctx->r29, ctx->r4);
    // swr         $a0, 0x2DC($sp)
    do_swr(rdram, 0X2DC, ctx->r29, ctx->r4);
    // swl         $a1, 0x2E3($sp)
    do_swl(rdram, 0X2E3, ctx->r29, ctx->r5);
    // swr         $a1, 0x2E0($sp)
    do_swr(rdram, 0X2E0, ctx->r29, ctx->r5);
    // swl         $a2, 0x2E7($sp)
    do_swl(rdram, 0X2E7, ctx->r29, ctx->r6);
    // swr         $a2, 0x2E4($sp)
    do_swr(rdram, 0X2E4, ctx->r29, ctx->r6);
    // addiu       $s0, $sp, 0x550
    ctx->r16 = ADD32(ctx->r29, 0X550);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x2E8
    ctx->r5 = ADD32(ctx->r29, 0X2E8);
    // ori         $v0, $zero, 0x320
    ctx->r2 = 0 | 0X320;
    // sh          $v0, 0x550($sp)
    MEM_H(0X550, ctx->r29) = ctx->r2;
    // sll         $v0, $s3, 4
    ctx->r2 = S32(ctx->r19) << 4;
    // addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, 0XF0);
    // sh          $v0, 0x552($sp)
    MEM_H(0X552, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sh          $v0, 0x554($sp)
    MEM_H(0X554, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // jal         0x8006335C
    // sh          $v0, 0x556($sp)
    MEM_H(0X556, ctx->r29) = ctx->r2;
    StoreImageWithCallback(rdram, ctx);
    goto after_10;
    // sh          $v0, 0x556($sp)
    MEM_H(0X556, ctx->r29) = ctx->r2;
    after_10:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x368
    ctx->r5 = ADD32(ctx->r29, 0X368);
    // ori         $v0, $zero, 0x324
    ctx->r2 = 0 | 0X324;
    // jal         0x8006335C
    // sh          $v0, 0x550($sp)
    MEM_H(0X550, ctx->r29) = ctx->r2;
    StoreImageWithCallback(rdram, ctx);
    goto after_11;
    // sh          $v0, 0x550($sp)
    MEM_H(0X550, ctx->r29) = ctx->r2;
    after_11:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x3E8
    ctx->r5 = ADD32(ctx->r29, 0X3E8);
    // ori         $v0, $zero, 0x328
    ctx->r2 = 0 | 0X328;
    // jal         0x8006335C
    // sh          $v0, 0x550($sp)
    MEM_H(0X550, ctx->r29) = ctx->r2;
    StoreImageWithCallback(rdram, ctx);
    goto after_12;
    // sh          $v0, 0x550($sp)
    MEM_H(0X550, ctx->r29) = ctx->r2;
    after_12:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lw          $a0, 0x138($gp)
    ctx->r4 = MEM_W(0X138, ctx->r28);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    memset_recomp(rdram, ctx);
    goto after_13;
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    after_13:
    // lw          $a0, 0x138($gp)
    ctx->r4 = MEM_W(0X138, ctx->r28);
    // jal         0x8004B694
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    sub_8004B694(rdram, ctx);
    goto after_14;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_14:
    // lw          $a0, 0x138($gp)
    ctx->r4 = MEM_W(0X138, ctx->r28);
    // jal         0x80025D40
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    sub_80025D40(rdram, ctx);
    goto after_15;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_15:
    // lw          $a2, 0x138($gp)
    ctx->r6 = MEM_W(0X138, ctx->r28);
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // or          $v1, $s1, $a2
    ctx->r3 = ctx->r17 | ctx->r6;
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // beq         $v1, $zero, L_80025B08
    if (ctx->r3 == 0) {
        // sw          $v0, 0x468($sp)
        MEM_W(0X468, ctx->r29) = ctx->r2;
        goto L_80025B08;
    }
    // sw          $v0, 0x468($sp)
    MEM_W(0X468, ctx->r29) = ctx->r2;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_80025AB4:
    // lwl         $v0, 0x3($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r17);
    // lwr         $v0, 0x0($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r17);
    // lwl         $v1, 0x7($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r17);
    // lwr         $v1, 0x4($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r17);
    // lwl         $a0, 0xB($s1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r17);
    // lwr         $a0, 0x8($s1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r17);
    // lwl         $a1, 0xF($s1)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r17);
    // lwr         $a1, 0xC($s1)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r17);
    // swl         $v0, 0x3($a2)
    do_swl(rdram, 0X3, ctx->r6, ctx->r2);
    // swr         $v0, 0x0($a2)
    do_swr(rdram, 0X0, ctx->r6, ctx->r2);
    // swl         $v1, 0x7($a2)
    do_swl(rdram, 0X7, ctx->r6, ctx->r3);
    // swr         $v1, 0x4($a2)
    do_swr(rdram, 0X4, ctx->r6, ctx->r3);
    // swl         $a0, 0xB($a2)
    do_swl(rdram, 0XB, ctx->r6, ctx->r4);
    // swr         $a0, 0x8($a2)
    do_swr(rdram, 0X8, ctx->r6, ctx->r4);
    // swl         $a1, 0xF($a2)
    do_swl(rdram, 0XF, ctx->r6, ctx->r5);
    // swr         $a1, 0xC($a2)
    do_swr(rdram, 0XC, ctx->r6, ctx->r5);
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // bne         $s1, $a3, L_80025AB4
    if (ctx->r17 != ctx->r7) {
        // addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
        goto L_80025AB4;
    }
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // j           L_80025B38
    // nop

    goto L_80025B38;
    // nop

L_80025B08:
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_80025B0C:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(0X8, ctx->r17);
    // lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(0XC, ctx->r17);
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // bne         $s1, $a3, L_80025B0C
    if (ctx->r17 != ctx->r7) {
        // addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
        goto L_80025B0C;
    }
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80025B38:
    // bne         $s5, $zero, L_80025B6C
    if (ctx->r21 != 0) {
        // addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
        goto L_80025B6C;
    }
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $a0, $sp, 0x4E8
    ctx->r4 = ADD32(ctx->r29, 0X4E8);
    // lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // jal         0x80062B10
    // ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    open(rdram, ctx);
    goto after_16;
    // ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    after_16:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80025C0C
    if (ctx->r16 == ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80025C0C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80062850
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_17;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
L_80025B6C:
    // addiu       $s1, $sp, 0x4E8
    ctx->r17 = ADD32(ctx->r29, 0X4E8);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80062B10
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    open(rdram, ctx);
    goto after_18;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    after_18:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $s4, L_80025BFC
    if (ctx->r16 == ctx->r20) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80025BFC;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $a1, 0x138($gp)
    ctx->r5 = MEM_W(0X138, ctx->r28);
    // jal         0x80062860
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    write(rdram, ctx);
    goto after_19;
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    after_19:
    // ori         $s2, $zero, 0x4000
    ctx->r18 = 0 | 0X4000;
    // bne         $v0, $s2, L_80025C00
    if (ctx->r2 != ctx->r18) {
        // slti        $v0, $s7, 0x3
        ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
        goto L_80025C00;
    }
    // slti        $v0, $s7, 0x3
    ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // jal         0x80062850
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_20;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_20:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80062B10
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    open(rdram, ctx);
    goto after_21;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_21:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $s4, L_80025BFC
    if (ctx->r16 == ctx->r20) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80025BFC;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $a1, 0x138($gp)
    ctx->r5 = MEM_W(0X138, ctx->r28);
    // jal         0x80062AC0
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    read(rdram, ctx);
    goto after_22;
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    after_22:
    // bne         $v0, $s2, L_80025C00
    if (ctx->r2 != ctx->r18) {
        // slti        $v0, $s7, 0x3
        ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
        goto L_80025C00;
    }
    // slti        $v0, $s7, 0x3
    ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // jal         0x80062850
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_23;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_23:
    // lw          $a0, 0x138($gp)
    ctx->r4 = MEM_W(0X138, ctx->r28);
    // jal         0x80025D40
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    sub_80025D40(rdram, ctx);
    goto after_24;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_24:
    // bne         $s6, $v0, L_80025C00
    if (ctx->r22 != ctx->r2) {
        // slti        $v0, $s7, 0x3
        ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
        goto L_80025C00;
    }
    // slti        $v0, $s7, 0x3
    ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // sb          $s3, 0x7C($gp)
    MEM_B(0X7C, ctx->r28) = ctx->r19;
    // j           L_80025C0C
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80025C0C;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80025BFC:
    // slti        $v0, $s7, 0x3
    ctx->r2 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
L_80025C00:
    // bne         $v0, $zero, L_80025870
    if (ctx->r2 != 0) {
        // addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
        goto L_80025870;
    }
    // addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80025C0C:
    // lw          $ra, 0x590($sp)
    ctx->r31 = MEM_W(0X590, ctx->r29);
    // lw          $s7, 0x58C($sp)
    ctx->r23 = MEM_W(0X58C, ctx->r29);
    // lw          $s6, 0x588($sp)
    ctx->r22 = MEM_W(0X588, ctx->r29);
    // lw          $s5, 0x584($sp)
    ctx->r21 = MEM_W(0X584, ctx->r29);
    // lw          $s4, 0x580($sp)
    ctx->r20 = MEM_W(0X580, ctx->r29);
    // lw          $s3, 0x57C($sp)
    ctx->r19 = MEM_W(0X57C, ctx->r29);
    // lw          $s2, 0x578($sp)
    ctx->r18 = MEM_W(0X578, ctx->r29);
    // lw          $s1, 0x574($sp)
    ctx->r17 = MEM_W(0X574, ctx->r29);
    // lw          $s0, 0x570($sp)
    ctx->r16 = MEM_W(0X570, ctx->r29);
    // addiu       $sp, $sp, 0x598
    ctx->r29 = ADD32(ctx->r29, 0X598);
    // jr          $ra
    // nop

    return;
    // nop

;}
