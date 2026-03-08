#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, 0x79B4($v1)
    ctx->r3 = MEM_W(0X79B4, ctx->r3);
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(0X50, ctx->r29);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(0X54, ctx->r29);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(0X58, ctx->r29);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(0X2C, ctx->r3);
    // lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(0X5C, ctx->r29);
    // subu        $s2, $a0, $v0
    ctx->r18 = SUB32(ctx->r4, ctx->r2);
    // lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(0X34, ctx->r3);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // subu        $s0, $a1, $v0
    ctx->r16 = SUB32(ctx->r5, ctx->r2);
    // jal         0x80015804
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // bgez        $s2, L_8003E848
    if (SIGNED(ctx->r18) >= 0) {
        // nop
    
        goto L_8003E848;
    }
    // nop

    // negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
L_8003E848:
    // bgez        $s0, L_8003E854
    if (SIGNED(ctx->r16) >= 0) {
        // nop
    
        goto L_8003E854;
    }
    // nop

    // negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_8003E854:
    // sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) << 16;
    // sra         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a1, $v0, L_8003E890
    if (ctx->r5 == ctx->r2) {
        // addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
        goto L_8003E890;
    }
    // addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // slti        $v0, $s2, 0x259
    ctx->r2 = SIGNED(ctx->r18) < 0X259 ? 1 : 0;
    // beq         $v0, $zero, L_8003E890
    if (ctx->r2 == 0) {
        // sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19) << 16;
        goto L_8003E890;
    }
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80015798
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    Math_IsAngleInRange(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    after_1:
    // bne         $v0, $zero, L_8003E894
    if (ctx->r2 != 0) {
        // sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19) << 16;
        goto L_8003E894;
    }
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // j           L_8003E8B4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8003E8B4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003E890:
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
L_8003E894:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // jal         0x8003E75C
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    sub_8003E75C(rdram, ctx);
    goto after_2;
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    after_2:
    // andi        $v0, $s3, 0xFFF
    ctx->r2 = ctx->r19 & 0XFFF;
L_8003E8B4:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
