#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // lh          $a1, 0x42($s0)
    ctx->r5 = MEM_H(0X42, ctx->r16);
    // jal         0x800157E4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_800157E4(rdram, ctx);
    goto after_0;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // beq         $v0, $zero, L_8003E734
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E734;
    }
    // nop

    // lh          $a1, 0x42($s0)
    ctx->r5 = MEM_H(0X42, ctx->r16);
    // jal         0x800157D4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_800157D4(rdram, ctx);
    goto after_1;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // beq         $v0, $zero, L_8003E690
    if (ctx->r2 == 0) {
        // negu        $a2, $s2
        ctx->r6 = SUB32(0, ctx->r18);
        goto L_8003E690;
    }
    // negu        $a2, $s2
    ctx->r6 = SUB32(0, ctx->r18);
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // nop

    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003E6B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E6B8;
    }
    // nop

    // j           L_8003E6B8
    // sh          $s2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r18;
    goto L_8003E6B8;
    // sh          $s2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r18;
L_8003E690:
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // nop

    // subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_8003E6B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E6B8;
    }
    // nop

    // sh          $a2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r6;
L_8003E6B8:
    // lh          $a1, 0x42($s0)
    ctx->r5 = MEM_H(0X42, ctx->r16);
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // lh          $v1, 0x58($s0)
    ctx->r3 = MEM_H(0X58, ctx->r16);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // blez        $v1, L_8003E6F8
    if (SIGNED(ctx->r3) <= 0) {
        // sh          $v0, 0x42($s0)
        MEM_H(0X42, ctx->r16) = ctx->r2;
        goto L_8003E6F8;
    }
    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800157D4
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    sub_800157D4(rdram, ctx);
    goto after_2;
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    after_2:
    // beq         $v0, $zero, L_8003E738
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003E738;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lh          $a1, 0x42($s0)
    ctx->r5 = MEM_H(0X42, ctx->r16);
    // j           L_8003E71C
    // nop

    goto L_8003E71C;
    // nop

L_8003E6F8:
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x800157D4
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    sub_800157D4(rdram, ctx);
    goto after_3;
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    after_3:
    // beq         $v0, $zero, L_8003E738
    if (ctx->r2 == 0) {
        // addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
        goto L_8003E738;
    }
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lh          $a0, 0x42($s0)
    ctx->r4 = MEM_H(0X42, ctx->r16);
L_8003E71C:
    // jal         0x800157D4
    // nop

    sub_800157D4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // bne         $v0, $zero, L_8003E738
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003E738;
    }
    // nop

    // j           L_8003E738
    // sh          $s2, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r18;
    goto L_8003E738;
    // sh          $s2, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r18;
L_8003E734:
    // sh          $zero, 0x58($s0)
    MEM_H(0X58, ctx->r16) = 0;
L_8003E738:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
