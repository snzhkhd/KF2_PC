#include "recomp.h"
#include "disable_warnings.h"

void LoadTalkFiles(uint8_t* rdram, recomp_context* ctx) 
{
    printf("LoadTalkFiles\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // addiu       $a2, $a2, 0x10B0
    ctx->r6 = ADD32(ctx->r6, 0X10B0);
    // or          $v0, $a3, $a2
    ctx->r2 = ctx->r7 | ctx->r6;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sw          $ra, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r31;
    // sw          $s4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r20;
    // sw          $s3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r19;
    // sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // sw          $s1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_80018C6C
    if (ctx->r2 == 0) {
        // sw          $s0, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r16;
        goto L_80018C6C;
    }
    // sw          $s0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r16;
    // addiu       $t0, $a2, 0x70
    ctx->r8 = ADD32(ctx->r6, 0X70);
L_80018C18:
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
    // bne         $a2, $t0, L_80018C18
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80018C18;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_80018C9C
    // nop

    goto L_80018C9C;
    // nop

L_80018C6C:
    // addiu       $t0, $a2, 0x70
    ctx->r8 = ADD32(ctx->r6, 0X70);
L_80018C70:
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
    // bne         $a2, $t0, L_80018C70
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80018C70;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_80018C9C:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addiu       $s3, $sp, 0x10
    ctx->r19 = ADD32(ctx->r29, 0X10);
    // lui         $s4, 0x801A
    ctx->r20 = S32(0X801A << 16);
    // addiu       $s4, $s4, -0x19D0
    ctx->r20 = ADD32(ctx->r20, -0X19D0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
L_80018CD4:
    // lw          $v0, 0x58($gp)
    ctx->r2 = MEM_W(0X58, ctx->r28);
    // lb          $v1, 0x5C($gp)
    ctx->r3 = MEM_B(0X5C, ctx->r28);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sb          $v1, 0x14($sp)
    MEM_B(0X14, ctx->r29) = ctx->r3;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80062B90
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    strcat_recomp(rdram, ctx);
    goto after_0;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6320
    ctx->r5 = ADD32(ctx->r5, 0X6320);
    // jal         0x80062B90
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_1:
    // addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
L_80018D04:
    // jal         0x8004F4AC
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    KF_CdSearchFile(rdram, ctx);
    goto after_2;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_2:
    // bne         $v0, $zero, L_80018D2C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80018D2C;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x1128
    ctx->r4 = ADD32(ctx->r4, 0X1128);
    // jal         0x80062BA0
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    psx_printf(rdram, ctx);
    goto after_3;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // j           L_80018D04
    // addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
    goto L_80018D04;
    // addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
L_80018D2C:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x1144
    ctx->r4 = ADD32(ctx->r4, 0X1144);
    // jal         0x80062BA0
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    psx_printf(rdram, ctx);
    goto after_4;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_4:
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slti        $v0, $s2, 0x6
    ctx->r2 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_80018CD4
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
        goto L_80018CD4;
    }
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // lw          $ra, 0xDC($sp)
    ctx->r31 = MEM_W(0XDC, ctx->r29);
    // lw          $s4, 0xD8($sp)
    ctx->r20 = MEM_W(0XD8, ctx->r29);
    // lw          $s3, 0xD4($sp)
    ctx->r19 = MEM_W(0XD4, ctx->r29);
    // lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(0XD0, ctx->r29);
    // lw          $s1, 0xCC($sp)
    ctx->r17 = MEM_W(0XCC, ctx->r29);
    // lw          $s0, 0xC8($sp)
    ctx->r16 = MEM_W(0XC8, ctx->r29);
    // addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // jr          $ra
    // nop

    return;
    // nop

;}
