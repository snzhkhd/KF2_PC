#include "recomp.h"
#include "disable_warnings.h"

void sub_8005E43C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(0X40, ctx->r29);
    // lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(0X44, ctx->r29);
    // lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(0X48, ctx->r29);
    // lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(0X4C, ctx->r29);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(0X50, ctx->r29);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lwl         $v1, 0x3($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r4);
    // lwr         $v1, 0x0($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r4);
    // lwl         $t4, 0x7($a0)
    ctx->r12 = do_lwl(rdram, ctx->r12, 0X7, ctx->r4);
    // lwr         $t4, 0x4($a0)
    ctx->r12 = do_lwr(rdram, ctx->r12, 0X4, ctx->r4);
    // swl         $v1, 0x3($v0)
    do_swl(rdram, 0X3, ctx->r2, ctx->r3);
    // swr         $v1, 0x0($v0)
    do_swr(rdram, 0X0, ctx->r2, ctx->r3);
    // swl         $t4, 0x7($v0)
    do_swl(rdram, 0X7, ctx->r2, ctx->r12);
    // swr         $t4, 0x4($v0)
    do_swr(rdram, 0X4, ctx->r2, ctx->r12);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // lwl         $v1, 0x3($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r5);
    // lwr         $v1, 0x0($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r5);
    // lwl         $a0, 0x7($a1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r5);
    // lwr         $a0, 0x4($a1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r5);
    // swl         $v1, 0x2F($v0)
    do_swl(rdram, 0X2F, ctx->r2, ctx->r3);
    // swr         $v1, 0x2C($v0)
    do_swr(rdram, 0X2C, ctx->r2, ctx->r3);
    // swl         $a0, 0x33($v0)
    do_swl(rdram, 0X33, ctx->r2, ctx->r4);
    // swr         $a0, 0x30($v0)
    do_swr(rdram, 0X30, ctx->r2, ctx->r4);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // lwl         $v1, 0x3($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r7);
    // lwr         $v1, 0x0($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r7);
    // lwl         $a0, 0x7($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r7);
    // lwr         $a0, 0x4($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r7);
    // swl         $v1, 0x5B($v0)
    do_swl(rdram, 0X5B, ctx->r2, ctx->r3);
    // swr         $v1, 0x58($v0)
    do_swr(rdram, 0X58, ctx->r2, ctx->r3);
    // swl         $a0, 0x5F($v0)
    do_swl(rdram, 0X5F, ctx->r2, ctx->r4);
    // swr         $a0, 0x5C($v0)
    do_swr(rdram, 0X5C, ctx->r2, ctx->r4);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x63AC($v0)
    ctx->r2 = MEM_W(0X63AC, ctx->r2);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x87($v0)
    do_swl(rdram, 0X87, ctx->r2, ctx->r3);
    // swr         $v1, 0x84($v0)
    do_swr(rdram, 0X84, ctx->r2, ctx->r3);
    // swl         $a0, 0x8B($v0)
    do_swl(rdram, 0X8B, ctx->r2, ctx->r4);
    // swr         $a0, 0x88($v0)
    do_swr(rdram, 0X88, ctx->r2, ctx->r4);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x63AC($v1)
    ctx->r3 = MEM_W(0X63AC, ctx->r3);
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // sh          $v0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sh          $v0, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(0X0, ctx->r10);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sh          $v0, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(0X0, ctx->r11);
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // sh          $v0, 0xA4($v1)
    MEM_H(0XA4, ctx->r3) = ctx->r2;
L_8005E540:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x63AC($a0)
    ctx->r4 = MEM_W(0X63AC, ctx->r4);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    // jal         0x8005F348
    // addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    sub_8005F348(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    after_0:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x63AC($v1)
    ctx->r3 = MEM_W(0X63AC, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6448($v0)
    ctx->r2 = MEM_W(0X6448, ctx->r2);
    // addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(0X10, ctx->r3);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(0X10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6450($v0)
    ctx->r2 = MEM_W(0X6450, ctx->r2);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    // slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8005E540
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
        goto L_8005E540;
    }
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8005E5E8
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_8005E5E8(rdram, ctx);
    goto after_1;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
