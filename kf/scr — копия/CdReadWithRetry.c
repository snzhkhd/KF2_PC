#include "recomp.h"
#include "disable_warnings.h"

void CdReadWithRetry(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[DEBUG]     CdReadWithRetry\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x3
    ctx->r16 = 0 | 0X3;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8004CF78:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x8004EAB8
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    CD_readm(rdram, ctx);
    goto after_0;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_0:
    // bne         $v0, $zero, L_8004CF94
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8004CF94;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // j           L_8004CFA0
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8004CFA0;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004CF94:
    // bne         $s0, $s4, L_8004CF78
    if (ctx->r16 != ctx->r20) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8004CF78;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004CFA0:
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
