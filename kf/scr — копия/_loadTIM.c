#include "recomp.h"
#include "disable_warnings.h"

void _loadTIM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x888
    ctx->r29 = ADD32(ctx->r29, -0X888);
    // sw          $ra, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r31;
    // sw          $s4, 0x880($sp)
    MEM_W(0X880, ctx->r29) = ctx->r20;
    // sw          $s3, 0x87C($sp)
    MEM_W(0X87C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x878($sp)
    MEM_W(0X878, ctx->r29) = ctx->r18;
    // sw          $s1, 0x874($sp)
    MEM_W(0X874, ctx->r29) = ctx->r17;
    // sw          $s0, 0x870($sp)
    MEM_W(0X870, ctx->r29) = ctx->r16;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x115C
    ctx->r5 = ADD32(ctx->r5, 0X115C);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lwl         $v1, 0x7($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r5);
    // lwr         $v1, 0x4($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r5);
    // lwl         $a0, 0xB($a1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r5);
    // lwr         $a0, 0x8($a1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r5);
    // swl         $v0, 0x853($sp)
    do_swl(rdram, 0X853, ctx->r29, ctx->r2);
    // swr         $v0, 0x850($sp)
    do_swr(rdram, 0X850, ctx->r29, ctx->r2);
    // swl         $v1, 0x857($sp)
    do_swl(rdram, 0X857, ctx->r29, ctx->r3);
    // swr         $v1, 0x854($sp)
    do_swr(rdram, 0X854, ctx->r29, ctx->r3);
    // swl         $a0, 0x85B($sp)
    do_swl(rdram, 0X85B, ctx->r29, ctx->r4);
    // swr         $a0, 0x858($sp)
    do_swr(rdram, 0X858, ctx->r29, ctx->r4);
    // lwl         $v0, 0xF($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0XF, ctx->r5);
    // lwr         $v0, 0xC($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0XC, ctx->r5);
    // lwl         $v1, 0x13($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r5);
    // lwr         $v1, 0x10($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r5);
    // lwl         $a0, 0x17($a1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r5);
    // lwr         $a0, 0x14($a1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r5);
    // swl         $v0, 0x85F($sp)
    do_swl(rdram, 0X85F, ctx->r29, ctx->r2);
    // swr         $v0, 0x85C($sp)
    do_swr(rdram, 0X85C, ctx->r29, ctx->r2);
    // swl         $v1, 0x863($sp)
    do_swl(rdram, 0X863, ctx->r29, ctx->r3);
    // swr         $v1, 0x860($sp)
    do_swr(rdram, 0X860, ctx->r29, ctx->r3);
    // swl         $a0, 0x867($sp)
    do_swl(rdram, 0X867, ctx->r29, ctx->r4);
    // swr         $a0, 0x864($sp)
    do_swr(rdram, 0X864, ctx->r29, ctx->r4);
    // lwl         $v0, 0x1B($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1B, ctx->r5);
    // lwr         $v0, 0x18($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X18, ctx->r5);
    // lb          $v1, 0x1C($a1)
    ctx->r3 = MEM_B(0X1C, ctx->r5);
    // lb          $a0, 0x1D($a1)
    ctx->r4 = MEM_B(0X1D, ctx->r5);
    // swl         $v0, 0x86B($sp)
    do_swl(rdram, 0X86B, ctx->r29, ctx->r2);
    // swr         $v0, 0x868($sp)
    do_swr(rdram, 0X868, ctx->r29, ctx->r2);
    // sb          $v1, 0x86C($sp)
    MEM_B(0X86C, ctx->r29) = ctx->r3;
    // sb          $a0, 0x86D($sp)
    MEM_B(0X86D, ctx->r29) = ctx->r4;
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // addiu       $s4, $s4, -0x4A66
    ctx->r20 = ADD32(ctx->r20, -0X4A66);
    // lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(0X0, ctx->r20);
    // addiu       $v1, $sp, 0x850
    ctx->r3 = ADD32(ctx->r29, 0X850);
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // jal         0x80018960
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_80018960(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80018E58
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80018E58;
    }
    // nop

    // jal         0x800373DC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    ProcessTIMContainer(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // jal         0x80017C40
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_PadChkVsync(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80018E58:
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, -0x5790
    ctx->r16 = ADD32(ctx->r16, -0X5790);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(0X0, ctx->r20);
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x19D0
    ctx->r17 = ADD32(ctx->r17, -0X19D0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // lwl         $a2, 0x3($v1)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X3, ctx->r3);
    // lwr         $a2, 0x0($v1)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X0, ctx->r3);
    // nop

    // swl         $a2, 0x7($s0)
    do_swl(rdram, 0X7, ctx->r16, ctx->r6);
    // swr         $a2, 0x4($s0)
    do_swr(rdram, 0X4, ctx->r16, ctx->r6);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x19CC
    ctx->r1 = ADD32(ctx->r1, -0X19CC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5788($at)
    MEM_W(-0X5788, ctx->r1) = ctx->r2;
    // jal         0x80018890
    // ori         $a2, $zero, 0x800
    ctx->r6 = 0 | 0X800;
    CalculateSectorCount(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x800
    ctx->r6 = 0 | 0X800;
    after_3:
    // lui         $s3, 0x8001
    ctx->r19 = S32(0X8001 << 16);
    // addiu       $s3, $s3, 0x117C
    ctx->r19 = ADD32(ctx->r19, 0X117C);
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // jal         0x80062BA0
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    psx_printf(rdram, ctx);
    goto after_4;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    after_4:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // jal         0x80017C40
    // nop

    KF_PadChkVsync(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(0X10, ctx->r29);
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // jal         0x80017C18
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    AllocateMemory(rdram, ctx);
    goto after_6;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    after_6:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $s2, $sp, 0x12
    ctx->r18 = ADD32(ctx->r29, 0X12);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // lhu         $a2, 0x10($sp)
    ctx->r6 = MEM_HU(0X10, ctx->r29);
    // addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // jal         0x800176B4
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    CopyToFinalBuffer(rdram, ctx);
    goto after_7;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_7:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(0X0, ctx->r20);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $s1, $v1, $s1
    ctx->r17 = ADD32(ctx->r3, ctx->r17);
    // lwl         $v0, 0x3($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r17);
    // lwr         $v0, 0x0($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r17);
    // nop

    // swl         $v0, 0x7($s0)
    do_swl(rdram, 0X7, ctx->r16, ctx->r2);
    // swr         $v0, 0x4($s0)
    do_swr(rdram, 0X4, ctx->r16, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x19CC
    ctx->r1 = ADD32(ctx->r1, -0X19CC);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5764($at)
    MEM_W(-0X5764, ctx->r1) = ctx->r2;
    // jal         0x80018890
    // ori         $a2, $zero, 0x800
    ctx->r6 = 0 | 0X800;
    CalculateSectorCount(rdram, ctx);
    goto after_8;
    // ori         $a2, $zero, 0x800
    ctx->r6 = 0 | 0X800;
    after_8:
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // jal         0x80062BA0
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    psx_printf(rdram, ctx);
    goto after_9;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    after_9:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // jal         0x80017C40
    // nop

    KF_PadChkVsync(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(0X10, ctx->r29);
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // jal         0x80017C18
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    AllocateMemory(rdram, ctx);
    goto after_11;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    after_11:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lhu         $a2, 0x10($sp)
    ctx->r6 = MEM_HU(0X10, ctx->r29);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // jal         0x800176B4
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    CopyToFinalBuffer(rdram, ctx);
    goto after_12;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_12:
    // lw          $ra, 0x884($sp)
    ctx->r31 = MEM_W(0X884, ctx->r29);
    // lw          $s4, 0x880($sp)
    ctx->r20 = MEM_W(0X880, ctx->r29);
    // lw          $s3, 0x87C($sp)
    ctx->r19 = MEM_W(0X87C, ctx->r29);
    // lw          $s2, 0x878($sp)
    ctx->r18 = MEM_W(0X878, ctx->r29);
    // lw          $s1, 0x874($sp)
    ctx->r17 = MEM_W(0X874, ctx->r29);
    // lw          $s0, 0x870($sp)
    ctx->r16 = MEM_W(0X870, ctx->r29);
    // addiu       $sp, $sp, 0x888
    ctx->r29 = ADD32(ctx->r29, 0X888);
    // jr          $ra
    // nop

    return;
    // nop

;}
