#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // lw          $s3, 0x79B4($s3)
    ctx->r19 = MEM_W(0X79B4, ctx->r19);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // jal         0x80015538
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    Math_AnglesToDirVector(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // lwl         $v0, 0x1B($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1B, ctx->r29);
    // lwr         $v0, 0x18($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X18, ctx->r29);
    // lwl         $v1, 0x1F($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X1F, ctx->r29);
    // lwr         $v1, 0x1C($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X1C, ctx->r29);
    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // swl         $v1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r3);
    // swr         $v1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r3);
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    // sra         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16) >> 16;
    // jal         0x80015694
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    sub_80015694(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) << 16;
    // sra         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17) >> 16;
    // jal         0x80015694
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    sub_80015694(rdram, ctx);
    goto after_2;
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // lh          $a1, 0x18($sp)
    ctx->r5 = MEM_H(0X18, ctx->r29);
    // lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(0X20, ctx->r29);
    // lh          $a0, 0x50($s3)
    ctx->r4 = MEM_H(0X50, ctx->r19);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lh          $a0, 0x52($s3)
    ctx->r4 = MEM_H(0X52, ctx->r19);
    // sh          $v0, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r2;
    // lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(0X1A, ctx->r29);
    // lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(0X22, ctx->r29);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lh          $a0, 0x54($s3)
    ctx->r4 = MEM_H(0X54, ctx->r19);
    // sh          $v0, 0x52($s3)
    MEM_H(0X52, ctx->r19) = ctx->r2;
    // lh          $a1, 0x1C($sp)
    ctx->r5 = MEM_H(0X1C, ctx->r29);
    // lh          $a2, 0x24($sp)
    ctx->r6 = MEM_H(0X24, ctx->r29);
    // jal         0x80014D48
    // nop

    sub_80014D48(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8003D8E4
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    sub_8003D8E4(rdram, ctx);
    goto after_6;
    // sh          $v0, 0x54($s3)
    MEM_H(0X54, ctx->r19) = ctx->r2;
    after_6:
    // sltu        $s0, $zero, $v0
    ctx->r16 = 0 < ctx->r2 ? 1 : 0;
    // lh          $a0, 0x52($s3)
    ctx->r4 = MEM_H(0X52, ctx->r19);
    // lw          $v1, 0x30($s3)
    ctx->r3 = MEM_W(0X30, ctx->r19);
    // lhu         $a3, 0x1C($s3)
    ctx->r7 = MEM_HU(0X1C, ctx->r19);
    // lhu         $v0, 0x1E($s3)
    ctx->r2 = MEM_HU(0X1E, ctx->r19);
    // addu        $s1, $a0, $v1
    ctx->r17 = ADD32(ctx->r4, ctx->r3);
    // lw          $v1, 0x28($s3)
    ctx->r3 = MEM_W(0X28, ctx->r19);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(0X2C, ctx->r19);
    // lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(0X34, ctx->r19);
    // jal         0x8002E4F4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8002E4F4(rdram, ctx);
    goto after_7;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
    // bne         $v0, $zero, L_8003EA08
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003EA08;
    }
    // nop

    // j           L_8003EA0C
    // sw          $s1, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r17;
    goto L_8003EA0C;
    // sw          $s1, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r17;
L_8003EA08:
    // ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
L_8003EA0C:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
