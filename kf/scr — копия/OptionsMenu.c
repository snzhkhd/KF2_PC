#include "recomp.h"
#include "disable_warnings.h"

void OptionsMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, -0x63
    ctx->r19 = ADD32(0, -0X63);
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // ori         $s4, $zero, 0x6
    ctx->r20 = 0 | 0X6;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A75($v1)
    ctx->r3 = MEM_BU(-0X4A75, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x4A74($a0)
    ctx->r4 = MEM_BU(-0X4A74, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lbu         $a1, -0x4A73($a1)
    ctx->r5 = MEM_BU(-0X4A73, ctx->r5);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lbu         $a2, -0x4A72($a2)
    ctx->r6 = MEM_BU(-0X4A72, ctx->r6);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lbu         $a3, -0x4A71($a3)
    ctx->r7 = MEM_BU(-0X4A71, ctx->r7);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lbu         $t0, -0x4A70($t0)
    ctx->r8 = MEM_BU(-0X4A70, ctx->r8);
    // ori         $v0, $zero, 0xB4
    ctx->r2 = 0 | 0XB4;
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // ori         $t1, $zero, 0x2D
    ctx->r9 = 0 | 0X2D;
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // sh          $t1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r9;
    // sb          $v1, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r3;
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
    // sb          $a0, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r4;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x6248
    ctx->r4 = ADD32(ctx->r4, -0X6248);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sb          $a1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r5;
    // sb          $a2, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r6;
    // sb          $a3, 0x14($sp)
    MEM_B(0X14, ctx->r29) = ctx->r7;
    // sb          $t0, 0x15($sp)
    MEM_B(0X15, ctx->r29) = ctx->r8;
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a1, 0x7($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r2);
    // lwr         $a1, 0x4($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r2);
    // lwl         $a2, 0xB($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XB, ctx->r2);
    // lwr         $a2, 0x8($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X8, ctx->r2);
    // lwl         $a3, 0xF($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0XF, ctx->r2);
    // lwr         $a3, 0xC($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r5);
    // swr         $a1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r5);
    // swl         $a2, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r6);
    // swr         $a2, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r6);
    // swl         $a3, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r7);
    // swr         $a3, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r7);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a1, 0x17($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r2);
    // lwr         $a1, 0x14($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r5);
    // swr         $a1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r5);
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x4A66($a1)
    ctx->r5 = MEM_H(-0X4A66, ctx->r5);
    // addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // sh          $t1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r9;
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
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // swl         $a1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r5);
    // swr         $a1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r5);
    // swl         $a2, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r6);
    // swr         $a2, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r6);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a0, 0x17($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r2);
    // lwr         $a0, 0x14($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r2);
    // swl         $v1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r3);
    // swr         $v1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r3);
    // swl         $a0, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r4);
    // swr         $a0, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r4);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
L_8001CB04:
    // beq         $s3, $v0, L_8001CB1C
    if (ctx->r19 == ctx->r2) {
        // nop
    
        goto L_8001CB1C;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8001CCBC
    // nop

    goto L_8001CCBC;
    // nop

L_8001CB1C:
    // jal         0x80024E70
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    WaitForInputStable(rdram, ctx);
    goto after_1;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
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
    // beq         $v1, $zero, L_8001CB60
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8001CB60;
    }
    // nop

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
    // bne         $s1, $zero, L_8001CC70
    if (ctx->r17 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_8001CC70;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // j           L_8001CC70
    // addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    goto L_8001CC70;
    // addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_8001CB60:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001CB94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CB94;
    }
    // nop

    // sw          $zero, 0x74($gp)
    MEM_W(0X74, ctx->r28) = 0;
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_4:
    // bne         $s1, $s4, L_8001CC70
    if (ctx->r17 != ctx->r20) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8001CC70;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // j           L_8001CC70
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_8001CC70;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8001CB94:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_8001CBDC
    if (ctx->r2 != 0) {
        // slt         $v0, $s1, $s4
        ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
        goto L_8001CBDC;
    }
    // slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62FC($v0)
    ctx->r2 = MEM_W(0X62FC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_8001CBDC
    if (ctx->r2 != 0) {
        // slt         $v0, $s1, $s4
        ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
        goto L_8001CBDC;
    }
    // slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6300($v0)
    ctx->r2 = MEM_W(0X6300, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001CC34
    if (ctx->r2 == 0) {
        // slt         $v0, $s1, $s4
        ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
        goto L_8001CC34;
    }
    // slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
L_8001CBDC:
    // beq         $v0, $zero, L_8001CC08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CC08;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_5:
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // j           L_8001CC70
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    goto L_8001CC70;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8001CC08:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001CC74
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001CC74;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_6:
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // j           L_8001CC70
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    goto L_8001CC70;
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
L_8001CC34:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D0($v0)
    ctx->r2 = MEM_W(0X62D0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_8001CC64
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001CC64;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E0($v0)
    ctx->r2 = MEM_W(0X62E0, ctx->r2);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8001CC74
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001CC74;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001CC64:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_7:
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_8001CC70:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001CC74:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_8;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80022774
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_9;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_9:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // jal         0x80022354
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    RenderOptionsList(rdram, ctx);
    goto after_10;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_10:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001CC74
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x63
        ctx->r2 = ADD32(0, -0X63);
        goto L_8001CC74;
    }
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // j           L_8001CB04
    // nop

    goto L_8001CB04;
    // nop

L_8001CCBC:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // lbu         $v1, 0x11($sp)
    ctx->r3 = MEM_BU(0X11, ctx->r29);
    // lbu         $a0, 0x12($sp)
    ctx->r4 = MEM_BU(0X12, ctx->r29);
    // lbu         $a1, 0x13($sp)
    ctx->r5 = MEM_BU(0X13, ctx->r29);
    // lbu         $a2, 0x14($sp)
    ctx->r6 = MEM_BU(0X14, ctx->r29);
    // lbu         $a3, 0x15($sp)
    ctx->r7 = MEM_BU(0X15, ctx->r29);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A75($at)
    MEM_B(-0X4A75, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x4A74($at)
    MEM_B(-0X4A74, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A73($at)
    MEM_B(-0X4A73, ctx->r1) = ctx->r4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a1, -0x4A72($at)
    MEM_B(-0X4A72, ctx->r1) = ctx->r5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a2, -0x4A71($at)
    MEM_B(-0X4A71, ctx->r1) = ctx->r6;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a3, -0x4A70($at)
    MEM_B(-0X4A70, ctx->r1) = ctx->r7;
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
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
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
