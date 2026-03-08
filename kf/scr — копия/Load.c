#include "recomp.h"
#include "disable_warnings.h"

void KF_SaveLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, -0x63
    ctx->r19 = ADD32(0, -0X63);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // ori         $a2, $zero, 0x65
    ctx->r6 = 0 | 0X65;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x4A66
    ctx->r5 = ADD32(ctx->r5, -0X4A66);
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // sh          $a2, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r6;
    // lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(0X0, ctx->r5);
    // ori         $v0, $zero, 0x7B
    ctx->r2 = 0 | 0X7B;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x6218
    ctx->r4 = ADD32(ctx->r4, -0X6218);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a3, 0x7($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X7, ctx->r2);
    // lwr         $a3, 0x4($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X4, ctx->r2);
    // lwl         $t0, 0xB($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0XB, ctx->r2);
    // lwr         $t0, 0x8($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X8, ctx->r2);
    // lwl         $t1, 0xF($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, 0XF, ctx->r2);
    // lwr         $t1, 0xC($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, 0XC, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // swl         $a3, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r7);
    // swr         $a3, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r7);
    // swl         $t0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r8);
    // swr         $t0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r8);
    // swl         $t1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r9);
    // swr         $t1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r9);
    // lwl         $v1, 0x13($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r2);
    // lwr         $v1, 0x10($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r2);
    // lwl         $a3, 0x17($v0)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X17, ctx->r2);
    // lwr         $a3, 0x14($v0)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X14, ctx->r2);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a3, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r7);
    // swr         $a3, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r7);
    // ori         $v0, $zero, 0x95
    ctx->r2 = 0 | 0X95;
    // sh          $a2, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r6;
    // lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(0X0, ctx->r5);
    // addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
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
L_8001C864:
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001C884
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_8001C884;
    }
    // nop

    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // nop

    // beq         $v0, $s3, L_8001C88C
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8001C88C;
    }
    // nop

L_8001C884:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8001C88C:
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // nop

    // beq         $v1, $zero, L_8001C8AC
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001C8AC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8001C8B4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001C8B4;
    }
    // nop

    // j           L_8001C8B8
    // nop

    goto L_8001C8B8;
    // nop

L_8001C8AC:
    // j           L_8001C8B8
    // sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    goto L_8001C8B8;
    // sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8001C8B4:
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
L_8001C8B8:
    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001C940
    if (ctx->r2 != ctx->r19) {
        // addiu       $v0, $sp, 0x58
        ctx->r2 = ADD32(ctx->r29, 0X58);
        goto L_8001C940;
    }
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // jal         0x80020420
    // addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    MenuInputProcess(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_1:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8001C8E8:
    // jal         0x800244E0
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_2;
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_2:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // lw          $s0, 0x70($gp)
    ctx->r16 = MEM_W(0X70, ctx->r28);
    // sw          $zero, 0x70($gp)
    MEM_W(0X70, ctx->r28) = 0;
    // jal         0x80022774
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    RenderMenuFrame(rdram, ctx);
    goto after_3;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_3:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(0X54, ctx->r29);
    // sw          $s0, 0x70($gp)
    MEM_W(0X70, ctx->r28) = ctx->r16;
    // jal         0x80023294
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    ApplyViewTransforms(rdram, ctx);
    goto after_4;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_4:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001C8E8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C8E8;
    }
    // nop

    // j           L_8001C864
    // nop

    goto L_8001C864;
    // nop

L_8001C940:
    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(0X70, ctx->r29);
    // lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
