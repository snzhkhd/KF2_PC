#include "recomp.h"
#include "disable_warnings.h"

void sub_80014ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $s3, 15
    ctx->r6 = S32(ctx->r19) << 15;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // jal         0x80015798
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    Math_IsAngleInRange(rdram, ctx);
    goto after_0;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_0:
    // beq         $v0, $zero, L_80014F3C
    if (ctx->r2 == 0) {
        // slt         $v0, $s3, $s0
        ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
        goto L_80014F3C;
    }
    // slt         $v0, $s3, $s0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_80014F3C
    if (ctx->r2 != 0) {
        // negu        $v0, $s3
        ctx->r2 = SUB32(0, ctx->r19);
        goto L_80014F3C;
    }
    // negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80014F88
    if (ctx->r2 == 0) {
        // subu        $v0, $s2, $s1
        ctx->r2 = SUB32(ctx->r18, ctx->r17);
        goto L_80014F88;
    }
    // subu        $v0, $s2, $s1
    ctx->r2 = SUB32(ctx->r18, ctx->r17);
L_80014F3C:
    // beq         $s1, $s2, L_80014F68
    if (ctx->r17 == ctx->r18) {
        // sll         $a0, $s1, 16
        ctx->r4 = S32(ctx->r17) << 16;
        goto L_80014F68;
    }
    // sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18) << 16;
    // jal         0x800157D4
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_800157D4(rdram, ctx);
    goto after_1;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_1:
    // beq         $v0, $zero, L_80014F64
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80014F64;
    }
    // nop

    // j           L_80014F68
    // subu        $s0, $s0, $s3
    ctx->r16 = SUB32(ctx->r16, ctx->r19);
    goto L_80014F68;
    // subu        $s0, $s0, $s3
    ctx->r16 = SUB32(ctx->r16, ctx->r19);
L_80014F64:
    // addu        $s0, $s0, $s3
    ctx->r16 = ADD32(ctx->r16, ctx->r19);
L_80014F68:
    // blez        $s0, L_80014F78
    if (SIGNED(ctx->r16) <= 0) {
        // nop
    
        goto L_80014F78;
    }
    // nop

    // j           L_80014F84
    // subu        $s0, $s0, $s4
    ctx->r16 = SUB32(ctx->r16, ctx->r20);
    goto L_80014F84;
    // subu        $s0, $s0, $s4
    ctx->r16 = SUB32(ctx->r16, ctx->r20);
L_80014F78:
    // bgez        $s0, L_80014F88
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80014F88;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
L_80014F84:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80014F88:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
