#include "recomp.h"
#include "disable_warnings.h"

void MemCard_CheckSlot(uint8_t* rdram, recomp_context* ctx) 
{
    printf("MemCard_CheckSlot bypassed\n");
    ctx->r2 = 0;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x38
//    ctx->r29 = ADD32(ctx->r29, -0X38);
//    // sw          $ra, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r31;
//    // sw          $s0, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r16;
//    // lui         $a1, 0x8001
//    ctx->r5 = S32(0X8001 << 16);
//    // addiu       $a1, $a1, 0x1200
//    ctx->r5 = ADD32(ctx->r5, 0X1200);
//    // lwl         $v0, 0x3($a1)
//    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
//    // lwr         $v0, 0x0($a1)
//    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
//    // lwl         $v1, 0x7($a1)
//    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r5);
//    // lwr         $v1, 0x4($a1)
//    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r5);
//    // lwl         $a0, 0xB($a1)
//    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r5);
//    // lwr         $a0, 0x8($a1)
//    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r5);
//    // swl         $v0, 0x13($sp)
//    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
//    // swr         $v0, 0x10($sp)
//    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
//    // swl         $v1, 0x17($sp)
//    do_swl(rdram, 0X17, ctx->r29, ctx->r3);
//    // swr         $v1, 0x14($sp)
//    do_swr(rdram, 0X14, ctx->r29, ctx->r3);
//    // swl         $a0, 0x1B($sp)
//    do_swl(rdram, 0X1B, ctx->r29, ctx->r4);
//    // swr         $a0, 0x18($sp)
//    do_swr(rdram, 0X18, ctx->r29, ctx->r4);
//    // lwl         $v0, 0xF($a1)
//    ctx->r2 = do_lwl(rdram, ctx->r2, 0XF, ctx->r5);
//    // lwr         $v0, 0xC($a1)
//    ctx->r2 = do_lwr(rdram, ctx->r2, 0XC, ctx->r5);
//    // lwl         $v1, 0x13($a1)
//    ctx->r3 = do_lwl(rdram, ctx->r3, 0X13, ctx->r5);
//    // lwr         $v1, 0x10($a1)
//    ctx->r3 = do_lwr(rdram, ctx->r3, 0X10, ctx->r5);
//    // lwl         $a0, 0x17($a1)
//    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17, ctx->r5);
//    // lwr         $a0, 0x14($a1)
//    ctx->r4 = do_lwr(rdram, ctx->r4, 0X14, ctx->r5);
//    // swl         $v0, 0x1F($sp)
//    do_swl(rdram, 0X1F, ctx->r29, ctx->r2);
//    // swr         $v0, 0x1C($sp)
//    do_swr(rdram, 0X1C, ctx->r29, ctx->r2);
//    // swl         $v1, 0x23($sp)
//    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
//    // swr         $v1, 0x20($sp)
//    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
//    // swl         $a0, 0x27($sp)
//    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
//    // swr         $a0, 0x24($sp)
//    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
//    // lb          $v0, 0x18($a1)
//    ctx->r2 = MEM_B(0X18, ctx->r5);
//    // lb          $v1, 0x19($a1)
//    ctx->r3 = MEM_B(0X19, ctx->r5);
//    // sb          $v0, 0x28($sp)
//    MEM_B(0X28, ctx->r29) = ctx->r2;
//    // sb          $v1, 0x29($sp)
//    MEM_B(0X29, ctx->r29) = ctx->r3;
//    // jal         0x80025DE0
//    // nop
//
//    sub_80025DE0(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // jal         0x8004C8A4
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    KF_card_info(rdram, ctx);
//    goto after_1;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_1:
//    // jal         0x80025D64
//    // nop
//
//    sub_80025D64(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // addu        $v1, $v0, $zero
//    ctx->r3 = ADD32(ctx->r2, 0);
//    // ori         $v0, $zero, 0x2
//    ctx->r2 = 0 | 0X2;
//    // beq         $v1, $v0, L_8002515C
//    if (ctx->r3 == ctx->r2) {
//        // addiu       $a0, $sp, 0x10
//        ctx->r4 = ADD32(ctx->r29, 0X10);
//        goto L_8002515C;
//    }
//    // addiu       $a0, $sp, 0x10
//    ctx->r4 = ADD32(ctx->r29, 0X10);
//    // bne         $v1, $zero, L_80025184
//    if (ctx->r3 != 0) {
//        // addu        $v0, $v1, $zero
//        ctx->r2 = ADD32(ctx->r3, 0);
//        goto L_80025184;
//    }
//    // addu        $v0, $v1, $zero
//    ctx->r2 = ADD32(ctx->r3, 0);
//L_8002515C:
//    // jal         0x80062B10
//    // ori         $a1, $zero, 0x200
//    ctx->r5 = 0 | 0X200;
//    open(rdram, ctx);
//    goto after_3;
//    // ori         $a1, $zero, 0x200
//    ctx->r5 = 0 | 0X200;
//    after_3:
//    // addu        $s0, $v0, $zero
//    ctx->r16 = ADD32(ctx->r2, 0);
//    // jal         0x80062850
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    close(rdram, ctx);
//    goto after_4;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_4:
//    // jal         0x80062880
//    // addiu       $a0, $sp, 0x10
//    ctx->r4 = ADD32(ctx->r29, 0X10);
//    erase(rdram, ctx);
//    goto after_5;
//    // addiu       $a0, $sp, 0x10
//    ctx->r4 = ADD32(ctx->r29, 0X10);
//    after_5:
//    // nor         $s0, $zero, $s0
//    ctx->r16 = ~(0 | ctx->r16);
//    // sltiu       $s0, $s0, 0x1
//    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
//    // sll         $v0, $s0, 1
//    ctx->r2 = S32(ctx->r16) << 1;
//L_80025184:
//    // lw          $ra, 0x34($sp)
//    ctx->r31 = MEM_W(0X34, ctx->r29);
//    // lw          $s0, 0x30($sp)
//    ctx->r16 = MEM_W(0X30, ctx->r29);
//    // addiu       $sp, $sp, 0x38
//    ctx->r29 = ADD32(ctx->r29, 0X38);
//    // jr          $ra
//    // nop

    return;
    // nop

;}
